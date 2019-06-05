//isettingenumdao.h

#ifndef _ISETTINGENUMDAO_PENGSHIKANG_20131224_H_
#define _ISETTINGENUMDAO_PENGSHIKANG_20131224_H_

#include "../ibasicdao.h"                        // for IBasicDao
#include <QStringList>                           // for QStringList

#define SETTINGENUMDAO_CLASSID    "csettingenumdao"
#define SETTINGENUMDAO_INTFID     "isettingenumdao"

//参数枚举数据定义
class ISettEnumDao : virtual public IBasicDao
{
public:	
	//根据枚举数据记录位置得到枚举值集合
	virtual const char* GetEnumValues(int pos) = 0;
	//根据枚举数据记录位置得到枚举描述集合
	virtual const char* GetEnumDescrips(int pos) = 0;
	//根据枚举数据记录位置得到枚举值名对集合
	virtual const char* GetEnumVal_Names(int pos) = 0;
	//根据枚举数据记录位置得到枚举值名对列表
	virtual bool GetEnumVal_NameList(int pos, QStringList& valNames) = 0;
};

#endif
