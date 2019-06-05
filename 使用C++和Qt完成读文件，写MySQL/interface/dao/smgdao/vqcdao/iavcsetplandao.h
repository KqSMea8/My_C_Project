//iavcsetplandao.h

#ifndef _IAVCSETPLANDAO_PENGSHIKANG_20150824_H_
#define _IAVCSETPLANDAO_PENGSHIKANG_20150824_H_

#include "../../ibasicdao.h"                     // for IBasicDao

#define AVCSETPLANDAO_CLASSID    "cavcsetplandao"
#define AVCSETPLANDAO_INTFID     "iavcsetplandao"

typedef enum
{
	LOCAL_QCURVE, DISPATCH_QSETTING, DISPATCH_QCURVE5, DISPATCH_QCURVE15, QUNDEFINE,
}QCurvePlanType;

typedef struct 
{
	int iCount;
	int busIds[4];
	int planPos[4];
}MultBusPlan;


class IAvcSetPlanDao : virtual public IBasicDao
{
public:

	//�����޹���ֵ�ƻ����͵õ�AVC��ֵ�ƻ�λ��
	virtual int GetDispatchCurvePlanPos(QCurvePlanType& dispType) = 0;
	//���ݵ�ǰʱ���ж�ָ��λ�õ�AVC��ֵ�ƻ��Ƿ���Ч
	virtual bool IsValidDispatchCurvePlan(int pos, double curTime) = 0;

	//����AVC��ֵ�ƻ�λ�ö�ȡ�Ƿ���Ч��־
	virtual int IsEnable(int pos) = 0;

	//����AVC��ֵ�ƻ�λ�ö�ȡ��ѹ�޹��������͡�
	//����ֵ��0�����ѹ��1�����޹����ʣ�kVar/Mvar����2���㹦��������3���޹�����ֵ��4��������������ֵ��5���޹�����ֵ��
	virtual int GetVQCosAdjustType(int pos) = 0;
	//����AVC��ֵ�ƻ�λ�ö�ȡ�ƻ���Դ���͡�
	//����ֵ��0���������üƻ����ߣ�1: Զ�̵����·�����ֵ��2��Զ�������·�5���Ӽƻ����ߣ�3��Զ�������·�15���Ӽƻ����ߡ�
	virtual int GetCurveValueOrigin(int pos) = 0;
	//����AVC��ֵ�ƻ�λ�ö�ȡ�����޹�����ֵ�Ƿ�������������Ϊ��ֵ��
	//����ֵ��true: ��վ����޹�Ϊ����false���޹�������վΪ���� 
	virtual bool DispatchQIsOutput(int pos) = 0;
	//����AVC��ֵ�ƻ�λ�ö�ȡ�����޹�����ֵ�Ƿ���MVarΪ��λ��
	//����ֵ��true: ��λΪMVar��false����λΪkVar�� 
	virtual bool DispatchQInMVar(int pos) = 0;
	//����AVC��ֵ�ƻ�λ�õõ�������ѹ��ֵ
	virtual void GetLockVoltageLimitValues(int pos, double& upperVal, double& lowerVal) = 0;
	//����AVC��ֵ�ƻ��ƻ�λ�õõ���ѹֵ���ͣ�0--����ֵ��1--����ֵ��2--��������ֵ��3--��������ֵ��
	virtual int GetVoltageAimValueType(int pos) = 0;


	//����AVC��ֵ�ƻ�λ�õõ�AVC���ڲ�������
	virtual int GetStrategyType(int pos) = 0;
	//����AVC��ֵ�ƻ�λ���ж��޹�����Ŀ���Ƿ�Ϊ�޹�
	virtual bool TargetIsRp(int pos) = 0;
	//����AVC��ֵ�ƻ�λ���ж��Ƿ������޹�����
	virtual bool CanRpReverse(int pos) = 0;
	//����AVC��ֵ�ƻ�λ�õõ����ʷ����෴ʱ�޹���������
	virtual double GetMaxRpReverse(int pos) = 0;
	//����AVC��ֵ�ƻ�λ�õõ���ѹ����ֵ����
	virtual int GetVoltageValueType(int pos) = 0;
	//����AVC��ֵ�ƻ�λ�ö�ȡ����ָ����Чʱ����
	virtual double GetValidTimeSpan(int pos) = 0;
	//����AVC��ֵ�ƻ�λ�ö�ȡԶ�̵����·����ڶ�ʱ��ID
	virtual int GetCommTimerID(int pos) = 0;

	//����AVC��ֵ�ƻ�λ�ö�ȡԶ�̵����������ʱ��
	virtual double GetReceiveTime(int pos) = 0;
	//����AVC��ֵ�ƻ�λ�ø���Զ�̵����������ʱ��
	virtual bool SetReceiveTime(int pos, double recvTime) = 0;

	//����AVC��ֵ�ƻ�λ�ö�ȡ��ǰ�ƻ���ѹֵ������ֵ��
	virtual double GetPlanVol(int pos) = 0;
	//����AVC��ֵ�ƻ�λ�ø��ĵ�ǰ�ƻ���ѹֵ������ֵ��
	virtual bool SetPlanVol(int pos, double planvol) = 0;

	//����AVC��ֵ�ƻ�λ�ö�ȡ��ǰ�ƻ��޹�-��������ֵ
	virtual double GetPlanRF(int pos) = 0;
	//����AVC��ֵ�ƻ�λ�ø��ĵ�ǰ�ƻ��޹�-��������ֵ
	virtual bool SetPlanRF(int pos, double planrf) = 0;

	//����AVC��ֵ�ƻ�λ�ö�ȡ��ǰʵ�ʵ�ѹֵ������ֵ��
	virtual double GetCurVol(int pos) = 0;
	//����AVC��ֵ�ƻ�λ�ø��ĵ�ǰʵ�ʵ�ѹֵ������ֵ��
	virtual bool SetCurVol(int pos, double curVol) = 0;

	//����AVC��ֵ�ƻ�λ�ö�ȡ��ǰʵ���޹�-��������ֵ
	virtual double GetCurRF(int pos) = 0;
	//����AVC��ֵ�ƻ�λ�ø��ĵ�ǰʵ���޹�-��������ֵ
	virtual bool SetCurRF(int pos, double curRf) = 0;

	//����AVC��ֵ�ƻ�λ�ñ���Զ�̵���AVC��ֵ����ʱ��[save]
	virtual bool SaveDispatchReceiveTime(int pos, double recvTime) = 0;
	//����AVC��ֵ�ƻ�λ�ñ���Զ�̵���AVC��ѹ��ֵ��Ϣ[save]
	virtual bool SaveDispatchVoltageInfo(int pos, double recvTime, double aimVoltage) = 0;
	//����AVC��ֵ�ƻ�λ�ñ��浱ǰ��ѹֵ��Ϣ[save]
	virtual bool SaveCurrentAimVoltage(int pos, double curVoltage) = 0;
	//����AVC��ֵ�ƻ�λ�ñ���Զ�̵���AVC�޹�-����������ֵ��Ϣ[save]
	virtual bool SaveDispatchQorCosfaInfo(int pos, double recvTime, double aimQorCosfa) = 0;
	//����AVC��ֵ�ƻ�λ�ñ��浱ǰ�޹�-��������ֵ��ֵ��Ϣ[save]
	virtual bool SaveCurrentQorCosfaValue(int pos, double curQorCosfa) = 0;

	//�õ���Ч�ı���AVC���߼ƻ�λ��
	virtual int GetLocalCurvePlanPos() = 0;

	//����AVC��ֵ�ƻ�λ�ö�ȡ��ǰ�ƻ��޹�-������������ֵ
	virtual double GetPlanRFLow(int pos) = 0;
	//����AVC��ֵ�ƻ�λ�ø��ĵ�ǰ�ƻ��޹�-������������ֵ
	virtual bool SetPlanRFLow(int pos, double minplanrf) = 0;
	//����AVC��ֵ�ƻ�λ�ñ���Զ�̵���AVC�޹�-������������ֵ��Ϣ[save]
	virtual bool SaveDispatchQorCosfaLower(int pos, double recvTime, double aimQorCosfa) = 0;
	//����AVC��ֵ�ƻ�λ�ñ��浱ǰ�޹�-������������ֵ��Ϣ[save]
	virtual bool SaveCurrentQorCosfaRange(int pos, double curQUpper, double curQLower) = 0;

	//���ݵ�ѹ�޹��������ͺ͵������͵õ�AVC��ֵ�ƻ�λ��
	virtual int GetDispatchCurvePlanPosByType(int adjustType, QCurvePlanType dispType) = 0;
	//���ݵ����������ȼ��͵����·�ʱ��õ�AVC��ֵ�ƻ�λ��
	virtual int GetDispatchCurvePlanPosByTime(QCurvePlanType& dispType) = 0;

	//����AVC��ֵ�ƻ�λ�ö�ȡͳ�ƴ洢���ڣ����ڼƻ���ʷ�洢��
	virtual int GetSaveTimerID(int pos) = 0;
	//����AVC��ֵ�ƻ�λ�ö�ȡͳ�ƴ洢��־
	virtual int GetSaveFlag(int pos) = 0;

	//����AVC��ֵ�ƻ�λ�ö�ȡ����ĸ��ID
	virtual int GetCtrlBusID(int pos) = 0;
	//����AVC��ֵ�ƻ�λ�ö�ȡ����Ŀ��ֵ�쳣��־
	virtual int GetAimAbnormalFlag(int pos) = 0;
	//����AVC��ֵ�ƻ�λ�����õ���Ŀ��ֵ�쳣��־
	virtual bool SetAimAbnormalFlag(int pos, int nAbnormalFlag) = 0;
	//���ݵ����������ȼ��Ϳ���ĸ��ID�õ�AVC��ֵ�ƻ�λ��
	virtual int GetDispatchCurvePlanPosByBusID(int busId, QCurvePlanType& dispType) = 0;
	//���ݵ������͵õ�AVC��ֵ�ƻ�ĸ����
	virtual MultBusPlan GetDispatchCurvePlanGroupByType(int adjustType, QCurvePlanType dispType) = 0;
	//����AVC��ֵ�ƻ�λ�ñ����Ƿ���Ч��־
	virtual bool SaveEnable(int pos, int iEnable) = 0;

	//����ĸ��ID�õ���Ч�ı���AVC���߼ƻ�λ��
	virtual int GetLocalCurvePlanPos(int busId) = 0;

	//����AVC��ֵ�ƻ�λ�ö�ȡ��ǰʵ�ʵ�ѹ�ο�ֵ
	virtual double GetVoltageReferValue(int pos) = 0;
	//����AVC��ֵ�ƻ�λ�����õ�ǰʵ�ʵ�ѹ�ο�ֵ
	virtual bool SetVoltageReferValue(int pos, double dVoltRef) = 0;
	//����AVC��ֵ�ƻ�λ�ö�ȡ��ǰʵ���޹����ʲο�ֵ
	virtual double GetRepowerReferValue(int pos) = 0;
	//����AVC��ֵ�ƻ�λ�����õ�ǰʵ���޹����ʲο�ֵ
	virtual bool SetRepowerReferValue(int pos, double dRepowRef) = 0;
};

#endif
