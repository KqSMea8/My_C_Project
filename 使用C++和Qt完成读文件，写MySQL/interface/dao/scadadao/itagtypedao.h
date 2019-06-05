//itagtypedao.h

#ifndef _ITAGTYPEDAO_PENGSHIKANG_20100821_H_
#define _ITAGTYPEDAO_PENGSHIKANG_20100821_H_

#include "../ibasicdao.h"                        // for IBasicDao

#define TAGTYPEDAO_CLASSID    "ctagtypedao"
#define TAGTYPEDAO_INTFID     "itagtypedao"

class ITagTypeDao : virtual public IBasicDao
{
public:
	//根据挂牌类型位置得到描述
	virtual const char* GetDescription(int pos) = 0;
	//根据挂牌类型位置得到是否允许处理标志
	virtual bool CanProcessFlag(int pos) = 0;
};

#endif
