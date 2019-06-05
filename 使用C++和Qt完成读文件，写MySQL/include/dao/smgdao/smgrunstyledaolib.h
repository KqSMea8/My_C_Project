// smgrunstyledaolib.h: implement for the CSmgRunstyleDao class.
#ifndef _SMGRUNSTYLEDAOLIB_20130311_ZHANGPENG_H_
#define _SMGRUNSTYLEDAOLIB_20130311_ZHANGPENG_H_

#include "../../commgr/intfobjptrb.h"            // for CIntfObjPtrB
#include "../../../interface/dao/smgdao/ismgrunstyledao.h"// for ISmgRunstyleDao

class ISMicgridDao;

//DLL输出的接口对象引用
class CSmgRunstyleDao : public CIntfObjPtrB<ISmgRunstyleDao>
{
public:
	CSmgRunstyleDao(ISMicgridDao* pSMicgrid) : CIntfObjPtrB<ISmgRunstyleDao>
		(SMGDAO_MODULE, SMGRUNSTYLEDAO_CLASSID, SMGRUNSTYLEDAO_INTFID, (void**)&pSMicgrid) { }
};

#endif
