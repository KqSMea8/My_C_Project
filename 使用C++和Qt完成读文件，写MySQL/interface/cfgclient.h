#ifndef CFGMAN_CLIENT_H
#define CFGMAN_CLIENT_H

#ifdef _MSC_VER
	#ifdef CFGCLIENT_EXPORT
		#define CFGCLIENT_API __declspec(dllexport)
	#else
		#define CFGCLIENT_API __declspec(dllimport)
	#endif
#else
	#define CFGCLIENT_API
#endif

#define REGISTER_NAME_LENGTH 32

typedef enum
{
    CFGSRV_ROLE_UNKNOWN = 1, //δ֪�Ľ�ɫ
    CFGSRV_ROLE_ENABLED,     //���ý�ɫ
    CFGSRV_ROLE_STANDBY,     //���ý�ɫ
    CFGSRV_ROLE_DISABLED     //�����ý�ɫ
} CFGSRV_ROLE;
/*
 *	1 UNKNOWN,2 ENABLED,3 STANDBY,4 DISABLED
 */

typedef void (*CONFIG_CALLBACK_STATCHANGE) (int role);

extern "C"
{
	//���̵��õĽӿڣ�ע���Լ���cfgctrl���ݿ������õĽ�����
	//���Ȳ�����12,���ȳ���12�� �ظ���ʼ������false
	CFGCLIENT_API bool CfgClientInit(const char* process_name);

	//��ģ������ע���ɫ����ͻ���,ģ������󳤶���32�������ᱻ�ض�
	CFGCLIENT_API void CfgRegisterCallBack(const char* registerName,CONFIG_CALLBACK_STATCHANGE pState);
	//ģ��registerNameֹͣ���ܽ�ɫ����
	CFGCLIENT_API void StopCfgClient(const char* registerName);
	//��ӡ��ǰ���̵�����ע����Ϣ����ѡʹ��
	CFGCLIENT_API void DumpInfo();
}

#endif
