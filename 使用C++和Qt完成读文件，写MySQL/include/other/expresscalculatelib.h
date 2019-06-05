// expresscalculatelib.h: implement for the CExpressCalculateLib class.
#ifndef _EXPRESSOPERATELIB_2013_09_05_PENGSHIKANG_H_
#define _EXPRESSOPERATELIB_2013_09_05_PENGSHIKANG_H_

#include "../commgr/intfobjptra.h"               // for CIntfObjPtrA
#include "../../interface/scadasrv/idummycompute_v2d1.h"// for ICalculator
#include "../../interface/scadasrv/iexpresscalculate_v2d1.h"// for IExpressCalculate

//DLL输出的接口对象引用
class CCalculateLib : public CIntfObjPtrA<ICalculator>
{
public:
	CCalculateLib() : CIntfObjPtrA<ICalculator>(DLL_DUMMYCOMPUTE, CID_DUMMYCOMPUTE, IID_DUMMYCOMPUTE)
	{
		m_pObj = CreateObject(CID_DUMMYCOMPUTE, IID_DUMMYCOMPUTE);
	}
};

//DLL输出的接口对象引用
class CExpressCalculateLib : public CIntfObjPtrA<IExpressCalculate>
{
public:
	CExpressCalculateLib() : CIntfObjPtrA<IExpressCalculate>(DLL_EXPRESSOPERATE, CID_EXPRESSOPERATE, IID_IEXPRESSOPERATE)
	{
		m_pObj = CreateObject(CID_EXPRESSOPERATE, IID_IEXPRESSOPERATE);
	}
};

#endif 
