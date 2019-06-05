// ctrlexpdaolib.h: implement for the CCtrlExpDao class.
#ifndef _CTRLEXPDAOLIB_20130310_PENGSHIKANG_H_
#define _CTRLEXPDAOLIB_20130310_PENGSHIKANG_H_

#include "../../commgr/intfobjptrb.h"       // for CIntfObjPtrB
#include "../../../interface/dao/scadadao/ictrlexpdao.h"    // for ICtrlExpDao

//DLL����Ľӿڶ�������
class CCtrlExpDao : public CIntfObjPtrB<ICtrlExpDao>
{
public:
	CCtrlExpDao() : CIntfObjPtrB<ICtrlExpDao>
		(SCADADAO_MODULE, CTRLEXPDAO_CLASSID, CTRLEXPDAO_INTFID) { }
};

#endif 
