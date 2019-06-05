#ifndef _TREND_DATAVALUE_H_INCLUDED_
#define _TREND_DATAVALUE_H_INCLUDED_

#include "trendobjectexpdef.h"

#include <qstring.h>

/*
 *	���ݴ洢��:֧����ֵ���ͺ��ַ������͵Ĵ洢
 *	�����ڲ�ͨ�����캯����ʼ��
 *	�����ݵĶ�ȡҪͨ������������DataValueType��ȡ
 *	
 */
class HMITRENDOBJ_EXPORT DataValue
{
public:
	DataValue();
	explicit DataValue(double dbl);
	explicit DataValue(const QString& str);
	DataValue(double dbl, const QString& str);
	
	//���л�֧��
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