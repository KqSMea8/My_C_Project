#ifndef _DATAVALUE_EDIT_H_INCLUDED_
#define _DATAVALUE_EDIT_H_INCLUDED_

#include "trendwndmacro.h"

#include <qwidget.h>

#include "datavaluetype.h"

class QLineEdit;
class QPushButton;
class HMITRENDWND_EXPORT DataValueEdit : public QWidget
{
	Q_OBJECT
public:
	void SetDblValue(double val);
	double GetDblValue();
	DataValueEdit( QWidget * parent = 0, const char * name = 0);
	DataValue GetValue();
	void SetValue(const DataValue& val);
	void SetType(const DataValueType& type, bool bRangeMode = false);
	void Init();
	void UpdateValView();
protected slots:
	void OnValButtonClicked();
	void OnEditTextChanged(const QString& text);
protected:
	QString ToDateTimeString(double dt);
	QString ToDateTimeRange(double dt);
	QLineEdit* m_pValEdit;
	QPushButton* m_pValButton;
private:
	DataValueType m_type;
	DataValue	m_value;
	bool m_bRange;
};
#endif