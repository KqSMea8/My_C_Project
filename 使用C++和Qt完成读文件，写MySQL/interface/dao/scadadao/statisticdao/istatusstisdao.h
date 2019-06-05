//istatusstisdao.h

#ifndef _ISTATUSSTATISTICSDAO_PENGSHIKANG_20130310_H_
#define _ISTATUSSTATISTICSDAO_PENGSHIKANG_20130310_H_

#include "istatisticdao.h"                     // for IStatisticDao

#define STATUSSTISDAO_CLASSID    "cstatusstisdao"
#define STATUSSTISDAO_INTFID     "istatusstisdao"

class IStatusStisDao : virtual public IStatisticDao
{
public:
	//设置状态量统计处理结果
	virtual bool SetStatusStisValue(int nObjPos, bool isConnect, double curTime, double dSmpTime) = 0;
};

#endif
