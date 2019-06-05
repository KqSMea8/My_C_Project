// icsdbaccess.h
#ifndef __IDBACCESS_2007_03_14_PENGSHIKANG_H__
#define __IDBACCESS_2007_03_14_PENGSHIKANG_H__

#include "../include/commgr/icsunknown.h" // for IICSUnknown
#include "icsvalue.h"   // for icsvariant

#define MODULE_DBACCESS		"dbaccess"

#define IID_IDALibrary		"idalibrary"
#define IID_IOdbcLibrary	"iodbclibrary"
#define IID_IGaiaLibrary	"igaialibrary"
#define IID_IMysqlLibrary	"imysqllibrary"
#define IID_IDARecords		"idarecords"
#define IID_IDAQuery		"idaquery"
#define IID_IDATable		"idatable"

#define CLSID_DALibrary		"dalibrary"
#define CLSID_DARecords		"darecords"
#define CLSID_DAQuery		"daquery"
#define CLSID_DATable		"datable"

#define STRMAXLEN   4096      // 字段的字符串值的最大长度
#define FIELDNMLEN   128      // 字段名(和参数名)字符串的最大长度

///////////////////////////////////////////////////////////////////////////////
//访问数据库
///////////////////////////////////////////////////////////////////////////////

enum LibraryType   // 数据库类型定义。
{
		LT_NULL,	//未指定数据库
		LT_RTGAIA,	//GAIA实时数据库
		LT_RTMYSQL,	//MySQL实时数据库
		LT_ODBC,	//ODBC通用接口数据库
		LT_ORACLE,	//Oracle数据库
		LT_SQLSVR,	//MS SQL Server数据库
		LT_SYBASE,	//Sybase Adaptive Server数据库
		LT_HMYSQL,	//MySQL磁盘数据库
		LT_DBTWO,	//IBM DB2数据库
		LT_TEXT,	//文本文件型数据库
};

typedef struct // 数据库连接配置信息
{
    LibraryType libType;//数据库类型
	char librName[32];  //数据库登陆名
	char userName[32];  //登陆用户名
	char password[32];  //登陆密码
	char hostAddr[100]; //服务器地址
}DBCONFIG;

enum DAErrorCode    // 数据分析错误信息编码定义
{
		DAE_NoError, //无错误
		DAE_Unknown, //其他错误
		DAE_BadLibType,//无效的数据库类型
		DAE_BadLibCfg,//错误的数据库配置信息
		DAE_MakeLib, //创建数据库连接对象失败
		DAE_NullLib, //空的数据库连接指针
		DAE_OpenLib, //打开数据库连接失败
		DAE_Transact,//事务处理失败
		DAE_MakeRecs,//创建数据访问对象失败
		DAE_NoExec,  //未调用数据库访问的执行函数
		DAE_SqlSpell,//SQL语句拼写错误
		
		DAE_NullJobLib,//未设置业务配置库=10
		DAE_NullJobID,//未设置业务ID号
		DAE_NullDLL,//装载DLL处理接口失败
		DAE_ParamName,//输入的参数名无效
		DAE_ZeroStep,//无计算步骤
		DAE_NullStep,//无对应ID的计算步骤
		DAE_NullHead,//无首项计算步骤
		DAE_OverCross,//交叉组合设置的参数个数过多（不能超过2个）
		DAE_ParamSign,//字符串中参数名的界定符出错（应该为[pn]）
		DAE_UncoParam,//字符串中的参数名在前面未定义
		DAE_NullParam,//字符串中的参数没有对应的值(列表)
		DAE_Bijection,//一一对应组合中存在元素个数不等的参数数组
		DAE_BadLibID,//SQL语句计算项的数据库ID信息无效
		
		DAE_MinusCount, //值的个数<=0 
		DAE_BadDataType,//无效的数据类型
		DAE_NoProcess,//未执行
		
		DAE_NullDBSTab,//未找到数据源（DA_DATASOURCE）表
		DAE_NullRecord,//Select SQL语句无输出记录，不能给参数赋值
		
		DAE_BadFileName,//无效的配置文件名
};

enum RecordsType  // 记录集类型定义。
{
		RT_UNKNOWN, //未定义记录集。未执行SQL语句
		RT_UNQUERY, //非查询记录集。执行数据操纵、数据定义SQL语句或存储过程
		RT_SELECT,  //Select记录集。执行数据查询SQL语句(查询表)
		RT_TABLE,   //数据表记录集。数据库中的数据表(实表)或视图(虚表)
};
//内存（实时）数据库的数据表记录集类型只能是RT_TABLE。

enum ParamIOType  // 参数输入输出类型定义。用于带参数的存储过程
{
		PT_In=1,//输入参数
		PT_Out, //输出参数
		PT_IO,  //输入输出参数
};

struct SQLPARAMS // SQL语句或存储过程的参数信息
{
	char name[64];      //参数字段名称
	icsvariant value;  //参数值
	ParamIOType ioType; //参数输入输出类型
};


//!连接状态改变通知，回调函数原型定义
typedef void (*ConnectCB)(int status);

typedef void (*BeforeUpdateAction)(); //实时库在线更新之前的行为回调
typedef void  (*AfterUpdateAction)(); //实时库在线更新之后的行为回调

//数据库基类
class IDALibrary : virtual public IICSUnknown
{
public:
	//!设置连接状态改变通知回调函数
	virtual bool SetConnectCallback(ConnectCB Function) = 0;
	
	//打开数据库连接。与SetDbConfigInfo()配合使用。
	virtual bool Open() = 0;
	
	//重新打开先前关闭的数据库连接。
	virtual bool Reopen() = 0;
	//判断数据库连接是否打开
	virtual bool IsOpen() = 0;
	//关闭数据库连接。
	virtual void Close() = 0;
	
	//得到数据库连接配置信息
	virtual DBCONFIG GetDbConfigInfo() = 0;
	
	//得到数据库连接的唯一标识。若返回空字符串，则数据库连接为空。
	virtual void GetLibraryID(char* strLibID) = 0;
	//得到操作结果信息编码。
	virtual DAErrorCode GetErrorCode() = 0;
	//得到操作结果信息。返回空字符串，表示执行正确。
	virtual void GetErrorInfo(char* strInfo) = 0;
	
	//给数据库设置事务处理
	virtual bool BeginTransaction() = 0;
	//结束数据库的事务处理（自动提交或回滚）。
	//对该数据库的所有数据访问操作均正确完成时提交，否则回滚。
	virtual bool EndTransaction(char* strInfo=0) = 0;
	//强制提交数据库的事务处理。若提交失败，则需要强制回滚。
	virtual bool CommitTrans() = 0;
	//强制回滚数据库的事务处理
	virtual bool RollbackTrans() = 0;
	
	//!得到当前数据库拥有的数据表的个数
	virtual int GetTableCount() = 0;
	
	//根据数据表在数据库中的索引得到数据表名称
	virtual bool GetTableName(int tableIndex, char* tableName) = 0;
	//根据数据表名称得到数据表在数据库中的索引
	virtual int GetTableIndex(const char* tableName) = 0;
	
	//根据数据表名称得到数据表实体: IRTDBQuery**、QSqlCursor**
	virtual bool GetTableEntity(const char* tableName, void** ppTable) = 0;
	//根据数据表名称得到数据表结构: IRTDBTableSchema**、QSqlCursor**
	virtual bool GetTableSchema(void* pTable, void** ppSchema) = 0;

protected:
	//注册同步在线更新的数据表
	virtual void RegistSynchroTable(const char* tableName, void* pTable) = 0;
	//撤销注册同步在线更新的数据表
	virtual void UnregistSynchroTable(const char* tableName, void* pTable) = 0;
	friend class CGaiaTableIn;
	
public:
	static char *GetIntfName()
	{
		return IID_IDALibrary;
	};
};

//历史数据库类
class IOdbcLibrary : virtual public IDALibrary
{
public:
//private:
	//得到查询表实体: QSqlQuery**
	virtual bool GetQueryEntity(void** ppQuery) = 0;
	//friend class COdbcRecordsIn;
	//得到查询表结构: QSqlQuery*, QSqlRecord**
	virtual bool GetQuerySchema(void* pQuery, void** ppSchema) = 0;
	//friend class COdbcQueryIn;
	
public:
	static char *GetIntfName()
	{
		return IID_IOdbcLibrary;
	};
};

//Gaia实时数据库类
class IGaiaLibrary : virtual public IDALibrary
{
public:
	//设置实时库限定参数和远程服务器的监听端口号
	virtual void SetGaiaParams(const char* miscParams, const char* portParams=0, bool rtdbBuffer=false) = 0;
	//得到实时库限定参数和远程服务器的监听端口号
	virtual void GetGaiaParams(char* miscParams, char* portParams, bool& rtdbBuffer) = 0;
	//刷新Rtdbintf内部缓冲。在线更新完成后调用
	virtual bool RefreshRtdb(const char* updateTableNames=0) = 0;

public:
	static char *GetIntfName()
	{
		return IID_IGaiaLibrary;
	};
};

//Mysql实时数据库类
class IMysqlLibrary : virtual public IDALibrary
{
public:
	//得到数据库实体: MYSQL*
	virtual void* GetDatabase() = 0;
	
public:
	static char *GetIntfName()
	{
		return IID_IMysqlLibrary;
	};
};

/////////////////////////////////////////////////////////////////////////////////////////

//记录集基类
class IDARecords : virtual public IICSUnknown
{
public:
	//执行SQL语句或存储过程。strSQL为SQL语句或存储过程名称。
	//默认不带参数。prmCount>0，表示带参数。
	virtual bool ExecSqlProcess(const char* strSQL, int prmCount=0, const SQLPARAMS params[]=0) = 0;
	
	//关闭查询记录集
	virtual void CloseRecords() = 0;
	
	//得到操作结果信息编码。
	virtual DAErrorCode GetErrorCode() = 0;
	//得到操作结果信息。返回空字符串，表示执行正确。
	virtual void GetErrorInfo(char* strInfo) = 0;

	//得到数据库连接对象
	virtual IDALibrary* GetDatabase() = 0;
	//得到查询结果记录集类型。
	virtual RecordsType GetRecordsType() = 0;

	//得到操作结果影响的记录数。
	//对于数据查询，返回查询表的记录数；
	//对于数据操纵（增删改），返回修改了的数据表记录数。
	virtual int GetRecordCount() = 0;

public:
	static char *GetIntfName()
	{
		return IID_IDARecords;
	};
};

#define BOF_POS   -1    //第一条记录之前的位置
#define AOL_POS   -2    //最后一条记录之后的位置
#define INV_POS   -3    //无效的记录位置（非查询记录集）

//查询记录集类
class IDAQuery : virtual public IDARecords
{
public:
	/*表的记录属性*/
	//得到当前记录的位置[-1表示第一条之前；－2表示最后一条之后]
	virtual int GetPosition() = 0;
	//移动当前记录到第一条[当前记录位置号变为0]
	virtual bool MoveFirst() = 0;
	//移动当前记录到下一条
	virtual bool MoveNext() = 0;
	//移动当前记录到上一条
	virtual bool MovePrev() = 0;
	//移动当前记录到最后一条
	virtual bool MoveLast() = 0;
	//移动当前记录到指定位置。relative表示是否相对当前位置偏移。
	virtual bool MoveTo(int i, bool relative=false) = 0;

	/*表的字段属性*/
	//得到查询表的字段数
	virtual int GetFieldCount() = 0;
	//根据字段名称得到字段位置。字段位置从0开始计数。
	virtual int GetFieldIndex(const char* sField) = 0;
	//根据字段位置得到字段名称。
	virtual const char* GetFieldName(int index) = 0;
	//得到整个数据表的所有字段位置和字段名称。返回查询表的字段数。
	virtual int GetAllFieldName(const char* fields[]) = 0;
	
	//根据字段名称得到字段数据类型
	virtual FIELDTYPE GetFieldType(const char* sField, int& size) = 0;
	//根据字段位置得到字段数据类型
	virtual FIELDTYPE GetFieldType(int index, int& size) = 0;
	
	/*表记录的字段值*/
	//得到当前记录指定字段名称的数据值
	virtual bool GetFieldValue(const char* sField, icsvariant& fldValue) = 0;
	//得到当前记录指定字段位置的数据值
	virtual bool GetFieldValue(int index, icsvariant& fldValue) = 0;
	//得到指定记录指定字段名称的数据值
	virtual bool GetFieldValue(int iRecord, const char* sField, icsvariant& fldValue) = 0;
	//得到指定记录指定字段位置的数据值
	virtual bool GetFieldValue(int iRecord, int index, icsvariant& fldValue) = 0;
	
	//得到全部记录的指定字段名称的数据值列表[长度为recordCount]
	virtual bool GetFieldValues(const char* sField, icsvariant pValues[]) = 0;
	//得到全部记录的指定字段位置的数据值列表[长度为recordCount]
	virtual bool GetFieldValues(int index, icsvariant pValues[]) = 0;
	//得到全部记录的指定字段列表对应的二维表数据值[长度为(fieldNum*recordCount)]
	virtual bool GetFieldValues(int fieldNum, const char* fields[], icsvariant pValues[]) = 0;
	
	//得到指定字段名称的连续数据个数的数据值缓冲区
	virtual bool GetFieldBuffer(const char* sField, void* pBuffer, int nBufSize, int count) = 0;
	//得到指定字段位置的连续数据个数的数据值缓冲区
	virtual bool GetFieldBuffer(int index, void* pBuffer, int nBufSize, int count) = 0;
	
	//得到当前记录所有字段的数据值[长度为fieldCount]
	virtual bool GetRecordValues(icsvariant pValues[]) = 0;
	//得到指定记录所有字段的数据值[长度为fieldCount]
	virtual bool GetRecordValues(int iRecord, icsvariant pValues[]) = 0;
	//得到整个数据表的所有字段的数据值[长度为(fieldCount*recordCount)]
	virtual bool GetTableValues(icsvariant pValues[]) = 0;
	
public:
	static char *GetIntfName()
	{
		return IID_IDAQuery;
	};
};

//单个数据表记录集类
class IDATable : virtual public IDAQuery
{
public:
	//根据数据表名称打开数据库中的单个数据表（或视图）。
	virtual bool OpenTable(const char* tableName, const char* strFilter=0, const char* strSort=0) = 0;
	//设置单表记录集的过滤条件。执行后，当前记录位置为0。
	virtual bool SetFilter(const char* strFilter) = 0;
	//根据整型主键“ID”字段的值定位记录。
	virtual bool LocateByID(int nId) = 0;
	//设置单表记录集的排序条件。执行后，当前记录位置为0。
	//此函数对于Gaia实时数据库，不产生任何操作。
	virtual bool SetSort(const char* strSort) = 0;
	
	//得到RT_TABLE类型记录集的数据表名字
	virtual bool GetTableName(char* strTable) = 0;
	//得到单表记录集的过滤条件。
	virtual bool GetFilter(char* strFilter) = 0;
	//得到单表记录集的排序条件。
	virtual bool GetSort(char* strSort) = 0;

	//根据字段位置对应的值完整地添加记录。fieldIndexs=0，表示字段位置次序为:0,1,2,…。
	virtual int AddRecord(int fieldNum, const icsvariant pValues[], const int fieldIndexs[]=0) = 0;
	//根据字段名称对应的值完整地添加记录。
	virtual int AddRecord(int fieldNum, const char* fieldNames[], const icsvariant pValues[]) = 0;
	
	//根据字段位置对应的值完整地修改记录。每次只修改符合过滤条件的第一条记录。
	//strFilter=0，表示记录集的当前记录。
	virtual int EditRecord(int fieldNum, const icsvariant pValues[], const int fieldIndexs[]=0, const char* strFilter=0) = 0;
	//根据字段名称对应的值完整地修改记录。
	virtual int EditRecord(int fieldNum, const char* fieldNames[], const icsvariant pValues[], const char* strFilter=0) = 0;

	//!在当前记录后面插入新的记录，当前记录指向新记录。使用方式为：Add()…SetFieldValue()…Update()。
	virtual bool Add() = 0;
	//修改当前记录或查询到的第一条记录。使用方式为：Edit()…SetFieldValue()…Update()。
	//此函数对于Gaia实时数据库，不产生任何操作。
	virtual bool Edit(const char* strFilter=0) = 0;
	//设置当前记录中指定字段名称的字段值。参数bCmpTyp表示是否要求匹配字段数据类型。
	virtual bool SetFieldValue(const char* sField, const icsvariant& fldValue, bool bCmpTyp=false) = 0;
	//设置当前记录中指定字段位置的字段值。
	virtual bool SetFieldValue(int index, const icsvariant& fldValue, bool bCmpTyp=false) = 0;
	//设置当前记录中所有字段的字段值。
	virtual bool SetRecordValue(const icsvariant pValues[], bool bCmpTyp=false) = 0;
	//保存编辑的记录。
	virtual int Update() = 0;

	//按照查询条件删除记录。strFilter=0，表示删除记录集的当前记录。
	virtual int Delete(const char* strFilter=0) = 0;
	//!删除当前记录开始的count条记录，记录集游标不动，即定位到被删除记录的下一条记录上
	virtual int Delete(unsigned count) = 0;
	
	//设置指定字段名称的连续数据个数的数据值缓冲区
	virtual bool SetFieldBuffer(const char* sField, void* pBuffer, int nBufSize, int count) = 0;
	//设置指定字段位置的连续数据个数的数据值缓冲区
	virtual bool SetFieldBuffer(int index, void* pBuffer, int nBufSize, int count) = 0;
	
	//刷新记录集 [在线更新后调用]
	virtual bool Refresh() = 0;
	
public:
	static char *GetIntfName()
	{
		return IID_IDATable;
	};
};

#endif
