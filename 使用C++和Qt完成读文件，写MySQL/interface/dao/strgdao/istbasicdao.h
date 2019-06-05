//istbasicdao.h

#ifndef _ISTBASICDAO_20190527_YANGZHENYU_H_
#define _ISTBASICDAO_20190527_YANGZHENYU_H_

#include "../ibasicdao.h"                             // for IMgdDao

#define STBASICDAO_CLASSID    "cstbasicdao"
#define STBASICDAO_INTFID     "istbasicdao"


class IStbasicdao : virtual public IBasicDao
{
public:	
	//��̬
	//���ݴ��ܵ�վλ�õõ�����������id
	virtual int GetMgID(int pos) = 0;

	//���ݴ��ܵ�վλ�õõ��װ������(MW)
	virtual double GetBatCapacity(int pos) = 0;

	//���ݴ��ܵ�վλ�õõ��豸װ��̨��
	virtual double GetTotalEqNum(int pos) = 0;

	//���ݴ��ܵ�վλ�õõ�Ӧ��ϵͳ
	virtual const char* GetFamilyName(int pos) = 0;

	////���ݴ��ܵ�վλ�õõ�ʣ������SOCID
	//virtual int GetSocId(int pos) = 0;

	////���ݴ��ܵ�վλ�õõ�ʣ������SOC
	//virtual double GetCurSoc(int pos) = 0;

	////���ݴ��ܵ�վλ�õõ�ȫվSOHID
	//virtual int GetSohId(int pos) = 0;

	////���ݴ��ܵ�վλ�õõ�ȫվ���ƽ���¶�ID
	//virtual int GetTempId(int pos) = 0;

	////���ݴ��ܵ�վλ�õõ���ǰȫվSOH
	//virtual double GetSoh(int pos) = 0;

	////���ݴ��ܵ�վλ�õõ���ǰȫվ���ƽ���¶�
	//virtual double GetTemperature(int pos) = 0;

	//���ݴ��ܵ�վλ�õõ�Զ���͵�ѹ��ID
	virtual int GetFarclampID(int pos) = 0;

	//���ݴ��ܵ�վλ�õõ�AGC����ѹ��ID
	virtual int GetPclampID(int pos) = 0;

	//���ݴ��ܵ�վλ�õõ�����AGC����״̬ID
	virtual int GetAgcStatusid(int pos) = 0;

	//���ݴ��ܵ�վλ�õõ�����������ID
	virtual int GetRunGenCptyID(int pos) = 0;

	//���ݴ��ܵ�վλ�õõ��й��ɵ�����ID
	virtual int GetCtrlGenCptyID(int pos) = 0;

	//���ݴ��ܵ�վλ�õõ����ɷ��й�ID
	virtual int GetMaxpID(int pos) = 0;

	//���ݴ��ܵ�վλ�õõ����ɳ��й�ID
	virtual int GetMinPID(int pos) = 0;

	//���ݴ��ܵ�վλ�õõ������й�ID
	virtual int GetIncreasPID(int pos) = 0;

	//���ݴ��ܵ�վλ�õõ��ɼ��й�ID
	virtual int GetDiminsPID(int pos) = 0;

	//���ݴ��ܵ�վλ�õõ����������й�ID
	virtual int GetPccPid(int pos) = 0;

	////���ݴ��ܵ�վλ�õõ����ܳ�ŵ����й�ID
	//virtual int GetStoragePid(int pos) = 0;

	//���ݴ��ܵ�վλ�õõ��й�����ֵID
	virtual int GetPFdbckID(int pos) = 0;

	//���ݴ��ܵ�վλ�õõ��й�����ң��ID
	virtual int GetPCtrlID(int pos) = 0;

	//���ݴ��ܵ�վλ�õõ�����AVC����״̬ID
	virtual int GetAvcStatusid(int pos) = 0;

	//���ݴ��ܵ�վλ�õõ�AVC����ѹ��ID
	virtual int GetQclampID(int pos) = 0;

	//���ݴ��ܵ�վλ�õõ����ɷ��޹�ID
	virtual int GetMaxQID(int pos) = 0;

	//���ݴ��ܵ�վλ�õõ��������޹�ID
	virtual int GetMinQID(int pos) = 0;

	//���ݴ��ܵ�վλ�õõ������޹�ID
	virtual int GetIncreasQID(int pos) = 0;

	//���ݴ��ܵ�վλ�õõ��ɼ��޹�ID
	virtual int GetDiminsQID(int pos) = 0;

	//���ݴ��ܵ�վλ�õõ��������ѹID
	virtual int GetVolID(int pos) = 0;

	//���ݴ��ܵ�վλ�õõ����������޹�ID
	virtual int GetPccQid(int pos) = 0;

	////���ݴ��ܵ�վλ�õõ����ܳ�ŵ��޹�ID
	//virtual int GetStorageQid(int pos) = 0;

	//���ݴ��ܵ�վλ�õõ��޹�����ֵID
	virtual int GetQFdbckID(int pos) = 0;

	//���ݴ��ܵ�վλ�õõ��޹�����ң��ID
	virtual int GetQCtrlID(int pos) = 0;

	//���ݴ��ܵ�վλ�õõ����������ID
	virtual int GetTodayinPtID(int pos) = 0;

	//���ݴ��ܵ�վλ�õõ�����ŵ����ID
	virtual int GetTodayoutPtID(int pos) = 0;

	//���ݴ��ܵ�վλ�õõ��ۼ��ܳ����ID
	virtual int GetTotalinPtID(int pos) = 0;

	//���ݴ��ܵ�վλ�õõ��ۼ��ܷŵ���ID
	virtual int GetTotaloutPtID(int pos) = 0;



	////���ݴ��ܵ�վλ�õõ�����վ���õ������ʣ������
	//virtual double GetConMaxCap(int pos) = 0;
	//////���ݴ��ܵ�վλ�����ô���վ���õ������ʣ������
	////virtual bool SetConMaxCap(int pos, double ConMaxCap) = 0;

	////���ݴ��ܵ�վλ�õõ�����վ���õ�����Сʣ������
	//virtual double GetConMinCap(int pos) = 0;
	//////���ݴ��ܵ�վλ�����ô���վ���õ�����Сʣ������
	////virtual bool SetConMinCap(int pos, double ConMinCap) = 0;

	////���ݴ��ܵ�վλ�õõ�����վ�������ʣ������
	//virtual double GetExchMaxCap(int pos) = 0;
	//////���ݴ��ܵ�վλ�����ô���վ�������ʣ������
	////virtual bool SetExchMaxCap(int pos, double ExchMaxCap) = 0;

	////���ݴ��ܵ�վλ�õõ�����վ������Сʣ������
	//virtual double GetDisconMinCap(int pos) = 0;
	//////���ݴ��ܵ�վλ�����ô���վ������Сʣ������
	////virtual bool SetDisconMinCap(int pos, double DisconMinCap) = 0;

	//���ݴ��ܵ�վλ�õõ���ʷֵ�洢����
	virtual int GetSvTimerID(int pos) = 0;
	////���ݴ��ܵ�վλ��������ʷֵ�洢����
	//virtual bool SetSvTimerID(int pos, int SvTimerID) = 0;

	//���ݴ��ܵ�վλ�õõ�ң��������ϵ��
	virtual double GetSensitivity(int pos) = 0;
	////���ݴ��ܵ�վλ������ң��������ϵ��
	//virtual bool SetSensitivity(int pos, double Sensitivity) = 0;

	//���ݴ��ܵ�վλ�õõ������豸̨��ң��ID
	virtual int GetRunEqNumID(int pos) = 0;

	//���ݴ��ܵ�վλ�õõ��¹����ź�ң��ID
	virtual int GetTotalFtID(int pos) = 0;

	//���ݴ��ܵ�վλ�õõ���̬�����޹�ID
	virtual int GetDyInsQID(int pos) = 0;

	//���ݴ��ܵ�վλ�õõ���̬�ɼ��޹�ID
	virtual int GetDyDisQID(int pos) = 0;





	//��̬
	////���ݴ��ܵ�վλ�õõ������������
	//virtual double GetBatCapacity(int pos) = 0;
	////���ݴ��ܵ�վλ�����õ����������
	//virtual bool SetBatCapacity(int pos, double BatCapacity) = 0;

	//���ݴ��ܵ�վλ�õõ���ǰԶ���͵�ѹ��
	virtual int GetFarclamp(int pos) = 0;
	//���ݴ��ܵ�վλ�����õ�ǰԶ���͵�ѹ��
	virtual bool SetFarclamp(int pos, int Farclamp) = 0;

	//���ݴ��ܵ�վλ�õõ���ǰAGCѹ��
	virtual int GetAGCclamp(int pos) = 0;
	//���ݴ��ܵ�վλ�����õ�ǰAGCѹ��
	virtual bool SetAGCclamp(int pos, int AGCclamp) = 0;

	//���ݴ��ܵ�վλ�õõ���ǰ����AGC����״̬
	virtual int GetAGCCurRunState(int pos) = 0;
	//���ݴ��ܵ�վλ�����õ�ǰ����AGC����״̬
	virtual bool SetAGCCurRunState(int pos, int AGCrunState) = 0;

	//���ݴ��ܵ�վλ�õõ���ǰ����AVC����״̬
	virtual int GetAVCCurRunState(int pos) = 0;
	//���ݴ��ܵ�վλ�����õ�ǰ����AVC����״̬
	virtual bool SetAVCCurRunState(int pos, int AVCrunState) = 0;

	//���ݴ��ܵ�վλ�õõ���ǰ��������
	virtual double GetCurRunGenCpty(int pos) = 0;
	//���ݴ��ܵ�վλ�����õ�ǰ��������
	virtual bool SetCurRunGenCpty(int pos, double CurRunGenCpty) = 0;

	//���ݴ��ܵ�վλ�õõ���ǰ�й��ɵ�����
	virtual double GetCurCtrlGenCpty(int pos) = 0;
	//���ݴ��ܵ�վλ�����õ�ǰ�й��ɵ�����
	virtual bool SetCurCtrlGenCpty(int pos, double CurCtrlGenCpty) = 0;

	//���ݴ��ܵ�վλ�õõ���ǰ�����й�
	virtual double GetCurPccP(int pos) = 0;
	//���ݴ��ܵ�վλ�����õ�ǰ�����й�
	virtual bool SetCurPccP(int pos, double CurPccP) = 0;

	////���ݴ��ܵ�վλ�õõ���ǰ���ܳ�ŵ��й�
	//virtual double GetCurStorageP(int pos) = 0;
	////���ݴ��ܵ�վλ�����õ�ǰ���ܳ�ŵ��й�
	//virtual bool SetCurStorageP(int pos, double CurStorageP) = 0;

	//���ݴ��ܵ�վλ�õõ���ǰ�й�����ֵ
	virtual double GetCurPFdbck(int pos) = 0;
	//���ݴ��ܵ�վλ�����õ�ǰ�й�����ֵ
	virtual bool SetCurPFdbck(int pos, double CurPFdbck) = 0;

	//���ݴ��ܵ�վλ�õõ���ǰ���ɷ��й�
	virtual double GetCurMaxP(int pos) = 0;
	//���ݴ��ܵ�վλ�����õ�ǰ���ɷ��й�
	virtual bool SetCurMaxP(int pos, double CurMaxP) = 0;

	//���ݴ��ܵ�վλ�õõ���ǰ���ɳ��й�
	virtual double GetCurMinP(int pos) = 0;
	//���ݴ��ܵ�վλ�����õ�ǰ���ɳ��й�
	virtual bool SetCurMinP(int pos, double CurMinP) = 0;

	//���ݴ��ܵ�վλ�õõ���ǰ�����й�
	virtual double GetCurIncreasP(int pos) = 0;
	//���ݴ��ܵ�վλ�����õ�ǰ�����й�
	virtual bool SetCurIncreasP(int pos, double CurIncreasP) = 0;

	//���ݴ��ܵ�վλ�õõ���ǰ�ɼ��й�
	virtual double GetCurDiminsP(int pos) = 0;
	//���ݴ��ܵ�վλ�����õ�ǰ�ɼ��й�
	virtual bool SetCurDiminsP(int pos, double CurDiminsP) = 0;

	//���ݴ��ܵ�վλ�õõ��й����Ƽƻ�ֵ
	virtual double GetPlanP(int pos) = 0;
	//���ݴ��ܵ�վλ�������й����Ƽƻ�ֵ
	virtual bool SetPlanP(int pos, double PlanP) = 0;

	////���ݴ��ܵ�վλ�õõ��й�����ԭ��
	//virtual int GetPctrlSort(int pos) = 0;
	////���ݴ��ܵ�վλ�������й�����ԭ��
	//virtual bool SetPctrlSort(int pos, int PctrlSort) = 0;

	//���ݴ��ܵ�վλ�õõ��й�����ʱ��
	virtual double GetPCtrlTime(int pos) = 0;
	//���ݴ��ܵ�վλ�������й�����ʱ��
	virtual bool SetPCtrlTime(int pos) = 0;

	//���ݴ���λ�ó�ʼ���й�����ʧ�ܴ�����
	virtual bool InitPCtrlFailTimes(int pos) = 0;
	//���ݴ���λ�������й�����ʧ�ܴ�����
	virtual bool IncreasePCtrlFailTimes(int pos) = 0;
	//���ݴ���λ�õõ��й�����ʧ�ܴ���
	virtual int GetPCtrlFailTimes(int pos) = 0;

	//���ݴ��ܵ�վλ�õõ��й�ʧ�ܱ���ʱ��
	//virtual double GetPLockedTime(int pos) = 0;
	////���ݴ��ܵ�վλ�������й�ʧ�ܱ���ʱ��
	//virtual bool SetPLockedTime(int pos, double PLockedTime) = 0;

	//���ݴ��ܵ�վλ�õõ���ǰ��ѹ����ֵ(kV)
	virtual double GetCurVolVal(int pos) = 0;
	//���ݴ��ܵ�վλ�����õ�ǰ��ѹ����ֵ(kV)
	virtual bool SetCurVolVal(int pos, double CurVolVal) = 0;

	//���ݴ��ܵ�վλ�õõ���ǰ��ѹ����ֵ
	virtual double GetCurVolPer(int pos) = 0;
	//���ݴ��ܵ�վλ�����õ�ǰ��ѹ����ֵ
	virtual bool SetCurVolPer(int pos, double CurVolPer) = 0;

	//���ݴ��ܵ�վλ�õõ���ǰ�����޹�
	virtual double GetCurPccQ(int pos) = 0;
	//���ݴ��ܵ�վλ�����õ�ǰ�����޹�
	virtual bool SetCurPccQ(int pos, double CurPccQ) = 0;

	////���ݴ��ܵ�վλ�õõ���ǰ���ܳ�ŵ��޹�
	//virtual double GetCurStorageQ(int pos) = 0;
	////���ݴ��ܵ�վλ�����õ�ǰ���ܳ�ŵ��޹�
	//virtual bool SetCurStorageQ(int pos, double CurStorageQ) = 0;

	//���ݴ��ܵ�վλ�õõ���ǰ�޹�����ֵ
	virtual double GetCurQFdbck(int pos) = 0;
	//���ݴ��ܵ�վλ�����õ�ǰ�޹�����ֵ
	virtual bool SetCurQFdbck(int pos, double CurQFdbck) = 0;

	//���ݴ��ܵ�վλ�õõ���ǰ���ɷ��޹�
	virtual double GetCurMaxQ(int pos) = 0;
	//���ݴ��ܵ�վλ�����õ�ǰ���ɷ��޹�
	virtual bool SetCurMaxQ(int pos, double CurMaxQ) = 0;

	//���ݴ��ܵ�վλ�õõ���ǰ�������޹�
	virtual double GetCurMinQ(int pos) = 0;
	//���ݴ��ܵ�վλ�����õ�ǰ�������޹�
	virtual bool SetCurMinQ(int pos, double CurMinQ) = 0;

	//���ݴ��ܵ�վλ�õõ���ǰAVCѹ��
	virtual int GetCurQClamp(int pos) = 0;
	//���ݴ��ܵ�վλ�����õ�ǰAVCѹ��
	virtual bool SetCurQClamp(int pos, int CurQClamp) = 0;

	//���ݴ��ܵ�վλ�õõ���ǰ�����޹�
	virtual double GetCurIncreasQ(int pos) = 0;
	//���ݴ��ܵ�վλ�����õ�ǰ�����޹�
	virtual bool SetCurIncreasQ(int pos, double CurIncreasQ) = 0;

	//���ݴ��ܵ�վλ�õõ���ǰ�ɼ��޹�
	virtual double GetCurDiminsQ(int pos) = 0;
	//���ݴ��ܵ�վλ�����õ�ǰ�ɼ��޹�
	virtual bool SetCurDiminsQ(int pos, double CurDiminsQ) = 0;

	//���ݴ��ܵ�վλ�õõ��޹����Ƽƻ�ֵ
	virtual double GetPlanQ(int pos) = 0;
	//���ݴ��ܵ�վλ�������޹����Ƽƻ�ֵ
	virtual bool SetPlanQ(int pos, double PlanQ) = 0;

	////���ݴ��ܵ�վλ�õõ��޹�����ԭ��
	//virtual int GetQCtrlSort(int pos) = 0;
	////���ݴ��ܵ�վλ�������޹�����ԭ��
	//virtual bool SetQCtrlSort(int pos, int QCtrlSort) = 0;

	//���ݴ��ܵ�վλ�õõ��޹�����ʱ��
	virtual double GetQCrlTime(int pos) = 0;
	//���ݴ��ܵ�վλ�������޹�����ʱ��
	virtual bool SetQCrlTime(int pos) = 0;

	//���ݴ���λ�ó�ʼ���޹�����ʧ�ܴ�����
	virtual bool InitQCtrlFailTimes(int pos) = 0;
	//���ݴ���λ�������޹�����ʧ�ܴ�����
	virtual bool IncreaseQCtrlFailTimes(int pos) = 0;
	//���ݴ���λ�õõ��޹�����ʧ�ܴ���
	virtual int GetQCtrlFailTimes(int pos) = 0;

	//���ݴ��ܵ�վλ�õõ��޹�ʧ�ܱ���ʱ��
	//virtual double GetQLockedTime(int pos) = 0;
	////���ݴ��ܵ�վλ�������޹�ʧ�ܱ���ʱ��
	//virtual bool SetQLockedTime(int pos, double QLockedTime) = 0;

	////���ݴ���λ�ó�ʼ���ܳ�������
	//virtual bool InitChargeTimes(int pos) = 0;
	////���ݴ���λ�������ܳ�������
	//virtual bool IncreaseChargeTimes(int pos) = 0;
	////���ݴ���λ�õõ��ܳ�����
	//virtual int GetChargeTimes(int pos) = 0;

	////���ݴ���λ�ó�ʼ���ܷŵ������
	//virtual bool InitDisChargeTimes(int pos) = 0;
	////���ݴ���λ�������ܷŵ������
	//virtual bool IncreaseDisChargeTimes(int pos) = 0;
	////���ݴ���λ�õõ��ܷŵ����
	//virtual int GetDisChargeTimes(int pos) = 0;

	////���ݴ���λ�ó�ʼ�����ճ�������
	//virtual bool InitTodayChargeTimes(int pos) = 0;
	////���ݴ���λ�����ӽ��ճ�������
	//virtual bool IncreaseTodayChargeTimes(int pos) = 0;
	////���ݴ���λ�õõ����ճ�����
	//virtual int GetTodayChargeTimes(int pos) = 0;

	////���ݴ���λ�ó�ʼ�����շŵ������
	//virtual bool InitTodayDisChargeTimes(int pos) = 0;
	////���ݴ���λ�����ӽ��շŵ������
	//virtual bool IncreaseTodayDisChargeTimes(int pos) = 0;
	////���ݴ���λ�õõ����շŵ����
	//virtual int GetTodayDisChargeTimes(int pos) = 0;

	//���ݴ���λ�õõ����������
	virtual double GetTodayinPt(int pos) = 0;
	//���ݴ��ܵ�վλ�����õ��������
	virtual bool SetTodayinPt(int pos, double TdInP) = 0;

	//���ݴ���λ�õõ�����ŵ����
	virtual double GetTodayoutPt(int pos) = 0;
	//���ݴ��ܵ�վλ�����õ���ŵ����
	virtual bool SetTodayoutPt(int pos, double TdOutP) = 0;

	//���ݴ���λ�õõ��ۼ��ܳ����
	virtual double GetTotalinPt(int pos) = 0;
	//���ݴ��ܵ�վλ�������ۼ��ܳ����
	virtual bool SetTotalinPt(int pos, double TotalInP) = 0;

	//���ݴ���λ�õõ��ۼ��ܷŵ���
	virtual double GetTotaloutPt(int pos) = 0;
	//���ݴ��ܵ�վλ�������ۼ��ܷŵ���
	virtual bool SetTotaloutPt(int pos, double TotalOutP) = 0;

	////���㵱ǰ���ʳ�����ʱ��(����)
	//virtual double CalculateInableT(float minSoc, float maxSoc, float curSoc, float curP, float Capacity) = 0;

	////���㵱ǰ���ʷŵ����ʱ��(����)
	//virtual double CalculateOutableT(float minSoc, float maxSoc, float curSoc, float curP, float Capacity) = 0;

	////��������ʳ�����ʱ��(����)
	//virtual double CalculateMaxPinableT(float minSoc, float maxSoc, float curSoc, float MaxP, float Capacity) = 0;

	////��������ʷŵ����ʱ��(����)
	//virtual double CalculateMaxPoutableT(float minSoc, float maxSoc, float curSoc, float MaxP, float Capacity) = 0;

	////���ݴ��ܵ�վλ�õõ�ȫվ��������־
	//virtual int GetChargeLock(int pos) = 0;
	////���ݴ��ܵ�վλ������ȫվ��������־
	//virtual bool SetChargeLock(int pos, int ChargeLock) = 0;

	////���ݴ��ܵ�վλ�õõ�ȫվ�ŵ������־
	//virtual int GetDisChargeLock(int pos) = 0;
	////���ݴ��ܵ�վλ������ȫվ�ŵ������־
	//virtual bool SetDisChargeLock(int pos, int DisChargeLock) = 0;

	//���ݴ��ܵ�վλ�õõ���ǰͨѶ״̬
	virtual int GetCurNetState(int pos) = 0;
	//���ݴ��ܵ�վλ�����õ�ǰͨѶ״̬
	virtual bool SetCurNetState(int pos, int CurNetState) = 0;

	//���ݴ��ܵ�վλ�õõ������豸̨��
	virtual int GetCurRunEqNum(int pos) = 0;
	//���ݴ��ܵ�վλ�����������豸̨��
	virtual bool SetCurRunEqNum(int pos, int CurRunEqNum) = 0;

	//���ݴ��ܵ�վλ�õõ��¹����ź�
	virtual int GetTotalFt(int pos) = 0;
	//���ݴ��ܵ�վλ�������¹����ź�
	virtual bool SetTotalFt(int pos, int TotalFt) = 0;

	//���ݴ��ܵ�վλ�õõ���ǰ��̬�����޹�
	virtual double GetCurDyInsQ(int pos) = 0;
	//���ݴ��ܵ�վλ�õõ���ǰ��̬�����޹�
	virtual bool SetCurDyInsQ(int pos, double CurDyInsQ) = 0;

	//���ݴ��ܵ�վλ�õõ���ǰ��̬�ɼ��޹�
	virtual double GetCurDyDisQ(int pos) = 0;
	//���ݴ��ܵ�վλ�õõ���ǰ��̬�ɼ��޹�
	virtual bool SetCurDyDisQ(int pos, double CurDyDisQ) = 0;
};

#endif
