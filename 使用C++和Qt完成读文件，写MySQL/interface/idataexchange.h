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
		UINT    _cb;				//! �������С, ������չ.
		UINT	_uTransID;			//! ת������ID.
		UINT	_uScadaType;		//! SCADAģ���е�����, 1=>ģ����, 2=>�ź�����, �μ�SCADAģ�Ͷ���.
		UINT	_uScadaID;			//! SCADAģ���е�����ID, ͨ�����ͺ�ID��ȡSCADA���ݷ���
		union
		{
			UINT	_uCurValue;		 //! ģ�������ź����Ŀ��ӻ���ǰֵ, �Կ�������˵����Ŀ��ֵ.
			FLOAT	_fCurValue;		 //! ģ�������ź����Ŀ��ӻ���ǰֵ, �Կ�������˵����Ŀ��ֵ.
			UINT8	_uByte4[4];
		};
		UINT64	_u64CTime;			//! ����޸�ʱ��.
		UINT	_uQuality;			//! ת��ģ���е�����.
		UINT	_uTransRTU;			//! ת����ͨѶ��ַ
		UINT	_uTransPoint;		//! ת������Ϣ�����ݣ����
		UINT	_uTransMsgType;		//! ת������Ϣ����
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
		DQ_Overflow  = 0x00001, //! �������.
		DQ_Lock		 = 0x00010, //! ������.
		DQ_Replace	 = 0x00020, //! ���滻, ��״̬����, 
		DQ_Resort	 = 0x00040, //! δˢ��.
		DQ_Invalid	 = 0x00080, //! ������Ч.
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
		LE_Connected	= 0,	//! ���ӽ���.
		LE_Closed		= 1,    //! ���ӹر�.
		LE_Actived		= 2,    //! ������.
		LE_Restrained	= 3,	//! ������.
	};

	enum DEReechoStatus
	{
		RS_Null		= 0x00,						//�����û���
		RS_Sent		= 0x01,						//���е���
		RS_Received = 0x02,						//���е���
		RS_All		= RS_Received | RS_Sent,	//�����û���.
	};

	enum DEMessageDirection
	{
		MD_Sent,
		MD_Received,
	};
public:
	//!
	//! pHandle �ص����.
	//! argc ��������.
	//! argv �����б�.
	//! ��: IEC104 -sockaddr 0.0.0.0:2024. ����IEC104Э��, ��ȫ����ַ�ϼ���2024�˿�.
	//! ��: DL476  -sockaddr 10.10.10.224:2024. ����DL476Э��,  ��10.10.10.224��ַ�ϼ���2024�˿�.
	//! ��: RSE104  -sockaddr 10.10.10.224:2024. �����Ӻ���ѧ104��չЭ��,  ��10.10.10.224��ַ�ϼ���2024�˿�.
	//!
	virtual UINT start(IDataExchangeCallback *pHandle, int argc, char **argv) = 0;

	//!
	//!
	//!
	virtual UINT stop() = 0;

	//!
	//! ���ⷢ������,
	//! һֱ uTransReason = TR_Spont.
	virtual UINT issue(UINT uTransReason, LPCDATAEXCHANGEITEM lpData) = 0;

	//!
	//! ������Ӧ����.
	//! uMask = RM_SelectControl/RM_ExecControl
	//! uReqResult = Failed/Success.
	virtual UINT respond(UINT uMask, UINT uReqResult, LPCDATAEXCHANGEITEM lpData) = 0;

	//!
	//! ������������.
	//! uMask = RM_SelectControl/RM_ExecControl
	virtual UINT request(UINT uMask, LPCDATAEXCHANGEITEM lpData) = 0;

	//!
	//! ��ȡ����Э������.
	virtual const char* protocolName() const = 0;

	//!
	//! ��ȡ����Э�����.
	virtual const char* protocolAlias() const = 0;

	//!
	//! �򿪻�رձ��Ļ���, Ĭ��Ϊ�رա�ͨ���������ԡ�
	//! ���б��ķ��ͳɹ������ʱ, ������Թ��ܴ�, 
	//! ����ûص������е�linkerMessage֪ͨӦ�ó����б��ı����ͻ����.
	//! �μ� DEReechoStatus
	virtual void setReechoStatus(UINT rs) = 0;

	//!
	//! ��ȡ���Ļ���״̬.
	//! 
	virtual UINT reechoStatus() const = 0;
};


class IDataExchangeCallback
{
public:
	//!
	//! �ⲿ��SCADA��������.
	//! uTransRTU ת��RTU��.
	//! uTransPoint ת�����
	//! uMask ��������.
	//! uValue ����Ŀ��.
	virtual BOOL request(UINT /*uTransRTU*/, UINT /*uTransPoint*/, UINT /*uMask*/, UINT /*uValue*/) { return FALSE; }

	//!
	//! �ⲿ������Ӧ.
	//! uTransRTU ת��RTU��.
	//! uTransPoint ת�����
	//! uMask ��������.
	//! uResult ������.
	//! uValue ����Ŀ��.
	virtual VOID respond(UINT /*uTransRTU*/, UINT /*uTransPoint*/, UINT /*uMask*/, UINT /*uResult*/, UINT /*uValue*/) { return; }

	//!
	//! �ⲿ��������.
	//! uTransReason ����ԭ��, �μ�IDataExchange::DETransReason.
	//! uTransRTU ת��RTU��.
	//! uTransPoint ת�����.
	//! uValue ����ֵ.
	//! uFileTime ���ݲ���ʱ��.
	//! uQuality ��������.
	virtual VOID issue(UINT /*uTransReason*/, UINT /*uTransRTU*/, UINT /*uTransPoint*/, UINT /*uValue*/, UINT64 /*uFileTime*/, UINT /*uQuality*/) { return ; }
	

	//!
	//! ת�����¼��.
	//! ����������Ӧ���ٻ�.
	virtual UINT count() const { return 0; }

	//!
	//! ת�����¼����.
	//! ����������Ӧ���ٻ�.
	virtual LPCDATAEXCHANGEITEM item(UINT/* uIndex*/) const { return NULL; }

	//!
	//! ����״̬֪ͨ.
	//! uLinker ���ӵ�ַ, ��4λ��ʾ������IP��ַ, ��2λ��ʾ������Ŷ˿�.
	//! uEvent  �μ�: IDataExchange::DELinkerEvent.
	virtual VOID linkerEvent(UINT64 /*uLinker*/, IDataExchange::DELinkerEvent /*uEvent*/) {	return;	}

	//!
	//! ��Ϣ֪ͨ.
	//! uLinker ���ӵ�ַ, ��4λ��ʾ������IP��ַ, ��2λ��ʾ������Ŷ˿�.
	//! uDirection 0 ����(����); 1����(����).
	//! szMessage ��Ϣ��ַ.
	//! uLen ��Ϣ����.
	virtual VOID linkerMessage(UINT64 /*uLinker*/, IDataExchange::DEMessageDirection /*uDirection*/, LPCUSTR /*szMessage*/, UINT /*uLen*/) {	return;	}

	virtual BOOL refreshDataValues(UINT uScadaType=0) = 0;
	virtual UINT typeCount(UINT uScadaType) const { return 0; }
};

//!
//! �����������
//! ÿ����̬����԰������ת�������
//! 
class IDELibPluginManager : public IICSUnknown
{
public:
	int  AddRef() { return 1; }

	int  Release() { return 1; }
public:
	//! 
	//! ö��֧��Э��.
	//! @param [out]szNames ���ջ����ַ, ÿ������ӿ�����֮����'\0'�ָ�,
	//! ���һ������ӿ�������"\0\0"����.
	//! @param [int]uLen ���泤��.
	//! @return д�뻺��ĳ���,�����������ͷָ��,��szProtocols�����uLenС����Ҫ�ĳ��ȣ�
	//! ������ʵ����Ҫ�ĳ���.
	virtual UINT enumPluginInterfaceNames(char* szNames, UINT uLen) const = 0;

	//! 
	//! ��ѯ�ӿڡ�
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
