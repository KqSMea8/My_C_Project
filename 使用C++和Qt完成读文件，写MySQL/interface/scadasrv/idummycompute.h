// idummycompute.h: interface for the ICalculator class.
//

#ifndef _IDUMMYCOMPUTE_PENGSHIKANG_20130826_H
#define _IDUMMYCOMPUTE_PENGSHIKANG_20130826_H

#include "../icsunknown.h"                       // for IICSUnknown

#define DLL_EXPRESSOPERATE           "expresscalculate"
#define CID_DUMMYCOMPUTE             "cdummycompute"
#define IID_DUMMYCOMPUTE             "idummycompute"

//���ʽ����(@00210000=1)&(@00220000<1.26)
//˵����1��@���Ǳ�������������8���ַ�,�ַ����ݿ���������ģ�
//		2��< = �������ǰ�����пո�
//		3��& �룬| ��
//		4�������Ǳ����
//		5�����ʽ����಻�ܳ���19������

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

#define FORMULAMAXLENGTH 512
#define MAXOPERANDCOUNT  200

class ICalculator //: virtual public IICSUnknown 
{
public:
	virtual double DoCalculate(const char* expression, bool& bOk) = 0;
	virtual int GetLastError() = 0;
	virtual const char* GetLastErrorInfo() = 0;
};

#endif