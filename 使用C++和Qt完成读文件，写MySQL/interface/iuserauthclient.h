/*
**++
**  ģ������:   USERAUTH - Client
**
**  �ļ�����:   iuserauthclient.h
**
**  �ļ�����:	�������û�Ȩ����֤�ͻ���ģ��(USERAUTHCLIENT)��APIs,
**				���������ӿ� IUACResource, IUACPermission, IUserAuthClient
**				�Ķ����һ�����󴴽����� GetClassObject.
**
**  ��������:   2006-12-14
**
**  �޸�����:
**
**		2006-12-10  �����ļ� [����].
**		2007-4-6    �޸�Ȩ�޿ͻ��˷��ʽӿ�,   �ı�ModifyUserPsw()�����Ĳ��� [����].  
**		2008-10-24  ���getlastloginuser�ӿ�, �����������½���û�.
**	
**--
*/

#ifndef __IUSERAUTHCLIENT_H_INCLUDED__
#define __IUSERAUTHCLIENT_H_INCLUDED__

#include "icsunknown.h"
#include "generalintf.h"
#include "qiptr.h"
#include <time.h>
#include <string>

#define IID_IUserAuthClient "IUserAuthClient"
#define IID_IUACResource	"IUACResource"
#define IID_IUACPermission	"IUACPermission"

#define IID_IUACArea		"IUACArea"
#define IID_IUACAreaPerm	"IUACAreaPerm"
#define IID_IUACSpecialPerm	"IUACSpecialPerm"
#define IID_IUACUser		"IID_IUACUser"

#define CLSID_UserAuthClient "userauthclient"


enum _UASRESULT			//Ȩ�޹�������������.
{
	UAS_SUCCESS = 0,	//�ɹ�����
	UAS_UNLOGIN,		//�û�δ��½
	UAS_RELOGIN,		//�ظ���½.
	UAS_NOUSER,			//�û����Ʋ�����
	UAS_PWDERR,			//�������

	UAS_USERINSTOP,	    //�û�ͣ��
	UAS_USEROVERDUE,	//�û�����.
	UAS_USERLOCKED,     //�û�������.
	UAS_UNREGESTEDWS,   //δע�Ṥ��վ.	
	UAS_NOPERMISSION,   //û����Ӧ��Ȩ��.

	UAS_NOPERMISSION_U, //�û�û��Ȩ��.
	UAS_NOPERMISSION_H, //����վû��Ȩ��.
	UAS_NOPERM,         //��Դ�����η������̶�Ȩ�޲�����.
	UAS_MISFITOPER,     //����Ȩ�޲����á� ��������������ڹ̶�Ȩ��.
	//UAS_INVALIDVERSION, //�������Ϳͻ��˰汾��һ��.

	UAS_MINOR,          //����������.
	UAS_DBERR,			//���ݿ����, �����������ݿ���񲻳ɹ�.
	UAS_UASERR,         //Ȩ�޷�������Ӧʧ��
	UAS_ABNORMITY,      //�������쳣.
	UAS_PWDINSTOP,		//�������	18-06-03 by lxl
	UAS_PWDINT,			//�޸ĳ�ʼ���� 18-06-04 by lxl
	UAS_PINERROR,		//��֤����� 18-06-10 by lxl
	UAS_INVALIDVERSION, //�������Ϳͻ��˰汾��һ��.
};

enum _UACRESULT         //Ȩ�޹���ͻ��˷����
{
	UAC_SUCCESS			= UAS_SUCCESS,		  //0
	UAC_UNLOGIN			= UAS_UNLOGIN,		  //1 
	UAC_RELOGIN			= UAS_RELOGIN,		  //2
	UAC_NOUSER			= UAS_NOUSER,		  //3
	UAC_PWDERR			= UAS_PWDERR,		  //4

	UAC_USERINSTOP		= UAS_USERINSTOP,	  //5
	UAC_USEROVERDUE		= UAS_USEROVERDUE,	  //6
	UAC_USERLOCKED		= UAS_USERLOCKED,     //7
	UAC_UNREGESTEDWS	= UAS_UNREGESTEDWS,   //8
	UAC_NOPERMISSION	= UAS_NOPERMISSION,   //9

	UAC_NOPERMISSION_U  = UAS_NOPERMISSION_U, //10
	UAC_NOPERMISSION_H	= UAS_NOPERMISSION_H, //11 
	UAC_NOPERM			= UAS_NOPERM,         //12��Դ�����η������̶�Ȩ�޲�����.
	UAC_MISFITOPER		= UAS_MISFITOPER,     //13����Ȩ�޲����á� ��������������ڹ̶�Ȩ��.
	UAC_INVALIDVERSION  = UAS_INVALIDVERSION, //14�������Ϳͻ��˰汾��һ��.
	
	UAC_MAX_PARAMERR     = UAS_INVALIDVERSION, //14, �����������������.
											   
	UAC_MINOR			 = UAS_MINOR,          //15
	UAC_UASERR			 = UAS_UASERR,		   //16Ȩ�޷�������Ӧʧ��
	//17
	UAC_NOUAS			 = 18,				   //Ȩ�޷�����δ��Ӧ.  //18
	UAC_PARMERR,							   //��������ȷ.				//19

	UAC_SENDERROR,							   //�������ʧ��.				//20
	UAC_OVERTIME,							   //������Ӧ��ʱ.				//21
	UAC_READMSGERR,							   //��ȡ��Ӧ����ʧ��.			//22
	UAC_UNCMPERR,							   //����ѹ����ʽ����.			//23
	UAC_UNKOWNERR,							   //24
};

//Ȩ������:
enum _UA_PERMTYPE
{
	UAPT_RES,     //��Դ
	UAPT_AREA,    //���η���.
	UAPT_SPERM,   //�̶�Ȩ��.
	UAPT_ALLTYPE, //��������.
	UAPT_NULL,    //��Ч����.
};

//��Դ����
enum _UA_RESTYPE
{
	UART_APP,	   //Ӧ�ó���
	UART_VDFPAGE,  //��̬ҳ��.
	UART_URL,	   //WEBҳ��.
	UART_REPORT,   //����.
	UART_ALLTYPE,  //��������.
};
enum _UA_USRCTORL
{
	UA_USERAUTH = 1,	//1 Ȩ��ά��
	UA_MODEL,			//2��ģ��ά��
	UA_UI,				//3: ������̬
	UA_AI,				//4���˻����н���
	UA_CONSOLE,			//5������̨
	UA_CONTROL,			//6������/ֹͣ����
	UA_AUDIT,			//7����ȫ���
};
#ifndef MAX_UAOBJID_LEN
#define MAX_UAOBJID_LEN				32
#endif

#ifndef MAX_UAOBJNAME_LEN
#define MAX_UAOBJNAME_LEN			256
#endif

#ifndef MAX_USERID_LEN
#define MAX_USERID_LEN				MAX_UAOBJID_LEN
#endif

#ifndef MAX_USERNAME_LEN
#define MAX_USERNAME_LEN				MAX_UAOBJID_LEN
#endif

#ifndef MAX_RESID_LEN
#define MAX_RESID_LEN				MAX_UAOBJID_LEN
#endif

#ifndef MAX_AREAID_LEN
#define MAX_AREAID_LEN				MAX_UAOBJID_LEN
#endif

#ifndef MAX_SPERMID_LEN
#define MAX_SPERMID_LEN				MAX_UAOBJID_LEN
#endif

#ifndef MAX_OPERID_LEN
#define MAX_OPERID_LEN				MAX_UAOBJID_LEN
#endif

#ifndef MAX_PASSWORD_LEN
#define MAX_PASSWORD_LEN			32
#endif

#ifndef MAX_HOSTNAME_LEN
#define MAX_HOSTNAME_LEN			64
#endif

#ifndef MAX_PROCESSNAME_LEN
#define MAX_PROCESSNAME_LEN			64
#endif

#ifndef  MAX_OPTID_LEN
#define  MAX_OPTID_LEN				8
#endif

#define ALIGNFILLSIZE(s)    (4 - (s)%4)

typedef struct __tagLoginInfo
{
	char		cUserID[MAX_USERID_LEN + 1];
	char		cUnkownTag[MAX_PASSWORD_LEN + 1];
	time_t		tLoginTime;
	time_t		tLogoutTime;
	char	    ___alignFill__tagLoginInfo[ALIGNFILLSIZE(MAX_USERID_LEN + 9)];
}LOGININFOR, *LPLOGININFOR;

//////////////////////////////////////////////////////////////////////////
// IUACArea���η����ӿ�
/*
**  ���η����ӿ��ṩ�˷������η���ʵ�����Ҫ���Եķ���.
*/
class IUACArea : public IICSUnknown
{
public:
	/*!����:������η���ID.
	* \���� id (INOUT):���η���ID.
	* \���� size (IN):���η���id����.
	*/
	virtual void GetAreaID(char* id, int size) = 0;

	/*!����:������η�������.
	* \���� name (INOUT):���η�������.
	* \���� size (IN):���η������Ƴ���.
	*/
	virtual void GetAreaName(char* name, int size) = 0;

public:	
	static char* GetIntfName ()
	{
		return IID_IUACArea;
	}
};

// IUACAreaPerm��Դ�ӿ�
/*
**  ��Դ���ʽӿ��ṩ�˷�����Դʵ�����Ҫ���Եķ���.
*/
class IUACAreaPerm : public IICSUnknown
{
public:
	/*!����:������η���ID.
	* \���� id (INOUT):���η���ID.
	* \���� size (IN):���η���id����.
	*/
	virtual void GetAreaID(char* id, int size) = 0;

	/*!����:������η�������.
	* \���� name (INOUT):���η�������.
	* \���� size (IN):���η������Ƴ���.
	*/
	virtual void GetAreaName(char* name, int size) = 0;

	/*!����:������η�������.
	* \���� authmod (INOUT):���η���������ʽ.
	* \���� size (IN):���η���������ʽ����.
	*/
	virtual void GetAreaOper(char* Oper, int size) = 0;

public:
	
	static char* GetIntfName ()
	{
		return IID_IUACAreaPerm;
	}
};


class IUACSpecialPerm : public IICSUnknown
{
public:
	/*!����:��ù̶�Ȩ��ID.
	* \���� id (INOUT):�̶�Ȩ��ID.
	* \���� size (IN):�̶�Ȩ��id����.
	*/
	virtual void GetSPermID(char* id, int size) = 0;

	/*!����:��ù̶�Ȩ������.
	* \���� name (INOUT):�̶�Ȩ������.
	* \���� size (IN):�̶�Ȩ�����Ƴ���.
	*/
	virtual void GetSPermName(char* name, int size) = 0;

public:
	
	static char* GetIntfName ()
	{
		return IID_IUACSpecialPerm;
	}
};
// add by lyc end
//////////////////////////////////////////////////////////////////////////


// IUACResource��Դ�ӿ�
/*
**  ��Դ���ʽӿ��ṩ�˷�����Դʵ�����Ҫ���Եķ���.
*/
class IUACResource : public IICSUnknown
{
public:

	/*!����:�����ԴID.
	 *	\���� id (INOUT):��Դid.
	 *  \���� size (IN):��Դid����.
	 */
	virtual void GetResID( char* id, int size ) = 0;

	/*!����:�����Դ����.
	 *	\���� name (INOUT):��Դ����.
	 *  \���� size (IN):��Դ���Ƴ���.
	 */
	virtual void GetResName( char* name, int size ) = 0;

	/*!����:�����Դ������Ϣ.
	 *	\���� type (INOUT):��Դ��������.
	 *  \���� size (IN):��Դ���ͳ���.
	 */
	virtual void GetResType( char* type, int size ) = 0;

public:
	
	static char* GetIntfName ()
	{
		return IID_IUACResource;
	}

};

// IUACPermissionȨ�޽ӿ�.
/*
**  Ȩ����һ����Ԫ��(<��Դ, ����>),
**  Ȩ�޷��ʽӿ��ṩ�˷���Ȩ��ʵ�����Ҫ���Եķ���.
*/
class IUACPermission : public IICSUnknown
{
public:

	/*!����:���Ȩ�޶�Ӧ����Դ.
	 *	\���� ppRes (INOUT):��ǰȨ�޶�Ӧ����Դ.
	 */
	virtual bool GetResource( IUACResource** ppRes ) = 0;

	/*!����:���Ȩ�޶�Ӧ�Ĳ���.
	 *	\���� operation (INOUT):��������.
	 *  \���� size (INOUT):�������Ƴ���.
	 */
	virtual void GetOperation( char* operation, int size ) = 0;

public:	

	static char* GetIntfName ()
	{
		return IID_IUACPermission;
	}
};


class IUACUser : public IICSUnknown
{
public:
	virtual const char *userName() = 0;

	virtual const char *userId() = 0;

public:	

	static char* GetIntfName ()
	{
		return IID_IUACPermission;
	}
};

// IUserAuthClient�û�Ȩ�޿ͻ��˷��ʽӿ�
/*
**  �ͻ��˷��ʽӿ��ṩ�ķ�����������û�Ȩ����֤����.
*/
class IUserAuthClient : public IICSUnknown
{
public:
	/************************************************************************************************/
	/*������ʽӿڣ�ntype��ʾȨ�����Ͳο�_UA_USRCTORL												*/
	/*LogConsole = trueʱ��ʾ�����ӷ�����,���ʧ����ֱ�Ӷ�ȡ���ݿ�									*/
	/*LogConsole = falseʱ��ʾֻ���ӷ�����,�ǿ���̨����ͨ��ӦΪfalse								*/
	/*IsDlg = true ��ʾ��Ҫ��¼���ڣ�IPadress,UsrName,pwd�Ȳ���Ϊ��������							*/
	/*IsDlg = false��ʾ����Ҫ��¼���ڣ�UsrName,pwd�Ȳ���Ϊ�������,LogConsole��IPadress������Ч		*/
	/*IPadress �ͻ������ڻ���IP,UsrName����¼�˺ţ�pwd ��¼����										*/				
	/*����ֵ �ɹ�UAC_SUCCESS��ʧ��UAC_UNLOGIN														*/		
	/************************************************************************************************/
	virtual int LogWithWindow(int ntype,bool LogConsole,bool IsDlg,std::string &IPadress,std::string &UsrName,std::string &pwd) = 0;
	/*!����: ��¼�ⲿ�ͻ�ϵͳ.
	 *	\���� psUserId (IN):�û�ID.
	 *  \���� psPassword (IN):����.
	 *  \����ֵ:
	 *       UAC_SUCCESS( = 0),���ε�¼������;
	 *  �ýӿڱ����� lxl 18-06-07
	 
	 */
	virtual int LogIn ( const char* psUserId, 
		                 const char* psPassword ) = 0;

	/*!����:ע�����ⲿ�ͻ�ϵͳ�ı��ε�¼.
	 *	\���� psUserId (IN):��ע����¼���û�ID.
	 *  \����ֵ:
	 *       UAC_SUCCESS( = 0),	�û���ע�����󱻽���;
	 *       other,				�û���ע�������޷�������.
	 */
	virtual int LogOut ( const char* psUserId ) = 0;

	/*!����:��֤�û�.��:�����û��������Ƿ���ȷ.
	 *	\���� psUserId (IN):�û�ID.
	 *  \���� psPassword (IN):����.
	 *  \����ֵ:
	 *       UAC_SUCCESS( = 0),�û���֤�ɹ�,���û����ⲿ�ͻ�ϵͳ�ĺϷ�ʹ����;
	 *       other,			   �û���֤ʧ��,���û����ⲿ�ͻ�ϵͳ��˵�ǷǷ���.
	 */
	virtual int ValidateUser (const char* psUserId, 
		                      const char* psPassword ) = 0;

	/*!����:�޸��û�����.
	 *	\���� psUserId (IN):�û�ID.
	 *  \���� psOldPassword (IN):������.
	 *  \���� psNewPassword (IN):������.
	 *  \����ֵ:
	 *       UAC_SUCCESS( = 0),�޸��û�����ɹ�;
	 *       other,			   �޸��û�����ʧ��.
	 */
	virtual int ModifyUserPsw ( const char* psUserId, 
		                         const char* psOldPassword, 
		                         const char* psNewPassword ) = 0;

	/*!����:��֤�û�Ȩ��.�����˵,�û���ĳһ��Դ�Ƿ���Խ���ָ���Ĳ���.
	 *	\���� psUserId (IN):�û�ID.
	 *  \���� psResId (IN):��Դid,��ʾ����֤����Դ.
	 *  \���� psOperation (IN):ָĳһ����.
	 *  \����ֵ:
	 *       UAC_SUCCESS( = 0),�û��Ը�����Դ���Խ���ָ���Ĳ���;
	 *       other,			   �û��Ը�����Դ���ܽ���ָ���Ĳ���.
	 */
	/*virtual int ValidateUserPerm (const char* psUserId,
		                          const char* pResId,
								  const char* psOperation, bool bIncArea = true) = 0;*/
	virtual int ValidateUserPerm (const char* psUserId,
		                          const char* pResId,
								  const char* psOperation) = 0;

	/*!����:��֤�û��Ƿ������ĳһ��Դ��ص�Ȩ��.
	 *	\���� psUserId (IN):�û�ID.
	 *  \���� psResId (IN):��Դid,��ʾ����֤����Դʵ��.
	 *  \����ֵ:
	 *       UAC_SUCCESS( = 0),�û����и���Դ�����Ȩ��;
	 *       other,			   �û������и���Դ���κ�Ȩ��,���û����ܶԸ���Դ�����κβ���.
	 */
	/*virtual int ValidateResource ( const char* psUserId,
		                            const char* pResId, bool bIncArea = true) = 0;*/
	virtual int ValidateResource ( const char* psUserId,
		                            const char* pResId) = 0;
	

	/*!����:�г��û�������Ȩ��.Ȩ����һ����Ԫ��(<��Դ, ����>).
	 *  \���� psUserId (IN):�û�ID.
	 *  \���� ppPerms (INOUT):���ҵ��ĸ��û�����Ȩ���б�.
	 *  \����ֵ: 
	 *       UAC_SUCCESS( = 0), �ɹ�
	 *		 other,				ʧ��
	 */
/*	virtual int ListPermsByUser ( const char* psUserId,
								   IICSEnum** ppPerms, bool bIncArea = true) = 0;*/
	virtual int ListPermsByUser ( const char* psUserId,
								   IICSEnum** ppPerms) = 0;
	
	/*!����:�г�ϵͳ�����е���Դ.
	 *	\���� ppReses (INOUT):ϵͳ��������Դ���б�.
	 *  \����ֵ:
	 *       UAC_SUCCESS( = 0), �ɹ�
	 *		 other,				ʧ��
	 */
	virtual int ListAllResource ( IICSEnum** ppReses ) = 0;

	/*!����:�г��û���ϵͳ��ӵ�еĸ������͵�ȫ����Դ.
	 *	\���� psUserId (IN):�û�ID.
	 *  \���� psResType (IN):����ѯ����Դ����.
	 *  \���� ppReses (INOUT):����������������Դ���б�.
	 *  \����ֵ:
	 *       UAC_SUCCESS( = 0), �ɹ�
	 *		 other,				ʧ��
	 */
	/*virtual int ListUserResourceByType ( const char* psUserId,
		                                  const char* psResType,
										  IICSEnum** ppReses, bool bIncArea = true) = 0;*/

	virtual int ListUserResourceByType ( const char* psUserId,
		                                  const char* psResType,
										  IICSEnum** ppReses) = 0;

	/*!����:�г��û�ӵ�еĸ�����Դ��ȫ��ֱ���¼���Դ.
	 *	\���� psUserId (IN):�û�ID.
	 *  \���� psParentResId (IN):��Դid,��ʾ����ѯ���¼�����Դ.
	 *  \���� ppReses (INOUT):����������������Դ���б�.
	 *  \����ֵ:
	 *       UAC_SUCCESS( = 0), �ɹ�
	 *		 other,				ʧ��
	 */
	/*virtual int ListUserAllSubResource ( const char* psUserId,
										  const char* psParentResId,
										  IICSEnum** ppReses, bool bIncArea = true) = 0;*/
	virtual int ListUserAllSubResource ( const char* psUserId,
										  const char* psParentResId,
										  IICSEnum** ppReses) = 0;

	/*!����:�г��û�ӵ�еĸ�����Դ��ָ�����͵�ȫ��ֱ���¼���Դ.
	 *	\���� psUserId (IN):�û�ID.
	 *  \���� psParentResId (IN):��Դid,��ʾ����ѯ���¼�����Դ.
	 *  \���� psResType (IN):����ѯ����Դ����.
	 *  \���� ppReses (INOUT):����������������Դ���б�.
	 *  \����ֵ:
	 *       UAC_SUCCESS( = 0), �ɹ�
	 *		 other,				ʧ��
	 */
	/*virtual int ListUserSubResourceByType  ( const char* psUserId,
											 const char* psParentResId,
											 const char* psResType,
											 IICSEnum** ppReses, bool bIncArea = true) = 0;*/
	virtual int ListUserSubResourceByType  ( const char* psUserId,
											 const char* psParentResId,
											 const char* psResType,
											 IICSEnum** ppReses) = 0;
    
	/* added by mjr 2006.12.12 */
	/*!����:�г�ĳ����Դ��ֱ��������Դ.���ض����е��ϼ���Դ���¼���Դ������Ч.
	 *  \���� psParentResId (IN):��Դid,��ʾ����ѯ���¼�����Դ.
	 *  \���� ppReses (INOUT):����������������Դ���б�.
	 *  \����ֵ:
	 *       UAC_SUCCESS( = 0), �ɹ�
	 *		 other,				ʧ��
	 */
	virtual int ListAllSubResource ( const char* psParentResId,
									  IICSEnum** ppReses) = 0;

	/*!����:���ĳ��Դ��ĳ���͵�ֱ���¼���Դ.���ض����е��ϼ���Դ���¼���Դ������Ч.
	 *  \���� psParentResId (IN):��Դid,��ʾ����ѯ���¼�����Դ.
	 *  \���� psResType (IN):����ѯ����Դ����.
	 *  \���� ppReses (INOUT):����������������Դ���б�.
	 *  \����ֵ:
	 *       UAC_SUCCESS( = 0), �ɹ�
	 *		 other,				ʧ��
	 */
	virtual int ListSubResourceByType ( const char* psParentResId,
										 const char* psResType,
									     IICSEnum** ppReses) = 0;
	
	/*! ����:��֤ĳһ�̶�Ȩ��
	 *  \���� szUserID (IN):	�û�ID.
	 *  \���� szSPermID (IN):   �̶�Ȩ��ID.
	 *  \����ֵ:
	 *       UAC_SUCCESS( = 0), ��Ȩ��.
	 *		 UAC_NOPERMISSION(= 10), û��Ȩ��.
	 *		 UAC_NOPERMISSION_U(= 11),  �û�û��Ȩ��.
	 *		 UAC_NOPERMISSION_H(= 12),	����վû��Ȩ��.
	 *		 ��������ֵ��ʾ��֤ʧ��.
	 */
	virtual int ValidateSPerm(const char *szUserID, const char *szSPermID) = 0;

	/*! ����:��֤ĳһ���η���
	 *  \���� szUserID (IN):	�û�ID.
	 *  \���� szSPermID (IN):   ���η���ID.
	 *  \����ֵ:
	 *       UAC_SUCCESS( = 0), ��Ȩ��.
	 *		 UAC_NOPERMISSION(= 10), û��Ȩ��.
	 *		 UAC_NOPERMISSION_U(= 11),  �û�û��Ȩ��.
	 *		 UAC_NOPERMISSION_H(= 12),	����վû��Ȩ��.
	 *		 ��������ֵ��ʾ��֤ʧ��.
	 */
	virtual int ValidateArea(const char *szUserID, const char *szSAreaID, const char *szOperation) = 0;

	/*! ����:��֤ĳһ���η���
	 *  \���� szUserID (IN):	�û�ID.
	 *  \���� szSPermID (IN):   ���η���ID.
	 *  \����ֵ:
	 *       UAC_SUCCESS( = 0), �ɹ�.
	 *		 ��������ֵ��ʾʧ��.
	*/
	virtual int ListAllArea(IICSEnum** ppAreas) = 0;


	/*! ����:�г��û����������η���Ȩ��, Ȩ����һ����Ԫ��(<���η���, ����>).
	 *  \���� psUser (IN):	  �û�ID.
	 *  \���� ppAreaOper (OUT):   ���ҵ��ĸ��û��������η���Ȩ���б�.
	 *  \����ֵ:
	 *       UAC_SUCCESS( = 0), �ɹ�.
	 *		 ��������ֵ��ʾʧ��.
	*/
	virtual int ListAreaPermsByUser(const char* psUser, IICSEnum** ppAreaOper) = 0;

	/*! ���� : �г��û����������η���.
	 *  \����  psUser (IN):	  �û�ID.
	 *  \����  ppAreas (OUT):   ���ҵ��ĸ��û��������η����б�.
	 *  \����ֵ:
	 *       UAC_SUCCESS( = 0), �ɹ�.
	 *		 ��������ֵ��ʾʧ��.
	*/
	virtual int ListAreasByUser(const char* psUser, IICSEnum** ppAreas) = 0;

	/*! ���� : �������½���û�ID.
	 *  \����  pszUser (OUT):	  �����û�ID�Ļ����ַ, �������ΪNULL(0)ʱ, GetLastLoginUser�������û�ID�ĳ���.
	 *  \����  nUserLen (INT):    �����û�ID�Ļ��������ȵ�ַ.
	 *  \����ֵ:
	 *				���pszUser != NULLʱ, ����UAC_SUCCESS��ʾ�ɹ�,
	 *				���pszUser == NULLʱ, �������û�ID�ĳ���, �����ʱû���û���½������ 0.
	 *				��������ֵ��ʾʧ��.
	 *
	 *	\ע�� :		userID��󳤶� ��MAX_USERID_LEN����
	 *				����û��Ѿ�ע��Ҳ����������ID.
	*/
	virtual int GetLastLoginUser(char *pszUser, int nUserLen) = 0;
public:
//the method in this section afford ui support.
//user process must initialize QApplication object before use ui method.
	//login action. this function pop-up a login dialog.
	//[in, out] szUser           : point to the buffer that indicate default userid and receive the login userid 
	//[in] nLen			         : length of buffer
	//[in] nTryTimes			 : the times that allow user retry when login faild.  
	//[in] bWithChangePwdButton  : indicated the dialog cantains change password button.
	//[out]bOK                   : the bool point to the buffer that receive the OK or Cancel button be clicked.
	//Return Value : return ture if login seccuss, else return false
	virtual bool ULogIn(char *szUser = 0, int nLen = 32, int nTryTimes = 3, bool bWithChangePwdButton = true, bool *bOK = NULL) = 0;

	//change password action. this function pop-up a change password dialog.
	//[in, out] szUser           : point to the buffer that indicate defaulter userid and receive the login userid 
	//[in] nLen			         : length of buffer
	//[out]bOK                   : the bool pointer that receive the OK or Cancel button be clicked.
	//Return Value : return ture if change password seccuss, else return false.
	virtual bool UChangePassword(char *szUser = 0, int nLen = 32, bool *bOK = NULL) = 0;
	
	//[in] szUser   : point to the buffer that indicate defaulter userid
	//[in] nLen			         : length of buffer
	//[in] nTryTimes			 : the times that allow user retry when login faild.  
	//[in] bWithChangePwdButton : indicated the dialog cantains change password button.
	//[out]bOK                  : the bool point to the buffer that receive the OK or Cancel button be clicked.
	//Return Value : return ture if logout seccuss, else return false.
	virtual bool ULogOut(const char *szUser = 0, bool *bOK = NULL) = 0;
public:
	/*! ���� :		UpdateUAS����������Ȩ�޷�����(UAS)�е�����.
	 *				�������Ŀǰֻ��Ȩ�޹�����(usercfg)ʹ��.
	 *				����ģ����ʱ��Ҫʹ��.
	 */	
	virtual int UpdateUAS() = 0;


	virtual const char *UaErrorText(int nUaRet) = 0;

	/*! ����:ö���û�
	 *  \���� ppUsers (OUT):	���ն���, �ο� IUACUser.
	 *  \���� nPermType (IN):   ���Ȩ������,  ��Դ\���η���\�̶�Ȩ��
	 *	\���� szPermId (IN):    ���Ȩ��Id.
	 *	\���� szOperId (IN):    ��ز���Id.    "R"\"W"\"E"
	 *  \����ֵ:
	 *       UAC_SUCCESS( = 0), �ɹ�.
	 *		 ��������ֵ��ʾʧ��.
	*/
	virtual int  ListUsers(IICSEnum** ppUsers, int nPermType = UAPT_NULL, const char *szPermId = NULL, const char *szOperId = NULL) = 0;

	/*!
	 *login user.
	*/
	virtual const char *currentUser() = 0;
	/*
	 *last User used ValidateUser interface.
	*/
	virtual const char *lastUser() = 0;

public:
	static char* GetIntfName ()
	{
		return IID_IUserAuthClient;
	}
};


//��������ָ��
typedef CQIPtr<IUserAuthClient>	UserAuthClient;
typedef CQIPtr<IUACResource>	UACResource;
typedef CQIPtr<IUACPermission>	UACPermission;

//���崴�������������Լ���������
/*
**  �������������ڴ����ⲿӦ������Ľӿ�ʵ��.
*/

//����ɰ�� GetClassObjectMethod ����. ����ʹ�� PFNUACGETCLASSOBJECTMETHOD ����.
#ifndef UAC_GETCLASSOBJECTMETHOD
#define UAC_GETCLASSOBJECTMETHOD
typedef bool (*PFNUACGETCLASSOBJECTMETHOD)(const char *classname, IICSUnknown** ppUnk);
#endif

//��������Ǿɰ��. ����ʹ�� PFNUACGETCLASSOBJECTMETHOD ����.
#ifndef GETCLASSOBJECTMETHOD
#define GETCLASSOBJECTMETHOD
typedef bool (*GetClassObjectMethod)(const char *classname, IICSUnknown** ppUnk);
#endif

#ifndef MODEL_USERAUTH_CLIENT
#define MODEL_USERAUTH_CLIENT "userauthclient"
#endif

#ifndef METHOD_GETCLASSOBJECT
#define METHOD_GETCLASSOBJECT "GetClassObject"
#endif

#endif  /* __IUSERAUTHCLIENT_H_INCLUDED__ */
