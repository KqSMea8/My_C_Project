// ctrlworddaolib.h: implement for the CCtrlWordDefDao class.
#ifndef _CTRLWORDDAOLIB_20131224_PENGSHIKANG_H_
#define _CTRLWORDDAOLIB_20131224_PENGSHIKANG_H_

#include "../../commgr/intfobjptrb.h"       // for CIntfObjPtrB
#include "../../../interface/dao/scadadao/ictrlworddefdao.h" // for ICtrlWordDefDao

//DLL����Ľӿڶ�������
class CCtrlWordDefDao : public CIntfObjPtrB<ICtrlWordDefDao>
{
public:
	CCtrlWordDefDao() : CIntfObjPtrB<ICtrlWordDefDao>
		(SCADADAO_MODULE, CTRLWORDDEFDAO_CLASSID, CTRLWORDDEFDAO_INTFID) { }
};

#endif 
