//isqctrlitemobj.h
#ifndef _ISQCTRLITEMOBJ_PENGSHIKANG_20140507_H_
#define _ISQCTRLITEMOBJ_PENGSHIKANG_20140507_H_

class ISqctrlItemObj
{
public:
	virtual const int GetPosition() = 0;   //�õ���¼λ��
	virtual const int GetCtrlStep() = 0;   //�õ����Ʋ����
	virtual const int GetCtrlId() = 0;     //�õ�����ID
	virtual const int GetCtrlType() = 0;   //�õ���������
	virtual const char* GetCtrlValue() = 0;//�õ�����ֵ���ʽ
	virtual const int GetConfirmFlag() = 0;//�õ��Ƿ�ȷ��
	virtual const int GetSkipFlag() = 0;   //�õ��Ƿ�������һ��
	virtual const int GetWaitTime() = 0;   //�õ��ȴ�ʱ��
	
	virtual const bool operator < (ISqctrlItemObj& obj) = 0;
	virtual const bool operator > (ISqctrlItemObj& obj) = 0;
	virtual const bool operator == (ISqctrlItemObj& obj) = 0;
	virtual const bool operator <= (ISqctrlItemObj& obj) = 0;
	virtual const bool operator >= (ISqctrlItemObj& obj) = 0;
	virtual const bool operator != (ISqctrlItemObj& obj) = 0;
};

#endif
