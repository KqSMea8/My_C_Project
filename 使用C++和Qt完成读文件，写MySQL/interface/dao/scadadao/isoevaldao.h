//isoevaldao.h

#ifndef _ISOEVALTYPEDAO_PENGSHIKANG_20090217_H_
#define _ISOEVALTYPEDAO_PENGSHIKANG_20090217_H_

#include "../ibasicdao.h"                        // for IBasicDao

#define SOEVALDAO_CLASSID    "csoevaldao"
#define SOEVALDAO_INTFID     "isoevaldao"

class ISoeValDao : virtual public IBasicDao
{
public:	
	//�����������ͺ�ֵ�õ�SOEֵ������λ��
	virtual int GetSoeValTypPosByValue(int nMeasType, int nValue) = 0;
	//����SOEֵ������λ�õõ��Ƿ�����������־
	virtual int GetReportFlag(int pos) = 0;
	
	//����SOE��ֵ����λ�ö�ȡ����ID
	virtual int GetAlarmID(int pos) = 0;
};

#endif
