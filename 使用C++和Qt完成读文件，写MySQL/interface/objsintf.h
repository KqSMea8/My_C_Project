/*
**  文件名：ObjsIntf.h
**
**  描述： 业务逻辑对象实时库访问接口
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

//定义接口名称常量
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

//定义对象名称常量
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
//定义一次设备对象名称常量
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
定义图形支持接口
*/
class IICSVisionObject : public IICSUnknown
{
public:
	//获取创建对象的模块名称
	virtual void GetModule(char* module, int size)=0;
	//获取类ID
	virtual void GetClassID(char* clsid, int size)=0;
	//获取对象ID
	virtual int GetID()=0;
	//获取对象名称
	virtual void GetName(char* name, int size)=0;
	//根据ID创建图形支持对象
	virtual bool GetObjByID(int id, char* FieldFilter, IICSVisionObject** ppObj)=0;	
	//获取对象的逻辑名称路径
	virtual void GetLogicalPath(char *cPath, int nSize)=0;
	//根军对象的逻辑名称路径创建对象
	virtual bool GetObjByPath(char* path, char* FieldFilter, IICSVisionObject** ppObj)=0;
public:
	static	char* GetIntfName(){return IID_IICSVisionObject;};	
};

/*
类型树接口
*/
class IICSTypeTree : public IICSUnknown
{
public:
    /*
        【功  能】      获取类型树的名称
        【参  数】      name[out]       存放返回的类型树名称
                        nSize           缓冲区大小
        【返回值】      无
    */
    virtual void GetName(char *name, int nSize)=0;

    /*
        【功  能】      获取类型库描述
        【参  数】      name[out]       存放返回的类型树描述
						nSize           缓冲区大小
        【返回值】      无
    */
    virtual void GetCaption(char *caption, int nSize)=0;

    /*
        【功  能】      获取根类型(没有父类型的类型)枚举接口
        【参  数】      ppEnum[out]     存放返回的枚举接口
        【返回值】      返回是否成功
    */
    virtual bool GetRootType(IICSEnum **ppEnum)=0;

    /*
        【功  能】      获取所有类型枚举接口
        【参  数】      ppEnum[out]     存放返回的枚举接口
        【返回值】      返回是否成功
    */
    virtual bool GetAllType(IICSEnum **ppEnum)=0;
public:
    static char *GetIntfName()
    {
        return IID_IICSTypeTree;
    };
};

/*
类型信息访问接口
*/
class IICSTypeInfo : public IICSUnknown
{
public:
    /*
        【功  能】      获取类型的名称
        【参  数】      name[out]       存放返回的类型名称
                        nSize           缓冲区大小
        【返回值】      无
    */
    virtual void GetName(char *name, int nSize)=0;

    /*
        【功  能】      获取类型描述
        【参  数】      caption[out]    存放返回的类型描述
                        nSize                   缓冲区大小
        【返回值】      无
    */
    virtual void GetCaption(char *caption, int nSize)=0;

    /*
        【功  能】      获取字段枚举接口
        【参  数】      ppEnum[out]     存放返回的枚举接口
                        nSize           缓冲区大小
        【返回值】      无
    */
    virtual void GetFields(IICSEnum **ppEnum)=0;

    /*
        【功  能】      获取关键字字段
        【参  数】      ppField[out]    存放关键字字段接口       
        【返回值】      1表时查找成功,0表示查找失败
    */
    virtual bool GetKeyField(IICSTypeField **ppField)=0;

    /*
        【功  能】      查找名称为name字段
        【参  数】      name[in]        查找的字段名称
                        ppField[out]存放查找的字段的接口
        【返回值】      0表示未找到1表示查找成功
    */
    virtual bool FindField(char *name, IICSTypeField **ppField)=0;

    /*
        【功  能】      获取父类型枚举接口
        【参  数】      ppEnum[out]     存放枚举接口
        【返回值】      返回成功失败
    */
    virtual bool GetParentType(IICSEnum **ppEnum)=0;

    /*
        【功  能】      获取子类型枚举接口
        【参  数】      ppEnum[out]     存放枚举接口
        【返回值】      返回成功失败
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
属性（字段）信息访问接口
*/
class IICSTypeField : public IICSUnknown
{
public:
    /*
        【功  能】      获取字段名称
        【参  数】      name[out]       存放字段名称的缓冲区
                        nSize[in]       缓冲区大小
        【返回值】      无
    */
    virtual void GetName(char *name, int nSize)=0;

    /*
        【功  能】      获取字段描述
        【参  数】      caption[out]    存放字段描述的缓冲区
                        nSize[in]               缓冲区大小
        【返回值】      无
    */
    virtual void GetCaption(char *caption, int nSize)=0;

    /*
        【功  能】      获取字段所属类型接口
        【参  数】      ppTaskType[out] 存放所属类型接口
        【返回值】      无
    */
    virtual void GetOwnerType(IICSTypeInfo **ppTaskType)=0;

    /*
        【功  能】      获取字段类型
        【参  数】      无
        【返回值】      返回字段类型
    */
    virtual int GetFieldType()=0;

    /*
        【功  能】      判断字段是否为关键字字段
        【参  数】      无
        【返回值】      1为关键字0为非关键字
    */
    virtual bool IsKey()=0;

    /*
        【功  能】      获取子类型枚举接口
        【参  数】      ppEnum[out]     存放枚举接口
        【返回值】      返回成功失败
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
业务对象实时库访问接口，业务对象都实现该接口
*/
class IICSRtdbObject : public IICSUnknown
{
public:
    /*
        【功  能】      查询实时库对象
        【参  数】      sql             简单查询语句
        【返回值】      返回成功失败
        【说  明】      1,sql = select *|prop1[,prop2]...[,propN]  [where condition1 [and condition2] ... [and conditionN]]
                        2,condition = prop >|<|=|<=|>= value (第一步只实现=)
                        3,对于字符串值应以''分隔符分开
                        4,例如:select ID,Name where ID=1 Name='wxh-801'
                        5,如果字段不存在将会失败
    */
    virtual bool Open(char * sql)=0; 

    /*
        【功  能】      判断数据访问记录集有没有打开
        【参  数】      无
        【返回值】      略
        【说  明】      1,当记录集没有打开时调用First,Next,Prev,Last会失败    
    */
    virtual bool IsOpen()=0;

    /*
        【功  能】      查询实时库对象
        【参  数】      FieldName       查询过滤条件字段
                        var             查询过滤条件对应的字段值数组
        【返回值】      返回成功失败
        【说  明】      1,FieldName = *|prop1[,prop2] ... [,propN]
                        2,var 为variant数组
                        3,FieldFilter = *|prop1[,prop2]...[,propN]
                        4,例如:Open("IEDName,IEDID", vararray, "IEDName,IEDID")
                        5,如果字段不存在将会失败
    */
    virtual bool Open(char *FieldName, variant *var, char *FieldFilter)=0;        

    /*
        【功  能】      查询实时库对象
        【参  数】      sql             简单查询语句
        【返回值】      返回成功失败
        【说  明】      1,sql = select *|prop1[,prop2]...[,propN]  [where condition1 [and condition2] ... [and conditionN]]
                        2,condition = prop >|<|=|<=|>= value (第一步只实现=)
                        3,对于字符串值应以''分隔符分开
                        4,例如:select ID,Name where ID=1 Name='wxh-801'
                        5,如果字段不存在将会失败              
    */
    virtual bool QueryObjects(char * sql)=0;

    /*
        【功  能】      查询实时库对象
        【参  数】      FieldName       查询过滤条件字段
                                var                     查询过滤条件对应的字段值数组
        【返回值】      返回成功失败
        【说  明】      1,FieldName = *|prop1[,prop2] ... [,propN]
                        2,var 为variant数组
                        3,FieldFilter = *|prop1[,prop2]...[,propN]
                        4,例如:Open("IEDName,IEDID", vararray, "IEDName,IEDID")
                        5,如果字段不存在将会失败                        
    */
    virtual bool QueryObjects(char *FieldName, variant *var, char *FieldFilter)=0; 

    /*
        【功  能】      从实时数据库中取出数据
        【参  数】      无
        【说  明】      1,当记录集没有打开时,调用会失败
                        2,当记录集没有打开时自动开,定位到当前记录再从数据库中取出数据

    */
    virtual bool UpdateFromRtdb()=0;

    /*
        【功  能】      把对象修改的数据刷新到实时数据库中
        【参  数】      无
        【说  明】      1,当记录集没有打开时,调用会失败
                        2,当记录集没有打开时自动开,定位到当前记录再把修改的数据刷新到数据库中

    */
    virtual bool UpdateToRtdb()=0;

    /*
        【功  能】      移动当前记录集的游标
        【参  数】      无
        【返回值】      返回成功失败
        【说  明】      1,当记录集没有打开时,调用会失败
                        2,当记录集没有打开时自动开,定位到当前记录再进行移动游标

    */
    virtual bool First()=0;
    virtual bool Last()=0;
    virtual bool Next()=0;
    virtual bool Prev()=0;

    /*
        【功  能】      判断当前记录集是否处于开始以及结束位置
        【参  数】      无
        【返回值】      返回真假
        【说  明】      1,当记录集没有打开时,调用结果无实际意义
                        2,结束位置表示最后一条记录的下一条虚拟记录
                        3,开始位置表示第一条记录之前的虚拟记录
    */
    virtual bool IsEOF()=0; 
    virtual bool IsBOF()=0;

    /*
        【功  能】      获取/设置对象字段
        【参  数】      无
        【返回值】      返回成功失败
    */
    virtual bool GetFieldValueByIndex(int indx, variant *var)=0; 
    virtual bool GetFieldValueByName(char *FieldName, variant *var)=0;
    virtual bool SetFieldValueByIndex(int indx, variant *var)=0;
    virtual bool SetFieldValueByName(char *FieldName, variant *var)=0;

    /*
        【功  能】      获取类型信息
        【参  数】      ppTypeInfo[out]         存放返回的类型接口
        【返回值】      返回成功失败
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
业务对象接口，业务对象网络对象都实现该接口
*/
class ITaskObject : public IICSUnknown
{       
public:
    /*
        【功  能】      获取业务对象名称
        【参  数】      name[out]       存放名称的缓冲区
                        nSize[in]       缓冲区大小
        【返回值】      无
    */
    virtual void GetName(char *name, int size)=0;

    /*
        【功  能】      设置业务对象名称
        【参  数】      name[in]        存放名称缓冲区
        【返回值】      无
    */
    virtual void SetName(char *name)=0;

    /*
        【功  能】      获取业务对象ID
        【参  数】      无
        【返回值】      返回业务对象ID
    */
    virtual int GetID()=0;

    /*
        【功  能】      根据业务对象ID从实时库中装载对象
        【参  数】      无
        【返回值】      返回成功失败
    */
    virtual bool LoadByID(int id)=0; 


    /*
        【功  能】      根据业务对象的path路径获取业务对象
        【参  数】      path[in]    对象详细路径格式为:
                                    站[.间隔[.装置[.(遥测|遥信|遥控|遥脉).点名称]]]
                        ppObj[out]  返回业务对象
        【返回值】      返回成功失败
    */
    virtual bool GetObjByPath(char* path, ITaskObject** ppObj)=0;

    /*
        【功  能】      根据业务对象ID从实时库中重新装载对象
        【参  数】      无
        【返回值】      返回成功失败
    */
    virtual bool ReloadByID(int id)=0; 

    /*
        【功  能】      获取业务对象关联的网络对象接口[注意:暂时没有实现]
        【参  数】      ppObj[out]      存放返回的网络对象接口
        【返回值】      返回成功失败
    */
    virtual bool GetNetObject(INetObject **ppObj)=0; 

    /*
        【功  能】      获取业务对象的逻辑名称描述(格式见GetObjByPath)
        【参  数】      cPath[out]              存放逻辑名称描述缓冲区
                        nSize[in]               缓冲区大小
        【返回值】      返回成功失败
    */
    virtual void GetLogicalPath(char *cPath, int nSize)=0;

    /*
        【功  能】      获取业务对象的网络名称描述(例如：站.间隔.装置.点)
        【参  数】      cPath[out]              存放逻辑名称描述缓冲区
                        nSize[in]               缓冲区大小
        【返回值】      返回成功失败
    */
    virtual void GetNetPath(char *cPath, int nSize)=0; 

    /*
        【功  能】      获取业务对象的父业务对象接口
        【参  数】      ppObj[out]      存放父业务对象接口                                      
        【返回值】      返回成功失败
    */
    virtual bool GetParentObject(ITaskObject ** ppObj)=0; 

    /*
        【功  能】      获取业务对象的子业务对象接口
        【参  数】      type[in]                        子对象类型
                        ppObj[out]      存放父业务对象接口                                      
        【返回值】      返回成功失败
    */
    virtual bool GetChildObject(char *type, ITaskObject **ppObj)=0; 

    /*
        【功  能】      克隆一个业务对象
        【参  数】      ppObj[out]              存放克隆的业务对象接口                                  
        【返回值】      返回成功失败
    */
    virtual bool Clone(ITaskObject **ppObj)=0; 

    /*
        【功  能】      本地系列化业务对象
        【参  数】      bLoad[in]               0表示存储1表示装载      
                        pStream[in,out] 流接口                  
        【返回值】      返回成功失败
    */
    virtual bool LocalSerialize(bool bLoad, IICSStream *pStream)=0; 

    /*
        【功  能】      远程系列化业务对象
        【参  数】      bLoad[in]               0表示存储1表示装载      
                        pStream[in,out] 流接口                  
        【返回值】      返回成功失败
    */
    virtual bool RemoteSerialize(bool bLoad, IICSStream *pStream)=0;
	
	//获取名称路径即短路径
	virtual void GetNamePath(char* cPath, int nSize)=0;
	virtual void GetDescription(char* desc, int nSize)=0;
	virtual void SetDescription(const char* desc)=0;
public:
    static char *GetIntfName()
    {
        return IID_ITaskObject;
    };
};

//定义报警扩展接口
#define IID_IExTaskObject "IExTaskObject"

class IExTaskObject : public ITaskObject
{
public:
	// 获取对象规范命名
	virtual void GetStandPath(char* path, int size) = 0;
public:
	static char* GetIntfName() {return IID_IExTaskObject;};
};

/*
网络对象接口，网络对象都实现该接口
*/
class INetObject : public IICSUnknown
{
public:
    /*
        【功  能】      获取网络对象名称
        【参  数】      name[out]       存放明称的缓冲区
                        nSize[in]       缓冲区大小
        【返回值】      无
    */
    virtual void GetName(char *name, int size)=0;

    /*
        【功  能】      设置网络对象名称
        【参  数】      name[out]       存放对象名称的缓冲区
                        nSize[in]       缓冲区大小
        【返回值】      无
    */
    virtual void SetName(char *name)=0;

    /*
        【功  能】      获取对象ID
        【参  数】      无
        【返回值】      略
    */
    virtual int GetID()=0;

    /*
        【功  能】      装载对象
        【参  数】      略
        【返回值】      返回成功失败
    */
    virtual bool LoadByID(int id)=0;

    /*
        【功  能】      重新装载网络对象
        【参  数】      略
        【返回值】      返回成功失败
    */
    virtual bool ReloadByID(int id)=0;

    /*
        【功  能】      判断网络是否连通
    */
    virtual bool IsConnect()=0;

    /*
        【功  能】      获取父网路对象接口
        【参  数】      ppObjs[out]     存放父网路对象接口                                      
        【返回值】      返回成功失败
    */
    virtual bool GetParentNetObject(INetObject **ppObj)=0;

    /*
        【功  能】      获取子网路对象接口
        【参  数】      ppObjs[out]     存放父子网路对象接口                                    
        【返回值】      返回成功失败
    */
    virtual bool GetChildNetObject(INetObject **ppObj)=0;

    /*
        【功  能】      克隆一个网络对象
        【参  数】      ppObj[out]              存放克隆的网络对象接口                                  
        【返回值】      返回成功失败
    */
    virtual bool Clone(INetObject **ppObj)=0;

    /*
        【功  能】      本地系列化网络对象象
        【参  数】      bLoad[in]               0表示存储1表示装载      
                        pStream[in,out] 流接口                  
        【返回值】      返回成功失败
    */
    virtual bool LocalSerialize(bool bLoad, IICSStream *pStream)=0;

    /*
        【功  能】      本地系列化网络对象
        【参  数】      bLoad[in]               0表示存储1表示装载      
                        pStream[in,out] 流接口                  
        【返回值】      返回成功失败
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
用户接口
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
        【功  能】      获取业务对象名称
        【参  数】      name[out]       存放名称的缓冲区
                        nSize[in]       缓冲区大小
        【返回值】      无
    */
    virtual void GetName(char *name, int size)=0;

    /*
        【功  能】      设置业务对象名称
        【参  数】      name[in]        存放名称缓冲区
        【返回值】      无
    */
    virtual void SetName(char *name)=0;

    /*
        【功  能】      获取业务对象ID
        【参  数】      无
        【返回值】      返回业务对象ID
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
节点接口
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

//定义实时库状态通知接口
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

//定义注册注销实时库状态通知函数名称及原型
#define METHOD_REGRTDBSTATE		"RegRtdbState"
#define METHOD_UNREGRTDBSTATE	"UnRegRtdbState"
typedef void (*RegRtdbStateMethod)(IRTDBState* pRtdbState);
typedef void (*UnRegRtdbStateMethod)(IRTDBState* pRtdbState);

//定义模块名称
#define MOUDLE_ICSTYPEINFO		"ICSTypeInfo"

/*
定义接口的智能指针
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

//定义创建对象函数类型以及函数名称
typedef bool (*GetClassObjectMethod)(char *classname, IICSUnknown** ppUnk);
#define METHOD_GETCLASSOBJECT "GetClassObject"
#define METHOD_GETCACHEOBJECT "GetCacheObject"

//定义对象模块名称
#define MODULE_TASKOBJECTS	"ICSTaskObjects"
#define MODULE_NETOBJECTS	"ICSNetObjects" 
#define MODULE_DBOBJECTS	"ICSDBObjects"
#define MODULE_SCADAOBJECTS	"ICSScadaObjects"

#endif
