// sqctrldaolib.h: implement for the CSqCtrlDao class.
#ifndef _SQCTRLDAOLIB_SUNRUI_20140425_H_
#define _SQCTRLDAOLIB_SUNRUI_20140425_H_

#include "../../commgr/intfobjptrb.h"       // for CIntfObjPtrB
#include "../../../interface/dao/scadadao/isqctrldao.h"    // for ISqCtrlDao

//DLL输出的接口对象引用
class CSqCtrlDao : public CIntfObjPtrB<ISqCtrlDao>
{
public:
	CSqCtrlDao() : CIntfObjPtrB<ISqCtrlDao>
		(SCADADAO_MODULE, SQCTRLDAO_CLASSID, SQCTRLDAO_INTFID) { }
};

#endif 
