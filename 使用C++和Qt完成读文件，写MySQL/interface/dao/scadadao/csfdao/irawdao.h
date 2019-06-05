//irawdao.h

#ifndef _IRAWDAO_PENGSHIKANG_20100915_H_
#define _IRAWDAO_PENGSHIKANG_20100915_H_

#include "icsfdao.h"                             // for ICsfDao

#define RawDao_CLASSID    "crawdao"
#define RawDao_INTFID     "irawdao"

class IRawDao : virtual public ICsfDao
{
public:
	//�������ڴ������
	virtual void LockUpdate() = 0;
	//�������ڴ������
	virtual void UnlockUpdate() = 0;

	//����ʵʱ�ɼ���λ�õõ�������Դ����
	virtual int GetOrigin(int pos) = 0;
	//����ʵʱ�ɼ���λ������������Դ����
	virtual bool SetOrigin(int pos, int nValue) = 0;
	//��������������Դ����
	virtual void SaveOrigin() = 0;

	//����ʵʱ�ɼ���λ�õõ�����Ʒ������
	virtual int GetQuality(int pos) = 0;
	//����ʵʱ�ɼ���ID�õ�����Ʒ������
	virtual int GetQualityById(int id) = 0;
	//����ʵʱ�ɼ���λ����������Ʒ������
	virtual bool SetQuality(int pos, int nValue) = 0;

	//����ʵʱ�ɼ���λ�õõ��ɼ�ֵ
	virtual double GetRawValue(int pos) = 0;

	//���ݲ���ֵ��ü���ֵ
	virtual double CalculateValue(int pos, double rawValue) = 0;
	
	//����ʵʱ�ɼ���λ�ý����˹�����(����ֵ)�������ؾ�ֵ
	virtual double SetManualValue(int pos, double curTime, double calValue, bool isIncValue=false) = 0;

	//����ʵʱ�ɼ���λ��ȡ���˹�����
	virtual bool CancelManualSet(int pos) = 0;
	//����ʵʱ�ɼ���IDȡ���˹�����
	virtual bool CancelManualSetById(int id) = 0;
	
	//����ң��ң������������Ӱ����
	virtual bool TestControlResult(int measId, float aimValue) = 0;

	//��������Դͨ��״̬�޸���ң����Ʒ��
	virtual bool UpdateQualityBySrcConnect(int nSrcId, bool isConnected) = 0;
	
protected:
	//����ʵʱ�ɼ���λ�����òɼ�ֵ��Ʒ������[����]
	virtual void SetRawValue0(int pos, int nSrcId, int nPntId, int curQualt, double curTime, const void* pRawValue) = 0;
	//����ʵʱ�ɼ���λ�ý����˹�����(����ֵ)�������ؾ�ֵ[����]
	virtual double SetManualValue0(int pos, double curTime, double calValue, bool isIncValue=false) = 0;

	//��ȡ����Ʒ�������ֶ�����
	virtual int GetIndex_Quality() = 0;
	//ʹ������Ʒ�������ֶ�����
	virtual int UseIndex_Quality() = 0;
	//��ȡ���ݲɼ�ֵ�ֶ�����
	virtual int GetIndex_RawValue() = 0;
	//ʹ�����ݲɼ�ֵ�ֶ�����
	virtual int UseIndex_RawValue() = 0;
	//��ȡ���ݼ���ֵ�ֶ�����
	virtual int GetIndex_CalcValue() = 0;
	//ʹ�����ݼ���ֵ�ֶ�����
	virtual int UseIndex_CalcValue() = 0;
};

#endif
