// statusprdstisdaolib.h: implement for the CSttsPrdStisDao class.
#ifndef _STTSPRDSTISDAOLIB_20130310_PENGSHIKANG_H_
#define _STTSPRDSTISDAOLIB_20130310_PENGSHIKANG_H_

#include "../../../commgr/intfobjptrb.h"       // for CIntfObjPtrB
#include "../../../../interface/dao/scadadao/statisticdao/istatusprdstisdao.h"    // for ISttsPrdStisDao

class IPeriodDao;
class IPeriodTypeDao;

//DLL����Ľӿڶ�������
class CSttsPrdStisDao : public CIntfObjPtrB<ISttsPrdStisDao>
{
public:
	CSttsPrdStisDao(IPeriodDao* pPeriod, IPeriodTypeDao* pPrdType) : CIntfObjPtrB<ISttsPrdStisDao>
		(SCADADAO_MODULE, STTSPRDSTISDAO_CLASSID, STTSPRDSTISDAO_INTFID)
	{
		void* pParams[2];
		pParams[0] = (void*)pPeriod;//ʱ��ʵ�����
		pParams[1] = (void*)pPrdType;//ʱ������ʵ�����
		m_pObj = CreateObject(pParams);
	}
};

#endif 
