// soeparadaolib.h: implement for the CSoeParaDao class.
#ifndef _SOEPARADAOLIB_20130311_PENGSHIKANG_H_
#define _SOEPARADAOLIB_20130311_PENGSHIKANG_H_

#include "../../commgr/intfobjptrb.h"       // for CIntfObjPtrB
#include "../../../interface/dao/scadadao/isoeparadao.h"    // for ISoeParaDao

//DLL����Ľӿڶ�������
class CSoeParaDao : public CIntfObjPtrB<ISoeParaDao>
{
public:
	CSoeParaDao() : CIntfObjPtrB<ISoeParaDao>
		(SCADADAO_MODULE, SOEPARADAO_CLASSID, SOEPARADAO_INTFID) { }
};

#endif 