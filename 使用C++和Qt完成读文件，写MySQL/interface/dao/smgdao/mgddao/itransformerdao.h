//itransformerdao.h

#ifndef _ITRANSFORMERDAO_PENGSHIKANG_20120511_H_
#define _ITRANSFORMERDAO_PENGSHIKANG_20120511_H_

#include "../../ibasicdao.h"                        // for IBasicDao

#define TRANSFORMERDAO_CLASSID    "ctransformerdao"
#define TRANSFORMERDAO_INTFID     "itransformerdao"

class IEquipDao;
class IAnalogDao;
class IStatusDao;
class IBusDao;
class ICommSrcDao;
class IControlDao;

class ITransformerDao : virtual public IBasicDao
{
public:
	//���òɼ�����Դ����
	virtual void SetCommSrcDao(ICommSrcDao* pCommSrc) = 0;
	//����ģ����ʵ�����
	virtual void SetAnalogDao(IAnalogDao* pAnalog) = 0;
	//����״̬��ʵ�����
	virtual void SetStatusDao(IStatusDao* pStatus) = 0;
	//���ÿ�����ʵ�����
	virtual void SetControlDao(IControlDao* pControl) = 0;
	//����ĸ��ʵ�����
	virtual void SetBusDao(IBusDao* pBus) = 0;

	//��ʼ�����е�ĸ��������ѹ����Ϣ
	virtual void InitAllBusTransNaborInfo() = 0;
	//��ʼ�����б�ѹ�������VQC����ϵͳ����Ϣ
	virtual void InitAllAdjustAreaNos() = 0;
	
	//���ݱ�ѹ�������λ�����ø���������ʵʱֵ
	virtual void SetMeasureValues(int pos, int* nBrkPos, int& nTapPos) = 0;
	
	//���ݱ�ѹ������λ�õõ������
	virtual double GetCapacity(int pos) = 0;
	//���ݱ�ѹ������λ�õõ���΢��ID
	virtual int GetSubMicGridID(int pos) = 0;
	//���ݱ�ѹ������λ�õõ���ѹ������
	virtual int GetWindingType(int pos) = 0;
	//���ݱ�ѹ������λ���ж��Ƿ�Ϊ�ɵ���ѹ��
	virtual int IsControllable(int pos) = 0;
	//���ݱ�ѹ������λ�õõ��ֽ�ͷ���λ��
	virtual int GetMaxTapPos(int pos) = 0;
	//���ݱ�ѹ������λ�õõ��ֽ�ͷ��λ��Ч����
	virtual int GetUnuseTapCode(int pos) = 0;
	//���ݱ�ѹ������λ�ú������ŵõ��������������ĸ��ID
	virtual int GetWindingBusID(int pos, int windingNo) = 0;
	//���ݱ�ѹ������λ�ú������ŵõ����������������ң����ID
	virtual int GetWindingPosStatusID(int pos, int windingNo) = 0;
	//���ݱ�ѹ������λ�ú������ŵõ����������������״ֵ̬
	virtual int GetWindingSwitchPos(int pos, int windingNo) = 0;
	//���ݱ�ѹ������λ�õõ��ֽ�ͷÿ������ʱ��
	virtual int GetTapActTime(int pos) = 0;
	//���ݱ�ѹ������λ�õõ�ͬ����ʱ����
	virtual int GetActTimespan(int pos) = 0;
	//���ݱ�ѹ������λ�õõ�������ʱ����
	virtual int GetReactTimespan(int pos) = 0;
	//���ݱ�ѹ������λ�õõ��ն���������
	virtual int GetMaxActTimesOfADay(int pos) = 0;
	//���ݱ�ѹ������λ�õõ��ն���ʧ��������
	virtual int GetMaxFailTimesOfADay(int pos) = 0;
	//���ݱ�ѹ������λ�õõ��������ֽ�ͷ������
	virtual int GetMaxAscendTimes(int pos) = 0;
	//���ݱ�ѹ������λ�õõ��������ֽ�ͷ������
	virtual int GetMaxDescendTimes(int pos) = 0;
	//���ݱ�ѹ������λ�õõ��ֽ�ͷ�����ѹ����־
	virtual bool IsVoltageAgreeWithTapChange(int pos) = 0;
	//���ݱ�ѹ������λ�õõ���λ״̬��ID
	virtual int GetTapMeasId(int pos) = 0;
	//���ݱ�ѹ������λ�õõ���λ��ң����ID
	virtual int GetTapUpCtrlId(int pos) = 0;
	//���ݱ�ѹ������λ�õõ���λ��ң����ID
	virtual int GetTapDownCtrlId(int pos) = 0;
	//���ݱ�ѹ������λ�õõ���λͣң����ID
	virtual int GetTapStopCtrlId(int pos) = 0;
	
	//���ݱ�ѹ������λ�õõ��Ƿ�����
	virtual bool IsRunning(int pos) = 0;
	//���ݱ�ѹ������λ�õõ���ѹ��������������
	virtual int GetAdjustAreaNo(int pos) = 0;
	//���ݱ�ѹ������λ�õõ���ǰ��λλ��
	virtual int GetCurTapPos(int pos) = 0;
	//���ݱ�ѹ������λ�õõ��ϴε�λλ��
	virtual int GetOldTapPos(int pos) = 0;
	//���ݱ�ѹ������λ�õõ��������ֽ�ͷ����
	virtual int GetCurAscendTimes(int pos) = 0;
	//���ݱ�ѹ������λ�õõ��������ֽ�ͷ����
	virtual int GetCurDescendTimes(int pos) = 0;
	//���ݱ�ѹ������λ�õõ����һ���Ŷ�ʱ��
	virtual double GetRecentDisturbTime(int pos) = 0;
	//���ݱ�ѹ������λ�õõ����һ�ζ���ʱ��
	virtual double GetRecentActTime(int pos) = 0;
	//���ݱ�ѹ������λ�õõ����һ�ζ�������
	virtual int GetRecentActTrend(int pos) = 0;
	//���ݱ�ѹ������λ�õõ��ֽ�ͷ�Ƿ��ѵ����λ��
	virtual bool IsAtMaxTapPos(int pos) = 0;
	//���ݱ�ѹ������λ�õõ��ֽ�ͷ�Ƿ��ѵ���Сλ��
	virtual bool IsAtMinTapPos(int pos) = 0;
	//���ݱ�ѹ������λ�õõ���������ʧ�ܴ���
	virtual int GetContinueFailTimes(int pos) = 0;
	//���ݱ�ѹ������λ�õõ���ʧ�ܴ���
	virtual int GetActFailTimesOfToday(int pos) = 0;
	//���ݱ�ѹ������λ�õõ��ն�������
	virtual int GetActTimesOfToday(int pos) = 0;

	//���ݱ�ѹ������λ�����ñ�ѹ��������������
	virtual bool SetAdjustAreaNo(int pos, int adjustNo) = 0;
	//���ݱ�ѹ������λ�ú����������ø��������������״ֵ̬
	virtual bool SetWindingSwitchPos(int pos, int windingNo, int swiPos) = 0;
	//���ݱ�ѹ������λ�����õ�ǰ��λλ��
	virtual bool SetCurTapPos(int pos, int nValue) = 0;
	//���ݱ�ѹ������λ�������ϴε�λλ��
	virtual bool SetOldTapPos(int pos, int nValue) = 0;
	//���ݱ�ѹ������λ�����ó������ֽ�ͷ����
	virtual bool SetCurAscendTimes(int pos, int nValue) = 0;
	//���ݱ�ѹ������λ�����ó������ֽ�ͷ����
	virtual bool SetCurDescendTimes(int pos, int nValue) = 0;
	//���ݱ�ѹ������λ���������һ���Ŷ�ʱ��
	virtual bool SetRecentDisturbTime(int pos, double dValue) = 0;
	//���ݱ�ѹ������λ���������һ�ζ���ʱ��
	virtual bool SetRecentActTime(int pos, double dValue) = 0;
	//���ݱ�ѹ������λ���������һ�ζ�������
	virtual bool SetRecentActTrend(int pos, int nValue) = 0;
	//���ݱ�ѹ������λ�����÷ֽ�ͷ�Ƿ��ѵ����λ��
	virtual bool SetAtMaxTapPos(int pos, bool bValue) = 0;
	//���ݱ�ѹ������λ�����÷ֽ�ͷ�Ƿ��ѵ���Сλ��
	virtual bool SetAtMinTapPos(int pos, bool bValue) = 0;
	//���ݱ�ѹ������λ�����ö�������ʧ�ܴ���
	virtual bool SetContinueFailTimes(int pos, int nValue) = 0;
	//���ݱ�ѹ������λ��������ʧ�ܴ���
	virtual bool SetActFailTimesOfToday(int pos, int nValue) = 0;
	//���ݱ�ѹ������λ�������ն�������
	virtual bool SetActTimesOfToday(int pos, int nValue) = 0;
	
	//���ݱ�ѹ������λ�ú������ŵõ���������ѹ���޹����仯��
	virtual double GetWindingMaxOffset(int pos, int windingNo) = 0;
	//���ݱ�ѹ������λ�ú������ŵõ���������ѹ���޹���С�仯��
	virtual double GetWindingMinOffset(int pos, int windingNo) = 0;

	//���ݱ�ѹ������λ�ú������ŵõ��й�ң��ID
	virtual int GetTappId(int pos, int windingNo) = 0;
	//���ݱ�ѹ������λ�ú������ŵõ��޹�ң��ID
	virtual int GetTapqId(int pos, int windingNo) = 0;
	//���ݱ�ѹ������λ�ú������ŵõ��й�
	virtual double GetTapp(int pos, int windingNo) = 0;
	//���ݱ�ѹ������λ�ú������ŵõ��޹�
	virtual double GetTapq(int pos, int windingNo) = 0;

	//���ݱ�ѹ������λ�õõ�����ͨ����ͨ״̬
	virtual int GetSrcConnectState(int pos) = 0;
	//���ݱ�ѹ������λ����������ͨ����ͨ״̬
	virtual bool SeSrcConnectState(int pos, int srcState) = 0;
	//���ݱ�ѹ������λ�ú�����Ĺ������ж�������ѹ�������Ƿ����
	virtual bool IsOverPower(int pos, double dOverRate=1.0) = 0;

	//�����豸ʵ�����
	virtual void SetEquipDao(IEquipDao* pEquip) = 0;

};

#endif
