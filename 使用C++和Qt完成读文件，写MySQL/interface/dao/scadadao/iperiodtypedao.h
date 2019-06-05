//iperiodtypedao.h

#ifndef _IPERIODTYPEDAO_PENGSHIKANG_20130328_H_
#define _IPERIODTYPEDAO_PENGSHIKANG_20130328_H_

#include "../ibasicdao.h"                        // for IBasicDao

#define PERIODTYPEDAO_CLASSID     "cperiodtypedao"
#define PERIODTYPEDAO_INTFID      "iperiodtypedao"

class IPeriodTypeDao : virtual public IBasicDao
{
public:
	//����ʱ������ID�õ�������ۺ��������
	virtual bool GetPriceById(int id, double& genPrice, double& usePrice) = 0;

	//����ʱ������λ�õõ��������(�������)
	virtual double GetGenPrice(int pos) = 0;
	//����ʱ������λ�õõ��������(ʹ�õ��)
	virtual double GetUsePrice(int pos) = 0;

	//�õ����������۵�ʱ��(���ʱ��)����ID
	virtual int GetPeakPrdTypID() = 0;
	//�õ����������۵�ʱ��(���ʱ��)����ID
	virtual int GetHollowPrdTypID() = 0;
};

#endif
