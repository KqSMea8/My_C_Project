//ictrlworddefdao.h

#ifndef _ICTRLWORDDEFINEDAO_PENGSHIKANG_20131224_H_
#define _ICTRLWORDDEFINEDAO_PENGSHIKANG_20131224_H_

#include "../ibasicdao.h"                        // for IBasicDao

#define CTRLWORDDEFDAO_CLASSID    "cctrlworddefdao"
#define CTRLWORDDEFDAO_INTFID     "ictrlworddefdao"

//控制字类型定义
class ICtrlWordDefDao : virtual public IBasicDao
{
public:
	//根据控制字类型记录位置得到指定位的位含义
	virtual bool GetBitMeaning(int pos, int nBit, char* strMeaning) = 0;
};

#endif
