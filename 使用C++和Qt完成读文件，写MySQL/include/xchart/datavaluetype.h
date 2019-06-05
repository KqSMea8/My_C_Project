#ifndef _TREND_DATAVALUE_TYPE_H_INCLUDED_
#define _TREND_DATAVALUE_TYPE_H_INCLUDED_

#include <qstring.h>
#include <qmap.h>

#include "trendobjectexpdef.h"
#include "datavalue.h"

/*
 *	数据类型信息类
 *	数据类型定义
 *	数据的字符串表现格式定义
 *	数据和字符串之间的相互转换
 */
class HMITRENDOBJ_EXPORT DataValueType
{
public:
	typedef enum ValueType
	{
		VTNumber = 0,
		VTText,
		VTDateTime
	};
	DataValueType(ValueType type=VTNumber, const QString& name="");

	//序列化支持
	friend HMITRENDOBJ_EXPORT QDataStream &operator<<( QDataStream &, const DataValueType & );
	friend HMITRENDOBJ_EXPORT QDataStream &operator>>( QDataStream &, DataValueType & );

	//名称
	QString GetName();
	void SetName( const QString& name);

	//类型
	ValueType GetType();
	void SetType( ValueType type);
	//格式定义
	QString GetFormat();
	void SetFormat(const QString& format);
	QMap<double,QString> GetNumStrMap();
	void ClearNumStrMap();
	void RemoveNumStrMap(double val);
	void InsertNumStrMap(double val, const QString& text);
	
	//数值转换
	double ToDouble(const DataValue& data);
	QString ToString(const DataValue& data);
	double StringToDouble(const QString& str);
	QString DoubleToString(double var);

protected:
private:
	//m_strFormat定义:
	// 比如m_strFormat="%1元#2f"
	// #2f是对 %1的格式定义，表示小数形式，保留两位小数
	// 当值为32.2331 返回 32.23元
	// 再如m_strFormat="%1万元#10d"
	// #10d表示十进制整数
	// 当值为32.2331时,返回 32万元
	QString m_strName;		//数据类型名称
	ValueType m_type;		//数据类型
	QString m_strFormat;	//数据的字符串表现格式
	QMap<double,QString>	m_mapNumStr;	//数值-文本影射表
};

HMITRENDOBJ_EXPORT QDataStream &operator<<( QDataStream &, const DataValueType & );
HMITRENDOBJ_EXPORT QDataStream &operator>>( QDataStream &, DataValueType & );

#endif	//_TREND_DATAVALUE_TYPE_H_INCLUDED_
