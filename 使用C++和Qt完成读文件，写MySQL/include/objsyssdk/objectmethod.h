#ifndef __OBJECT_SYSTEM_COMMON_OBJECTMETHOD_H_INCLUDED_
#define __OBJECT_SYSTEM_COMMON_OBJECTMETHOD_H_INCLUDED_

#include "iobjsystem.h"
#include "objsyscommexpdef.h"

#include "intfobject.h"
#include <q3dict.h>
#include <QStringList>

class OBJSYSCOMMON_CLASS ObjectMethodInfo : public CIntfObjectImpl
{
public:
	ObjectMethodInfo(IICSUnknown *pOuter = 0);
	ObjectMethodInfo(const QString& name, const QString& desc,
		IICSUnknown *pOuter = 0);
	~ObjectMethodInfo();
public:
	void SetNameAndDesc(const QString& name, const QString& desc );
	bool AddParameter( IObjPropertyInfo* pIPara );
	bool AddParameter( const QString& name, const QString& desc, int type );
protected:
	virtual bool ObjQueryInterface(const char *InterfaceName, void **ppV);
	virtual QString GetName();
	virtual QString GetDesc();
	virtual QStringList GetParameterNames();
	virtual bool	GetParameterInfo(const QString& name, IObjPropertyInfo** ppIPara);
private:
	class  XObjectMethodInfo : public IObjMethodInfo
	{
	public:
		ObjectMethodInfo* m_pParent;
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
		virtual QStringList GetParameterNames(){
			return m_pParent->GetParameterNames();
		};
		virtual bool GetParameterInfo(const QString& name, IObjPropertyInfo** ppIPara){
			return m_pParent->GetParameterInfo(name, ppIPara);
		};
	}m_XObjMthdInfo;
	friend class XObjectMethodInfo;
	QString m_name;
	QString m_desc;
	Q3Dict<IObjPropertyInfo> m_paras;
};


#endif	//__OBJECT_SYSTEM_COMMON_OBJECTPROPERTY_H_INCLUDED__