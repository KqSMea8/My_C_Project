#ifndef __OBJECT_SYSTEM_COMMON_OBJECTPROPERTY_H_INCLUDED__
#define __OBJECT_SYSTEM_COMMON_OBJECTPROPERTY_H_INCLUDED__

#include "iobjsystem.h"
#include "objsyscommexpdef.h"

#include "intfobject.h"
#include <QStringList>


class OBJSYSCOMMON_CLASS ObjectPropertyInfo : public CIntfObjectImpl
{
public:
	ObjectPropertyInfo(IICSUnknown *pOuter = 0);
	ObjectPropertyInfo(const QString& name, const QString& desc, int type,
		IICSUnknown *pOuter = 0);
	~ObjectPropertyInfo();
public:
	void SetType(int type);
	void SetNameAndDesc(const QString& name, const QString& desc );	
	void SetEnumKeys(const QMap<QString,QVariant>& keys);
	void AddEnumKeyValue( const QString& key, const QVariant& val );
	void RemoveEnumKeys();
protected:
	virtual bool ObjQueryInterface(const char *InterfaceName, void **ppV);
	virtual int GetType();
	virtual QString GetTypeName();
	virtual QString GetName();
	virtual QString GetDesc();
	virtual bool IsEnumType();
	virtual QStringList GetEnumKeys();
	virtual QVariant KeyToValue(const QString& key);
	virtual QString ValueToKey(const QVariant& val);
private:
	class  XObjectPropertyInfo : public IObjPropertyInfo
	{
	public:
		ObjectPropertyInfo* m_pParent;
		virtual int AddRef(){
            return m_pParent->AddRef();
        };
        virtual int Release(){
			return m_pParent->Release();
        };
        virtual bool QueryInterface(const char *InterfaceName, void **ppUnknown){  
            return m_pParent->QueryInterface(InterfaceName, ppUnknown);
        };
		virtual int GetType(){
			return m_pParent->GetType();
		};
		virtual QString GetTypeName(){
			return m_pParent->GetTypeName();
		};
		virtual QString GetName(){
			return m_pParent->GetName();
		};
		virtual QString GetDesc(){
			return m_pParent->GetDesc();
		};
		virtual bool IsEnumType(){
			return m_pParent->IsEnumType();
		};
		virtual QStringList GetEnumKeys(){
			return m_pParent->GetEnumKeys();
		};
		virtual QVariant KeyToValue(const QString& key){
			return m_pParent->KeyToValue(key);
		};
		virtual QString ValueToKey(const QVariant& val){
			return m_pParent->ValueToKey(val);
		};
	}m_XObjPropInfo;
	friend class XObjectPropertyInfo;
	int m_nType;
	QString m_strName;
	QString m_strDesc;
	QMap<QString,QVariant> m_enumKeys;
};


#endif	//__OBJECT_SYSTEM_COMMON_OBJECTPROPERTY_H_INCLUDED__