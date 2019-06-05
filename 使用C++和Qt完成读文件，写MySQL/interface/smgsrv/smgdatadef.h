//smgdatadef.h
#ifndef _SMGDATADEFINE_PENGSHIKANG_20080714_H_
#define _SMGDATADEFINE_PENGSHIKANG_20080714_H_

#include "../icsvalue.h"                         // for intarray
#include "genstatisdef.h"                        // for GeneClassStatisInfo

#define SMOOTHRAWNUMBER 200

#define MAINNETWORK   0 // �Դ����Ϊ����Դ
#define MAINGENERATOR 1 // ����ת�����Ϊ����Դ
#define MAINSTORAGE   2 // �Դ����豸Ϊ����Դ

#define ADDLOAD   1     // Ͷ�븺��
#define ADDGENERATOR 2  // Ͷ�뷢���
#define ADJUSTGEN   3   // ���ӷ��������

enum EquipmentType
{
	ET_UNKNOWN = 0,//δ֪�豸
	ET_SYSTEM,     //ϵͳ��Ϣ
	ET_GENERATOR,  //�����豸
	ET_STORAGE,    //�����豸
	ET_BUS,        //ĸ��
	ET_TRANSFORMER,//��ѹ��
	ET_LOAD,       //����
	ET_PCC,        //��������֧·
	ET_REPOWERCOMP,//�޹������豸
	ET_LINE,       //��·
};

enum PowerChangeState
{
	PCS_UNKNOWN = 0,//δ֪
	PCS_LOWER,      //Խ����
	PCS_NORMAL,     //����
	PCS_UPPER,      //Խ����
};

typedef struct 
{
	unsigned int count;
	int         isleIds[10];
	double      loadPs[10];
}islearray; // �����������ĸ������� [������10��������]

struct MicgridObectInfo
{
	int nMGPos;
	int nMGId;
	int nParentId;
	int nRunStyle0;//Ĭ������ģʽ
	int nRunStyle1;//��ǰ����ģʽ
	int nMainType;//�������豸���ͣ�=0���������=1����ת�������=2�������ܡ�
	int nMainStorPos;//�������豸Pos�� >= 0 Ϊ�������豸Pos��=-1 ����ת�����������Ϊ����Դ
	intarray mainSrcIds;//����ת�����豸ID�б�
	float sysFreq;//ϵͳƵ��
	float totalI; //ϵͳ����
	int freqState0;//�ϴ�Ƶ��״̬
	int powerState0;//�ϴ�Ƶ�ʹ���״̬

	islearray islandIds;//�����������ĸ�������
	int mainIsleId;
	
	//��������
	bool bIntoIsle;  //��������״̬ InitializeCombineEntry() -->false, InitializeIslandEntry() -->true
	double dIsleTime0;//���κ�������ʼ��ʱ��
	double dIsleTime;//���κ�������ʼ��ʱ��

	bool hasAct;    //�Ƿ��в��Զ���
	int respSeconds;//����Դ��Ӧʱ����[��]
	double dActTime;//�´β������Ե�ʱ��
	
	//�������Բ���
	int nExchPlanId;//�����������߼ƻ�ID[��ֵ]
	int nStorPlanId;//���ܷŵ����߼ƻ�ID[��ֵ]

	//PCC
	int connectFlag;//����״̬ [0--������1--����]  ok
	int breakerFlag;//��·����־ [0--������1--����] 
	float exchangeP;//ʵ�ʽ����й�����[����ĸ��Ϊ��] ok
	double exchangeQ[2];//ʵ�ʽ����޹�����[����ĸ��Ϊ��] ����VQC���޹�״̬�ж�
 	int nDoRecall;  //ִ�лָ�����״̬��0--ֹͣ�ָ���1--��ת���ָ���2--�޲��Իָ���3--�����ָ���
	int nLoadRecall;//���ɻָ�����״̬��0--ֹͣ�ָ���1--��ת���ָ���2--�޲��Իָ���3--�����ָ���
 	bool bGenRecall; //����ʱ�Ƿ��ڹ���ָ�״̬
	bool bStrategy;  //����ʱ�Ƿ����Զ�ִ�в���
	
	//����
	int nLoadSum;//���ɸ���[��ֵ] ok
	int nLoadNum[3];//�ּ����ɼ��ϳ���[��ֵ] ok
	intarray runLoad[3];//�Ӵ�С�����Ͷ�˵ķּ����ɼ��� ok
	intarray cutLoad[3];//�Ӵ�С�����δ�����г��ķּ����ɼ��� ok
	float cutLoadP;//δ�����г��ĸ��ɵĹ��� ok
	
	//�����
	int nGenNum;//���������[��ֵ] ok
	int nAdjGenNum;//Ͷ�˵Ŀɵ������������
	int nAdjOrder;//�ɵ��ڷ���������ִ�
	intarray mainGen;//������ó����Ӵ�С�����Ͷ�˵��������λ���б� ok
	intarray fixGen; //����ǰ�����Ӵ�С����Ĳ��ɵ��ڳ�����Ͷ�˵ķ��������λ���б� ok
	intarray newGen; //���������Ӵ�С����Ŀɵ��ڳ����������ķ��������λ���б�[��ֵ] ok
	intarray unewGen;//���������Ӵ�С����Ŀɵ��ڳ������������ķ��������λ���б�[��ֵ] ok
	intarray peakGen;//���������Ӵ�С�����Ͷ�˵ĵ��巢����б�
	intarray cutGen; //����󿹳�������Ӵ�С�����δ�����г��Ĳ��ɵ��ڷ����λ���� ok
	intarray cutAGen;//����󿹳�������Ӵ�С�����δ�����г��Ŀɵ��ڷ����λ���� ok

	//�������Ⱥ
	int nGroupNum;//�������Ⱥ����[��ֵ] ok
	intarray aGenGroup; //���������Ӵ�С����ķ������Ⱥλ���б�[��ֵ] ok

	float mainGenP;//Ͷ�˵�����������ܷ����й����� ok
	float fixGenP;//Ͷ�˵Ĳ��ɵ�������������ܷ����й����� ok
	float adjGenP;//Ͷ�˵Ŀɵ�������������ܷ����й����� ok
	float addAdjGenP;//Ͷ�˵Ŀɵ���������������������ӷ����й����� ok
	float backupP;//Ͷ�˵�����������ܱ����й����� ok
	float maxEcoP;//Ͷ�˵�����������ܾ����й��������� ok
	float minEcoP;//Ͷ�˵�����������ܾ����й��������� ok
	float maxAimP;//Ͷ�˵���������������Ŀ���й����� ok
	float minAimP;//Ͷ�˵��������������СĿ���й����� ok
	float maxGenP;//Ͷ�˵����������������й����� ok
	float minGenP;//Ͷ�˵��������������С�й����� ok
	float cutGenP;//δ�����г��ķ�������ܷ��繦�� ok
	float mainGenS;//Ͷ�˵���������������� ok
	float maxSensP;//Ͷ�˵��������������������� ok
	
	//����װ��
	intarray powerStor; //�Ӵ�С��������е��й��ɵ��Ĺ����ʹ���װ��
	intarray sortedStor;//�Ӵ�С��������е��й��ɵ��������ʹ���װ��
	intarray repowStor; //�Ӵ�С��������е��޹��ɵ��Ĵ���װ��

	float totalSCapa;//Ͷ�˵��������ܵ�����
	float maxSCapa;  //Ͷ�˵�������������������
	float minSCapa;  //Ͷ�˵�������������С������
	float curSCapa;  //Ͷ�˵������ܵ�ǰʣ�������

	float maxDchgP; //Ͷ�˴����ܵ����ŵ繦�� ok
	float maxChgP;  //Ͷ�˴����ܵ�����繦�� ok
	float optDchgP; //Ͷ�˴����ܵ����ŷŵ繦�� ok
	float optChgP;  //Ͷ�˴����ܵ����ų�繦�� ok
	float storplanP;//Ͷ�˴����ܵļƻ��й�����
	int socState;   //����SOC״̬
	float storpwrP0; //�ܵ�Ͷ�˵�����SOC�Ĺ����ʹ����й�����
	float storpwrP2; //�ܵ�Ͷ�˵��쳣SOC�Ĺ����ʹ��ܱ����Ե����й�
	float storenyP0; //�ܵ�Ͷ�˵�����SOC�������ʹ����й�����
	float storenyP2; //�ܵ�Ͷ�˵��쳣SOC�������ʹ��ܱ����Ե����й�

	//��΢��ʵʱ�Ļ��ܹ���
	GeneClassStatisInfo genSttsInfo[GT_INVALID];//���������ͳ����Ϣ
	float storageP; //�ܵ�Ͷ�˴����й�����
	float storageQ; //�ܵ�Ͷ�˴����޹�����
	float loadP;    //�ܵ��й�����
	float loadQ;    //�ܵ��޹�����
	float sensLoadP;//���������й�
	float sensLoadQ;//���������޹�
	float ctrlLoadP;//�ɿظ����й�
	float ctrlLoadQ;//�ɿظ����޹�
	float cutdLoadP;//���и����й�
	float cutdLoadQ;//���и����޹�

	//ƽ�����Ʋ���
	int nSmoothPos;  //ƽ�����Ƽ�¼λ��
	bool hasSmooth;  //ƽ�������Ƿ���Ч
	int nAimType;    //ƽ������Ŀ������
	float dMaxRatio; //ƽ�������������仯��
	double dSmothSpan;//�������Ƴ���ʱ�䣨������ת��Ϊ������
	//���������Ƿ���Ч
	bool hasEcnomic;  //���������Ƿ���Ч

	bool hasBaseP;
	bool isNewAimP;
	int prevPNum;//��ǰĿ�깦�ʸ���
	double smRawTime;//���ݲɼ�ʱ��
	double smothTime;//ƽ������ʱ��
	float prevExchP[SMOOTHRAWNUMBER];//��ǰ��������
	float prevGenP[SMOOTHRAWNUMBER];//��ǰ���繦��
	float prevStorP[SMOOTHRAWNUMBER];//��ǰʵ�ʴ��ܹ���
	float prevStopP[SMOOTHRAWNUMBER];//��ǰ�ƻ����ܹ���
	float prevLoadP[SMOOTHRAWNUMBER];//��ǰ���ɹ���
	float arvgExchP;//��ǰƽ����������
	float arvgGenP; //��ǰƽ�����繦��
	float arvgStorP;//��ǰƽ��ʵ�ʴ��ܹ���
	float arvgStopP;//��ǰƽ���ƻ����ܹ���
	float arvgLoadP;//��ǰƽ�����ɹ���
	float prevBaseP;//��ǰ��׼Ŀ�깦��
	float prevAimP; //��ǰĿ�깦��
	float curBaseP; //��ǰ��׼Ŀ�깦��
	float curAimP;  //��ǰĿ�깦��
	float maxOffsP; //��������Ŀ�깦��
	float curRatio; //��ǰ�仯��
	float curCompP; //��ǰ��������
	float nearState[3];//����ı仯��״̬
	int smoothFlag; //����ƽ�����Ʋ�������

	int storFCState;//���ܵ�Ƶ�ʵ���״̬ [0-δ���ڣ�1--������]
	int storVCState;//���ܵĵ�ѹ����״̬ [0-δ���ڣ�1--������] 

	float sysFreq0;//��һ��ϵͳƵ��
	float totalI0; //��һ��ϵͳ����
	float exchangeP0;//��һ�ν����й�����
	float mainGenP0;//��һ����������ܷ��繦��

	float todaySaleEnergy;//������������
	float totalSaleEnergy;//�ۼ���������
	float todayUseEnergy; //������������ 
	float totalUseEnergy; //�ۼ���������
	float adjGenP0;//Ͷ�˵Ŀɵ�������������������ܷ����й����� for ƽ��
	float addAdjGenP0;//Ͷ�˵Ŀɵ��������������������Ǳ�ڿ����ӷ����й����� for ƽ��
	float addAdjGenP1;//Ͷ�˵Ŀɵ��������������������Ǳ�ڿ����ӷ����й����� for �鲥-
	double emergeTime;//����֧�ſ�ʼʱ��
};

/*enum CONTROLTYPE     //���Ʋ�������
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
	CT_STOR_SET_REPOWER,    //20:���ڴ����޹�����
	CT_RACP_SWI_BREAK,      //21:�г��޹�����װ��
	CT_RACP_SWI_CONNECT,    //22:Ͷ���޹�����װ��
	CT_RACP_SET_POWER,      //23:�����޹�����װ���й�����
	CT_RACP_SET_REPOWER,    //24:�����޹�����װ���޹�����
	CT_TRANS_TAP_ASCEND,    //25:��ѹ���ֽ�ͷ��
	CT_TRANS_TAP_DESCEND,   //26:��ѹ���ֽ�ͷ��
	CT_TRANS_TAP_STOP,      //27:��ѹ���ֽ�ͷ��ͣ
	CT_END,
};

struct ControlLogInfo
{
	int controlId;//��ǰ����ID
	double ctrlTime;//��ǰ����ʱ��
	char ctrlKind[64];//��ǰ����ҵ��
	CONTROLTYPE ctrlType;//��ǰ��������
	int equipId;//��ǰ�����豸ID
	char stateVal0[64];//��ǰ����ǰ״̬
	char stateVal1[64];//��ǰ����Ŀ��״̬
	int isManCtrl;//��ǰ�����Ƿ�ȷ��ִ��
	char ctrlUser[200];//��ǰ����ȷ����
	int ctrlResult;//��ǰ���ƽ��
};*/

typedef struct
{
	int swithtype;           //�л��������ʣ�0����  1���� 2��������̬��
	intarray sonmicgrids;    //��΢���б���̬��
	int fathermicgridPos;    //��΢������̬��
	intarray toMainP;        //�л��������Դ(��̬)
	int mainptype;           //�л��������Դ����(��̬)0���� 1�������ͻ�Ϊ����Դ 2����pcsΪ����Դ
}switchgridobj;

//////////////////////////////////////////////////////////////////////////////////////

enum CONTROLBUSINESS //����ҵ��
{
	CB_UNKNOWN,               //0: δ�������ҵ��
	CB_MODESWITCH,            //1: ����ģʽ�л�
	CB_BLARKSTART,            //2: ������
	CB_ISLANDBALANCE,         //3: ��������ƽ��
	CB_CONTINENTRECALL,       //4: ����״̬�ָ�
	CB_EXCHANGEPOWER,         //5: �����й����ʿ���
	CB_POWERSMOOTH,           //6: �й�����ƽ������
	CB_VOLTAGEREPOWER,        //7: ��ѹ�޹�����
	CB_STORAGEPOWER,          //8: ���ܹ��ʿ���
	CB_STORAGESOC,            //9: ����SOCά��
	CB_DGAUTOSTOP,            //10:DGͣ��ά��
	CB_SCADASQCTRL,           //11:SCADA˳�����
};

enum CONTROLREASON //����ԭ��
{
	CR_UNKNOWN,                 // 0: δ�������ԭ��
	CR_RUNMODE_SWITCH=1,        // 1: ��������ģʽ�л����� ��
	CR_MODESWITCH_GENTOCONTI,   // 2: ��ת����Դ�л�����������ģʽ
	CR_MODESWITCH_STORTOCONTI,  // 3: PCS����Դ�л�����������ģʽ
	CR_MODESWITCH_CONTITOGEN,   // 4: ���������л�����ת����Դģʽ
	CR_MODESWITCH_CONTITOSTOR,  // 5: ���������л���PCS����Դģʽ
	CR_MODESWITCH_GENTOSTOR,    // 6: ��ת����Դ�л���PCS����Դģʽ
	CR_MODESWITCH_STORTOGEN,    // 7: PCS����Դ�л�����ת����Դģʽ
	CR_BLARKSTART=10,           //10: ������������� ��
	CR_BLARKSTART_BEFORE,       //11: ������ǰ��׼������
	CR_BLARKSTART_MAINSOURCE,   //12: ������һ������Դ
	CR_BLARKSTART_AFTER,        //13: ��������Ļָ�����
	CR_ISLAND_BALANCE=20,       //20: ������������ƽ�� ��
	CR_ISLAND_FREQ_LOWER,       //21: ����Ƶ��Խ����
	CR_ISLAND_FREQ_UPPER,       //22: ����Ƶ��Խ����
	CR_ISLAND_POWER_LOWER,      //23: ��������Դ����Խ��������
	CR_ISLAND_POWER_UPPER,      //24: ��������Դ����Խ��������
	CR_ISLAND_POWER_NORMAL,     //25: ��������Դ��������
	CR_ISLAND_DATA_UNNORMAL,    //26: ����������Ϣ�쳣
	CR_CONTINENT_CONTROL=30,    //30: ���벢���������� ��
	CR_CONTINENT_RECALL,		//31: ����״̬�ָ�
	CR_EMERGEXCHP_SUPPORT,      //32: �������ʽ���֧�ſ���
	CR_EMERGEXCHP_STOP,			//33: �������ʽ���ͣ�˿���
	CR_EXCHPOWER_ANTIINVERSE,   //34: ���潻���й����ʿ���
	CR_EXCHPOWER_FIXEDVALUE,    //35: �������й����ʿ���
	CR_EXCHPOWER_CURVE,         //36: �����й���������ά��
	CR_SMOOTH_EXCHPOWER=41,     //41: �����й�����ƽ��
	CR_SMOOTH_DGPOWER,          //42: �ֲ�ʽ��Դ����ƽ��
	CR_VOLTAGE_REACTPOWER=50,   //50: �����ѹ�޹��Զ����� ��
	CR_VQC_VOLT_LOWER,          //51: ��ѹԽ�����Զ�����
	CR_VQC_VOLT_UPPER,          //52: ��ѹԽ�����Զ�����
	CR_VQC_REPOWER_LOWER,       //52: �޹�Խ�����Զ�����
	CR_VQC_REPOWER_UPPER,       //53: �޹�Խ�����Զ�����
	CR_VQC_POWFACTOR_LOWER,     //54: ��������Խ���޿���
	CR_VQC_POWFACTOR_UPPER,     //55: ��������Խ���޿���
	CR_STOEAGEPOWER_CURVE=61,   //61: �����й���������ά��
	CR_STOEAGEPOWER_KEEP,       //62: �����й�����ά��
	CR_STOEAGEREPOWER_KEEP,     //63: �����޹�����ά��
	CR_STOEAGESOC_KEEP,         //64: ����SOC����ά��
	CR_STOEAGESOC_LOWER,        //65: ����SOCԽ���޿���
	CR_STOEAGESOC_UPPER,        //66: ����SOCԽ���޿���
	CR_DGNOPOWER_STOP=71,       //71: DG����ͣ��תͣ������
	CR_SEQUENCTRL_MANUAL=81,    //81: �˹�˳�����
	CR_SEQUENCTRL_TIMER,        //82: ��ʱ˳�����
	CR_SEQUENCTRL_TRIGGER,      //83: ��������˳�����
};

enum CONTROLINDEX //��������
{
	CI_UNDEFINE,                // 0---0: δ�������ԭ��
	CI_RUNMODE_SWITCH,          // 1---1: ��������ģʽ�л����ƣ�
	CI_MODESWITCH_GENTOCONTI,   // 2---2: ģʽ�л�������Դ�й���������
	CI_MODESWITCH_STORTOCONTI,  // 3---3: ģʽ�л�������Դ�й���������
	CI_MODESWITCH_CONTITOGEN,   // 4---4: ����pcc���й�Ϊ0
	CI_MODESWITCH_CONTITOSTOR,  // 5---5: ����pcc���޹�Ϊ0
	CI_MODESWITCH_GENTOSTOR,    // 6---6: �·�ģʽ�л�����
	CI_MODESWITCH_STORTOGEN,    // 7---7: ģʽ�л�������Դ�޹���������������
	CI_BLARKSTART,              // 8--10: ��ʼ���������� ��
	CI_BLARKSTART_BEFORE,       // 9--11: ������ǰ��׼������
	CI_BLARKSTART_MAINSOURCE,   //10--12: ������һ������Դ
	CI_BLARKSTART_AFTER,        //11--13: ��������Ļָ�����
	CI_ISLAND_BALANCE,          //12--20: ��ʼ��������ƽ�� ��
	CI_ISLAND_FREQ_LOWER,       //13--21: ����Ƶ��Խ����
	CI_ISLAND_FREQ_UPPER,       //14--22: ����Ƶ��Խ����
	CI_ISLAND_POWER_LOWER,      //15--23: ��������Դ����Խ��������
	CI_ISLAND_POWER_UPPER,      //16--24: ��������Դ����Խ��������
	CI_ISLAND_POWER_NORMAL,     //17--25: ��������Դ��������
	CI_ISLAND_DATA_UNNORMAL,    //18--26: ����������Ϣ�쳣
	CI_CONTINENT_CONTROL,       //19--30: ��ʼ������������ ��
	CI_CONTINENT_RECALL,        //20--31: ����״̬�ָ�
	CI_EMERGEXCHP_SUPPORT,      //21--32: �������ʽ���֧�ſ���
	CI_EMERGEXCHP_STOP,			//22--33: �������ʽ���ͣ�˿���
	CI_EXCHPOWER_ANTIINVERSE,   //23--34: ���潻���й����ʿ���
	CI_EXCHPOWER_FIXEDVALUE,    //24--35: �������й����ʿ���
	CI_EXCHPOWER_CURVE,         //25--36: �����й���������ά��
	CI_SMOOTH_EXCHPOWER,        //26--41: �����й�����ƽ��
	CI_SMOOTH_DGPOWER,          //27--42: �ֲ�ʽ��Դ����ƽ��
	CI_VQC,                     //28--50: ��ʼ��ѹ�޹��Զ����� ��
	CI_VQC_VOLT_LOWER,          //29--51: ��ѹԽ�����Զ�����
	CI_VQC_VOLT_UPPER,          //30--52: ��ѹԽ�����Զ�����
	CI_VQC_REPOWER_LOWER,       //31--52: �޹�Խ�����Զ�����
	CI_VQC_REPOWER_UPPER,       //32--53: �޹�Խ�����Զ�����
	CI_VQC_POWFACTOR_LOWER,     //33--54: ��������Խ���޿���
	CI_VQC_POWFACTOR_UPPER,     //34--55: ��������Խ���޿���
	CI_STOEAGEPOWER_CURVE,      //35--61: �����й���������ά��
	CI_STOEAGEPOWER_KEEP,       //36--62: �����й�����ά��
	CI_STOEAGEREPOWER_KEEP,     //37--63: �����޹�����ά��
	CI_STOEAGESOC_KEEP,         //38--64: ����SOC����ά��
	CI_STOEAGESOC_LOWER,        //39--65: ����SOCԽ���޿���
	CI_STOEAGESOC_UPPER,        //40--66: ����SOCԽ���޿���
	CI_DGNOPOWER_STOP,          //41--71: DG����ͣ��תͣ������
	CI_SEQUENCTRL_MANUAL,       //42--81: �˹�˳�����
	CI_SEQUENCTRL_TIMER,        //43--82: ��ʱ˳�����
	CI_SEQUENCTRL_TRIGGER,      //44--83: ��������˳�����
};

const struct ControlReason
{
	CONTROLBUSINESS ctrlTask;
	CONTROLREASON ctrlCause;
	char ctrlDescr[64];
} 
g_ctrlReasons[] = 
{
	{ CB_UNKNOWN,    CR_UNKNOWN,                 "δ�������ҵ��" },
	{ CB_MODESWITCH, CR_RUNMODE_SWITCH,          "ģʽ�л�" }, // ��
	{ CB_MODESWITCH, CR_MODESWITCH_GENTOCONTI,   "ģʽ�л�" },
	{ CB_MODESWITCH, CR_MODESWITCH_STORTOCONTI,  "ģʽ�л�" },
	{ CB_MODESWITCH, CR_MODESWITCH_CONTITOGEN,   "ģʽ�л�" },
	{ CB_MODESWITCH, CR_MODESWITCH_CONTITOSTOR,  "ģʽ�л�" },
	{ CB_MODESWITCH, CR_MODESWITCH_GENTOSTOR,    "ģʽ�л�" },
	{ CB_MODESWITCH, CR_MODESWITCH_STORTOGEN,    "ģʽ�л�" },
	{ CB_BLARKSTART, CR_BLARKSTART,              "���ں�����" }, // ��
	{ CB_BLARKSTART, CR_BLARKSTART_BEFORE,       "������-����ǰ׼��" },
	{ CB_BLARKSTART, CR_BLARKSTART_MAINSOURCE,   "������-����һ������Դ" },
	{ CB_BLARKSTART, CR_BLARKSTART_AFTER,        "������-������ָ�" },
	{ CB_ISLANDBALANCE, CR_ISLAND_BALANCE,       "������������ƽ��" }, // ��
	{ CB_ISLANDBALANCE, CR_ISLAND_FREQ_LOWER,    "��������ƽ��-Ƶ��Խ����" },
	{ CB_ISLANDBALANCE, CR_ISLAND_FREQ_UPPER,    "��������ƽ��-Ƶ��Խ����" },
	{ CB_ISLANDBALANCE, CR_ISLAND_POWER_LOWER,   "��������ƽ��-����Դ����Խ����" },
	{ CB_ISLANDBALANCE, CR_ISLAND_POWER_UPPER,   "��������ƽ��-����Դ����Խ����" },
	{ CB_ISLANDBALANCE, CR_ISLAND_POWER_NORMAL,  "��������ƽ��-����Դ��������" },
	{ CB_ISLANDBALANCE, CR_ISLAND_DATA_UNNORMAL, "��������ƽ��-�ɼ������쳣" },
	{ CB_CONTINENTRECALL, CR_CONTINENT_CONTROL,  "���ڲ�����������" }, // ��
	{ CB_CONTINENTRECALL, CR_CONTINENT_RECALL,   "������������-����״̬�ָ�" },
	{ CB_EXCHANGEPOWER, CR_EMERGEXCHP_SUPPORT,   "������������-�������ʽ���֧�ſ���" },
	{ CB_EXCHANGEPOWER, CR_EMERGEXCHP_STOP,      "������������-�������ʽ���ͣ�˿���" },
	{ CB_EXCHANGEPOWER, CR_EXCHPOWER_ANTIINVERSE,"������������-���潻���й����ʿ���" },
	{ CB_EXCHANGEPOWER, CR_EXCHPOWER_FIXEDVALUE, "������������-�������й����ʿ���" },
	{ CB_EXCHANGEPOWER, CR_EXCHPOWER_CURVE,      "������������-�����й���������ά��" },
	{ CB_POWERSMOOTH, CR_SMOOTH_EXCHPOWER,       "������������-�����й�����ƽ��" },
	{ CB_POWERSMOOTH, CR_SMOOTH_DGPOWER,         "������������-�ֲ�ʽ��Դ����ƽ��" },
	{ CB_VOLTAGEREPOWER, CR_VOLTAGE_REACTPOWER,  "���ڵ�ѹ�޹��Զ�����" }, // ��
	{ CB_VOLTAGEREPOWER, CR_VQC_VOLT_LOWER,      "VQC-��ѹԽ����" },
	{ CB_VOLTAGEREPOWER, CR_VQC_VOLT_UPPER,      "VQC-��ѹԽ����" },
	{ CB_VOLTAGEREPOWER, CR_VQC_REPOWER_LOWER,   "VQC-�޹�Խ����" },
	{ CB_VOLTAGEREPOWER, CR_VQC_REPOWER_UPPER,   "VQC-�޹�Խ����" },
	{ CB_VOLTAGEREPOWER, CR_VQC_POWFACTOR_LOWER, "VQC-��������Խ����" },
	{ CB_VOLTAGEREPOWER, CR_VQC_POWFACTOR_UPPER, "VQC-��������Խ����" },
	{ CB_STORAGEPOWER, CR_STOEAGEPOWER_CURVE,    "���ܳ���ά��-�й���������ά��" },
	{ CB_STORAGEPOWER, CR_STOEAGEPOWER_KEEP,     "���ܳ���ά��-�й�����ά��" },
	{ CB_STORAGEPOWER, CR_STOEAGEREPOWER_KEEP,   "���ܳ���ά��-�޹�����ά��" },
	{ CB_STORAGESOC, CR_STOEAGESOC_KEEP,         "����SOCά��-SOC����" },
	{ CB_STORAGESOC, CR_STOEAGESOC_LOWER,        "����SOCά��-SOCԽ����" },
	{ CB_STORAGESOC, CR_STOEAGESOC_UPPER,        "����SOCά��-SOCԽ����" },
	{ CB_DGAUTOSTOP, CR_DGNOPOWER_STOP,          "DGͣ��ά��-����ͣ��תͣ������" },
	{ CB_SCADASQCTRL, CR_SEQUENCTRL_MANUAL,      "SCADA˳�����-�˹�˳��" },
	{ CB_SCADASQCTRL, CR_SEQUENCTRL_TIMER,       "SCADA˳�����-��ʱ˳��" },
	{ CB_SCADASQCTRL, CR_SEQUENCTRL_TRIGGER,     "SCADA˳�����-��������˳��" },
};

const int g_ctrlReasonNum = sizeof(g_ctrlReasons) / sizeof(ControlReason);

inline int GetControlBusinessIndex(int ctrlReason)
{
	for(int index = 0; index < g_ctrlReasonNum; ++index)
	{
		if(g_ctrlReasons[index].ctrlCause == ctrlReason) return index;
	}
	return 0;
};

#endif
