#ifndef _PROTECTREPORTINTF_H_
#define _PROTECTREPORTINTF_H_

#include "objsintf.h"
typedef unsigned char BYTE;

#define IID_ICallReport		    "ICallProtReport"   //动作报告
#define IID_IProtectSinker      "IProtectSinker"
#define IID_IProtectObject      "IProtectObject"
#define IID_ISave               "ISave"
#define IID_IGetReport          "IGetReport"
#define IID_IProtectClient      "IProtectClient"
#define OPCLSID_CallReport		"callreport"      //动作报告
#define OPCLSID_ProtectObject	"protectobject"      //动作报告
#define OPCLSID_ProtectProcess  "protectprocess"


#define OPCLSID_CallEvent       "callevent"         //自检报告和运行事件报告
#define IID_ICallEvent          "ICallEventReport"  //自检报告和运行事件报告
/*
	[文  件]	定义保护动作报告相关接口
*/
#define TASK_TYPE_PROTECT		"protect"			// 业务类型－保护动作报告
#define MODULE_PROTOBJECT		"protectobject"
#define	MODULE_PROTCLIENT		"protectclient"


// 定义故障性质
typedef enum
{	
	pt_permanent = 0,			// 永久性故障
	pt_instant,					// 瞬时性故障
	pt_dimness,					// 故障性质不清楚
} PROTECT_TYPE;

static char* PROTECT_TYPE_DESC[] = { "永久性故障", "瞬时性故障", "故障性质不清楚" };

// 定义故障相别
typedef enum
{
	pp_dimness = 0,	pp_w1,	pp_w2,	// 故障相别不确定
	pp_a,		pp_w4,	pp_b,	// 单相接地故障
	pp_ab,		pp_abn,	pp_w8,	// 相间故障
	pp_c,		pp_ca,	pp_can,	// 相间接地故障
 	pp_bc,		pp_bcn,	pp_abc,	// 三相故障
	pp_abcn,					
	
} PROTECT_PHASE;

static char* PROTECT_PHASE_DESC[] = {
		"",					"",					"",
		"A相保护动作",		"",					"B相保护动作",		
		"AB故障",			"ABN故障",			"",		
		"C相保护动作",		"CA相保护动作",		"CAN故障",
		"BC相保护动作",		"BCN故障",			"ABC三相保护动作",		
		"ABCN故障"
};

/*
static char* PROTECT_PHASE_DESC[] = {
	"A相保护动作",		"B相保护动作",	"C相保护动作",
	"AN故障",			"BN故障",		"CN故障",
	"AB相保护动作",		"BC相保护动作", "CA相保护动作",
	"ABN故障",			"BCN故障",		"CAN故障",
	"ABC三相保护动作",	"ABCN故障",
	"故障相别不确定" 
};
*/

// 定义调装置动作报告返回类型
typedef enum
{	
  	pt_has = 0,		         	// 有此故障报告
		pt_no,					// 无此故障报告
		pt_end,					// 传输结束
} PROTECT_RESULT;

static char* PROTECT_RESULT_DESC[] = { "有此故障报告", "无此故障报告", "传输结束" };

// 定义调装置动作报告返回类型
typedef enum
{	

	pt_nouse = 0,                    // 不用
	    pt_return, 		         	// 返回
		pt_start,					// 启动
		pt_unused,					// 不用
} ACTION_STATE;

static char* ACTION_STATE_DESC[] = {"不用", "返回", "启动", "不用" };

/*
	保护动作报告－对象接口
*/
class IProtectObject : public IICSUnknown
{
public:
	virtual int GetCpuNo() = 0;							// CPU号	
	virtual int GetSinNo() = 0;							// 故障报告序号
	virtual int GetFaultOrder() = 0;						// 故障序号 	
		 
	virtual int GetStationId() = 0;                        // 厂站ID
	virtual int GetBayId() = 0;                            // 间隔ID
	virtual int GetDevId() = 0;							// 装置ID
	
	virtual void GetDevName(char* name, int size) = 0;		// 装置名称	

	virtual int GetSoeId() = 0;                            //SoeID
	virtual void GetProtName(char* name, int size) = 0;		// 动作元件名称
	
	virtual ACTION_STATE GetActionState() = 0;				// 动作状态
    virtual void GetActionDesc(char* desc, int size) = 0;	// 动作状态描述
	
	virtual PROTECT_PHASE GetProtectPhase() = 0;            //故障相别
    virtual void GetPhaseDesc(char* desc, int size) = 0;	// 分相保护动作描述
	
	virtual PROTECT_TYPE  GetProtectType() = 0;             //故障性质
	virtual void GetTypeDesc(char* desc, int size) = 0;		// 故障性质描述
	
	virtual int GetRelativeTime() = 0;						// 保护动作相对时间
	virtual double GetStartUpTime() = 0;					// 启动时间	
	    
	virtual int GetValueCount() = 0;						// 故障值数目
	virtual void GetValueNameByIndex(int index, char* name, int size) = 0;	// 故障值名称
	virtual double GetValueByIndex(int index) = 0;			// 故障值数值
	
	//根据soeid取得动作元件名称
	virtual void GetParaNameBySoe(int soe) = 0;

    virtual int GetTimeOut() = 0;
	virtual void SetTimeOut(int t) = 0;

	virtual void SetStationId(int id ) = 0;                        // 厂站ID
	virtual void SetBayId(int id) = 0;                            // 间隔ID
	virtual void SetDevId(int value) = 0;					// 装置ID
	virtual void SetCpuNo(int value) = 0;					// CPU号
	virtual void SetSinNo(int value) = 0;                  //故障报告序号	
	virtual void SetSoeId(int value,bool b) = 0;
	
	virtual void AddValueName(int index,char* sValueName) = 0;
	virtual void SetDevName(char* name) = 0;
	virtual void SetProtectName(char* name) = 0;
	
	virtual void SetFaultOrder(int value) = 0;				// 故障序号	
	virtual void SetRelativeTime(int time) = 0;			// 保护动作相对时间
	virtual void SetStartUpTime(double time) = 0;			// 启动时间	
	virtual void SetActionState(ACTION_STATE state) = 0;    // 动作状态
	virtual void SetType(PROTECT_TYPE type) = 0;			// 保护动作故障性质
	virtual void SetPhase(PROTECT_PHASE phase) = 0;			// 故障相别	
	 
	virtual void AddProtValue(int index, double value) = 0;	// 设置保护动作故障值
};

/*
	保护动作报告－消费者接口（由HMI实现）
*/
class IProtectConsumer : public IICSUnknown
{
public:
	//HMI接收动作报告
	virtual void OnProtComing(IProtectObject* pProtObject) = 0;
};

/*
	保护动作报告－客户端接口
*/
class IProtectClient : public IICSUnknown
{
public:
	// 向HMI或者存储模块，提交保护动作对象
	virtual void PostProtect(IProtectObject* pProtObject) = 0;	
	//注册/反注册消费者接口, bLocal=true表示本地服务程序
	virtual bool RegisterConsumer(IProtectConsumer* pConsumer/*, bool bLocal = false*/) = 0;
	virtual bool UnRegisterConsumer(IProtectConsumer* pConsumer) = 0;
};

/*
	保护动作报告－业务客户端与服务端交互接口
*/
class ICallProtReport : public IICSUnknown
{
public:
	virtual void SetDevId(int value) = 0;					// 装置ID
	virtual void SetCpuNo(int value) = 0;					// CPU号
	virtual void SetSinNo(int value) = 0;                  //故障报告序号

    virtual int GetDevId() = 0;
	virtual int GetCpuNo() = 0;
	virtual int GetSinNo() = 0;

	virtual int GetProtects(IICSEnum** ppEnum)=0;
	virtual void AddProtect(IProtectObject* pProtectObject) = 0;

	virtual void SetProtectInput(IProtectObject* ProtectObject) = 0;
	virtual void GetProtectObject(IProtectObject** ppProtObject) = 0;
};

#define SQL_LONG_PARAM_IS_NOT_USE 0X0FFFFFFF
//读取动作报告接口（数据库访问模块实现）
class IGetReport : public IICSUnknown
{
public:
	//根据间隔，装置，查询某段时间内的动作报告
	/*!
	\brief 根据间隔，装置，查询某段时间内的动作报告
	@param[in]    starttime     起始时间，使用 CDateTime 
	@param[in]    EndTime       结束时间，使用 CDateTime 
	@param[out]   ppObjectList  结果对象集
	@param[in]    Bay           间隔号
	@param[in]    nDev          装置号
	*/	
	virtual void GetReport(double StartTime, double EndTime,long Bay,
		long nDev, IICSEnum** ppObjectList) = 0; 
	
	
		/*!
		\brief 根据 时间段，间隔号，装置号，cpu 号 等条件检索数据
	       除了时间段外，间隔号，装置号，cpu 号 等参数都是可选的，
		   如果不设置某个参数（就是该参数使用默认值），则该参数不在检索中生效
		   @param[in]    starttime     起始时间，使用 CDateTime 
		   @param[in]    EndTime       结束时间，使用 CDateTime 
		   @param[out]   ppObjectList  结果对象集
		   @param[in]    nDev          装置号 
		   @param[in]    CpuNo         CPU 号 
		   @param[in]    SqlWhere      补充检索条件，示例：cpuno < 20 and devid > 2000
		   @param[in]    GetRecFrom    从该位置开始获取记录 
		   @param[in]    GetRecNumber  获取指定数量的记录 
		   \return       返回值为符合检索条件的记录总数，查询失败返回 -1
	*/
	/*Created by 张展国 2008/01/16 */
	virtual int GetReport(double StartTime, double EndTime,IICSEnum** ppObjectList , 
		long Bay = SQL_LONG_PARAM_IS_NOT_USE, long nDev = SQL_LONG_PARAM_IS_NOT_USE, 
		long CpuNo = SQL_LONG_PARAM_IS_NOT_USE,	const char * SqlWhere="", 
		long GetRecFrom = 0 , long GetRecNumber = SQL_LONG_PARAM_IS_NOT_USE ) = 0; 
};


/*
	调运行事件报告和自检报告－业务客户端与服务端交互接口
*/
class ICallEventReport : public IICSUnknown
{
public:
	virtual void SetDevId(int value) = 0;					// 装置ID
	virtual void SetSinNo(int value) = 0;                  //事件报告和自检报告报告序号

    virtual int GetDevId() = 0;
	virtual int GetSinNo() = 0;

	virtual int GetEvents(IICSEnum** ppEnum)=0;
	virtual void AddEvent(IProtectObject* pProtectObject) = 0;

};




#define	MODULE_PROTECTCTRL	"ProtectCtrlClient"
#define MODULE_PROTECTCOMPS	"ProtectComps"



#endif