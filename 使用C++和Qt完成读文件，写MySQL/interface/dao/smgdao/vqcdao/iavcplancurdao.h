//iavcplancurdao.h

#ifndef _IAVCPLANCURDAO_PENGSHIKANG_20150824_H_
#define _IAVCPLANCURDAO_PENGSHIKANG_20150824_H_

#include "../../ibasicdao.h"                     // for IBasicDao

#define AVCPLANCURDAO_CLASSID    "cavcplancurdao"
#define AVCPLANCURDAO_INTFID     "iavcplancurdao"

class IAvcPlanCurDao : virtual public IBasicDao
{
public:
	//����AVC��վ��ֵλ�õõ���ֵ�ƻ�ID
	virtual int GetAvcSetPlanId(int pos) = 0;

	//����AVC��վ��ֵλ�õõ�ʱ�䷶Χ
	virtual void GetTimeRange(int pos, int& startTime, int& endTime) = 0;

	//����AVC��ֵ�ƻ�ID�͵�ǰʱ��õ�AVC��վ��ֵλ��
	virtual int GetPositionByTime(int planId, int time) = 0;
	//����AVC��ֵ�ƻ�ID�͵�ǰʱ���ȡ�ƻ���ѹֵ
	virtual bool GetPlanVoltage(int planId, int time, double& aimVoltage) = 0;
	//����AVC��ֵ�ƻ�ID�͵�ǰʱ���ȡ�ƻ��޹�-��������ֵ
	virtual bool GetPlanQorCosfa(int planId, int time, double& aimQorCosfa) = 0;

	//����AVC��վ��ֵλ�ö�ȡ��ǰ�ƻ���ѹֵ
	virtual double GetPlanVoltage(int pos) = 0;
	//����AVC��վ��ֵλ�����õ�ǰ�ƻ���ѹֵ
	virtual bool SetPlanVoltage(int pos, double aimVoltage) = 0;

	//����AVC��վ��ֵλ�ö�ȡ��ǰ�ƻ��޹�-��������ֵ
	virtual double GetPlanQorCosfa(int pos) = 0;
	//����AVC��վ��ֵλ�����õ�ǰ�ƻ��޹�-��������ֵ
	virtual bool SetPlanQorCosfa(int pos, double aimQorCosfa) = 0;

	//����AVC��վ��ֵλ�ö�ȡ��ǰʵ�ʵ�ѹֵ
	virtual double GetCurVoltage(int pos) = 0;
	//����AVC��վ��ֵλ�����õ�ǰʵ�ʵ�ѹֵ
	virtual bool SetCurVoltage(int pos, double aimVoltage) = 0;

	//����AVC��վ��ֵλ�ö�ȡ��ǰʵ���޹�-��������ֵ
	virtual double GeCurQorCosfa(int pos) = 0;
	//����AVC��վ��ֵλ�����õ�ǰʵ���޹�-��������ֵ
	virtual bool SetCurQorCosfa(int pos, double aimQorCosfa) = 0;

	//�����ݱ�Ķ�̬��Ϣд�����
	virtual void WriteDynamicInfo1() = 0;

	//����AVC��վ��ֵλ�ö�ȡ�ƻ��޹�-������������ֵ
	virtual double GetCtrlRFLow(int pos) = 0;
	//����AVC��վ��ֵλ�ø��ļƻ��޹�-������������ֵ
	virtual bool SetCtrlRFLow(int pos, double minctrlrf) = 0;

	//����AVC��վ��ֵλ�ö�ȡͳ�ƴ洢���ڣ����ڼƻ���ʷ�洢��
	virtual int GetSaveTimerID(int pos) = 0;
	//����AVC��վ��ֵλ�ö�ȡͳ�ƴ洢��־
	virtual int GetSaveFlag(int pos) = 0;

};

#endif
