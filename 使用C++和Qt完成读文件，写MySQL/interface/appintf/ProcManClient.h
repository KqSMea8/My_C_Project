#ifndef PROCMANCLIENT_H
#define PROCMANCLIENT_H

#define SERVER_PORT           18111

#define SGIP_FIRST           "224.11.11.1"
#define SGIP_SECOND          "224.11.11.2"

#define SERVER_GPORT_FIRST    18201        
#define SERVER_GPORT_SECOND   18202

/*当主备状态发生变化
	参数：   
		int StatMachine ，主备状态
             （1：主机 , 2：备机 ）
        int StatNet1  ，网络一状态（0：没有回应；1：恢复应答）
        int StatNet2  ，网络二状态（0：没有回应；1：恢复应答）
	返回值：
	    无
*/
typedef void (*PROCMAN_CALLBACK_STATCHANGE)
       (int StatMachine,int StatNet1,int StatNet2);

#ifdef WIN32

/*启动进程管理客户端工作线程
	参数：
	    char* psProcManIP  ,  进程管理器所在主机的IP
        unsigned short nServrPort, 进程管理器为其客户端所提供的服务端口
        char* psGIP , 进程管理器为主动触发而提供的组地址

	返回值：
        无
    说明：使用者在使用前必须调用该函数，以启动工作线程
*/   
extern "C" _declspec(dllexport) void StartWorkThread(char* psProcManIP,char* psGIP = SGIP_FIRST,
													 unsigned short nGPort = SERVER_GPORT_FIRST,
													 unsigned short nServrPort = SERVER_PORT);

/*设置进程管理客户端需要的一个回调
	参数：   
	    PROCMAN_CALLBACK_STATCHANGE pOnStatChange ，函数指针，指向用户实现的函数
	返回值：
        无
*/   
extern "C" _declspec(dllexport) void SetProcManCallBack(
                     PROCMAN_CALLBACK_STATCHANGE pOnStatChange);

/*关闭进程管理客户端工作线程
	参数：   
	    无
	返回值：
        无
    说明：使用者在退出前应当调用该函数清理相关资源
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

