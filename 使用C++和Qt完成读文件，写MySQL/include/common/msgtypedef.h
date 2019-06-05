/*******************************************************
 * msgtypedef.h -- ��Ϣ�������Ͷ���
 * 
 *******************************************************/

#ifndef MSGDATATYPEDEFINE_PENGSHIKANG_20110808_H
#define MSGDATATYPEDEFINE_PENGSHIKANG_20110808_H

typedef struct 
{
	/* ��Ϣ���� [0 - 30]�ڲ�ʹ��, [31-255]Ϊ�ⲿʹ�� */
	typedef enum {
		GroupNone = 0,
			GroupConnection,		//���� CTRL_MSC_MSGT = 110
			GroupSCADAControl,		//���� CTRL_MSC_MSGT = 110
			GroupSCADAOperate,		//�˹����� CTRL_MSC_MSGT = 110
			GroupSCADASetting,		//��ֵ���� CTRL_MSC_MSGT = 110
			GroupSysReset,			//ϵͳ�ܸ���/��վ�ܸ��� CTRL_MSC_MSGT = 110
			GroupCallData,			//�����ٻ� CTRL_MSC_MSGT = 110
			GroupHistorySave=20,    //������ʷ�洢 EVENT_MSGT = 126
			GroupDispatch=30,       //���������շ��� �գ�RECV_CURVE_MSGT=127  ����SEND_CURVE_MSGT=128 | FD_MSC_MSGT=101
			GroupFiveDefense,		//�����Ϣ����/����ת���� ��|����FD_MSC_MSGT = 101
			GroupAllControl,	    //���鲥��ʽ����Ⱥ�ء� ����FD_MSC_MSGT = 101
			GroupStrategyAGC,		//AGC���Ʋ��ԡ� ����AUTO_CTRL_MSGT = 111
			GroupStrategyAVC,		//AVC���Ʋ��ԡ� ����AUTO_CTRL_MSGT = 111
	} MsgGroup;
	
	typedef enum {
		/* 1��MsgGroup = CONNECTION */
			TypeNone = 0,
			LOST,
			KEEP,
			ACKKEEP,
			LOGIN,				//���ƿͻ�������������Ự
			LOGINSUCCESS,		//����˽��ܿͻ��˻Ự����
			LOGINFAIL,
			LOGOUT,
			SERVERONLINE,		//=8 ���������

		/* 2��MsgGroup = GroupSCADAControl */
			ShowSqCtrlView = 8, //=8 (��)������ʾ˳�ع��� /*  int(sqctrlID) | int(optType) | int(timeout) | char(userID[256]) : size=270 */
			// optType : 1--ִ�У�2--��ͣ��3--�������ָ�ִ�У���4--��ֹ��
			RequestForGuardian,	//=9 (��)����໤ { bAdjust = 0/ң�� | 4/ң�� }
			/* int(ctrlID) | char(curStatusDesc[16]) | char(strAction[116]) | uchar(bAdjust) | uchar(bSoft) | [[char(userID[256]) || int(smgId) | int(eqpId) | char(curValue[124]) | char(aimValue[124])]]: size=396 */
			GuardianResult,		//(��)�໤�������  int(sid) | uchar(yOrn) | char(newValue[16]) | char(userID[256]) : size=278 

		/* 3��MsgGroup = GroupSCADAControl, GroupSCADAOperate or GroupSCADASetting */ // ����\�������
			ProgressInfo,       //=11 (��) ����ִ����
			Success,            //=12 (��) ���Ƴɹ�����
			Failed,             //=13 (��) ����ʧ��
			Timeout,            //=14 (��) ���Ƴ�ʱ
			Error,              //=15 (��) ���ƴ���

		/* 4��MsgGroup = GroupSCADAControl */ // �˻�����ң������
			RequestForControl,	//=16 (��)����ִ�п���
			/* int(sid) | int(ctrlID) | int( ctrlValueID) | int(timeout) | char(userID[256]) 
			| char(wkstationID[256]) | char(guardianwkstation[256]) | double(dblCtrlValue) | uchar(bManuCtrl) : size=794 */
			ExecuteOrCancel,	//(��/��)ִ�л���  uchar(eorc) : size=2 
			SuccessCancel,		//(��)�������Ƴɹ� Server->Client

		/* 5��MsgGroup = GroupSCADAOperate */ // �˻��������
			RequestForOperate,	//=19 ����ִ�в���
			//GroupSCADAOperate|RequestForOperate|sid|objId|objType[BYTE]|oprType|timeout|userID|wkstationID|value(double or int)
			/* objType[BYTE]��     00 -- WholeSystem,     // typeNone = 0
				01 -- typeAnalog,  02 -- typeStatus, 03 -- typeAccumulator,
				04 -- typeControl,
				05 -- typeSetting     --> no use
				06 -- typeSettingArea --> no use
				07 -- typeAlarm       --> no use
				08 -- typeStation,  09 -- typeBay,   10 -- typeEquip,
				11 -- typeSOE,
				12 -- typeMicgrid,
				end - ObjectEndFlag --> no use                            */
			/* 	oprType[int]��	00 -- ID_GZConfirm = 0,		//����ȷ��
				01 -- ID_ManualSet,			//�˹�����  value = setValue(double)
				02 -- ID_CancelManualSet,	//ȡ������
				03 -- ID_Lock,				//����/���� (ע:���������豸���������վ����Ϊ������ң�⡢ң�š�ң������Ϊ����)
				04 -- ID_UnLock,			//�����/���
				05 -- ID_TagOn,				//����      value = tagTypeId(int)
				06 -- ID_TagOff,			//����ȡ��
				07 -- ID_Unflicker,			//����
				08 -- ID_ManuCtrl,			//�˹�����
				09 -- ID_CancelManuCtrl,	//ȡ���˹�����
				10 -- ID_GenAlarmConfirm,	//Ԥ����ȷ�ϣ����ޣ� --> null_object
				11 -- ID_GenFaultConfirm,	//�¹���ȷ�ϣ����ޣ� --> null_object
				12 -- ID_ManualSet_Trip,	//ң���˹��������֣�
				13 -- ID_ManualSet_Close,	//ң���˹��������ϣ�
				////����Ϊ��������////
				14 -- ID_EquipGZConfirm,	//�豸ȫ������ȷ��
				15 -- ID_BayGZConfirm,		//���ȫ������ȷ��
				16 -- ID_StationGZConfirm,	//��վȫ������ȷ��
				17 -- ID_SysGZConfirm,		//ȫϵͳ����ȷ��
				//
				18 -- ID_EquipUnflicker,	//�豸ȫ�������
				19 -- ID_BayUnflicker,		//���ȫ�������
				20 -- ID_StationUnflicker,	//��վȫ�������
				21 -- ID_SysUnflicker = 21,	//ȫϵͳ����
				//
				//22 -- ID_EquipMeasLock,	//�豸ȫ������
				//23 -- ID_BayMeasLock,		//���ȫ������
				//24 -- ID_StationMeasLock,	//��վȫ������
				//25 -- ID_SysMeasLock,		//ϵͳȫ������
				//
				22 -- ID_EquipMeasUnLock = 22,//�豸ȫ�������
				23 -- ID_BayMeasUnLock,		//���ȫ�������
				24 -- ID_StationMeasUnLock,	//��վȫ�������
				25 -- ID_SysMeasUnLock,		//ϵͳȫ�������	
				//
				26 -- ID_StationReset,		//��վ�ܸ����� --> null_object
				27 -- ID_SysGeneralReset,	//ϵͳ�ܸ����� --> null_object
				////��ǰ�ý��������ٻ�////
				28 -- ID_CallStationData,	//ȫվ�����ٻ� --> null_object
				29 -- ID_CallAnalog,		//ң���ٻ��������㣩 --> null_object
				30 -- ID_CallStatus,		//ң���ٻ��������㣩 --> null_object
				31 -- ID_CallAccum,			//ң���ٻ��������㣩 --> null_object
				32 -- ID_CallAnalogsOfStation,//ȫң���ٻ���������վ�� --> null_object
				33 -- ID_CallStatusesOfStation,//ȫң���ٻ���������վ�� --> null_object
				34 -- ID_CallAccumsOfStation,//ȫң���ٻ���������վ��--> null_object
				//
				35 -- ID_STATClear,			//ͳ�ƴ����޸� value = ChangeNum(int)+AccidNum(int)
				36 -- ID_FiveDefenseOn,		//վ���Ͷ��	��ע��ϵͳ��Prevent/FiveDefense/WF�ύ��ʹ��
				37 -- ID_FiveDefenseOff,	//վ����˳�
				38 -- ID_FiveDefenseMode=38,//վ���ģʽ���� value = wfmode(int)
				//
				39 -- ID_ClearFaultFlag,      //=39 ���[��վ\���\�豸]���¹ʱ�־
				40 -- ID_ClearAlarmFlag,      //=40 ���[��վ\���]��Ԥ���־
				41 -- ID_ClearFailedTimes,    //=41 ���[΢��\�豸]����������ʧ�ܴ���
				42 -- ID_BayReset,			  //=42 ����ܸ�����
				43 -- ID_ManualSet_Status,	  //=43 ң���˹�����	value = setValue(int) + setName(char[64]);
				44 -- ID_LockStrategy,        //=44 �Զ����Ա���    value = type(int) : 1--AGC; 2--AVC; 3--AGC/AVCȫ����
				45 -- ID_UnlockStrategy,      //=45 �Զ����Խ���    value = type(int) : 1--AGC; 2--AVC; 3--AGC/AVCȫ����
				//
				end - ID_OperationEndFlag,  //�ղ������ͣ������˻��������������
			*/


		/* 6��MsgGroup = GroupSCADASetting */ // ��ֵ����������
			RequestForSetting,	//����ִ�ж�ֵ����
			CallSettingResult,
			CallVersionResult,
			RequestForCharging,	//����ִ�г����ƣ�@@@11-15��ӣ�ֻ����������վ������

		/* 7��MsgGroup = GroupSCADAControl */ // ���ȶ��·���������
			RequestForCtrlVal,	//=24 (��)����ִ�п��� int(ctrlID) | int( aimValue) | uchar(bAuto) | uchar( isCtrlVal) | uchar( isSelCtrl) : size=12 
			SuccessChange,      //=25 (��)���Ƴɹ���λ���ȴ�������
			RequestForCtrlCode,	//=26 (��)����ִ�п���
			/* int(sid) | int(ctrlID) | int( ctrlTypeCode) | int(timeout) | char(userID[256]) 
			| char(guardianwkstation[256]) | uchar(bManuCtrl) | int(ctrlSrcId1) | int(ctrlSrcId2): size=538 */
			RequestForAdjust,	//=27 (��)����ִ�е��� int(ctrlID) | double( aimValue) | uchar(bAuto) : size=14 
			RequestForSqCtrl,	//=28 (��)����ִ��˳�� /* int(sid) | int(ctrlID) | int(optType) | int(timeout) | char(userID[256]): size=268 */
			// optType : 1--ִ�У�2--��ͣ��3--�������ָ�ִ�У���4--��ֹ��
			RequestTestControl,	//=29 (��)����ִ�г��վ���� int(ctrlID) | int( aimValue) : size=8 
			RequestTestAdjust,	//=30 (��)����ִ�г��վ���� int(ctrlID) | double( aimValue) : size=12 

			RequestGroupCtrlCode,//=31 (��)����ִ�ж�ص���� /* int(sid) | int( ctrlTypeCode) | intarry(ctrlID) | int(timeout) | char(userID[256]) : size=680,N<=100 */
			RequestGroupAdjust,//=32 (��)����ִ�ж�ص���� /* int(sid) | double( adjustValue) | intarry(ctrlID) | int(timeout) | char(userID[256]) : size=680,N<=100 */
			//intarry��count,data1,data2,...,dataN��N <= 100
 
		/* 8��MsgGroup = GroupFiveDefense */ // ����ת����������
			ANALOG=1,	/* (��)ת��ң��		      0x 1F 01 | int(id) | double(value) | int(CAUSE) | double(timestamp) */
			STATUS,		/* (��/��)�������ң��    0x 1F 02 | int(id) | int(dblpoint) | int(value) | int(quality) | int(CAUSE) | double(timestamp) */
			ASK4PREVNT,	/* (��)����������/ң��  0x 1F 03 | int(id) | int(dblpoint) | int(value) */
			PREVNTRET,	/* (��)��������������   0x 1F 04 | int(id) | int(bSuccess) | double(timestamp) */
			PREVNTCMD,	/* (��)���������		  0x 1F 05 | int(id) | int(bLock) | double(timestamp) */		
			ACCUMU,		/* (��)ת��ң��			  0x 1F 06 | int(id) | double(value) | double(timestamp) */
			EXPRCAL,	/*=7 (��/��)���ʽ������  0x 1F 07 | int(id) | double(value) | double(timestamp) */
			EXPRCALSEND,

		/* 9��MsgGroup = GroupDispatch */ // ����ҵ�����ݴ���
			TASKRECV,   /*= 9 ���յ��ȶ�ҵ������    0x 1E 09 | short(task) | int/float(value) */
			TASKSEND,   /*=10 �����ȶ˷���ҵ������  0x 1E 0A | short(task) | int/float(value) */
			TASKRESULT, /*=11 ҵ����������      0x 1E 0B | short(task) | int(result) */
			TASKRECVCLI,/*=12 ���淢��ҵ������      0x 1E 0C | short(task) | int/float(value) */
			GROUPCTRL,   /*=13 �鲥Ⱥ����������     0x 1E 0D | short(kind) | float(value) */
			/*kind��
			1-	ң�ؿ��ػ�
			2-	�й�����
			3-	�޹�����
			4-	���ʵ���
			5-	��ѹ����
			6-	�޹����޵���
			7-	�޹����޵���*/

		/* 10��MsgGroup = GroupAllControl */ // Ⱥ��ҵ�����ݴ���
			//GROUPCTRL,   /*=13 �鲥Ⱥ����������     0x 20 0D | short(kind) | float(value) */
			GRPCTRLRESULT,/*=14 �鲥Ⱥ��ִ�н��    0x 20 0E | short(kind) | int(result) */

		/* 11��MsgGroup = GroupHistorySave */ // ʵʱ������ʷ�洢
			SeqCtrlResult=1,/*=1˳�ؽ���洢        0x 14 01 | int(sctrlId) | byte(runState) | char(strResult[256]) */
				/* runState��0--��ʼ��1--�ɹ���2--ʧ�� */
			DispatchSwitch,	/*=2����ѹ��仯�洢    0x 14 02 | short(taskType) | int(dataValue) */
			StatusChange,	/*=3ң�ű�λ�洢  0x 14 03 | int(statusId) | int(dataValue) | double(dataTime) | int(lastValue) | double(lastTime) | int(faultNum) */
			RemoteValChange,/*=4Զ�����ݱ仯        0x 14 04 | char(strSql[256]) */

	} MsgType;
} CControlMsg;

typedef enum 
{
	RT_SUCCESS, RT_FAILED, RT_TIMEOUT, RT_ERROR, RT_FINISH,
	RT_ProgressInfo, RT_ExecuteOrCancel, RT_SuccessCancel, RT_SuccessChange, RT_ActionFailed, 
} enumRetType;

#endif
