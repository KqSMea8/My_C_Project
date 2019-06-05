//ismicgriddao.h

#ifndef _ICSMICGRIDDAO_PENGSHIKANG_20100324_H_
#define _ICSMICGRIDDAO_PENGSHIKANG_20100324_H_

#include "../../ibasicdao.h"                     // for IBasicDao
#include "../../../scadasrv/scadadatadef.h"      // for ControlLogInfo
#include "../../../smgsrv/smgdatadef.h"          // for MicgridObectInfo
#include "../../../smgsrv/genstatisdef.h"        // for GeneClassStatisInfo

#define CSMICGRIDDAO_CLASSID    "csmicgriddao"
#define CSMICGRIDDAO_INTFID     "ismicgriddao"

class IVoltageDao;
class ISysInfoDao;
class ISmoothCtrlDao;

class ISMicgridDao : virtual public IBasicDao
{
public:
	//将数据表的动态信息写入库中
	virtual void WriteDynamicInfo1() = 0;

	virtual void SetVoltageDao(IVoltageDao* pVoltage) = 0;//设置电压等级实体对象
	virtual void SetSysInfoDao(ISysInfoDao* pSysInfo) = 0;//设置系统信息实体对象
	virtual void SetSmoothCtrlDao(ISmoothCtrlDao* pSmoothCtrl) = 0;//设置平滑控制实体对象
	
	virtual void InitAllMicgridObjectStaticInfo(bool isSwiMgObj=false) = 0;//所有子微网静态信息初始化
	virtual void InitAllMicgridObjectDynamicInfo(bool isSwiMgObj=false) = 0;//所有子微网动态信息初始化
	virtual void InitAllMicgridBufferPowerInfo() = 0;//初始化所有子微网的累计功率信息
	
	virtual double GetBaseU(int pos) = 0;            //得到系统基准电压	
	virtual double GetMaxU(int pos) = 0;             //得到系统最大允许电压
	virtual double GetMinU(int pos) = 0;             //得到系统最小允许电压
	virtual double GetMaxF(int pos) = 0;             //得到系统最大允许频率
	virtual double GetMinF(int pos) = 0;             //得到系统最小允许频率
	virtual double GetAimF(int pos) = 0;             //得到孤岛目标频率
	virtual double GetLoadAdjustCoef(int pos) = 0;   //得到负荷调节系数
	virtual int GetParentMicgridID(int pos) = 0;     //得到上级微电网ID
	virtual int GetConnectStatusID(int pos) = 0;     //得到并网标志状态量ID
	virtual int GetConnectFlag(int pos) = 0;         //得到微电网并网运行标志
	virtual bool IsRootMicgridPos(int pos) = 0;      //判断是否为根微电网
	virtual bool IsSonMicgridID(int id, int dadId) = 0;//是否为指定微电网ID的子微电网ID
	virtual int GetRootMicgridIDById(int id) = 0;    //得到根微电网ID
	virtual double GetTurnTime(int pos) = 0;         //得到最近的并离网切换时间
	virtual double GetStaticTime(int pos) = 0;       //得到统计开始时间
	virtual double GetIslandRunTime(int pos) = 0;    //得到孤岛总运行时间
	virtual int GetVoltGradeId(int pos) = 0;         //得到系统电压等级ID	
	virtual double GetSysU(int pos) = 0;             //得到系统电压
	virtual double GetSysUById(int id) = 0;          //得到系统电压
	virtual double GetSysF(int pos) = 0;             //得到系统频率
	virtual int GetSysUState(int pos, double& smgU) = 0;//得到系统电压合格状态：-2--未启动；-1--越下限；0--合格；1--越上限。
	virtual int GetSysFState(int pos, double& smgF) = 0;//得到系统频率合格状态：-2--未启动；-1--越下限；0--合格；1--越上限。
	virtual double GetExchangeP(int pos) = 0;        //得到交换有功功率
	virtual double GetExchangeQ(int pos) = 0;        //得到交换无功功率
	virtual double GetLackingP(int pos) = 0;         //得到孤网有功缺口
	virtual double GetLackingQ(int pos) = 0;         //得到孤网无功缺口
	virtual double GetTotalGenP(int pos) = 0;        //得到总发电有功出力
	virtual double GetTotalGenQ(int pos) = 0;        //得到总发电无功出力
	//virtual double GetWindP(int pos) = 0;            //得到风力发电有功出力 delete_by_zp_130315
	//virtual double GetWindQ(int pos) = 0;            //得到风力发电无功出力 delete_by_zp_130315
	//virtual double GetPvP(int pos) = 0;              //得到光伏发电有功出力 delete_by_zp_130315
	//virtual double GetPvQ(int pos) = 0;              //得到光伏发电无功出力 delete_by_zp_130315
	//virtual double GetTurbineP(int pos) = 0;         //得到燃气轮机有功出力 delete_by_zp_130315
	//virtual double GetTurbineQ(int pos) = 0;         //得到燃气轮机无功出力 delete_by_zp_130315
	//virtual double GetFuelcellP(int pos) = 0;        //得到燃料电池有功出力 delete_by_zp_130315
	//virtual double GetFuelcellQ(int pos) = 0;        //得到燃料电池无功出力 delete_by_zp_130315
	virtual double GetStorageP(int pos) = 0;         //得到储能有功出力
	virtual double GetStorageQ(int pos) = 0;         //得到储能无功出力
	virtual double GetStorageMaxP(int pos) = 0;      //得到储能最大有功出力
	virtual double GetTotalLoadP(int pos) = 0;       //得到总有功负荷
	virtual double GetTotalLoadQ(int pos) = 0;       //得到总无功负荷
	virtual double GetSensitiveLoadP(int pos) = 0;   //得到灵敏负荷有功
	virtual double GetSensitiveLoadQ(int pos) = 0;   //得到灵敏负荷无功
	virtual double GetControllableLoadP(int pos) = 0;//得到可控负荷有功
	virtual double GetControllableLoadQ(int pos) = 0;//得到可控负荷无功
	virtual double GetCutedLoadP(int pos) = 0;       //得到可切负荷有功
	virtual double GetCutedLoadQ(int pos) = 0;       //得到可切负荷无功
	//--------------zff_0814_0815_new_add-----------------------------//
	virtual double GetMaxVol2(int pos) = 0;          //得到系统电压紧急控制上限
	virtual double GetMinVol2(int pos) = 0;          //得到系统电压紧急控制下限
	virtual double GetMaxF2(int pos) = 0;            //得到系统频率紧急控制上限
	virtual double GetMinF2(int pos) = 0;            //得到系统频率紧急控制下限

	virtual int GetCurStyleId(int pos) = 0;          //得到当前运行方式ID
    virtual double GetLastSwitchTime(int pos) = 0;   //得到上次运行方式切换时间
	virtual bool SetLastSwitchTime(int pos, double switchtime) = 0;   //设置上次运行方式切换时间   --sunr add
 	virtual bool SetCurStyle(int pos, int styleId) = 0;//设置当前运行方式ID
   //--------------------------------------------------------//
	virtual int ModifyConnectFlag(int pos, bool isConnect, double curTime) = 0;//修改微电网并网运行标志
	virtual bool SetStaticTime(int pos, double durTime) = 0;//设置统计开始时间
	virtual bool SetIslandRunTime(int pos, double runTime) = 0;//设置孤岛总运行时间
	virtual bool SetAimF(int pos, double aimF) = 0;//设置孤岛目标频率
	virtual bool SetSysUF(int pos, double sysU, double sysF) = 0;//设置系统电压
	virtual bool SetExchangePQ(int pos, double valueP, double valueQ) = 0;//设置交换功率
	virtual bool SetLackingPQ(int pos, double valueP, double valueQ) = 0;//设置孤网功率缺口
	//增加子微网总的发电功率. 参数：isRefGener--是否为标杆发电机；canAdjP--是否为功率可调发电机
	virtual bool IncreaseTotalGenPQ(MicgridObectInfo* pCurMgObj, const GeneClassStatisInfo& genSttsInfo, 
		int genType, int runState, bool isRefGener, bool canAdjP) = 0;
	virtual bool IncreaseTotalLoadPQ(MicgridObectInfo* pCurMgObj, int loadType, double valueP, double valueQ) = 0; //增加子微网总的负荷功率

	//设置指定位置微网的交换功率和缺额功率
	virtual void SetExchangeAndLackingPQ(int pos) = 0;

	virtual MicgridObectInfo* GetMicgridObject(int pos) = 0;
	virtual MicgridObectInfo* GetSwitchSMGObject(int pos) = 0;
	virtual void InitSmoothAttrOfMicgridObject(MicgridObectInfo* pCurMgObj) = 0;//子微网的平滑控制静态信息初始化
	
	virtual int GetStartState(int pos) = 0;       //得到黑启动状态
	virtual double GetStartTime(int pos) = 0;     //得到黑启动开始时间
	virtual double GetCurRemainP(int pos) = 0;    //得到当前主电源出力冗余量
	virtual int GetCurActType(int pos) = 0;       //得到当前操作性质
	virtual int GetCurObjectId(int pos) = 0;      //得到当前操作对象ID
	virtual int GetCurObjectType(int pos) = 0;    //得到当前操作对象类型
	virtual double GetCurTime(int pos) = 0;       //得到当前操作时间
	virtual double GetPrevreMainP(int pos) = 0;   //得到先前主电源出力冗余量
	virtual int GetPrevActType(int pos) = 0;      //得到先前操作性质
	virtual int GetPrevObjectId(int pos) = 0;     //得到先前操作对象ID
	virtual bool SetStartState(int pos, int start) = 0;      //设置黑启动状态
	virtual bool SetStartTime(int pos, double time) = 0;     //设置黑启动开始时间
	virtual bool SetCurRemainP(int pos, double remainP) = 0; //设置当前主电源出力冗余量
	virtual bool SetCurActType(int pos, int actType) = 0;    //设置当前操作性质
	virtual bool SetCurObjectId(int pos, int objectId) = 0;  //设置当前操作对象ID
	virtual bool SetCurObjectType(int pos, int objType) = 0; //设置当前操作对象类型
	virtual bool SetCurTime(int pos, double time) = 0;       //设置当前操作时间
	virtual bool SetPrevreMainP(int pos, double remainP) = 0;//设置先前主电源出力冗余量
	virtual bool SetPrevActType(int pos, int actType) = 0;   //设置先前操作性质
	virtual bool SetPrevObjectId(int pos, int objectId) = 0; //设置先前操作对象ID
	virtual void InitCurControlInfo(int id, bool needGuard, ControlLogInfo& ctrlInfo) = 0;//初始化当前操作信息
	virtual bool GetCurControlInfo(int pos, ControlLogInfo& ctrlInfo) = 0;//得到当前操作信息
	virtual bool SetCurControlInfoByID(int id, const ControlLogInfo& ctrlInfo, bool isBefore=false) = 0;//设置当前操作信息
	virtual bool SetCurControlInfo(int pos, const ControlLogInfo& ctrlInfo, bool isBefore=false) = 0;//设置当前操作信息
	virtual bool SetCurControlState(int pos, int ctrlReason) = 0;//设置当前操作的条件检查类型

	virtual bool IsEnableStart(int pos) = 0;      //判断是否存在黑启动功能
	virtual bool InitAutoBlackStart(int pos, double curTime) = 0;//进入自动黑启动状态
	virtual bool EndBlackStart(int pos, double curTime) = 0;
	virtual bool RecordBlackStart(int pos, int actType, int objectId, double remainP, double curTime) = 0;
	virtual bool RecordBlackStartByID(int id, int actType, int objectId) = 0;

	//-------------sunr add-------------------//
	virtual double GetMaxWindRate(int pos) = 0;              //得到风力发电允许最高渗透率
	virtual double GetMaxPVRate(int pos) = 0;                //得到风力发电允许最高渗透率
	virtual double GetCurWindRate(int pos) = 0;              //得到风力发电当前渗透率
	virtual double GetCurPVRate(int pos) = 0;                //得到光伏当前渗透率
	virtual bool SetCurWindRate(int pos, double rate) = 0;   //设置风力发电当前渗透率
	virtual bool SetCurPVRate(int pos, double rate) = 0;     //设置光伏当前渗透率
	virtual bool IsActive(int pos) = 0;                      //判断微电网是否带电
	virtual switchgridobj* GetSwitchObject(int pos) = 0;
	virtual int GetStorFreqCtrlStateId(int pos) = 0;         //得到储能的频率调节状态ID（遥信量ID）
	virtual int GetStorVoltCtrlStateId(int pos) = 0;         //得到储能的电压调节状态ID（遥信量ID）

	virtual double GetCurCap(int pos) = 0;                   //得到微网当前运行容量
	virtual double GetSpareCap(int pos) = 0;                 //得到微网当前备用容量
	virtual int GetCurCheckType(int pos) = 0;                //得到当前条件检查类型
	virtual int GetCtrlReason(int pos) = 0;                  //得到当前控制原因

	virtual bool SetCurCap(int pos, double& cap) = 0;        //设置微网当前运行容量
	virtual bool SetSpareCap(int pos, double& cap) = 0;      //设置微网当前备用容量
	virtual bool SetCurCheckType(int pos, int& type) = 0;    //设置当前条件检查类型
	virtual bool SetCtrlReason(int pos, int& reason) = 0;    //设置当前控制原因
	virtual double GetTotalGenCapacity(int pos) = 0;         //得到微网装机容量
	//微电网有功出力调节一次的最大调节量
	virtual double GetMicgridMaxAdjustPower(MicgridObectInfo* pCurMgObj) = 0;

	//得到当前AGC执行计划ID
	virtual int GetCurAGCPlanID(int pos) = 0;
	//得到当前AGC有功目标值
	virtual double GetCurAGCAimVal(int pos) = 0;
	//保存当前AGC执行计划ID和有功目标值
	virtual bool SaveCurAGCPlanValue(int pos, int agcPlanId, double aimPower) = 0;
	//是否存在“当前AGC执行计划ID”字段
	virtual bool HasAGCPlanID() = 0;

	//读取当前控制记录存储标志
	virtual int ReadSaveFlag(int pos) = 0;
	//保存当前操作信息
	virtual bool SaveCurControlInfo(int pos) = 0;

	//得到AGC允许控制状态
	virtual bool CanControlAgc(int pos) = 0;
	//保存保存AGC允许控制状态标志
	virtual bool SaveCanCtrlAgcFlag(int pos, bool canCtrl) = 0;

};
#endif
