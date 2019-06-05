//istorcurvedao.h

#ifndef _ISTORAGEPOWERCURVEDAO_PENGSHIKANG_20101103_H_
#define _ISTORAGEPOWERCURVEDAO_PENGSHIKANG_20101103_H_

#include "../ibasicdao.h"                        // for IBasicDao

#define STORCURVEDAO_CLASSID    "cstorcurvedao"
#define STORCURVEDAO_INTFID     "istorcurvedao"

class IStorCurveDao : virtual public IBasicDao
{
public:
	//���ݴ��ܷŵ繦������λ�õõ����߼ƻ�ID
	virtual int GetCurvePlanID(int pos) = 0;
	
	//���ݴ��ܷŵ繦������λ�ö�ȡ�Ƿ���Ч��־
	virtual int IsEnable(int pos) = 0;

	//���ݴ��ܷŵ繦������λ�õõ�ʱ�䷶Χ
	virtual void GetTimeRange(int pos, int& startTime, int& endTime) = 0;

	//���ݴ��ܷŵ繦������λ�ö�ȡ���ܷŵ繦��ֵ
	virtual double GetCurvePlanPower(int pos) = 0;

	//�������߼ƻ�ID�͵�ǰʱ���ȡ���ܷŵ繦��ֵ�����ش��ܷŵ繦������λ�á�
	virtual int GetCurvePlanPowerByMinutes(int planId, int time, double& power) = 0;

	//���ݴ��ܷŵ繦������λ�ö�ȡ���ܳ�ŵ�Ŀ������
	/*
	0���̶�ֵ��ŵ硣
	1�����ն��෢�磺�����������õ磬���ܳ�磬�����������ʱ�����Ʒ��磻����õ���ڷ��磬���ܲ��ŵ硣
	2���Է����ã������������õ磬���ܳ�磬�����������ʱ�����Ʒ��磻����õ���ڷ��磬���ܷŵ磬�ŵ���������ʱ�������õ硣
	*/
	virtual int GetCurvePlanAimType(int pos) = 0;
	
};

#endif
