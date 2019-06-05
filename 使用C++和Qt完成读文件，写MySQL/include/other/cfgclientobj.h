// cfgclientobj.h: implement for the CCfgClientObj class.
#ifndef _CFGCLIENTOBJ_2008_02_20_PENGSHIKANG_H_
#define _CFGCLIENTOBJ_2008_02_20_PENGSHIKANG_H_

#include "../commgr/icsdllobj.h"            // for CICSDllObj
#include "../../interface/cfgclient.h"      // for CONFIG_CALLBACK_STATCHANGE

#define MODULE_CFGCLIENT		"cfgclient"

//DLL����Ľӿڶ�������
class CCfgClientObj : public CICSDllObj
{
public:
	CCfgClientObj() : CICSDllObj(MODULE_CFGCLIENT) { }
	
	/** �Ե�ǰ����ģ�飬ע���Լ���cfgctrl���ݿ������õĽ����������������Ȳ�����12��
		���������ȳ���12 ���ظ����øú������򷵻�false�� **/
	bool CfgClientInit(const char* processName)
	{
		typedef bool (*CfgClientInitMethod)(const char*);
		CfgClientInitMethod DoCfgClientInit = (CfgClientInitMethod)GetActionPtr("CfgClientInit");
		if(DoCfgClientInit)
			return DoCfgClientInit(processName);
		return false;
	}
	
	//�Ե�ǰDLLģ��ע���ɫ����ͻ��ˡ�ע���ģ������󳤶���32�����ȳ����ᱻ�ضϡ�
	bool CfgRegisterCallBack(const char* registerName, CONFIG_CALLBACK_STATCHANGE pState)
	{
		if(pState != 0)
		{
			typedef void (*CfgRegisterCallBackMethod)(const char*, CONFIG_CALLBACK_STATCHANGE);
			CfgRegisterCallBackMethod DoCfgRegisterCallBack = (CfgRegisterCallBackMethod)GetActionPtr("CfgRegisterCallBack");
			if(DoCfgRegisterCallBack)
			{
				DoCfgRegisterCallBack(registerName, pState);
				return true;
			}
		}
		return false;
	}

	//�Ե�ǰ����ģ��ע���ɫ����ͻ��ˡ�ע��Ľ�������󳤶���12�����ȳ�����ע��ʧ�ܡ�
	bool RegisterCfgClient(const char* registerName, CONFIG_CALLBACK_STATCHANGE pState)
	{
		if(pState && CfgClientInit(registerName))
			return CfgRegisterCallBack(registerName, pState);
		return false;
	}

	//ģ��registerNameֹͣ���ܽ�ɫ���䡣������DLLģ��ͽ���ģ�顣
	void StopCfgClient(const char* registerName)
	{
		typedef void (*StopCfgClientMethod)(const char*);
		StopCfgClientMethod DoStopCfgClient = (StopCfgClientMethod)GetActionPtr("StopCfgClient");
		if(DoStopCfgClient) DoStopCfgClient(registerName);
	}

	//��ӡ��ǰ����ģ�������ע����Ϣ��
	void DumpInfo()
	{
		typedef void (*DumpInfoMethod)();
		DumpInfoMethod DoDumpInfo = (DumpInfoMethod)GetActionPtr("DumpInfo");
		if(DoDumpInfo) DoDumpInfo();
	}

};
	
#endif 
