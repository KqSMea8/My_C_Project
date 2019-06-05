// smoothctrldaolib.h: implement for the CSmoothCtrlDao class.
#ifndef _SMOOTHCTRLDAOLIB_20130311_ZHANGPENG_H_
#define _SMOOTHCTRLDAOLIB_20130311_ZHANGPENG_H_

#include "../../commgr/intfobjptrb.h"            // for CIntfObjPtrB
#include "../../../interface/dao/smgdao/ismoothctrldao.h"// for ISmoothCtrlDao

//DLL输出的接口对象引用
class CSmoothCtrlDao : public CIntfObjPtrB<ISmoothCtrlDao>
{
public:
	CSmoothCtrlDao() : CIntfObjPtrB<ISmoothCtrlDao>
		(SMGDAO_MODULE, SMOOTHCTRLDAO_CLASSID, SMOOTHCTRLDAO_INTFID) { }
};

#endif
