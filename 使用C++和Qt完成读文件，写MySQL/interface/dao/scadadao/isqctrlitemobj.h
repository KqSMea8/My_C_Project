//isqctrlitemobj.h
#ifndef _ISQCTRLITEMOBJ_PENGSHIKANG_20140507_H_
#define _ISQCTRLITEMOBJ_PENGSHIKANG_20140507_H_

class ISqctrlItemObj
{
public:
	virtual const int GetPosition() = 0;   //得到记录位置
	virtual const int GetCtrlStep() = 0;   //得到控制步骤号
	virtual const int GetCtrlId() = 0;     //得到控制ID
	virtual const int GetCtrlType() = 0;   //得到控制类型
	virtual const char* GetCtrlValue() = 0;//得到控制值表达式
	virtual const int GetConfirmFlag() = 0;//得到是否确认
	virtual const int GetSkipFlag() = 0;   //得到是否跳过这一步
	virtual const int GetWaitTime() = 0;   //得到等待时间
	
	virtual const bool operator < (ISqctrlItemObj& obj) = 0;
	virtual const bool operator > (ISqctrlItemObj& obj) = 0;
	virtual const bool operator == (ISqctrlItemObj& obj) = 0;
	virtual const bool operator <= (ISqctrlItemObj& obj) = 0;
	virtual const bool operator >= (ISqctrlItemObj& obj) = 0;
	virtual const bool operator != (ISqctrlItemObj& obj) = 0;
};

#endif
