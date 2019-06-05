#ifndef __OBJECT_SYSTEM_COMMON_OBJECTGROUP_H_INCLUDED__
#define __OBJECT_SYSTEM_COMMON_OBJECTGROUP_H_INCLUDED__

#include "iobjsystem.h"
#include "objsyscommexpdef.h"

#include "intfobject.h"

class OBJSYSCOMMON_CLASS ObjectGroup : public CIntfObjectImpl
{
public:
	ObjectGroup(IObjectSystem* pIObjSys,IObjectTypeInfo* pIType,IICSUnknown *pOuter = 0);
	~ObjectGroup();
public:
protected:
	virtual bool ObjQueryInterface(const char *InterfaceName, void **ppV);
	virtual bool GetObjSystem( IObjectSystem** ppIObjSys );
	bool GetObjType( IObjectTypeInfo** ppType );
	virtual int GetObjCount() = 0;
	virtual bool GetObjEntity(int index, IObjectEntity** ppObj ) = 0;
	virtual bool AddObjEntity( IObjectEntity** ppIObj ) = 0;
	virtual bool DelObjEntity( IObjectEntity* pIObj ) = 0;
	IObjectSystem* m_pIObjSys;
	IObjectTypeInfo* m_pIType;	
private:
	class  XObjectGroup : public IObjectGroup
	{
	public:
		ObjectGroup* m_pParent;
		virtual int AddRef(){
            return m_pParent->AddRef();
        };
        virtual int Release(){
			return m_pParent->Release();
        };
        virtual bool QueryInterface(const char *InterfaceName, void **ppUnknown){  
            return m_pParent->QueryInterface(InterfaceName, ppUnknown);
        };
		virtual bool GetObjType( IObjectTypeInfo** ppType ){
			return m_pParent->GetObjType(ppType);
		};
		virtual int GetObjCount(){
			return m_pParent->GetObjCount();
		};
		virtual bool GetObjEntity(int index, IObjectEntity** ppObj ){
			return m_pParent->GetObjEntity(index,ppObj);
		};
		virtual bool AddObjEntity( IObjectEntity** ppIObj ){
			return m_pParent->AddObjEntity(ppIObj);
		};
		virtual bool DelObjEntity( IObjectEntity* pIObj ){
			return m_pParent->DelObjEntity(pIObj);
		};
		virtual bool GetObjSystem( IObjectSystem** ppIObjSys ){
		return m_pParent->GetObjSystem(ppIObjSys );
		};
	}m_XObjGroup;
	friend class XObjectGroup;
};


#endif //__OBJECT_SYSTEM_COMMON_OBJECTGROUP_H_INCLUDED__