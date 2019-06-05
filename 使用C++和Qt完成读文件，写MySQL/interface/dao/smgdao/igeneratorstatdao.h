//igeneratorstatdao.h

#ifndef _IGENERATORSTATDAO_PENGSHIKANG_20150713_H_
#define _IGENERATORSTATDAO_PENGSHIKANG_20150713_H_

#include "mgddao/igeneratordao.h"                // for IMgdDao

#define GENERATORSTATDAO_CLASSID    "cgeneratorstatdao"
#define GENERATORSTATDAO_INTFID     "igeneratorstatdao"

class IGeneratorStatDao : virtual public IBasicDao
{
public:
	//�����ݱ�Ķ�̬��Ϣд�����[save]
	virtual void WriteDynamicInfo1() = 0;

	//���ݷ����ͳ��λ�ö�ȡͳ�ƴ洢���ڣ����ڼƻ���ʷ�洢��
	virtual int GetSaveTimerID(int pos) = 0;

	//���ݷ����ͳ��λ�õõ�����󷢵繦��
	virtual double GetMaxPower(int pos) = 0;
	//���ݷ����ͳ��λ����������󷢵繦��
	virtual bool SetMaxPower(int pos, double maxPower) = 0;

	//���ݷ����ͳ��λ�õõ���ͣ��ʱ��(Сʱ)
	virtual double GeStopHours(int pos) = 0;
	//���ݷ����ͳ��λ��������ͣ��ʱ��(Сʱ)
	virtual bool SetStopHours(int pos, double stopHours) = 0;

	//���ݷ����ͳ��λ�õõ��մ���ʱ��(Сʱ)
	virtual double GetBackupHours(int pos) = 0;
	//���ݷ����ͳ��λ�������մ���ʱ��(Сʱ)
	virtual bool SetBackupHours(int pos, double waitHours) = 0;

	//���ݷ����ͳ��λ�õõ��շ���ʱ��(Сʱ)
	virtual double GetRunHours(int pos) = 0;
	//���ݷ����ͳ��λ�������շ���ʱ��(Сʱ)
	virtual bool SetRunHours(int pos, double runHours) = 0;

	//���ݷ����ͳ��λ�õõ����޵�ʱ��(Сʱ)
	virtual double GetLimitHours(int pos) = 0;
	//���ݷ����ͳ��λ���������޵�ʱ��(Сʱ)
	virtual bool SetLimitHours(int pos, double lmtHours) = 0;

	//���ݷ����ͳ��λ�õõ���ǰ������
	virtual double GetRunGenRate(int pos) = 0;
	//���ݷ����ͳ��λ�����õ�ǰ������
	virtual bool SetRunGenRate(int pos, double runRate) = 0;

	//���ݷ����ͳ��λ�õõ���ǰ�޵���
	virtual double GetLimitGenRate(int pos) = 0;
	//���ݷ����ͳ��λ�����õ�ǰ�޵���
	virtual bool SetLimitGenRate(int pos, double runRate) = 0;

	//���ݷ����ͳ��λ�õõ����շ�����
	virtual double GetTodayEnergy(int pos) = 0;
	//���ݷ����ͳ��λ�õõ��ۼƷ�����
	virtual double GetTotalEnergy(int pos) = 0;
	//���ݷ����ͳ��λ�ø��½��շ��������ۼƷ�����
	virtual bool UpdateGenEnergy(int pos, double todayW, double totalW) = 0;

	//���ݷ����ͳ��λ�õõ�����󷢵繦�ʳ���ʱ��
	virtual double GetMaxPowerTime(int pos) = 0;
	//���ݷ����ͳ��λ����������󷢵繦�ʳ���ʱ��
	virtual bool SetMaxPowerTime(int pos, double curTime) = 0;

	//���ݷ����ͳ��λ�õõ����һ��ͳ��ʱ��
	virtual double GetStatisticsTime(int pos) = 0;
	//���ݷ����ͳ��λ���������һ��ͳ��ʱ��
	virtual bool SetStatisticsTime(int pos, double curTime) = 0;

	//��ȡ�����ͳ�Ʊ��ͳ�ƴ洢��־
	virtual void ReadSaveFlags() = 0;
	//���ݷ����ͳ��λ�õõ�ͳ�ƴ洢��־
	virtual int GetSaveFlag(int pos) = 0;
	//��λָ����¼λ�õ�ͳ�ƴ洢��־
	virtual bool ResetSaveFlag(int pos) = 0;

};

#endif
