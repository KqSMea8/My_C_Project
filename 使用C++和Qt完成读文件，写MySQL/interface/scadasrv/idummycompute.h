// idummycompute.h: interface for the ICalculator class.
//

#ifndef _IDUMMYCOMPUTE_PENGSHIKANG_20130826_H
#define _IDUMMYCOMPUTE_PENGSHIKANG_20130826_H

#include "../icsunknown.h"                       // for IICSUnknown

#define DLL_EXPRESSOPERATE           "expresscalculate"
#define CID_DUMMYCOMPUTE             "cdummycompute"
#define IID_DUMMYCOMPUTE             "idummycompute"

//表达式例子(@00210000=1)&(@00220000<1.26)
//说明：1、@后是变量名，必须是8个字符,字符内容可以是任意的；
//		2、< = 等运算符前后不能有空格；
//		3、& 与，| 或
//		4、括号是必须的
//		5、表达式中最多不能超过19个变量

/*
// type : 的定义
// 0 : const 常量
// 1 ~ 19: Var 第几个变量,最多可达19个
// 20 : left parenthesis 左括号'('
// 21~39 : operator Double 双目操作符 + - * / ^ 等
// 40 : right parenthesis 右括号')'
// 41~49 : operator Single 单目操作符 '-'(求相反数)、 '+' 等
// 41~44 : -、+、!、~
// 51~99 : Functions 函数
// 51~60 : SIN、COS、TAN、SQRT、LOG、LN、COT、ABS、FINT、ARCSIN
// 61~65 : ARCCOS、ARCTAN、SINH、COSH、TANH


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