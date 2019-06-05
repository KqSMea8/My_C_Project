//iacurvelmtdao.h

#ifndef _IACURVELMTDAO_PENGSHIKANG_20130310_H_
#define _IACURVELMTDAO_PENGSHIKANG_20130310_H_

#include "../ibasicdao.h"                        // for IBasicDao

#define ACURVELMTDAO_CLASSID    "cacurvelmtdao"
#define ACURVELMTDAO_INTFID     "iacurvelmtdao"

class IACurveLmtDao : virtual public IBasicDao
{
public:
	//����ģ��������Խ������λ�ö�ȡģ����Խ������ID
	virtual int GetLimitType(int pos) = 0;
	
	//����ģ��������Խ������λ�õõ�ʱ�䷶Χ
	virtual void GetTimeRange(int pos, double& startTime, double& endTime) = 0;
	
	//����ģ��������Խ������λ�õõ�������ֵ
	virtual void GetLimitValues(int pos, double& upperVal, double& lowerVal) = 0;

	//����ģ��������Խ������λ�ö�ȡ���ޱ���ֵ
	virtual double GetUpperValue(int pos) = 0;

	//����ģ��������Խ������λ�ö�ȡ���ޱ���ֵ
	virtual double GetLowerValue(int pos) = 0;
};

#endif
