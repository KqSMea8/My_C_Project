#ifndef UIPMESSAGEDEF_H_
#define UIPMESSAGEDEF_H_

typedef unsigned char BYTE;

#define  _MSG_MSG_MAX_LEN	    256
#define  _MSG_STATION_MAX_LEN   26
#define _RCD_FILE_NAME_LEN	 	128
#define _IED_NAME_LEN           32

//内部信息分类 用于ucintype字段
#define _ACTIVE_TYPE_RCDMAD_TYPE	1	//传输rcdmade 录波完成通知
#define _ACTIVE_TYPE_GETMSG_TYPE	2	//召唤消息类型
#define _ACTIVE_TYPE_SHOWMSG_TYPE	3	//显示报文消息，响应_ACTIVE_TYPE_GETMSG_TYPE
#define _ACTIVE_TYPE_YXMSG_TYPE	    4	//遥信消息类型
//信息传输结构 对应消息类型_MSG_SEND_INITIATIVE_MSGTYPE
typedef struct  
{
	char            	iedname[_IED_NAME_LEN]; //改为装置名称
	BYTE			ucsector;	// 为CPU，或LD序号 没有时为0
	BYTE			ucLms; //文件属性
	BYTE			ucHms;
	BYTE			ucMinute;
	BYTE			ucHour;
	BYTE			ucDay;
	BYTE			ucMonth;
	BYTE			ucYear;
	char		    fName[_RCD_FILE_NAME_LEN]; // 文件名称，含路径，不含扩展名
	//以下为从现场收到时的时间
	unsigned int	    uisec;			/* 从现场收到时的时间 秒 从1970年到今*/
	unsigned int	    uimsec;			/* 从现场收到时的时间 毫秒*/
}RECREPORT;

typedef struct  
{
	unsigned int ucChl;		//通道号
	BYTE ucShow;	//1:召唤显示报文 0：停止显示报文
	BYTE ucSuccess;	//1:成功 0：失败
}GETMSG;

//报文信息传输结构 对应消息类型 _MSG_SHOW_MSGTYPE
typedef struct	
{
	unsigned int ucChl;		//通道号
	BYTE ucup;		//TRUE: 上行报文 FALSE:下行报文
	BYTE lastFlg;	//TRUE:最后一帧 FALSE:非最后一帧报文
	BYTE len;
	BYTE ucbuf[_MSG_MSG_MAX_LEN];	//报文内容
	char station[_MSG_STATION_MAX_LEN]; //主站信息描述： 192.168.1.3  COM3
}SHOWMSG;

typedef struct
{
	unsigned int 	usIndex;			/* index in RTDB */
	BYTE	ucChangeTo;			/* new value 不论单双点，遥信量 1--分；2--合；0，3--不确定状态*/
	BYTE	ucLms;
	BYTE	ucHms;
	BYTE	ucMinute;
	BYTE	ucHour;
	BYTE	ucDay;
	BYTE	ucMonth;
	BYTE	ucYear;
	BYTE    ucReason;			// 传送原因 0：正常 1：检修压板或装置断 2：取代
}YXMSG;

typedef union
{
	RECREPORT   recReport;      // 录波简报
	GETMSG	    getmsg;
	SHOWMSG	    showmsg;
	YXMSG       yxmsg;
}MSGDATA;


/* 一条完整消息在实时数据库中的结构 */
typedef struct
{
	unsigned int		uiType;			/* 信息分类message type, example_ACTIVE_TYPE_RCDMAD_TYPE */
	MSGDATA		msgData;			
}DBMSG;

#endif