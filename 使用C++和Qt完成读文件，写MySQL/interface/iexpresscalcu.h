// iexpresscalcu.h
#ifndef _IEXPRESSCALCU_H_
#define _IEXPRESSCALCU_H_

#include "icsunknown.h" // for IICSUnknown

//数据计算接口
#define DLL_EXPRESSCALCU	"expresscalcu"
#define IID_EXPRESSCALCU	"IExpressCalcu"
#define CID_EXPRESSCALCU	"CExpressCalcu"


class IExpressCalcu: public IICSUnknown
{
public:
	//返回结果0成功，1：表达式为空，2：表达式不正确，3：被除数为0,  4:计算超值域， 5:实时库连接失败 ,6:计算ID不存在
	//数据质量quality：
	///根据表达式计算结果
	virtual	int calcuExp(const char* exp,double* result,int* quality) = 0;  
	//通过计算ID计算结果
	virtual	int calcuExpCalID(int expCalID,double* result,int* quality) = 0; 
	//弹出用户自定义计算对话框
	virtual	void customerCal() = 0; 
};

#endif
