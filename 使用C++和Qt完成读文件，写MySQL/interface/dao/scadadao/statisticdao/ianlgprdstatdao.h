//ianlgprdstatdao.h

#ifndef _IANALOGPROIDSTATISTICSDAO_PENGSHIKANG_20130310_H_
#define _IANALOGPROIDSTATISTICSDAO_PENGSHIKANG_20130310_H_

#include "iperiodstatdao.h"                      // for IPeriodStatDao 

#define ANLGPRDSTATDAO_CLASSID    "canlgprdstatdao"
#define ANLGPRDSTATDAO_INTFID     "ianlgprdstatdao"

class IAnlgPrdStatDao : virtual public IPeriodStatDao
{
public:
	//����ģ����ʱ��ͳ�ƴ�����
	virtual bool SetAnlgPrdStatValue(int objPos, bool bQualified, int nProFlag, 
		int curQualt, double curTime, double dSmpTime, double dAlmTime, int hasAlm) = 0;
};

#endif
