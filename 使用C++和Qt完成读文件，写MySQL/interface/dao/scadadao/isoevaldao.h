//isoevaldao.h

#ifndef _ISOEVALTYPEDAO_PENGSHIKANG_20090217_H_
#define _ISOEVALTYPEDAO_PENGSHIKANG_20090217_H_

#include "../ibasicdao.h"                        // for IBasicDao

#define SOEVALDAO_CLASSID    "csoevaldao"
#define SOEVALDAO_INTFID     "isoevaldao"

class ISoeValDao : virtual public IBasicDao
{
public:	
	//根据量测类型和值得到SOE值类型量位置
	virtual int GetSoeValTypPosByValue(int nMeasType, int nValue) = 0;
	//根据SOE值类型量位置得到是否带参数报告标志
	virtual int GetReportFlag(int pos) = 0;
	
	//根据SOE量值类型位置读取报警ID
	virtual int GetAlarmID(int pos) = 0;
};

#endif
