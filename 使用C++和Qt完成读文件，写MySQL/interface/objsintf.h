/*
**  �ļ�����ObjsIntf.h
**
**  ������ ҵ���߼�����ʵʱ����ʽӿ�
**
**
*/
#ifndef _OBJSINTF__H_
#define _OBJSINTF__H_
#include "typedef.h"
#include "generalintf.h"

// class IICSUnknown;
// class IICSStream;
// class IICSEnum;
// class IICSPersistStream;
class IICSTypeTree;
class IICSTypeInfo;
class IICSTypeField;
class IICSRtdbObject;
class ITaskObject;
class INetObject;
class IICSBufObject;

//����ӿ����Ƴ���
//#define IID_IICSEnum            "IICSEnum"
//#define IID_IICSStream          "IICSStream"
//#define IID_IICSPersistStream	"IICSPersistStream"
#define IID_IICSVisionObject	"IICSVisionObject"
#define IID_IICSTypeTree        "IICSTypeTree"
#define IID_IICSTypeInfo        "IICSTypeInfo"
#define IID_IICSTypeField       "IICSTypeField"
#define IID_IICSRtdbObject      "IICSRtdbObject"
#define IID_ITaskObject         "ITaskObject"
#define IID_INetObject          "INetObject"
#define IID_IUserObject         "IUserObject"
#define IID_INodeObject         "INodeObject"
#define IID_IICSBufObject		"IICSBufObject"
#define IID_IICSCommonObject	"IICSCommonObject"
#define IID_IScadaObject        "IScadaObject"
#define CLSID_IICSCommonObject	"IICSCommonObject"

//����������Ƴ���
#define CLSID_TaskTypeTree  "tasktypetree"
#define CLSID_NetTypeTree	"nettypetree"
#define CLSID_DBTypeTree	"dbtypetree"
#define CLSID_Analog        "analog"
#define CLSID_Control       "control"
#define CLSID_Pulse         "pulse"
#define CLSID_Status        "status"
#define CLSID_Setting		"setting"
#define CLSID_IED           "ied"
#define CLSID_Bay           "bay"
#define CLSID_Station       "station"
#define CLSID_BufAnalog		"bufanalog"
#define CLSID_BufStatus		"bufstatus"
#define CLSID_User          "user"
#define CLSID_Node          "node"
#define CLSID_Channel       "channel"
#define CLSID_ChannelGrp    "channelgrp"
//#define CLSID_ICSStream     "icsstream"
#define CLSID_BayState		"baystate"
#define CLSID_DynAnalog     "dynanalog"
#define CLSID_Equipment		"equipment"
//����һ���豸�������Ƴ���
#define CLSID_TSubStation	"station"
#define CLSID_TTransformer	"transformer"
#define CLSID_TWinding		"twinding"
#define CLSID_TVoltageLevel	"voltagelevel"
#define CLSID_TBay			"bay"
#define CLSID_TEquipBody	"tequipbody"
#define CLSID_TEquipment	"equipment"
#define CLSID_TMeasurand	"tmeasurand"
#define CLSID_TRelateIED	"ied"
#define CLSID_TIED			"ied"
#define CLSID_CentreNode	"centrenode"
#define CLSID_AnalogPara	"mxpara"
#define CLSID_Equipment     "equipment"

#define CLSID_AnalogTypeInfo        "analogtypeinfo"
#define CLSID_ControlTypeInfo       "controltypeinfo"
#define CLSID_PulseTypeInfo         "pulsetypeinfo"
#define CLSID_StatusTypeInfo        "statustypeinfo"
#define CLSID_SettingTypeInfo		"settingtypeinfo"
#define CLSID_IEDTypeInfo           "iedtypeinfo"
#define CLSID_BayTypeInfo           "baytypeinfo"
#define CLSID_StationTypeInfo       "stationtypeinfo"
#define CLSID_UserTypeInfo          "usertypeinfo"
#define CLSID_NodeTypeInfo          "nodetypeinfo"
#define CLSID_ChannelTypeInfo       "channeltypeinfo"
#define CLSID_ChannelGrpTypeInfo    "channelgrptypeinfo"
#define CLSID_EquipmentTypeInfo     "equipmenttypeinfo"

#define CLSID_Protect               "protectdesc"

/*
����ͼ��֧�ֽӿ�
*/
class IICSVisionObject : public IICSUnknown
{
public:
	//��ȡ���������ģ������
	virtual void GetModule(char* module, int size)=0;
	//��ȡ��ID
	virtual void GetClassID(char* clsid, int size)=0;
	//��ȡ����ID
	virtual int GetID()=0;
	//��ȡ��������
	virtual void GetName(char* name, int size)=0;
	//����ID����ͼ��֧�ֶ���
	virtual bool GetObjByID(int id, char* FieldFilter, IICSVisionObject** ppObj)=0;	
	//��ȡ������߼�����·��
	virtual void GetLogicalPath(char *cPath, int nSize)=0;
	//����������߼�����·����������
	virtual bool GetObjByPath(char* path, char* FieldFilter, IICSVisionObject** ppObj)=0;
public:
	static	char* GetIntfName(){return IID_IICSVisionObject;};	
};

/*
�������ӿ�
*/
class IICSTypeTree : public IICSUnknown
{
public:
    /*
        ����  �ܡ�      ��ȡ������������
        ����  ����      name[out]       ��ŷ��ص�����������
                        nSize           ��������С
        ������ֵ��      ��
    */
    virtual void GetName(char *name, int nSize)=0;

    /*
        ����  �ܡ�      ��ȡ���Ϳ�����
        ����  ����      name[out]       ��ŷ��ص�����������
						nSize           ��������С
        ������ֵ��      ��
    */
    virtual void GetCaption(char *caption, int nSize)=0;

    /*
        ����  �ܡ�      ��ȡ������(û�и����͵�����)ö�ٽӿ�
        ����  ����      ppEnum[out]     ��ŷ��ص�ö�ٽӿ�
        ������ֵ��      �����Ƿ�ɹ�
    */
    virtual bool GetRootType(IICSEnum **ppEnum)=0;

    /*
        ����  �ܡ�      ��ȡ��������ö�ٽӿ�
        ����  ����      ppEnum[out]     ��ŷ��ص�ö�ٽӿ�
        ������ֵ��      �����Ƿ�ɹ�
    */
    virtual bool GetAllType(IICSEnum **ppEnum)=0;
public:
    static char *GetIntfName()
    {
        return IID_IICSTypeTree;
    };
};

/*
������Ϣ���ʽӿ�
*/
class IICSTypeInfo : public IICSUnknown
{
public:
    /*
        ����  �ܡ�      ��ȡ���͵�����
        ����  ����      name[out]       ��ŷ��ص���������
                        nSize           ��������С
        ������ֵ��      ��
    */
    virtual void GetName(char *name, int nSize)=0;

    /*
        ����  �ܡ�      ��ȡ��������
        ����  ����      caption[out]    ��ŷ��ص���������
                        nSize                   ��������С
        ������ֵ��      ��
    */
    virtual void GetCaption(char *caption, int nSize)=0;

    /*
        ����  �ܡ�      ��ȡ�ֶ�ö�ٽӿ�
        ����  ����      ppEnum[out]     ��ŷ��ص�ö�ٽӿ�
                        nSize           ��������С
        ������ֵ��      ��
    */
    virtual void GetFields(IICSEnum **ppEnum)=0;

    /*
        ����  �ܡ�      ��ȡ�ؼ����ֶ�
        ����  ����      ppField[out]    ��Źؼ����ֶνӿ�       
        ������ֵ��      1��ʱ���ҳɹ�,0��ʾ����ʧ��
    */
    virtual bool GetKeyField(IICSTypeField **ppField)=0;

    /*
        ����  �ܡ�      ��������Ϊname�ֶ�
        ����  ����      name[in]        ���ҵ��ֶ�����
                        ppField[out]��Ų��ҵ��ֶεĽӿ�
        ������ֵ��      0��ʾδ�ҵ�1��ʾ���ҳɹ�
    */
    virtual bool FindField(char *name, IICSTypeField **ppField)=0;

    /*
        ����  �ܡ�      ��ȡ������ö�ٽӿ�
        ����  ����      ppEnum[out]     ���ö�ٽӿ�
        ������ֵ��      ���سɹ�ʧ��
    */
    virtual bool GetParentType(IICSEnum **ppEnum)=0;

    /*
        ����  �ܡ�      ��ȡ������ö�ٽӿ�
        ����  ����      ppEnum[out]     ���ö�ٽӿ�
        ������ֵ��      ���سɹ�ʧ��
    */
    virtual bool GetChildType(IICSEnum **ppEnum)=0;

	//added 
	virtual bool GetField(int index, IICSTypeField** ppField)=0;
public:
    static char * GetIntfName()
    {
        return IID_IICSTypeInfo;
    };
};

/*
���ԣ��ֶΣ���Ϣ���ʽӿ�
*/
class IICSTypeField : public IICSUnknown
{
public:
    /*
        ����  �ܡ�      ��ȡ�ֶ�����
        ����  ����      name[out]       ����ֶ����ƵĻ�����
                        nSize[in]       ��������С
        ������ֵ��      ��
    */
    virtual void GetName(char *name, int nSize)=0;

    /*
        ����  �ܡ�      ��ȡ�ֶ�����
        ����  ����      caption[out]    ����ֶ������Ļ�����
                        nSize[in]               ��������С
        ������ֵ��      ��
    */
    virtual void GetCaption(char *caption, int nSize)=0;

    /*
        ����  �ܡ�      ��ȡ�ֶ��������ͽӿ�
        ����  ����      ppTaskType[out] ����������ͽӿ�
        ������ֵ��      ��
    */
    virtual void GetOwnerType(IICSTypeInfo **ppTaskType)=0;

    /*
        ����  �ܡ�      ��ȡ�ֶ�����
        ����  ����      ��
        ������ֵ��      �����ֶ�����
    */
    virtual int GetFieldType()=0;

    /*
        ����  �ܡ�      �ж��ֶ��Ƿ�Ϊ�ؼ����ֶ�
        ����  ����      ��
        ������ֵ��      1Ϊ�ؼ���0Ϊ�ǹؼ���
    */
    virtual bool IsKey()=0;

    /*
        ����  �ܡ�      ��ȡ������ö�ٽӿ�
        ����  ����      ppEnum[out]     ���ö�ٽӿ�
        ������ֵ��      ���سɹ�ʧ��
    */
    virtual int GetDataSize()=0;

	virtual int GetIndex()=0;
	virtual bool IsRuntime()=0;
	virtual int GetSlot()=0;
	virtual void SetSlot(const int slot)=0;
	virtual void SetRuntime(bool bRuntime)=0;
public:
    static char * GetIntfName()
    {
        return IID_IICSTypeField;
    };
};

/*
ҵ�����ʵʱ����ʽӿڣ�ҵ�����ʵ�ָýӿ�
*/
class IICSRtdbObject : public IICSUnknown
{
public:
    /*
        ����  �ܡ�      ��ѯʵʱ�����
        ����  ����      sql             �򵥲�ѯ���
        ������ֵ��      ���سɹ�ʧ��
        ��˵  ����      1,sql = select *|prop1[,prop2]...[,propN]  [where condition1 [and condition2] ... [and conditionN]]
                        2,condition = prop >|<|=|<=|>= value (��һ��ֻʵ��=)
                        3,�����ַ���ֵӦ��''�ָ����ֿ�
                        4,����:select ID,Name where ID=1 Name='wxh-801'
                        5,����ֶβ����ڽ���ʧ��
    */
    virtual bool Open(char * sql)=0; 

    /*
        ����  �ܡ�      �ж����ݷ��ʼ�¼����û�д�
        ����  ����      ��
        ������ֵ��      ��
        ��˵  ����      1,����¼��û�д�ʱ����First,Next,Prev,Last��ʧ��    
    */
    virtual bool IsOpen()=0;

    /*
        ����  �ܡ�      ��ѯʵʱ�����
        ����  ����      FieldName       ��ѯ���������ֶ�
                        var             ��ѯ����������Ӧ���ֶ�ֵ����
        ������ֵ��      ���سɹ�ʧ��
        ��˵  ����      1,FieldName = *|prop1[,prop2] ... [,propN]
                        2,var Ϊvariant����
                        3,FieldFilter = *|prop1[,prop2]...[,propN]
                        4,����:Open("IEDName,IEDID", vararray, "IEDName,IEDID")
                        5,����ֶβ����ڽ���ʧ��
    */
    virtual bool Open(char *FieldName, variant *var, char *FieldFilter)=0;        

    /*
        ����  �ܡ�      ��ѯʵʱ�����
        ����  ����      sql             �򵥲�ѯ���
        ������ֵ��      ���سɹ�ʧ��
        ��˵  ����      1,sql = select *|prop1[,prop2]...[,propN]  [where condition1 [and condition2] ... [and conditionN]]
                        2,condition = prop >|<|=|<=|>= value (��һ��ֻʵ��=)
                        3,�����ַ���ֵӦ��''�ָ����ֿ�
                        4,����:select ID,Name where ID=1 Name='wxh-801'
                        5,����ֶβ����ڽ���ʧ��              
    */
    virtual bool QueryObjects(char * sql)=0;

    /*
        ����  �ܡ�      ��ѯʵʱ�����
        ����  ����      FieldName       ��ѯ���������ֶ�
                                var                     ��ѯ����������Ӧ���ֶ�ֵ����
        ������ֵ��      ���سɹ�ʧ��
        ��˵  ����      1,FieldName = *|prop1[,prop2] ... [,propN]
                        2,var Ϊvariant����
                        3,FieldFilter = *|prop1[,prop2]...[,propN]
                        4,����:Open("IEDName,IEDID", vararray, "IEDName,IEDID")
                        5,����ֶβ����ڽ���ʧ��                        
    */
    virtual bool QueryObjects(char *FieldName, variant *var, char *FieldFilter)=0; 

    /*
        ����  �ܡ�      ��ʵʱ���ݿ���ȡ������
        ����  ����      ��
        ��˵  ����      1,����¼��û�д�ʱ,���û�ʧ��
                        2,����¼��û�д�ʱ�Զ���,��λ����ǰ��¼�ٴ����ݿ���ȡ������

    */
    virtual bool UpdateFromRtdb()=0;

    /*
        ����  �ܡ�      �Ѷ����޸ĵ�����ˢ�µ�ʵʱ���ݿ���
        ����  ����      ��
        ��˵  ����      1,����¼��û�д�ʱ,���û�ʧ��
                        2,����¼��û�д�ʱ�Զ���,��λ����ǰ��¼�ٰ��޸ĵ�����ˢ�µ����ݿ���

    */
    virtual bool UpdateToRtdb()=0;

    /*
        ����  �ܡ�      �ƶ���ǰ��¼�����α�
        ����  ����      ��
        ������ֵ��      ���سɹ�ʧ��
        ��˵  ����      1,����¼��û�д�ʱ,���û�ʧ��
                        2,����¼��û�д�ʱ�Զ���,��λ����ǰ��¼�ٽ����ƶ��α�

    */
    virtual bool First()=0;
    virtual bool Last()=0;
    virtual bool Next()=0;
    virtual bool Prev()=0;

    /*
        ����  �ܡ�      �жϵ�ǰ��¼���Ƿ��ڿ�ʼ�Լ�����λ��
        ����  ����      ��
        ������ֵ��      �������
        ��˵  ����      1,����¼��û�д�ʱ,���ý����ʵ������
                        2,����λ�ñ�ʾ���һ����¼����һ�������¼
                        3,��ʼλ�ñ�ʾ��һ����¼֮ǰ�������¼
    */
    virtual bool IsEOF()=0; 
    virtual bool IsBOF()=0;

    /*
        ����  �ܡ�      ��ȡ/���ö����ֶ�
        ����  ����      ��
        ������ֵ��      ���سɹ�ʧ��
    */
    virtual bool GetFieldValueByIndex(int indx, variant *var)=0; 
    virtual bool GetFieldValueByName(char *FieldName, variant *var)=0;
    virtual bool SetFieldValueByIndex(int indx, variant *var)=0;
    virtual bool SetFieldValueByName(char *FieldName, variant *var)=0;

    /*
        ����  �ܡ�      ��ȡ������Ϣ
        ����  ����      ppTypeInfo[out]         ��ŷ��ص����ͽӿ�
        ������ֵ��      ���سɹ�ʧ��
    */
    virtual bool GetTypeInfo(IICSTypeInfo **ppTypeInfo)=0;

	//added on 2005-11-03
	virtual void GetFields(IICSEnum** pEnum)=0;
public:
    static char * GetIntfName()
    {
        return IID_IICSRtdbObject;
    };
};

#define IID_IICSRtdbObjectEx "ExIICSRtdbObject"

class IICSRtdbObjectEx : public IICSRtdbObject
{
public:
	virtual bool AsyncUpdateFromRtdb() = 0;
public:
    static char * GetIntfName()
    {
        return IID_IICSRtdbObjectEx;
    };
}; 

class IICSBufObject : public IICSRtdbObject
{
public:
	virtual bool GetFieldInfo(const char* FieldName, int* offset, FIELDTYPE* fieldtype, int* datasize) = 0;
	virtual bool GetFieldValueByOffset(int offset, FIELDTYPE type, int datasize, variant* var) = 0;
	virtual bool SetFieldValueByOffset(int offset, FIELDTYPE type, int datasize, variant* var) = 0;
public:
	static char * GetIntfName()
    {
        return IID_IICSBufObject;
    };
};

/*
ҵ�����ӿڣ�ҵ������������ʵ�ָýӿ�
*/
class ITaskObject : public IICSUnknown
{       
public:
    /*
        ����  �ܡ�      ��ȡҵ���������
        ����  ����      name[out]       ������ƵĻ�����
                        nSize[in]       ��������С
        ������ֵ��      ��
    */
    virtual void GetName(char *name, int size)=0;

    /*
        ����  �ܡ�      ����ҵ���������
        ����  ����      name[in]        ������ƻ�����
        ������ֵ��      ��
    */
    virtual void SetName(char *name)=0;

    /*
        ����  �ܡ�      ��ȡҵ�����ID
        ����  ����      ��
        ������ֵ��      ����ҵ�����ID
    */
    virtual int GetID()=0;

    /*
        ����  �ܡ�      ����ҵ�����ID��ʵʱ����װ�ض���
        ����  ����      ��
        ������ֵ��      ���سɹ�ʧ��
    */
    virtual bool LoadByID(int id)=0; 


    /*
        ����  �ܡ�      ����ҵ������path·����ȡҵ�����
        ����  ����      path[in]    ������ϸ·����ʽΪ:
                                    վ[.���[.װ��[.(ң��|ң��|ң��|ң��).������]]]
                        ppObj[out]  ����ҵ�����
        ������ֵ��      ���سɹ�ʧ��
    */
    virtual bool GetObjByPath(char* path, ITaskObject** ppObj)=0;

    /*
        ����  �ܡ�      ����ҵ�����ID��ʵʱ��������װ�ض���
        ����  ����      ��
        ������ֵ��      ���سɹ�ʧ��
    */
    virtual bool ReloadByID(int id)=0; 

    /*
        ����  �ܡ�      ��ȡҵ�����������������ӿ�[ע��:��ʱû��ʵ��]
        ����  ����      ppObj[out]      ��ŷ��ص��������ӿ�
        ������ֵ��      ���سɹ�ʧ��
    */
    virtual bool GetNetObject(INetObject **ppObj)=0; 

    /*
        ����  �ܡ�      ��ȡҵ�������߼���������(��ʽ��GetObjByPath)
        ����  ����      cPath[out]              ����߼���������������
                        nSize[in]               ��������С
        ������ֵ��      ���سɹ�ʧ��
    */
    virtual void GetLogicalPath(char *cPath, int nSize)=0;

    /*
        ����  �ܡ�      ��ȡҵ������������������(���磺վ.���.װ��.��)
        ����  ����      cPath[out]              ����߼���������������
                        nSize[in]               ��������С
        ������ֵ��      ���سɹ�ʧ��
    */
    virtual void GetNetPath(char *cPath, int nSize)=0; 

    /*
        ����  �ܡ�      ��ȡҵ�����ĸ�ҵ�����ӿ�
        ����  ����      ppObj[out]      ��Ÿ�ҵ�����ӿ�                                      
        ������ֵ��      ���سɹ�ʧ��
    */
    virtual bool GetParentObject(ITaskObject ** ppObj)=0; 

    /*
        ����  �ܡ�      ��ȡҵ��������ҵ�����ӿ�
        ����  ����      type[in]                        �Ӷ�������
                        ppObj[out]      ��Ÿ�ҵ�����ӿ�                                      
        ������ֵ��      ���سɹ�ʧ��
    */
    virtual bool GetChildObject(char *type, ITaskObject **ppObj)=0; 

    /*
        ����  �ܡ�      ��¡һ��ҵ�����
        ����  ����      ppObj[out]              ��ſ�¡��ҵ�����ӿ�                                  
        ������ֵ��      ���سɹ�ʧ��
    */
    virtual bool Clone(ITaskObject **ppObj)=0; 

    /*
        ����  �ܡ�      ����ϵ�л�ҵ�����
        ����  ����      bLoad[in]               0��ʾ�洢1��ʾװ��      
                        pStream[in,out] ���ӿ�                  
        ������ֵ��      ���سɹ�ʧ��
    */
    virtual bool LocalSerialize(bool bLoad, IICSStream *pStream)=0; 

    /*
        ����  �ܡ�      Զ��ϵ�л�ҵ�����
        ����  ����      bLoad[in]               0��ʾ�洢1��ʾװ��      
                        pStream[in,out] ���ӿ�                  
        ������ֵ��      ���سɹ�ʧ��
    */
    virtual bool RemoteSerialize(bool bLoad, IICSStream *pStream)=0;
	
	//��ȡ����·������·��
	virtual void GetNamePath(char* cPath, int nSize)=0;
	virtual void GetDescription(char* desc, int nSize)=0;
	virtual void SetDescription(const char* desc)=0;
public:
    static char *GetIntfName()
    {
        return IID_ITaskObject;
    };
};

//���屨����չ�ӿ�
#define IID_IExTaskObject "IExTaskObject"

class IExTaskObject : public ITaskObject
{
public:
	// ��ȡ����淶����
	virtual void GetStandPath(char* path, int size) = 0;
public:
	static char* GetIntfName() {return IID_IExTaskObject;};
};

/*
�������ӿڣ��������ʵ�ָýӿ�
*/
class INetObject : public IICSUnknown
{
public:
    /*
        ����  �ܡ�      ��ȡ�����������
        ����  ����      name[out]       ������ƵĻ�����
                        nSize[in]       ��������С
        ������ֵ��      ��
    */
    virtual void GetName(char *name, int size)=0;

    /*
        ����  �ܡ�      ���������������
        ����  ����      name[out]       ��Ŷ������ƵĻ�����
                        nSize[in]       ��������С
        ������ֵ��      ��
    */
    virtual void SetName(char *name)=0;

    /*
        ����  �ܡ�      ��ȡ����ID
        ����  ����      ��
        ������ֵ��      ��
    */
    virtual int GetID()=0;

    /*
        ����  �ܡ�      װ�ض���
        ����  ����      ��
        ������ֵ��      ���سɹ�ʧ��
    */
    virtual bool LoadByID(int id)=0;

    /*
        ����  �ܡ�      ����װ���������
        ����  ����      ��
        ������ֵ��      ���سɹ�ʧ��
    */
    virtual bool ReloadByID(int id)=0;

    /*
        ����  �ܡ�      �ж������Ƿ���ͨ
    */
    virtual bool IsConnect()=0;

    /*
        ����  �ܡ�      ��ȡ����·����ӿ�
        ����  ����      ppObjs[out]     ��Ÿ���·����ӿ�                                      
        ������ֵ��      ���سɹ�ʧ��
    */
    virtual bool GetParentNetObject(INetObject **ppObj)=0;

    /*
        ����  �ܡ�      ��ȡ����·����ӿ�
        ����  ����      ppObjs[out]     ��Ÿ�����·����ӿ�                                    
        ������ֵ��      ���سɹ�ʧ��
    */
    virtual bool GetChildNetObject(INetObject **ppObj)=0;

    /*
        ����  �ܡ�      ��¡һ���������
        ����  ����      ppObj[out]              ��ſ�¡���������ӿ�                                  
        ������ֵ��      ���سɹ�ʧ��
    */
    virtual bool Clone(INetObject **ppObj)=0;

    /*
        ����  �ܡ�      ����ϵ�л����������
        ����  ����      bLoad[in]               0��ʾ�洢1��ʾװ��      
                        pStream[in,out] ���ӿ�                  
        ������ֵ��      ���سɹ�ʧ��
    */
    virtual bool LocalSerialize(bool bLoad, IICSStream *pStream)=0;

    /*
        ����  �ܡ�      ����ϵ�л��������
        ����  ����      bLoad[in]               0��ʾ�洢1��ʾװ��      
                        pStream[in,out] ���ӿ�                  
        ������ֵ��      ���سɹ�ʧ��
    */
    virtual bool RemoteSerialize(bool bLoad, IICSStream *pStream)=0;
	virtual void GetLogicalPath(char *Path, int nSize)=0;
	virtual bool GetObjByPath(char* path, INetObject** ppObj)=0;
	virtual void GetNamePath(char* cPath, int nSize)=0;
	virtual void GetDescription(char* desc, int nSize)=0;
	virtual void SetDescription(const char* desc)=0;
public:     
    static char *GetIntfName()
    {
        return IID_INetObject;
    };
};


/*
�û��ӿ�
*/
class IUserObject : public IICSUnknown
{
public:
    virtual void GetName(char *name, int size)=0;
    virtual void SetName(char *name)=0;
    virtual int GetID()=0;
    virtual bool LoadByID(int id)=0;
    virtual bool ReloadByID(int id)=0;
    virtual bool GetPassword(char *pwd, int size)=0;
    virtual bool GetRight(int *right)=0;
    virtual bool Clone(IUserObject ** ppObj)=0;      
    virtual bool LocalSerialize(bool bLoad, IICSStream *pStream)=0;
    virtual bool RemoteSerialize(bool bLoad, IICSStream *pStream)=0;
	virtual void GetLogicalPath(char *Path, int nSize)=0;
	virtual bool GetObjByPath(char* path, IUserObject** ppObj)=0;
	virtual void GetNamePath(char* cPath, int nSize)=0;
	virtual void GetDescription(char* desc, int nSize)=0;
	virtual void SetDescription(const char* desc)=0;
public:
    static char *GetIntfName()
    {
        return IID_IUserObject;
    };
};

class IScadaObject : public IICSUnknown
{
public:
	    /*
        ����  �ܡ�      ��ȡҵ���������
        ����  ����      name[out]       ������ƵĻ�����
                        nSize[in]       ��������С
        ������ֵ��      ��
    */
    virtual void GetName(char *name, int size)=0;

    /*
        ����  �ܡ�      ����ҵ���������
        ����  ����      name[in]        ������ƻ�����
        ������ֵ��      ��
    */
    virtual void SetName(char *name)=0;

    /*
        ����  �ܡ�      ��ȡҵ�����ID
        ����  ����      ��
        ������ֵ��      ����ҵ�����ID
    */
	virtual int GetCount() = 0;
    virtual int GetID()=0;
	virtual void GetDescription(char* desc, int size)=0;
	virtual bool Clone(IScadaObject** ppScadaObject)=0;
	virtual bool NewObject(IICSRtdbObject **ppScadaObject)=0;
	virtual bool NewObject(IICSRtdbObject **ppScadaObject, char* tableName)=0;
	virtual bool GetChildObject(char* type, IICSRtdbObject** ppChildObj)=0;
	virtual int GetBrotherCount()=0;
	virtual bool GetParentObject(IICSRtdbObject **ppParentObj)=0;
	virtual bool Del() = 0;
	virtual bool DelChild(char* name)=0;
};


class ICommonObject : public IICSUnknown
{
public:
    virtual void GetName(char *name, int size)=0;
    virtual void SetName(char *name)=0;
    virtual int GetID()=0;
    virtual bool LoadByID(int id)=0;
    virtual bool ReloadByID(int id)=0;
    virtual bool GetParentObject(ICommonObject **ppObj)=0;
    virtual bool GetChildObject(ICommonObject **ppObj)=0;
    virtual bool Clone(ICommonObject **ppObj)=0;
    virtual bool LocalSerialize(bool bLoad, IICSStream *pStream)=0;
    virtual bool RemoteSerialize(bool bLoad, IICSStream *pStream)=0;
	virtual void GetLogicalPath(char *Path, int nSize)=0;
	virtual bool GetObjByPath(char* path, ICommonObject** ppObj)=0;
	virtual void GetNamePath(char* cPath, int nSize)=0;
	virtual void GetDescription(char* desc, int nSize)=0;
	virtual void SetDescription(const char* desc)=0;
public:     
    static char *GetIntfName()
    {
        return IID_IICSCommonObject;
    };
};

/*
�ڵ�ӿ�
*/
class INodeObject : public IICSUnknown
{
public:
    virtual void GetName(char *name, int size)=0;
    virtual void SetName(char *name)=0;
    virtual int GetID()=0;
    virtual int GetStatus()=0; 
    virtual bool LoadByID(int id)=0;
    virtual bool ReloadByID(int id)=0;
    virtual bool Clone(INodeObject **ppObj)=0;      
    virtual bool LocalSerialize(bool bLoad, IICSStream *pStream)=0;
    virtual bool RemoteSerialize(bool bLoad, IICSStream *pStream)=0; 
	virtual void GetLogicalPath(char *Path, int nSize)=0;
	virtual bool GetObjByPath(char* path, INodeObject** ppObj)=0;
	virtual void GetNamePath(char* cPath, int nSize)=0;
	virtual void GetDescription(char* desc, int nSize)=0;
	virtual void SetDescription(const char* desc)=0;
public:
    static char * GetIntfName()
    {
        return IID_INodeObject;
    }
};

//����ʵʱ��״̬֪ͨ�ӿ�
#define IID_IRTDBState	"IRTDBState"
class IRTDBState : public IICSUnknown
{
public:
	virtual void OnDBStateChanged(bool bState) = 0;
public:
    static char * GetIntfName()
    {
        return IID_IRTDBState;
    }
};

//����ע��ע��ʵʱ��״̬֪ͨ�������Ƽ�ԭ��
#define METHOD_REGRTDBSTATE		"RegRtdbState"
#define METHOD_UNREGRTDBSTATE	"UnRegRtdbState"
typedef void (*RegRtdbStateMethod)(IRTDBState* pRtdbState);
typedef void (*UnRegRtdbStateMethod)(IRTDBState* pRtdbState);

//����ģ������
#define MOUDLE_ICSTYPEINFO		"ICSTypeInfo"

/*
����ӿڵ�����ָ��
*/
//typedef CQIPtr<IICSEnum>			ICSEnum;
//typedef CQIPtr<IICSStream>			ICSStream;
//typedef CQIPtr<IICSPersistStream>	ICSPersistStream;
typedef CQIPtr<IICSVisionObject>	ICSVisionObject;
typedef CQIPtr<IICSTypeTree>		ICSTypeTree;
typedef CQIPtr<IICSTypeInfo>		ICSTypeInfo;
typedef CQIPtr<IICSTypeField>		ICSTypeField;
typedef CQIPtr<IICSTypeField>		ICSTypeField;
typedef CQIPtr<IICSRtdbObject>		ICSRtdbObject;
typedef CQIPtr<ITaskObject>			ICSTaskObject;
typedef CQIPtr<INetObject>			ICSNetObject;
typedef CQIPtr<IUserObject>			ICSUserObject;
typedef CQIPtr<INodeObject>			ICSNodeObject;

//���崴�������������Լ���������
typedef bool (*GetClassObjectMethod)(char *classname, IICSUnknown** ppUnk);
#define METHOD_GETCLASSOBJECT "GetClassObject"
#define METHOD_GETCACHEOBJECT "GetCacheObject"

//�������ģ������
#define MODULE_TASKOBJECTS	"ICSTaskObjects"
#define MODULE_NETOBJECTS	"ICSNetObjects" 
#define MODULE_DBOBJECTS	"ICSDBObjects"
#define MODULE_SCADAOBJECTS	"ICSScadaObjects"

#endif
