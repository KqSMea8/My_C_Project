//icsfdao.h

#ifndef _ICSFDAO_PENGSHIKANG_20100915_H_
#define _ICSFDAO_PENGSHIKANG_20100915_H_

#include "../../ibasicdao.h"                        // for IBasicDao
#include "../../../icsvalue.h"                      // for icsarray

#define CsfDao_CLASSID    "ccsfdao"
#define CsfDao_INTFID     "icsfdao"

struct DataMeasType // һ�����������Ϣ
{
	int dataId;    //����ID
	int dataPos;   //����λ�� 
	int measTypeId;//���ݵĲ������ID
};

struct DataMeasTypeSet //һ���豸��Ӧ�Ĳ�����ݼ���
{
	int measCount;            //������
	DataMeasType** pMeasTypes;//���������Ϣ_����
};

class ICsfDao : virtual public IBasicDao
{
public:
	//����ǰ���ϴ���λ�õõ���վID
	virtual int GetStationId(int pos) = 0;
	//����ǰ���ϴ���λ�õõ����ID
	virtual int GetBayId(int pos) = 0;
	//����ǰ���ϴ���λ�õõ��豸ID
	virtual int GetEquipId(int pos) = 0;
	//����ǰ���ϴ���λ�õõ����������ID
	virtual int GetMeasType(int pos) = 0;

	//����ǰ���ϴ���λ�õõ�����
	virtual const char* GetDescription(int pos) = 0;
	//����ǰ���ϴ���λ�õõ�·��
	virtual const char* GetPathName(int pos) = 0;
	//����ǰ���ϴ���λ�õõ�·������
	virtual const char* GetPathReference(int pos) = 0;
	//����ǰ���ϴ���λ�õõ��Ƿ�ת����־
	virtual int GetDataTransFlag(int pos) = 0;

	//����ǰ���ϴ�����·�������õ���¼λ��
	virtual int GetPositionByPathRef(const char* pathRef) = 0;

	//���ݶ�ֵ��λ�õõ��ɼ�����Դ��
	virtual int GetRawSourceId(int pos) = 0;
	//���ݶ�ֵ��λ�õõ��ɼ����ݵ��
	virtual int GetRawPointId(int pos) = 0;
	
	//����ǰ���ϴ���λ�õõ��ɼ����ݵĲɼ�Դ�Ͳɼ����
	virtual void GetRawSrcPointId(int pos, int& nSrcId, int& nPntId) = 0;
	//����ǰ���ϴ���λ�����òɼ����ݵĲɼ�Դ�Ͳɼ����
	virtual void SetRawSrcPointId(int pos, int nSrcId, int nPntId) = 0;
	
	//����ǰ���ϴ���λ�õõ���ǰʱ��
	virtual double GetCurTime(int pos) = 0;
	//����ǰ���ϴ���λ�����õ�ǰʱ��
	virtual bool SetCurTime(int pos, double dTime) = 0;
	
	//����ǰ���ϴ���λ�õõ���������״̬
	virtual int GetOperateState(int pos) = 0;
	//����ǰ���ϴ���λ�����ò�������״̬
	virtual bool SetOperateState(int pos, int nOprState) = 0;
	
	//����ǰ���ϴ���λ�õõ�������־
	virtual int GetLockFlag(int pos) = 0;
	//����ǰ���ϴ���λ�����ñ�����־
	virtual bool SetLockFlag(int pos, int lockFlag) = 0;

	//����ָ���豸ID��ø��豸ĳһ���Ͳɼ���������ID�б�
	virtual DataMeasTypeSet* GetMeasArrayByEquipId(int eqpId) = 0;

protected:
	//��ȡǰ���ϴ��ķǲɼ������ȫ����̬��Ϣ
	virtual int ReadCsfStaticInfo(const char* strFilter, bool onlyRead, int fldNum, const char nameList[][64]) = 0;
	//��ȡǰ�òɼ������ȫ����̬��Ϣ
	virtual int ReadRawStaticInfo(const char* strFilter, bool onlyRead, int fldNum, const char nameList[][64]) = 0;

	//ʹ�õ�ǰʱ���ֶ�����
	virtual int UseIndex_CurrTime() = 0;
	//ʹ�ò�������״̬�ֶ�����
	virtual int UseIndex_OperState() = 0;
	//ʹ�ñ�����־�ֶ�����
	virtual int UseIndex_LockFlag() = 0;
	//ʹ���Ƿ�ת����־�ֶ�����
	virtual int UseIndex_TransFlag() = 0;

	//ʹ�õ�ǰ������ԴRTU������
	virtual int UseIndex_CommSrc() = 0;
	//ʹ�õ�ǰ�ɼ���������
	virtual int UseIndex_CommPnt() = 0;

};

#endif
