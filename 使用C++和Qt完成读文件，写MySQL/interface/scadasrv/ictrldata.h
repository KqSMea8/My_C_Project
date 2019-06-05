// ictrldata.h: interface for the IControlData class.
//
//////////////////////////////////////////////////////////////////////

#ifndef _ICONTROLDATA_H__PENGSHIKANG_20130303__INCLUDED_
#define _ICONTROLDATA_H__PENGSHIKANG_20130303__INCLUDED_

class IControlData  
{
public:
	virtual bool IsNull() = 0;
	virtual float GetValueBefore() = 0;
	virtual float GetResultValue() = 0;
	virtual bool IsValidate(int ctrlPos, char* logText) = 0;
	virtual bool NeedVerify(char* logText) = 0;
	virtual const char* GetControlType() = 0;
	virtual bool IsAimStatus(float aimVal, char* logText) = 0;
	virtual bool IsDataLock(char* logText) = 0;
	virtual bool IsManualSet(char* logText) = 0;
	virtual bool IsCheckWF() = 0;
	virtual unsigned char GetCType() = 0;
	virtual void SetControlResult(float aimVal) = 0;
	virtual bool GetDummyCalID(int& exprId, char* logText) = 0;
	virtual bool DealResultValue(float curVal, char* logText) = 0;
	virtual void GetStatusDesc(float ctrlVal, char* logText) = 0;
};

#endif
