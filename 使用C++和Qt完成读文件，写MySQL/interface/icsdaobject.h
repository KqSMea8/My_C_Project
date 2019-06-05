#ifndef _ICSDAOBJECT__INTERFACE_H_
#define _ICSDAOBJECT__INTERFACE_H_

#include "icsdbaccess.h" // for IDATable
#include "qiptr.h"

#define MODULE_ICSDAOBJECT		"icsdao"
#define CLSID_ICSDAObject       "ICSDAObject"
#define IID_IICSDAObject        "IICSDAObject"

/*
���ݷ��ʶ�����: �ṩͳһ���ݷ��ʽӿ�
*/
class IICSDAObject : virtual public IICSUnknown
{
public:
	/////////////////////////////////////////////////////////////////
	//1����ʼ������
	/////////////////////////////////////////////////////////////////
	//�������ݱ��¼������
	virtual bool SetDataTable(IDATable* pTable) = 0;
	//�����ݱ��¼�����й���
	virtual bool Filter(const char* strFilter) = 0;
	//ȡ��¼����ָ��˳��ŵļ�¼����
	virtual bool IndexTo(int pos, bool bRefresh=true) = 0;
	//����IDֵ��λ��¼���еļ�¼����
	virtual bool LocateByID(int nId) = 0;
	//���ö��������ݱ��¼���е������ֶ���
	virtual bool SetPrimeKey(const char* strPK) = 0;
	
	
	/////////////////////////////////////////////////////////////////
	//2�����ݿ����
	/////////////////////////////////////////////////////////////////

	//���ݿ��������ˢ�µ������ֶ�(������RT_TABLE��RT_SELECT��RT_UNQUERY����)
	//��ִ�гɹ�������Ӱ��ļ�¼������ִ��ʧ�ܣ�����-1����ʾ��������
	virtual int Load() = 0;

	//�������ֶ�ֵ�������ݿ���е�һ�������ļ�¼��(������RT_TABLE����)
	virtual int Insert() = 0;
	//�������ֶ�ֵ�������ݿ���ж�Ӧ��һ���Ѵ��ڵļ�¼��(������RT_TABLE����)
	virtual int Update() = 0;

	//����������ݵ����ݿ����(������RT_TABLE���Ͷ���)
	//�ú����ڲ����ݶ���״̬������ִ��Insert()��Update()����
	virtual int Save() = 0;

	//ɾ�����ݿ���е�ǰ�������ڵļ�¼(ִ�гɹ��󣬵�ǰ����λ�ñ�Ϊ-1)
	virtual bool Remove() = 0;


	/////////////////////////////////////////////////////////////////
	//3���������
	/////////////////////////////////////////////////////////////////
	//��ѯ��¼���ĵ�һ������(��������Ӧ�ļ�¼���ļ�¼����Ϊ0����������NULL)
	virtual IICSDAObject* FirstObj() = 0;
	//��ѯ��¼������һ������(�����ǰ����Ϊ���һ��������������NULL)
	virtual IICSDAObject* NextObj() = 0;
	//��ѯ��¼��ָ��λ�õĶ���
	virtual IICSDAObject* IndexObj(int pos) = 0;
	//����һ��ͬ�����ݵ��¶���(����״̬ͬ������)
	virtual IICSDAObject* CopyObj() = 0;
	//ͨ�����������ֵ�Ӽ�¼���ж�ȡ����
	virtual IICSDAObject* FromPrimeKey(const icsvariant& pkValue) = 0;
	

	/////////////////////////////////////////////////////////////////
	//4���������Բ���
	/////////////////////////////////////////////////////////////////
	//�õ����ݱ��¼������
	virtual bool GetDataTable(IDATable* pTable) = 0;
	//�õ�����Ĺ�������
	virtual bool GetFilter(char* strFilter) = 0;
	//�õ��������������
	virtual bool GetPrimeKeyName(char* pkName) = 0;

	//�õ������Ӧ�ļ�¼���ļ�¼����
	virtual int GetObjCount() = 0;
	//�õ���ǰ�����ڼ�¼���е�λ��
	virtual int GetObjIndex() = 0;
	
	/////////////////////////////////////////////////////////////////
	//5�������ֶβ���
	/////////////////////////////////////////////////////////////////
	//�õ���ǰ������ֶ���
	virtual int GetFieldCount() = 0;
	//�õ���ǰ������½��ֶ���
	virtual int GetNewFieldCount() = 0;
	
	//�����ֶ����Ƶõ��ֶ�λ��
	virtual int GetFieldIndex(const char* fldName) = 0;
	//�����ֶ�λ�õõ��ֶ�����(�ֶ�λ�ô�0��ʼ����)
	virtual bool GetFieldName(int index, char* fldName) = 0;

	//�����ֶ����Ƶõ��ֶ���������
	virtual FIELDTYPE GetFieldType(const char* fldName) = 0;
	//�����ֶ�λ�õõ��ֶ���������
	virtual FIELDTYPE GetFieldType(int index) = 0;

	//�õ�ָ���ֶ����Ƶ�����ֵ(����bKeepType��ʾȡ����ֵ�Ƿ�ת��Ϊ������������)
	virtual bool GetFieldValue(const char* fldName, icsvariant& fldValue, bool bKeepType=false) = 0;
	//�õ�ָ���ֶ�λ�õ�����ֵ(����bKeepType��ʾȡ����ֵ�Ƿ�ת��Ϊ������������)
	virtual bool GetFieldValue(int index, icsvariant& fldValue, bool bKeepType=false) = 0;
	//�õ����������ֶε�����ֵ(����bKeepType��ʾȡ����ֵ�Ƿ�ת��Ϊ������������)
	virtual bool GetPrimeKeyValue(icsvariant& pkValue, bool bKeepType=false) = 0;
	
	//����ָ���ֶ����Ƶ��ֶ�ֵ(����bCreate��ʾ: ��ָ�����ֶβ�����ʱ�Ƿ񴴽����ֶ�)
	virtual bool SetFieldValue(const char* fldName, const icsvariant& fldValue, bool bCreate=false) = 0;
	//����ָ���ֶ�λ�õ��ֶ�ֵ(��index >= ���ֶθ���ʱ�������ֶ�ֵʧ��(����false))
	virtual bool SetFieldValue(int index, const icsvariant& fldValue) = 0;
	//�½�һ�����������ֶε�����ֵ(����ʵʱ���ݿ⣬�ò����������ݱ��в���һ����¼)
	virtual bool NewPrimeKeyValue(const icsvariant& pkValue) = 0;
	
	//�����ֶ������ж��Ƿ�Ϊ�Ѵ��ڵ��ֶ�
	virtual bool IsExistField(const char* fldName) = 0;
	//�����ֶ�λ���ж��Ƿ�Ϊ�Ѵ��ڵ��ֶ�(�����ڵ��ֶ�һ�������ֶΡ���ֵ�ֶΡ�ɾ��ʧ�ܵ��ֶ�)
	virtual bool IsExistField(int index) = 0;

	//�����ֶ������ж��Ƿ�Ϊ���ֶ�
	virtual bool IsNewField(const char* fldName) = 0;
	//�����ֶ�λ���ж��Ƿ�Ϊ���ֶ�
	virtual bool IsNewField(int index) = 0;
	
	//ɾ�����ֶ�(ֻ���Ѵ��ڵ����ֶβ���ɾ���ɹ�)
	virtual bool RemoveNewField(const char* fldName) = 0;
	//��ն�̬�ֶ��б�����������
	virtual void ClearNewFields() = 0;
	//����̬�ֶ�ת�Ƶ����ݿ��ֶΡ���CreateObjectBy���ʹ�á�
	virtual void NewFieldsToDbFields() = 0;

private:
	friend class CICSDAObjectIn;//dll�ڲ��õ���Ԫ��

	//���·�������CICSDAObjectIn�ڲ�ʹ�õĽӿڷ���:
	//���ö�̬�ֶ��б�ɾ��������ʱ�Ƿ��Զ��ͷ��������ڴ档[�ڲ�ʹ��]
	virtual void SetAutoDeleteNewFields(bool bDelNewFld) = 0;
	//�õ���̬�ֶ��б�[�ڲ�ʹ��]
	virtual void* GetNewFields() = 0;

public:
    static char *GetIntfName()
    {
        return IID_IICSDAObject;
    };
};

typedef CQIPtr<IICSDAObject> ICSDAObject;

#endif 
