#ifndef PDRTRIGGERNOTICE_H_INCLUDED
#define PDRTRIGGERNOTICE_H_INCLUDED 1
#include <QDataStream>
#include <QString>

#define TOPIC_PDRTRIGGERNOTICE "pdrTriggerNotice-from-trigger"

//׷�䴥��֪ͨ:pSend("pdrTriggerNotice-from-trigger", st_pdrTriggerMessage)


struct PDRTriggerMsg
{	
	QString  strFaultdesc;			//�¹�����
	QString  strEquipObject;		//�����¹��豸�б��豸���ͱ����id���������ͱ���_id������豸֮�䰴��,��������������ͱ���1_id1�����ͱ���2_id2
	QString  strRelatedfeederId;   //�¹��������豸�б�����,�����
	double  dFaulttime;			//�¹ʷ���ʱ��
	int  nFaultdescID;			//ң��/ң��ID��������Ϊ�ǲ�����ͣ����ֶ�ֵĬ���0����
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
	int nType;			//1:ң��Խ��;  2:ң�ű�λ;  3:�¹ʴ���;  4:�˹�����
	QList<PDRTriggerMsg>   stPdrTriglist;         //�����ź��б�           ����������qlist��count�������
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