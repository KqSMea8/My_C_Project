/*******************************************************
 * vqcforwardtypes.h -- VQC��CVTת���������Ͷ���
 * 
 * date: 2008.12.26 hongkeqin@xjgc.com
 * revised:
		���Ӷ�ֵ����������: fwdSetting 2009.05.12
		�����������壺tCMDTYPE::CALLDATA 2009.06.09
		CVT���ݶ��� 2009.10.15
 *******************************************************/

#ifndef _VQCFORWARDTYPES_H_
#define _VQCFORWARDTYPES_H_

struct VQC_T
{
	/* ָ������ */
	typedef enum {
		SELCMD = 0,		// ѡ����
		EXECMD = 1,		// ִ����
		CANCLCMD,		// ������
		FINCMD,			// ������[�ڷ���ִ�������󣬷���]
		CALLDATA		// ������
	} tCMDTYPE;
	
	/* ����ֵ */
	typedef enum {
		SUCCESS = 0,	// �ɹ�
		FAILED			// ʧ��

	} tRETVAL;
	
};

/* ҵ������ö�� */
typedef enum {
	GRP_NONE = 0,
	GRP_VQC = 1,
	GRP_CVT = 2,
	GRP_SM = 3

} TASKGRP;

/*
 * ���������ͼ���ʽ
 */
typedef enum {
	fwdNone = 0, 
	/* VQC ��� */
	fwdIdVarTime,	//ң�š�ң��ת����ʽ�� uchar(fwdIdVarTime) | int (id) | QVariant (value) | double (timestamp)
						///������vqc->Զ��;

	fwdSetting,		//vqcң�ء��趨ֵ��ʽ�� uchar(fwdSetting) | int (id) | uchar (VQC_T::tCMDTYPE) \
						///	| QVariant (value) | uchar (VQC_T::tRETVAL)������vqc<-->Զ��;
	/* ���� ��� */
	fwdCallData,	//��ʽ�� uchar(fwdCallData) | int (id) | QVariant (value) | uchar (TASKGRP) ���򣺼��->Զ��;
						///��ʽ: enumType(fwdCallData) ����Զ��->���;
	/* CVT ��� */
	CVT_STATUS,		//ң�Ÿ�ʽ��uchar(CVT_STATUS) | int (id) | QVariant (value) | double (timestamp)
	CVT_ANALOG,		//ң���ʽ��uchar(CVT_ANALOG) | int (id) | QVariant (value) | double (timestamp)
	CVT_CMD	,		//ң�ء���ֵ��ʽ��uchar(CVT_CMD) |  int (id) | unsigned char (VQC_T::tCMDTYPE) \
						///	| QVariant (value) | unsigned char (VQC_T::tRETVAL)������cvt<-->Զ��;

	/* �ӵ�ѡ��(SM) ��� */
	SM_STATUS,		//ң�Ÿ�ʽ��uchar(SM_STATUS) | int (id) | QVariant (value) | double (timestamp)
	SM_ANALOG,		//ң���ʽ��uchar(SM_ANALOG) | int (id) | QVariant (value) | double (timestamp)
	SM_CMD			//ң�ء���ֵ��ʽ��uchar(SM_CMD) |  int (id) | unsigned char (VQC_T::tCMDTYPE) \
	///	| QVariant (value) | unsigned char (VQC_T::tRETVAL)������cvt<-->Զ��;

} FWDTYPES;

/*
 * ��Ϣ������غ궨��
 */
#define FWDMsgType				280
#define Sender_PSPARTNAME 		"VQCSender"
#define Recver_PSPARTNAME 		"VQCRecver"
#define Sender_PARTTYPE 		0x9F		//unsigned short
#define Recver_PARTTYPE 		0x9E			


#define FWDTYPES_VQCROLE 100	//VQC������ɫ�������
typedef enum {
	TEST = 0,
	KEEP,
	ACK
} tVQCROLEMSG;
#endif
