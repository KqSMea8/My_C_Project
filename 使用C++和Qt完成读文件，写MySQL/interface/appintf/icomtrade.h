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

// 开关量变位结构
typedef struct tagStatus 
{
	int position;		// 变位位置
	bool change;		// 状态，True-↑, False-↓
} STATUS;

// 时段采样结构
typedef struct tagSample
{
	int count;
	int begin;
	int end;
	bool idle;			// 无效标志
	double frequency;
} SAMPLE;


/* IComtradeFactory Comtrade工厂 */
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

	// 创建空白数据对象
	virtual bool CreateComtrade(IComtradeObject** ppComtrade, File_Type fileType = comtradeFile) = 0;
	// 将数据对象保存为指定文件
	virtual bool Serialize(IComtradeObject* pComtrade, const QString& file) = 0;
};



/* IComtradeChan 数据通道类 */
class IComtradeChan : virtual public IICSUnknown
{
public:
	// 获得模拟量数据
	virtual double* GetAnaData(int minPos, int maxPos, int& count) = 0;
	// 获得开关量数据
	virtual STATUS* GetDigData(int& initData, int& count) = 0;
	// 获得通道名称
	virtual QString ChannelName() = 0;
	// 获得通道索引（唯一）
	virtual int ChannelNo() = 0;
	// 获得通道相别
	virtual int ChannelPhase() = 0;
	// 获得通道变位次数
	virtual int SwitchNum() = 0;
	// 获得所有变位信息
	virtual int GetAllSwitch(STATUS* pSta) = 0;
	// 获得通道某点的值
	virtual double Value(int idx) = 0;
	// 获得通道最大值(绝对值)
	virtual double GetMaxValue() = 0;
	// 获得通道颜色
	virtual QColor GetColor() = 0;
	// 获得通道谐波次数
	virtual int HarmValue() = 0;
	// 格式化数据(仅针对状态量)
	virtual void Filtrate() = 0;

	// 设置通道名称
	virtual void SetChannelName(const QString& name) = 0;
	// 设置通道相别(仅针对模拟量)
	virtual void SetChannelPhase(int phase) = 0;
	// 设置模拟量通道数值
	virtual void SetChannelData(int dataNum, double* pData) = 0;
	// 设置开关量通道数值
	virtual void SetAllSwitch(int switchNum, STATUS* pSta) = 0;
};


/* IComtradeObject Comtrade数据类 */
class IComtradeObject : virtual public IICSUnknown
{
public:
	enum { DefSysFrequency = 50 };
	enum { AnaChannel = 0, DigChannel, BothChannel };
	// 故障文件名称
	virtual QString FaultFile() = 0;
	// 文件类型
	virtual QString FileType() = 0;
	// 通道总数
	virtual int Count(int tChan = BothChannel) = 0;
	// 获得指定类型、索引的通道
	virtual bool GetChannel(int index, int tChan, IComtradeChan** ppChan) = 0;
	
	// 通道类型（模拟量）
	virtual uint ChannelType(int n) = 0;
	// 通道谐波次数（模拟量）
	virtual uint ChannelHarmValue(int n) = 0;
	// 通道相位（模拟量）
	virtual uint ChannelPhase(int n) = 0;
	virtual QString StartTime() = 0;
	virtual QString TriggerTime() = 0;
	virtual int SysFrequency() = 0;

	// 时标是否正确
	virtual bool PosIsCorrect(double timeData) = 0;
	virtual	int Pos(double timeData) = 0;
	virtual int DataCount() = 0;
	// pos位置处的周波点数
	virtual int CycleCount(int pos) = 0;
	
	// 获得一个周波数据，与时段相关
	virtual double* GetCycleData(int n, int pos) = 0;
	virtual double* GetAnaData(int n, int pos, int count) = 0;
	virtual STATUS* GetDigData(int& initData, int& count, int n) = 0;
	// 获得通道从pos位置开始的数据指针
	virtual double* GetData(int n, int pos) = 0;

	virtual int SampleCount() = 0;
	virtual int GetSamples(int ns, int ne, SAMPLE* sam) = 0;
	// 获得完整的采样信息
	virtual void GetFullSample(SAMPLE* sam) = 0;
	// 获得Pos位置的时标
	virtual double GetSampleTime(int pos) = 0;
	// 获得最大采样周波数
	virtual int MaxCycleCount() = 0;
	// 获得最大变位数
	virtual int MaxSwitchNum() = 0;
	// 获得信息字符串
	virtual QString GetInfoStr(int n) = 0;
	// 获得故障时刻位置
	virtual int GetFaultPos() = 0;
	// 获得指定位置的采样时标数据指针
	virtual double* GetPSample(int pos) = 0;


	// 创建指定类型通道
	virtual bool CreateChannel(int chanType, IComtradeChan** ppChan) = 0;
	// 设置录波起始时刻
	virtual void SetStartTime(double time) = 0;
	// 设置录波触发时刻
	virtual void SetTriggerTime(double time) = 0;
	// 设置系统频率，默认为50Hz
	virtual void SetSysFrequency(int freq = DefSysFrequency) = 0;
	// 设置采样频率信息
	virtual void SetSamples(int samNum, SAMPLE* sam) = 0;

	virtual void SetDataCount(int nNum) = 0;

};

#endif