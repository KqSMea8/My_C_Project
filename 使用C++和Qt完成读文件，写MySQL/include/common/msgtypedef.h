/*******************************************************
 * msgtypedef.h -- 消息数据类型定义
 * 
 *******************************************************/

#ifndef MSGDATATYPEDEFINE_PENGSHIKANG_20110808_H
#define MSGDATATYPEDEFINE_PENGSHIKANG_20110808_H

typedef struct 
{
	/* 消息分组 [0 - 30]内部使用, [31-255]为外部使用 */
	typedef enum {
		GroupNone = 0,
			GroupConnection,		//连接 CTRL_MSC_MSGT = 110
			GroupSCADAControl,		//控制 CTRL_MSC_MSGT = 110
			GroupSCADAOperate,		//人工操作 CTRL_MSC_MSGT = 110
			GroupSCADASetting,		//定值设置 CTRL_MSC_MSGT = 110
			GroupSysReset,			//系统总复归/厂站总复归 CTRL_MSC_MSGT = 110
			GroupCallData,			//数据召唤 CTRL_MSC_MSGT = 110
			GroupHistorySave=20,    //数据历史存储 EVENT_MSGT = 126
			GroupDispatch=30,       //调度数据收发。 收：RECV_CURVE_MSGT=127  发：SEND_CURVE_MSGT=128 | FD_MSC_MSGT=101
			GroupFiveDefense,		//五防消息分组/数据转发。 收|发：FD_MSC_MSGT = 101
			GroupAllControl,	    //以组播方式进行群控。 发：FD_MSC_MSGT = 101
			GroupStrategyAGC,		//AGC控制策略。 发：AUTO_CTRL_MSGT = 111
			GroupStrategyAVC,		//AVC控制策略。 发：AUTO_CTRL_MSGT = 111
	} MsgGroup;
	
	typedef enum {
		/* 1、MsgGroup = CONNECTION */
			TypeNone = 0,
			LOST,
			KEEP,
			ACKKEEP,
			LOGIN,				//控制客户端向服务端请求会话
			LOGINSUCCESS,		//服务端接受客户端会话请求
			LOGINFAIL,
			LOGOUT,
			SERVERONLINE,		//=8 服务端上线

		/* 2、MsgGroup = GroupSCADAControl */
			ShowSqCtrlView = 8, //=8 (发)请求显示顺控过程 /*  int(sqctrlID) | int(optType) | int(timeout) | char(userID[256]) : size=270 */
			// optType : 1--执行；2--暂停；3--继续（恢复执行）；4--中止。
			RequestForGuardian,	//=9 (发)请求监护 { bAdjust = 0/遥信 | 4/遥调 }
			/* int(ctrlID) | char(curStatusDesc[16]) | char(strAction[116]) | uchar(bAdjust) | uchar(bSoft) | [[char(userID[256]) || int(smgId) | int(eqpId) | char(curValue[124]) | char(aimValue[124])]]: size=396 */
			GuardianResult,		//(收)监护结果返回  int(sid) | uchar(yOrn) | char(newValue[16]) | char(userID[256]) : size=278 

		/* 3、MsgGroup = GroupSCADAControl, GroupSCADAOperate or GroupSCADASetting */ // 控制\操作结果
			ProgressInfo,       //=11 (发) 控制执行中
			Success,            //=12 (发) 控制成功返回
			Failed,             //=13 (发) 控制失败
			Timeout,            //=14 (发) 控制超时
			Error,              //=15 (发) 控制错误

		/* 4、MsgGroup = GroupSCADAControl */ // 人机界面遥控命令
			RequestForControl,	//=16 (收)请求执行控制
			/* int(sid) | int(ctrlID) | int( ctrlValueID) | int(timeout) | char(userID[256]) 
			| char(wkstationID[256]) | char(guardianwkstation[256]) | double(dblCtrlValue) | uchar(bManuCtrl) : size=794 */
			ExecuteOrCancel,	//(收/发)执行或撤销  uchar(eorc) : size=2 
			SuccessCancel,		//(发)撤销控制成功 Server->Client

		/* 5、MsgGroup = GroupSCADAOperate */ // 人机界面操作
			RequestForOperate,	//=19 请求执行操作
			//GroupSCADAOperate|RequestForOperate|sid|objId|objType[BYTE]|oprType|timeout|userID|wkstationID|value(double or int)
			/* objType[BYTE]：     00 -- WholeSystem,     // typeNone = 0
				01 -- typeAnalog,  02 -- typeStatus, 03 -- typeAccumulator,
				04 -- typeControl,
				05 -- typeSetting     --> no use
				06 -- typeSettingArea --> no use
				07 -- typeAlarm       --> no use
				08 -- typeStation,  09 -- typeBay,   10 -- typeEquip,
				11 -- typeSOE,
				12 -- typeMicgrid,
				end - ObjectEndFlag --> no use                            */
			/* 	oprType[int]：	00 -- ID_GZConfirm = 0,		//光字确认
				01 -- ID_ManualSet,			//人工置数  value = setValue(double)
				02 -- ID_CancelManualSet,	//取消置数
				03 -- ID_Lock,				//闭锁/封锁 (注:控制量、设备、间隔、厂站对象为闭锁；遥测、遥信、遥脉对象为封锁)
				04 -- ID_UnLock,			//解闭锁/解封
				05 -- ID_TagOn,				//挂牌      value = tagTypeId(int)
				06 -- ID_TagOff,			//挂牌取消
				07 -- ID_Unflicker,			//消闪
				08 -- ID_ManuCtrl,			//人工控制
				09 -- ID_CancelManuCtrl,	//取消人工控制
				10 -- ID_GenAlarmConfirm,	//预告总确认（暂无） --> null_object
				11 -- ID_GenFaultConfirm,	//事故总确认（暂无） --> null_object
				12 -- ID_ManualSet_Trip,	//遥信人工置数（分）
				13 -- ID_ManualSet_Close,	//遥信人工置数（合）
				////以下为批量操作////
				14 -- ID_EquipGZConfirm,	//设备全测点光字确认
				15 -- ID_BayGZConfirm,		//间隔全测点光字确认
				16 -- ID_StationGZConfirm,	//厂站全测点光字确认
				17 -- ID_SysGZConfirm,		//全系统光字确认
				//
				18 -- ID_EquipUnflicker,	//设备全测点消闪
				19 -- ID_BayUnflicker,		//间隔全测点消闪
				20 -- ID_StationUnflicker,	//厂站全测点消闪
				21 -- ID_SysUnflicker = 21,	//全系统消闪
				//
				//22 -- ID_EquipMeasLock,	//设备全测点封锁
				//23 -- ID_BayMeasLock,		//间隔全测点封锁
				//24 -- ID_StationMeasLock,	//厂站全测点封锁
				//25 -- ID_SysMeasLock,		//系统全测点封锁
				//
				22 -- ID_EquipMeasUnLock = 22,//设备全测点解封锁
				23 -- ID_BayMeasUnLock,		//间隔全测点解封锁
				24 -- ID_StationMeasUnLock,	//厂站全测点解封锁
				25 -- ID_SysMeasUnLock,		//系统全测点解封锁	
				//
				26 -- ID_StationReset,		//厂站总复归令 --> null_object
				27 -- ID_SysGeneralReset,	//系统总复归令 --> null_object
				////向前置进行数据召唤////
				28 -- ID_CallStationData,	//全站数据召唤 --> null_object
				29 -- ID_CallAnalog,		//遥测召唤（单个点） --> null_object
				30 -- ID_CallStatus,		//遥信召唤（单个点） --> null_object
				31 -- ID_CallAccum,			//遥脉召唤（单个点） --> null_object
				32 -- ID_CallAnalogsOfStation,//全遥测召唤（单个厂站） --> null_object
				33 -- ID_CallStatusesOfStation,//全遥信召唤（单个厂站） --> null_object
				34 -- ID_CallAccumsOfStation,//全遥脉召唤（单个厂站）--> null_object
				//
				35 -- ID_STATClear,			//统计次数修改 value = ChangeNum(int)+AccidNum(int)
				36 -- ID_FiveDefenseOn,		//站五防投入	！注：系统中Prevent/FiveDefense/WF会交替使用
				37 -- ID_FiveDefenseOff,	//站五防退出
				38 -- ID_FiveDefenseMode=38,//站五防模式设置 value = wfmode(int)
				//
				39 -- ID_ClearFaultFlag,      //=39 清除[厂站\间隔\设备]的事故标志
				40 -- ID_ClearAlarmFlag,      //=40 清除[厂站\间隔]的预告标志
				41 -- ID_ClearFailedTimes,    //=41 清除[微网\设备]的连续控制失败次数
				42 -- ID_BayReset,			  //=42 间隔总复归令
				43 -- ID_ManualSet_Status,	  //=43 遥信人工置数	value = setValue(int) + setName(char[64]);
				44 -- ID_LockStrategy,        //=44 自动策略闭锁    value = type(int) : 1--AGC; 2--AVC; 3--AGC/AVC全闭锁
				45 -- ID_UnlockStrategy,      //=45 自动策略解锁    value = type(int) : 1--AGC; 2--AVC; 3--AGC/AVC全解锁
				//
				end - ID_OperationEndFlag,  //空操作类型，置于人机界面操作类的最后
			*/


		/* 6、MsgGroup = GroupSCADASetting */ // 定值管理界面操作
			RequestForSetting,	//请求执行定值操作
			CallSettingResult,
			CallVersionResult,
			RequestForCharging,	//请求执行充电控制，@@@11-15添加，只针对汽车充电站充电控制

		/* 7、MsgGroup = GroupSCADAControl */ // 调度端下发控制命令
			RequestForCtrlVal,	//=24 (收)请求执行控制 int(ctrlID) | int( aimValue) | uchar(bAuto) | uchar( isCtrlVal) | uchar( isSelCtrl) : size=12 
			SuccessChange,      //=25 (发)控制成功变位，等待返回令
			RequestForCtrlCode,	//=26 (收)请求执行控制
			/* int(sid) | int(ctrlID) | int( ctrlTypeCode) | int(timeout) | char(userID[256]) 
			| char(guardianwkstation[256]) | uchar(bManuCtrl) | int(ctrlSrcId1) | int(ctrlSrcId2): size=538 */
			RequestForAdjust,	//=27 (收)请求执行调节 int(ctrlID) | double( aimValue) | uchar(bAuto) : size=14 
			RequestForSqCtrl,	//=28 (收)请求执行顺控 /* int(sid) | int(ctrlID) | int(optType) | int(timeout) | char(userID[256]): size=268 */
			// optType : 1--执行；2--暂停；3--继续（恢复执行）；4--中止。
			RequestTestControl,	//=29 (收)请求执行充电站控制 int(ctrlID) | int( aimValue) : size=8 
			RequestTestAdjust,	//=30 (收)请求执行充电站调节 int(ctrlID) | double( aimValue) : size=12 

			RequestGroupCtrlCode,//=31 (收)请求执行多控点控制 /* int(sid) | int( ctrlTypeCode) | intarry(ctrlID) | int(timeout) | char(userID[256]) : size=680,N<=100 */
			RequestGroupAdjust,//=32 (收)请求执行多控点调节 /* int(sid) | double( adjustValue) | intarry(ctrlID) | int(timeout) | char(userID[256]) : size=680,N<=100 */
			//intarry：count,data1,data2,...,dataN。N <= 100
 
		/* 8、MsgGroup = GroupFiveDefense */ // 数据转发及五防监控
			ANALOG=1,	/* (发)转发遥测		      0x 1F 01 | int(id) | double(value) | int(CAUSE) | double(timestamp) */
			STATUS,		/* (收/发)五防上送遥信    0x 1F 02 | int(id) | int(dblpoint) | int(value) | int(quality) | int(CAUSE) | double(timestamp) */
			ASK4PREVNT,	/* (发)监控请求五防/遥控  0x 1F 03 | int(id) | int(dblpoint) | int(value) */
			PREVNTRET,	/* (收)监控请求五防返回   0x 1F 04 | int(id) | int(bSuccess) | double(timestamp) */
			PREVNTCMD,	/* (收)五防请求监控		  0x 1F 05 | int(id) | int(bLock) | double(timestamp) */		
			ACCUMU,		/* (发)转发遥脉			  0x 1F 06 | int(id) | double(value) | double(timestamp) */
			EXPRCAL,	/*=7 (收/发)表达式计算量  0x 1F 07 | int(id) | double(value) | double(timestamp) */
			EXPRCALSEND,

		/* 9、MsgGroup = GroupDispatch */ // 调度业务数据处理
			TASKRECV,   /*= 9 接收调度端业务数据    0x 1E 09 | short(task) | int/float(value) */
			TASKSEND,   /*=10 往调度端发送业务数据  0x 1E 0A | short(task) | int/float(value) */
			TASKRESULT, /*=11 业务处理结果返回      0x 1E 0B | short(task) | int(result) */
			TASKRECVCLI,/*=12 界面发来业务数据      0x 1E 0C | short(task) | int/float(value) */
			GROUPCTRL,   /*=13 组播群控命令数据     0x 1E 0D | short(kind) | float(value) */
			/*kind：
			1-	遥控开关机
			2-	有功调节
			3-	无功调节
			4-	功率调节
			5-	电压调节
			6-	无功上限调节
			7-	无功下限调节*/

		/* 10、MsgGroup = GroupAllControl */ // 群控业务数据处理
			//GROUPCTRL,   /*=13 组播群控命令数据     0x 20 0D | short(kind) | float(value) */
			GRPCTRLRESULT,/*=14 组播群控执行结果    0x 20 0E | short(kind) | int(result) */

		/* 11、MsgGroup = GroupHistorySave */ // 实时数据历史存储
			SeqCtrlResult=1,/*=1顺控结果存储        0x 14 01 | int(sctrlId) | byte(runState) | char(strResult[256]) */
				/* runState：0--开始；1--成功；2--失败 */
			DispatchSwitch,	/*=2调度压板变化存储    0x 14 02 | short(taskType) | int(dataValue) */
			StatusChange,	/*=3遥信变位存储  0x 14 03 | int(statusId) | int(dataValue) | double(dataTime) | int(lastValue) | double(lastTime) | int(faultNum) */
			RemoteValChange,/*=4远方数据变化        0x 14 04 | char(strSql[256]) */

	} MsgType;
} CControlMsg;

typedef enum 
{
	RT_SUCCESS, RT_FAILED, RT_TIMEOUT, RT_ERROR, RT_FINISH,
	RT_ProgressInfo, RT_ExecuteOrCancel, RT_SuccessCancel, RT_SuccessChange, RT_ActionFailed, 
} enumRetType;

#endif
