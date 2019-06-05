/*
**++
**  模块名称:   USERAUTH - Client
**
**  文件名称:   iuserauthclient.h
**
**  文件描述:	定义了用户权限验证客户端模块(USERAUTHCLIENT)的APIs,
**				包含三个接口 IUACResource, IUACPermission, IUserAuthClient
**				的定义和一个对象创建函数 GetClassObject.
**
**  创建日期:   2006-12-14
**
**  修改履历:
**
**		2006-12-10  创建文件 [张妮].
**		2007-4-6    修改权限客户端访问接口,   改变ModifyUserPsw()方法的参数 [张妮].  
**		2008-10-24  添加getlastloginuser接口, 用来获得最后登陆的用户.
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


enum _UASRESULT			//权限管理服务器服结果.
{
	UAS_SUCCESS = 0,	//成功返回
	UAS_UNLOGIN,		//用户未登陆
	UAS_RELOGIN,		//重复登陆.
	UAS_NOUSER,			//用户名称不存在
	UAS_PWDERR,			//密码错误

	UAS_USERINSTOP,	    //用户停用
	UAS_USEROVERDUE,	//用户过期.
	UAS_USERLOCKED,     //用户被锁定.
	UAS_UNREGESTEDWS,   //未注册工作站.	
	UAS_NOPERMISSION,   //没有相应的权限.

	UAS_NOPERMISSION_U, //用户没有权限.
	UAS_NOPERMISSION_H, //工作站没有权限.
	UAS_NOPERM,         //资源、责任分区、固定权限不存在.
	UAS_MISFITOPER,     //操作权限不适用、 如读操作不适用于固定权限.
	//UAS_INVALIDVERSION, //服务器和客户端版本不一致.

	UAS_MINOR,          //非主服务器.
	UAS_DBERR,			//数据库错误, 尝试请求数据库服务不成功.
	UAS_UASERR,         //权限服务器响应失败
	UAS_ABNORMITY,      //服务器异常.
	UAS_PWDINSTOP,		//密码过期	18-06-03 by lxl
	UAS_PWDINT,			//修改初始密码 18-06-04 by lxl
	UAS_PINERROR,		//验证码错误 18-06-10 by lxl
	UAS_INVALIDVERSION, //服务器和客户端版本不一致.
};

enum _UACRESULT         //权限管理客户端服结果
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
	UAC_NOPERM			= UAS_NOPERM,         //12资源、责任分区、固定权限不存在.
	UAC_MISFITOPER		= UAS_MISFITOPER,     //13操作权限不适用、 如读操作不适用于固定权限.
	UAC_INVALIDVERSION  = UAS_INVALIDVERSION, //14服务器和客户端版本不一致.
	
	UAC_MAX_PARAMERR     = UAS_INVALIDVERSION, //14, 技术参数错误的最大号.
											   
	UAC_MINOR			 = UAS_MINOR,          //15
	UAC_UASERR			 = UAS_UASERR,		   //16权限服务器响应失败
	//17
	UAC_NOUAS			 = 18,				   //权限服务器未响应.  //18
	UAC_PARMERR,							   //参数不正确.				//19

	UAC_SENDERROR,							   //请求服务失败.				//20
	UAC_OVERTIME,							   //服务相应超时.				//21
	UAC_READMSGERR,							   //读取相应数据失败.			//22
	UAC_UNCMPERR,							   //数据压缩格式有误.			//23
	UAC_UNKOWNERR,							   //24
};

//权限类型:
enum _UA_PERMTYPE
{
	UAPT_RES,     //资源
	UAPT_AREA,    //责任分区.
	UAPT_SPERM,   //固定权限.
	UAPT_ALLTYPE, //所有类型.
	UAPT_NULL,    //无效类型.
};

//资源类型
enum _UA_RESTYPE
{
	UART_APP,	   //应用程序
	UART_VDFPAGE,  //组态页面.
	UART_URL,	   //WEB页面.
	UART_REPORT,   //报表.
	UART_ALLTYPE,  //所有类型.
};
enum _UA_USRCTORL
{
	UA_USERAUTH = 1,	//1 权限维护
	UA_MODEL,			//2：模型维护
	UA_UI,				//3: 界面组态
	UA_AI,				//4：人机运行界面
	UA_CONSOLE,			//5：控制台
	UA_CONTROL,			//6：启动/停止服务
	UA_AUDIT,			//7：安全审计
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
// IUACArea责任分区接口
/*
**  责任分区接口提供了访问责任分区实体各主要属性的方法.
*/
class IUACArea : public IICSUnknown
{
public:
	/*!功能:获得责任分区ID.
	* \参数 id (INOUT):责任分区ID.
	* \参数 size (IN):责任分区id长度.
	*/
	virtual void GetAreaID(char* id, int size) = 0;

	/*!功能:获得责任分区名称.
	* \参数 name (INOUT):责任分区名称.
	* \参数 size (IN):责任分区名称长度.
	*/
	virtual void GetAreaName(char* name, int size) = 0;

public:	
	static char* GetIntfName ()
	{
		return IID_IUACArea;
	}
};

// IUACAreaPerm资源接口
/*
**  资源访问接口提供了访问资源实体各主要属性的方法.
*/
class IUACAreaPerm : public IICSUnknown
{
public:
	/*!功能:获得责任分区ID.
	* \参数 id (INOUT):责任分区ID.
	* \参数 size (IN):责任分区id长度.
	*/
	virtual void GetAreaID(char* id, int size) = 0;

	/*!功能:获得责任分区名称.
	* \参数 name (INOUT):责任分区名称.
	* \参数 size (IN):责任分区名称长度.
	*/
	virtual void GetAreaName(char* name, int size) = 0;

	/*!功能:获得责任分区操作.
	* \参数 authmod (INOUT):责任分区操作方式.
	* \参数 size (IN):责任分区操作方式长度.
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
	/*!功能:获得固定权限ID.
	* \参数 id (INOUT):固定权限ID.
	* \参数 size (IN):固定权限id长度.
	*/
	virtual void GetSPermID(char* id, int size) = 0;

	/*!功能:获得固定权限名称.
	* \参数 name (INOUT):固定权限名称.
	* \参数 size (IN):固定权限名称长度.
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


// IUACResource资源接口
/*
**  资源访问接口提供了访问资源实体各主要属性的方法.
*/
class IUACResource : public IICSUnknown
{
public:

	/*!功能:获得资源ID.
	 *	\参数 id (INOUT):资源id.
	 *  \参数 size (IN):资源id长度.
	 */
	virtual void GetResID( char* id, int size ) = 0;

	/*!功能:获得资源名称.
	 *	\参数 name (INOUT):资源名称.
	 *  \参数 size (IN):资源名称长度.
	 */
	virtual void GetResName( char* name, int size ) = 0;

	/*!功能:获得资源类型信息.
	 *	\参数 type (INOUT):资源类型内容.
	 *  \参数 size (IN):资源类型长度.
	 */
	virtual void GetResType( char* type, int size ) = 0;

public:
	
	static char* GetIntfName ()
	{
		return IID_IUACResource;
	}

};

// IUACPermission权限接口.
/*
**  权限是一个二元组(<资源, 操作>),
**  权限访问接口提供了访问权限实体各主要属性的方法.
*/
class IUACPermission : public IICSUnknown
{
public:

	/*!功能:获得权限对应的资源.
	 *	\参数 ppRes (INOUT):当前权限对应的资源.
	 */
	virtual bool GetResource( IUACResource** ppRes ) = 0;

	/*!功能:获得权限对应的操作.
	 *	\参数 operation (INOUT):操作名称.
	 *  \参数 size (INOUT):操作名称长度.
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

// IUserAuthClient用户权限客户端访问接口
/*
**  客户端访问接口提供的方法处理各种用户权限验证请求.
*/
class IUserAuthClient : public IICSUnknown
{
public:
	/************************************************************************************************/
	/*界面访问接口，ntype表示权限类型参考_UA_USRCTORL												*/
	/*LogConsole = true时表示先连接服务器,如果失败则直接读取数据库									*/
	/*LogConsole = false时表示只连接服务器,非控制台程序通常应为false								*/
	/*IsDlg = true 表示需要登录窗口，IPadress,UsrName,pwd等参数为传出参数							*/
	/*IsDlg = false表示不需要登录窗口，UsrName,pwd等参数为传入参数,LogConsole，IPadress参数无效		*/
	/*IPadress 客户端所在机器IP,UsrName，登录账号，pwd 登录密码										*/				
	/*返回值 成功UAC_SUCCESS，失败UAC_UNLOGIN														*/		
	/************************************************************************************************/
	virtual int LogWithWindow(int ntype,bool LogConsole,bool IsDlg,std::string &IPadress,std::string &UsrName,std::string &pwd) = 0;
	/*!功能: 登录外部客户系统.
	 *	\参数 psUserId (IN):用户ID.
	 *  \参数 psPassword (IN):密码.
	 *  \返回值:
	 *       UAC_SUCCESS( = 0),本次登录被接受;
	 *  该接口被弃用 lxl 18-06-07
	 
	 */
	virtual int LogIn ( const char* psUserId, 
		                 const char* psPassword ) = 0;

	/*!功能:注销对外部客户系统的本次登录.
	 *	\参数 psUserId (IN):欲注销登录的用户ID.
	 *  \返回值:
	 *       UAC_SUCCESS( = 0),	用户的注销请求被接受;
	 *       other,				用户的注销请求无法被处理.
	 */
	virtual int LogOut ( const char* psUserId ) = 0;

	/*!功能:验证用户.即:检验用户和密码是否正确.
	 *	\参数 psUserId (IN):用户ID.
	 *  \参数 psPassword (IN):密码.
	 *  \返回值:
	 *       UAC_SUCCESS( = 0),用户验证成功,即用户是外部客户系统的合法使用者;
	 *       other,			   用户验证失败,即用户对外部客户系统来说是非法的.
	 */
	virtual int ValidateUser (const char* psUserId, 
		                      const char* psPassword ) = 0;

	/*!功能:修改用户密码.
	 *	\参数 psUserId (IN):用户ID.
	 *  \参数 psOldPassword (IN):旧密码.
	 *  \参数 psNewPassword (IN):新密码.
	 *  \返回值:
	 *       UAC_SUCCESS( = 0),修改用户密码成功;
	 *       other,			   修改用户密码失败.
	 */
	virtual int ModifyUserPsw ( const char* psUserId, 
		                         const char* psOldPassword, 
		                         const char* psNewPassword ) = 0;

	/*!功能:验证用户权限.具体地说,用户对某一资源是否可以进行指定的操作.
	 *	\参数 psUserId (IN):用户ID.
	 *  \参数 psResId (IN):资源id,表示欲验证的资源.
	 *  \参数 psOperation (IN):指某一操作.
	 *  \返回值:
	 *       UAC_SUCCESS( = 0),用户对给定资源可以进行指定的操作;
	 *       other,			   用户对给定资源不能进行指定的操作.
	 */
	/*virtual int ValidateUserPerm (const char* psUserId,
		                          const char* pResId,
								  const char* psOperation, bool bIncArea = true) = 0;*/
	virtual int ValidateUserPerm (const char* psUserId,
		                          const char* pResId,
								  const char* psOperation) = 0;

	/*!功能:验证用户是否具有与某一资源相关的权限.
	 *	\参数 psUserId (IN):用户ID.
	 *  \参数 psResId (IN):资源id,表示欲验证的资源实例.
	 *  \返回值:
	 *       UAC_SUCCESS( = 0),用户具有该资源的相关权限;
	 *       other,			   用户不具有该资源的任何权限,即用户不能对该资源进行任何操作.
	 */
	/*virtual int ValidateResource ( const char* psUserId,
		                            const char* pResId, bool bIncArea = true) = 0;*/
	virtual int ValidateResource ( const char* psUserId,
		                            const char* pResId) = 0;
	

	/*!功能:列出用户的所有权限.权限是一个二元组(<资源, 操作>).
	 *  \参数 psUserId (IN):用户ID.
	 *  \参数 ppPerms (INOUT):查找到的该用户所有权限列表.
	 *  \返回值: 
	 *       UAC_SUCCESS( = 0), 成功
	 *		 other,				失败
	 */
/*	virtual int ListPermsByUser ( const char* psUserId,
								   IICSEnum** ppPerms, bool bIncArea = true) = 0;*/
	virtual int ListPermsByUser ( const char* psUserId,
								   IICSEnum** ppPerms) = 0;
	
	/*!功能:列出系统中所有的资源.
	 *	\参数 ppReses (INOUT):系统中所有资源的列表.
	 *  \返回值:
	 *       UAC_SUCCESS( = 0), 成功
	 *		 other,				失败
	 */
	virtual int ListAllResource ( IICSEnum** ppReses ) = 0;

	/*!功能:列出用户在系统中拥有的给定类型的全部资源.
	 *	\参数 psUserId (IN):用户ID.
	 *  \参数 psResType (IN):欲查询的资源类型.
	 *  \参数 ppReses (INOUT):满足条件的所有资源的列表.
	 *  \返回值:
	 *       UAC_SUCCESS( = 0), 成功
	 *		 other,				失败
	 */
	/*virtual int ListUserResourceByType ( const char* psUserId,
		                                  const char* psResType,
										  IICSEnum** ppReses, bool bIncArea = true) = 0;*/

	virtual int ListUserResourceByType ( const char* psUserId,
		                                  const char* psResType,
										  IICSEnum** ppReses) = 0;

	/*!功能:列出用户拥有的给定资源的全部直接下级资源.
	 *	\参数 psUserId (IN):用户ID.
	 *  \参数 psParentResId (IN):资源id,表示欲查询其下级的资源.
	 *  \参数 ppReses (INOUT):满足条件的所有资源的列表.
	 *  \返回值:
	 *       UAC_SUCCESS( = 0), 成功
	 *		 other,				失败
	 */
	/*virtual int ListUserAllSubResource ( const char* psUserId,
										  const char* psParentResId,
										  IICSEnum** ppReses, bool bIncArea = true) = 0;*/
	virtual int ListUserAllSubResource ( const char* psUserId,
										  const char* psParentResId,
										  IICSEnum** ppReses) = 0;

	/*!功能:列出用户拥有的给定资源的指定类型的全部直接下级资源.
	 *	\参数 psUserId (IN):用户ID.
	 *  \参数 psParentResId (IN):资源id,表示欲查询其下级的资源.
	 *  \参数 psResType (IN):欲查询的资源类型.
	 *  \参数 ppReses (INOUT):满足条件的所有资源的列表.
	 *  \返回值:
	 *       UAC_SUCCESS( = 0), 成功
	 *		 other,				失败
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
	/*!功能:列出某种资源的直接下属资源.返回对象中的上级资源和下级资源属性无效.
	 *  \参数 psParentResId (IN):资源id,表示欲查询其下级的资源.
	 *  \参数 ppReses (INOUT):满足条件的所有资源的列表.
	 *  \返回值:
	 *       UAC_SUCCESS( = 0), 成功
	 *		 other,				失败
	 */
	virtual int ListAllSubResource ( const char* psParentResId,
									  IICSEnum** ppReses) = 0;

	/*!功能:获得某资源的某类型的直接下级资源.返回对象中的上级资源和下级资源属性无效.
	 *  \参数 psParentResId (IN):资源id,表示欲查询其下级的资源.
	 *  \参数 psResType (IN):欲查询的资源类型.
	 *  \参数 ppReses (INOUT):满足条件的所有资源的列表.
	 *  \返回值:
	 *       UAC_SUCCESS( = 0), 成功
	 *		 other,				失败
	 */
	virtual int ListSubResourceByType ( const char* psParentResId,
										 const char* psResType,
									     IICSEnum** ppReses) = 0;
	
	/*! 功能:验证某一固定权限
	 *  \参数 szUserID (IN):	用户ID.
	 *  \参数 szSPermID (IN):   固定权限ID.
	 *  \返回值:
	 *       UAC_SUCCESS( = 0), 有权限.
	 *		 UAC_NOPERMISSION(= 10), 没有权限.
	 *		 UAC_NOPERMISSION_U(= 11),  用户没有权限.
	 *		 UAC_NOPERMISSION_H(= 12),	工作站没有权限.
	 *		 返回其他值表示验证失败.
	 */
	virtual int ValidateSPerm(const char *szUserID, const char *szSPermID) = 0;

	/*! 功能:验证某一责任分区
	 *  \参数 szUserID (IN):	用户ID.
	 *  \参数 szSPermID (IN):   责任分区ID.
	 *  \返回值:
	 *       UAC_SUCCESS( = 0), 有权限.
	 *		 UAC_NOPERMISSION(= 10), 没有权限.
	 *		 UAC_NOPERMISSION_U(= 11),  用户没有权限.
	 *		 UAC_NOPERMISSION_H(= 12),	工作站没有权限.
	 *		 返回其他值表示验证失败.
	 */
	virtual int ValidateArea(const char *szUserID, const char *szSAreaID, const char *szOperation) = 0;

	/*! 功能:验证某一责任分区
	 *  \参数 szUserID (IN):	用户ID.
	 *  \参数 szSPermID (IN):   责任分区ID.
	 *  \返回值:
	 *       UAC_SUCCESS( = 0), 成功.
	 *		 返回其他值表示失败.
	*/
	virtual int ListAllArea(IICSEnum** ppAreas) = 0;


	/*! 功能:列出用户的所有责任分区权限, 权限是一个二元组(<责任分区, 操作>).
	 *  \参数 psUser (IN):	  用户ID.
	 *  \参数 ppAreaOper (OUT):   查找到的该用户所有责任分区权限列表.
	 *  \返回值:
	 *       UAC_SUCCESS( = 0), 成功.
	 *		 返回其他值表示失败.
	*/
	virtual int ListAreaPermsByUser(const char* psUser, IICSEnum** ppAreaOper) = 0;

	/*! 功能 : 列出用户的所有责任分区.
	 *  \参数  psUser (IN):	  用户ID.
	 *  \参数  ppAreas (OUT):   查找到的该用户所有责任分区列表.
	 *  \返回值:
	 *       UAC_SUCCESS( = 0), 成功.
	 *		 返回其他值表示失败.
	*/
	virtual int ListAreasByUser(const char* psUser, IICSEnum** ppAreas) = 0;

	/*! 功能 : 获得最后登陆的用户ID.
	 *  \参数  pszUser (OUT):	  接收用户ID的缓冲地址, 这个参数为NULL(0)时, GetLastLoginUser将返回用户ID的长度.
	 *  \参数  nUserLen (INT):    接收用户ID的缓冲区长度地址.
	 *  \返回值:
	 *				如果pszUser != NULL时, 返回UAC_SUCCESS表示成功,
	 *				如果pszUser == NULL时, 将返回用户ID的长度, 如果这时没有用户登陆将返回 0.
	 *				返回其他值表示失败.
	 *
	 *	\注意 :		userID最大长度 由MAX_USERID_LEN定义
	 *				如果用户已经注销也将返回他的ID.
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
	/*! 功能 :		UpdateUAS函数将更新权限服务器(UAS)中的数据.
	 *				这个功能目前只被权限管理工具(usercfg)使用.
	 *				其他模块暂时不要使用.
	 */	
	virtual int UpdateUAS() = 0;


	virtual const char *UaErrorText(int nUaRet) = 0;

	/*! 功能:枚举用户
	 *  \参数 ppUsers (OUT):	接收对象, 参考 IUACUser.
	 *  \参数 nPermType (IN):   相关权限类型,  资源\责任分区\固定权限
	 *	\参数 szPermId (IN):    相关权限Id.
	 *	\参数 szOperId (IN):    相关操作Id.    "R"\"W"\"E"
	 *  \返回值:
	 *       UAC_SUCCESS( = 0), 成功.
	 *		 返回其他值表示失败.
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


//定义智能指针
typedef CQIPtr<IUserAuthClient>	UserAuthClient;
typedef CQIPtr<IUACResource>	UACResource;
typedef CQIPtr<IUACPermission>	UACPermission;

//定义创建对象函数类型以及函数名称
/*
**  创建对象函数用于创建外部应用所需的接口实例.
*/

//代替旧版的 GetClassObjectMethod 定义. 建议使用 PFNUACGETCLASSOBJECTMETHOD 代替.
#ifndef UAC_GETCLASSOBJECTMETHOD
#define UAC_GETCLASSOBJECTMETHOD
typedef bool (*PFNUACGETCLASSOBJECTMETHOD)(const char *classname, IICSUnknown** ppUnk);
#endif

//这个定义是旧版的. 建议使用 PFNUACGETCLASSOBJECTMETHOD 代替.
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
