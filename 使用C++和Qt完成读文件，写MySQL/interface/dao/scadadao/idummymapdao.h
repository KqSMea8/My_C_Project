//idummymapdao.h

#ifndef _IDUMMYCALMAPDAO_PENGSHIKANG_20130310_H_
#define _IDUMMYCALMAPDAO_PENGSHIKANG_20130310_H_

#include "../ibasicdao.h"                        // for IBasicDao

#define DUMMYCALDAO_CLASSID    "cdummycaldao"
#define DUMMYCALDAO_INTFID     "idummycaldao"

class IDummyCalDao : virtual public IBasicDao
{
public:
	//根据虚点模拟量位置读取公式计算ID
	virtual int GetExprCalID(int pos) = 0;
};

#endif
