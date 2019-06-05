#ifndef __HMI_IBROWSERMODEL_H_INCLUDED__
#define __HMI_IBROWSERMODEL_H_INCLUDED__

#include <qobject.h>
#include <qmap.h>
#include <qvariant.h>
#include <qpixmap.h>

#define XBROWSER_EVENT_LOGIN	"LogIn"
#define XBROWSER_EVENT_LOGOUT	"LogOut"
#define XBROWSER_EVENT_REFRESH	"Refresh"
#define XBROWSER_EVENT_PRINT	"Print"
#define XBROWSER_EVENT_ADDFAVORITE	"AddToFavorite"
#define XBROWSER_EVENT_OPENFAVORITE	"OpenFavorite"
#define XBROWSER_EVENT_ACTIVATE	"activate"
#define XBROWSER_EVENT_PASSIVE "inactivate"

class IBrowser;
class IXViewModule : public QObject
{
public:
	virtual void Load(IBrowser* frame, QString name, const QMap<QString,QVariant>& paras) = 0;
	virtual void OnEvent(const QString& event, const QMap<QString,QVariant>& args) = 0;
	virtual void UnLoad() = 0;
	
	//返回模块说明文字
	virtual QString GetCapton() = 0;
	virtual QPixmap GetIcon() = 0;
};

#ifdef _MSC_VER
#define BROWSER_MODULE_API __declspec(dllexport)
#else
#define BROWSER_MODULE_API 
#endif

extern "C"
{
	BROWSER_MODULE_API IXViewModule* CreateModule();
}

typedef IXViewModule* (*MethodCreateModule)();

#endif