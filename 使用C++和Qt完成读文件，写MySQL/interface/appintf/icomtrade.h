#ifndef _ICOMTRADE_H__
#define _ICOMTRADE_H__

#include <qcolor.h>
#include <qstring.h>
#include "icsunknown.h"

#define IID_IComtradeObject			"icomtradeobject"
#define IID_IComtradeChan			"icomtradechan"
#define IID_IComtradeFactory		"icomtradefactory"
#define CLSID_ComtradeFactory		"comtradefactory"
#define MODULE_COMTRADEOBJECT		"comtradeobject"


const QString CHANNELCLASS[] = {"QChannel", "QAnalog", "QDigtal"};


typedef	enum ListNotify { lnAdded, lnDeleted, lnExtracted };

// ��������λ�ṹ
typedef struct tagStatus 
{
	int position;		// ��λλ��
	bool change;		// ״̬��True-��, False-��
} STATUS;

// ʱ�β����ṹ
typedef struct tagSample
{
	int count;
	int begin;
	int end;
	bool idle;			// ��Ч��־
	double frequency;
} SAMPLE;


/* IComtradeFactory Comtrade���� */
class IComtradeObject;
class IComtradeFactory : virtual public IICSUnknown
{
public:
	enum File_Type { comtradeFile = 0, pmuFile, dynDataFile, protLocgicFile, hisFaultData };
	virtual bool CreateComtrade(const QString& file, IComtradeObject** ppComtrade
		, File_Type fileType = comtradeFile) = 0;
	virtual bool GetFaultReport(void** ppReport) = 0;
	virtual int GetErrorCode() = 0;
	virtual QString GetErrorDesc(int errCode) = 0;

	// �����հ����ݶ���
	virtual bool CreateComtrade(IComtradeObject** ppComtrade, File_Type fileType = comtradeFile) = 0;
	// �����ݶ��󱣴�Ϊָ���ļ�
	virtual bool Serialize(IComtradeObject* pComtrade, const QString& file) = 0;
};



/* IComtradeChan ����ͨ���� */
class IComtradeChan : virtual public IICSUnknown
{
public:
	// ���ģ��������
	virtual double* GetAnaData(int minPos, int maxPos, int& count) = 0;
	// ��ÿ���������
	virtual STATUS* GetDigData(int& initData, int& count) = 0;
	// ���ͨ������
	virtual QString ChannelName() = 0;
	// ���ͨ��������Ψһ��
	virtual int ChannelNo() = 0;
	// ���ͨ�����
	virtual int ChannelPhase() = 0;
	// ���ͨ����λ����
	virtual int SwitchNum() = 0;
	// ������б�λ��Ϣ
	virtual int GetAllSwitch(STATUS* pSta) = 0;
	// ���ͨ��ĳ���ֵ
	virtual double Value(int idx) = 0;
	// ���ͨ�����ֵ(����ֵ)
	virtual double GetMaxValue() = 0;
	// ���ͨ����ɫ
	virtual QColor GetColor() = 0;
	// ���ͨ��г������
	virtual int HarmValue() = 0;
	// ��ʽ������(�����״̬��)
	virtual void Filtrate() = 0;

	// ����ͨ������
	virtual void SetChannelName(const QString& name) = 0;
	// ����ͨ�����(�����ģ����)
	virtual void SetChannelPhase(int phase) = 0;
	// ����ģ����ͨ����ֵ
	virtual void SetChannelData(int dataNum, double* pData) = 0;
	// ���ÿ�����ͨ����ֵ
	virtual void SetAllSwitch(int switchNum, STATUS* pSta) = 0;
};


/* IComtradeObject Comtrade������ */
class IComtradeObject : virtual public IICSUnknown
{
public:
	enum { DefSysFrequency = 50 };
	enum { AnaChannel = 0, DigChannel, BothChannel };
	// �����ļ�����
	virtual QString FaultFile() = 0;
	// �ļ�����
	virtual QString FileType() = 0;
	// ͨ������
	virtual int Count(int tChan = BothChannel) = 0;
	// ���ָ�����͡�������ͨ��
	virtual bool GetChannel(int index, int tChan, IComtradeChan** ppChan) = 0;
	
	// ͨ�����ͣ�ģ������
	virtual uint ChannelType(int n) = 0;
	// ͨ��г��������ģ������
	virtual uint ChannelHarmValue(int n) = 0;
	// ͨ����λ��ģ������
	virtual uint ChannelPhase(int n) = 0;
	virtual QString StartTime() = 0;
	virtual QString TriggerTime() = 0;
	virtual int SysFrequency() = 0;

	// ʱ���Ƿ���ȷ
	virtual bool PosIsCorrect(double timeData) = 0;
	virtual	int Pos(double timeData) = 0;
	virtual int DataCount() = 0;
	// posλ�ô����ܲ�����
	virtual int CycleCount(int pos) = 0;
	
	// ���һ���ܲ����ݣ���ʱ�����
	virtual double* GetCycleData(int n, int pos) = 0;
	virtual double* GetAnaData(int n, int pos, int count) = 0;
	virtual STATUS* GetDigData(int& initData, int& count, int n) = 0;
	// ���ͨ����posλ�ÿ�ʼ������ָ��
	virtual double* GetData(int n, int pos) = 0;

	virtual int SampleCount() = 0;
	virtual int GetSamples(int ns, int ne, SAMPLE* sam) = 0;
	// ��������Ĳ�����Ϣ
	virtual void GetFullSample(SAMPLE* sam) = 0;
	// ���Posλ�õ�ʱ��
	virtual double GetSampleTime(int pos) = 0;
	// ����������ܲ���
	virtual int MaxCycleCount() = 0;
	// �������λ��
	virtual int MaxSwitchNum() = 0;
	// �����Ϣ�ַ���
	virtual QString GetInfoStr(int n) = 0;
	// ��ù���ʱ��λ��
	virtual int GetFaultPos() = 0;
	// ���ָ��λ�õĲ���ʱ������ָ��
	virtual double* GetPSample(int pos) = 0;


	// ����ָ������ͨ��
	virtual bool CreateChannel(int chanType, IComtradeChan** ppChan) = 0;
	// ����¼����ʼʱ��
	virtual void SetStartTime(double time) = 0;
	// ����¼������ʱ��
	virtual void SetTriggerTime(double time) = 0;
	// ����ϵͳƵ�ʣ�Ĭ��Ϊ50Hz
	virtual void SetSysFrequency(int freq = DefSysFrequency) = 0;
	// ���ò���Ƶ����Ϣ
	virtual void SetSamples(int samNum, SAMPLE* sam) = 0;

	virtual void SetDataCount(int nNum) = 0;

};

#endif