#ifndef __IDATAEXCHANGED_H__
#define __IDATAEXCHANGED_H__
#include "icsunknown.h"
#include "../xcompatinc/xcompatdef.h"

#ifndef _UINT_DEFINED
#define _UINT_DEFINED
	typedef unsigned int UINT;
#endif

#ifndef _CHAR_DEFINED
#define _CHAR_DEFINED
	typedef char CHAR;
#endif

#ifndef _FLOAT_DEFINED
#define _FLOAT_DEFINED
	typedef float FLOAT;
#endif

#ifndef _UINT64_DEFINED
	#define _UINT64_DEFINED
	#ifdef _WIN32
		typedef unsigned __int64 UINT64;
	#else
		typedef unsigned long long UINT64;
	#endif
#endif 

#ifndef VOID
	#define VOID void
#endif 

#ifndef _WINDEF_
	#ifndef _BOOL_DEFINED
	#define _BOOL_DEFINED
	typedef long BOOL;

#ifndef TRUE
#define TRUE  1
#endif

#ifndef FALSE
#define FALSE  0
#endif
#endif 
#endif


#ifndef _DATAEXCHANGEITEM_DEFINED
#define _DATAEXCHANGEITEM_DEFINED
	typedef struct DataExchangeItem
	{
		UINT    _cb;				//! 数据项大小, 用于扩展.
		UINT	_uTransID;			//! 转发表内ID.
		UINT	_uScadaType;		//! SCADA模型中的类型, 1=>模拟量, 2=>信号量等, 参见SCADA模型定义.
		UINT	_uScadaID;			//! SCADA模型中的数据ID, 通过类型和ID获取SCADA数据服务。
		union
		{
			UINT	_uCurValue;		 //! 模拟量、信号量的可视化当前值, 对控制量来说是其目标值.
			FLOAT	_fCurValue;		 //! 模拟量、信号量的可视化当前值, 对控制量来说是其目标值.
			UINT8	_uByte4[4];
		};
		UINT64	_u64CTime;			//! 最后修改时间.
		UINT	_uQuality;			//! 转发模型中的质量.
		UINT	_uTransRTU;			//! 转发的通讯地址
		UINT	_uTransPoint;		//! 转发的消息（数据）点号
		UINT	_uTransMsgType;		//! 转发的消息类型
		FLOAT	_fKValue;			//!
		FLOAT	_fBValue;			//!
	}DATAEXCHANGEITEM, *LPDATAEXCHANGEITEM;
	typedef const DataExchangeItem* LPCDATAEXCHANGEITEM;
#endif

#ifndef F2IFORROUND
	#define F2IFORROUND(f) (((f) > 0.0f) ? ((f) + 0.5f) : ((f) - 0.5f))
#endif

class IDataExchangeCallback;


class IDataExchange : public IICSUnknown
{
public:
	enum DataExchangeResult
	{
		Failed  = -1,
		Success = 0,
		IsRuning,		//! 
		HasNotStarted,  //! 
	};

	enum ReqResult
	{
		ReqFailed  = -1,
		ReqSuccess = 0,
	};

	enum DESCADAType
	{
		ST_Analog      = 0x0001,
		ST_Status      = 0x0002,
		ST_Pulse	   = 0x0003,
		ST_Control	   = 0x0004,
		ST_Soe		   = 0x0005,
		ST_Setting	   = 0x0006,
		ST_ExprcalS	   = 0x0007,
		ST_ExprcalR	   = 0x0008,
		ST_Custom      = 0xFF00, //! minimum of custom data type.
	};

	enum DEDataQualitay
	{
		DQ_Overflow  = 0x00001, //! 数据溢出.
		DQ_Lock		 = 0x00010, //! 被闭锁.
		DQ_Replace	 = 0x00020, //! 被替换, 如状态估计, 
		DQ_Resort	 = 0x00040, //! 未刷新.
		DQ_Invalid	 = 0x00080, //! 数据无效.
	};

	enum DETransReason
	{
		TR_Cyc		= 1,		
		TR_Back,
		TR_Spont, 
		TR_Init,
		TR_Req		= 5,
		TR_Act,
		TR_Actcon,
		TR_Deact,
		TR_Deactcon,
		TR_Actterm	= 10,
	};

	enum DERequestMask
	{
		RM_DataExchanged	= 1,
		RM_SelectControl	= 2,
		RM_ExecControl,
		RM_CannelControl,
		RM_SelectAdjust,
		RM_ExecAdjust,
		RM_CannelAdjust,
		RM_Custom			= 0xFFFF0000,
	};

	enum DELinkerEvent
	{
		LE_Connected	= 0,	//! 连接建立.
		LE_Closed		= 1,    //! 连接关闭.
		LE_Actived		= 2,    //! 被激活.
		LE_Restrained	= 3,	//! 被抑制.
	};

	enum DEReechoStatus
	{
		RS_Null		= 0x00,						//不调用回显
		RS_Sent		= 0x01,						//下行调用
		RS_Received = 0x02,						//上行调用
		RS_All		= RS_Received | RS_Sent,	//都调用回显.
	};

	enum DEMessageDirection
	{
		MD_Sent,
		MD_Received,
	};
public:
	//!
	//! pHandle 回调句柄.
	//! argc 参数个数.
	//! argv 参数列表.
	//! 如: IEC104 -sockaddr 0.0.0.0:2024. 启动IEC104协议, 在全部地址上监听2024端口.
	//! 如: DL476  -sockaddr 10.10.10.224:2024. 启动DL476协议,  在10.10.10.224地址上监听2024端口.
	//! 如: RSE104  -sockaddr 10.10.10.224:2024. 启动河海大学104扩展协议,  在10.10.10.224地址上监听2024端口.
	//!
	virtual UINT start(IDataExchangeCallback *pHandle, int argc, char **argv) = 0;

	//!
	//!
	//!
	virtual UINT stop() = 0;

	//!
	//! 对外发布数据,
	//! 一直 uTransReason = TR_Spont.
	virtual UINT issue(UINT uTransReason, LPCDATAEXCHANGEITEM lpData) = 0;

	//!
	//! 对外相应请求.
	//! uMask = RM_SelectControl/RM_ExecControl
	//! uReqResult = Failed/Success.
	virtual UINT respond(UINT uMask, UINT uReqResult, LPCDATAEXCHANGEITEM lpData) = 0;

	//!
	//! 向外请求数据.
	//! uMask = RM_SelectControl/RM_ExecControl
	virtual UINT request(UINT uMask, LPCDATAEXCHANGEITEM lpData) = 0;

	//!
	//! 获取交换协议名称.
	virtual const char* protocolName() const = 0;

	//!
	//! 获取交换协议别名.
	virtual const char* protocolAlias() const = 0;

	//!
	//! 打开或关闭报文回显, 默认为关闭。通常用来调试。
	//! 当有报文发送成功或接收时, 如果回显功能打开, 
	//! 则调用回调函数中的linkerMessage通知应用程序有报文被发送或接收.
	//! 参见 DEReechoStatus
	virtual void setReechoStatus(UINT rs) = 0;

	//!
	//! 获取报文回显状态.
	//! 
	virtual UINT reechoStatus() const = 0;
};


class IDataExchangeCallback
{
public:
	//!
	//! 外部向SCADA请求数据.
	//! uTransRTU 转发RTU号.
	//! uTransPoint 转发点号
	//! uMask 请求类型.
	//! uValue 请求目标.
	virtual BOOL request(UINT /*uTransRTU*/, UINT /*uTransPoint*/, UINT /*uMask*/, UINT /*uValue*/) { return FALSE; }

	//!
	//! 外部数据相应.
	//! uTransRTU 转发RTU号.
	//! uTransPoint 转发点号
	//! uMask 请求类型.
	//! uResult 请求结果.
	//! uValue 请求目标.
	virtual VOID respond(UINT /*uTransRTU*/, UINT /*uTransPoint*/, UINT /*uMask*/, UINT /*uResult*/, UINT /*uValue*/) { return; }

	//!
	//! 外部数据输入.
	//! uTransReason 传送原因, 参见IDataExchange::DETransReason.
	//! uTransRTU 转发RTU号.
	//! uTransPoint 转发点号.
	//! uValue 数据值.
	//! uFileTime 数据产生时间.
	//! uQuality 数据质量.
	virtual VOID issue(UINT /*uTransReason*/, UINT /*uTransRTU*/, UINT /*uTransPoint*/, UINT /*uValue*/, UINT64 /*uFileTime*/, UINT /*uQuality*/) { return ; }
	

	//!
	//! 转发表记录数.
	//! 用来处理响应总召唤.
	virtual UINT count() const { return 0; }

	//!
	//! 转发表记录对象.
	//! 用来处理响应总召唤.
	virtual LPCDATAEXCHANGEITEM item(UINT/* uIndex*/) const { return NULL; }

	//!
	//! 连接状态通知.
	//! uLinker 连接地址, 高4位表示网络序IP地址, 低2位表示本地序号端口.
	//! uEvent  参见: IDataExchange::DELinkerEvent.
	virtual VOID linkerEvent(UINT64 /*uLinker*/, IDataExchange::DELinkerEvent /*uEvent*/) {	return;	}

	//!
	//! 消息通知.
	//! uLinker 连接地址, 高4位表示网络序IP地址, 低2位表示本地序号端口.
	//! uDirection 0 上行(接收); 1下行(发送).
	//! szMessage 消息地址.
	//! uLen 消息长度.
	virtual VOID linkerMessage(UINT64 /*uLinker*/, IDataExchange::DEMessageDirection /*uDirection*/, LPCUSTR /*szMessage*/, UINT /*uLen*/) {	return;	}

	virtual BOOL refreshDataValues(UINT uScadaType=0) = 0;
	virtual UINT typeCount(UINT uScadaType) const { return 0; }
};

//!
//! 插件管理器．
//! 每个动态库可以包含多个转发插件．
//! 
class IDELibPluginManager : public IICSUnknown
{
public:
	int  AddRef() { return 1; }

	int  Release() { return 1; }
public:
	//! 
	//! 枚举支持协议.
	//! @param [out]szNames 接收缓存地址, 每个插件接口名称之间用'\0'分割,
	//! 最后一个插件接口名称以"\0\0"结束.
	//! @param [int]uLen 缓存长度.
	//! @return 写入缓存的长度,包括结束符和分割符,　szProtocols或如果uLen小于需要的长度，
	//! 将返回实际需要的长度.
	virtual UINT enumPluginInterfaceNames(char* szNames, UINT uLen) const = 0;

	//! 
	//! 查询接口。
	virtual bool QueryInterface(const char* szInterfaceName, void** ppUnknown) = 0;
};

# ifndef MODEL_COMMDATAEXCHANGE
#	ifdef _DEBUG
#		define MODEL_COMMDATAEXCHANGE "commdataexchange"
#	else
#		define MODEL_COMMDATAEXCHANGE "commdataexchange"
#	endif
# endif

# ifndef MODEL_RSE104DATAEXCHANGE
#	ifdef _DEBUG
#		define MODEL_RSE104DATAEXCHANGE "rse104dataexchange"
#	else
#		define MODEL_RSE104DATAEXCHANGE "rse104dataexchange"
#	endif
# endif

# ifndef MODEL_XJ104DATAEXCHANGE
#	ifdef _DEBUG
#		define MODEL_XJ104DATAEXCHANGE "xj104dataexchange"
#	else
#		define MODEL_XJ104DATAEXCHANGE "xj104dataexchange"
#	endif
# endif

# ifndef CLSID_COMMDATAEXCHANGE
#	define CLSID_COMMDATAEXCHANGE	"commdataexchange"
# endif

# ifndef CLSID_RSE104DATAEXCHANGE
#	define CLSID_RSE104DATAEXCHANGE	"rse104dataexchange"
# endif

# ifndef CLSID_XJ104DATAEXCHANGE
#	define CLSID_XJ104DATAEXCHANGE	"xj104dataexchange"
# endif


# ifndef IID_ICE104DataExchange
#	define IID_ICE104DataExchange	"iec104"
# endif

# ifndef IID_DL476DataExchange
#	define IID_DL476DataExchange	"dl476"
# endif

# ifndef IID_RSE104DataExchange
#	define IID_RSE104DataExchange	"rse104"
# endif

# ifndef IID_XJ104DataExchange
#	define IID_XJ104DataExchange	"xj104"
# endif

# ifndef DE_GETCLASSOBJECTMETHOD
#	define DE_GETCLASSOBJECTMETHOD
	typedef bool (*PFN_DE_GETCLASSOBJECTMETHOD)(const char *classname, IICSUnknown** ppUnk);
# endif

# ifndef METHOD_GETCLASSOBJECT
#	define METHOD_GETCLASSOBJECT "GetClassObject"
# endif

#endif
