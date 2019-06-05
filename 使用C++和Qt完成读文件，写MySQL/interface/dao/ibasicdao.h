//ibasicdao.h

#ifndef _IBASICDAO_PENGSHIKANG_20100802_H_
#define _IBASICDAO_PENGSHIKANG_20100802_H_

#include "../icsunknown.h"

#define SCADADAO_MODULE    "scadadao"
#define SMGDAO_MODULE      "smgdao"
#define STRGDAO_MODULE     "strgdao"

class IBasicDao : virtual public IICSUnknown
{
public:
	//����ȫ���ֶ���Ϣ�ļ��������
	virtual void Lock() = 0;//����ȫ���ֶ���Ϣǰ����
	virtual void Unlock() = 0;//����ȫ���ֶ���Ϣ�����

	//�õ����ݱ�����
	virtual const char* GetTableName() = 0;
	//�õ����ݱ��¼�������
	virtual int GetObjectCount() = 0;
	
	//��ʼ�����ݱ��ֶ�������
	virtual void GetFieldIndexs() = 0;
	//��ȡ���ݱ�ľ�̬��Ϣ
	//virtual void ReadStaticInfo() = 0;
	virtual void ReadStaticInfo(int fldNum=0, const char nameList[][64]=0, const char* strFilter="DELETEFLAG==0", bool onlyRead=false) = 0;

	//��ȡ���ݱ�Ķ�̬��Ϣ
	virtual void ReadDynamicInfo() = 0;
	//�����ݱ�Ķ�̬��Ϣд�����
	virtual void WriteDynamicInfo() = 0;

	//�������ݱ��¼ID�õ���¼λ��
	virtual int GetPositionByID(int nId, bool bRequery=false) = 0;
	//�������ݱ��¼λ�õõ���¼ID
	virtual int GetIdentifierByPos(int nPos) = 0;

	//�������ݱ��¼λ�õõ��ü�¼���������
	virtual const char* GetName(int nPos) = 0;
	//�������ݱ��¼λ���жϸü�¼�Ƿ��ѱ�ɾ��
	virtual bool IsDeleted(int nPos) = 0;

	//���ݲ�ѯ������ü�¼ID����
	//ע�⣺ָ��idSet���ⲿ��Ҫ�����ڴ棬���ڽӿں����ڲ���new[]���������ڴ棬
	//      �����ͷ����ⲿ���û�����delete[]������ɡ�
	virtual int FindObjectsByFilter(int& count, int*& idSet, const char* strFilter, bool onlyRead=true, int fldCount=0, const char fldList[][64]=0) = 0;

protected:
	//�õ���������
	virtual int GetIndex_Name() = 0;
	//ʹ����������
	virtual int UseIndex_Name() = 0;
	//�õ�ɾ����־����
	virtual int GetIndex_DeleteFlag() = 0;
	//ʹ��ɾ����־����
	virtual int UseIndex_DeleteFlag() = 0;
	//��ȡ�������ֶ���Ϣ
	virtual void LoadBaseField() = 0;
	//���ֶ����Ƽ�ת��Ϊ�Ϸ����ֶ�������
	virtual bool GetFieldIndexsByNames(int inCount, const char nameList[][64], int& outCount, int*& indexList) = 0;

public:
	//�����ݿ�����������
	virtual bool BeginTransaction() = 0;
	//�������ݿ���������Զ��ύ��ع�����
	//�Ը����ݿ���������ݷ��ʲ�������ȷ���ʱ�ύ������ع���
	virtual bool EndTransaction(char* strInfo=0) = 0;
};

#endif
