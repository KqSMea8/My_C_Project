// settingareadaolib.h: implement for the CSettAreaDao class.
#ifndef _SETTINGAREADAOLIB_20130311_PENGSHIKANG_H_
#define _SETTINGAREADAOLIB_20130311_PENGSHIKANG_H_

#include "../../commgr/intfobjptrb.h"       // for CIntfObjPtrB
#include "../../../interface/dao/scadadao/isettingareadao.h"    // for ISettAreaDao

//DLL输出的接口对象引用
class CSettAreaDao : public CIntfObjPtrB<ISettAreaDao>
{
public:
	CSettAreaDao() : CIntfObjPtrB<ISettAreaDao>
		(SCADADAO_MODULE, SETTINGAREADAO_CLASSID, SETTINGAREADAO_INTFID) { }
};

#endif 