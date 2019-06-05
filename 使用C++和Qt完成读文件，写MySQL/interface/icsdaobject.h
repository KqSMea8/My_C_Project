#ifndef _ICSDAOBJECT__INTERFACE_H_
#define _ICSDAOBJECT__INTERFACE_H_

#include "icsdbaccess.h" // for IDATable
#include "qiptr.h"

#define MODULE_ICSDAOBJECT		"icsdao"
#define CLSID_ICSDAObject       "ICSDAObject"
#define IID_IICSDAObject        "IICSDAObject"

/*
数据访问对象类: 提供统一数据访问接口
*/
class IICSDAObject : virtual public IICSUnknown
{
public:
	/////////////////////////////////////////////////////////////////
	//1、初始化操作
	/////////////////////////////////////////////////////////////////
	//设置数据表记录集对象
	virtual bool SetDataTable(IDATable* pTable) = 0;
	//对数据表记录集进行过滤
	virtual bool Filter(const char* strFilter) = 0;
	//取记录集中指定顺序号的记录对象
	virtual bool IndexTo(int pos, bool bRefresh=true) = 0;
	//根据ID值定位记录集中的记录对象
	virtual bool LocateByID(int nId) = 0;
	//设置对象在数据表记录集中的主键字段名
	virtual bool SetPrimeKey(const char* strPK) = 0;
	
	
	/////////////////////////////////////////////////////////////////
	//2、数据库操作
	/////////////////////////////////////////////////////////////////

	//数据库表中数据刷新到对象字段(适用于RT_TABLE、RT_SELECT、RT_UNQUERY类型)
	//若执行成功，返回影响的记录数；若执行失败，返回-1，表示操作错误。
	virtual int Load() = 0;

	//将对象字段值加入数据库表中的一条新增的记录中(适用于RT_TABLE类型)
	virtual int Insert() = 0;
	//将对象字段值加入数据库表中对应的一条已存在的记录中(适用于RT_TABLE类型)
	virtual int Update() = 0;

	//保存对象内容到数据库表中(适用于RT_TABLE类型对象)
	//该函数内部根据对象状态，决定执行Insert()或Update()操作
	virtual int Save() = 0;

	//删除数据库表中当前对象所在的记录(执行成功后，当前对象位置变为-1)
	virtual bool Remove() = 0;


	/////////////////////////////////////////////////////////////////
	//3、对象操作
	/////////////////////////////////////////////////////////////////
	//查询记录集的第一个对象(如果对象对应的记录集的记录个数为0，则它返回NULL)
	virtual IICSDAObject* FirstObj() = 0;
	//查询记录集的下一个对象(如果当前对象为最后一个对象，则它返回NULL)
	virtual IICSDAObject* NextObj() = 0;
	//查询记录集指定位置的对象
	virtual IICSDAObject* IndexObj(int pos) = 0;
	//复制一个同样内容的新对象(对象状态同样复制)
	virtual IICSDAObject* CopyObj() = 0;
	//通过对象的主键值从记录集中读取对象
	virtual IICSDAObject* FromPrimeKey(const icsvariant& pkValue) = 0;
	

	/////////////////////////////////////////////////////////////////
	//4、对象属性操作
	/////////////////////////////////////////////////////////////////
	//得到数据表记录集对象
	virtual bool GetDataTable(IDATable* pTable) = 0;
	//得到对象的过滤条件
	virtual bool GetFilter(char* strFilter) = 0;
	//得到对象的主键名称
	virtual bool GetPrimeKeyName(char* pkName) = 0;

	//得到对象对应的记录集的记录个数
	virtual int GetObjCount() = 0;
	//得到当前对象在记录集中的位置
	virtual int GetObjIndex() = 0;
	
	/////////////////////////////////////////////////////////////////
	//5、对象字段操作
	/////////////////////////////////////////////////////////////////
	//得到当前对象的字段数
	virtual int GetFieldCount() = 0;
	//得到当前对象的新建字段数
	virtual int GetNewFieldCount() = 0;
	
	//根据字段名称得到字段位置
	virtual int GetFieldIndex(const char* fldName) = 0;
	//根据字段位置得到字段名称(字段位置从0开始计数)
	virtual bool GetFieldName(int index, char* fldName) = 0;

	//根据字段名称得到字段数据类型
	virtual FIELDTYPE GetFieldType(const char* fldName) = 0;
	//根据字段位置得到字段数据类型
	virtual FIELDTYPE GetFieldType(int index) = 0;

	//得到指定字段名称的数据值(参数bKeepType表示取到的值是否转换为给定数据类型)
	virtual bool GetFieldValue(const char* fldName, icsvariant& fldValue, bool bKeepType=false) = 0;
	//得到指定字段位置的数据值(参数bKeepType表示取到的值是否转换为给定数据类型)
	virtual bool GetFieldValue(int index, icsvariant& fldValue, bool bKeepType=false) = 0;
	//得到对象主键字段的数据值(参数bKeepType表示取到的值是否转换为给定数据类型)
	virtual bool GetPrimeKeyValue(icsvariant& pkValue, bool bKeepType=false) = 0;
	
	//设置指定字段名称的字段值(参数bCreate表示: 当指定的字段不存在时是否创建新字段)
	virtual bool SetFieldValue(const char* fldName, const icsvariant& fldValue, bool bCreate=false) = 0;
	//设置指定字段位置的字段值(当index >= 总字段个数时，设置字段值失败(返回false))
	virtual bool SetFieldValue(int index, const icsvariant& fldValue) = 0;
	//新建一个对象主键字段的数据值(对于实时数据库，该操作会在数据表中插入一条记录)
	virtual bool NewPrimeKeyValue(const icsvariant& pkValue) = 0;
	
	//根据字段名称判断是否为已存在的字段
	virtual bool IsExistField(const char* fldName) = 0;
	//根据字段位置判断是否为已存在的字段(不存在的字段一定是新字段、空值字段、删除失败的字段)
	virtual bool IsExistField(int index) = 0;

	//根据字段名称判断是否为新字段
	virtual bool IsNewField(const char* fldName) = 0;
	//根据字段位置判断是否为新字段
	virtual bool IsNewField(int index) = 0;
	
	//删除新字段(只有已存在的新字段才能删除成功)
	virtual bool RemoveNewField(const char* fldName) = 0;
	//清空动态字段列表的所有数据项。
	virtual void ClearNewFields() = 0;
	//将动态字段转移到数据库字段。与CreateObjectBy配合使用。
	virtual void NewFieldsToDbFields() = 0;

private:
	friend class CICSDAObjectIn;//dll内部用的友元类

	//以下方法属于CICSDAObjectIn内部使用的接口方法:
	//设置动态字段列表删除数据项时是否自动释放数据项内存。[内部使用]
	virtual void SetAutoDeleteNewFields(bool bDelNewFld) = 0;
	//得到动态字段列表。[内部使用]
	virtual void* GetNewFields() = 0;

public:
    static char *GetIntfName()
    {
        return IID_IICSDAObject;
    };
};

typedef CQIPtr<IICSDAObject> ICSDAObject;

#endif 
