//scadadatadef.h
#ifndef _SCADADATADEFINE_PENGSHIKANG_20080714_H_
#define _SCADADATADEFINE_PENGSHIKANG_20080714_H_

#include "../idataproxy.h"             // for CAPP_SDO_Status

#define TOUPPERALARMID  101 //越上限报警类型ID
#define TOLOWERALARMID  102 //越下限报警类型ID
#define TOUUPPERALARMID 103 //越上上限报警类型ID
#define TOLLOWERALARMID 104 //越下下限报警类型ID
#define TONORMALALARMID 105 //越限恢复报警类型ID
#define TOABRUPTALARMID 106 //跳变报警类型ID

#define TOSOEALARMID    305 //SOE报警类型ID
#define TOREVERTALARMID 308 //复归超时报警类型ID
#define TOCHANGECOUNTID 309 //操作变位次数越限报警类型ID
#define TOFAULTCOUNTID  310 //事故变位次数越限报警类型ID
#define TODISCORDALMID  311 //双位置遥信量不一致报警类型ID
#define TOCHANNELALMID  1001//通道状态变更报警类型ID
#define TOCHANNELEXCID  1002//通道状态切换为主报警类型ID

enum QUALITYPE
{
	QT_UNINIT=1,    //未初始化
	QT_DATAOVER,    //溢出
	QT_METEROVER,   //超值域
	QT_DISCORD,     //不一致
	QT_DOUBLTFUL,   //可疑
	QT_FAULT,       //故障
	QT_OLDDATA,     //老数据
	QT_NORMAL=8,    //正常
	QT_UNCHANGE,    //不变
	QT_ABRUPT,      //跳变
	QT_UUPPEROVER,  //越上上限
	QT_UPPEROVER,   //越上限
	QT_LOWEROVER,   //越下限
	QT_LLOWEROVER,  //越下下限
};

enum STATUSTYPE     //状态值类型
{
	ST_UNKNOWN,        //无、未知
		ST_SWI_BREAK,      //1:开关分
		ST_SWI_CONNECT,    //2:开关合
		ST_EQP_STOP,       //3:设备停止
		ST_EQP_START,      //4:设备启动
		ST_ALM_FAULT,      //5:设备故障、事故信号动作
		ST_ALM_EXCEP,      //6:预告信号动作
		ST_INF_BEFALL,     //7:保护信号动作
		ST_INF_RESET,      //8:信号复归
		ST_RYB_EXIT,       //9:软压板退出
		ST_RYB_RUN,        //10:软压板投入
		ST_EQP_REPAIR,     //11：设备检修
		ST_MOD_VF,         //12:VF模式
		ST_MOD_PQ,         //13:PQ模式
		ST_SYS_PARALLEL,   //14:并网
		ST_SYS_ISOLATED,   //15:离网
		ST_SYS_ENABLE,     //16:启用/启控/允许充放电
		ST_SYS_DISABLE,    //17:禁用/禁控/禁止充放电
		ST_STOR_START,     //18:储能黑启动
		ST_GEN_STANDBY,    //19:电源并网待机
		ST_GEN_LMTPOWER,   //20:电源限功率
		ST_END,
		ST_TAP_ASCEND=25,  //05:分接头升
		ST_TAP_DESCEND,    //06:分接头降
		ST_TAP_STOP,       //07:分接头急停
};

enum OPERATETYPE     //控制操作类型
{
	OT_UNKNOWN,        //无、未知
		OT_SWI_BREAK,      //1:开关分
		OT_SWI_CONNECT,    //2:开关合
		OT_EQP_STOP,       //3:设备停止
		OT_EQP_START,      //4:设备启动
		OT_TAP_ASCEND,     //5:分接头升
		OT_TAP_DESCEND,    //6:分接头降
		OT_TAP_STOP,       //7:分接头急停
		OT_INF_RESET,      //8:信号复归
		OT_RYB_EXIT,       //9:软压板退出
		OT_RYB_RUN,        //10:软压板投入
		OT_SETAREA_ALTER,  //11:定值区切换
		OT_MOD_VF,         //12:VF模式切换
		OT_MOD_PQ,         //13:PQ模式切换
		OT_SYS_PARALLEL,   //14:并网
		OT_SYS_ISOLATED,   //15:离网
		OT_SYS_ENABLE,     //16:启用/启控
		OT_SYS_DISABLE,    //17:禁用/禁控
		OT_STOR_START,     //18:储能黑启动
		OT_SYS_SWITCH,     //19:运行方式切换
		//OT_STANDBY,        //20:备用
		OT_END,
};

typedef struct 
{
	double dealTime;          //处理时间
	CAPP_SDO_Status* pObject; //状态量对象
	int objId;                //状态量ID
	int objPos;               //状态量位置
	int ssrcPos;              //状态量多数据源位置
	int calValue;             //计算值
}WaitingStatus, *PWaitingStatus;//等待处理的状态量对象

typedef struct 
{
	double dealTime;          //处理时间
	int objId;                //状态量ID
	int objPos;               //状态量位置
	int ssrcPos;              //状态量多数据源位置
	int alarmId;              //报警对象ID
}RevertStatus, *PRevertStatus;//等待复归超时报警的状态量对象

typedef struct 
{
	double dealTime;          //处理时间
	CAPP_SDO_Status* pObject1;//状态量对象1
	CAPP_SDO_Status* pObject2;//状态量对象2
	int eqpId;                //设备ID
	int objId1;               //状态量ID1
	int objId2;               //状态量ID2
	int objPos1;              //状态量位置1
	int objPos2;              //状态量位置2
	int srcPos1;              //状态量多数据源位置1
	int srcPos2;              //状态量多数据源位置2
	int calValue1;            //计算值1
	int calValue2;            //计算值2
}DoubleStatus, *PDoubleStatus;//双位置状态量对象

struct CtrlGroup //一组相关的控制量
{
	int groupId;
	int count;
	int* ctrlIds;
};

struct AlarmObjectInfo
{
	double dTime;     //报警发生时间
	int nObjId;       //报警对象ID
	char objType[32]; //报警对象类型
	char objDesc[128];//报警对象描述
	char objPath[64]; //报警对象路径
	char almPage[64]; //报警推画面文件
	char almVoice[64];//报警语音文件
	char almUserId[64];//报警确认人ID
};

struct MultSrcObjInfo
{
	int m_priority;
	int m_position;
	int m_commSrcId;
	int m_commPointId;
};

enum CONTROLTYPE     //控制操作性质
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
	CT_STOR_SET_SOC,        //20:因维护SOC而调节储能有功出力++
	CT_STOR_SET_REPOWER,    //21:调节储能无功出力

	CT_RACP_SWI_BREAK,      //22:切除无功补偿装置
	CT_RACP_SWI_CONNECT,    //23:投入无功补偿装置
	CT_RACP_SET_POWER,      //24:调节无功补偿装置有功出力
	CT_RACP_SET_REPOWER,    //25:调节无功补偿装置无功出力

	CT_TRANS_TAP_ASCEND,    //26:变压器分接头升
	CT_TRANS_TAP_DESCEND,   //27:变压器分接头降
	CT_TRANS_TAP_STOP,      //28:变压器分接头急停

	CT_MICG_SYS_SWITCH,     //29:微电网运行方式切换
	CT_MICG_SYS_ABNORMAL,   //30:微电网运行数据异常

	CT_GROUP_CONTROL,       //31:顺序控制

	CT_STOR_SWI_BREAK,      //32:切除储能
	CT_STOR_SWI_CONNECT,    //33:投入储能

	CT_END,
};

struct ControlLogInfo
{
	//double operateId;//本次操作标识号
	int smgId;//当前微电网ID
	int equipId;//当前设备ID
	int controlId;//当前控制ID
	double ctrlTime;//当前操作时间
	//char ctrlKind[64];//当前控制业务
	CONTROLTYPE ctrlType;//当前操作性质
	char stateVal0[64];//当前控制前状态
	char stateVal1[64];//当前控制目标状态
	int isManCtrl;//当前操作是否确认执行
	char ctrlUser[256];//当前控制确认人
	int ctrlResult;//当前控制结果
	int ctrlReason;//当前控制原因
	int equipType;//当前操作设备类型
};

enum CONTROLORIGIN
{
	MANUCTRL, AUTOCTRL, DISPCTRL,
};

enum AUTOEXECUTESELECTCMD
{
	AESC_STOP,        //0--停止自动执行
	AESC_SELECT,      //1--开启自动执行
	AESC_CONTROL,     //2--选控自动转直控
	AESC_NOGUARD,     //3--跳过监护自动执行
};

typedef struct 
{
	int statusId;             //状态量ID
	int curValue;             //当前值
	double curTime;           //当前时间
	int lastValue;            //上次值
	double lastTime;          //上次时间
	int faultNum;             //故障变位统计次数
}HisStatusInfo, *PHisStatusInfo;//遥信量变位后的历史存储信息

#endif
