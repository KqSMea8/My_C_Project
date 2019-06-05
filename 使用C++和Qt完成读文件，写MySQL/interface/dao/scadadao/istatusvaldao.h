//istatusvaldao.h

#ifndef _ISTATUSVALUETYPEDAO_PENGSHIKANG_20081204_H_
#define _ISTATUSVALUETYPEDAO_PENGSHIKANG_20081204_H_

#include "../ibasicdao.h"                        // for IBasicDao
#include "../../../interface/scadasrv/scadadatadef.h"// for STATUSTYPE

#define STATUSVALDAO_CLASSID    "cstatusvaldao"
#define STATUSVALDAO_INTFID     "istatusvaldao"

class IStatusValDao : virtual public IBasicDao
{
public:
	//是否为基于遥信类型码识别遥信类型的模式
	virtual bool IsStatusCodeMode() = 0;

	//根据测控量类型和状态量值得到状态量值类型记录位置
	virtual int GetPositionByStateValue(int nMeasType, int nValue) = 0;
	//根据测控量类型和状态类型得到状态量值类型记录位置
	virtual int GetPositionByStateType(int nMeasType, STATUSTYPE nStatType) = 0;
	
	//根据测控量类型和状态量值得到状态类型
	virtual STATUSTYPE GetStateTypeByStateValue(int nMeasType, int nValue) = 0;
	//根据测控量类型和状态量值得到状态操作描述
	virtual void GetStateDescByStateValue(int nMeasType, int nValue, char* sValDesc) = 0;
	//根据测控量类型和状态类型得到状态量值
	virtual int GetValueByStateType(int nMeasType, STATUSTYPE nStatType, bool& bOk) = 0;
	
	//根据状态量值类型位置读取状态值
	virtual int GetStateValue(int pos) = 0;
	//根据状态量值类型位置读取状态类型
	virtual STATUSTYPE GetStateType(int pos) = 0;
	//根据状态量值类型位置读取状态操作描述
	virtual const char* GetStateDesc(int pos) = 0;
	
	//根据状态量值类型位置读取事故变位报警ID
	virtual int GetFaultAlarmID(int pos) = 0;
	//根据状态量值类型位置读取操作变位报警ID
	virtual int GetCtrlAlarmID(int pos) = 0;

	//根据测控量类型读取状态类型
	virtual STATUSTYPE GetStateTypeByMeasType(int nMeasType) = 0;
	//根据测控量类型判断是否为开关投切状态量类型
	virtual bool IsSwitchMeasType(int nMeasType) = 0;
	//根据测控量类型判断是否为事故信号状态量类型
	virtual bool IsFaultMeasType(int nMeasType) = 0;
	//根据测控量类型判断是否为预告信号状态量类型
	virtual bool IsAlarmMeasType(int nMeasType) = 0;
};

#endif
