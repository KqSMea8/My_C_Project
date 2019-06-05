#ifndef IRAWCTRL_H
#define IRAWCTRL_H

#include "./scadactrl_defines.h"
#include "../icsunknown.h"

typedef struct {
	typedef enum {	/* 控制操作枚举 */
		UNKNOWN,
		SELECT = 1,		/* 选择令 */
		EXEC,			/* 执行令 */
		CANCEL			/* 撤销令 */
	} CMDType;

	typedef enum {	/* 控制类枚举 */
		UNCONTROL,      /* 非控制类 */
		MAINLOGIC,      /* 主逻辑控制类 */
		CALLDATA,		/* 召测数据控制类 */
		SYSRESET,		/* 系统复归控制类 */
		SETTING,        /* 定值下发类 */ // psk 2011-10-26
	} CLSType;
	
	typedef enum {	/* IRawCtrl::ErrNo() 返回值定义 */
		ECSRVBUSY = 1,	/* 系统繁忙，无法处理当前请求 */
		ECNETLOST,		/* 无法连接服务端 */
		ECALREADY,		/* 前一次操作尚未完成，请结束后再操作 */
		ECSYS,			/* 系统错误 */
		ECBADID,		/* 控点配置有误或非法 */
		ECBADVAL,		/* 控制值非法 */
		ECUNEXPECTCMD,	/* 控点请求的命令不合法 */
		ECPERM,			/* 用户无权限 */
		ECFAIL,			/* 失败 */
		ECTMOUT			/* 超时 */
	} ErrorCode;
	
	typedef enum {
		SUCCESS = 0,
		FAILED,
		TIMEOUT
	} CMDRET;
} st_rawctrl;

/* 控制回调接口 */
class ICtrlReturn
{
public:
	/* !注意该方法应该快速返回，切勿堵塞 */
	virtual void OnRecv( st_rawctrl::CMDType t, st_rawctrl::CMDRET ret ) = 0;
};

/* 控制下发接口 */
class IRawCtrl : public IICSUnknown
{
public:
    static const char* GetIntfName() { return IID_IRAWCTRL; } 

	/* 设置操作员、密码 */
	virtual void SetUser(const char* name, const char* passwd) = 0;

	/* 获取操作员 */
	virtual const char* GetUser() = 0;

	/*
	遥控下发选择令
		ctrlID -- 遥控ID
		value -- 0 - 分/切；1 - 合/投；
	返回 0 - 成功；-1 - 失败；
	注：如果控点为直控，则返回失败。
	 */
	virtual int Telectrl_select(int ctrlID, int value) = 0;

	/* 
	遥控下发执行令
		ctrlID -- 遥控ID
		value -- 0 - 分/切；1 - 合/投；
		bMsc -- false-不注册消息中心；true -- 注册消息中心
	返回 0 - 成功；-1 - 失败；
	 */
	virtual int Telectrl_exec(int ctrlID, int value,bool bMsc = false,bool bResult = true) = 0;

	/*
	遥调下发选择令
		ctrlID -- 遥调ID
		value -- 0 - 停；1 - 降；2 - 升；
	返回 0 - 成功；-1 - 失败；
	注：如果控点为直控，则返回失败。
	 */
	virtual int Teleadjust_select(int ctrlID, int value) = 0;



	virtual int Teleadjust_exec(int ctrlID, double value,bool bMsc = false,bool bResult = true) = 0;

	/* 
	下发撤销令
		ctrlID -- 控点ID
	返回 0 - 成功；-1 - 失败；
	 */
	virtual int Cancel(int ctrlID) = 0;

	/* 下发模拟量型选择令 (暂未实现) */
	virtual int DBL_select(int ctrlID, double value) = 0;

	/* 下发模拟量型执行令 (暂未实现) */
	virtual int DBL_exec(int ctrlID, double value) = 0;

	/* 获取错误编号，参考st_rawctrl::ErrorCode */
	virtual int ErrNo() = 0;

	/* 获取错误字符描述 */
	virtual const char* ErrStr() = 0;

	/*
	 注册回调接口
	 返回:
		上次注册的回调接口
	 */
	virtual ICtrlReturn* RegisterCallBack(ICtrlReturn* ptr) = 0;

	/* 
	遥信人工置数
		sttsID -- 遥信量ID
	返回 0 - 成功；-1 - 失败；
	 */
	virtual int ManualSetStatus(int sttsID, int value) = 0;

	/* 
	遥测人工置数
		anlgID -- 遥测量ID
	返回 0 - 成功；-1 - 失败；
	 */
	virtual int ManualSetAnalog(int anlgID, double value) = 0;

	/* 
	撤消遥信人工置数标志
		sttsID -- 遥信量ID
	返回 0 - 成功；-1 - 失败；
	 */
	virtual int CancelStatusManualSet(int sttsID) = 0;

	/* 
	撤消遥测人工置数标志
		anlgID -- 遥测量ID
	返回 0 - 成功；-1 - 失败；
	 */
	virtual int CancelAnalogManualSet(int anlgID) = 0;

};

#endif /* IRAWCTRL_H */
