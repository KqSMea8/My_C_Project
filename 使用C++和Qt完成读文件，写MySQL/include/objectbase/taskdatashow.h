//taskdatashow.h
#ifndef _TASKDATASHOW_20080122_PENGSHIKANG_H_ 
#define _TASKDATASHOW_20080122_PENGSHIKANG_H_

#include <qfile.h>
#include <map>
#include "icsvariant.h"
#include "objectbase.h"

class IICSRtdbObject;
class IICSTaskObject;

typedef std::multimap<QString, icsarray*> ARYMAP;

//得到字段类型名称
void OBJECTBASE_EXPORT FieldTypeToString(FIELDTYPE ft, char* sType);

//判断icsvariant对象的值是否为空值
bool OBJECTBASE_EXPORT VariantIsNull(const icsvariant& var);
//设置icsvariant对象的值为空值
void OBJECTBASE_EXPORT SetNullVariant(icsvariant& var);

//时间的天数值转化为标准时间字符串
void OBJECTBASE_EXPORT CDatetimeToString(double dTime, char* sTime);
//IICSUnknown对象的值转化为字符串
void OBJECTBASE_EXPORT GetUnknownObjectString(char* strOut, IICSUnknown* pUnk);

//数组元素值转化为字符串
void OBJECTBASE_EXPORT GetElementString(char* strOut, FIELDTYPE ft, void* pValue, int index=0);
//icsarray对象的值转化为字符串
void OBJECTBASE_EXPORT GetArrayString(char* strOut, const icsarray& ary, const char* sep=",");
//icsvariant对象的值转化为字符串
bool OBJECTBASE_EXPORT GetVariantString(char* strOut, const icsvariant& var, const char* sep=",", bool bShowNull=false);
//得到字段数组元素信息字符串
QString OBJECTBASE_EXPORT ICSArrayToString(const char* name, icsarray* pAry, int index, int order1, int order2=-1);

//深拷贝构建一个新的数组对象
void OBJECTBASE_EXPORT CopyArray(icsarray& arySrc, icsarray* aryDest);
//释放数组占用的内存空间
void OBJECTBASE_EXPORT FreeArray(icsarray* pAry);
//释放数组列表占用的内存空间
void OBJECTBASE_EXPORT FreeArrayList(ARYMAP& aryList);

//处理icsvariant变量信息：单值变量，输出变量信息；数组变量，构建数组列表。
void DealICSVariant(const char* name, const icsvariant& valu, QString& strContext, 
	ARYMAP& arrayList, ARYMAP& childList);
//根据一维（父)数组，得到指定组号的二维（子）数组的首元素索引号
int OBJECTBASE_EXPORT GetHeadPosOfChildArray(icsarray* aryParent, int groupNo);

//输出所有一、二级数组元素信息
void OBJECTBASE_EXPORT OutputArrayList(QString& strContext, ARYMAP& arrayList, ARYMAP& childList);

//将输出的字符串信息写入日志文件
void OBJECTBASE_EXPORT WriteLogToFile(const char* fileName, const char* outInfo, QIODevice::OpenMode mode, bool timestamp=true);

//变量转化为BYTE数据
bool OBJECTBASE_EXPORT VariantToByte(const icsvariant& var, BYTE& bOut);
//变量转化为short数据
bool OBJECTBASE_EXPORT VariantToShort(const icsvariant& var, short& sOut);
//变量转化为int数据
bool OBJECTBASE_EXPORT VariantToInt(const icsvariant& var, int& iOut);
//变量转化为float数据
bool OBJECTBASE_EXPORT VariantToFloat(const icsvariant& var, float& fOut);
//变量转化为double数据
bool OBJECTBASE_EXPORT VariantToDouble(const icsvariant& var, double& dOut);

#endif