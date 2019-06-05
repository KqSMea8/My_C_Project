//imeasunitdao.h

#ifndef _IMEASUNITDAO_PENGSHIKANG_20090218_H_
#define _IMEASUNITDAO_PENGSHIKANG_20090218_H_

#include "../ibasicdao.h"                        // for IBasicDao

#define MEASUNITDAO_CLASSID    "cmeasunitdao"
#define MEASUNITDAO_INTFID     "imeasunitdao"

class IUnitDao : virtual public IBasicDao
{
public:
	//����ң�ⵥλ��ID�õ�����
	virtual const char* GetNameById(int id) = 0;
};

#endif
