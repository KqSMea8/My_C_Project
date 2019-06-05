//ictrlvaltypdao.h

#ifndef _ICTRLVALUETYPEDAO_PENGSHIKANG_20130310_H_
#define _ICTRLVALUETYPEDAO_PENGSHIKANG_20130310_H_

#include "../ibasicdao.h"                        // for IBasicDao
#include "../../scadasrv/scadadatadef.h"         // for OPERATETYPE

#define CTRLVALTYPDAO_CLASSID    "cctrlvaltypdao"
#define CTRLVALTYPDAO_INTFID     "ictrlvaltypdao"


class ICtrlValTypDao : virtual public IBasicDao
{
public:
	//是否为基于控制码识别遥控操作类型的模式
	virtual bool IsControlCodeMode() = 0;

	//根据遥控量类型和遥控命令值得到遥控值类型记录位置
	virtual int GetPositionByOperateValue(int nMeasType, int nValue) = 0;
	
	//根据遥控量类型和操作类型得到遥控量值类型记录位置
	virtual int GetPositionByOperateType(int nMeasType, OPERATETYPE nOprtType) = 0;
	
	//根据遥控量类型和操作类型得到遥控命令值
	virtual int GetValueByOperateType(int nMeasType, OPERATETYPE nOprtType) = 0;
	
	//根据遥控值类型量位置得到遥控值
	virtual int GetCtrlValue(int pos) = 0;
	//根据遥控值类型量位置得到遥控类型
	virtual OPERATETYPE GetCtrlType(int pos) = 0;
	//根据遥控值类型量位置得到告警方式ID
	virtual int GetAlarmId(int pos) = 0;
	//根据遥控值类型量位置得到返回值是否为目标值
	virtual int GetJudgeAimval(int pos) = 0;
	//根据遥控值类型量位置得到遥控返回目标值
	virtual int GetAimval(int pos) = 0;	
	//根据遥控值类型量位置得到测控量类型
	virtual int GetMeasTypeId(int pos) = 0;
};

#endif
