//ibusdao.h

#ifndef _IBUSDAO_PENGSHIKANG_20100324_H_
#define _IBUSDAO_PENGSHIKANG_20100324_H_

#include "../../ibasicdao.h"                     // for IBasicDao
#include "../../../smgsrv/vqcdatadef.h"          // for BusDeviceInfo、VQCAreaInfo

#define BUSDAO_CLASSID    "cbusdao"
#define BUSDAO_INTFID     "ibusdao"

class IEquipDao;
class IAnalogDao;
class IVoltageDao;
class ISMicgridDao;
class ICommSrcDao;

class IBusDao : virtual public IBasicDao
{
public:
	//设置采集数据源对象
	virtual void SetCommSrcDao(ICommSrcDao* pCommSrc) = 0;
	//设置设备实体对象
	virtual void SetEquipDao(IEquipDao* pEquip) = 0;
	//设置模拟量实体对象
	virtual void SetAnalogDao(IAnalogDao* pAnalog) = 0;
	//设置电压等级实体对象
	virtual void SetVoltageDao(IVoltageDao* pVoltage) = 0;
	//设置微电网实体对象
	virtual void SetSMicgridDao(ISMicgridDao* pSMicgrid) = 0;

	//所有母线所带设备动态信息初始化[用于VQC]
	virtual void InitAllBusDeviceDynamicInfo() = 0;
	//初始化所有VQC调节系统的无功进线集合信息
	virtual void InitAllRepowSourcesOfAdjustArea(int pccNum, int lineNum) = 0;
	//初始化所有母线的VQC调节系统号信息
	virtual void InitAllAdjustAreaNos() = 0;
	//初始化所有母线所在VQC调节系统的九区图区号信息
	virtual void InitAllVqcZoneNos() = 0;

	//根据母线的位置设置各个量测量实时值
	virtual void SetMeasureValues(int pos, double& dValueU, double& dValueF) = 0;
	
	//根据母线位置得到母线所带设备信息
	virtual BusDeviceInfo* GetBusDeviceInfo(int pos) = 0;
	//根据母线ID得到母线所带设备信息
	virtual BusDeviceInfo* GetBusDeviceInfoById(int id) = 0;
	
	//根据母线位置得到路径
	virtual const char* GetPathReference(int pos) = 0;
	//根据母线位置得到子微网ID
	virtual int GetSubMicGridID(int pos) = 0;
	//根据母线位置得到其所处的活岛ID
	virtual int GetActiveIslandId(int pos) = 0;
	//根据母线对象ID判断其是否处于指定子微电网的主活岛中
	virtual bool InMicgridActiveIslandByID(int id, int mgPos) = 0;

	//根据母线位置得到U遥测ID
	virtual int GetUID(int pos) = 0;
	//根据母线位置得到F遥测ID
	virtual int GetFID(int pos) = 0;
	//根据母线位置得到当前电压
	virtual double GetCurU(int pos) = 0;
	//根据母线位置得到当前频率
	virtual double GetCurF(int pos) = 0;
	//根据母线位置得到当前电压和频率
	virtual bool GetCurUFById(int id, double& curU, double& curF) = 0;
	
	//根据母线位置得到母线所属调节区号
	virtual int GetAdjustAreaNo(int pos) = 0;
	//根据母线位置设置母线所属调节区号
	virtual bool SetAdjustAreaNo(int pos, int adjustNo) = 0;
	//根据母线ID设置母线所属调节区号
	virtual bool SetAdjustAreaNoByID(int id, int adjustNo) = 0;
	
	//根据母线位置得到VQC当前区域号
	virtual int GetVoltRepowerAreaNo(int pos) = 0;
	//根据母线位置设置VQC当前区域号
	virtual bool SetVoltRepowerAreaNo(int pos, int zoneNo) = 0;
	
	//根据母线位置得到电压无功控制母线类型。0--参考母线；1--电压无功控制母线；2--电压控制母线；3--无功控制母线。
	virtual int GetVoltageControlType(int pos) = 0;
	
	//根据VQC调节区域ID得到VQC调节区域对象
	virtual VQCAreaInfo* GetAdjustAreaByID(int areaId) = 0;
	//根据无功控制母线位置得到VQC调节区域对象
	virtual VQCAreaInfo* GetAdjustAreaByRPCBusPos(int busPos) = 0;
	
	//根据母线位置得到额定电压
	virtual double GetBaseVoltage(int pos) = 0;
	virtual double GetBaseVoltageByID(int id) = 0;
	virtual bool IsNormalVoltage(int pos) = 0;
	virtual bool IsActive(int pos) = 0;

	//以下函数模拟控制策略时使用
	//根据母线对象ID设置当前电压和频率为正常值
	virtual bool TestBusVolt_FreqToNormalByID(int id) = 0;
	//根据母线对象位置设置当前电压为指定值
	virtual bool TestSetBusVoltage(int pos, float curU) = 0;
	//根据母线位置设置当前频率为指定值
	virtual bool TestSetBusFrequency(int pos, float curF) = 0;
	//根据子微网ID设置子微网内所有母线电压为正常值
	virtual bool TestMicgridVoltageToNormal(int dadMgId) = 0;
	//根据子微网ID设置子微网内所有母线频率为正常值
	virtual bool TestMicgridFrequencyToNormal(int dadMgId) = 0;
	//根据子微网ID设置子微网内所有母线频率为指定值
	virtual bool TestSetMicgridFrequency(int dadMgId, float newF) = 0;

	//根据母线对象位置得到数据通道连通状态
	virtual int GetSrcConnectState(int pos) = 0;
	//根据母线对象位置设置数据通道连通状态
	virtual bool SeSrcConnectState(int pos, int srcState) = 0;
	//释放所有的母线所带设备信息的空间
	virtual void FreeAllBusDeviceInfoMemory() = 0;
	//根据母线位置得到当前电压品质
	virtual int GetCurUQuality(int pos) = 0;
	//根据母线位置得到当前频率品质
	virtual int GetCurFQuality(int pos) = 0;
	//根据母线位置检测母线实时数据品质是否异常
	virtual bool InnormalRtDataByQuality(int pos) = 0;

	//获取整个控制母线位置列表
	virtual const intarray& GetCtrlBusList() = 0;

};

#endif
