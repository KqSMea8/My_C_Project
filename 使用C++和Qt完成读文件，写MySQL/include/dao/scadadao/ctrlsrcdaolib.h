// ctrlsrcdaolib.h: implement for the CControlSrcDao class.
#ifndef _CONTROLSRCDAOLIB_20180801_PENGSHIKANG_H_
#define _CONTROLSRCDAOLIB_20180801_PENGSHIKANG_H_

#include "../../commgr/intfobjptrb.h"            // for CIntfObjPtrB
#include "../../../interface/dao/scadadao/icontrolsrcdao.h"// for IControlSrcDao

//DLL输出的接口对象引用
class CControlSrcDao : public CIntfObjPtrB<IControlSrcDao>
{
public:
	CControlSrcDao() : CIntfObjPtrB<IControlSrcDao>
		(SCADADAO_MODULE, CTRLSRCDAO_CLASSID, CTRLSRCDAO_INTFID) { }
};

#endif 