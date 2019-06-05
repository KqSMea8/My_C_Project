#ifndef UIPMESSAGEDEF_H_
#define UIPMESSAGEDEF_H_

typedef unsigned char BYTE;

#define  _MSG_MSG_MAX_LEN	    256
#define  _MSG_STATION_MAX_LEN   26
#define _RCD_FILE_NAME_LEN	 	128
#define _IED_NAME_LEN           32

//�ڲ���Ϣ���� ����ucintype�ֶ�
#define _ACTIVE_TYPE_RCDMAD_TYPE	1	//����rcdmade ¼�����֪ͨ
#define _ACTIVE_TYPE_GETMSG_TYPE	2	//�ٻ���Ϣ����
#define _ACTIVE_TYPE_SHOWMSG_TYPE	3	//��ʾ������Ϣ����Ӧ_ACTIVE_TYPE_GETMSG_TYPE
#define _ACTIVE_TYPE_YXMSG_TYPE	    4	//ң����Ϣ����
//��Ϣ����ṹ ��Ӧ��Ϣ����_MSG_SEND_INITIATIVE_MSGTYPE
typedef struct  
{
	char            	iedname[_IED_NAME_LEN]; //��Ϊװ������
	BYTE			ucsector;	// ΪCPU����LD��� û��ʱΪ0
	BYTE			ucLms; //�ļ�����
	BYTE			ucHms;
	BYTE			ucMinute;
	BYTE			ucHour;
	BYTE			ucDay;
	BYTE			ucMonth;
	BYTE			ucYear;
	char		    fName[_RCD_FILE_NAME_LEN]; // �ļ����ƣ���·����������չ��
	//����Ϊ���ֳ��յ�ʱ��ʱ��
	unsigned int	    uisec;			/* ���ֳ��յ�ʱ��ʱ�� �� ��1970�굽��*/
	unsigned int	    uimsec;			/* ���ֳ��յ�ʱ��ʱ�� ����*/
}RECREPORT;

typedef struct  
{
	unsigned int ucChl;		//ͨ����
	BYTE ucShow;	//1:�ٻ���ʾ���� 0��ֹͣ��ʾ����
	BYTE ucSuccess;	//1:�ɹ� 0��ʧ��
}GETMSG;

//������Ϣ����ṹ ��Ӧ��Ϣ���� _MSG_SHOW_MSGTYPE
typedef struct	
{
	unsigned int ucChl;		//ͨ����
	BYTE ucup;		//TRUE: ���б��� FALSE:���б���
	BYTE lastFlg;	//TRUE:���һ֡ FALSE:�����һ֡����
	BYTE len;
	BYTE ucbuf[_MSG_MSG_MAX_LEN];	//��������
	char station[_MSG_STATION_MAX_LEN]; //��վ��Ϣ������ 192.168.1.3  COM3
}SHOWMSG;

typedef struct
{
	unsigned int 	usIndex;			/* index in RTDB */
	BYTE	ucChangeTo;			/* new value ���۵�˫�㣬ң���� 1--�֣�2--�ϣ�0��3--��ȷ��״̬*/
	BYTE	ucLms;
	BYTE	ucHms;
	BYTE	ucMinute;
	BYTE	ucHour;
	BYTE	ucDay;
	BYTE	ucMonth;
	BYTE	ucYear;
	BYTE    ucReason;			// ����ԭ�� 0������ 1������ѹ���װ�ö� 2��ȡ��
}YXMSG;

typedef union
{
	RECREPORT   recReport;      // ¼����
	GETMSG	    getmsg;
	SHOWMSG	    showmsg;
	YXMSG       yxmsg;
}MSGDATA;


/* һ��������Ϣ��ʵʱ���ݿ��еĽṹ */
typedef struct
{
	unsigned int		uiType;			/* ��Ϣ����message type, example_ACTIVE_TYPE_RCDMAD_TYPE */
	MSGDATA		msgData;			
}DBMSG;

#endif