#ifndef __HMI_IBROWSER_H_INCLUDED__
#define __HMI_IBROWSER_H_INCLUDED__

#include <QObject>
#include <QMainWindow>
#include <QAction>
#include <QMenu>
#include <QDockWidget>


class IBrowser : public QObject
{
public:
	virtual QMainWindow* MainWindow() = 0;

	//中心窗口访问
	virtual QWidget* ViewContainer() = 0;
	virtual void AddView(QWidget* widget, const QString& module, bool closable = true, int screen = -1 ) = 0;
	virtual void RaiseView(QWidget* widget) = 0;
	virtual void RemoveView(QWidget* widget) = 0;

	//添加工具按钮
	virtual void AddToolButton( QAction* action) = 0;
	virtual void AddToolButton( QWidget* widget) = 0;
	virtual int AddMenuBar(const QString& text, QMenu* popup) = 0;
	virtual int AddMenuBar(QActionGroup* ag) = 0;
	virtual void RemoveMenuBar(int id) = 0;

	//状态条功能
	virtual void AddStatusWidget( QWidget* widget, int stretch = 0, bool permanent = false ) = 0;
	virtual void RemoveStatusWidget( QWidget* widget ) = 0;
	virtual void DisplayStatusMessage( const QString& msg, int ms = -1 ) = 0;
	virtual void ClearStatusMessage() = 0;

	//添加停靠窗口（工具条/停靠窗口等)
	virtual QDockWidget* AddDockWindow( QWidget* widget, const QString& label, Qt::DockWidgetArea dock, int screen = -1 ) = 0;
	virtual void SetDockEnabled ( QDockWidget * dw, Qt::DockWidgetArea dock, bool enable ) = 0;
	//添加停靠窗口页
	virtual void AddLeftDockTabPage( QWidget * page, const QString & label, const QIcon & iconset ) = 0;	
	virtual void AddBottomDockTabPage( QWidget * page, const QString & label, const QIcon & iconset ) = 0;	
	virtual void ChangeDockWindow( QWidget * widget, const QString & label, const QIcon & iconset ) = 0;
	virtual void RemoveDockWindow( QWidget* widget ) = 0;
	virtual void SetDockWindowShown( QWidget* widget, bool show = true ) = 0;

	//在启动画面输出信息
	virtual void DisplaySplashMessage( const QString& msg, int alignment = Qt::AlignLeft, const QColor & color = Qt::black ) = 0;
	virtual void ClearSplashMessage() = 0;

	//模块间消息传递
	virtual void PostEventToMdl(const QString& module, const QString& event, const QMap<QString,QVariant>& args) = 0;
	virtual void PostEventToMdl(const QString& module, const QString& event) = 0;

	//当前登录用户
	virtual QString GetCurrentUser() = 0;
	virtual void AddToFavorite(const QString& module, const QString& name, const QString& url, const QMap<QString,QVariant>& data ) = 0;
};

#endif