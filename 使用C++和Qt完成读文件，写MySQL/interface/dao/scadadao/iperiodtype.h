//iperiodtype.h
#ifndef _IPERIODTYPE_PENGSHIKANG_20080711_H_
#define _IPERIODTYPE_PENGSHIKANG_20080711_H_

#include "../ibasicdao.h"                        // for IBasicDao

#define PERIODTYPE_CLASSID    "cperiodtype"
#define PERIODTYPE_INTFID     "iperiodtype"

class IPeriodType : virtual public IBasicDao
{
public:
	//����ʱ�����Ͷ���
	virtual void CreatePeriodTypes() = 0;

	//�õ�ʱ�����͸���
	virtual int GetPeriodTypeCount() = 0;
	
	//�õ�ȫ����ʱ������ID
	virtual bool GetAllPeriodTypeID(int pPeriodIDs[]) = 0;
	
    //����ʱ��õ�������ʱ������ID
    virtual int GetPeriodTypeID(double dTime, int& beginTime, int& endTime) = 0;

	//����ʱ������ID�õ�������ۺ��������
	virtual bool GetPriceByPrdTypID(int typeId, float& genPrice, float& usePrice) = 0;
	//�õ����������۵�ʱ�Σ����ʱ�Σ�����ID
    virtual int GetPeakPrdTypID() = 0;
	//�õ����������۵�ʱ�Σ����ʱ�Σ�����ID
    virtual int GetHollowPrdTypID() = 0;
};

#endif
