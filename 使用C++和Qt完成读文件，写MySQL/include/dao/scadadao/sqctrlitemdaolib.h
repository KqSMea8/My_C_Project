// sqctrlitemdaolib.h: implement for the CSqCtrlitemDao class.
#ifndef _SQCTRLITEMDAOLIB_SUNRUI_20140425_H_
#define _SQCTRLITEMDAOLIB_SUNRUI_20140425_H_

#include "../../commgr/intfobjptrb.h"       // for CIntfObjPtrB
#include "../../../interface/dao/scadadao/isqctrlitemdao.h"    // for ISqCtrlitemDao

//DLL输出的接口对象引用
class CSqCtrlitemDao : public CIntfObjPtrB<ISqCtrlitemDao>
{
public:
	CSqCtrlitemDao() : CIntfObjPtrB<ISqCtrlitemDao>
		(SCADADAO_MODULE, SQCTRLITEMDAO_CLASSID, SQCTRLITEMDAO_INTFID) { }
};

#endif 
