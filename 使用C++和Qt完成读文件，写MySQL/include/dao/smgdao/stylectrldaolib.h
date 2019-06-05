// stylectrldaolib.h: implement for the CStyleCtrlDao class.
#ifndef _STYLECTRLDAOLIB_20130310_SUNRUI_H_
#define _STYLECTRLDAOLIB_20130310_SUNRUI_H_

#include "../../commgr/intfobjptrb.h"            // for CIntfObjPtrB
#include "../../../interface/dao/smgdao/istylectrldao.h"// for IStyleCtrlDao

//DLL输出的接口对象引用
class CStyleCtrlDao : public CIntfObjPtrB<IStyleCtrlDao>
{
public:
	CStyleCtrlDao() : CIntfObjPtrB<IStyleCtrlDao>
		(SMGDAO_MODULE, STYLECTRLDAO_CLASSID, STYLECTRLDAO_INTFID) { }
};

#endif 
