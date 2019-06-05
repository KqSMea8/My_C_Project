//ibaseinfo.h

#ifndef _IBASEINFO_PENGSHIKANG_20130315_H_
#define _IBASEINFO_PENGSHIKANG_20130315_H_

class IGaiaTable;

class IBaseInfo
{
public:
	virtual void LockWrite() = 0;//��̬�ֶ���Ϣ����
	virtual void UnlockWrite() = 0;//��̬�ֶ���Ϣ����
	virtual void LockRead() = 0;//��̬�ֶ���Ϣ����
	virtual void UnlockRead() = 0;//��̬�ֶ���Ϣ����
	virtual void LockUpdate() = 0;//�������ڴ������
	virtual void UnlockUpdate() = 0;//�������ڴ������
	virtual void Lock() = 0;
	virtual void Unlock() = 0;
	
	//�õ����ݱ�����
	virtual const char* GetTableName() = 0;
	virtual IGaiaTable*& GetTableEntity() = 0;
	
	//�������ݱ��¼λ�õõ������͵�ֻ���ֶ�ֵ
	virtual bool GetBoolReadableFieldValue(int pos, int index, bool bDefault=false) = 0;
	//�������ݱ��¼λ�õõ������͵Ŀ�д�ֶ�ֵ
	virtual bool GetBoolWritableFieldValue(int pos, int index, bool bDefault=false) = 0;
	//�������ݱ��¼λ�õõ������͵�ֻ���ֶ�ֵ
	virtual int GetIntReadableFieldValue(int pos, int index, int nDefault=0) = 0;
	//�������ݱ��¼λ�õõ������͵Ŀ�д�ֶ�ֵ
	virtual int GetIntWritableFieldValue(int pos, int index, int nDefault=0) = 0;
	//�������ݱ��¼λ�õõ�ʵ���͵�ֻ���ֶ�ֵ
	virtual double GetDoubleReadableFieldValue(int pos, int index, double dDefault=0.0) = 0;
	//�������ݱ��¼λ�õõ�ʵ���͵Ŀ�д�ֶ�ֵ
	virtual double GetDoubleWritableFieldValue(int pos, int index, double dDefault=0.0) = 0;
};

#endif
