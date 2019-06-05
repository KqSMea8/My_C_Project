#ifndef __OBJECTSYSTEM_COMMON_OBJECTENTITY_H_INCLUDED__
#define __OBJECTSYSTEM_COMMON_OBJECTENTITY_H_INCLUDED__

#include "iobjsystem.h"

#include "objsyscommexpdef.h"
#include <qimage.h>
//Added by qt3to4:
#include <Q3PtrList>

#include "intfobject.h"

class OBJSYSCOMMON_CLASS ObjectEntity : public CIntfObjectImpl
{
public:
	ObjectEntity(IObjectSystem* pIObjSys,IObjectTypeInfo* pIType, IICSUnknown *pOuter = 0);
	~ObjectEntity();
public:
	virtual void EmitSignal(const QString& signalName, const QMap<QString,QVariant>& args );
protected:
	virtual bool ObjQueryInterface(const char *InterfaceName, void **ppV);
	virtual bool GetObjSystem( IObjectSystem** ppIObjSys );
	virtual bool GetObjType( IObjectTypeInfo** ppType );
	virtual bool GetCondition( QMap<QString,QVariant>& cond ) = 0;
	virtual bool MatchCondition( const QMap<QString,QVariant>& cond ) {return true;}
	virtual QString GetName() = 0;
	virtual QString GetDesc() = 0;
	virtual bool IsValid() = 0;
	virtual QImage GetIcon();
	virtual bool SetProperty( const QString& name, const QVariant& val ) = 0;
	virtual bool GetProperty( const QString& name, QVariant& val ) = 0;
	virtual bool CallMethod( const QString& method, const QMap<QString,QVariant>& args, QVariant& res ) = 0;
	virtual bool RegSignalAnswer( IObjSignalAnswer* pIAnswer, bool bReg );
	virtual bool Update() = 0;
	virtual bool Commit() = 0;
	virtual bool GetRelObjectEntity(const QString& rel, const QMap<QString,QVariant>& condition, IObjectEntity** ppObj) = 0;
	virtual bool GetRelObjectGroup(const QString& rel, const QMap<QString,QVariant>& condition, IObjectGroup** ppObjs) = 0;
	IObjectSystem* m_pIObjSys;
	IObjectTypeInfo* m_pIType;
private:
	class  XObjectEntity : public IObjectEntity
	{
	public:
		ObjectEntity* m_pParent;
		virtual int AddRef(){
            return m_pParent->AddRef();
        };
        virtual int Release(){
			return m_pParent->Release();
        };
        virtual bool QueryInterface(const char *InterfaceName, void **ppUnknown){  
            return m_pParent->QueryInterface(InterfaceName, ppUnknown);
        };
		virtual bool GetObjSystem( IObjectSystem** ppIObjSys ){
			return m_pParent->GetObjSystem( ppIObjSys );
		};
		virtual bool GetObjType( IObjectTypeInfo** ppType ){
			return m_pParent->GetObjType(ppType);
		};
		virtual bool GetCondition( QMap<QString,QVariant>& cond ){
			return m_pParent->GetCondition( cond );
		};
		virtual bool MatchCondition( const QMap<QString,QVariant>& cond ){
			return m_pParent->MatchCondition( cond );
		};
		virtual QString GetName(){
			return m_pParent->GetName();
		};
		virtual QString GetDesc(){
			return m_pParent->GetDesc();
		}
		virtual bool IsValid(){
			return m_pParent->IsValid();
		}
		virtual QImage GetIcon(){
			return m_pParent->GetIcon();
		};
		virtual bool SetProperty( const QString& name, const QVariant& val ){
			return m_pParent->SetProperty(name,val);
		};
		virtual bool GetProperty( const QString& name, QVariant& val ){
			return m_pParent->GetProperty(name,val);
		};
		virtual bool CallMethod( const QString& method, const QMap<QString,QVariant>& args, QVariant& res ){
			return m_pParent->CallMethod(method,args,res);
		};
		virtual bool RegSignalAnswer( IObjSignalAnswer* pIAnswer, bool bReg ){
			return m_pParent->RegSignalAnswer(pIAnswer,bReg);
		};
		virtual bool Update(){
			return m_pParent->Update();
		};
		virtual bool Commit(){
			return m_pParent->Commit();
		};
		virtual bool GetRelObjectEntity(const QString& rel, const QMap<QString,QVariant>& condition, IObjectEntity** ppObj){
			return m_pParent->GetRelObjectEntity( rel, condition, ppObj );
		};
		virtual bool GetRelObjectGroup(const QString& rel, const QMap<QString,QVariant>& condition, IObjectGroup** ppObjs){
			return m_pParent->GetRelObjectGroup( rel, condition, ppObjs );
		};
	}m_XObjEntity;
	friend class XObjectEntity;
	Q3PtrList<IObjSignalAnswer> m_signalAnswers;
};

#endif	//__OBJECTSYSTEM_COMMON_OBJECTENTITY_H_INCLUDED__