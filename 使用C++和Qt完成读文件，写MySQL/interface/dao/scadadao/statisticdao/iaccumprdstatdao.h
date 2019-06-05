//iaccumprdstatdao.h

#ifndef _IACCUMUPROIDSTATISTICSDAO_PENGSHIKANG_20130310_H_
#define _IACCUMUPROIDSTATISTICSDAO_PENGSHIKANG_20130310_H_

#include "iperiodstatdao.h"                    // for IPeriodStatDao

#define ACCUMPRDSTATDAO_CLASSID    "caccumprdstatdao"
#define ACCUMPRDSTATDAO_INTFID     "iaccumprdstatdao"

class IAccumPrdStatDao : virtual public IPeriodStatDao
{
public:
	//�����ۼ���ʱ��ͳ�ƴ�����
	virtual bool SetAccumPrdStatValue(int objPos, double incValue, double curTime) = 0;
};

#endif
