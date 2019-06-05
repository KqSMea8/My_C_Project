#ifndef _ICSMEMSHARE__H_
#define _ICSMEMSHARE__H_

#include "objsintf.h"

/*
	icsbusobjectsģ��ʵ�֣�
	1����CLSID_BusTypeTree���ɴ������߶���������
	2�����������������ͣ��ɴ���ָ�����Ͷ���
	3���ɶ���ɲ�ѯ����������Ϣ�����ֶ�������Ϣ
	4������IICSRtdbObject����ʱ������Ϊ���߶�����ֶ�
*/


// ����ӿ����Ƴ���
#define IID_IICSMemShareServer	"ICSMemShareServer"
#define IID_IICSMemShareClient	"ICSMemShareClient"

// ����������Ƴ���
#define CLSID_MemShareServer	"memshareserver"
#define CLSID_MemShareClient	"memshareclient"

// �������ģ������
#define MODULE_MemShareServer	"memshareserver"
#define MODULE_MemShareClient	"memshareclient"

// ͨ�����ݽṹ�������²�������չ�ڽṹ������չ��
struct TCommonData
{
	int nDataType;		// ��������
	int nID;			// ID
	double dValue;		// ֵ
	double dTime;		// ʱ��
	char strMessage[MaxStringLen];	// �ַ�������
};

class IMemShareConsumer
{
public:
	virtual void OnMessage(const char* sType, int nID, int nValue, double dTime) = 0;

	// ���յ�ͨ������
	virtual void OnCommonMessage(const TCommonData& tComData) = 0;
};

/*
	IICSMemShareSever: �����ڴ�����
*/
class IICSMemShareServer : public IICSUnknown
{
public:
	// ���״̬�仯ʱ���������������Զ��ת������ң�ţ�nID ң��ID��nValue ң��ֵ��time ʱ��
	virtual bool MemShareDataReceived() = 0;
	
	virtual void RegisterConsumer(IMemShareConsumer* pConsumer) = 0;

	virtual void UnRegisterConsumer(IMemShareConsumer* pConsumer) = 0;

	virtual void SetPipeName(const char* sPipeName) = 0; // ���ùܵ����ƣ��ͻ��˵Ĺܵ�������Ҫ�����˹ܵ�����ͬ��

public:
	static char *GetIntfName()
	{
		return IID_IICSMemShareServer;
	};
};

/*
	IICSMemShareClient: �����ڴ�ͻ���
*/
class IICSMemShareClient : public IICSUnknown
{
public:
	// �������ݵ�����
	enum PostType { PT_BayStatus = 0, PT_DataVal, PT_CommonData };

	// ���״̬�仯ʱ���������������Զ��ת������ң�ţ�nID ң��ID��nValue ң��ֵ��time ʱ��
	virtual bool BayStateStatusPost(int nID, int nValue, double time) = 0;
	
	// ����PMUʵʱ���ݣ�sType ���ͣ�analog/status����nID ���ID��nValue ң��ֵ��time ʱ��
	virtual bool PostDataVal(const char* sType, int nID, int nValue, double time) = 0;

	// ���ùܵ����ƣ��ͻ��˵Ĺܵ�������Ҫ�����˹ܵ�����ͬ��
	virtual void SetPipeName(const char* sPipeName) = 0; 

	// ����ͨ�����ݣ�������������Ӧ�ã�
	virtual bool PostCommonData(const TCommonData& tComData) = 0;

public:
	static char *GetIntfName()
	{
		return IID_IICSMemShareClient;
	};
};


#endif // _ICSMEMSHARE__H_
