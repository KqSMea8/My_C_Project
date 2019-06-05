// mglinedaolib.h: implement for the CMGLineDao class.
#ifndef _MGLINEDAOLIB_20130310_PENGSHIKANG_H_
#define _MGLINEDAOLIB_20130310_PENGSHIKANG_H_

#include "../../../commgr/intfobjptrb.h"         // for CIntfObjPtrB
#include "../../../../interface/dao/smgdao/mgddao/imglinedao.h"// for IMGLineDao

//DLL����Ľӿڶ�������
class CMGLineDao : public CIntfObjPtrB<IMGLineDao>
{
public:
	CMGLineDao() : CIntfObjPtrB<IMGLineDao>
		(SMGDAO_MODULE, MGLINEDAO_CLASSID, MGLINEDAO_INTFID) { }
};

#endif 
