#ifndef _IWAVEGRAPH_H__
#define _IWAVEGRAPH_H__

#include "icsunknown.h"

#define IID_IComtradeGraph			"icomtradegraph"
#define CLSID_ComtradeGraph			"comtradegraph"
#define MODULE_COMTRADEGRAPH		"comtradegraph"

class QWidget;
class IComtradeObject;
class IComtradeGraph : virtual public IICSUnknown
{
public:
	// UI构建
	virtual QWidget* GetWindow() = 0;
	virtual void OnCreate(QWidget* pParentWnd) = 0;
	virtual void OnDestroy() = 0;
	virtual void Show() = 0;
	virtual void Hide() = 0;
	virtual void Move(const QPoint& offset) = 0;
	virtual void Resize(int w, int h) = 0;

	// 数据交互
	virtual void SetComtrade(IComtradeObject* pComtradeObj) = 0;
	virtual void SetProtReport(void* pReport) = 0;
};

#endif