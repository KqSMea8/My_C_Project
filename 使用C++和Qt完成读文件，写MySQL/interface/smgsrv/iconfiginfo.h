// iconfiginfo.h: interface for the IConfigInfo class.
//
//////////////////////////////////////////////////////////////////////

#ifndef _ICONFIGINFO_H__PENGSHIKANG_20131209__INCLUDED_
#define _ICONFIGINFO_H__PENGSHIKANG_20131209__INCLUDED_

class IConfigInfo  
{
public:
	virtual bool ReadConfigInfo() = 0;//�������ļ���ȡ������Ϣ
	
	virtual const double GetOffsetPowerRatio() const = 0;//�õ���������ƫ�������ϵ��
	virtual const double GetMaxFrequency() const = 0;//�õ����ܵ����Ƶ��
	virtual const double GetMinFrequency() const = 0;//�õ����ܵ����Ƶ��
	virtual const double GetAMinute() const = 0;//һ���ӵ�ʱ����

	virtual const bool IsDebug()    const = 0;//�Ƿ��ڲ��Խ׶�
	virtual const bool WriteSmg()   const = 0;//�Ƿ�дSmg������־
	virtual const bool IsTest()     const = 0;//�Ƿ�Ϊ�������״̬
	virtual const bool FreqTest()   const = 0;//�Ƿ������ε�Ƶ
	virtual const bool HasSmooth()  const = 0;//ƽ�������Ƿ�д��־
	virtual const bool HasStatus()  const = 0;//�Ƿ����ң�����ݴ���
	virtual const bool HasAnalog()  const = 0;//�Ƿ����ң�����ݴ���
	virtual const bool HasAccumu()  const = 0;//�Ƿ����ң�����ݴ���
	virtual const bool HasSoe()     const = 0;//�Ƿ����SOE���ݴ���
	virtual const bool HasDumCalc() const = 0;//�Ƿ����������ݼ��㴦��
	virtual const bool HasControl() const = 0;//�Ƿ����ң��ң������
	virtual const bool HasMicgrid() const = 0;//�Ƿ����΢�������ݴ���
	virtual const bool HasFDTask()  const = 0;//�Ƿ�����������ҵ��
	
	virtual const float GetRateF()  const = 0;//�Ƶ��
	virtual const float GetKGene()  const = 0;//�������Ƶ�ʵ���ЧӦϵ��������ֵ��
	virtual const float GetKLoad()  const = 0;//���ɵ�Ƶ�ʵ���ЧӦϵ��������ֵ��
	
	virtual const bool OpenConsoleLog() const = 0;//module console-log open status
	virtual const bool OpenFileLog()    const = 0;//module file-log open status

	virtual const unsigned GetAnalogCycle() const = 0;//ģ������ʱ�����������ڣ����룩
	virtual const unsigned GetStatusCycle() const = 0;//״̬����ʱ�����������ڣ����룩
	virtual const unsigned GetAccumuCycle() const = 0;//�ۼ�����ʱ�����������ڣ����룩
	virtual const unsigned GetExprcalCycle() const = 0;//����������ʱ�����������ڣ����룩
	virtual const char* GetCfgGuardianor()  const = 0;//�໤��1
	virtual const char* GetCfgGuardianor2() const = 0;//�໤��2
	virtual const char* GetProjectName() const = 0;//��Ŀ��

	virtual const bool CompareWithCurrentTime() const = 0;//ǰ�òɼ�����ʱ���Ƿ��ⲻ�ܳ�����ǰʱ�������1Сʱ��
	virtual const bool AutoCtrlWaitResult() const = 0;//�Զ������Ƿ�ȴ��������
	virtual const unsigned GetAutoCtrlCheckTime() const = 0;//�Զ����Լ�����仯�ĵȴ�ʱ�䣨�룩
	virtual const char* GetPowerNetType() const = 0;//������������
};

#endif

