/*******************************************************
 * vqcforwardtypes.h -- VQC、CVT转发数据类型定义
 * 
 * date: 2008.12.26 hongkeqin@xjgc.com
 * revised:
		增加定值数据流定义: fwdSetting 2009.05.12
		添加总召命令定义：tCMDTYPE::CALLDATA 2009.06.09
		CVT数据定义 2009.10.15
 *******************************************************/

#ifndef _VQCFORWARDTYPES_H_
#define _VQCFORWARDTYPES_H_

struct VQC_T
{
	/* 指令类型 */
	typedef enum {
		SELCMD = 0,		// 选择令
		EXECMD = 1,		// 执行令
		CANCLCMD,		// 撤销令
		FINCMD,			// 结束令[在发送执行令结果后，发送]
		CALLDATA		// 总召令
	} tCMDTYPE;
	
	/* 返回值 */
	typedef enum {
		SUCCESS = 0,	// 成功
		FAILED			// 失败

	} tRETVAL;
	
};

/* 业务类型枚举 */
typedef enum {
	GRP_NONE = 0,
	GRP_VQC = 1,
	GRP_CVT = 2,
	GRP_SM = 3

} TASKGRP;

/*
 * 数据流类型及格式
 */
typedef enum {
	fwdNone = 0, 
	/* VQC 相关 */
	fwdIdVarTime,	//遥信、遥测转发格式： uchar(fwdIdVarTime) | int (id) | QVariant (value) | double (timestamp)
						///，方向：vqc->远动;

	fwdSetting,		//vqc遥控、设定值格式： uchar(fwdSetting) | int (id) | uchar (VQC_T::tCMDTYPE) \
						///	| QVariant (value) | uchar (VQC_T::tRETVAL)，方向：vqc<-->远动;
	/* 总召 相关 */
	fwdCallData,	//格式： uchar(fwdCallData) | int (id) | QVariant (value) | uchar (TASKGRP) 方向：监控->远动;
						///格式: enumType(fwdCallData) 方向：远动->监控;
	/* CVT 相关 */
	CVT_STATUS,		//遥信格式：uchar(CVT_STATUS) | int (id) | QVariant (value) | double (timestamp)
	CVT_ANALOG,		//遥测格式：uchar(CVT_ANALOG) | int (id) | QVariant (value) | double (timestamp)
	CVT_CMD	,		//遥控、定值格式：uchar(CVT_CMD) |  int (id) | unsigned char (VQC_T::tCMDTYPE) \
						///	| QVariant (value) | unsigned char (VQC_T::tRETVAL)，方向：cvt<-->远动;

	/* 接地选线(SM) 相关 */
	SM_STATUS,		//遥信格式：uchar(SM_STATUS) | int (id) | QVariant (value) | double (timestamp)
	SM_ANALOG,		//遥测格式：uchar(SM_ANALOG) | int (id) | QVariant (value) | double (timestamp)
	SM_CMD			//遥控、定值格式：uchar(SM_CMD) |  int (id) | unsigned char (VQC_T::tCMDTYPE) \
	///	| QVariant (value) | unsigned char (VQC_T::tRETVAL)，方向：cvt<-->远动;

} FWDTYPES;

/*
 * 消息中心相关宏定义
 */
#define FWDMsgType				280
#define Sender_PSPARTNAME 		"VQCSender"
#define Recver_PSPARTNAME 		"VQCRecver"
#define Sender_PARTTYPE 		0x9F		//unsigned short
#define Recver_PARTTYPE 		0x9E			


#define FWDTYPES_VQCROLE 100	//VQC主备角色相关类型
typedef enum {
	TEST = 0,
	KEEP,
	ACK
} tVQCROLEMSG;
#endif
