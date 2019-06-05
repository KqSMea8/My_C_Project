#ifndef MSCRESOURCES_H
#define MSCRESOURCES_H
/* 
 *	“当前项目”中各个应用模块已使用的消息中心资源。
 *	！当有新的模块使用消息中心时，请向后追加，避免冲突！
 */

/* 各个应用模块已使用的“消息中心消息类型” */
typedef enum {
	// 四遥数据转发(31)：smgserver --> intersite (已有消息处理对象)
	FD_MSC_MSGT			= 101,		/* 四遥（遥测.遥信.遥脉、遥控）数据转发 */ 
	// 调度端遥控\遥调(2)：intersite --> smgserver (已有消息处理对象)
	// 界面端连接状态、控制\操作\定值\复归\总召、操作进度上送、调度策略启停压板 (1、2、3、4、5、6、30)：smgserver <--> ctrlclient
	CTRL_MSC_MSGT		= 110,		/* 遥控模块：主客连接状态、控制执行结果 */ 
	AUTO_CTRL_MSGT		= 111,		/*AGC、AVC自动策略*/
	// 报警消息通信
	ALRM_MSGT			= 120,		/* 报警信息 */
	ALRM_ACK_MSGT		= 121,		/* 确认一条报警 */
	ALRM_CLEAR_MSGT		= 122,		/* 清除一条报警 */
	ALRM_ACKALL_MSGT	= 123,		/* 确认全部报警 */
	ALRM_CLEARALL_MSGT	= 124,		/* 清除全部报警 */
	// [顺控进度|调度压板变化]进行历史库存储（20）：smgserver --> hisstragy (已有消息处理对象)
	EVENT_MSGT			= 126,		/* 事件(顺控使用) */  
	// 调度策略压板和定值下发后台服务（30）：intersite --> smgserver (部分有消息处理对象)
	RECV_CURVE_MSGT     = 127,      /* 曲线数据接收 */    
	// [调度策略压板由本地变更信息|响应调度策略的结果]发送调度端（30）：smgserver --> intersite (已有消息处理对象)
	// 功率预测曲线由预测服务发送调度端（30）：curvesend --> intersite
	SEND_CURVE_MSGT     = 128,      /* 曲线数据发送 */    
	// 组播群控命令信息发送给群控服务（32）：smgserver --> grpctrlserver
	GRPCTRL_MSC_MSGT    = 129,      /* 组播群控命令发送 */  
	PDR_MANUALFT_TRIGGER = 150,		/*人工触发事故*/
} MSC_MSGT;


/* 各个应用模块向消息中心进行登录时的第二个参数：PartType，登录者类型（模块类型） */
#define MSC_PTYPE_BASE	10								/* 应用模块类型基准值 */
typedef enum {
	MSC_PTYPE_CTRLCLIENT	=	MSC_PTYPE_BASE + 57866, /* ctrlclient 模块 */
	MSC_PTYPE_CTRLSRV		=	MSC_PTYPE_BASE + 57867,	/* ctrlserver 模块 */ // 废止
	MSC_PTYPE_DATAPROC		=	MSC_PTYPE_BASE + 57867,	/* 数据处理服务（scadasrv、smgserver）模块 */
	MSC_PTYPE_ALRMCLIENT	=	MSC_PTYPE_BASE + 21,	/* alarmclient模块 */
	MSC_PTYPE_ALRMCENTER	=	MSC_PTYPE_BASE + 41,	/* alarmcenter模块 */
	MSC_PTYPE_ANALOG		=	MSC_PTYPE_BASE + 42,	/* 遥测服务模块 */    // 废止
	MSC_PTYPE_STATUS		=	MSC_PTYPE_BASE + 43,	/* 遥信服务模块 */    // 废止
	MSC_PTYPE_ACCUM			=	MSC_PTYPE_BASE + 44,	/* 遥脉服务模块 */    // 废止
	MSC_PTYPE_INTERSITE		=	MSC_PTYPE_BASE + 45,	/* InterSite模块 */
	MSC_PTYPE_TESTMODULE	=	MSC_PTYPE_BASE + 46,	/* 测试模块 */
	MSC_PTYPE_HISSTRAGY		=	MSC_PTYPE_BASE + 47,	/* hisstragy模块 */
	MSC_PTYPE_CURVESEND		=	MSC_PTYPE_BASE + 48,	/* 曲线数据发送（curvesend）模块 */
	MSC_PTYPE_GRPCTRLSRV	=	MSC_PTYPE_BASE + 49,	/* 组播群控处理服务（grpctrlserver）模块 */
	MSC_PTYPE_STRATEGYSHOW	=	MSC_PTYPE_BASE + 50,	/* 客户端接收服务策略(agc/avc)模块 */
	MSC_PTYPE_PDRMANUAL		=	MSC_PTYPE_BASE + 61,
	
} MSC_PTYPE; /* 注：由于历史原因控制模块使用的值较大，新模块不必如此，只需确保值不冲突且在(MSC_PTYPE_BASE, maxvalue(ushort))之间即可。*/



#endif	/* MSCRESOURCES_H */
