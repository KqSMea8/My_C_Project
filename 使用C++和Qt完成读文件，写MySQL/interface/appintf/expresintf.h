#ifndef _EXPRESSIONAPI_H_
#define _EXPRESSIONAPI_H_

#include "icsunknown.h"

//定义接口名称常量
#define IID_IICSExpression		"IICSExpression"

//定义对象名称常量
#define CLSID_Expression		"expression"

/*
IICSExpression表达式解析接口
*/
class IICSExpression : public IICSUnknown
{
public:
    /*
        【功  能】      设置表达式
        【参  数】      express: 表达式字符串
    */
	virtual void SetExpression(const char* express) = 0;

    /*
        【功  能】      表达式有效?
        【参  数】
    */
	virtual bool IsValid() = 0;

    /*
        【功  能】      获得表达式中变量个数
        【参  数】      
    */
	virtual int VarCount() = 0;

    /*
        【功  能】      获得变量名称
        【参  数】      index: 变量序号
    */
	virtual const char* VarName(int index) = 0;

    /*
        【功  能】      设置变量数值
        【参  数】      index:变量序号 val: 变量数值
    */
	virtual void SetVarValue(int index, double val) = 0;

    /*
        【功  能】      获得表达式计算值
        【参  数】      无
    */
	virtual double Value() = 0;

    /*
        【功  能】      表达式编译的错误信息(语法解析)
        【参  数】      无
    */
	virtual const char* GetLastError() = 0;
public:
    static char *GetIntfName()
    {
        return IID_IICSExpression;
    };
};

//定义创建对象函数类型以及函数名称(for class)
//typedef bool (*GetClassObjectMethod)(char *classname, IICSUnknown** ppUnk);
//#define METHOD_GETCLASSOBJECT "GetClassObject"

//定义对象模块名称
#define MODULE_EXPRESSION	"expression"


#endif