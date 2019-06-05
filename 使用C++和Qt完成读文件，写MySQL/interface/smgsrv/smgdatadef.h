//smgdatadef.h
#ifndef _SMGDATADEFINE_PENGSHIKANG_20080714_H_
#define _SMGDATADEFINE_PENGSHIKANG_20080714_H_

#include "../icsvalue.h"                         // for intarray
#include "genstatisdef.h"                        // for GeneClassStatisInfo

#define SMOOTHRAWNUMBER 200

#define MAINNETWORK   0 // 以大电网为主电源
#define MAINGENERATOR 1 // 以旋转发电机为主电源
#define MAINSTORAGE   2 // 以储能设备为主电源

#define ADDLOAD   1     // 投入负荷
#define ADDGENERATOR 2  // 投入发电机
#define ADJUSTGEN   3   // 增加发电机出力

enum EquipmentType
{
	ET_UNKNOWN = 0,//未知设备
	ET_SYSTEM,     //系统信息
	ET_GENERATOR,  //发电设备
	ET_STORAGE,    //储能设备
	ET_BUS,        //母线
	ET_TRANSFORMER,//变压器
	ET_LOAD,       //负荷
	ET_PCC,        //公共连接支路
	ET_REPOWERCOMP,//无功补偿设备
	ET_LINE,       //线路
};

enum PowerChangeState
{
	PCS_UNKNOWN = 0,//未知
	PCS_LOWER,      //越下线
	PCS_NORMAL,     //正常
	PCS_UPPER,      //越上线
};

typedef struct 
{
	unsigned int count;
	int         isleIds[10];
	double      loadPs[10];
}islearray; // 各个电气岛的负荷容量 [最多加入10个电气岛]

struct MicgridObectInfo
{
	int nMGPos;
	int nMGId;
	int nParentId;
	int nRunStyle0;//默认运行模式
	int nRunStyle1;//当前运行模式
	int nMainType;//主发电设备类型：=0，大电网；=1，旋转发电机；=2，主储能。
	int nMainStorPos;//主储能设备Pos。 >= 0 为主储能设备Pos；=-1 以旋转发电机或大电网为主电源
	intarray mainSrcIds;//主旋转发电设备ID列表
	float sysFreq;//系统频率
	float totalI; //系统电流
	int freqState0;//上次频率状态
	int powerState0;//上次频率功率状态

	islearray islandIds;//各个电气岛的负荷容量
	int mainIsleId;
	
	//离网参数
	bool bIntoIsle;  //进入离网状态 InitializeCombineEntry() -->false, InitializeIslandEntry() -->true
	double dIsleTime0;//初次黑启动开始的时间
	double dIsleTime;//本次黑启动开始的时间

	bool hasAct;    //是否有策略动作
	int respSeconds;//主电源响应时间间隔[秒]
	double dActTime;//下次产生策略的时间
	
	//并网策略参数
	int nExchPlanId;//交换功率曲线计划ID[定值]
	int nStorPlanId;//储能放电曲线计划ID[定值]

	//PCC
	int connectFlag;//并网状态 [0--离网，1--并网]  ok
	int breakerFlag;//断路器标志 [0--离网，1--并网] 
	float exchangeP;//实际交换有功功率[流入母线为正] ok
	double exchangeQ[2];//实际交换无功功率[流入母线为正] 用于VQC的无功状态判断
 	int nDoRecall;  //执行恢复策略状态：0--停止恢复；1--离转并恢复；2--无策略恢复；3--紧急恢复。
	int nLoadRecall;//负荷恢复策略状态：0--停止恢复；1--离转并恢复；2--无策略恢复；3--紧急恢复。
 	bool bGenRecall; //并网时是否处于光伏恢复状态
	bool bStrategy;  //并网时是否有自动执行策略
	
	//负荷
	int nLoadSum;//负荷个数[定值] ok
	int nLoadNum[3];//分级负荷集合长度[定值] ok
	intarray runLoad[3];//从大到小排序的投运的分级负荷集合 ok
	intarray cutLoad[3];//从大到小排序的未挂牌切除的分级负荷集合 ok
	float cutLoadP;//未挂牌切除的负荷的功率 ok
	
	//发电机
	int nGenNum;//发电机个数[定值] ok
	int nAdjGenNum;//投运的可调非主发电个数
	int nAdjOrder;//可调节发电机调节轮次
	intarray mainGen;//按最大备用出力从大到小排序的投运的主发电机位置列表 ok
	intarray fixGen; //按当前出力从大到小排序的不可调节出力的投运的非主发电机位置列表 ok
	intarray newGen; //按最大出力从大到小排序的可调节出力可再生的非主发电机位置列表[定值] ok
	intarray unewGen;//按最大出力从大到小排序的可调节出力不可再生的非主发电机位置列表[定值] ok
	intarray peakGen;//按最大出力从大到小排序的投运的调峰发电机列表
	intarray cutGen; //按最大抗冲击出力从大到小排序的未挂牌切除的不可调节发电机位置列 ok
	intarray cutAGen;//按最大抗冲击出力从大到小排序的未挂牌切除的可调节发电机位置列 ok

	//发电机机群
	int nGroupNum;//发电机机群个数[定值] ok
	intarray aGenGroup; //按最大出力从大到小排序的发电机机群位置列表[定值] ok

	float mainGenP;//投运的主发电机的总发电有功功率 ok
	float fixGenP;//投运的不可调非主发电机的总发电有功功率 ok
	float adjGenP;//投运的可调非主发电机的总发电有功功率 ok
	float addAdjGenP;//投运的可调非主发电机的总最大可增加发电有功功率 ok
	float backupP;//投运的主发电机的总备用有功功率 ok
	float maxEcoP;//投运的主发电机的总经济有功出力上限 ok
	float minEcoP;//投运的主发电机的总经济有功出力下限 ok
	float maxAimP;//投运的主发电机的总最大目标有功出力 ok
	float minAimP;//投运的主发电机的总最小目标有功出力 ok
	float maxGenP;//投运的主发电机的总最大有功出力 ok
	float minGenP;//投运的主发电机的总最小有功出力 ok
	float cutGenP;//未挂牌切除的发电机的总发电功率 ok
	float mainGenS;//投运的主发电机的总容量 ok
	float maxSensP;//投运的主发电机的最大灵敏功率 ok
	
	//储能装置
	intarray powerStor; //从大到小排序的运行的有功可调的功率型储能装置
	intarray sortedStor;//从大到小排序的运行的有功可调的能量型储能装置
	intarray repowStor; //从大到小排序的运行的无功可调的储能装置

	float totalSCapa;//投运的主储能总的容量
	float maxSCapa;  //投运的主储能容许最大的容量
	float minSCapa;  //投运的主储能容许最小的容量
	float curSCapa;  //投运的主储能当前剩余的容量

	float maxDchgP; //投运储能总的最大放电功率 ok
	float maxChgP;  //投运储能总的最大充电功率 ok
	float optDchgP; //投运储能总的最优放电功率 ok
	float optChgP;  //投运储能总的最优充电功率 ok
	float storplanP;//投运储能总的计划有功出力
	int socState;   //储能SOC状态
	float storpwrP0; //总的投运的正常SOC的功率型储能有功出力
	float storpwrP2; //总的投运的异常SOC的功率型储能保护性调节有功
	float storenyP0; //总的投运的正常SOC的能量型储能有功出力
	float storenyP2; //总的投运的异常SOC的能量型储能保护性调节有功

	//子微网实时的汇总功率
	GeneClassStatisInfo genSttsInfo[GT_INVALID];//发电机分类统计信息
	float storageP; //总的投运储能有功出力
	float storageQ; //总的投运储能无功出力
	float loadP;    //总的有功负荷
	float loadQ;    //总的无功负荷
	float sensLoadP;//灵敏负荷有功
	float sensLoadQ;//灵敏负荷无功
	float ctrlLoadP;//可控负荷有功
	float ctrlLoadQ;//可控负荷无功
	float cutdLoadP;//可切负荷有功
	float cutdLoadQ;//可切负荷无功

	//平滑控制策略
	int nSmoothPos;  //平滑控制记录位置
	bool hasSmooth;  //平滑控制是否生效
	int nAimType;    //平滑控制目标类型
	float dMaxRatio; //平滑控制最大允许变化率
	double dSmothSpan;//定量控制持续时间（分钟数转化为天数）
	//经济运行是否有效
	bool hasEcnomic;  //经济运行是否有效

	bool hasBaseP;
	bool isNewAimP;
	int prevPNum;//先前目标功率个数
	double smRawTime;//数据采集时间
	double smothTime;//平滑处理时间
	float prevExchP[SMOOTHRAWNUMBER];//先前交换功率
	float prevGenP[SMOOTHRAWNUMBER];//先前发电功率
	float prevStorP[SMOOTHRAWNUMBER];//先前实际储能功率
	float prevStopP[SMOOTHRAWNUMBER];//先前计划储能功率
	float prevLoadP[SMOOTHRAWNUMBER];//先前负荷功率
	float arvgExchP;//先前平均交换功率
	float arvgGenP; //先前平均发电功率
	float arvgStorP;//先前平均实际储能功率
	float arvgStopP;//先前平均计划储能功率
	float arvgLoadP;//先前平均负荷功率
	float prevBaseP;//先前基准目标功率
	float prevAimP; //先前目标功率
	float curBaseP; //当前基准目标功率
	float curAimP;  //当前目标功率
	float maxOffsP; //允许波动的目标功率
	float curRatio; //当前变化率
	float curCompP; //当前补偿功率
	float nearState[3];//最近的变化率状态
	int smoothFlag; //启动平滑控制操作类型

	int storFCState;//储能的频率调节状态 [0-未调节，1--调节中]
	int storVCState;//储能的电压调节状态 [0-未调节，1--调节中] 

	float sysFreq0;//上一次系统频率
	float totalI0; //上一次系统电流
	float exchangeP0;//上一次交换有功功率
	float mainGenP0;//上一次主发电机总发电功率

	float todaySaleEnergy;//今日上网电量
	float totalSaleEnergy;//累计上网电量
	float todayUseEnergy; //今日下网电量 
	float totalUseEnergy; //累计下网电量
	float adjGenP0;//投运的可调不可增非主发电机的总发电有功功率 for 平滑
	float addAdjGenP0;//投运的可调不可增非主发电机的总潜在可增加发电有功功率 for 平滑
	float addAdjGenP1;//投运的可调不可增非主发电机的总潜在可增加发电有功功率 for 组播-
	double emergeTime;//紧急支撑开始时间
};

/*enum CONTROLTYPE     //控制操作性质
{
	CT_EQUIP_UNKNOWN,       // 0:无、未知
	CT_MICG_SYS_PARALLEL,   // 1:微电网并网
	CT_MICG_SYS_ISOLATED,   // 2:微电网离网
	CT_LOAD_SWI_BREAK,      // 3:切除负荷
	CT_LOAD_SWI_CONNECT,    // 4:投入负荷
	CT_GENE_SWI_BREAK,      // 5:切除发电机
	CT_GENE_SWI_CONNECT,    // 6:投入发电机
	CT_GENE_EQP_STOP,       // 7:停止发电机
	CT_GENE_EQP_START,      // 8:启动发电机
	CT_GENE_MOD_VF,         // 9:发电机切换为VF模式
	CT_GENE_MOD_PQ,         //10:发电机切换为PQ模式
	CT_GENE_INF_RESET,      //11:发电机故障复归
	CT_GENE_SET_POWER,      //12:调节发电机有功出力
	CT_GENE_SET_REPOWER,    //13:调节发电机无功出力
	CT_STOR_EQP_STOP,       //14:停止储能
	CT_STOR_EQP_START,      //15:启动储能
	CT_STOR_MOD_VF,         //16:储能切换为VF模式
	CT_STOR_MOD_PQ,         //17:储能切换为PQ模式
	CT_STOR_INF_RESET,      //18:储能故障复归
	CT_STOR_SET_POWER,      //19:调节储能有功出力
	CT_STOR_SET_REPOWER,    //20:调节储能无功出力
	CT_RACP_SWI_BREAK,      //21:切除无功补偿装置
	CT_RACP_SWI_CONNECT,    //22:投入无功补偿装置
	CT_RACP_SET_POWER,      //23:调节无功补偿装置有功出力
	CT_RACP_SET_REPOWER,    //24:调节无功补偿装置无功出力
	CT_TRANS_TAP_ASCEND,    //25:变压器分接头升
	CT_TRANS_TAP_DESCEND,   //26:变压器分接头降
	CT_TRANS_TAP_STOP,      //27:变压器分接头急停
	CT_END,
};

struct ControlLogInfo
{
	int controlId;//当前控制ID
	double ctrlTime;//当前操作时间
	char ctrlKind[64];//当前控制业务
	CONTROLTYPE ctrlType;//当前操作性质
	int equipId;//当前操作设备ID
	char stateVal0[64];//当前控制前状态
	char stateVal1[64];//当前控制目标状态
	int isManCtrl;//当前操作是否确认执行
	char ctrlUser[200];//当前控制确认人
	int ctrlResult;//当前控制结果
};*/

typedef struct
{
	int swithtype;           //切换动作性质：0不变  1并网 2离网（动态）
	intarray sonmicgrids;    //子微网列表（静态）
	int fathermicgridPos;    //父微网（静态）
	intarray toMainP;        //切换后的主电源(动态)
	int mainptype;           //切换后的主电源性质(动态)0并网 1离网柴油机为主电源 2离网pcs为主电源
}switchgridobj;

//////////////////////////////////////////////////////////////////////////////////////

enum CONTROLBUSINESS //控制业务
{
	CB_UNKNOWN,               //0: 未定义控制业务
	CB_MODESWITCH,            //1: 运行模式切换
	CB_BLARKSTART,            //2: 黑启动
	CB_ISLANDBALANCE,         //3: 离网能量平衡
	CB_CONTINENTRECALL,       //4: 并网状态恢复
	CB_EXCHANGEPOWER,         //5: 交换有功功率控制
	CB_POWERSMOOTH,           //6: 有功功率平滑控制
	CB_VOLTAGEREPOWER,        //7: 电压无功控制
	CB_STORAGEPOWER,          //8: 储能功率控制
	CB_STORAGESOC,            //9: 储能SOC维护
	CB_DGAUTOSTOP,            //10:DG停机维护
	CB_SCADASQCTRL,           //11:SCADA顺序控制
};

enum CONTROLREASON //控制原因
{
	CR_UNKNOWN,                 // 0: 未定义控制原因
	CR_RUNMODE_SWITCH=1,        // 1: 进入运行模式切换控制 ！
	CR_MODESWITCH_GENTOCONTI,   // 2: 旋转主电源切换到并网运行模式
	CR_MODESWITCH_STORTOCONTI,  // 3: PCS主电源切换到并网运行模式
	CR_MODESWITCH_CONTITOGEN,   // 4: 并网运行切换到旋转主电源模式
	CR_MODESWITCH_CONTITOSTOR,  // 5: 并网运行切换到PCS主电源模式
	CR_MODESWITCH_GENTOSTOR,    // 6: 旋转主电源切换到PCS主电源模式
	CR_MODESWITCH_STORTOGEN,    // 7: PCS主电源切换到旋转主电源模式
	CR_BLARKSTART=10,           //10: 进入黑启动控制 ！
	CR_BLARKSTART_BEFORE,       //11: 黑启动前的准备工作
	CR_BLARKSTART_MAINSOURCE,   //12: 黑启动一个主电源
	CR_BLARKSTART_AFTER,        //13: 黑启动后的恢复工作
	CR_ISLAND_BALANCE=20,       //20: 进入离网能量平衡 ！
	CR_ISLAND_FREQ_LOWER,       //21: 离网频率越下限
	CR_ISLAND_FREQ_UPPER,       //22: 离网频率越上限
	CR_ISLAND_POWER_LOWER,      //23: 离网主电源出力越经济下限
	CR_ISLAND_POWER_UPPER,      //24: 离网主电源出力越经济上限
	CR_ISLAND_POWER_NORMAL,     //25: 离网主电源出力正常
	CR_ISLAND_DATA_UNNORMAL,    //26: 离网电气信息异常
	CR_CONTINENT_CONTROL=30,    //30: 进入并网能量控制 ！
	CR_CONTINENT_RECALL,		//31: 并网状态恢复
	CR_EMERGEXCHP_SUPPORT,      //32: 交换功率紧急支撑控制
	CR_EMERGEXCHP_STOP,			//33: 交换功率紧急停运控制
	CR_EXCHPOWER_ANTIINVERSE,   //34: 防逆交换有功功率控制
	CR_EXCHPOWER_FIXEDVALUE,    //35: 定交换有功功率控制
	CR_EXCHPOWER_CURVE,         //36: 交换有功功率曲线维护
	CR_SMOOTH_EXCHPOWER=41,     //41: 交换有功功率平滑
	CR_SMOOTH_DGPOWER,          //42: 分布式电源出力平滑
	CR_VOLTAGE_REACTPOWER=50,   //50: 进入电压无功自动控制 ！
	CR_VQC_VOLT_LOWER,          //51: 电压越下限自动控制
	CR_VQC_VOLT_UPPER,          //52: 电压越上限自动控制
	CR_VQC_REPOWER_LOWER,       //52: 无功越下限自动控制
	CR_VQC_REPOWER_UPPER,       //53: 无功越上限自动控制
	CR_VQC_POWFACTOR_LOWER,     //54: 功率因数越下限控制
	CR_VQC_POWFACTOR_UPPER,     //55: 功率因数越上限控制
	CR_STOEAGEPOWER_CURVE=61,   //61: 储能有功出力曲线维护
	CR_STOEAGEPOWER_KEEP,       //62: 储能有功出力维持
	CR_STOEAGEREPOWER_KEEP,     //63: 储能无功出力维持
	CR_STOEAGESOC_KEEP,         //64: 储能SOC正常维护
	CR_STOEAGESOC_LOWER,        //65: 储能SOC越下限控制
	CR_STOEAGESOC_UPPER,        //66: 储能SOC越上限控制
	CR_DGNOPOWER_STOP=71,       //71: DG自由停机转停机控制
	CR_SEQUENCTRL_MANUAL=81,    //81: 人工顺序控制
	CR_SEQUENCTRL_TIMER,        //82: 定时顺序控制
	CR_SEQUENCTRL_TRIGGER,      //83: 条件触发顺序控制
};

enum CONTROLINDEX //控制索引
{
	CI_UNDEFINE,                // 0---0: 未定义控制原因
	CI_RUNMODE_SWITCH,          // 1---1: 进入运行模式切换控制！
	CI_MODESWITCH_GENTOCONTI,   // 2---2: 模式切换后主电源有功出力过高
	CI_MODESWITCH_STORTOCONTI,  // 3---3: 模式切换后主电源有功出力过低
	CI_MODESWITCH_CONTITOGEN,   // 4---4: 调节pcc点有功为0
	CI_MODESWITCH_CONTITOSTOR,  // 5---5: 调节pcc点无功为0
	CI_MODESWITCH_GENTOSTOR,    // 6---6: 下发模式切换命令
	CI_MODESWITCH_STORTOGEN,    // 7---7: 模式切换后主电源无功出力不满足条件
	CI_BLARKSTART,              // 8--10: 开始黑启动控制 ！
	CI_BLARKSTART_BEFORE,       // 9--11: 黑启动前的准备工作
	CI_BLARKSTART_MAINSOURCE,   //10--12: 黑启动一个主电源
	CI_BLARKSTART_AFTER,        //11--13: 黑启动后的恢复工作
	CI_ISLAND_BALANCE,          //12--20: 开始离网能量平衡 ！
	CI_ISLAND_FREQ_LOWER,       //13--21: 离网频率越下限
	CI_ISLAND_FREQ_UPPER,       //14--22: 离网频率越上限
	CI_ISLAND_POWER_LOWER,      //15--23: 离网主电源出力越经济下限
	CI_ISLAND_POWER_UPPER,      //16--24: 离网主电源出力越经济上限
	CI_ISLAND_POWER_NORMAL,     //17--25: 离网主电源出力正常
	CI_ISLAND_DATA_UNNORMAL,    //18--26: 离网电气信息异常
	CI_CONTINENT_CONTROL,       //19--30: 开始并网能量控制 ！
	CI_CONTINENT_RECALL,        //20--31: 并网状态恢复
	CI_EMERGEXCHP_SUPPORT,      //21--32: 交换功率紧急支撑控制
	CI_EMERGEXCHP_STOP,			//22--33: 交换功率紧急停运控制
	CI_EXCHPOWER_ANTIINVERSE,   //23--34: 防逆交换有功功率控制
	CI_EXCHPOWER_FIXEDVALUE,    //24--35: 定交换有功功率控制
	CI_EXCHPOWER_CURVE,         //25--36: 交换有功功率曲线维护
	CI_SMOOTH_EXCHPOWER,        //26--41: 交换有功功率平滑
	CI_SMOOTH_DGPOWER,          //27--42: 分布式电源出力平滑
	CI_VQC,                     //28--50: 开始电压无功自动控制 ！
	CI_VQC_VOLT_LOWER,          //29--51: 电压越下限自动控制
	CI_VQC_VOLT_UPPER,          //30--52: 电压越上限自动控制
	CI_VQC_REPOWER_LOWER,       //31--52: 无功越下限自动控制
	CI_VQC_REPOWER_UPPER,       //32--53: 无功越上限自动控制
	CI_VQC_POWFACTOR_LOWER,     //33--54: 功率因数越下限控制
	CI_VQC_POWFACTOR_UPPER,     //34--55: 功率因数越上限控制
	CI_STOEAGEPOWER_CURVE,      //35--61: 储能有功出力曲线维护
	CI_STOEAGEPOWER_KEEP,       //36--62: 储能有功出力维持
	CI_STOEAGEREPOWER_KEEP,     //37--63: 储能无功出力维持
	CI_STOEAGESOC_KEEP,         //38--64: 储能SOC正常维护
	CI_STOEAGESOC_LOWER,        //39--65: 储能SOC越下限控制
	CI_STOEAGESOC_UPPER,        //40--66: 储能SOC越上限控制
	CI_DGNOPOWER_STOP,          //41--71: DG自由停机转停机控制
	CI_SEQUENCTRL_MANUAL,       //42--81: 人工顺序控制
	CI_SEQUENCTRL_TIMER,        //43--82: 定时顺序控制
	CI_SEQUENCTRL_TRIGGER,      //44--83: 条件触发顺序控制
};

const struct ControlReason
{
	CONTROLBUSINESS ctrlTask;
	CONTROLREASON ctrlCause;
	char ctrlDescr[64];
} 
g_ctrlReasons[] = 
{
	{ CB_UNKNOWN,    CR_UNKNOWN,                 "未定义控制业务" },
	{ CB_MODESWITCH, CR_RUNMODE_SWITCH,          "模式切换" }, // ！
	{ CB_MODESWITCH, CR_MODESWITCH_GENTOCONTI,   "模式切换" },
	{ CB_MODESWITCH, CR_MODESWITCH_STORTOCONTI,  "模式切换" },
	{ CB_MODESWITCH, CR_MODESWITCH_CONTITOGEN,   "模式切换" },
	{ CB_MODESWITCH, CR_MODESWITCH_CONTITOSTOR,  "模式切换" },
	{ CB_MODESWITCH, CR_MODESWITCH_GENTOSTOR,    "模式切换" },
	{ CB_MODESWITCH, CR_MODESWITCH_STORTOGEN,    "模式切换" },
	{ CB_BLARKSTART, CR_BLARKSTART,              "处于黑启动" }, // ！
	{ CB_BLARKSTART, CR_BLARKSTART_BEFORE,       "黑启动-启动前准备" },
	{ CB_BLARKSTART, CR_BLARKSTART_MAINSOURCE,   "黑启动-启动一个主电源" },
	{ CB_BLARKSTART, CR_BLARKSTART_AFTER,        "黑启动-启动后恢复" },
	{ CB_ISLANDBALANCE, CR_ISLAND_BALANCE,       "处于离网能量平衡" }, // ！
	{ CB_ISLANDBALANCE, CR_ISLAND_FREQ_LOWER,    "离网能量平衡-频率越下限" },
	{ CB_ISLANDBALANCE, CR_ISLAND_FREQ_UPPER,    "离网能量平衡-频率越上限" },
	{ CB_ISLANDBALANCE, CR_ISLAND_POWER_LOWER,   "离网能量平衡-主电源出力越下限" },
	{ CB_ISLANDBALANCE, CR_ISLAND_POWER_UPPER,   "离网能量平衡-主电源出力越上限" },
	{ CB_ISLANDBALANCE, CR_ISLAND_POWER_NORMAL,  "离网能量平衡-主电源出力正常" },
	{ CB_ISLANDBALANCE, CR_ISLAND_DATA_UNNORMAL, "离网能量平衡-采集数据异常" },
	{ CB_CONTINENTRECALL, CR_CONTINENT_CONTROL,  "处于并网能量控制" }, // ！
	{ CB_CONTINENTRECALL, CR_CONTINENT_RECALL,   "并网能量控制-并网状态恢复" },
	{ CB_EXCHANGEPOWER, CR_EMERGEXCHP_SUPPORT,   "并网能量控制-交换功率紧急支撑控制" },
	{ CB_EXCHANGEPOWER, CR_EMERGEXCHP_STOP,      "并网能量控制-交换功率紧急停运控制" },
	{ CB_EXCHANGEPOWER, CR_EXCHPOWER_ANTIINVERSE,"并网能量控制-防逆交换有功功率控制" },
	{ CB_EXCHANGEPOWER, CR_EXCHPOWER_FIXEDVALUE, "并网能量控制-定交换有功功率控制" },
	{ CB_EXCHANGEPOWER, CR_EXCHPOWER_CURVE,      "并网能量控制-交换有功功率曲线维护" },
	{ CB_POWERSMOOTH, CR_SMOOTH_EXCHPOWER,       "并网能量控制-交换有功功率平滑" },
	{ CB_POWERSMOOTH, CR_SMOOTH_DGPOWER,         "并网能量控制-分布式电源出力平滑" },
	{ CB_VOLTAGEREPOWER, CR_VOLTAGE_REACTPOWER,  "处于电压无功自动控制" }, // ！
	{ CB_VOLTAGEREPOWER, CR_VQC_VOLT_LOWER,      "VQC-电压越下限" },
	{ CB_VOLTAGEREPOWER, CR_VQC_VOLT_UPPER,      "VQC-电压越上限" },
	{ CB_VOLTAGEREPOWER, CR_VQC_REPOWER_LOWER,   "VQC-无功越下限" },
	{ CB_VOLTAGEREPOWER, CR_VQC_REPOWER_UPPER,   "VQC-无功越上限" },
	{ CB_VOLTAGEREPOWER, CR_VQC_POWFACTOR_LOWER, "VQC-功率因数越下限" },
	{ CB_VOLTAGEREPOWER, CR_VQC_POWFACTOR_UPPER, "VQC-功率因数越上限" },
	{ CB_STORAGEPOWER, CR_STOEAGEPOWER_CURVE,    "储能出力维护-有功出力曲线维护" },
	{ CB_STORAGEPOWER, CR_STOEAGEPOWER_KEEP,     "储能出力维护-有功出力维持" },
	{ CB_STORAGEPOWER, CR_STOEAGEREPOWER_KEEP,   "储能出力维护-无功出力维持" },
	{ CB_STORAGESOC, CR_STOEAGESOC_KEEP,         "储能SOC维护-SOC正常" },
	{ CB_STORAGESOC, CR_STOEAGESOC_LOWER,        "储能SOC维护-SOC越下限" },
	{ CB_STORAGESOC, CR_STOEAGESOC_UPPER,        "储能SOC维护-SOC越上限" },
	{ CB_DGAUTOSTOP, CR_DGNOPOWER_STOP,          "DG停机维护-自由停机转停机控制" },
	{ CB_SCADASQCTRL, CR_SEQUENCTRL_MANUAL,      "SCADA顺序控制-人工顺制" },
	{ CB_SCADASQCTRL, CR_SEQUENCTRL_TIMER,       "SCADA顺序控制-定时顺制" },
	{ CB_SCADASQCTRL, CR_SEQUENCTRL_TRIGGER,     "SCADA顺序控制-条件触发顺制" },
};

const int g_ctrlReasonNum = sizeof(g_ctrlReasons) / sizeof(ControlReason);

inline int GetControlBusinessIndex(int ctrlReason)
{
	for(int index = 0; index < g_ctrlReasonNum; ++index)
	{
		if(g_ctrlReasons[index].ctrlCause == ctrlReason) return index;
	}
	return 0;
};

#endif
