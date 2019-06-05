#ifndef PDRTRIGGERNOTICE_H_INCLUDED
#define PDRTRIGGERNOTICE_H_INCLUDED 1
#include <QDataStream>
#include <QString>

#define TOPIC_PDRTRIGGERNOTICE "pdrTriggerNotice-from-trigger"

//追忆触发通知:pSend("pdrTriggerNotice-from-trigger", st_pdrTriggerMessage)


struct PDRTriggerMsg
{	
	QString  strFaultdesc;			//事故描述
	QString  strEquipObject;		//发生事故设备列表（设备类型编码和id）即：类型编码_id；多个设备之间按“,”间隔，即：类型编码1_id1，类型编码2_id2
	QString  strRelatedfeederId;   //事故区馈线设备列表，按“,”间隔
	double  dFaulttime;			//事故发生时间
	int  nFaultdescID;			//遥测/遥信ID（若触发为非测点类型，本字段值默认填“0”）
};


inline QDataStream &operator<<(QDataStream &out, const PDRTriggerMsg& inValue)
{	
	out << inValue.strFaultdesc;
	out << inValue.strEquipObject;
	out << inValue.strRelatedfeederId;
	out << inValue.dFaulttime;
	out << inValue.nFaultdescID;
	
	return out; 
}

inline QDataStream &operator >> (QDataStream &in, PDRTriggerMsg& outValue)
{	
	in >> outValue.strFaultdesc;
	in >> outValue.strEquipObject;
	in >> outValue.strRelatedfeederId;
	in >> outValue.dFaulttime;
	in >> outValue.nFaultdescID;
		
	return in;
}

enum PDRTrigType
{
	pdrttYC = 1,
	pdrttYX = 2,
	pdrttACC = 3,
	pdrttMANUAL = 4
};

struct st_pdrTriggerMessage {
	int nType;			//1:遥测越限;  2:遥信变位;  3:事故触发;  4:人工触发
	QList<PDRTriggerMsg>   stPdrTriglist;         //触发信号列表           参数个数从qlist的count方法获得
};

inline QDataStream &operator<<(QDataStream &out, const st_pdrTriggerMessage& inValue)
{
	out << inValue.nType;
	out << inValue.stPdrTriglist;
	return out; 
}

inline QDataStream &operator >> (QDataStream &in, st_pdrTriggerMessage& outValue)
{
	in >> outValue.nType;
	in >> outValue.stPdrTriglist;
	return in;
}

#endif