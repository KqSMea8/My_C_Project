//ianlgstatdao.h

#ifndef _IANALOGSTATISTICSDAO_PENGSHIKANG_20130310_H_
#define _IANALOGSTATISTICSDAO_PENGSHIKANG_20130310_H_

#include "istatisticdao.h"                     // for IStatisticDao 

#define ANLGSTATDAO_CLASSID    "canlgstatdao"
#define ANLGSTATDAO_INTFID     "ianlgstatdao"

class IAnlgStatDao : virtual public IStatisticDao 
{
public:	
	//设置模拟量统计处理结果
	virtual bool SetAnalogStatValue(int nObjPos, bool bQualified, int nProFlag,
		int curQualt, double calValue, double curTime, double dSmpTime, double dAlmTime, int hasAlm) = 0;	
};

#endif
