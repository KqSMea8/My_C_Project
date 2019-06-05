// iexpresscalculate.h: interface for the IExpressCalculate class.
//
//////////////////////////////////////////////////////////////////////

#ifndef AFX_IEXPRESSOPERATE_H__PENGSHIKANG_20120812_NEW_INCLUDED_
#define AFX_IEXPRESSOPERATE_H__PENGSHIKANG_20120812_NEW_INCLUDED_

#define DLL_EXPRESSOPERATE           "expresscalculate"
#define CID_EXPRESSOPERATE           "cexpresscalculate"
#define IID_IEXPRESSOPERATE          "iexpresscalculate"

#include "../icsunknown.h"                       // for IICSUnknown
#include "iexpressmap.h"                         // for ExpMap��IExpressMap

class IExpressCalculate : virtual public IICSUnknown 
{
public:
	//�Դ������ı��ʽ���м���
	virtual bool CalculateExpMap(IExpressMap* pExprMap, ExpMap* curExp, double& dResult, int& nQuality) = 0;
	//�Ա��ʽ���м��㡣��pExprMap=0����ʾ��������
	virtual bool CalculateExpress(IExpressMap* pExprMap, const char* expr, double& dResult, int& nQuality) = 0;
	//������ʽ����Ƿ�ΪTRUE����pExprMap=0����ʾ��������
	virtual bool IsTrue(IExpressMap* pExprMap, const char* strExpr) = 0;

public:
	static char *GetIntfName()
	{
		return IID_IEXPRESSOPERATE;
	};

};

#endif
