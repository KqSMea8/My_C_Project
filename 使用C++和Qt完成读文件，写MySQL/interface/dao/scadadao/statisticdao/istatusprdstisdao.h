//istatusprdstisdao.h

#ifndef _ISTATUSPROIDSTATISTICSDAO_PENGSHIKANG_20130310_H_
#define _ISTATUSPROIDSTATISTICSDAO_PENGSHIKANG_20130310_H_

#include "iperiodstatdao.h"                    // for IPeriodStatDao

#define STTSPRDSTISDAO_CLASSID    "csttsprdstisdao"
#define STTSPRDSTISDAO_INTFID     "isttsprdstisdao"

class ISttsPrdStisDao : virtual public IPeriodStatDao
{
public:
	//����״̬��ʱ��ͳ�ƴ����� [����״̬������ͳ�ƴ����߳�]
	virtual bool SetSttsPrdStisValue(int nObjPos, bool isConnect, double curTime, double dSmpTime) = 0;
	
	//ʱ�ε�ʱ��״̬����ʱ��ͳ�� [����ʱ�ε�ʱͳ���߳�]
	virtual void PeriodStatistics() = 0;
};

#endif
