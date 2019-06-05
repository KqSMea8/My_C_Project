// idummycompute.h: interface for the ICalculator class.
//

#ifndef _IDUMMYCOMPUTE_PENGSHIKANG_20130826_NEW_H
#define _IDUMMYCOMPUTE_PENGSHIKANG_20130826_NEW_H

#include "../icsunknown.h"                       // for IICSUnknown

#define DLL_DUMMYCOMPUTE             "expresscalculate"
#define CID_DUMMYCOMPUTE             "cdummycompute"
#define IID_DUMMYCOMPUTE             "idummycompute"

/*
// type : �Ķ���
// 0 : const ����
// 1 ~ 19: Var �ڼ�������,���ɴ�19��

// 20 : left parenthesis ������'('
// 21~39 : operator Double ˫Ŀ������ + - * / ^ ��
// 40 : right parenthesis ������')'

// 41~49 : operator Single ��Ŀ������ '-'(���෴��)�� '+' ��
// 41~44 : -��+��!��~

// 51~99 : Functions ����
// 51~60 : SIN��COS��TAN��SQRT��LOG��LN��COT��ABS��FINT��ARCSIN
// 61~65 : ARCCOS��ARCTAN��SINH��COSH��TANH
*/

class ICalculator : virtual public IICSUnknown 
{
public:
	virtual double DoCalculate(const char* expression, bool& bOk) = 0;
	virtual int GetLastError() = 0;
	virtual const char* GetLastErrorInfo() = 0;

public:
	static char *GetIntfName()
	{
		return IID_DUMMYCOMPUTE;
	};
};

#endif