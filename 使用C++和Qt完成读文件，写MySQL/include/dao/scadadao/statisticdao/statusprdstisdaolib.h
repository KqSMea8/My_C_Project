// statusprdstisdaolib.h: implement for the CSttsPrdStisDao class.
#ifndef _STTSPRDSTISDAOLIB_20130310_PENGSHIKANG_H_
#define _STTSPRDSTISDAOLIB_20130310_PENGSHIKANG_H_

#include "../../../commgr/intfobjptrb.h"       // for CIntfObjPtrB
#include "../../../../interface/dao/scadadao/statisticdao/istatusprdstisdao.h"    // for ISttsPrdStisDao

class IPeriodDao;
class IPeriodTypeDao;

//DLL输出的接口对象引用
class CSttsPrdStisDao : public CIntfObjPtrB<ISttsPrdStisDao>
{
public:
	CSttsPrdStisDao(IPeriodDao* pPeriod, IPeriodTypeDao* pPrdType) : CIntfObjPtrB<ISttsPrdStisDao>
		(SCADADAO_MODULE, STTSPRDSTISDAO_CLASSID, STTSPRDSTISDAO_INTFID)
	{
		void* pParams[2];
		pParams[0] = (void*)pPeriod;//时段实体对象
		pParams[1] = (void*)pPrdType;//时段类型实体对象
		m_pObj = CreateObject(pParams);
	}
};

#endif 
