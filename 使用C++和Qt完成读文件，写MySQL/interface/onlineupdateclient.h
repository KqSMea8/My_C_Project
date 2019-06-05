#if !defined(ONLINE_UPDATE_H)
#define ONLINE_UPDATE_H

//#include "ace/config-all.h"

#ifdef _MSC_VER
	#ifdef ONLINEUPDATE_EXPORT
		#define ONLINEUPDATE_API __declspec(dllexport)
	#else
		#define ONLINEUPDATE_API __declspec(dllimport)
	#endif
#else
	#define ONLINEUPDATE_API
#endif

//�ص�����ONLINEUPDATE_FINISHED_CB�Ĳ���ֵ 
#define ONLINEUPDATE_S_SUCCEED	0 //�ɹ�
#define ONLINEUPDATE_F_FAILED	-1 //ʧ��
#define ONLINEUPDATE_F_NETERR	-2 //û�з���
#define ONLINEUPDATE_F_NOFAMILY  -3 //û��family

//BegineUpdate�ķ���ֵ
#define ONLINEUPDATE_F_CLIENTNOTREADY	-3 //�ͻ���û��׼����
#define ONLINEUPDATE_F_SERVERNOTREADY	-4 //�����û��׼����
#define ONLINEUPDATE_S_SUCCEED	0 //�ɹ�
#define ONLINEUPDATE_F_NETERR	-2 //û�з���


//�ص�����ONLINEUPDATE_UPDATENOTIFY_CB�Ĳ���ֵ
#define BEFORE_UPDATE_NOTIFY	20  //׼������ʵʱ��
#define AFTER_UPDATE_NOTIFY		21  //ʵʱ��������

typedef void (*ONLINEUPDATE_FINISHED_CB)(int status); //���߸������̽������֪ͨ�ص�
typedef void (*ONLINEUPDATE_UPDATENOTIFY_CB)(int type, const char* insertTableNames, const char* editTableNames); //����ʵʱ��֮ǰ��֮���֪ͨ�ص�

class OnlineUpdateClient
{
public:
	virtual int BeginUpdate(const char* familyName, bool bDeleteHisdb) = 0; //��ʼ���߸�������
	virtual bool RegFinishCb(ONLINEUPDATE_FINISHED_CB cb) = 0; //ע�����߸������̽�����֪ͨ�ص�����
	virtual bool RegUpdateNotifyCb(ONLINEUPDATE_UPDATENOTIFY_CB cb) = 0; //ע��ʵʱ����ǰ���֪ͨ�ص�����
	virtual bool SendPauseReadyAck(const char* procName) = 0; //����ʵʱ����ǰ׼���û�Ӧ
	virtual bool SendRefreshFinishAck(const char* procName) = 0; //����ʵʱ������׼���û�Ӧ
	virtual void ReleaseThis() = 0;
	virtual bool SwitchRole() = 0;
};

extern "C"
{
	ONLINEUPDATE_API OnlineUpdateClient* GetOnlineUpdateInterface();
}



#endif
