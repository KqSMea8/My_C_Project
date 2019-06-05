#ifndef __OBJECT_SYSTEM_COMMON_OBJECTTYPEINFO_H_INCLUDED__
#define __OBJECT_SYSTEM_COMMON_OBJECTTYPEINFO_H_INCLUDED__


#include "iobjsystem.h"
#include "objsyscommexpdef.h"

#include "intfobject.h"

#include <q3dict.h>
#include <qimage.h>
#include <QStringList>

class RelationInfo;
class OBJSYSCOMMON_CLASS ObjectTypeInfo : public CIntfObjectImpl
{
public:
	ObjectTypeInfo(IObjectSystem* pObjSys, IICSUnknown *pOuter = 0);
	ObjectTypeInfo(const QString& name, const QString& desc, const QImage& icon,
		IObjectSystem* pObjSys, IICSUnknown *pOuter = 0);
	~ObjectTypeInfo();
public:
	void SetNameAndDesc(const QString& name, const QString& desc);
	void SetIcon(const QImage& icon);

	void AddPropToCond();
	bool AddCondition(const QString& name, const QString& desc, int type);	
	bool AddProperty(const QString& name, const QString& desc, int type);
	bool AddMethod(const QString& name, const QString& desc);
	bool AddSignal(const QString& name, const QString& desc);

	bool AddCondition(IObjPropertyInfo* pIProp);
	bool AddProperty(IObjPropertyInfo* pIProp);
	bool AddMethod(IObjMethodInfo* pIMthd);
	bool AddSignal(IObjSignalInfo* pISgnl);

	bool AddRelation( const QString& name, const QString& typeName, RelationType type, const QString& desc, const QIcon& icon );

	void InsertCustomData(const QString& key, const QVariant& data);

protected:
	virtual bool ObjQueryInterface(const char *InterfaceName, void **ppV);
	virtual QString GetName();
	virtual QString GetDesc();
	virtual QImage GetIcon();
	virtual QStringList GetConditionNames();
	virtual bool GetConditionInfo(const QString& name,IObjPropertyInfo** ppProperty);
	virtual QStringList GetPropertyNames();
	virtual bool GetPropertyInfo(const QString& name,IObjPropertyInfo** ppProperty);
	virtual QStringList GetMethodNames();
	virtual bool GetMethodInfo(const QString& name,IObjMethodInfo** ppMethod);
	virtual QStringList GetSignalNames();
	virtual bool GetSignalInfo(const QString& name,IObjSignalInfo** ppSignal);
	virtual QVariant GetCustomData(const QString& key);
	virtual QStringList GetRelations();
	virtual bool GetRelation( const QString& rel, QString& typeName, RelationType& type, QString& desc, QIcon& icon );
private:
	class  XObjectTypeInfo : public IObjectTypeInfo
	{
	public:
		ObjectTypeInfo* m_pParent;
		virtual int AddRef(){
            return m_pParent->AddRef();
        };
        virtual int Release(){
			return m_pParent->Release();
        };
        virtual bool QueryInterface(const char *InterfaceName, void **ppUnknown){  
            return m_pParent->QueryInterface(InterfaceName, ppUnknown);
        };
		virtual QString GetName(){
			return m_pParent->GetName();
		};
		virtual QString GetDesc(){
			return m_pParent->GetDesc();
		};
		virtual QImage GetIcon(){
			return m_pParent->GetIcon();
		};
		virtual QStringList GetConditionNames(){
			return m_pParent->GetConditionNames();
		};
		virtual bool GetConditionInfo(const QString& name,IObjPropertyInfo** ppProperty){
			return m_pParent->GetConditionInfo(name,ppProperty);
		};
		virtual QStringList GetPropertyNames(){
			return m_pParent->GetPropertyNames();
		};
		virtual bool GetPropertyInfo(const QString& name,IObjPropertyInfo** ppProperty){
			return m_pParent->GetPropertyInfo(name,ppProperty);
		};
		virtual QStringList GetMethodNames(){
			return m_pParent->GetMethodNames();
		};
		virtual bool GetMethodInfo(const QString& name,IObjMethodInfo** ppMethod){
			return m_pParent->GetMethodInfo(name,ppMethod);
		};
		virtual QStringList GetSignalNames(){
			return m_pParent->GetSignalNames();
		};
		virtual bool GetSignalInfo(const QString& name,IObjSignalInfo** ppSignal){
			return m_pParent->GetSignalInfo(name,ppSignal);
		};
		virtual QVariant GetCustomData(const QString& key){
			return m_pParent->GetCustomData( key );
		};
		virtual QStringList GetRelations()
		{
			return m_pParent->GetRelations();
		};
		virtual bool GetRelation( const QString& rel, QString& typeName, RelationType& type, QString& desc, QIcon& icon )
		{
			return m_pParent->GetRelation( rel, typeName, type, desc, icon );
		};
	}m_XObjTypeInfo;
	friend class XObjectTypeInfo;
	IObjectSystem* m_pIObjSys;
	QString m_strName;
	QString m_strDesc;
	QImage m_icon;

	QStringList m_propNames;
	QStringList m_conditionNames;
	Q3Dict<IObjPropertyInfo> m_conditions;
	Q3Dict<IObjPropertyInfo> m_props;
	Q3Dict<IObjMethodInfo> m_mthds;
	Q3Dict<IObjSignalInfo> m_sgnls;
	QMap<QString,RelationInfo*> m_relations;
	QMap<QString,QVariant> m_customData;
};


#endif	//__OBJECT_SYSTEM_COMMON_OBJECTTYPEINFO_H_INCLUDED__