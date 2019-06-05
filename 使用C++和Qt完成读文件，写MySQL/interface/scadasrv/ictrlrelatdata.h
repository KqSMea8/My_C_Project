// ictrlrelatdata.h: interface for the ICtrlRelatData class.
//
//////////////////////////////////////////////////////////////////////

#ifndef _ICOCONTROLRELATEDDATA_PENGSHIKANG_H_20171221
#define _ICOCONTROLRELATEDDATA_PENGSHIKANG_H_20171221

class ICtrlRelatData  
{
public:
	virtual bool HasMeasData() = 0;
	virtual float GetValueBefore() = 0;
	virtual float GetResultValue() = 0;
	virtual bool IsValidate(char* logText) = 0;
	virtual bool CanVerify(int ctrlId, char* logText) = 0;
	virtual bool NeedVerify(char* logText) = 0;
	virtual const char* GetControlTypeName() = 0;
	virtual bool IsAimStatus(float aimVal, char* logText) = 0;
	virtual bool IsDataLock(char* logText) = 0;
	virtual bool IsManualSet(char* logText) = 0;
	virtual bool IsCheckWF() = 0;
	virtual unsigned char GetCType() = 0;
	virtual void SetControlResult(float aimVal, int ctrlID) = 0;
	virtual bool GetDummyCalID(int& exprId, char* logText) = 0;
	virtual bool DealResultValue(float curVal, float aimVal, char* logText, const char* actorID) = 0;
	virtual void GetStatusDesc(float ctrlVal, char* logText) = 0;
	virtual void GetAimValueAndCtrlValue(int ctrlId, const char* valueDes, double& aimValue, float& ctrlValue) = 0;
};

#endif
