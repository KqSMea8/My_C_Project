#ifndef IMSCCLIENT_H
#define IMSCCLIENT_H

#ifdef WIN32
#pragma pack(push) 
#endif
#pragma pack(1)

typedef struct TMSCMes{
	unsigned short  nType;      //消息类型  （>100：0－100由消息中心使用）
	unsigned short	nLevel;     //消息优先级（1－3：其中1的级别最低）
	long            nLength;    //消息的长度（按字节记）
	unsigned char*  pBuf;       //消息缓存
}TMSCMES,*PTMSCMES;

typedef enum EMesTransType{
    By_MesType = 1,         //按照消息类型发送
	By_PartType,            //按照接收模块类型发送
	By_PartName             //发送至指定的某一模块
}EMESTRANSTYPE,*PEMESTRANSTYPE;

#ifdef WIN32
#pragma pack(pop)
#else 
#pragma pack()
#endif

#define		MSG_LEVEL_LOW		1	//低优先级队列
#define		MSG_LEVEL_NORMAL	2	//正常优先级队列
#define		MSG_LEVEL_HIGH		3	//高优先级

#ifdef WIN32
#ifdef MSCCLIENT_DLL_FILE
class _declspec(dllimport) IMSCClientCallBack  //导出类
#else
class _declspec(dllexport) IMSCClientCallBack  //导入类
#endif
#else
class IMSCClientCallBack
#endif

{
public:
    /*接收到一则消息
	    参数：   
		    pMsg，收到的消息，调用者不关心此缓存的释放
		    nPoster，此消息投递者的句柄
	    返回值：
	        无
    */
    virtual void OnRecv(PTMSCMES pMsg,char* psPoster) = 0;

    /*消息投递超时
	    参数：   
		    pMsg，欲投递的消息，调用者无须考虑该缓存的释放问题
	    返回值：
	        无
    */
    virtual void OnPostTimeout(PTMSCMES pMsg) = 0;  

    /*登录状态变化
	    参数：   
		    lResult，
		          0: 标识登录成功，或与消息中心的连接恢复(登录后)；
		          1: 句柄或模块名称和其它已登录模块重复(登录失败)
			      2: 消息中心的内存不允许新的模块登录(登录失败)
			      3: 登录成功后，与消息中心的连接断开(状态仍为“已登录”)
	    返回值：
	        无
	    说明：
	        只有登录成功，才能接收和投递消息，使用模块在调用完毕LogIn函数后，客户端会自动尝试并维护与消息中心的联系，
		    若联系中断，消息客户端会调用此函数通知使用模块；在登录成功，或联系恢复后消息客户端也会调用此函数进行通
		    知。模块初始化默认状态为“未登录”。
    */
    virtual void OnLogStaChange(long lResult) = 0;    

    /*查询模块完成
	    参数：   
	        lPartnerNum，模块数目
		    pPartners，内存块，{一个unsigned char的名字长度，接下来是该模块的名字（字符串）},
		               一共有lPartnerNum个如此的结构
	    返回值：
    */   
    virtual void OnQueryPartnersFinish(long lPartnerNum,
							   unsigned char* pPartners) = 0;

    /*查询查询某一模块的信息完成
	    参数：   
	        nType，模块的类型
            psPartName，模块的名称或描述
		    nAcquMsgNum，订阅的消息类型数目
		    plMsgTypes，所有订阅的消息类型
		    hModel，该模块所属的链接库标识
	    返回值：
    */   
    virtual void OnQueryPartInfoFinish(unsigned short nType,
							   char* psPartName,
							   long nAcquMsgNum,
							   unsigned short *plMsgTypes,
							   char* psModel) = 0;
};

#ifdef WIN32
#ifdef MSCCLIENT_DLL_FILE
class _declspec(dllexport) IMSCClient
#else 
class _declspec(dllimport) IMSCClient
#endif
#else
class IMSCClient
#endif
{
public:
	
	/*投递一则消息
		参数：   
		pMsg，欲投递的消息，由调用者在IMESMAN_ONSENDFINISH函数中自行释放
		eTType，指定投递要求
		nTransReference，指定投递参数，依据eTType而不同
		    若eTType是By_MesType：该值无效
			若eTType是By_PartType：该值指定接收者的类型
			若eTType是By_PartName：该值是一个（char*），指定接收者名称
		lDeadline,本消息的生命期，在此时限内若没有抵达相应订阅者，将被删除(单位：毫秒)
		CallBackFunc，投递完成的回调函数指针
		返回值：
		   true,本次投递已经被接纳，但不一定真正成功，若失败则ALLBACK_OnPostTimeout被回调
		   false,本次投递无法完成
	*/
	virtual bool Post(PTMSCMES pMsg,
			EMESTRANSTYPE eTType,
			long nTransReference,
			unsigned long lDeadline) = 0;
	
	
	/*向消息中心进行登录
		参数：   
			psPartName，登录者名称（文字描述）
			PartType，登录者类型（模块类型）
			lMesTypeNum，模块所订阅的消息类型数目
			pMesType，模块所订阅的所有消息类型
		返回值：
		    false，本次登录要求被接纳
		    true， 本次登录无法被接纳
		说明：
		    1. 向消息中心登录后，即使与中心的连接中断，在投递者指定的消息生命期内，中心会为本客户
			   保留该消息（当本客户与中心重新建立连接后将收到相关消息）。
			2. 登录是否成功，或者当前与消息中心的连接情况由OnLogStaChange回调函数获知。
	*/
	virtual bool LogIn(char* psPartName,
			unsigned short PartType,
			long lMesTypeNum,
			unsigned short* pMesType) = 0;
	
	/*向消息中心进行注销
		参数：   无
		返回值： 
		     true,  该指令已被客户端程序接收
			 false，由于内存原因，暂时无法处理
		说明：
		     客户端必须在正常退出，或不再需要“消息服务”时向消息中心注销，否则，消息中心会根据
			 相关消息的生命期为该客户保留所有为投递的消息（在连接断开时）。
	*/
	virtual bool LogOut() = 0;
	
	
	/*清理本模块消息队列中尚未发送多的所有消息
		参数：   无
		返回值： 无
	*/   
	virtual void ClearQueue() = 0;
	
	
	/*查询当前系统中所有已在消息中心登录的模块
		参数：   
			nTimeOut,本次操作的时间要求，届时按失败处理
		返回值： 
		    true,  该指令已被客户端程序接收
			false，由于内存原因，暂时无法处理
	*/   
	virtual bool QueryPartners(unsigned long nTimeOut) = 0;
	
	/*查询查询某一模块的信息
		参数：   
			hPartner，某一模块的句柄
			nTimeOut,本次操作的时间要求，届时按失败处理
			CallBackFunc，查询完成的回调函数指针
		返回值： 
		    true,  该指令已被客户端程序接收
			false，由于内存原因，暂时无法处理
	*/   
	virtual bool QueryPartInfo(char* psPartner,
			unsigned long nTimeOut) = 0;	

	/*设置消息服务中心客户端所需要的回调函数
		参数：   
			IMSCClientCallBack* pCallBacks ，回调接口（参见上述）
		返回值： 
		    无
	*/   
    virtual void SetCallBackInterface(IMSCClientCallBack* pCallBacks) = 0;
};


/*

消息处理类
主要用于跨平台传输消息时的字节顺序转换问题.

InitBuffer:
发/送双方调用,初始化时指明待操作缓存地址及长度

SetXXXX(unsigned long lPos, unsigned XXX xV)
发送方调用,将数据从主机字节序转换至网络字节序,并写入缓存相应偏移地址.

GetXXXX(unsigned long lPos, unsigned XXX & xV):
接收方调用,从缓存相应偏移地址取出数据,并从网络字节序转换至主机字节序.

*/ 

#ifdef WIN32
#ifdef MSCCLIENT_DLL_FILE
class _declspec(dllexport) CMSCBuffer
#else 
class _declspec(dllimport) CMSCBuffer
#endif
#else
class CMSCBuffer
#endif
{
public:
	CMSCBuffer();
	~CMSCBuffer();
private:
	unsigned char* m_pBuf;
	unsigned short	m_sLength;
public:
	bool InitBuffer(unsigned char* pBuf, short nLength);
	bool SetShort(unsigned long lPos, unsigned short sV);
	bool SetLong(unsigned long lPos, unsigned long lV);
	bool SetFloat(unsigned long lPos, float fV);
	bool GetShort(unsigned long lPos, unsigned short & sV);
	bool GetLong(unsigned long lPos, unsigned long & lV);
	bool GetFloat(unsigned long lPos, float& fV);
//	bool GetBuffer(unsigned char* pBuf);
};


#ifdef WIN32

/*获取一个消息中心客户端的接口
	参数：   
	    hModel，本链接库的标识，该值应当是全系统（不仅仅是本机）唯一
		    当同一进程多次调用本函数时，应当传入相同的值
		CenterPort，消息中心的服务端口(网络一)
		CenterIP，消息中心的IP地址(网络一)
		CenterPort2，消息中心的服务端口(网络二)
		CenterIP2，消息中心的IP地址(网络二)
	返回值：
	说明：
	    若为单网，请将CenterIP2设为NULL（0）
*/   
#ifdef MSCCLIENT_DLL_FILE
extern "C" _declspec(dllexport) IMSCClient* GetMSCClient(char* psModel,
						unsigned short CenterPort,char* CenterIP,
						unsigned short CenterPort2,char* CenterIP2);
#else
extern "C" _declspec(dllimport) IMSCClient* GetMSCClient(char* psModel,
                        unsigned short CenterPort,char* CenterIP,
						unsigned short CenterPort2,char* CenterIP2);
#endif


/*删除一个不再使用的接口
	参数：   
	    IMSCClient* pClient ， 欲删除的接口
	返回值：
	说明：
*/   
#ifdef MSCCLIENT_DLL_FILE
extern "C" _declspec(dllexport) void RemoveMSCClient(IMSCClient* pInterface);
#else
extern "C" _declspec(dllimport) void RemoveMSCClient(IMSCClient* pInterface);
#endif


/*开启消息服务客户端日志记录功能
     参数：  运行日志的路径和名称
	 返回值：无
	 说明：
	         本函数调试用
*/
#ifdef MSCCLIENT_DLL_FILE
extern "C" _declspec(dllexport) void BeginLog(char* psPath);
#else
extern "C" _declspec(dllimport) void BeginLog(char* psPath);
#endif


/*更新消息中心
     参数： 
	 返回值：0 , 新的信息被接收
	         1 , 参数不符合要求
			 2 , 新的信息和现有相同，可能已经更新过
	 说明：             
*/
#ifdef MSCCLIENT_DLL_FILE
extern "C" _declspec(dllexport) unsigned char  RefreshMSCenter(char* psModel,
					 unsigned short CenterPort,char* CenterIP,
					 unsigned short CenterPort2,char* CenterIP2);
#else
extern "C" _declspec(dllimport) unsigned char  RefreshMSCenter(char* psModel,
					 unsigned short CenterPort,char* CenterIP,
					 unsigned short CenterPort2,char* CenterIP2);
#endif

#else

extern "C"
IMSCClient* GetMSCClient(char* psModel,
						unsigned short CenterPort,char* CenterIP,
						unsigned short CenterPort2,char* CenterIP2);

extern "C"
void RemoveMSCClient(IMSCClient* pInterface);

extern "C"
unsigned char  RefreshMSCenter(char* psModel,
					 unsigned short CenterPort,char* CenterIP,
					 unsigned short CenterPort2,char* CenterIP2);

extern "C"
void BeginLog(char* psPath);
#endif

#endif
