#ifndef MSCRESOURCES_H
#define MSCRESOURCES_H
/* 
 *	����ǰ��Ŀ���и���Ӧ��ģ����ʹ�õ���Ϣ������Դ��
 *	�������µ�ģ��ʹ����Ϣ����ʱ�������׷�ӣ������ͻ��
 */

/* ����Ӧ��ģ����ʹ�õġ���Ϣ������Ϣ���͡� */
typedef enum {
	// ��ң����ת��(31)��smgserver --> intersite (������Ϣ�������)
	FD_MSC_MSGT			= 101,		/* ��ң��ң��.ң��.ң����ң�أ�����ת�� */ 
	// ���ȶ�ң��\ң��(2)��intersite --> smgserver (������Ϣ�������)
	// ���������״̬������\����\��ֵ\����\���١������������͡����Ȳ�����ͣѹ�� (1��2��3��4��5��6��30)��smgserver <--> ctrlclient
	CTRL_MSC_MSGT		= 110,		/* ң��ģ�飺��������״̬������ִ�н�� */ 
	AUTO_CTRL_MSGT		= 111,		/*AGC��AVC�Զ�����*/
	// ������Ϣͨ��
	ALRM_MSGT			= 120,		/* ������Ϣ */
	ALRM_ACK_MSGT		= 121,		/* ȷ��һ������ */
	ALRM_CLEAR_MSGT		= 122,		/* ���һ������ */
	ALRM_ACKALL_MSGT	= 123,		/* ȷ��ȫ������ */
	ALRM_CLEARALL_MSGT	= 124,		/* ���ȫ������ */
	// [˳�ؽ���|����ѹ��仯]������ʷ��洢��20����smgserver --> hisstragy (������Ϣ�������)
	EVENT_MSGT			= 126,		/* �¼�(˳��ʹ��) */  
	// ���Ȳ���ѹ��Ͷ�ֵ�·���̨����30����intersite --> smgserver (��������Ϣ�������)
	RECV_CURVE_MSGT     = 127,      /* �������ݽ��� */    
	// [���Ȳ���ѹ���ɱ��ر����Ϣ|��Ӧ���Ȳ��ԵĽ��]���͵��ȶˣ�30����smgserver --> intersite (������Ϣ�������)
	// ����Ԥ��������Ԥ������͵��ȶˣ�30����curvesend --> intersite
	SEND_CURVE_MSGT     = 128,      /* �������ݷ��� */    
	// �鲥Ⱥ��������Ϣ���͸�Ⱥ�ط���32����smgserver --> grpctrlserver
	GRPCTRL_MSC_MSGT    = 129,      /* �鲥Ⱥ������� */  
	PDR_MANUALFT_TRIGGER = 150,		/*�˹������¹�*/
} MSC_MSGT;


/* ����Ӧ��ģ������Ϣ���Ľ��е�¼ʱ�ĵڶ���������PartType����¼�����ͣ�ģ�����ͣ� */
#define MSC_PTYPE_BASE	10								/* Ӧ��ģ�����ͻ�׼ֵ */
typedef enum {
	MSC_PTYPE_CTRLCLIENT	=	MSC_PTYPE_BASE + 57866, /* ctrlclient ģ�� */
	MSC_PTYPE_CTRLSRV		=	MSC_PTYPE_BASE + 57867,	/* ctrlserver ģ�� */ // ��ֹ
	MSC_PTYPE_DATAPROC		=	MSC_PTYPE_BASE + 57867,	/* ���ݴ������scadasrv��smgserver��ģ�� */
	MSC_PTYPE_ALRMCLIENT	=	MSC_PTYPE_BASE + 21,	/* alarmclientģ�� */
	MSC_PTYPE_ALRMCENTER	=	MSC_PTYPE_BASE + 41,	/* alarmcenterģ�� */
	MSC_PTYPE_ANALOG		=	MSC_PTYPE_BASE + 42,	/* ң�����ģ�� */    // ��ֹ
	MSC_PTYPE_STATUS		=	MSC_PTYPE_BASE + 43,	/* ң�ŷ���ģ�� */    // ��ֹ
	MSC_PTYPE_ACCUM			=	MSC_PTYPE_BASE + 44,	/* ң������ģ�� */    // ��ֹ
	MSC_PTYPE_INTERSITE		=	MSC_PTYPE_BASE + 45,	/* InterSiteģ�� */
	MSC_PTYPE_TESTMODULE	=	MSC_PTYPE_BASE + 46,	/* ����ģ�� */
	MSC_PTYPE_HISSTRAGY		=	MSC_PTYPE_BASE + 47,	/* hisstragyģ�� */
	MSC_PTYPE_CURVESEND		=	MSC_PTYPE_BASE + 48,	/* �������ݷ��ͣ�curvesend��ģ�� */
	MSC_PTYPE_GRPCTRLSRV	=	MSC_PTYPE_BASE + 49,	/* �鲥Ⱥ�ش������grpctrlserver��ģ�� */
	MSC_PTYPE_STRATEGYSHOW	=	MSC_PTYPE_BASE + 50,	/* �ͻ��˽��շ������(agc/avc)ģ�� */
	MSC_PTYPE_PDRMANUAL		=	MSC_PTYPE_BASE + 61,
	
} MSC_PTYPE; /* ע��������ʷԭ�����ģ��ʹ�õ�ֵ�ϴ���ģ�鲻����ˣ�ֻ��ȷ��ֵ����ͻ����(MSC_PTYPE_BASE, maxvalue(ushort))֮�伴�ɡ�*/



#endif	/* MSCRESOURCES_H */
