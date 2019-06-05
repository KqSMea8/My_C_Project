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

//回调函数ONLINEUPDATE_FINISHED_CB的参数值 
#define ONLINEUPDATE_S_SUCCEED	0 //成功
#define ONLINEUPDATE_F_FAILED	-1 //失败
#define ONLINEUPDATE_F_NETERR	-2 //没有返回
#define ONLINEUPDATE_F_NOFAMILY  -3 //没有family

//BegineUpdate的返回值
#define ONLINEUPDATE_F_CLIENTNOTREADY	-3 //客户端没有准备好
#define ONLINEUPDATE_F_SERVERNOTREADY	-4 //服务端没有准备好
#define ONLINEUPDATE_S_SUCCEED	0 //成功
#define ONLINEUPDATE_F_NETERR	-2 //没有返回


//回调函数ONLINEUPDATE_UPDATENOTIFY_CB的参数值
#define BEFORE_UPDATE_NOTIFY	20  //准备更新实时库
#define AFTER_UPDATE_NOTIFY		21  //实时库更新完毕

typedef void (*ONLINEUPDATE_FINISHED_CB)(int status); //在线更新流程结束后的通知回调
typedef void (*ONLINEUPDATE_UPDATENOTIFY_CB)(int type, const char* insertTableNames, const char* editTableNames); //更新实时库之前、之后的通知回调

class OnlineUpdateClient
{
public:
	virtual int BeginUpdate(const char* familyName, bool bDeleteHisdb) = 0; //开始在线更新流程
	virtual bool RegFinishCb(ONLINEUPDATE_FINISHED_CB cb) = 0; //注册在线更新流程结束的通知回调函数
	virtual bool RegUpdateNotifyCb(ONLINEUPDATE_UPDATENOTIFY_CB cb) = 0; //注册实时库变更前后的通知回调函数
	virtual bool SendPauseReadyAck(const char* procName) = 0; //发送实时库变更前准备好回应
	virtual bool SendRefreshFinishAck(const char* procName) = 0; //发送实时库变更后准备好回应
	virtual void ReleaseThis() = 0;
	virtual bool SwitchRole() = 0;
};

extern "C"
{
	ONLINEUPDATE_API OnlineUpdateClient* GetOnlineUpdateInterface();
}



#endif
