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



#ifndef _S104INTERFACE_H
#define _S104INTERFACE_H

#ifdef  WIN32

#ifdef  S104APCI_EXPORTS

class _declspec(dllexport) IS104Interface;
class _declspec(dllexport) IS104CallBackInterface;
extern "C" 
{
/*************************************************
  函数名称:   GetS104
  函数描述:   获取通道对象

  输入参数:   无
  输出参数:   无
  返回值:     无

*************************************************/
      _declspec(dllexport) IS104Interface * GetS104();

/*************************************************
  函数名称:   GetCurrentDTime
  函数描述:   时间格式化输出
  输入参数:   char* psTime  时间格式化输出指针
  输出参数:   无
  返回值:     无

*************************************************/
	  _declspec(dllexport) void GetCurrentDTime(char* psTime);
/*************************************************
  函数名称:   SetLog
  函数描述:   设置日志输出策略

  输入参数:   char* sName  应用程序或者模块名称
  　　　　　　char* sLogName 保存日志文件名称
  　　　　　　bool bSet true 设置日志输出策略　false 取消日志输出策略 　　　　　　　　　　
  输出参数:   无
  返回值:     无

*************************************************/
	  _declspec(dllexport) void SetLog(char* sName,char* sLogName,bool bSet);
}
#else
class _declspec(dllimport) IS104Interface;
class _declspec(dllimport) IS104CallBackInterface;
extern "C" 
{
	  _declspec(dllimport) IS104Interface * GetS104();
	  _declspec(dllimport) void GetCurrentDTime(char* psTime);
	  _declspec(dllimport) void SetLog(char* sName,char* sLogName,bool bSet);
}
#endif
#else

class IS104Interface;
class IS104CallBackInterface;

extern "C" 
{
      IS104Interface * GetS104();
	  void GetCurrentDTime(char* psTime);
	  void SetLog(char* sName,char* sLogName,bool bSet);
}
#endif


class IS104Interface
{
public:
	/***************************************************************************
	函数：InitChannel
	功能：初始化通道信息
	参数：char* sIP1，欲联接的S104实例的网络一IP地址，不得为NULL
		  int nPort1，欲联接的S104实例的网络一侦听端口，必须大于零
		  char* sIP2，欲联接的S104实例的网络二IP地址，可为NULL
		  int nPort1，欲联接的S104实例的网络二侦听端口	
	返回：bool，true, 初始化成功
	            false,初始化失败
	****************************************************************************/
	virtual bool InitChannel(char* sIP1,
		int nPort1,
		char* sIP2,
		int nPort2
		)  = 0;

	/***************************************************************************
	函数：AddChannelGrp
	功能：增加欲连接的通道组信息
	参数：int nChnlGrp, 欲连接的通道组ID
	      char* sIP1,   欲联接的M104实例的网络通道一IP地址，不得为NULL
		  int nChnlID1，欲联接的M104实例的网络通道一ID，必须大于零
		  char* sIP2，  欲联接的M104实例的网络通道二IP地址，可为NULL
		  int nChnlID2，欲联接的M104实例的网络通道二ID，可为零	
	返回：bool，true, 初始化成功
	            false,初始化失败
	****************************************************************************/
	virtual bool AddChannelGrp(int nChnlGrp,
		char* sIP1,
		int nChnlID1,
		char* sIP2 = 0,
		int nChnlID2 = 0
		)  = 0;

	/***************************************************************************
	函数：FiniM104
	功能：清理M104应用服务库
	参数：无
	返回：无
	****************************************************************************/
	virtual void FiniS104()                 = 0;
    virtual bool MsgSend(int nChnlID, char * pBuf,short uLen ) = 0;
	virtual bool MsgSend(char * pBuf,short uLen, char * szIPandPort) = 0;
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
	参数：M104CallBackInterface* pCallBackInterface，回调接口
	      bool bConfig 是否需要配置连接客户端IP，如果为false,则不需要调用
		  AddChannelGrp函数
    返回：无
	***************************************************************************/
	virtual void Advise(IS104CallBackInterface* pCallBackInterface,bool bConfig = false)   = 0;
};


/***************************************************
类名称:  M104CallBackInterface
类描述:  M104应用服务的回调接口
***************************************************/
class IS104CallBackInterface
{
public:
	/***************************************************************************
	函数：MsgReturn
	功能：完成接收数据的回调
	参数：int nChnlID  通道标识
	      char * pBuf,接收报收的指针
	      short sLen，接收报收的长度
	返回：无
	***************************************************************************/
	virtual void  MsgReturn(int nChnlID ,char * pBuf, short sLen) = 0;
 	/***************************************************************************
	函数：MsgReturn
	功能：完成接收数据的回调
	参数：int nChnlID  通道标识
	      char * pBuf,接收报收的指针
	      char * szIPandPort 客户端IP+端口
	返回：无
	***************************************************************************/
   virtual void  MsgReturn(char * pBuf, short sLen,char * szIPandPort) = 0;

	/***************************************************************************
	函数：ConnectState
	功能：返回通道状态
	参数：unsigned int nChnlID 通道标识
	      bool bConnect        通道状态 0 断，1 主 ,2 备
	返回：无
	***************************************************************************/
	virtual void ConnectState(unsigned int nChnlID,unsigned char uState) = 0 ;
	/***************************************************************************
	函数：ConnectState
	功能：返回通道状态
	参数：char * szIPandPort 客户端IP+端口
	      bool bConnect        通道状态 0 断，1 主 ,2 备
	返回：无
	***************************************************************************/
	virtual void ConnectState(char * szIPandPort,unsigned char uState) = 0;
	/***************************************************************************
	函数：OnTimerReturn
	功能：定时器返回
	参数：unsigned long uTimerID 定时器标识
	返回：无
	***************************************************************************/
	virtual void OnTimerReturn(unsigned long uTimerID) = 0;
	/***************************************************************************
	函数：OnRawMsg
	功能：原始报文回调
	参数：unsigned char * pBuf 报文起始地址
	      short nLen           报文长度
		  char uDirect         报文方向 1 接收到的报文，0 发送的报文
		  unsigned char * szIP 通讯远方的IP

	返回：无
	***************************************************************************/
	virtual void OnRawMsg(unsigned char * pBuf,short nLen,char uDirect,unsigned char * szIP) = 0;

	/***************************************************************************
	函数：OnRawMsg
	功能：原始报文回调
	参数：unsigned char * pBuf 报文起始地址
	      short nLen           报文长度
		  char uDirect         报文方向 1 接收到的报文，0 发送的报文
		  unsigned short  sIedAddr 装置地址

	返回：无
	***************************************************************************/
	virtual void OnRawMsg(unsigned short  sIedAddr,unsigned char * pBuf,short nLen,char uDirect) = 0;
	
	virtual void  MsgShow(char * pBuf, short sLen,char * szIPandPort, int iDirect) = 0;
};


#endif
