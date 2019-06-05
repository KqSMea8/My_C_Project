//iperioddao.h

#ifndef _IPERIODDAO_PENGSHIKANG_20130328_H_
#define _IPERIODDAO_PENGSHIKANG_20130328_H_

#include "../ibasicdao.h"                        // for IBasicDao

#define PERIODDAO_CLASSID     "cperioddao"
#define PERIODDAO_INTFID      "iperioddao"

class IPeriodDao : virtual public IBasicDao
{
public:
	/* ����ʱ��õ�ʱ�����Ӧ������ */
	static int GetSecondsByTime(double dTime)
	{
		return (int)((dTime - int(dTime)) * 86400.0 + 0.5);
	}

	/* ��������ֵ�������õ�ʱ�� */
	static double GetTimeBySeconds(double dayTime, int secCount)
	{
		return (double)(int(dayTime) + secCount / 86400.0);
	}

	//����ʱ��λ�õõ���ֹʱ��
	virtual void GetTimes(int pos, double& beginTime, double& endTime) = 0;

	//����ʱ��λ�õõ���ʼʱ��
	virtual double GetBeginTime(int pos) = 0;
	//����ʱ��λ�õõ�����ʱ��
	virtual double GetEndTime(int pos) = 0;

	//����ʱ��õ�������ʱ������ID
	virtual int GetPeriodTypeID(double dTime, int* beginSeconds=0, int* endSeconds=0) = 0;

};

#endif
