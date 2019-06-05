//imicgridstatdao.h

#ifndef _ICSMICGRIDSTATISTICSDAO_PENGSHIKANG_20160923_H_
#define _ICSMICGRIDSTATISTICSDAO_PENGSHIKANG_20160923_H_

#include "../ibasicdao.h"                        // for IBasicDao
#include "../../smgsrv/smgdatadef.h"             // for MicgridObectInfo

#define CMICGRIDSTATDAO_CLASSID    "cmicgridstatdao"
#define CMICGRIDSTATDAO_INTFID     "imicgridstatdao"

class IAccumuDao;

class IMicgridStatDao : virtual public IBasicDao
{
public:
	//����ң����ʵ�����
	virtual void SetAccumuDao(IAccumuDao* pAccumu) = 0;
	//������΢��ͳ����Ϣ��λ�����ø���������ʵʱֵ
	virtual void SetMeasureValues(int pos, MicgridObectInfo* pCurMgObj, int& nAlarm) = 0;

	//������΢��ͳ����Ϣ��λ�õõ�������������
	virtual double GetTodaySaleEnergy(int pos) = 0;
	//������΢��ͳ����Ϣ��λ�õõ��ۼ���������
	virtual double GetTotalSaleEnergy(int pos) = 0;
	//������΢��ͳ����Ϣ��λ�õõ�������������
	virtual double GetTodayUseEnergy(int pos) = 0;
	//������΢��ͳ����Ϣ��λ�õõ��ۼ���������
	virtual double GetTotalUseEnergy(int pos) = 0;

	//������΢��ͳ����Ϣ��λ�����ý�����������
	virtual bool SetTodaySaleEnergy(int pos, double dTodaySaleWh) = 0;
	//������΢��ͳ����Ϣ��λ�������ۼ���������
	virtual bool SetTotalSaleEnergy(int pos, double dTotalSaleWh) = 0;
	//������΢��ͳ����Ϣ��λ�����ý�����������
	virtual bool SetTodayUseEnergy(int pos, double dTodayUseWh) = 0;
	//������΢��ͳ����Ϣ��λ�������ۼ���������
	virtual bool SetTotalUseEnergy(int pos, double dTotalUseWh) = 0;

	/////////////////////////////////////////////////////////////////////////////

	//������΢��ͳ����Ϣ��λ�ö�ȡͳ�ƴ洢���ڣ����ڼƻ���ʷ�洢��
	virtual int GetSaveTimerID(int pos) = 0;
	//������΢��ͳ����Ϣ��λ�õõ����һ��ͳ��ʱ��
	virtual double GetStatisticsTime(int pos) = 0;
	//������΢��ͳ����Ϣ��λ���������һ��ͳ��ʱ��
	virtual bool SetStatisticsTime(int pos, double curTime) = 0;
	//��ȡ��΢�����ͳ�ƴ洢��־
	virtual void ReadSaveFlags() = 0;
	//������΢��ͳ����Ϣ��λ�õõ�ͳ�ƴ洢��־
	virtual int GetSaveFlag(int pos) = 0;
	//��λָ����¼λ�õ�ͳ�ƴ洢��־
	virtual bool ResetSaveFlag(int pos) = 0;

	//������΢��ͳ����Ϣ��λ�õõ��ɵ�����
	virtual double GetAdjPCapacity(int pos) = 0;
	//������΢��ͳ����Ϣ��λ�õõ��й��ɵ�����
	virtual double GetAdjPUpperLimit(int pos) = 0;
	//������΢��ͳ����Ϣ��λ�õõ��й��ɵ�����
	virtual double GetAdjPLowerLimit(int pos) = 0;
	//������΢��ͳ����Ϣ��λ�õõ������й�
	virtual double GetPIncreaseLimit(int pos) = 0;
	//������΢��ͳ����Ϣ��λ�õõ��ɼ��й�
	virtual double GetDecreaseLimit(int pos) = 0;
	//������΢��ͳ����Ϣ��λ�õõ����������ʧ�й�����
	virtual double GetLossPower(int pos) = 0;
	//������΢��ͳ����Ϣ��λ�õõ��й��ϵ��ڱ�����־
	virtual int GetPIncLockFlag(int pos) = 0;
	//������΢��ͳ����Ϣ��λ�õõ��й��µ��ڱ�����־
	virtual int GetPDecLockFlag(int pos) = 0;
	//������΢��ͳ����Ϣ��λ�õõ��޹�����δ�޵�ʱ�����۷����й�����
	virtual double GetNaturalGeneratePower(int pos) = 0;
	//������΢��ͳ����Ϣ��λ�õõ�δ�޵�ʱ�Ŀ��÷����й�����
	virtual double GetRealGeneratePower(int pos) = 0;

};
#endif
