// statusstisdaolib.h: implement for the CStatusStisDao class.
#ifndef _STATUSSTISDAOLIB_20130310_PENGSHIKANG_H_
#define _STATUSSTISDAOLIB_20130310_PENGSHIKANG_H_

#include "../../../commgr/intfobjptrb.h"       // for CIntfObjPtrB
#include "../../../../interface/dao/scadadao/statisticdao/istatusstisdao.h"    // for IStatusStisDao

class IStatusDao;

//DLL输出的接口对象引用
class CStatusStisDao : public CIntfObjPtrB<IStatusStisDao>
{
public:
	CStatusStisDao(IStatusDao* pStatus) : CIntfObjPtrB<IStatusStisDao>
		(SCADADAO_MODULE, STATUSSTISDAO_CLASSID, STATUSSTISDAO_INTFID, (void**)&pStatus) { }
};

#endif 
