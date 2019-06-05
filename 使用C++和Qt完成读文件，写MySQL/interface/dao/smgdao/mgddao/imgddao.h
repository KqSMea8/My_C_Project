//imgddao.h

#ifndef _IMGDDAO_PENGSHIKANG_20100921_H_
#define _IMGDDAO_PENGSHIKANG_20100921_H_

#include "../../ibasicdao.h"                     // for IBasicDao
#include "../../../smgsrv/smgdatadef.h"          // for MicgridObectInfo、BusDeviceInfo

#define MGDDAO_CLASSID    "cmgddao"
#define MGDDAO_INTFID     "imgddao"

class ICommSrcDao;
class IEquipDao;
class IAnalogDao;
class IStatusDao;
class IAccumuDao;
class IControlDao;
class ISMicgridDao;
class IBusDao;
class IMGLineDao;
class ITransformerDao;

struct MgdOuterObject
{
	ICommSrcDao*& _pCommSrc;
	IEquipDao*& _pEquip;//不能为空（NULL）
	IAnalogDao*& _pAnalog;//不能为空（NULL）
	IStatusDao*& _pStatus;//不能为空（NULL）
	IAccumuDao*& _pAccumul;//不能为空（NULL）
	IControlDao*& _pControl;//不能为空（NULL）
	ISMicgridDao*& _pSMicgrid;//不能为空（NULL）
	IBusDao*& _pBus;
	IMGLineDao*& _pMGLine;
	ITransformerDao*& _pTransformer;
	MgdOuterObject(ICommSrcDao*& pCommSrc, IEquipDao*& pEquip, IAnalogDao*& pAnalog, IStatusDao*& pStatus, IAccumuDao*& pAccumul, IControlDao*& pControl, 
		ISMicgridDao*& pSMicgrid, IBusDao*& pBus, IMGLineDao*& pMGLine, ITransformerDao*& pTransformer) 
		: _pCommSrc(pCommSrc), _pEquip(pEquip), _pAnalog(pAnalog), _pStatus(pStatus), _pAccumul(pAccumul), _pControl(pControl), 
		  _pSMicgrid(pSMicgrid), _pBus(pBus), _pMGLine(pMGLine), _pTransformer(pTransformer){ }
};

class IMgdDao : virtual public IBasicDao
{
public:	
	//初始化依赖的外部实体对象
	virtual void InitOuterObject(const MgdOuterObject& outerObject) = 0;

	//根据微网对象的位置设置各个量测量实时值
	virtual void SetMeasureValues(int pos, int& nBrkPos, double& dBrkTime, double& dValueP, double& dValueQ, double& dValueI, bool isGen=false) = 0;

	//将指定位置的微网对象加入已按当前有功从大到小排序的对象列表中
	virtual void AddObjectIntoSortedPowerList(int pos, intarray& posList) = 0;
	
	//利用已排序的功率对象列表来增长功率,平衡功率缺乏现象
	virtual bool IncreasePowerFromSortedList(int* incList, int incCount, double lowerP, double upperP, 
										int actFlag, int* actList, int& actCount, double& lackP) = 0;
	//利用已排序的功率对象列表来降低功率,平衡功率盈余现象
	virtual bool DecreasePowerFromSortedList(int* decList, int decCount, double lowerP, double upperP, 
										int actFlag, int* actList, int& actCount, double& surplusP) = 0;
	virtual bool DecreasePowerFromSortedList(int* decList, int decCount, double maxplusP, 
										int actFlag, int* actList, int& actCount, double& surplusP) = 0;
	//根据微网对象位置得到额定容量
	virtual double GetCapacity(int pos) = 0;
	//根据微网对象位置得到路径
	virtual const char* GetPathReference(int pos) = 0;
	//根据微网对象位置得到所连母线ID
	virtual int GetBusID(int pos) = 0;
	//根据微网对象位置得到其接入点的额定电压
	virtual double GetBaseVoltage(int pos) = 0;
	//根据微网对象位置判断其接入点的电压状态是否正常
	virtual bool IsNormalVoltage(int pos) = 0;
	//根据微网对象位置判断其上级对象电压是否处于正常状态
	virtual bool IsNormalBusVoltage(int pos) = 0;
	//根据微网对象位置判断其是否属于指定微电网
	virtual bool IsMemberOfMicgrid(int pos, int mgId, bool chechVF=true) = 0;
	//根据微网对象位置得到自身的子微网ID
	virtual int GetSelfMicgridID(int pos) = 0;
	//根据微网对象位置得到其上级对象所处的微网ID
	virtual int GetSubMicGridID(int pos, bool chechVF=true) = 0;
	//根据微网对象位置得到其上级对象所处的根微网ID
	virtual int GetRootMicGridID(int pos, bool chechVF=true) = 0;
	//根据微网对象位置得到其上级对象所处的微网对象
	virtual MicgridObectInfo* GetSubMicGrid(int pos, bool chechVF=true) = 0;
	//根据微网对象位置得到其上级对象所处的根微网对象
	virtual MicgridObectInfo* GetRootMicGrid(int pos, bool chechVF=true) = 0;
	//根据微网对象位置得到其上级对象所处的微电网ID和活岛ID
	virtual bool GetMicgridIdAndActiveIslandId(int pos, int& mgId, int& isleId) = 0;

	//根据微网对象位置得到开关状态遥信ID
	virtual int GetPosID(int pos) = 0;
	//根据微网对象位置得到开关状态合遥控ID
	virtual int GetPosCtrlID(int pos) = 0;
	//根据微网对象位置得到开关状态分遥控ID
	virtual int GetCutCtrlID(int pos) = 0;

	//根据微网对象位置得到P、Q、I遥测ID
	virtual bool GetPQI_IDs(int pos, int& nPId, int& nQId, int& nIId) = 0;
	//根据微网对象位置得到P遥测ID
	virtual int GetPID(int pos) = 0;
	//根据微网对象位置得到Q遥测ID
	virtual int GetQID(int pos) = 0;
	//根据微网对象位置得到I遥测ID
	virtual int GetIID(int pos) = 0;

	//根据微网对象位置得到当前开关状态
	virtual int GetCurPos(int pos) = 0;
	//根据微网对象位置设置当前开关状态
	virtual bool SetCurPos(int pos, int kgPos) = 0;
	//根据微网对象位置得到当前有功出力
	virtual double GetCurP(int pos) = 0;
	//根据微网对象位置设置当前有功出力
	virtual bool SetCurP(int pos, double currP) = 0;
	//根据微网对象位置得到当前无功出力
	virtual double GetCurQ(int pos) = 0;
	//根据微网对象位置设置当前无功出力
	virtual bool SetCurQ(int pos, double currQ) = 0;
	//根据微网对象位置得到当前电流
	virtual double GetCurI(int pos) = 0;
	
	//根据微网对象位置得到P品质
	virtual int GetPQlty(int pos) = 0;
	//根据微网对象位置得到Q品质
	virtual int GetQQlty(int pos) = 0;
	//根据微网对象位置得到I品质
	virtual int GetIQlty(int pos) = 0;
	
	//根据微网对象位置得到控制计划开关位置
	virtual int GetPlanPos(int pos) = 0;
	//根据微网对象位置设置控制计划开关位置
	virtual bool SetPlanPos(int pos, int planPos) = 0;
	
	//根据微网对象位置得到控制计划有功出力
	virtual double GetPlanP(int pos) = 0;
	//根据微网对象位置设置控制计划有功出力
	virtual bool SetPlanP(int pos, double planP) = 0;
	
	//根据微网对象位置得到控制计划无功出力
	virtual double GetPlanQ(int pos) = 0;
	//根据微网对象位置设置控制计划无功出力
	virtual bool SetPlanQ(int pos, double planQ) = 0;
	
	//根据微网对象位置得到离网前有功功率
	virtual double GetOldP(int pos) = 0;
	//根据微网对象位置设置离网前有功功率[无锁]
	virtual bool SetOldP(int pos, double oldP) = 0;

	//根据微网对象位置得到有功遥调ID
	virtual int GetPCtrlID(int pos) = 0;
	//根据微网对象位置得到无功遥调ID
	virtual int GetQCtrlID(int pos) = 0;
	//根据微网对象位置更新计划功率		
	virtual void UpdatePlanPQ(int pos) = 0;

	//判断指定位置的微网对象是否人工闭锁了有功调节操作
	virtual bool ManuLockAdjustP(int pos) = 0;
	//判断指定位置的微网对象是否人工闭锁了无功调节操作
	virtual bool ManuLockAdjustQ(int pos) = 0;

	//根据遥调ID得到遥调真实的期望值		
	virtual double GetPlanValueByCtrlId(int ctrlId, bool& bOk) = 0;
	//根据微网对象位置得到数据通道连通状态
	virtual int GetSrcConnectState(int pos) = 0;
	//根据微网对象位置设置数据通道连通状态
	virtual bool SeSrcConnectState(int pos, int srcState) = 0;

	//根据微网对象位置得到有功增闭锁标志
	virtual int GetPIncLock(int pos) = 0;
	//根据微网对象位置设置有功增闭锁标志
	virtual bool SetPIncLock(int pos, int pIncLock) = 0;

	//根据微网对象位置得到有功减闭锁标志
	virtual int GetPDecLock(int pos) = 0;
	//根据微网对象位置设置有功减闭锁标志
	virtual bool SetPDecLock(int pos, int pDecLock) = 0;

	//根据微网对象位置得到无功增闭锁标志
	virtual int GetQIncLock(int pos) = 0;
	//根据微网对象位置设置无功增闭锁标志
	virtual bool SetQIncLock(int pos, int qIncLock) = 0;

	//根据微网对象位置得到无功减闭锁标志
	virtual int GetQDecLock(int pos) = 0;
	//根据微网对象位置设置无功减闭锁标志
	virtual bool SetQDecLock(int pos, int qDecLock) = 0;

protected:
	//使用开关状态遥信ID索引
	virtual int UseIndex_PosID() = 0; 
	//使用有功遥调ID索引
	virtual int UseIndex_PCtrlID() = 0;
	//使用无功遥调ID索引
	virtual int UseIndex_QCtrlID() = 0;
	//使用额定容量索引
	virtual int UseIndex_Capacity() = 0;
	//使用当前有功功率索引
	virtual int UseIndex_CurP() = 0;
	//使用当前无功功率索引
	virtual int UseIndex_CurQ() = 0;
	//使用模拟量实体对象
	virtual IAnalogDao* UseAnalogDao() = 0;
	//使用状态量实体对象
	virtual IStatusDao* UseStatusDao() = 0;
	//使用控制量实体对象
	virtual IControlDao* UseControlDao() = 0;
	//使用计划有功功率索引
	virtual int UseIndex_PlanP() = 0;
	//使用计划无功功率索引
	virtual int UseIndex_PlanQ() = 0;
	//判断是否为仿真测试状态
	virtual bool IsTest() = 0;
	//使用遥脉量实体对象
	virtual IAccumuDao* UseAccumuDao() = 0;

public:
	//根据微网对象位置得到上级设备位置。eqpType：0--未知；1--母线；2--线路；3--变压器。
	virtual bool GetParentEquipPos(int pos, int& eqpPos, int& objPos, int& eqpType, bool chechVF=true) = 0;
	//根据微网对象位置判断无功遥调值是否以容性（即发出）无功为正数
	virtual bool IsCapcitiveQCtrlValue(int pos) = 0;

};

//综合运行状态类型：0：停运，1:并网待机，2：全功率运行，3：限功率运行，4：检修，5：故障[待修或待复归]，6：离网[待并网]
enum RUNSTATETYPE
{
	RST_STOP, RST_BACKUP, RST_MAXPOWER, RST_LIMITPOWER, RST_REPAIR, RST_FAULT, RST_ISLAND, 
};

#endif
