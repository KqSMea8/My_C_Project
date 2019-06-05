// pccdaolib.h: implement for the CPccDao class.
#ifndef _PCCDAOLIB_20130310_PENGSHIKANG_H_
#define _PCCDAOLIB_20130310_PENGSHIKANG_H_

#include "../../../commgr/intfobjptrb.h"         // for CIntfObjPtrB
#include "../../../../interface/dao/smgdao/mgddao/ipccdao.h"// for IPccDao

//DLL����Ľӿڶ�������
class CPccDao : public CIntfObjPtrB<IPccDao>
{
public:
	CPccDao() : CIntfObjPtrB<IPccDao>
		(SMGDAO_MODULE, PCCDAO_CLASSID, PCCDAO_INTFID) { }
};

#endif 
