//isysinfodao.h

#ifndef _ISYSINFODAO_PENGSHIKANG_20100927_H_
#define _ISYSINFODAO_PENGSHIKANG_20100927_H_

#include "../ibasicdao.h"                        // for IBasicDao

#define SYSINFODAO_CLASSID    "csysinfodao"
#define SYSINFODAO_INTFID     "isysinfodao"

enum SYSCTRLMODE
{
	SYSCTRLMODE_ALLAUTO,      // 0--ȫ�Զ�
	SYSCTRLMODE_CUTAUTO,      // 1--�ط��Զ��غϼ໤
	SYSCTRLMODE_MANUAL,       // 2--ȫ�໤
	SYSCTRLMODE_ALARM,        // 3--��������ʾ
	SYSCTRLMODE_NOAUTO,       // 4--�ɿص�����ȷ��
};

enum DISPATCHFLAGBIT
{
	REPOWER_EMERGE=6, 
	POWER_RECALL, 
	POWER_SETTING, 
	POWER_REVERSE, 
	POWER_SMOOTH, 
	STORAGE_PCURVE, 
	POWER_OPTIMIZE, 
	VOLTAGE_SETTING, 
	STORAGE_SOCKEEP, 
	EMERGE_SUPPORT, 
	EMERGE_STOP, 
	QORCOS_SETTING=13,
};

class ISysInfoDao : virtual public IBasicDao
{
public:
	virtual int GetStationNumber() = 0;        //�õ�����������
	virtual int GetMicgridNumber() = 0;        //�õ�΢��������
	virtual int GetProFlag() = 0;              //�õ������־
	virtual double GetExchangePlusMargin() = 0;//�õ�������ֵ������ƫ��
	virtual double GetExchangeNegMargin() = 0; //�õ�������ֵ������ƫ��
	virtual double GetStoragePlusMargin() = 0; //�õ����ܳ�ŵ�������ƫ��
	virtual double GetStorageNegMargin() = 0;  //�õ����ܳ�ŵ�������ƫ��
	virtual double GetMaxReversePower() = 0;   //�õ�������������ż�
	virtual double GetMinStoreCapacity1() = 0; //�õ�����������������1�����ڸ�ֵ����Ͷ2��3������
	virtual double GetMinStoreCapacity2() = 0; //�õ�����������������2�����ڸ�ֵ����Ͷ1�����ɣ�С�ڵ��ڸ�ֵ������2��3������
	virtual double GetMinStoreCapacity3() = 0; //�õ�����������������3��С�ڵ��ڸ�ֵ������1������
	virtual int GetExchangeFlag() = 0;         //�õ�����������������־
	virtual int GetEmergeExchangeFlag() = 0;   //�õ�������������������־
	virtual double GetExchangeSetValue() = 0;  //�õ����������ʶ�ֵ
	//--------0809_0815_zff_new_add-------------------------------//
	virtual bool GetConnectType() = 0;   //�õ�ϵͳ���������� 0:������ 1:������
	virtual int GetIslandproflag() = 0;  //�õ�������ϵͳ���ܴ���
	virtual int GetSysProflag() = 0;     //�õ�΢����ϵͳ���ܴ����־
    virtual int GetBlackStartTime() = 0; //�õ���������ʱʱ��(��)
	virtual int GetStylesWitchSpan() = 0;//�õ����з�ʽ�л�ʱ����(����)
    virtual int GetSwitchDayMaxTimes() = 0; //�õ������ն���������
	virtual double GetSwitchOperSpan() = 0; //�õ����ض���ʱ����(����) 
	virtual double GetLoadMaxImpactTimes() = 0;//������������������
	//---------------------------------------------------------//
	virtual bool ModifyEmergeExchangeFlag(bool bRun) = 0;//(1)Ͷ�뽻�����ʽ���֧��ѹ��
	virtual bool ModifyEmergeStopFlag(bool bRun) = 0;//(2)Ͷ�뽻�����ʽ���ͣ��ѹ��
	virtual bool ModifyExchangeSetValueFlag(bool bRun) = 0;//(3)Ͷ�뽻�����ʶ�ֵ����ѹ��
	virtual bool EnableEmergeExchange(int bEnable) = 0;//(4)�����������ʽ���֧�Ź���
	virtual bool EnableEmergeStop(int bEnable) = 0;//(5)�����������ʽ���ͣ�˹���
	virtual bool ModifyExchangeSetValue(double dESValue) = 0;//(6)�޸Ķ��������ʶ�ֵ
	virtual bool ModifyDispatchFlag(DISPATCHFLAGBIT dispBit, bool bRun) = 0;//(7)Ͷ����Ȳ���ѹ��

	virtual int GetControlPattern() = 0; //�õ������Զ�ִ�з�ʽ
	virtual int GetSysRunStyle() = 0; //�õ���ǰϵͳ����ģʽ
	virtual bool SetSysRunStyle(int runStyle) = 0; //���õ�ǰϵͳ����ģʽ
	virtual bool SetSysAimRunStyle(int runStyle) = 0; //����ϵͳĿ������ģʽ
	virtual int  GetSysAimRunStyle() = 0; //�õ�ϵͳĿ������ģʽ
	virtual bool SetSysNextRunStyle(int runStyle) = 0;//����Ŀ��δ��ϵͳ����ģʽ
	virtual int GetSysNextRunStyle() = 0;	//�õ�δ��ϵͳ����ģʽ
	virtual int GetConnStragetySpan() = 0;	//�õ���������ִ�м��ʱ��(��)
	virtual int GetDispatchFlagUpdate() = 0;//�õ�AGC����ѹ�����״̬
	virtual int GetOnlyLocalFlag() = 0;     //�õ����ز���ѹ��Ͷ���־��0--Զ����1--���ء�
	virtual bool GetLocalFlagUpdate(int& localFlag) = 0;//��ȡ���ز���ѹ��Ͷ���־�Ƿ���
	virtual int GetGroupCtrlFlag() = 0;     //�õ��鲥��ʽȺ�ر�־
	virtual double GetMaxAdjustPStep() = 0; //�õ������й����Ʋ���
	virtual double GetMaxAdjustQStep() = 0; //�õ������޹����Ʋ���
	virtual bool IsPlantSystem() = 0;       //�Ƿ�Ϊ��ѹվϵͳ

	virtual double GetMaxAdjustPRate() = 0; //��ȡ�����·����й������������(kW/Min)
	virtual bool ModifyMaxPowerRate(double dMaxPRate) = 0; //�޸ĵ����·����й������������(kW/Min)
	virtual double GetMinAdjustPower() = 0;//��ȡ�����·��ĵ�������(kW)
	virtual bool ModifyMinAdjustPower(double dMinAdjustP) = 0;//�޸ĵ����·��ĵ�������(kW)
	virtual int GetMaxPowerGenerateMode() = 0;//��ȡ�����·������ɷ������ģʽ��1�����ɷ���ģʽ��0�����ʿ���ģʽ
	virtual bool ModifyMaxPowerGenerateMode(int isMaxPGene) = 0;//�޸ĵ����·������ɷ������ģʽ
	virtual double GetStartWindSpeedOfGenerator() = 0;//�������������������(m/s)
	virtual double GetStartLightIntensityOfGenerator() = 0;//������������������(W/m2)
	virtual bool InEmergeAvcControlling() = 0;//�ж��Ƿ����ý���AVC����ģʽ

	virtual double GetFreqCtrlCoef() = 0;//��ȡƵ�ʵ�����
	virtual double GetFreqCtrlStep() = 0;//��ȡ��Ƶ���ƹ��ʲ���(kW)
	virtual double GetPLossBaseValue() = 0;//��ȡ�й���׼���(kVar)
	virtual double GetPOutLossRate() = 0;//��ȡ����й����ƫ��
	virtual double GetPInputLossRate() = 0;//��ȡ�����й����ƫ��
	virtual int GetAgcAimAbnormalActFlag() = 0;//��ȡAGCĿ��ֵ�쳣�Ƿ���Ӧ
	virtual int GetAvcOnlyLocalFlag() = 0;//��ȡAVC����Զ��ѹ�壺��λȡֵ��λ��bit��ֵ��0--���أ�1--Զ��
	virtual bool GetAvcLocalFlagUpdate(int& localFlag) = 0;//��ȡAVC���ز���ѹ��Ͷ���־�Ƿ���
	virtual double GetQLossBaseValue() = 0;//��ȡ�޹���׼���(kVar)
	virtual double GetQOutLossRate() = 0;//��ȡ����޹����ƫ��
	virtual double GetQInputLossRate() = 0;//��ȡ�����޹����ƫ��
	virtual int GetAvcAimAbnormalActFlag() = 0;//��ȡAVCĿ��ֵ�쳣�Ƿ���Ӧ

};

#endif
