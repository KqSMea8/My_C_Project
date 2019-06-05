#ifndef _TREND_DATAVALUE_H_INCLUDED_
#define _TREND_DATAVALUE_H_INCLUDED_

#include "trendobjectexpdef.h"

#include <qstring.h>

/*
 *	数据存储类:支持数值类型和字符串类型的存储
 *	数据内部通过构造函数初始化
 *	对数据的读取要通过数据类型类DataValueType读取
 *	
 */
class HMITRENDOBJ_EXPORT DataValue
{
public:
	DataValue();
	explicit DataValue(double dbl);
	explicit DataValue(const QString& str);
	DataValue(double dbl, const QString& str);
	
	//序列化支持
	friend HMITRENDOBJ_EXPORT QDataStream &operator<<( QDataStream &, const DataValue & );
	friend HMITRENDOBJ_EXPORT QDataStream &operator>>( QDataStream &, DataValue & );
private:
	double m_fVal;
	QString m_strVal;
	friend class DataValueType;
};

HMITRENDOBJ_EXPORT QDataStream &operator<<( QDataStream &, const DataValue & );
HMITRENDOBJ_EXPORT QDataStream &operator>>( QDataStream &, DataValue & );

#endif	//_TREND_DATAVALUE_H_INCLUDED_