//ivqcstradao.h

#ifndef _IVQCSTRATEGYDAO_PENGSHIKANG_20120507_H_
#define _IVQCSTRATEGYDAO_PENGSHIKANG_20120507_H_

#include "../../ibasicdao.h"                     // for IBasicDao

#define VQCSTRADAO_CLASSID    "cvqcstradao"
#define VQCSTRADAO_INTFID     "ivqcstradao"

class IVqcStraDao : virtual public IBasicDao
{
public:
	//根据VQC调节策略类型ID和调节区号得到调节策略记录位置
	virtual int GetPositionByStraTypeAndZoneNo(int straType, int zoneNo) = 0;
	//根据VQC调节策略记录位置得到第1策略
	virtual int GetFirstStrategy(int pos) = 0;
	//根据VQC调节策略记录位置得到第2策略
	virtual int GetSecondStrategy(int pos) = 0;
	//根据VQC调节策略记录位置得到第3策略
	virtual int GetThirdStrategy(int pos) = 0;
	//根据VQC调节策略记录位置得到第4策略
	virtual int GetFourthStrategy(int pos) = 0;
	//根据VQC调节策略记录位置得到第n个策略
	virtual int GetStrategyN(int pos, unsigned int n) = 0;
};

#endif
