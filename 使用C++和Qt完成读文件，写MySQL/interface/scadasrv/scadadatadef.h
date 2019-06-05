//scadadatadef.h
#ifndef _SCADADATADEFINE_PENGSHIKANG_20080714_H_
#define _SCADADATADEFINE_PENGSHIKANG_20080714_H_

#include "../idataproxy.h"             // for CAPP_SDO_Status

#define TOUPPERALARMID  101 //Խ���ޱ�������ID
#define TOLOWERALARMID  102 //Խ���ޱ�������ID
#define TOUUPPERALARMID 103 //Խ�����ޱ�������ID
#define TOLLOWERALARMID 104 //Խ�����ޱ�������ID
#define TONORMALALARMID 105 //Խ�޻ָ���������ID
#define TOABRUPTALARMID 106 //���䱨������ID

#define TOSOEALARMID    305 //SOE��������ID
#define TOREVERTALARMID 308 //���鳬ʱ��������ID
#define TOCHANGECOUNTID 309 //������λ����Խ�ޱ�������ID
#define TOFAULTCOUNTID  310 //�¹ʱ�λ����Խ�ޱ�������ID
#define TODISCORDALMID  311 //˫λ��ң������һ�±�������ID
#define TOCHANNELALMID  1001//ͨ��״̬�����������ID
#define TOCHANNELEXCID  1002//ͨ��״̬�л�Ϊ����������ID

enum QUALITYPE
{
	QT_UNINIT=1,    //δ��ʼ��
	QT_DATAOVER,    //���
	QT_METEROVER,   //��ֵ��
	QT_DISCORD,     //��һ��
	QT_DOUBLTFUL,   //����
	QT_FAULT,       //����
	QT_OLDDATA,     //������
	QT_NORMAL=8,    //����
	QT_UNCHANGE,    //����
	QT_ABRUPT,      //����
	QT_UUPPEROVER,  //Խ������
	QT_UPPEROVER,   //Խ����
	QT_LOWEROVER,   //Խ����
	QT_LLOWEROVER,  //Խ������
};

enum STATUSTYPE     //״ֵ̬����
{
	ST_UNKNOWN,        //�ޡ�δ֪
		ST_SWI_BREAK,      //1:���ط�
		ST_SWI_CONNECT,    //2:���غ�
		ST_EQP_STOP,       //3:�豸ֹͣ
		ST_EQP_START,      //4:�豸����
		ST_ALM_FAULT,      //5:�豸���ϡ��¹��źŶ���
		ST_ALM_EXCEP,      //6:Ԥ���źŶ���
		ST_INF_BEFALL,     //7:�����źŶ���
		ST_INF_RESET,      //8:�źŸ���
		ST_RYB_EXIT,       //9:��ѹ���˳�
		ST_RYB_RUN,        //10:��ѹ��Ͷ��
		ST_EQP_REPAIR,     //11���豸����
		ST_MOD_VF,         //12:VFģʽ
		ST_MOD_PQ,         //13:PQģʽ
		ST_SYS_PARALLEL,   //14:����
		ST_SYS_ISOLATED,   //15:����
		ST_SYS_ENABLE,     //16:����/����/�����ŵ�
		ST_SYS_DISABLE,    //17:����/����/��ֹ��ŵ�
		ST_STOR_START,     //18:���ܺ�����
		ST_GEN_STANDBY,    //19:��Դ��������
		ST_GEN_LMTPOWER,   //20:��Դ�޹���
		ST_END,
		ST_TAP_ASCEND=25,  //05:�ֽ�ͷ��
		ST_TAP_DESCEND,    //06:�ֽ�ͷ��
		ST_TAP_STOP,       //07:�ֽ�ͷ��ͣ
};

enum OPERATETYPE     //���Ʋ�������
{
	OT_UNKNOWN,        //�ޡ�δ֪
		OT_SWI_BREAK,      //1:���ط�
		OT_SWI_CONNECT,    //2:���غ�
		OT_EQP_STOP,       //3:�豸ֹͣ
		OT_EQP_START,      //4:�豸����
		OT_TAP_ASCEND,     //5:�ֽ�ͷ��
		OT_TAP_DESCEND,    //6:�ֽ�ͷ��
		OT_TAP_STOP,       //7:�ֽ�ͷ��ͣ
		OT_INF_RESET,      //8:�źŸ���
		OT_RYB_EXIT,       //9:��ѹ���˳�
		OT_RYB_RUN,        //10:��ѹ��Ͷ��
		OT_SETAREA_ALTER,  //11:��ֵ���л�
		OT_MOD_VF,         //12:VFģʽ�л�
		OT_MOD_PQ,         //13:PQģʽ�л�
		OT_SYS_PARALLEL,   //14:����
		OT_SYS_ISOLATED,   //15:����
		OT_SYS_ENABLE,     //16:����/����
		OT_SYS_DISABLE,    //17:����/����
		OT_STOR_START,     //18:���ܺ�����
		OT_SYS_SWITCH,     //19:���з�ʽ�л�
		//OT_STANDBY,        //20:����
		OT_END,
};

typedef struct 
{
	double dealTime;          //����ʱ��
	CAPP_SDO_Status* pObject; //״̬������
	int objId;                //״̬��ID
	int objPos;               //״̬��λ��
	int ssrcPos;              //״̬��������Դλ��
	int calValue;             //����ֵ
}WaitingStatus, *PWaitingStatus;//�ȴ������״̬������

typedef struct 
{
	double dealTime;          //����ʱ��
	int objId;                //״̬��ID
	int objPos;               //״̬��λ��
	int ssrcPos;              //״̬��������Դλ��
	int alarmId;              //��������ID
}RevertStatus, *PRevertStatus;//�ȴ����鳬ʱ������״̬������

typedef struct 
{
	double dealTime;          //����ʱ��
	CAPP_SDO_Status* pObject1;//״̬������1
	CAPP_SDO_Status* pObject2;//״̬������2
	int eqpId;                //�豸ID
	int objId1;               //״̬��ID1
	int objId2;               //״̬��ID2
	int objPos1;              //״̬��λ��1
	int objPos2;              //״̬��λ��2
	int srcPos1;              //״̬��������Դλ��1
	int srcPos2;              //״̬��������Դλ��2
	int calValue1;            //����ֵ1
	int calValue2;            //����ֵ2
}DoubleStatus, *PDoubleStatus;//˫λ��״̬������

struct CtrlGroup //һ����صĿ�����
{
	int groupId;
	int count;
	int* ctrlIds;
};

struct AlarmObjectInfo
{
	double dTime;     //��������ʱ��
	int nObjId;       //��������ID
	char objType[32]; //������������
	char objDesc[128];//������������
	char objPath[64]; //��������·��
	char almPage[64]; //�����ƻ����ļ�
	char almVoice[64];//���������ļ�
	char almUserId[64];//����ȷ����ID
};

struct MultSrcObjInfo
{
	int m_priority;
	int m_position;
	int m_commSrcId;
	int m_commPointId;
};

enum CONTROLTYPE     //���Ʋ�������
{
	CT_EQUIP_UNKNOWN,       // 0:�ޡ�δ֪

	CT_MICG_SYS_PARALLEL,   // 1:΢��������
	CT_MICG_SYS_ISOLATED,   // 2:΢��������

	CT_LOAD_SWI_BREAK,      // 3:�г�����
	CT_LOAD_SWI_CONNECT,    // 4:Ͷ�븺��

	CT_GENE_SWI_BREAK,      // 5:�г������
	CT_GENE_SWI_CONNECT,    // 6:Ͷ�뷢���
	CT_GENE_EQP_STOP,       // 7:ֹͣ�����
	CT_GENE_EQP_START,      // 8:���������
	CT_GENE_MOD_VF,         // 9:������л�ΪVFģʽ
	CT_GENE_MOD_PQ,         //10:������л�ΪPQģʽ
	CT_GENE_INF_RESET,      //11:��������ϸ���
	CT_GENE_SET_POWER,      //12:���ڷ�����й�����
	CT_GENE_SET_REPOWER,    //13:���ڷ�����޹�����
	CT_STOR_EQP_STOP,       //14:ֹͣ����
	CT_STOR_EQP_START,      //15:��������
	CT_STOR_MOD_VF,         //16:�����л�ΪVFģʽ
	CT_STOR_MOD_PQ,         //17:�����л�ΪPQģʽ
	CT_STOR_INF_RESET,      //18:���ܹ��ϸ���
	CT_STOR_SET_POWER,      //19:���ڴ����й�����
	CT_STOR_SET_SOC,        //20:��ά��SOC�����ڴ����й�����++
	CT_STOR_SET_REPOWER,    //21:���ڴ����޹�����

	CT_RACP_SWI_BREAK,      //22:�г��޹�����װ��
	CT_RACP_SWI_CONNECT,    //23:Ͷ���޹�����װ��
	CT_RACP_SET_POWER,      //24:�����޹�����װ���й�����
	CT_RACP_SET_REPOWER,    //25:�����޹�����װ���޹�����

	CT_TRANS_TAP_ASCEND,    //26:��ѹ���ֽ�ͷ��
	CT_TRANS_TAP_DESCEND,   //27:��ѹ���ֽ�ͷ��
	CT_TRANS_TAP_STOP,      //28:��ѹ���ֽ�ͷ��ͣ

	CT_MICG_SYS_SWITCH,     //29:΢�������з�ʽ�л�
	CT_MICG_SYS_ABNORMAL,   //30:΢�������������쳣

	CT_GROUP_CONTROL,       //31:˳�����

	CT_STOR_SWI_BREAK,      //32:�г�����
	CT_STOR_SWI_CONNECT,    //33:Ͷ�봢��

	CT_END,
};

struct ControlLogInfo
{
	//double operateId;//���β�����ʶ��
	int smgId;//��ǰ΢����ID
	int equipId;//��ǰ�豸ID
	int controlId;//��ǰ����ID
	double ctrlTime;//��ǰ����ʱ��
	//char ctrlKind[64];//��ǰ����ҵ��
	CONTROLTYPE ctrlType;//��ǰ��������
	char stateVal0[64];//��ǰ����ǰ״̬
	char stateVal1[64];//��ǰ����Ŀ��״̬
	int isManCtrl;//��ǰ�����Ƿ�ȷ��ִ��
	char ctrlUser[256];//��ǰ����ȷ����
	int ctrlResult;//��ǰ���ƽ��
	int ctrlReason;//��ǰ����ԭ��
	int equipType;//��ǰ�����豸����
};

enum CONTROLORIGIN
{
	MANUCTRL, AUTOCTRL, DISPCTRL,
};

enum AUTOEXECUTESELECTCMD
{
	AESC_STOP,        //0--ֹͣ�Զ�ִ��
	AESC_SELECT,      //1--�����Զ�ִ��
	AESC_CONTROL,     //2--ѡ���Զ�תֱ��
	AESC_NOGUARD,     //3--�����໤�Զ�ִ��
};

typedef struct 
{
	int statusId;             //״̬��ID
	int curValue;             //��ǰֵ
	double curTime;           //��ǰʱ��
	int lastValue;            //�ϴ�ֵ
	double lastTime;          //�ϴ�ʱ��
	int faultNum;             //���ϱ�λͳ�ƴ���
}HisStatusInfo, *PHisStatusInfo;//ң������λ�����ʷ�洢��Ϣ

#endif
