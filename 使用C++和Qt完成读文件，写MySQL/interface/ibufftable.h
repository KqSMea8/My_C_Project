// igaiatable.h
#ifndef __IGATATABLE_2008_11_29_PENGSHIKANG_H__
#define __IGATATABLE_2008_11_29_PENGSHIKANG_H__

#include "icsdbaccess.h"   // for icsvariant��IDATable

#define IID_IGaiaTable		"igaiatable"
#define CLSID_GaiaTable		"gaiatable"

///////////////////////////////////////////////////////////////////////////////
//���ʴ���������ݱ�
///////////////////////////////////////////////////////////////////////////////

typedef enum 
{
		INVBUFF = -1, //��Ч����
		NULBUFF, //0--δ����
		OLDBUFF, //1--�ɻ���
		NEWBUFF, //2--�»���
		BADBUFF, //3--�����棨ָ�����С�����ݿ����ֶοռ��С��һ�£�
}BufferState;//���ݱ��ֶλ����״̬

//����������ݱ���
class IGaiaTable : virtual public IICSUnknown
{
public:
	//�õ����ݱ�ļ�¼����--
	virtual int GetRecordCount() = 0;
	
	//�õ����ݱ���ֶ�����--
	virtual int GetFieldCount() = 0;
	
	//�õ��������ݱ�������ֶ�λ�ú��ֶ����ơ��������ݱ���ֶ�����--
	virtual int GetAllFieldName(const char* fields[]) = 0;
	
	//�����ֶ����õ��ֶ�������--
	virtual int GetFieldIndex(const char* sField) = 0;
	
	//�õ�ָ���ֶλ����״̬��
	virtual BufferState GetFieldState(int index) = 0;
	
	//�����ݱ�װ�������ֶ����ݡ�����ֵ��ʾ�Ƿ�����װ�������ݡ�
	virtual bool LoadField(int index) = 0;
	
	//�����ֶ�����д�����ݱ�����ֵ��ʾ�Ƿ��������������ݱ�
	virtual bool SaveField(int index) = 0;
	
	//�ͷ������ֶλ���ռ�õĿռ䡣
	virtual void FreeField(int index) = 0;
	
	//�����������ݱ����ݡ�[���ݱ����߸��º������]
	//����ֵ��0������ʧ�ܣ�1�����³ɹ�����¼��δ�䣻2�����³ɹ�����¼���ѱ仯��
	virtual int LoadTable(int fldCount=0, const int* indexs=0, bool onlyRead=false, const char* strFilter="DELETEFLAG==0") = 0;
	
	//������������д�����ݱ�[���ݱ����߸���ǰ������]
	virtual void SaveTable(int fldCount=0, const int* indexs=0) = 0;
	
	
	//���ݼ�¼ID�õ���¼λ�á�ʧ��ʱ����-1��
	virtual int GetPosById(int id, bool bRequery=false) = 0;
	
	//���ݼ�¼λ�õõ���¼ID��ʧ��ʱ����-1��
	virtual int GetIdByPos(int pos) = 0;
	
	//�õ�ָ����¼λ��ָ���ֶ��������ֶ�ֵ��ʧ��ʱ����0��
	virtual const void* GetFieldValueByPos(int pos, int index) = 0;
	
	//�õ�ָ����¼IDָ���ֶ��������ֶ�ֵ��ʧ��ʱ����0��
	virtual const void* GetFieldValueById(int id, int index, bool bRequery=false) = 0;

	//�õ�ȫ��ָ���ֶ��������ֶ�ֵ��ֱ�Ӵ����ݿ��ȡ��
	virtual bool GetAllFieldValues(int index, void* pValues) = 0;
	
	//��ʼ��ָ���ֶ����������ֶ�ֵȫΪ0����ַ�����
	//ע�⣺ֻ�е���SaveField()��SaveTable()���д�����ݿ⡣
	virtual bool InitFieldValuesToZero(int index) = 0;
	
	//����ָ����¼λ��ָ���ֶ����������ֶ�ֵ��
	//ע�⣺ֻ�е���SaveField()��SaveTable()���д�����ݿ⡣
	virtual bool SetFieldValueByPos(int pos, int index, const void* pValue) = 0;
	
	//����ָ����¼IDָ���ֶ����������ֶ�ֵ��
	//ע�⣺ֻ�е���SaveField()��SaveTable()���д�����ݿ⡣
	virtual bool SetFieldValueById(int id, int index, const void* pValue) = 0;
	
	//���ⲿ����ָ����¼λ��ָ���ֶ��������ֶ�ֵ��ʧ��ʱ����0��
	//ע�⣺ֻ�е���SaveField()��SaveTable()���д�����ݿ⡣
	virtual void* SetFieldValueByPos(int pos, int index) = 0;
	
	//���ⲿ����ָ����¼IDָ���ֶ��������ֶ�ֵ��ʧ��ʱ����0��
	//ע�⣺ֻ�е���SaveField()��SaveTable()���д�����ݿ⡣
	virtual void* SetFieldValueById(int id, int index) = 0;
	
	//����ȫ��ָ���ֶ����������ֶ�ֵ��ֱ��д�����ݿ⡣
	virtual bool SetAllFieldValues(int index, void* pValues) = 0;
	
	//��ָ����¼λ��ָ���ֶ��������ֶ�ֵд�����ݱ�
	virtual bool SaveField(int pos, int index, const void* pValue=0) = 0;
	
	//��ȡ���ݷ��ʱ�
	//ע�⣺������ʹ�÷��ص�ָ��ʱ������÷���ָ���Release()��������
	virtual IDATable* TakeDATable() = 0;

	//�õ�ȫ��IDֵ�����ؼ�¼����
	virtual int GetAllIdentifiers(int* pIdValues) = 0;
	
public:
	static char *GetIntfName()
	{
		return IID_IGaiaTable;
	};
};

#endif
