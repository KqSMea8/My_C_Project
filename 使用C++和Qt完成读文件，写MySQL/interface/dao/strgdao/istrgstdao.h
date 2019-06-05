//istrgstdao.h

#ifndef _ISTRGSTDAO_20190531_YANGZHENYU_H_
#define _ISTRGSTDAO_20190531_YANGZHENYU_H_

#include "../ibasicdao.h"                             // for IMgdDao

#define STRGSTDAO_CLASSID    "cstrgstdao"
#define STRGSTDAO_INTFID     "istrgstdao"


class IStrgstdao : virtual public IBasicDao
{
public:	
	//��̬
	//���ݴ��ܵ�վλ�õõ�����վ�����������
	virtual double GetStBatCapacity(int pos) = 0;

	//���ݴ��ܵ�վλ�õõ�����վ���õ������ʣ������
	virtual double GetConMaxCap(int pos) = 0;

	//���ݴ��ܵ�վλ�õõ�����վ���õ�����Сʣ������
	virtual double GetConMinCap(int pos) = 0;

	//���ݴ��ܵ�վλ�õõ�����վ�������ʣ������
	virtual double GetExchMaxCap(int pos) = 0;

	//���ݴ��ܵ�վλ�õõ�����վ������Сʣ������
	virtual double GetDisconMinCap(int pos) = 0;

	//���ݴ��ܵ�վλ�õõ�ʣ������SOCID
	virtual int GetSocId(int pos) = 0;

	//���ݴ��ܵ�վλ�õõ����ܳ�ŵ����й�ID
	virtual int GetStoragePid(int pos) = 0;

	//���ݴ��ܵ�վλ�õõ����ܳ�ŵ��޹�ID
	virtual int GetStorageQid(int pos) = 0;

	//���ݴ��ܵ�վλ�õõ�ȫվSOHID
	virtual int GetSohId(int pos) = 0;

	//���ݴ��ܵ�վλ�õõ�ȫվ���ƽ���¶�ID
	virtual int GetTempId(int pos) = 0;

	//���ݴ��ܵ�վλ�õõ�������״̬ID
	virtual int GetChrFinishID(int pos) = 0;

	//���ݴ��ܵ�վλ�õõ��ŵ����״̬ID
	virtual int GetDiscFinishID(int pos) = 0;

	//���ݴ��ܵ�վλ�õõ�AGC������ID
	virtual int GetChargeLockID(int pos) = 0;

	//���ݴ��ܵ�վλ�õõ�AGC�ŵ����ID
	virtual int GetDisChargeLockID(int pos) = 0;

	//���ݴ��ܵ�վλ�õõ���ʷֵ�洢����
	virtual int GetSvTimerID(int pos) = 0;

	//���ݴ��ܵ�վλ�õõ�Ӧ��ϵͳ
	virtual const char* GetFamilyName(int pos) = 0;





	//��̬
	//���ݴ��ܵ�վλ�õõ�ʣ������SOC
	virtual double GetCurSoc(int pos) = 0;
	//���ݴ��ܵ�վλ������ʣ������SOC
	virtual bool SetCurSoc(int pos, double CurSoc) = 0;

	//���ݴ��ܵ�վλ�õõ���ǰȫվSOH
	virtual double GetSoh(int pos) = 0;
	//���ݴ��ܵ�վλ�����õ�ǰȫվSOH
	virtual bool SetSoh(int pos,double Soh) = 0;

	//���ݴ��ܵ�վλ�õõ���ǰȫվ���ƽ���¶�
	virtual double GetTemperature(int pos) = 0;
	//���ݴ��ܵ�վλ�����õ�ǰȫվ���ƽ���¶�
	virtual double SetTemperature(int pos,double Temperature) = 0;

	//���ݴ��ܵ�վλ�õõ���ǰ���ܳ�ŵ����й�
	virtual double GetCurStorageP(int pos) = 0;
	//���ݴ��ܵ�վλ�����õ�ǰ���ܳ�ŵ����й�
	virtual bool SetCurStorageP(int pos, double CurStorageP) = 0;

	//���ݴ��ܵ�վλ�õõ���ǰ���ܳ�ŵ����޹�
	virtual double GetCurStorageQ(int pos) = 0;
	//���ݴ��ܵ�վλ�����õ�ǰ���ܳ�ŵ����޹�
	virtual bool SetCurStorageQ(int pos, double CurStorageQ) = 0;

	//���ݴ���λ�õõ��ܳ�����
	virtual int GetChargeTimes(int pos) = 0;
	//���ݴ���λ�������ܳ�������
	virtual bool SetChargeTimes(int pos, int ChargeTimes) = 0;

	//���ݴ���λ�õõ��ܷŵ����
	virtual int GetDisChargeTimes(int pos) = 0;
	//���ݴ���λ�������ܷŵ������
	virtual bool SetDisChargeTimes(int pos, int DisChargeTimes) = 0;

	//���ݴ���λ�õõ����ճ�����
	virtual int GetTodayChargeTimes(int pos) = 0;
	//���ݴ���λ�����ý��ճ�������
	virtual bool SetTodayChargeTimes(int pos, int TodayChargeTimes) = 0;

	//���ݴ���λ�õõ����շŵ����
	virtual int GetTodayDisChargeTimes(int pos) = 0;
	//���ݴ���λ�����ý��շŵ������
	virtual bool SetTodayDisChargeTimes(int pos, int TodayDisChargeTimes) = 0;

	//���㵱ǰ���ʳ�����ʱ��(����)
	virtual double CalculateInableT(float minSoc, float maxSoc, float curSoc, float curP, float Capacity) = 0;

	//���㵱ǰ���ʷŵ����ʱ��(����)
	virtual double CalculateOutableT(float minSoc, float maxSoc, float curSoc, float curP, float Capacity) = 0;

	//��������ʳ�����ʱ��(����)
	virtual double CalculateMaxPinableT(float minSoc, float maxSoc, float curSoc, float MaxP, float Capacity) = 0;

	//��������ʷŵ����ʱ��(����)
	virtual double CalculateMaxPoutableT(float minSoc, float maxSoc, float curSoc, float MaxP, float Capacity) = 0;

	//���ݴ���λ�õõ�������״̬
	virtual int GetChrFinishSt(int pos) = 0;
	//���ݴ��ܵ�վλ�����ó�����״̬
	virtual bool SetChrFinishSt(int pos, int ChrFinishSt) = 0;

	//���ݴ���λ�õõ��ŵ����״̬
	virtual int GetDiscFinishSt(int pos) = 0;
	//���ݴ��ܵ�վλ�����÷ŵ����״̬
	virtual bool SetDiscFinishSt(int pos, int DiscFinishSt) = 0;

	//���ݴ��ܵ�վλ�õõ�AGC������
	virtual int GetChargeLock(int pos) = 0;
	//���ݴ��ܵ�վλ������AGC������
	virtual bool SetChargeLock(int pos, int ChargeLock) = 0;

	//���ݴ��ܵ�վλ�õõ�AGC�ŵ����
	virtual int GetDisChargeLock(int pos) = 0;
	//���ݴ��ܵ�վλ������AGC�ŵ����
	virtual bool SetDisChargeLock(int pos, int DisChargeLock) = 0;
};

#endif
