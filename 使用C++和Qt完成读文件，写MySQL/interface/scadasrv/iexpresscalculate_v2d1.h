// iexpresscalculate.h: interface for the IExpressCalculate class.
//
//////////////////////////////////////////////////////////////////////

#ifndef AFX_IEXPRESSOPERATE_H__PENGSHIKANG_20120812_NEW_INCLUDED_
#define AFX_IEXPRESSOPERATE_H__PENGSHIKANG_20120812_NEW_INCLUDED_

#define DLL_EXPRESSOPERATE           "expresscalculate"
#define CID_EXPRESSOPERATE           "cexpresscalculate"
#define IID_IEXPRESSOPERATE          "iexpresscalculate"

#include "../icsunknown.h"                       // for IICSUnknown
#include "iexpressmap.h"                         // for ExpMap、IExpressMap

class IExpressCalculate : virtual public IICSUnknown 
{
public:
	//对带参数的表达式进行计算
	virtual bool CalculateExpMap(IExpressMap* pExprMap, ExpMap* curExp, double& dResult, int& nQuality) = 0;
	//对表达式进行计算。若pExprMap=0，表示不带参数
	virtual bool CalculateExpress(IExpressMap* pExprMap, const char* expr, double& dResult, int& nQuality) = 0;
	//计算表达式结果是否为TRUE。若pExprMap=0，表示不带参数
	virtual bool IsTrue(IExpressMap* pExprMap, const char* strExpr) = 0;

public:
	static char *GetIntfName()
	{
		return IID_IEXPRESSOPERATE;
	};

};

#endif
