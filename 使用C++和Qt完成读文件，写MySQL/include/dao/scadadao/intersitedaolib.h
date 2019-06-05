// intersitelib.h: implement for the CIntersiteDao class.
#ifndef _INTERSITEDAOLIB_20100404_PENGSHIKANG_H_
#define _INTERSITEDAOLIB_20100404_PENGSHIKANG_H_

#include "../../commgr/intfobjptrb.h"            // for CIntfObjPtrB
#include "../../../interface/dao/scadadao/iintersitedao.h" // for IIntersiteDao

//DLL����Ľӿڶ�������
class CIntersiteDao : public CIntfObjPtrB<IIntersiteDao>
{
public:
	CIntersiteDao() : CIntfObjPtrB<IIntersiteDao>
		(SCADADAO_MODULE, INTERSITEDAO_CLASSID, INTERSITEDAO_INTFID) { }
};

#endif 