#ifndef _PROTECTREPORTINTF_H_
#define _PROTECTREPORTINTF_H_

#include "objsintf.h"
typedef unsigned char BYTE;

#define IID_ICallReport		    "ICallProtReport"   //��������
#define IID_IProtectSinker      "IProtectSinker"
#define IID_IProtectObject      "IProtectObject"
#define IID_ISave               "ISave"
#define IID_IGetReport          "IGetReport"
#define IID_IProtectClient      "IProtectClient"
#define OPCLSID_CallReport		"callreport"      //��������
#define OPCLSID_ProtectObject	"protectobject"      //��������
#define OPCLSID_ProtectProcess  "protectprocess"


#define OPCLSID_CallEvent       "callevent"         //�Լ챨��������¼�����
#define IID_ICallEvent          "ICallEventReport"  //�Լ챨��������¼�����
/*
	[��  ��]	���屣������������ؽӿ�
*/
#define TASK_TYPE_PROTECT		"protect"			// ҵ�����ͣ�������������
#define MODULE_PROTOBJECT		"protectobject"
#define	MODULE_PROTCLIENT		"protectclient"


// �����������
typedef enum
{	
	pt_permanent = 0,			// �����Թ���
	pt_instant,					// ˲ʱ�Թ���
	pt_dimness,					// �������ʲ����
} PROTECT_TYPE;

static char* PROTECT_TYPE_DESC[] = { "�����Թ���", "˲ʱ�Թ���", "�������ʲ����" };

// ����������
typedef enum
{
	pp_dimness = 0,	pp_w1,	pp_w2,	// �������ȷ��
	pp_a,		pp_w4,	pp_b,	// ����ӵع���
	pp_ab,		pp_abn,	pp_w8,	// ������
	pp_c,		pp_ca,	pp_can,	// ���ӵع���
 	pp_bc,		pp_bcn,	pp_abc,	// �������
	pp_abcn,					
	
} PROTECT_PHASE;

static char* PROTECT_PHASE_DESC[] = {
		"",					"",					"",
		"A�ౣ������",		"",					"B�ౣ������",		
		"AB����",			"ABN����",			"",		
		"C�ౣ������",		"CA�ౣ������",		"CAN����",
		"BC�ౣ������",		"BCN����",			"ABC���ౣ������",		
		"ABCN����"
};

/*
static char* PROTECT_PHASE_DESC[] = {
	"A�ౣ������",		"B�ౣ������",	"C�ౣ������",
	"AN����",			"BN����",		"CN����",
	"AB�ౣ������",		"BC�ౣ������", "CA�ౣ������",
	"ABN����",			"BCN����",		"CAN����",
	"ABC���ౣ������",	"ABCN����",
	"�������ȷ��" 
};
*/

// �����װ�ö������淵������
typedef enum
{	
  	pt_has = 0,		         	// �д˹��ϱ���
		pt_no,					// �޴˹��ϱ���
		pt_end,					// �������
} PROTECT_RESULT;

static char* PROTECT_RESULT_DESC[] = { "�д˹��ϱ���", "�޴˹��ϱ���", "�������" };

// �����װ�ö������淵������
typedef enum
{	

	pt_nouse = 0,                    // ����
	    pt_return, 		         	// ����
		pt_start,					// ����
		pt_unused,					// ����
} ACTION_STATE;

static char* ACTION_STATE_DESC[] = {"����", "����", "����", "����" };

/*
	�����������棭����ӿ�
*/
class IProtectObject : public IICSUnknown
{
public:
	virtual int GetCpuNo() = 0;							// CPU��	
	virtual int GetSinNo() = 0;							// ���ϱ������
	virtual int GetFaultOrder() = 0;						// ������� 	
		 
	virtual int GetStationId() = 0;                        // ��վID
	virtual int GetBayId() = 0;                            // ���ID
	virtual int GetDevId() = 0;							// װ��ID
	
	virtual void GetDevName(char* name, int size) = 0;		// װ������	

	virtual int GetSoeId() = 0;                            //SoeID
	virtual void GetProtName(char* name, int size) = 0;		// ����Ԫ������
	
	virtual ACTION_STATE GetActionState() = 0;				// ����״̬
    virtual void GetActionDesc(char* desc, int size) = 0;	// ����״̬����
	
	virtual PROTECT_PHASE GetProtectPhase() = 0;            //�������
    virtual void GetPhaseDesc(char* desc, int size) = 0;	// ���ౣ����������
	
	virtual PROTECT_TYPE  GetProtectType() = 0;             //��������
	virtual void GetTypeDesc(char* desc, int size) = 0;		// ������������
	
	virtual int GetRelativeTime() = 0;						// �����������ʱ��
	virtual double GetStartUpTime() = 0;					// ����ʱ��	
	    
	virtual int GetValueCount() = 0;						// ����ֵ��Ŀ
	virtual void GetValueNameByIndex(int index, char* name, int size) = 0;	// ����ֵ����
	virtual double GetValueByIndex(int index) = 0;			// ����ֵ��ֵ
	
	//����soeidȡ�ö���Ԫ������
	virtual void GetParaNameBySoe(int soe) = 0;

    virtual int GetTimeOut() = 0;
	virtual void SetTimeOut(int t) = 0;

	virtual void SetStationId(int id ) = 0;                        // ��վID
	virtual void SetBayId(int id) = 0;                            // ���ID
	virtual void SetDevId(int value) = 0;					// װ��ID
	virtual void SetCpuNo(int value) = 0;					// CPU��
	virtual void SetSinNo(int value) = 0;                  //���ϱ������	
	virtual void SetSoeId(int value,bool b) = 0;
	
	virtual void AddValueName(int index,char* sValueName) = 0;
	virtual void SetDevName(char* name) = 0;
	virtual void SetProtectName(char* name) = 0;
	
	virtual void SetFaultOrder(int value) = 0;				// �������	
	virtual void SetRelativeTime(int time) = 0;			// �����������ʱ��
	virtual void SetStartUpTime(double time) = 0;			// ����ʱ��	
	virtual void SetActionState(ACTION_STATE state) = 0;    // ����״̬
	virtual void SetType(PROTECT_TYPE type) = 0;			// ����������������
	virtual void SetPhase(PROTECT_PHASE phase) = 0;			// �������	
	 
	virtual void AddProtValue(int index, double value) = 0;	// ���ñ�����������ֵ
};

/*
	�����������棭�����߽ӿڣ���HMIʵ�֣�
*/
class IProtectConsumer : public IICSUnknown
{
public:
	//HMI���ն�������
	virtual void OnProtComing(IProtectObject* pProtObject) = 0;
};

/*
	�����������棭�ͻ��˽ӿ�
*/
class IProtectClient : public IICSUnknown
{
public:
	// ��HMI���ߴ洢ģ�飬�ύ������������
	virtual void PostProtect(IProtectObject* pProtObject) = 0;	
	//ע��/��ע�������߽ӿ�, bLocal=true��ʾ���ط������
	virtual bool RegisterConsumer(IProtectConsumer* pConsumer/*, bool bLocal = false*/) = 0;
	virtual bool UnRegisterConsumer(IProtectConsumer* pConsumer) = 0;
};

/*
	�����������棭ҵ��ͻ��������˽����ӿ�
*/
class ICallProtReport : public IICSUnknown
{
public:
	virtual void SetDevId(int value) = 0;					// װ��ID
	virtual void SetCpuNo(int value) = 0;					// CPU��
	virtual void SetSinNo(int value) = 0;                  //���ϱ������

    virtual int GetDevId() = 0;
	virtual int GetCpuNo() = 0;
	virtual int GetSinNo() = 0;

	virtual int GetProtects(IICSEnum** ppEnum)=0;
	virtual void AddProtect(IProtectObject* pProtectObject) = 0;

	virtual void SetProtectInput(IProtectObject* ProtectObject) = 0;
	virtual void GetProtectObject(IProtectObject** ppProtObject) = 0;
};

#define SQL_LONG_PARAM_IS_NOT_USE 0X0FFFFFFF
//��ȡ��������ӿڣ����ݿ����ģ��ʵ�֣�
class IGetReport : public IICSUnknown
{
public:
	//���ݼ����װ�ã���ѯĳ��ʱ���ڵĶ�������
	/*!
	\brief ���ݼ����װ�ã���ѯĳ��ʱ���ڵĶ�������
	@param[in]    starttime     ��ʼʱ�䣬ʹ�� CDateTime 
	@param[in]    EndTime       ����ʱ�䣬ʹ�� CDateTime 
	@param[out]   ppObjectList  �������
	@param[in]    Bay           �����
	@param[in]    nDev          װ�ú�
	*/	
	virtual void GetReport(double StartTime, double EndTime,long Bay,
		long nDev, IICSEnum** ppObjectList) = 0; 
	
	
		/*!
		\brief ���� ʱ��Σ�����ţ�װ�úţ�cpu �� ��������������
	       ����ʱ����⣬����ţ�װ�úţ�cpu �� �Ȳ������ǿ�ѡ�ģ�
		   ���������ĳ�����������Ǹò���ʹ��Ĭ��ֵ������ò������ڼ�������Ч
		   @param[in]    starttime     ��ʼʱ�䣬ʹ�� CDateTime 
		   @param[in]    EndTime       ����ʱ�䣬ʹ�� CDateTime 
		   @param[out]   ppObjectList  �������
		   @param[in]    nDev          װ�ú� 
		   @param[in]    CpuNo         CPU �� 
		   @param[in]    SqlWhere      �������������ʾ����cpuno < 20 and devid > 2000
		   @param[in]    GetRecFrom    �Ӹ�λ�ÿ�ʼ��ȡ��¼ 
		   @param[in]    GetRecNumber  ��ȡָ�������ļ�¼ 
		   \return       ����ֵΪ���ϼ��������ļ�¼��������ѯʧ�ܷ��� -1
	*/
	/*Created by ��չ�� 2008/01/16 */
	virtual int GetReport(double StartTime, double EndTime,IICSEnum** ppObjectList , 
		long Bay = SQL_LONG_PARAM_IS_NOT_USE, long nDev = SQL_LONG_PARAM_IS_NOT_USE, 
		long CpuNo = SQL_LONG_PARAM_IS_NOT_USE,	const char * SqlWhere="", 
		long GetRecFrom = 0 , long GetRecNumber = SQL_LONG_PARAM_IS_NOT_USE ) = 0; 
};


/*
	�������¼�������Լ챨�棭ҵ��ͻ��������˽����ӿ�
*/
class ICallEventReport : public IICSUnknown
{
public:
	virtual void SetDevId(int value) = 0;					// װ��ID
	virtual void SetSinNo(int value) = 0;                  //�¼�������Լ챨�汨�����

    virtual int GetDevId() = 0;
	virtual int GetSinNo() = 0;

	virtual int GetEvents(IICSEnum** ppEnum)=0;
	virtual void AddEvent(IProtectObject* pProtectObject) = 0;

};




#define	MODULE_PROTECTCTRL	"ProtectCtrlClient"
#define MODULE_PROTECTCOMPS	"ProtectComps"



#endif