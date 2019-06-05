// igaiatable.h
#ifndef __IGATATABLE_2008_11_29_PENGSHIKANG_H__
#define __IGATATABLE_2008_11_29_PENGSHIKANG_H__

#include "icsdbaccess.h"   // for icsvariant、IDATable

#define IID_IGaiaTable		"igaiatable"
#define CLSID_GaiaTable		"gaiatable"

///////////////////////////////////////////////////////////////////////////////
//访问带缓存的数据表
///////////////////////////////////////////////////////////////////////////////

typedef enum 
{
		INVBUFF = -1, //无效缓存
		NULBUFF, //0--未缓存
		OLDBUFF, //1--旧缓存
		NEWBUFF, //2--新缓存
		BADBUFF, //3--坏缓存（指缓存大小与数据库中字段空间大小不一致）
}BufferState;//数据表字段缓存的状态

//带缓存的数据表类
class IGaiaTable : virtual public IICSUnknown
{
public:
	//得到数据表的记录数。--
	virtual int GetRecordCount() = 0;
	
	//得到数据表的字段数。--
	virtual int GetFieldCount() = 0;
	
	//得到整个数据表的所有字段位置和字段名称。返回数据表的字段数。--
	virtual int GetAllFieldName(const char* fields[]) = 0;
	
	//根据字段名得到字段索引。--
	virtual int GetFieldIndex(const char* sField) = 0;
	
	//得到指定字段缓存的状态。
	virtual BufferState GetFieldState(int index) = 0;
	
	//从数据表装载整个字段内容。返回值表示是否真正装载了数据。
	virtual bool LoadField(int index) = 0;
	
	//整个字段内容写入数据表。返回值表示是否真正更新了数据表。
	virtual bool SaveField(int index) = 0;
	
	//释放整个字段缓存占用的空间。
	virtual void FreeField(int index) = 0;
	
	//更新整个数据表内容。[数据表在线更新后调用它]
	//返回值：0，更新失败；1，更新成功，记录数未变；2，更新成功，记录数已变化。
	virtual int LoadTable(int fldCount=0, const int* indexs=0, bool onlyRead=false, const char* strFilter="DELETEFLAG==0") = 0;
	
	//整个缓存内容写入数据表。[数据表在线更新前调用它]
	virtual void SaveTable(int fldCount=0, const int* indexs=0) = 0;
	
	
	//根据记录ID得到记录位置。失败时返回-1。
	virtual int GetPosById(int id, bool bRequery=false) = 0;
	
	//根据记录位置得到记录ID。失败时返回-1。
	virtual int GetIdByPos(int pos) = 0;
	
	//得到指定记录位置指定字段索引的字段值。失败时返回0。
	virtual const void* GetFieldValueByPos(int pos, int index) = 0;
	
	//得到指定记录ID指定字段索引的字段值。失败时返回0。
	virtual const void* GetFieldValueById(int id, int index, bool bRequery=false) = 0;

	//得到全表指定字段索引的字段值。直接从数据库读取。
	virtual bool GetAllFieldValues(int index, void* pValues) = 0;
	
	//初始化指定字段索引处的字段值全为0或空字符串。
	//注意：只有调用SaveField()或SaveTable()后才写入数据库。
	virtual bool InitFieldValuesToZero(int index) = 0;
	
	//设置指定记录位置指定字段索引处的字段值。
	//注意：只有调用SaveField()或SaveTable()后才写入数据库。
	virtual bool SetFieldValueByPos(int pos, int index, const void* pValue) = 0;
	
	//设置指定记录ID指定字段索引处的字段值。
	//注意：只有调用SaveField()或SaveTable()后才写入数据库。
	virtual bool SetFieldValueById(int id, int index, const void* pValue) = 0;
	
	//由外部设置指定记录位置指定字段索引的字段值。失败时返回0。
	//注意：只有调用SaveField()或SaveTable()后才写入数据库。
	virtual void* SetFieldValueByPos(int pos, int index) = 0;
	
	//由外部设置指定记录ID指定字段索引的字段值。失败时返回0。
	//注意：只有调用SaveField()或SaveTable()后才写入数据库。
	virtual void* SetFieldValueById(int id, int index) = 0;
	
	//设置全表指定字段索引处的字段值。直接写入数据库。
	virtual bool SetAllFieldValues(int index, void* pValues) = 0;
	
	//将指定记录位置指定字段索引的字段值写入数据表。
	virtual bool SaveField(int pos, int index, const void* pValue=0) = 0;
	
	//提取数据访问表。
	//注意：当不再使用返回的指针时，请调用返回指针的Release()方法！！
	virtual IDATable* TakeDATable() = 0;

	//得到全部ID值。返回记录数。
	virtual int GetAllIdentifiers(int* pIdValues) = 0;
	
public:
	static char *GetIntfName()
	{
		return IID_IGaiaTable;
	};
};

#endif
