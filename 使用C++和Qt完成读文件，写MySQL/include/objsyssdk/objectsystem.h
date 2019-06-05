#ifndef __OBJECT_SYSTEM_COMMON_OBJECTSYSTEM_H_INCLUDED__
#define __OBJECT_SYSTEM_COMMON_OBJECTSYSTEM_H_INCLUDED__


#include "iobjsystem.h"
#include "objsyscommexpdef.h"

#include "intfobject.h"
#include "objectentity.h"

#include <qstringlist.h>
#include <q3dict.h>
#include <qimage.h>

class CBasicInfoImpl;
class ObjectSystemUI;
class ObjectTypeInfo;
class OBJSYSCOMMON_CLASS ObjectSystem : public ObjectEntity
{
public:
	ObjectSystem(IICSUnknown *pOuter = 0);
	~ObjectSystem();
public:
	bool AddTypeInfo(IObjectTypeInfo* pTypeInfo);
protected:
	virtual bool GetCondition( QMap<QString,QVariant>& cond );
	virtual bool SetProperty( const QString& name, const QVariant& val );
	virtual bool GetProperty( const QString& name, QVariant& val );
	virtual bool CallMethod( const QString& method, const QMap<QString,QVariant>& args, QVariant& res );
	virtual bool Update();
	virtual bool Commit();

	// original
	virtual bool ObjQueryInterface(const char *InterfaceName, void **ppV);
	//IObjSystem接口实现
	
	virtual QString GetName();
	virtual QString GetDesc();
	virtual bool IsValid() { return IsConnected(); }
	virtual void SetConfigInfo( const QString& name, const QString& desc,const QString& configFile );
	virtual QString GetConfigFile();


	virtual bool IsConnected() = 0;
	virtual bool Connect() = 0;
	virtual bool DisConnect() = 0;

	virtual QStringList GetAllTypes();
	virtual bool GetTypeInfo(const QString& type, IObjectTypeInfo** ppTypeInfo);

	virtual bool GetObjectEntity(const QString& type,const QMap<QString,QVariant>& condition, IObjectEntity** ppObj ) = 0;
	virtual bool GetObjectGroup( const QString& type,const QMap<QString,QVariant>& condition, IObjectGroup** ppObjs ) = 0;

	virtual bool GetRelObjectEntity(const QString& rel, const QMap<QString,QVariant>& condition, IObjectEntity** ppObj);
	virtual bool GetRelObjectGroup(const QString& rel, const QMap<QString,QVariant>& condition, IObjectGroup** ppObjs);
	
private:
	class  XObjectSystem : public IObjectSystem
	{
	public:
		ObjectSystem* m_pParent;
		virtual int AddRef()
        {
            return m_pParent->AddRef();
        };
        virtual int Release()
        {
			return m_pParent->Release();
        };
        virtual bool QueryInterface(const char *InterfaceName, void **ppUnknown)
        {  
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
			return m_pParent->GetObjectEntity(rel, condition, ppObj);
		};
		virtual bool GetRelObjectGroup(const QString& rel, const QMap<QString,QVariant>& condition, IObjectGroup** ppObjs){
			return m_pParent->GetObjectGroup(rel, condition, ppObjs);
		};
		virtual void SetConfigInfo( const QString& name, const QString& desc,const QString& configFile )
		{
			m_pParent->SetConfigInfo(name, desc, configFile);
		};
		virtual bool IsConnected()
        {  
            return m_pParent->IsConnected();
        };
		virtual bool Connect()
        {  
            return m_pParent->Connect();
        };
		virtual QString GetConfigFile()
		{
			return m_pParent->GetConfigFile();
		};
		virtual bool DisConnect()
        {  
            return m_pParent->DisConnect();
        };
		virtual QStringList GetAllTypes()
        {  
            return m_pParent->GetAllTypes();
        };
		virtual bool GetTypeInfo(const QString& type, IObjectTypeInfo** ppTypeInfo)
        {  
            return m_pParent->GetTypeInfo(type, ppTypeInfo);
        };
		virtual bool GetObjectEntity(const QString& type,const QMap<QString,QVariant>& condition, IObjectEntity** ppObj )
        {
            return m_pParent->GetObjectEntity(type,condition, ppObj);
        };
		virtual bool GetObjectGroup(const QString& type,const QMap<QString,QVariant>& condition, IObjectGroup** ppObjs )
        { 
            return m_pParent->GetObjectGroup(type,condition, ppObjs);
        };
	}m_XObjectSystem;
	friend class XObjectSystem;

	QString m_name;
	QString m_desc;
	QString m_configFile;

	Q3Dict<IObjectTypeInfo> m_types;
protected:
	ObjectTypeInfo* m_typeInfo;
};


#endif	//__OBJECT_SYSTEM_COMMON_OBJECTSYSTEM_H_INCLUDED__