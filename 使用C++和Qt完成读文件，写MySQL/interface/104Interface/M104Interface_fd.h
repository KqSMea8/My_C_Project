/*****************************************************************************/
/*许继电气股份有限公司                                     版权：2007-2008   */
/*****************************************************************************/
/* 本源代码及其相关文档为河南许昌许继电气股份有限公司独家所有，未经明文许    */
/* 可不得擅自修改或发布，否则将追究相关的法律责任。                          */
/*                                                                           */
/*                      河南许昌许继股份有限公司                             */
/*                      www.xjgc.com                                         */
/*                      (0374) 321 2924                                      */
/*                                                                           */
/*****************************************************************************/



#ifndef _M104INTERFACE_PENGSHIKANG_20140528_H
#define _M104INTERFACE_PENGSHIKANG_20140528_H

#ifdef  WIN32

	#ifdef  M104_EXPORTS
		//class _declspec(dllexport) CChannel;  
		//class _declspec(dllexport) Client;    
		class _declspec(dllexport) IM104Interface_fd;
		class _declspec(dllexport) IM104CallBackInterface_fd;
		extern "C" 
		{
		/*************************************************
		  函数名称:   GetM104Channel_fd
		  函数描述:   获取通道对象

		  输入参数:   无
		  输出参数:   无
		  返回值:     无

		*************************************************/
			  _declspec(dllexport) IM104Interface_fd* GetM104Channel_fd();
		/*************************************************
		  函数名称:   RelM104Channel_fd
		  函数描述:   释放对象

		  输入参数:   无
		  输出参数:   无
		  返回值:     无

		*************************************************/
			  _declspec(dllexport) void RelM104Channel_fd();

		/*************************************************
		  函数名称:   GetCurrentDTime_fd
		  函数描述:   时间格式化输出
		  输入参数:   char* psTime  时间格式化输出指针
		  输出参数:   无
		  返回值:     无

		*************************************************/
			  _declspec(dllexport) void GetCurrentDTime_fd(char* psTime);
		/*************************************************
		  函数名称:   SetLog_fd
		  函数描述:   设置日志输出策略

		  输入参数:   char* sName  应用程序或者模块名称
  　　　　　　		  char* sLogName 保存日志文件名称
  　　　　　　		  bool bSet true 设置日志输出策略　false 取消日志输出策略 　　　　　　　　　　
		  输出参数:   无
		  返回值:     无

		*************************************************/
			  _declspec(dllexport) void SetLog_fd(char* sName,char* sLogName,bool bSet);
			  _declspec(dllexport)  void Ini_event_loop_fd();
		}
	#else
		//class _declspec(dllimport) CChannel;  
		//class _declspec(dllimport) Client;    
		class _declspec(dllimport) IM104Interface_fd;
		class _declspec(dllimport) IM104CallBackInterface_fd;
		extern "C" 
		{
			  _declspec(dllimport) IM104Interface_fd* GetM104Channel_fd();
			  _declspec(dllimport) void RelM104Channel_fd();
			  _declspec(dllimport) void GetCurrentDTime_fd(char* psTime);
			  _declspec(dllimport) void SetLog_fd(char* sName,char* sLogName,bool bSet);
			  _declspec(dllimport) void Ini_event_loop_fd();
		}
	#endif
#else
	//class CChannel;  
	//class Client;    
	class IM104Interface_fd;
	class IM104CallBackInterface_fd;

	extern "C" 
	{
		  IM104Interface_fd* GetM104Channel_fd();
		  void RelM104Channel_fd();
		  void Ini_event_loop_fd();
		  void GetCurrentDTime_fd(char* psTime);
		  void SetLog_fd(char* sName,char* sLogName,bool bSet);
	}

#endif


class IM104Interface_fd
{
public:
	/***************************************************************************
	函数：InitChannel
	功能：初始化通道信息
	参数：unsigned int nChnlID1,通道一标识
	      char* sIP1，欲联接的M104实例的网络一IP地址，不得为NULL
		  int nPort1，欲联接的M104实例的网络一侦听端口，必须大于零
		  int nChnlID2,nChnlID1,通道二标识
		  char* sIP2，欲联接的M104实例的网络二IP地址，可为NULL
		  int nPort1，欲联接的M104实例的网络二侦听端口	
	返回：bool，true, 初始化成功
	            false,初始化失败
	****************************************************************************/
	virtual bool InitChannel(unsigned int nChnlID1,
		char* sIP1,
		int nPort1,
		int nChnlID2,
		char* sIP2,
		int nPort2
		)  = 0;

	/***************************************************************************
	函数：FiniM104
	功能：清理M104应用服务库
	参数：无
	返回：无
	****************************************************************************/
	virtual void FiniM104()                 = 0;
    virtual bool MsgSend(char * pBuf,short uLen) = 0;

	/***************************************************************************
	函数：SetTimer
	功能：设置定时器
	参数：unsigned long uTimerID 定时器标识
	      unsigned long ulSpan   定时器定时间隔单位毫秒
	返回：bool  true 成功 false 失败
	****************************************************************************/
	virtual bool SetTimer(unsigned long uTimerID,unsigned long ulSpan) = 0;

	/***************************************************************************
	函数：CancelTimer
	功能：取消定时器
	参数：unsigned long uTimerID 定时器标识
	返回：无
	****************************************************************************/
	virtual bool CancelTimer(unsigned long uTimerID) = 0;

public:
	/***************************************************************************
	函数：Advise
	功能：设置M104应用服务的回调接口
	参数：M104CallBackInterface_fd* pCallBackInterface，回调接口
    返回：无
	***************************************************************************/
	virtual void Advise(IM104CallBackInterface_fd* pCallBackInterface)   = 0;

	virtual void SetGrpID(int nGrpID) = 0;
	virtual void Set104T(int nT0,int nT1,int nT2,int nT3) =0;
	virtual void Set104KW (int nK,int nW) = 0;
};


/***************************************************
类名称:  M104CallBackInterface
类描述:  M104应用服务的回调接口
***************************************************/
class IM104CallBackInterface_fd
{
public:
	/***************************************************************************
	函数：MsgReturn
	功能：完成接收数据的回调
	参数：unsigned int nChnlID 通道标识
	      char * pBuf,接收报收的指针
	      short sLen，接收报收的长度
	返回：无
	***************************************************************************/
	virtual void  MsgReturn(unsigned int nChnlID,char * pBuf, short sLen) = 0;


	/***************************************************************************
	函数：ConnectState
	功能：返回通道状态
	参数：unsigned int nChnlID 通道标识
	      bool bConnect        通道状态 0 断，1 主 ,2 备
	返回：无
	***************************************************************************/
	virtual void ConnectState(unsigned int nChnlID,unsigned char uState) = 0 ;

	/***************************************************************************
	函数：OnTimerReturn
	功能：定时器返回
	参数：unsigned long uTimerID 定时器标识
	返回：无
	***************************************************************************/
	virtual void OnTimerReturn(unsigned long uTimerID) = 0;
};


#endif
