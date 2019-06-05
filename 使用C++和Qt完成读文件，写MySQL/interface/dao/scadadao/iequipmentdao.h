//iequipmentdao.h

#ifndef _IEQUIPMENTDAO_PENGSHIKANG_20081203_H_
#define _IEQUIPMENTDAO_PENGSHIKANG_20081203_H_

#include "../ibasicdao.h"                        // for IBasicDao

#define EQUIPDAO_CLASSID    "cequipdao"
#define EQUIPDAO_INTFID     "iequipdao"

class ITagTypeDao;
class IVoltageDao;
class IAnalogDao;
class IStatusDao;

class IEquipDao : virtual public IBasicDao
{
public:
	//设置挂牌类型实体对象
	virtual void SetTagTypeDao(ITagTypeDao* pTagType) = 0;
	//设置电压等级实体对象
	virtual void SetVoltageDao(IVoltageDao* pVoltage) = 0;
	//设置模拟量实体对象
	virtual void SetAnalogDao(IAnalogDao* pAnalog) = 0;

	//根据设备位置得到描述
	virtual const char* GetDescription(int pos) = 0;
	//根据设备位置得到间隔ID
	virtual int GetBayId(int pos) = 0;
	//根据设备位置得到厂站ID
	virtual int GetStationId(int pos) = 0;
	//根据设备位置判断该设备是否有故障
	virtual bool HasFault(int pos) = 0;

	//根据设备ID得到设备分类编码
	virtual int GetEquipClassByID(int id) = 0;
	//根据设备位置得到设备分类编码
	virtual int GetEquipClass(int pos) = 0;
	//根据设备ID得到设备类型编码
	virtual int GetTypeCodeByID(int id) = 0;
	//根据设备位置得到设备类型编码
	virtual int GetTypeCode(int pos) = 0;
	//根据设备ID得到电压等级ID
	virtual int GetVoltageGradeByID(int id) = 0;
	//根据设备位置得到电压等级ID
	virtual int GetVoltageGrade(int pos) = 0;
	//根据设备ID得到额定电压
	virtual double GetBaseVoltageByID(int id) = 0;
	//根据设备位置得到额定电压
	virtual double GetBaseVoltage(int pos) = 0;
	//根据设备位置判断电压状态是否正常
	virtual bool IsNormalVoltage(int pos) = 0;
	//根据设备位置判断设备是否带电
	virtual bool IsActive(int pos) = 0;

	//根据设备位置判断设备是否处于挂牌状态
	virtual bool IsTag(int pos) = 0;
	//根据设备ID判断设备是否处于挂牌状态
	virtual bool IsTagByID(int id) = 0;
	//根据设备位置判断设备是否挂闭锁牌状态
	virtual bool IsLockTag(int pos, char* tagName=0) = 0;
	//根据设备位置设置设备是否处于挂牌状态
	virtual bool SetTagFlag(int pos, int isTag) = 0;

	//根据设备位置得到挂牌类型ID
	virtual int GetTagTypeId(int pos) = 0;
	//根据设备位置设置挂牌类型ID
	virtual bool SetTagTypeId(int pos, int tagTypId) = 0;

	//根据设备位置获取设备的挂牌信息
	virtual bool GetTagInfo(int pos, bool& isTag, int& tagTypId, char* tagOper, double& tagTime) = 0;
	//根据设备位置设置设备的挂牌信息
	virtual bool SetTagInfo(int pos, bool isTag, int tagTypId, const char* tagOper, double tagTime) = 0;

	//根据设备位置得到闭锁标志
	virtual int GetLockFlag(int pos) = 0;
	//根据设备位置设置闭锁标志
	virtual bool SetLockFlag(int pos, int lockFlag) = 0;

	//根据设备ID得到是否是双位置设备和双位置设备变化延迟时间
	virtual bool IsDoubleStatusByID(int id, int& nDelayTime) = 0;
	//根据设备位置判断设备是否是双位置设备
	virtual bool IsDoubleStatus(int pos) = 0;
	//根据设备位置得到双位置设备变化延迟时间
	virtual int GetDpsDelayTime(int pos) = 0;

	//清空设备的开关状态量ID值
	virtual void ClearStatusPos() = 0;
	
	//根据设备位置设置设备的开关状态量ID
	virtual bool SetStatusPos(int pos, int nStatusPos) = 0;
	//根据设备位置得到设备的开关状态量ID
	virtual bool GetStatusPos(int pos, int& nStatusPos1, int& nStatusPos2) = 0;

	//根据设备ID设置设备的开关状态量ID
	virtual bool SetStatusPosByEquipID(int id, int nStatusPos) = 0;
	//根据设备位置得到设备的开关状态量ID
	virtual bool GetStatusPosByEquipID(int id, int& nStatusPos1, int& nStatusPos2) = 0;

	//根据设备位置得到接入系统方式
	virtual int GetJoinType(int pos) = 0;
	//根据设备位置得到上级设备ID
	virtual int GetSupperEquipId(int pos) = 0;
	//根据设备位置得到上级设备位置
	virtual int GetSupperEquipPos(int pos) = 0;
	//根据设备位置得到设备控制闭锁表达式
	virtual const char* GetLockControlExpr(int pos) = 0;
	//根据设备位置得到功率值是否参与分类统计
	virtual int GetStatFlag(int pos) = 0;
	//根据设备位置判断设备是否闭锁控制操作
	virtual int DisabledControl(int pos) = 0;
	//根据设备位置设置设备是否闭锁控制操作
	virtual bool SetLockControl(int pos, int isLockCtrl) = 0;

	//根据设备位置判断设备是否处于活岛内
	virtual bool InActiveIsland(int pos) = 0;
	//根据设备位置得到所属拓扑岛ID
	virtual int GetIslandId(int pos) = 0;
	//根据设备位置得到所属拓扑活岛ID
	virtual int GetActiveIslandId(int pos) = 0;

	//根据设备位置得到设备事故标志
	virtual int GetFaultFlag(int pos) = 0;
	//根据设备位置得到设备事故类型
	virtual int GetFaultType(int pos) = 0;
	//根据设备位置得到设备事故测点ID
	virtual int GetFaultPointId(int pos) = 0;
	//根据设备位置得到设备事故发生时间
	virtual double GetFaultTime(int pos) = 0;
	//根据设备位置设置设备事故信息
	virtual bool SetFaultInfo(int pos, int faultType, int faultPntId, double faultTime) = 0;
	//根据设备位置确认设备事故信息
	virtual bool AckFaultInfo(int pos) = 0;
	//根据设备位置消闪设备事故信息
	virtual bool UnflickerFaultInfo(int pos, int faultType) = 0;

	//是否配置了电压遥测ID
	virtual bool HasVoltageAnalog() = 0;
	//根据设备位置得到电压遥测ID
	virtual int GetVoltageAnalogId(int pos) = 0;
	//根据设备位置得到频率遥测ID
	virtual int GetFrequencyAnalogId(int pos) = 0;

	//读取设备表的拓扑动态信息
	virtual void ReadTopoDynamicInfo() = 0;
	//根据设备位置判断设备是否能控制[未判故障标志]
	virtual bool CanControl(int pos) = 0;

	//根据设备位置得到电压合格状态：-3--失压；-2--越紧急下限；-1--越下限；0--合格；1--越上限；2--越紧急上限。
	virtual int GetEquipUState(int pos) = 0;
	//根据设备ID得到并网点电压值。
	virtual double GetVoltageByEquipID(int id) = 0;

	//根据设备位置得到设备通信状态ID
	virtual int GetNetStateId(int id) = 0;
	//根据设备位置得到设备当前通信状态
	virtual int GetNetState(int id) = 0;
	//设置遥信量实体对象
	virtual void SetStatusDao(IStatusDao* pStatus) = 0;
};

#endif
