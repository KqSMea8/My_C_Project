#ifndef _TREND_DATAVALUE_TYPE_H_INCLUDED_
#define _TREND_DATAVALUE_TYPE_H_INCLUDED_

#include <qstring.h>
#include <qmap.h>

#include "trendobjectexpdef.h"
#include "datavalue.h"

/*
 *	����������Ϣ��
 *	�������Ͷ���
 *	���ݵ��ַ������ָ�ʽ����
 *	���ݺ��ַ���֮����໥ת��
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

	//���л�֧��
	friend HMITRENDOBJ_EXPORT QDataStream &operator<<( QDataStream &, const DataValueType & );
	friend HMITRENDOBJ_EXPORT QDataStream &operator>>( QDataStream &, DataValueType & );

	//����
	QString GetName();
	void SetName( const QString& name);

	//����
	ValueType GetType();
	void SetType( ValueType type);
	//��ʽ����
	QString GetFormat();
	void SetFormat(const QString& format);
	QMap<double,QString> GetNumStrMap();
	void ClearNumStrMap();
	void RemoveNumStrMap(double val);
	void InsertNumStrMap(double val, const QString& text);
	
	//��ֵת��
	double ToDouble(const DataValue& data);
	QString ToString(const DataValue& data);
	double StringToDouble(const QString& str);
	QString DoubleToString(double var);

protected:
private:
	//m_strFormat����:
	// ����m_strFormat="%1Ԫ#2f"
	// #2f�Ƕ� %1�ĸ�ʽ���壬��ʾС����ʽ��������λС��
	// ��ֵΪ32.2331 ���� 32.23Ԫ
	// ����m_strFormat="%1��Ԫ#10d"
	// #10d��ʾʮ��������
	// ��ֵΪ32.2331ʱ,���� 32��Ԫ
	QString m_strName;		//������������
	ValueType m_type;		//��������
	QString m_strFormat;	//���ݵ��ַ������ָ�ʽ
	QMap<double,QString>	m_mapNumStr;	//��ֵ-�ı�Ӱ���
};

HMITRENDOBJ_EXPORT QDataStream &operator<<( QDataStream &, const DataValueType & );
HMITRENDOBJ_EXPORT QDataStream &operator>>( QDataStream &, DataValueType & );

#endif	//_TREND_DATAVALUE_TYPE_H_INCLUDED_
