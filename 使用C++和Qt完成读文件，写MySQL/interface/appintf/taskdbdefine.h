#ifndef _TASKDBDEFINE_H__
#define _TASKDBDEFINE_H__

/* ����ҵ��������ʵʱ�����ݱ������ֶ� */

// �����ֶ�
#define FIELD_ID					"ID"
#define FIELD_NAME					"Name"
#define FIELD_UNAME					"NAME"
#define FIELD_IEDID					"IEDID"
#define FIELD_BAYID					"BAYID"
#define FIELD_CPUNO					"CPUNO"
#define FIELD_TYPE					"TYPE"
#define FIELD_ATTRIBUTE				"ATTRIBUTE"
#define FIELD_NO                    "NO"
#define FIELD_RELATIVEID            "RELATIVEID"
#define FIELD_INFODEFTABLE2ID       "INFODEFTABLE2ID"
// վ����
#define FIELD_PRVEIEW				"STATUS"			// Ԥ��״̬(��վ)

// ����������
#define FIELD_CTRL_DBFLAG			"DoubleCtrlFlag"	// ˫ң��־
#define FIELD_CTRL_UDBFLAG			"DOUBLECTRLFLAG"	// ˫ң��־
#define FIELD_CTRL_TRIPID			"TripStrID"			// �ط�����(ID)
#define FIELD_CTRL_CLOSEID			"CloseStrID"		// �غϱ���(ID)
#define FIELD_CTRL_TRIPEXP			"TripLockExpID"		// �طֱ��ʽ(ID)
#define FIELD_CTRL_CLOSEEXP			"CloseLockExpID"	// �غϱ��ʽ(ID)
#define FIELD_CTRL_OPFLAG			"OPFLAG"			// �̿ر�־
#define FIELD_CTRL_ATTRIBUTE		"ATTRIBUTE"			// ��ض�������

// ������(61850)
#define FIELD_CTRL_INFOTBL			"INFODEFTABLE1"
#define FIELD_CTRL_INFOTBLID		"INFODEFTABLE1ID"
#define FIELD_CTRL_RELATIVEID		"RELATIVEID"
#define TYPE_CTRL_TAP				4				// ���������ֽ�ͷ����

// ���������104���ֶ�(61850)
#define TABLE_CTRL104				"ctrltcp104"
#define NUM_BASE_INFOADDR			24677


// ���ʽ���
#define TABLE_EXPRESSION			"expression"
#define FIELD_EXP_FORMULA			"FORMULA"
#define FIELD_EXP_DESC				"DESCRIPTION"

// ״̬�����
#define TABLE_STATUS				"status"
#define FIELD_STA_DBFLAG			"DoublePointFlag"
#define FIELD_STA_VALUE				"Value"
#define FIELD_STA_UVALUE			"VALUE"
#define FIELD_STA_ID				"ID"
#define FIELD_STA_INF104			"INFODEFTABLE1ID"
// ״̬��(61850)
#define VALUE_DPS_CLOSE				2				// ����˫���λ����ֵ
#define QUALITY_VALID				3				// ��Ч������־
#define FIELD_STA_DUMMYFLAG			"DUMMYFLAG"


// ģ�������
#define TABLE_ANALOG				"analog"
#define FIELD_ANA_VALUE				"CalValue"
// ģ����(61850)
#define FIELD_ANA_SCALE				"SECONDTATV"
#define FIELD_ANA_BASEVALUE			"BASEVALUE"


// ״̬��104Э���
#define TABLE_CTRL104				"ctrltcp104"
#define FIELD_CTRL104_CPU			"CPUNO"
#define FIELD_CTRL104_ADDR			"COMMONADDRESS"
#define FIELD_CTRL104_INF			"INFOADDR104"
#define FIELD_CTRL104_ASDU			"MSGTYPE104"


// װ�����
#define FIELD_IED_ADDRESS			"ADDRESS"
// ����װ�ñ��ֶ�(61850)
#define FIELD_IED_SESSIONID			"SESSIONID"


// ���򻯲���Ʊ���
#define TITLE_MSG					"�̿ز���ƱԤ��"
#define TABLE_TICKET				"ticket"
#define FIELD_TICKET_IOA			"IOA"

// ����豸̬���
#define FIELD_BAYS_EXPID			"EXPID"
#define FIELD_BAYS_STATE			"STATE"


// ���嶨ֵ�����ֶ�(61850)
#define TABLE_SETZONE				"settingzone"
#define FIELD_ZONE_ZONETYPE			"ZONETYPE"
#define TYPE_SWITCHZONE				11				// �л���ֵ������

// ���嶨ֵ���ֶ�(61850)
#define TABLE_SETTING				"setting"
#define SETINGZONE_CURRENT			15
#define MAX_SETTING					256				// ���ֵ����
#define COE_SETTING1				0				// ��ֵ�����ͼ�ϵ��  zqx �޸�Ϊ0
#define COE_SETTING2				16
#define COE_SETTING3				0x0002
#define MINUS_SETTING				0x0080
#define FACTOR_SETTING3				0.01
#define FIELD_SET_FACTOR			"SECONDCOL"
#define FIELD_SET_OFFSET			"OFFSET"
#define CODE_SET_VALUE				0x06

// �����豸��Ϣ���ֶ�(61850)
#define TABLE_DEVICEDESC			"devicedesc"


#endif