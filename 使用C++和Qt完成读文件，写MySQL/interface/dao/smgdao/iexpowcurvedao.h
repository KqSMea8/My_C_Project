//iexpowcurvedao.h

#ifndef _IEXCHANGEPOWERCURVEDAO_PENGSHIKANG_20101025_H_
#define _IEXCHANGEPOWERCURVEDAO_PENGSHIKANG_20101025_H_

#include "../ibasicdao.h"                        // for IBasicDao

#define EXPOWCURVEDAO_CLASSID    "cexpowcurvedao"
#define EXPOWCURVEDAO_INTFID     "iexpowcurvedao"

class IExPowCurveDao : virtual public IBasicDao
{
public:
	//���ݽ�����������λ�õõ����߼ƻ�ID
	virtual int GetCurvePlanID(int pos) = 0;
	//���ݽ�����������λ�ö�ȡ�Ƿ���Ч��־
	virtual int IsEnable(int pos) = 0;
	//���ݽ�����������λ�õõ�ʱ�䷶Χ
	virtual void GetTimeRange(int pos, int& startTime, int& endTime) = 0;
	//���ݽ�����������λ�ö�ȡ��������ֵ
	virtual double GetCurvePlanPower(int pos) = 0;
	//������΢��ID�͵�ǰʱ���ȡ��������ֵ
	virtual int GetCurvePlanPower(int planId, int time, double& expow) = 0;	
	//���ݽ�����������λ�����ý������ʼƻ�ֵ
	virtual bool SetCurvePlanPower(int pos, double expow, int flag=0) = 0;

	//������΢��ID�͵�ǰʱ��õ�������������λ��
	virtual int GetPositionByTime(int planId, int time) = 0;
	//���ݽ�����������λ�ö�ȡͳ�ƴ洢���ڣ����ڼƻ���ʷ�洢��
	virtual int GetSaveTimerID(int pos) = 0;
	//���ݽ�����������λ�ö�ȡͳ�ƴ洢��־
	virtual int GetSaveFlag(int pos) = 0;

	//���ݽ�����������λ�ö�ȡ��������ʵ��ֵ
	virtual double GetCurveActualPower(int pos) = 0;
	//���ݽ�����������λ�õõ����һ��ͳ��ʱ��
	virtual double GetStatisticsTime(int pos) = 0;
	//���ݽ�����������λ�����ý�������ʵ��ֵ
	virtual bool SetCurveActualPower(int pos, double curPower, double curTime) = 0;

	//�����ݱ�Ķ�̬��Ϣд�����[save]
	virtual void WriteDynamicInfo1() = 0;
};

#endif
