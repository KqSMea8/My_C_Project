//iexchcrvplandao.h

#ifndef _IEXCHANGEPOWERCURVEPLANDAO_PENGSHIKANG_20110314_H_
#define _IEXCHANGEPOWERCURVEPLANDAO_PENGSHIKANG_20110314_H_

#include "../ibasicdao.h"                        // for IBasicDao

#define EXCHCURVEPLANDAO_CLASSID    "cexchcurveplandao"
#define EXCHCURVEPLANDAO_INTFID     "iexchcurveplandao"

typedef enum
{
	LOCAL_CURVE, DISPATCH_SETTING, DISPATCH_CURVE5, DISPATCH_CURVE15, DISPATCH_INCREMENT, DISPATCH_SETTING_WK, UNDEFINE,
	// ���أ�       ���ȶ�ֵ��     ����5�������ߣ�  ����15�������ߣ�     ����������          �����ȿأ�         ��ֹ����
}CurvePlanType;

class IExchCurvePlanDao : virtual public IBasicDao
{
public:
	//���ݽ�����������λ�õõ���΢��ID
	virtual int GetSubMicGridID(int pos) = 0;
	//���ݽ�����������λ�ö�ȡ�Ƿ���Ч��־
	virtual int IsEnable(int pos) = 0;
	//������΢��ID�õ���Ч�ı��ؽ����������߼ƻ�ID[��δ��]
	virtual int GetEnableCurvePlanId(int mgId) = 0;	
	//�õ����Ƚ����������߼ƻ�λ��
	virtual int GetDispatchCurvePlanPos(CurvePlanType& dispType) = 0;
	//���ݵ��Ƚ����������߼ƻ�λ���ж��Ƿ���Ч
	virtual bool IsValidDispatchCurvePlan(int pos, double curTime) = 0;

	//���ݽ����������߼ƻ�λ�ö�ȡ���ʵ������͡�
	//����ֵ��0����������ʽ��е��ڣ�1����������������ٷֱȵ���
	virtual int GetPowerAdjustType(int pos) = 0;
	//���ݽ����������߼ƻ�λ�ö�ȡ�ƻ�����ֵ��Դ��
	//����ֵ��0���������üƻ����ߣ�1: Զ�̵����·�����ֵ��2��Զ�������·�5���Ӽƻ����ߣ�3��Զ�������·�15���Ӽƻ����ߣ�4��Զ�������·��й�������
	virtual int GetCurveValueOrigin(int pos) = 0;
	//���ݽ����������߼ƻ�λ�ö�ȡ�����й�����ֵ�Ƿ�������������Ϊ��ֵ��
	//����ֵ��true: ��վ����й�Ϊ����false���й�������վΪ���� 
	virtual bool DispatchPIsOutput(int pos) = 0;
	//���ݽ����������߼ƻ�λ�ö�ȡ�����й�����ֵ�Ƿ���MWΪ��λ��
	//����ֵ��true: ��λΪMW��false����λΪkW�� 
	virtual bool DispatchPInMW(int pos) = 0;
	//���ݽ����������߼ƻ�λ�ö�ȡԶ�̵����������ʱ��
	virtual double GetReceiveTime(int pos) = 0;
	//���ݽ����������߼ƻ�λ�ö�ȡԶ�̵����·����ڶ�ʱ��ID
	virtual int GetUpdateTimerID(int pos) = 0;
	//���ݽ����������߼ƻ�λ�ö�ȡ����ָ����Чʱ����
	virtual double GetValidTimeSpan(int pos) = 0;
	//���ݽ����������߼ƻ�λ�ö�ȡͳ�ƴ洢���ڣ����ڼƻ���ʷ�洢��
	virtual int GetSaveTimerID(int pos) = 0;
	//���ݽ����������߼ƻ�λ�ö�ȡͳ�ƴ洢��־
	virtual int GetSaveFlag(int pos) = 0;
	//���ݽ����������߼ƻ�λ�ö�ȡ��ǰ��������Ŀ��ֵ
	virtual double GetCurrentAimValue(int pos) = 0;
	//���ݽ����������߼ƻ�λ�����õ�ǰ��������Ŀ��ֵ
	virtual bool SetCurrentAimValue(int pos, double aimValue) = 0;

	//���ݽ����������߼ƻ�λ�ñ���Զ�̵�������������Ϣ
	virtual bool SaveDispatchCurveInfo(int pos, double recvTime) = 0;
	//���ݽ����������߼ƻ�λ�ñ���Զ�̵��ȶ�ֵ������Ϣ
	virtual bool SaveDispatchValueInfo(int pos, double recvTime, double aimValue) = 0;

	//���ݽ����������߼ƻ�λ�ö�ȡ��ǰ��������ʵ��ֵ
	virtual double GetActualPower(int pos) = 0;
	//���ݽ����������߼ƻ�λ�õõ����һ��ͳ��ʱ��
	virtual double GetStatisticsTime(int pos) = 0;
	//���ݽ����������߼ƻ�λ�����õ�ǰ��������ʵ��ֵ
	virtual bool SetActualPower(int pos, double curValue, double curTime) = 0;

	//������΢��ID�õ���Ч�ı��ؽ����������߼ƻ�λ��
	virtual int GetLocalCurvePlanPos(int mgId) = 0;	

	//���ݽ����������߼ƻ�λ�ö�ȡ�����·��Ƿ���Ч��־
	virtual bool IsDispatchEnable(int pos) = 0;
	//���ݽ����������߼ƻ�λ�����õ����·��Ƿ���Ч��־
	virtual bool SetDispatchEnable(int pos, int nDispEnable) = 0;
	//�������߼ƻ����͵õ���Ч�Ľ����������߼ƻ�λ��
	virtual int GetPositionByPlanType(CurvePlanType dispType, bool bEnable=true) = 0;
	//���ݽ�����������λ�������Ƿ���Ч��־�����ر����õļ�¼λ��( >= 0 )������ʧ��ʱ����-1��
	virtual int SetEnableFlagByPlanType(CurvePlanType dispType, bool bEnable) = 0;

	//���ݽ����������߼ƻ�λ�ö�ȡ����Ŀ�����͡�0���������ʣ� 1������Դ���繦�ʣ� 2�����ܳ�ŵ繦�ʡ�
	virtual int GetCtrlAimType(int pos) = 0;
	//���ݽ����������߼ƻ�λ�ö�ȡ����Ŀ��ֵ�쳣��־
	virtual int GetAimAbnormalFlag(int pos) = 0;
	//���ݽ����������߼ƻ�λ�����õ���Ŀ��ֵ�쳣��־
	virtual bool SetAimAbnormalFlag(int pos, int nAbnormalFlag) = 0;

};

#endif
