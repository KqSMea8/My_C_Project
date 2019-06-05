//dispatchtaskdata.h

#ifndef _DISPATCHTASKDATA_PENGSHIKANG_2015_07_13_H_
#define _DISPATCHTASKDATA_PENGSHIKANG_2015_07_13_H_

#include "../icsvalue.h"                         //  for FIELDTYPE

enum DISPATCH_TASKTYPE //����
{
	//DTT_UNKNOWN, 20160822 �������ݴ���������ߺ�0

	//----------------------------ң�⣨1-50��-------------------------------------
	DTT_DATA_MANAGE_SRV_ON = 0, //���ݴ����������

	DTT_POWER_SETTING = 1, //�й������趨ֵ
	DTT_VOLTAGE_SETTING, //Iĸ-��ѹ�趨ֵ
	DTT_QORCOS_SETTING, //Iĸ-�޹�/���������趨ֵ- 20160401 ��Ϊ��ʾ�޹�����Ŀ��ֵ
	DTT_GENCAPA_SETTING_4 = 5, //δ����Сʱ��������

	DTT_QORCOS_LOWERLIMIT = 6,//Iĸ-�޹�/������������Ŀ��ֵ
	DTT_POWER_MAXRATE = 7,//�����·��й��������

	DTT_QORCOS_ADJUSTABLE_UP_LIMIT = 8,//�޹��ɵ�����
	DTT_QORCOS_ADJUSTABLE_DOWN_LIMIT,//�޹��ɵ�����
	DTT_QORCOS_INCREASABLE_SETTING,//�����޹�
	DTT_QORCOS_REDUCIBLE_SETTING,//�ɼ��޹�

	//20160822 �������������� ѹ���Ϊ��50��ʼ���
	DTT_POWER_ADJUST_DEADZONE = 12,//�����·���������	12

	DTT_POWER_ADJUSTABLE_UP_LIMI,//�й��ɵ�����	13
	DTT_POWER_ADJUSTABLE_DOWN_LIMIT,//�й��ɵ�����	14
	DTT_POWER_INCREASABLE_SETTING,//�����й�	15
	DTT_POWER_REDUCIBLE_SETTING,//�ɼ��й�	16

	DTT_CAPACITY = 17,//װ������	17
	DTT_RUNNING_CAPACITY,//��������	18
	DTT_ADJUSTABLE_CAPACITY,//�ɵ�����	19
	DTT_POWER_LOSS,//���������ʧ�й�����	20

	//20161212 ���Ӷ�̬�޹�����/��Ŀ��ֵ��ʵ��ֵ
	DTT_Q_DYNAMIC_INCREASABLE_SETTING = 22,//��̬�����޹�Ŀ��ֵ 22
	DTT_Q_DYNAMIC_REDUCIBLE_SETTING,//��̬�ɼ��޹�Ŀ��ֵ 23
	DTT_Q_DYNAMIC_INCREASABLE_VALUE,//��̬�����޹�ʵ��ֵ 24 
	DTT_Q_DYNAMIC_REDUCIBLE_VALUE,//��̬�ɼ��޹�ʵ��ֵ 25

	DTT_REAL_GENPOWER_VALUE,//���÷����й����� 26
	DTT_NATURAL_GENPOWER__VALUE,//���۷����й����� 27

	DTT_VOLTAGE_REFER,// 	��ѹ�ο�ֵ��У	28
	DTT_Q_REFER,// 	�޹��ο�ֵ��У	29
	DTT_Run_GenNum,//����̨��	30

	//20171204 ����׷��ң��� ֻ���㲢���ͣ�������
	DTT_Q_COSAdjustableUpLimit_VALUE,//������������(ȫվ�������޹�����ʱ��������)--31
	DTT_Q_COSAdjustableDownLimit_VALUE,//������������(ȫվ�ɼ����޹�����ʱ��������)--32

	//20180920 �����ֳ�Ҫ������ĸ�߷ֱ��·���ѹ/�޹�Ŀ��ֵ������֧��II IIIĸ�ߵ�Ŀ��ֵ
	DTT_VOLTAGE_SETTING_2,		//IIĸ-��ѹ�趨ֵ
	DTT_QORCOS_SETTING_2,		//IIĸ-�޹�/���������趨ֵ(����)
	DTT_QORCOS_LOWERLIMIT_2,	//IIĸ-�޹�/������������Ŀ��ֵ
	DTT_VOLTAGE_SETTING_3,		//IIIĸ-��ѹ�趨ֵ
	DTT_QORCOS_SETTING_3,		//IIIĸ-�޹�/���������趨ֵ(����)
	DTT_QORCOS_LOWERLIMIT_3,	//IIIĸ-�޹�/������������Ŀ��ֵ

	DTT_VOLTAGE_REFER_2  =39,// IIĸ-��ѹ�ο�ֵ��У	39
	DTT_Q_REFER_2,// 	IIĸ-�޹��ο�ֵ��У	40
	DTT_VOLTAGE_REFER_3,// 	IIIĸ-��ѹ�ο�ֵ��У	41
	DTT_Q_REFER_3,// 	IIIĸ-�޹��ο�ֵ��У	42
	DTT_QORCOS_ADJUSTABLE_UP_LIMIT_2,//IIĸ-�޹��ɵ�����
	DTT_QORCOS_ADJUSTABLE_DOWN_LIMIT_2,//IIĸ-�޹��ɵ�����
	DTT_QORCOS_ADJUSTABLE_UP_LIMIT_3,//IIIĸ-�޹��ɵ�����
	DTT_QORCOS_ADJUSTABLE_DOWN_LIMIT_3,//IIIĸ-�޹��ɵ�����

	DTT_QORCOS_INCREASABLE_SETTING_2,	//IIĸ-�����޹�
	DTT_QORCOS_REDUCIBLE_SETTING_2,		//IIĸ-�ɼ��޹�
	DTT_QORCOS_INCREASABLE_SETTING_3,	//IIIĸ-�����޹�
	DTT_QORCOS_REDUCIBLE_SETTING_3,		//IIIĸ-�ɼ��޹�

	//----------------------------ң�ţ�51-100��-------------------------------------
	DTT_POWER_SWITCH = 51,		//�й����ʵ���ѹ��Ͷ��
	DTT_EMERGESUPPORT_SWITCH,	//���ʽ���֧��ѹ��Ͷ��
	DTT_EMERGESTOP_SWITCH,		//����ͣ��ѹ��Ͷ��
	DTT_VOLTAGE_SWITCH,			//Iĸ-��ѹ����ѹ��Ͷ��

	DTT_EMERGESUPPORT_ENABLE = 57,//����֧������
	DTT_EMERGESTOP_ENABLE,			//����ͣ������

	DTT_LOCALPLATEN_SWITCH = 59,//���ز���ѹ��Ͷ��

	DTT_Q_UP_LOCK_SWITCH = 60,	//�޹��ϵ��ڱ�����־
	DTT_Q_DOWN_LOCK_SWITCH,		//�޹��µ��ڱ�����־

	DTT_AGC_RUN_CONDITION,		// 	AGC����״̬	62
	DTT_AGC_ENABLE_CONDITION,	// 	AGC����״̬	63
	DTT_P_UP_LOCK_SWITCH,		// 	�й�����������	64
	DTT_P_DOWN_LOCK_SWITCH,		// 	�й����ʼ�����	65

	DTT_FREE_GENERATION_MODE,// 	�����·����ɷ���ģʽ66 0��ʾ���ɷ��磻1��ʾ������ֵ����

	DTT_P_ORDER_SOURCE = 67,	//20161212 �����й�Ŀ��ָ����Դ

	DTT_QORCOS_CTRL_MODE = 68,	//20161216 ���ӵ�ѹ�޹�����ģʽң��

	DTT_P_AGCSWITCH_BACK = 69,	//20180605 ����Ҫ�󣺵�������Զ��Ͷ��/�˳���Уֵ��������AGCѹ��Ӧ��YK��������Զ��Ͷ��/�˳�,ͬʱ�����ң�ؼǵ�smgsysinfo��AGC��ֹ״̬�ֶ���

	DTT_AVC_LocalRemote,// 	AVC��վԶ��/����	70
	DTT_EMERGESUPPORT_Dis_ENABLE_REFER,// 	����֧�Żָ�ң�ط�Уֵ	71
	DTT_EMERGESTOP_Dis_ENABLE_REFER,// 	����ͣ�˻ָ�ң�ط�Уֵ	72

	DTT_EMERGESUPPORT_ENABLE_REFER,// 	����֧��ң�ط�Уֵ	73
	DTT_EMERGESTOP_ENABLE_REFER,// 	����ͣ��ң�ط�Уֵ	74

	//20180920 AGC/AVC ָ���쳣�����ź�
	DTT_AGC_AIMERROR,//AGCָ���쳣���� 75

	DTT_AVC_AIMERROR,//Iĸ-AVCָ���쳣���� 76
	DTT_AVC_AIMERROR_2,//IIĸ-AVCָ���쳣���� 77
	DTT_AVC_AIMERROR_3,//IIIĸ-AVCָ���쳣���� 78

	DTT_QORCOS_CTRL_MODE_2,	//IIĸ-��ѹ�޹�����ģʽң��
	DTT_QORCOS_CTRL_MODE_3,	//IIIĸ-��ѹ�޹�����ģʽң��

	DTT_AVC_LocalRemote_2,//IIĸ-AVC��վԶ��/����	81
	DTT_AVC_LocalRemote_3,//IIIĸ-AVC��վԶ��/����	82

	DTT_VOLTAGE_Remote_SWITCH,			//Iĸ-��ѹ���� �ƻ���ЧͶ��
	DTT_VOLTAGE_Remote_SWITCH_2,		//IIĸ-��ѹ���� �ƻ���ЧͶ��
	DTT_VOLTAGE_Remote_SWITCH_3,		//IIIĸ-��ѹ���� �ƻ���ЧͶ��

	DTT_Q_UP_LOCK_SWITCH_2 ,	//IIĸ�޹��ϵ��ڱ�����־
	DTT_Q_DOWN_LOCK_SWITCH_2,	//IIĸ�޹��µ��ڱ�����־
	DTT_Q_UP_LOCK_SWITCH_3 ,	//IIIĸ�޹��ϵ��ڱ�����־
	DTT_Q_DOWN_LOCK_SWITCH_3,	//IIIĸ�޹��µ��ڱ�����־

//----------------------------���ߣ�101-��-------------------------------------
	DTT_DECLARE_CURVE_POWER_DAY = 101, //�շ��繦���걨����
	DTT_DECLARE_CURVE_ON_CAPACITY_DAY, //�տ��������걨����
	DTT_DECLARE_CURVE_POWER_4H , //��Сʱ���繦���걨����

//----------------------------ң�⣨1001-��-------------------------------------
	DTT_Q_SETTING_MID = 1001, //Iĸ-�޹�������Ŀ��ֵ��ֵ
	DTT_Q_SETTING_MID_2, //Iĸ-�޹�������Ŀ��ֵ��ֵ
	DTT_Q_SETTING_MID_3, //Iĸ-�޹�������Ŀ��ֵ��ֵ
};

//20160822 �������������ݲ����ϸ��Ӧ��������һ��ö���������������ݣ�ԭ����ö���������������ݡ�
enum DISPATCH_TASKTYPE_DOWN
{
	//----------------------------ң����1-20��-------------------------------------
	DTTD_POWER_SETTING = 1, //�й������趨ֵ
	DTTD_VOLTAGE_SETTING, //Iĸ��ѹ�趨ֵ
	DTTD_QORCOS_SETTING, //Iĸ�޹�/���������趨ֵ- 20160401 ��Ϊ��ʾ�޹�����Ŀ��ֵ
	DTTD_QORCOS_LOWERLIMIT = 6,//Iĸ�޹�/������������Ŀ��ֵ

	DTTD_POWER_MAXRATE = 7,//�����·��й��������
	
	DTTD_POWER_ADJUST_DEADZONE = 8,//�����·���������

	//20161212 ���Ӷ�̬�޹�����/��Ŀ��ֵ
	DTTD_Q_DYNAMIC_INCREASABLE_SETTING = 9,//��̬�����޹�Ŀ��ֵ 9
	DTTD_Q_DYNAMIC_REDUCIBLE_SETTING,//��̬�ɼ��޹�Ŀ��ֵ 10

	DTTD_VOLTAGE_REFER,//��ѹ�ο�ֵ 11
	DTTD_VOLTAGE_INCREMENT,//��ѹ����ֵ 12

	DTTD_Q_REFER,// 	�޹��ο�ֵ	13

	//20180920 �����ֳ�Ҫ������ĸ�߷ֱ��·���ѹ/�޹�Ŀ��ֵ������֧��II IIIĸ�ߵ�Ŀ��ֵ
	DTTD_VOLTAGE_SETTING_2 = 14,	//IIĸ ��ѹ�趨ֵ
	DTTD_QORCOS_SETTING_2,			//IIĸ �޹�/���������趨ֵ
	DTTD_QORCOS_LOWERLIMIT_2,		//IIĸ �޹�/������������Ŀ��ֵ
	DTTD_VOLTAGE_SETTING_3,			//IIIĸ ��ѹ�趨ֵ
	DTTD_QORCOS_SETTING_3,			//IIIĸ �޹�/���������趨ֵ
	DTTD_QORCOS_LOWERLIMIT_3,		//IIIĸ �޹�/������������Ŀ��ֵ


	//----------------------------ң�أ�21-50��-------------------------------------
	DTTD_POWER_SWITCH = 21, //�й����ʼƻ��Ƿ���Ч
	DTTD_EMERGESUPPORT_SWITCH, //���ʽ���֧��ѹ��Ͷ��
	DTTD_EMERGESTOP_SWITCH, //����ͣ��ѹ��Ͷ��
	DTTD_VOLTAGE_SWITCH, //��ѹ����ѹ��Ͷ��
	//DTTD_QORRCOS_SWITCH, //�޹�/������������ѹ��Ͷ��

	DTTD_LOCALPLATEN_SWITCH = 25,//���ز���ѹ��Ͷ��

	DTTD_EMERGESUPPORT_ENABLE = 27,//����֧������
	DTTD_EMERGESTOP_ENABLE,//����ͣ������

	
	DTTD_FREE_GENERATION_MODE = 29,// 	�����·����ɷ���ģʽ 0��ʾ���ɷ��磻1��ʾ������ֵ����

	DTTD_P_ORDER_SWITCH,//�й�Ŀ��ָ���л� 30  //20161212 �����й�Ŀ��ָ���л�

	DTTD_EMERGESUPPORT_Dis_ENABLE = 31,//����֧�Żָ�
	DTTD_EMERGESTOP_Dis_ENABLE,//����ͣ�˻ָ�

	DTTD_VOLTAGE_Remote_SWITCH,			//Iĸ-��ѹ���� �ƻ���ЧͶ��
	DTTD_VOLTAGE_Remote_SWITCH_2,		//IIĸ-��ѹ���� �ƻ���ЧͶ��
	DTTD_VOLTAGE_Remote_SWITCH_3,		//IIIĸ-��ѹ���� �ƻ���ЧͶ��

	//----------------------------�������ߣ�51-��-------------------------------------
	DTTD_POWER_CURVE = 51, //�й�����
	DTTD_VOLTAGE_CURVE, //��ѹ����
	DTTD_QORCOS_CURVE, //�޹���������������

	//----------------------------���٣�100��-------------------------------------
	DTTD_DISPATCH_CALL_BACK = 100,	////��������


	//----------------------------ң����1001-��-------------------------------------ҵ���Ų����ˣ��ֳ��Ѿ��͵��ȶԹ��㣬��������������ֻ����
	DTTD_VOLTAGE_REFER_2 = 1001,	//IIĸ ��ѹ�ο�ֵ 1001
	DTTD_Q_REFER_2,			//IIĸ �޹��ο�ֵ 1002
	DTTD_VOLTAGE_REFER_3,	//IIIĸ ��ѹ�ο�ֵ 1003
	DTTD_Q_REFER_3,			//IIIĸ �޹��ο�ֵ 1004

};

enum DISPATCH_TOHISTYPE //TO HISSTRATEGY ����
{
	DTOHIS_NO = 0,//0-������ʷ�洢������Ϣ 
	DTOHIS_DispatchSwitc,//1-����ѹ��仯��Ϣ 
	DTOHIS_RemoteValChange_SQL,//2-����sql���
};
struct DispatchTaskData
{
	short taskType;
	FIELDTYPE dataType;
	icsvalue dataValue;
};

struct DispatchSetting
{
	//ҵ�����ݣ����ڷ�����Ϣ�����ȶ�
	DispatchTaskData taskData;
	//Զ�̵����·�����ѹ����Ϣ��ͬ�������ÿ�
	int toHisSave;//0-������ʷ�洢������Ϣ 1-����ѹ��仯��Ϣ 2-����sql���
	icsvalue saveData;
	//���ؿ����·���ͣ������Ϣ���ظ�����
	int senderType;
	char senderName[128];
};

#endif
