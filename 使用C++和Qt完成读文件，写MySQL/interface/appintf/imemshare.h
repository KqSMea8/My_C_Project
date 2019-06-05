#ifndef _ICSMEMSHARE__H_
#define _ICSMEMSHARE__H_

#include "objsintf.h"

/*
	icsbusobjects模块实现：
	1，由CLSID_BusTypeTree，可创建总线对象类型树
	2，由类型树描述类型，可创建指定类型对象
	3，由对象可查询对象类型信息及其字段类型信息
	4，传输IICSRtdbObject对象时，可作为总线对象的字段
*/


// 定义接口名称常量
#define IID_IICSMemShareServer	"ICSMemShareServer"
#define IID_IICSMemShareClient	"ICSMemShareClient"

// 定义对象名称常量
#define CLSID_MemShareServer	"memshareserver"
#define CLSID_MemShareClient	"memshareclient"

// 定义对象模块名称
#define MODULE_MemShareServer	"memshareserver"
#define MODULE_MemShareClient	"memshareclient"

// 通用数据结构（若有新参数，扩展在结构体中扩展）
struct TCommonData
{
	int nDataType;		// 数据类型
	int nID;			// ID
	double dValue;		// 值
	double dTime;		// 时标
	char strMessage[MaxStringLen];	// 字符型数据
};

class IMemShareConsumer
{
public:
	virtual void OnMessage(const char* sType, int nID, int nValue, double dTime) = 0;

	// 接收到通用数据
	virtual void OnCommonMessage(const TCommonData& tComData) = 0;
};

/*
	IICSMemShareSever: 共享内存服务端
*/
class IICSMemShareServer : public IICSUnknown
{
public:
	// 间隔状态变化时，接收其关联的向远动转发的虚遥信：nID 遥信ID，nValue 遥信值，time 时间
	virtual bool MemShareDataReceived() = 0;
	
	virtual void RegisterConsumer(IMemShareConsumer* pConsumer) = 0;

	virtual void UnRegisterConsumer(IMemShareConsumer* pConsumer) = 0;

	virtual void SetPipeName(const char* sPipeName) = 0; // 设置管道名称（客户端的管道名必需要与服务端管道名相同）

public:
	static char *GetIntfName()
	{
		return IID_IICSMemShareServer;
	};
};

/*
	IICSMemShareClient: 共享内存客户端
*/
class IICSMemShareClient : public IICSUnknown
{
public:
	// 发送数据的类型
	enum PostType { PT_BayStatus = 0, PT_DataVal, PT_CommonData };

	// 间隔状态变化时，发送其关联的向远动转发的虚遥信：nID 遥信ID，nValue 遥信值，time 时间
	virtual bool BayStateStatusPost(int nID, int nValue, double time) = 0;
	
	// 发送PMU实时数据：sType 类型（analog/status），nID 测点ID，nValue 遥信值，time 时间
	virtual bool PostDataVal(const char* sType, int nID, int nValue, double time) = 0;

	// 设置管道名称（客户端的管道名必需要与服务端管道名相同）
	virtual void SetPipeName(const char* sPipeName) = 0; 

	// 发送通用数据（根据类型区别应用）
	virtual bool PostCommonData(const TCommonData& tComData) = 0;

public:
	static char *GetIntfName()
	{
		return IID_IICSMemShareClient;
	};
};


#endif // _ICSMEMSHARE__H_
