/**********************************************************************
文 件 名:		OperateIntf.h
描    述:		定义操作接口
修改记录:       created by jianshend on 2005-07-15
                add method name(exported by module OperateEnum)
					------Modified by jianshen on 2005-08-23
				add operate serialize
					------Modified by jianshen on 2005-12-15
**********************************************************************/

#ifndef _OPERATEINTF__H_
#define _OPERATEINTF__H_

#include "objsintf.h"

#define IID_IICSOperateType		"IICSOperateType"
#define IID_IICSOperate			"IICSOperate"

class IICSOperateType;
class IICSOperate;

//操作类型接口
class IICSOperateType : public IICSUnknown
{
public:
	//获取操作名称
	virtual void GetName(char* name, int size)=0;

	//获取操作的描述
	virtual void GetCaption(char* caption, int size, IICSRtdbObject* pObject = 0)=0;

	//获取操作相关对象的类型信息
	virtual void GetObjTypeInfo(IICSTypeInfo** pTypeInfo)=0;

	//获取实现该操作组件的模块名称
	virtual void GetOperateModule(char* module, int size)=0;

	//获取操作组件的类名称
	virtual void GetOperateClassName(char* name, int size)=0;

	/*
	【功  能】	判断对于一个对象该操作可执行
	【参  数】	无
	【返回值】	返回是否可执行
	【说  明】	如果一种操作类型对应某个对象是否可执行                                                                                                                                                                                                                                                                                                                       
	*/
	virtual bool IsEnable(IICSRtdbObject* pObject)=0;

	/*
	【功  能】	判断对于一个对象该操作类型是否又效
	【参  数】	无
	【返回值】	返回是否又效
	【说  明】	1,如果操作类型对应一个对象无效则该对象的右键菜单不应显示有该类型操作的菜单项
				2,操作对某一个对象可执行则必定对该对象有效,但是反过来则不一定
	*/
	virtual bool IsValid(IICSRtdbObject* pObject)=0;
	virtual bool CreateOperate(IICSRtdbObject* pObject, IICSOperate** pOperate)=0;
	virtual bool CanOperate(IUserObject* pUser)=0;
public:
	static	char* GetIntfName(){return IID_IICSOperateType;};
};

//操作模式:
//OPMD_NORMAL:	普通模式	-----	弹出参数输入界面,预检查,错误提示,执行所有步骤
//OPMD_QUIET :	不提示模式	-----	不弹出参数输入界面,预检查,错误不提示,忽略需要人工干预步骤
//注:	1.有的操作的参数必须自己弹出界面的情况下OPMD_QUIET不起作用
//		2.完全实现OPMD_QUIET模式需要为操作提供参数类型信息接口以及获取设置参数接口[未实现]
enum OPERATEMODE{OPMD_NORMAL, OPMD_QUIET , OPMD_YK};

class IICSOperate : public IICSUnknown
{
public:
	//获取操作相关对象
	virtual void GetObject(IICSRtdbObject** ppObject)=0;

	//设置操作相关对象
	virtual void SetObject(IICSRtdbObject* pObject)=0;

	//获取操作员
	virtual void GetUser(IICSRtdbObject** ppUser)=0;

	//设置操作员
	virtual void SetUser(IICSRtdbObject* pUser)=0;

	//获取操作描述
	virtual void GetActDesc(char* desc, int size)=0;

	//设置操作描述
	virtual void SetActDesc(char* desc)=0;

	/*
	【功  能】	输入操作需要的相关参数
	【参  数】	无
	【返回值】	返回成功失败
	【说  明】	调用此函数,操作组件将自己弹出界面(需要时)提示操作员输入操作相关的参数
	*/
	virtual bool InputOperate()=0;

	/*
	【功  能】	操作预处理
	【参  数】	无
	【返回值】	返回成功失败
	【说  明】	此函数将在客户端对将要进行的操作进行预先判断,如果该操作由于什么情况下不能执行,
				组件将会弹出对话框提示不能进行的原因,如果成功则可以对该操作进行提交
	*/
	virtual bool Preprocess()=0;

	/*
	【功  能】	提交操作
	【参  数】	无
	【返回值】	返回成功失败
	【说  明】	此函数将会把该操作提交给应用服务器,并显示界面提示操作员当前的操作状态
				(例如:显示操作的进度条以及当前的操作步骤)
	*/
	virtual bool Commit()=0;

	/*
	【功  能】	判断操作是否完成
	【参  数】	无
	【返回值】	返回成功失败
	【说  明】	使用此函数判断是否可以进行下一步操作
	*/
	virtual bool IsComplete()=0;
	
	/*
	【功  能】	判断操作是否成功
	【参  数】	无
	【返回值】	返回成功失败
	*/
	virtual bool IsSuccess()=0;

	//
	virtual void GetOperateType(IICSOperateType** ppType)=0;

	//由服务器端模块(OperateService)调用,客户端不调用
	virtual bool Execute()=0;

	//设置操作模式
	virtual void SetMode(OPERATEMODE opMode)=0;
	//获取错误码
	virtual int GetErrorCode()=0;
	//根据错误码获取错误描述
	virtual bool GetErrorDesc(int errorcode, char* buf, int bufsize)=0;
	//设置是否强制用户验证,默认不强制用户输入
	virtual bool SetUserCheck(bool b)=0;
public:
	static	char* GetIntfName(){return IID_IICSOperate;};
};

#define  IID_IFacelessOperate	"ifacelessoperate"

class IFacelessOperate : public IICSOperate
{
public:
	virtual void Terminate() = 0;
};

//定义操作枚举模块名称
#define MODULE_OPERATEENUM		"OperateEnum"
#define MODULE_OPRERATECOMPS	"OperateComps"
#define MODULE_ELEMCTRLCLIENT	"EleCtrlClient"

//定义共享库OperateEnum导出函数的名称
#define METHOD_REGISTEROPTYPE      "RegisterOperateType"
#define METHOD_UNREGISTEROPTYPE    "UnregisterOperateType"
#define METHOD_QUERYOPSBYTYPE      "QueryOperateByTypeInfo"
#define METHOD_QUERYOPSBYOBJ       "QueryOperateByObject"
#define METHOD_CREATEOPERTETYPE    "CreateOperateType"

/*
【说  明】	1,定义注册操作类型的函数指针类型
			2,该函数由共享库OperateEnum导出,共享库中函数名为RegisterOperateType
			3,该导出函数由业务逻辑处理模块调用,客户端各模块无需调用
*/
typedef	bool (*RegisterOperateMethod)(IICSOperateType* pType);

/*
【说  明】	1,定义注消操作类型的函数指针类型
			2,该函数由共享库OperateEnum导出,共享库中函数名为UnregisterOperateType
			3,该导出函数由业务逻辑处理模块调用,客户端各模块无需调用
*/
typedef bool (*UnregisterOperateMethod)(IICSOperateType* pType);

/*
【说  明】	1,定义查询操作类型的函数指针类型
			2,该函数由共享库OperateEnum导出,共享库中函数名为QueryOperateByTypeInfo
			3,该导出函数由客户端调用
			4,	pTypeInfo[in]		操作相关对象的类型信息
				ppEnum[out]			返回对象类型相关操作的枚举接口		
*/
typedef bool (*QueryOperateByTypeMethod)(IICSTypeInfo* pTypeInfo, IICSEnum** ppEnum);

/*
【说  明】	1,定义查询操作类型的函数指针类型
			2,该函数由共享库OperateEnum导出,共享库中函数名为QueryOperateByObject
			3,该导出函数由客户端调用
			4,	pObject[in]			操作相关对象接口
				ppEnum[out]			返回对象相关操作的枚举接口		
*/
typedef bool (*QueryOperateByObjectMethod)(IICSRtdbObject* pObject, IICSEnum** ppEnum);

typedef bool (*CreateOperateTypeMethod)(const char* TypeName, IICSOperateType** ppType);


#define METHOD_COMMITOPERATE	"CommitOperate"
typedef bool (*CommitOperateMethod)(IICSOperate* pOperate);
#define MODULE_OPERATECLIENT	"OperateClient"

//定义智能指针
typedef CQIPtr<IICSOperateType> ICSOperateType;
typedef CQIPtr<IICSOperate> ICSOperate;

#endif

