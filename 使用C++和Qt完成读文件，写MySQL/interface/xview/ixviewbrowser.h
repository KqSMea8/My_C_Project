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

	//���Ĵ��ڷ���
	virtual QWidget* ViewContainer() = 0;
	virtual void AddView(QWidget* widget, const QString& module, bool closable = true, int screen = -1 ) = 0;
	virtual void RaiseView(QWidget* widget) = 0;
	virtual void RemoveView(QWidget* widget) = 0;

	//��ӹ��߰�ť
	virtual void AddToolButton( QAction* action) = 0;
	virtual void AddToolButton( QWidget* widget) = 0;
	virtual int AddMenuBar(const QString& text, QMenu* popup) = 0;
	virtual int AddMenuBar(QActionGroup* ag) = 0;
	virtual void RemoveMenuBar(int id) = 0;

	//״̬������
	virtual void AddStatusWidget( QWidget* widget, int stretch = 0, bool permanent = false ) = 0;
	virtual void RemoveStatusWidget( QWidget* widget ) = 0;
	virtual void DisplayStatusMessage( const QString& msg, int ms = -1 ) = 0;
	virtual void ClearStatusMessage() = 0;

	//���ͣ�����ڣ�������/ͣ�����ڵ�)
	virtual QDockWidget* AddDockWindow( QWidget* widget, const QString& label, Qt::DockWidgetArea dock, int screen = -1 ) = 0;
	virtual void SetDockEnabled ( QDockWidget * dw, Qt::DockWidgetArea dock, bool enable ) = 0;
	//���ͣ������ҳ
	virtual void AddLeftDockTabPage( QWidget * page, const QString & label, const QIcon & iconset ) = 0;	
	virtual void AddBottomDockTabPage( QWidget * page, const QString & label, const QIcon & iconset ) = 0;	
	virtual void ChangeDockWindow( QWidget * widget, const QString & label, const QIcon & iconset ) = 0;
	virtual void RemoveDockWindow( QWidget* widget ) = 0;
	virtual void SetDockWindowShown( QWidget* widget, bool show = true ) = 0;

	//���������������Ϣ
	virtual void DisplaySplashMessage( const QString& msg, int alignment = Qt::AlignLeft, const QColor & color = Qt::black ) = 0;
	virtual void ClearSplashMessage() = 0;

	//ģ�����Ϣ����
	virtual void PostEventToMdl(const QString& module, const QString& event, const QMap<QString,QVariant>& args) = 0;
	virtual void PostEventToMdl(const QString& module, const QString& event) = 0;

	//��ǰ��¼�û�
	virtual QString GetCurrentUser() = 0;
	virtual void AddToFavorite(const QString& module, const QString& name, const QString& url, const QMap<QString,QVariant>& data ) = 0;
};

#endif