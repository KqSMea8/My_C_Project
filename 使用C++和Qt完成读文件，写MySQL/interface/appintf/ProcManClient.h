#ifndef PROCMANCLIENT_H
#define PROCMANCLIENT_H

#define SERVER_PORT           18111

#define SGIP_FIRST           "224.11.11.1"
#define SGIP_SECOND          "224.11.11.2"

#define SERVER_GPORT_FIRST    18201        
#define SERVER_GPORT_SECOND   18202

/*������״̬�����仯
	������   
		int StatMachine ������״̬
             ��1������ , 2������ ��
        int StatNet1  ������һ״̬��0��û�л�Ӧ��1���ָ�Ӧ��
        int StatNet2  �������״̬��0��û�л�Ӧ��1���ָ�Ӧ��
	����ֵ��
	    ��
*/
typedef void (*PROCMAN_CALLBACK_STATCHANGE)
       (int StatMachine,int StatNet1,int StatNet2);

#ifdef WIN32

/*�������̹���ͻ��˹����߳�
	������
	    char* psProcManIP  ,  ���̹���������������IP
        unsigned short nServrPort, ���̹�����Ϊ��ͻ������ṩ�ķ���˿�
        char* psGIP , ���̹�����Ϊ�����������ṩ�����ַ

	����ֵ��
        ��
    ˵����ʹ������ʹ��ǰ������øú����������������߳�
*/   
extern "C" _declspec(dllexport) void StartWorkThread(char* psProcManIP,char* psGIP = SGIP_FIRST,
													 unsigned short nGPort = SERVER_GPORT_FIRST,
													 unsigned short nServrPort = SERVER_PORT);

/*���ý��̹���ͻ�����Ҫ��һ���ص�
	������   
	    PROCMAN_CALLBACK_STATCHANGE pOnStatChange ������ָ�룬ָ���û�ʵ�ֵĺ���
	����ֵ��
        ��
*/   
extern "C" _declspec(dllexport) void SetProcManCallBack(
                     PROCMAN_CALLBACK_STATCHANGE pOnStatChange);

/*�رս��̹���ͻ��˹����߳�
	������   
	    ��
	����ֵ��
        ��
    ˵����ʹ�������˳�ǰӦ�����øú������������Դ
*/   
extern "C" _declspec(dllexport) void StopWorkThread();

#else
void StartWorkThread(char* psProcManIP,char* psGIP = SGIP_FIRST,
					 unsigned short nGPort = SERVER_GPORT_FIRST,
					 unsigned short nServrPort = SERVER_PORT);
void SetProcManCallBack(PROCMAN_CALLBACK_STATCHANGE pOnStatChange);
void StopWorkThread();
#endif

#endif

