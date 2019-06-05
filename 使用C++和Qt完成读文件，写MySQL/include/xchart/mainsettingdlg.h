#include "trendwndmacro.h"

#include <q3tabdialog.h>

class TrendManager;
class TrendProject;
class WndSettingImpl;
class TitleLegendImpl;
class AxisSettingImpl;
class TrendSettingImpl;
class DataSourceMgrImpl;

class HMITRENDWND_EXPORT MainSettingDlg : public Q3TabDialog
{
	Q_OBJECT
public:
	void SetData(TrendProject* trendPrj);
	MainSettingDlg( QWidget * parent = 0, const char * name = 0, bool modal = FALSE);
protected slots:
	void Apply();
private:
	TrendManager* m_trendMgr;
	WndSettingImpl* m_pWndPage;
	TitleLegendImpl* m_pTtlLgndPage;
	AxisSettingImpl* m_pAxisPage;
	TrendSettingImpl* m_pTrendPage;
	DataSourceMgrImpl* m_pDsMgr;
};