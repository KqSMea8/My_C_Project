//isoeparadao.h

#ifndef _ISOEPARAMETERDAO_PENGSHIKANG_20090217_H_
#define _ISOEPARAMETERDAO_PENGSHIKANG_20090217_H_

#include "../ibasicdao.h"                        // for IBasicDao

#define SOEPARADAO_CLASSID    "csoeparadao"
#define SOEPARADAO_INTFID     "isoeparadao"

class ISoeParaDao : virtual public IBasicDao
{
public:
	//根据参数的值类型和序号得到SOE参数量位置
	virtual int GetSoeParaPosBySeqNo(int nValType, int nSeqNo) = 0;
	//根据SOE参数量位置得到测控量类型ID
	virtual int GetMeasType(int pos) = 0;
	//根据SOE参数量位置得到参数单位ID
	virtual int GetUnitId(int pos) = 0;
};

#endif
