/***************************************************************/
//	�� �� �� :iobjsystem.h
//	�ļ����� :
//	��    �� : tieliu
//	����ʱ�� : 2007��3��14��
//	��Ŀ���� ��ObjSysMgr
//	����ϵͳ : 
//	��    ע :
//	��ʷ��¼�� : 
/***************************************************************/
#ifndef __OBJECTSYSTEM_IOBJSYSTEM_H_INCLUDED__
#define __OBJECTSYSTEM_IOBJSYSTEM_H_INCLUDED__

#include "icsunknown.h"
#include "qiptr.h"

#include <qstring.h>
#include <qmap.h>
#include <qvariant.h>
#include <QList>
#include <QIcon>

#define IID_IObjSystem			"IObjectSystem"
#define IID_IObjSystemUI		"IObjectSystemUI"

#define IID_IObjGroup			"IObjGroup"
#define IID_IObjEntity			"IObjEntity"
#define IID_IObjTypeInfo		"IObjPropertyInfo"
#define IID_IObjPropertyInfo	"IObjPropertyInfo"
#define IID_IObjMethodInfo		"IObjMethodInfo"
#define IID_IObjSignalInfo		"IObjSignalInfo"
#define IID_IObjSignalAnswer	"IObjSignalAnswer"

#define CLSID_ObjSystem			"CLSID_ObjSystem"
#define CLSID_ObjSystemUI		"CLSID_ObjSystemUI"

typedef enum
{
	RL_1_1,
	RL_1_N,
	RL_N_N,
	RL_N_1
}RelationType;

class IObjectSystem;
class IObjectEntity;
class IObjectGroup;
/*
 *	������ϵ�˻����湦�ܽӿ�
 */
class IObjectSystemUI : public IICSUnknown
{
public:
	//�˻���������
	virtual QWidget* CreateCustomView(IObjectSystem* ios, QWidget* parent) = 0;
	virtual bool SelectedInCustomView(IObjectSystem* ios, QWidget* customView, IObjectEntity** ppIObj ) = 0;
	virtual bool SelectedInCustomView(IObjectSystem* ios, QWidget* customView, QList<IICSUnknown*>& list) = 0;
	virtual bool Setup(IObjectSystem*) = 0;
public:
    //���������������ָ��ģ����
    static char* GetIntfName()
    {
        return IID_IObjSystemUI;
    }; 
};

//������Ϣ�ӿ�
class IObjPropertyInfo;
class IObjMethodInfo : public IICSUnknown
{
public:
	virtual QString GetName() = 0;
	virtual QString GetDesc() = 0;
	virtual QStringList GetParameterNames() = 0;
	virtual bool GetParameterInfo(const QString& name, IObjPropertyInfo** ppIProp) = 0;
public:
    //���������������ָ��ģ����
    static char* GetIntfName()
    {
        return IID_IObjMethodInfo;
    };
};

//����/������Ϣ�ӿ�
class IObjPropertyInfo : public IICSUnknown
{
public:
	virtual int GetType() = 0;
	virtual QString GetTypeName() = 0;
	virtual QString GetName() = 0;
	virtual QString GetDesc() = 0;
	virtual bool IsEnumType() = 0;
	virtual QStringList GetEnumKeys() = 0;
	virtual QVariant KeyToValue(const QString& key) = 0;
	virtual QString ValueToKey(const QVariant& val) = 0;
public:
    //���������������ָ��ģ����
    static char* GetIntfName()
    {
        return IID_IObjPropertyInfo;
    }; 

};

//�ź���Ϣ�ӿ�
class IObjSignalInfo : public IICSUnknown
{
public:
	virtual QString GetName() = 0;
	virtual QString GetDesc() = 0;
	virtual QStringList GetParameterNames() = 0;
	virtual bool	GetParameterInfo(const QString& name, IObjPropertyInfo** ppIProp) = 0;
public:
    //���������������ָ��ģ����
    static char* GetIntfName()
    {
        return IID_IObjSignalInfo;
    }; 
};

//�ź���Ӧ�ͻ��˻ص��ӿ�
class IObjSignalAnswer : public IICSUnknown
{
public:
	virtual void OnObjSignal( const QString& signal, const QMap<QString,QVariant>& args ) = 0;
public:
    //���������������ָ��ģ����
    static char* GetIntfName()
    {
        return IID_IObjSignalAnswer;
    }; 
};

//������Ϣ�ӿ�
class IObjectTypeInfo : public IICSUnknown
{
public:
	virtual QString GetName() = 0;
	virtual QString GetDesc() = 0;
	virtual QImage GetIcon() = 0;
	virtual QStringList GetPropertyNames() = 0;
	virtual bool GetPropertyInfo(const QString& name,IObjPropertyInfo** ppProperty) = 0;
	virtual QStringList GetConditionNames() = 0;
	virtual bool GetConditionInfo(const QString& name,IObjPropertyInfo** ppProperty) = 0;
	virtual QStringList GetMethodNames() = 0;
	virtual bool GetMethodInfo(const QString& name,IObjMethodInfo** ppProperty) = 0;
	virtual QStringList GetSignalNames() = 0;
	virtual bool GetSignalInfo(const QString& name,IObjSignalInfo** ppProperty) = 0;
	virtual QStringList GetRelations() = 0;
	virtual bool GetRelation( const QString& rel, QString& typeName, RelationType& type, QString& desc, QIcon& icon ) = 0;
	virtual QVariant GetCustomData( const QString& Key ) = 0;
public:
    //���������������ָ��ģ����
    static char* GetIntfName()
    {
        return IID_IObjTypeInfo;
    }; 
};


//����ʵ��ӿ�
class IObjectSystem;
class IObjectEntity : public IICSUnknown
{
public:
	virtual bool GetObjSystem( IObjectSystem** ppIObjSys ) = 0;
	virtual bool GetObjType( IObjectTypeInfo** ppType ) = 0;
	virtual bool GetCondition( QMap<QString,QVariant>& cond ) = 0;
	virtual bool MatchCondition( const QMap<QString,QVariant>& cond ) = 0;
	virtual QString GetName() = 0;
	virtual QString GetDesc() = 0;
	virtual bool IsValid() = 0;
	virtual QImage GetIcon() = 0;
	virtual bool SetProperty( const QString& name, const QVariant& val ) = 0;
	virtual bool GetProperty( const QString& name, QVariant& val ) = 0;
	virtual bool CallMethod( const QString& method, const QMap<QString,QVariant>& args, QVariant& res ) = 0;
	virtual bool RegSignalAnswer( IObjSignalAnswer* pIAnswer, bool bReg ) = 0;

	virtual bool Update() = 0;
	virtual bool Commit() = 0;

	virtual bool GetRelObjectEntity(const QString& rel, const QMap<QString,QVariant>& condition, IObjectEntity** ppIObj ) = 0;
	virtual bool GetRelObjectGroup(const QString& rel, const QMap<QString,QVariant>& condition, IObjectGroup** ppIObjs ) = 0;
public:
    //���������������ָ��ģ����
    static char* GetIntfName()
    {
        return IID_IObjEntity;
    }; 
};


/*
 *	������ϵ�ӿ�
 */
class IObjectSystem : public IObjectEntity
{
public:
	virtual void	SetConfigInfo( const QString& name, const QString& desc,const QString& configFile ) = 0;
	virtual QString	GetConfigFile() = 0;

	//����
	virtual bool	IsConnected() = 0;
	virtual bool	Connect() = 0;
	virtual bool	DisConnect() = 0;

	//���Ͳ�ѯ
	virtual QStringList GetAllTypes() = 0;
	virtual bool GetTypeInfo(const QString& type, IObjectTypeInfo** ppTypeInfo) = 0;

	//���󼯺�/����/���Բ�ѯ
	virtual bool GetObjectEntity(const QString& type, const QMap<QString,QVariant>& condition, IObjectEntity** ppObj ) = 0;
	virtual bool GetObjectGroup( const QString& type, const QMap<QString,QVariant>& condition, IObjectGroup** ppObjs ) = 0;
public:
    //���������������ָ��ģ����
    static char* GetIntfName()
    {
        return IID_IObjSystem;
    }; 
};

//���󼯺Ͻӿ�
class IObjectGroup : public IICSUnknown
{
public:
	virtual bool GetObjSystem( IObjectSystem** ppIObjSys ) = 0;
	virtual bool GetObjType( IObjectTypeInfo** ppType ) = 0;
	virtual int GetObjCount() = 0;
	virtual bool GetObjEntity(int index, IObjectEntity** ppObj ) = 0;
	IObjectEntity* GetObjEntity(int index);
public:
    //���������������ָ��ģ����
    static char* GetIntfName()
    {
        return IID_IObjGroup;
    }; 
};

//��������ָ��

typedef CQIPtr<IObjectSystem>		IObjectSystemCQIPtr;
typedef CQIPtr<IObjectSystemUI>		IObjectSystemUICQIPtr;
typedef CQIPtr<IObjectTypeInfo>		IObjectTypeInfoCQIPtr;
typedef CQIPtr<IObjPropertyInfo>	IObjPropertyInfoCQIPtr;
typedef CQIPtr<IObjMethodInfo>		IObjMethodInfoCQIPtr;
typedef CQIPtr<IObjSignalInfo>		IObjSignalInfoCQIPtr;
typedef CQIPtr<IObjSignalAnswer>	IObjSignalAnswerCQIPtr;
typedef CQIPtr<IObjectEntity>		IObjectEntityCQIPtr;
typedef CQIPtr<IObjectGroup>		IObjectGroupCQIPtr;

#ifdef _MSC_VER
#define OBJSYSTEM_MODULE_API __declspec(dllexport)
#else
#define OBJSYSTEM_MODULE_API 
#endif

extern "C"
{
	bool OBJSYSTEM_MODULE_API GetClassObject(char* clsid, IICSUnknown** ppUnk);
}


#endif	//__OBJECTSYSTEM_IOBJSYSTEM_H_INCLUDED__