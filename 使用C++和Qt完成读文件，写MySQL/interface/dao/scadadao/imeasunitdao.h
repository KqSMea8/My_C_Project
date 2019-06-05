//imeasunitdao.h

#ifndef _IMEASUNITDAO_PENGSHIKANG_20090218_H_
#define _IMEASUNITDAO_PENGSHIKANG_20090218_H_

#include "../ibasicdao.h"                        // for IBasicDao

#define MEASUNITDAO_CLASSID    "cmeasunitdao"
#define MEASUNITDAO_INTFID     "imeasunitdao"

class IUnitDao : virtual public IBasicDao
{
public:
	//根据遥测单位量ID得到名称
	virtual const char* GetNameById(int id) = 0;
};

#endif
