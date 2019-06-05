//ivqcrundatadao.h

#ifndef _IVQCRUNDATADAO_PENGSHIKANG_20120628_H_
#define _IVQCRUNDATADAO_PENGSHIKANG_20120628_H_

#include "../../ibasicdao.h"                     // for IBasicDao

#define VQCRUNDATADAO_CLASSID    "cvqcrundatadao"
#define VQCRUNDATADAO_INTFID     "ivqcrundatadao"

class IVqcRunDataDao : virtual public IBasicDao
{
public:
	virtual void SetTargetIsRp(int pos, int isRpTarget) = 0;
	virtual void SetVoltageRange(int pos, double upper, double lower) = 0;
	virtual void SetQOrCosRange(int pos, double upper, double lower) = 0;
	virtual void SetCurrentVoltage(int pos, double rateVolt, double realVolt) = 0;
	virtual void SetCurrentPower(int pos, double curP, double curQ, double curPF) = 0;
	virtual void SetEnableFlag(int pos, bool isEnable) = 0;
	virtual void ClearEnableFlag() = 0;

	//����Vqcʵʱ���б�λ�ö�ȡͳ�ƴ洢���ڣ����ڼƻ���ʷ�洢��
	virtual int GetSaveTimerID(int pos) = 0;
	//����Vqcʵʱ���б�λ�ö�ȡͳ�ƴ洢��־
	virtual int GetSaveFlag(int pos) = 0;
	//����Vqcʵʱ���б�λ�ø�λ�ü�¼��ͳ�ƴ洢��־
	virtual bool ResetSaveFlag(int pos) = 0;

	virtual void SetVoltageBase(int pos, double baseV) = 0;
	virtual void SetVoltageRatio(int pos, double dUdatio) = 0;
	virtual void SetRefVoltageRange(int pos, double upper, double lower) = 0;
	virtual void SetRefVoltageValue(int pos, double refVolt) = 0;

	//����Vqcʵʱ���б�λ�õõ����һ��ͳ��ʱ��
	virtual double GetStatisticsTime(int pos) = 0;
	//����Vqcʵʱ���б�λ���������һ��ͳ��ʱ��
	virtual bool SetStatisticsTime(int pos, double curTime) = 0;

	virtual int GetTargetIsRp(int pos) = 0;
	virtual double GetRateVoltage(int pos) = 0;
	virtual double GetRealVoltage(int pos) = 0;
	virtual double GetVoltageUpper(int pos) = 0;
	virtual double GetVoltageLower(int pos) = 0;
	virtual double GetRealReactPower(int pos) = 0;
	virtual double GetReactPowerUpper(int pos) = 0;
	virtual double GetReactPowerLower(int pos) = 0;

	virtual void SetRateVoltage(int pos, double dValue) = 0;
	virtual void SetRealVoltage(int pos, double dValue) = 0;
	virtual void SetRealReactPower(int pos, double dValue) = 0;
	virtual void SetReactPowerUpper(int pos, double dValue) = 0;
	virtual void SetReactPowerLower(int pos, double dValue) = 0;
		
	virtual bool SetAdjustQLower(int pos, double dValue) = 0;
	virtual double GetAdjustQLower(int pos) = 0;
	virtual bool SetAdjustQUpper(int pos, double dValue) = 0;
	virtual double GetAdjustQUpper(int pos) = 0;
	virtual bool SetAdjustQIncLimit(int pos, double dValue) = 0;
	virtual double GetAdjustQIncLimit(int pos) = 0;
	virtual bool SetAdjustQDecLimit(int pos, double dValue) = 0;
	virtual double GetAdjustQDecLimit(int pos) = 0;
	virtual bool SetAdjustQIncLock(int pos, int iValue) = 0;
	virtual int GetAdjustQIncLock(int pos) = 0;
	virtual bool SetAdjustQDecLock(int pos, int iValue) = 0;
	virtual int GetAdjustQDecLock(int pos) = 0;
	//�����ݱ�Ķ�̬��Ϣд�����[save]
	virtual void WriteDynamicInfo1() = 0;
	virtual double GetRealPowerFactor(int pos) = 0;

	virtual void SetAvcPlanTypeAndPlanId(int pos, int iPlanType, int iPlanID) = 0;
	// ��ȡ��ǰ��ѹ�޹����Ƽƻ����� 0 -- VQC;1 -- AVC
	virtual int GetCurPlanType(int pos) = 0;
	// ��ȡ��ǰ��ѹ�޹����Ƽƻ�ID 
	virtual int GetCurPlanID(int pos) = 0;
	// ��ȡ��ǰ��ѹ��׼ֵ
	virtual double GetVoltageBase(int pos) = 0;

	//�õ���ǰ��ѹ�޹��������ƴ���
	virtual bool GetCurCtrlTimes(int id, int& areaNo, int& actCount) = 0;
	//�õ���ǰ״̬�㴦�ھ���ͼ�е�����
	virtual int GetNineAreaPos(int pos) = 0;
	//���õ�ǰ��ѹ�޹��������ƴ���
	virtual bool SetCurCtrlTimes(int pos, int ctrlTimes) = 0;
	//���õ�ǰ״̬���ھ���ͼ�е�����
	virtual bool SetNineAreaPos(int pos, int areaNo) = 0;
	//���µ�ǰ��ѹ�޹��������ƴ���
	virtual bool UpdateCurCtrlTimes(int id, int areaNo, bool hasAct) = 0;
	//����ǰ��ѹ�޹��������ƴ���д��ʵʱ����
	virtual void WriteCurCtrlTimes() = 0;

	//�ж����ݱ����Ƿ���ڲο���ѹ���ޡ����ޡ���ǰֵ���ֶ�
	virtual bool HasRefVoltageValue() = 0;
	//�ж����ݱ����Ƿ���ڵ�ǰ�������ƴ���������ͼ�������ֶ�
	virtual bool HasCurCtrlTimes() = 0;

	virtual bool SetRpcAdjustQLowerValue(int pos, double dValue) = 0;//���ö�̬�޹��ɵ�����ֵ
	virtual double GetRpcAdjustQLowerValue(int pos) = 0;//�õ���̬�޹��ɵ�����ֵ
	virtual bool SetRpcAdjustQUpperValue(int pos, double dValue) = 0;//���ö�̬�޹��ɵ�����ֵ
	virtual double GetRpcAdjustQUpperValue(int pos) = 0;//�õ���̬�޹��ɵ�����ֵ
	virtual bool SetRpcAdjustQLowerAim(int pos, double dValue) = 0;//���ö�̬�޹��ɵ�����Ŀ��ֵ
	virtual double GetRpcAdjustQLowerAim(int pos) = 0;//�õ���̬�޹��ɵ�����Ŀ��ֵ
	virtual bool SetRpcAdjustQUpperAim(int pos, double dValue) = 0;//���ö�̬�޹��ɵ�����Ŀ��ֵ
	virtual double GetRpcAdjustQUpperAim(int pos) = 0;//�õ���̬�޹��ɵ�����Ŀ��ֵ

	virtual bool SetCurTotalRpcQ(int pos,double dValue) = 0; //����ȫվ��̬���޹�
	virtual double GetCurTotalRpcQ(int pos) = 0;//�õ�ȫվ��̬���޹�
	virtual bool SetMaxTotalRpcQ(int pos,double dValue) = 0; //���ö�̬�޹�ֵ����
	virtual double GetMaxTotalRpcQ(int pos) = 0;//�õ�ȫ��̬�޹�ֵ����
	virtual bool SetMinTotalRpcQ(int pos,double dValue) = 0; //���ö�̬�޹�ֵ����
	virtual double GetMinTotalRpcQ(int pos) = 0;//�õ���̬�޹�ֵ����

	//����VQCʵʱ���м�¼λ�����ÿ���ĸ��ID
	virtual bool SetCtrlBusID(int pos, int iBusId) = 0;
	//����VQCʵʱ���м�¼λ�ö�ȡ����ĸ��ID
	virtual int GetCtrlBusID(int pos) = 0;
	//���ݿ���ĸ��ID�õ�VQCʵʱ���м�¼λ�á�������-1����ʾ�����ڸ�ĸ�߶�Ӧ�ļ�¼
	virtual int GetPositionByBusID(int iBusId) = 0;

	//����VQCʵʱ���м�¼λ�ö�ȡ��ǰ��¼�Ƿ���Ч
	virtual bool IsEnabled(int pos) = 0;


};

#endif
