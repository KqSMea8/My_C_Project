#ifndef IRAWCTRL_H
#define IRAWCTRL_H

#include "./scadactrl_defines.h"
#include "../icsunknown.h"

typedef struct {
	typedef enum {	/* ���Ʋ���ö�� */
		UNKNOWN,
		SELECT = 1,		/* ѡ���� */
		EXEC,			/* ִ���� */
		CANCEL			/* ������ */
	} CMDType;

	typedef enum {	/* ������ö�� */
		UNCONTROL,      /* �ǿ����� */
		MAINLOGIC,      /* ���߼������� */
		CALLDATA,		/* �ٲ����ݿ����� */
		SYSRESET,		/* ϵͳ��������� */
		SETTING,        /* ��ֵ�·��� */ // psk 2011-10-26
	} CLSType;
	
	typedef enum {	/* IRawCtrl::ErrNo() ����ֵ���� */
		ECSRVBUSY = 1,	/* ϵͳ��æ���޷�����ǰ���� */
		ECNETLOST,		/* �޷����ӷ���� */
		ECALREADY,		/* ǰһ�β�����δ��ɣ���������ٲ��� */
		ECSYS,			/* ϵͳ���� */
		ECBADID,		/* �ص����������Ƿ� */
		ECBADVAL,		/* ����ֵ�Ƿ� */
		ECUNEXPECTCMD,	/* �ص����������Ϸ� */
		ECPERM,			/* �û���Ȩ�� */
		ECFAIL,			/* ʧ�� */
		ECTMOUT			/* ��ʱ */
	} ErrorCode;
	
	typedef enum {
		SUCCESS = 0,
		FAILED,
		TIMEOUT
	} CMDRET;
} st_rawctrl;

/* ���ƻص��ӿ� */
class ICtrlReturn
{
public:
	/* !ע��÷���Ӧ�ÿ��ٷ��أ�������� */
	virtual void OnRecv( st_rawctrl::CMDType t, st_rawctrl::CMDRET ret ) = 0;
};

/* �����·��ӿ� */
class IRawCtrl : public IICSUnknown
{
public:
    static const char* GetIntfName() { return IID_IRAWCTRL; } 

	/* ���ò���Ա������ */
	virtual void SetUser(const char* name, const char* passwd) = 0;

	/* ��ȡ����Ա */
	virtual const char* GetUser() = 0;

	/*
	ң���·�ѡ����
		ctrlID -- ң��ID
		value -- 0 - ��/�У�1 - ��/Ͷ��
	���� 0 - �ɹ���-1 - ʧ�ܣ�
	ע������ص�Ϊֱ�أ��򷵻�ʧ�ܡ�
	 */
	virtual int Telectrl_select(int ctrlID, int value) = 0;

	/* 
	ң���·�ִ����
		ctrlID -- ң��ID
		value -- 0 - ��/�У�1 - ��/Ͷ��
		bMsc -- false-��ע����Ϣ���ģ�true -- ע����Ϣ����
	���� 0 - �ɹ���-1 - ʧ�ܣ�
	 */
	virtual int Telectrl_exec(int ctrlID, int value,bool bMsc = false,bool bResult = true) = 0;

	/*
	ң���·�ѡ����
		ctrlID -- ң��ID
		value -- 0 - ͣ��1 - ����2 - ����
	���� 0 - �ɹ���-1 - ʧ�ܣ�
	ע������ص�Ϊֱ�أ��򷵻�ʧ�ܡ�
	 */
	virtual int Teleadjust_select(int ctrlID, int value) = 0;



	virtual int Teleadjust_exec(int ctrlID, double value,bool bMsc = false,bool bResult = true) = 0;

	/* 
	�·�������
		ctrlID -- �ص�ID
	���� 0 - �ɹ���-1 - ʧ�ܣ�
	 */
	virtual int Cancel(int ctrlID) = 0;

	/* �·�ģ������ѡ���� (��δʵ��) */
	virtual int DBL_select(int ctrlID, double value) = 0;

	/* �·�ģ������ִ���� (��δʵ��) */
	virtual int DBL_exec(int ctrlID, double value) = 0;

	/* ��ȡ�����ţ��ο�st_rawctrl::ErrorCode */
	virtual int ErrNo() = 0;

	/* ��ȡ�����ַ����� */
	virtual const char* ErrStr() = 0;

	/*
	 ע��ص��ӿ�
	 ����:
		�ϴ�ע��Ļص��ӿ�
	 */
	virtual ICtrlReturn* RegisterCallBack(ICtrlReturn* ptr) = 0;

	/* 
	ң���˹�����
		sttsID -- ң����ID
	���� 0 - �ɹ���-1 - ʧ�ܣ�
	 */
	virtual int ManualSetStatus(int sttsID, int value) = 0;

	/* 
	ң���˹�����
		anlgID -- ң����ID
	���� 0 - �ɹ���-1 - ʧ�ܣ�
	 */
	virtual int ManualSetAnalog(int anlgID, double value) = 0;

	/* 
	����ң���˹�������־
		sttsID -- ң����ID
	���� 0 - �ɹ���-1 - ʧ�ܣ�
	 */
	virtual int CancelStatusManualSet(int sttsID) = 0;

	/* 
	����ң���˹�������־
		anlgID -- ң����ID
	���� 0 - �ɹ���-1 - ʧ�ܣ�
	 */
	virtual int CancelAnalogManualSet(int anlgID) = 0;

};

#endif /* IRAWCTRL_H */
