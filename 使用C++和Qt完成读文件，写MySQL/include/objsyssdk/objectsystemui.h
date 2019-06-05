#ifndef __OBJECT_SYSTEM_COMMON_OBJECTSYSTEM_UI_H_INCLUDED__
#define __OBJECT_SYSTEM_COMMON_OBJECTSYSTEM_UI_H_INCLUDED__


#include "iobjsystem.h"
#include "objsyscommexpdef.h"

#include "intfobject.h"

#include <Q3PtrList>

class OBJSYSCOMMON_CLASS ObjectSystemUI : public CIntfObjectImpl
{
public:
	ObjectSystemUI(IICSUnknown *pOuter = 0);
	~ObjectSystemUI();
public:
	virtual bool ObjQueryInterface(const char *InterfaceName, void **ppV);
protected:
	virtual QWidget* CreateCustomView( IObjectSystem* pObjSys, QWidget* parent);
	virtual bool SelectedInCustomView( IObjectSystem* pObjSys, QWidget* customView, IObjectEntity** ppIObj );
	virtual bool SelectedInCustomView( IObjectSystem* pObjSys, QWidget* customView, QList<IICSUnknown*>& list );
	virtual bool Setup(IObjectSystem* pObjSys);
private:
	class  XObjectSystemUI : public IObjectSystemUI
	{
	public:
		ObjectSystemUI* m_pParent;
		virtual int AddRef(){
            return m_pParent->AddRef();
        };
        virtual int Release(){
			return m_pParent->Release();
        };
        virtual bool QueryInterface(const char *InterfaceName, void **ppUnknown){  
            return m_pParent->QueryInterface(InterfaceName, ppUnknown);
        };
		virtual QWidget* CreateCustomView( IObjectSystem* pObjSys, QWidget* parent){
			return m_pParent->CreateCustomView( pObjSys,parent );
		};
		virtual bool SelectedInCustomView( IObjectSystem* pObjSys, QWidget* customView, IObjectEntity** ppIObj ){
			return m_pParent->SelectedInCustomView( pObjSys, customView, ppIObj );
		};
		virtual bool SelectedInCustomView( IObjectSystem* pObjSys, QWidget* customView, QList<IICSUnknown*>& list ){
			return m_pParent->SelectedInCustomView( pObjSys, customView, list );
		};
		virtual bool Setup(IObjectSystem* pObjSys){
			return m_pParent->Setup(pObjSys);
		};
	}m_XObjSysUI;
	friend class XObjectSystemUI;
};


#endif	//__OBJECT_SYSTEM_COMMON_OBJECTSYSTEM_UI_H_INCLUDED__