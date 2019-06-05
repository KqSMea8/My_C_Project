#ifndef _RTDBINTERFACE_H
#define _RTDBINTERFACE_H

/*! \file rtdbintf.h
访问实时库
*/
#if defined(_WIN32)
#ifdef RTDBINTF_BUILD_DLL
#define Rtdbintf_Export __declspec(dllexport)
#else
#define Rtdbintf_Export __declspec(dllimport)
#endif
#else
#define Rtdbintf_Export 
#endif


//Gaia rtdb Field's Data Type
#define  GDB_DT_UNKNOWN  0 // unknown or undetermined
#define  GDB_DT_INT  1     // integer
#define  GDB_DT_FLOAT 2   // floating point
#define  GDB_DT_DATE  3    // date
#define  GDB_DT_TIME  4    // time
#define  GDB_DT_BOOL  5    // boolean (true or false)
#define  GDB_DT_BIT  6     // bit holder
#define  GDB_DT_MASK 7    // bit mask
#define  GDB_DT_CHAR 8  // character string

class IRTDBConnection;
//!使用rtdbintf接口库的入口函数
/*!
	\param ppUnk 输出函数，如果执行成功，*ppUnk指向接口库创建的实时库连接对象
	\return 如果执行成功，返回RTDB_S_OK  \n
			其它返回值请参阅状态码定义
	\warning 一个应用程序必须而且只能调用一次该函数

	\example test_library.cpp
*/
extern "C" int Rtdbintf_Export CreateRtdbConnection(IRTDBConnection** ppUnk);

#include "icsunknown.h"

/*!
\class IRTDBQuery
\brief 表数据查询接口(记录集)
\example test_query_local.cpp
\example test_query_remote.cpp
*/
class IRTDBQuery : public IICSUnknown
{
public:
	//!获取当前记录集订阅的字段个数
	/*!
	\param pCount 输出参数，当前记录集已经订阅的字段个数
	\return 如果执行成功，返回RTDB_S_OK  \n
			其它返回值请参阅状态码定义
	\sa TakeField()
	*/
	virtual int GetFieldCount(unsigned* pCount ) = 0;
	//!获取某一字段句柄对应的字段名
	/*!
	\param Handle 输入参数，字段句柄
	\param Buffer 缓冲区地址，容纳输出的字段名
	\param BufferSize 缓冲区长度(字节数)
	\return 如果执行成功，返回RTDB_S_OK  \n
			其它返回值请参阅状态码定义
	\sa TakeField()
	*/
	virtual int GetFieldName(unsigned Handle, char* Buffer, unsigned BufferSize ) = 0;
	//!取得先前调用Search方法时传入的查询条件
	/*!
	\param Buffer 缓冲区地址，容纳输出的查询条件
	\param BufferSize 缓冲区长度(字节数)
	\return 如果执行成功，返回RTDB_S_OK  \n
			其它返回值请参阅状态码定义
	\sa Search()
	*/
	virtual int GetOptions(char* Buffer, unsigned BufferSize ) = 0;
	//!取得当前记录集所属表的名字
	/*!
	\param Buffer 缓冲区地址，容纳输出的表名字
	\param BufferSize 缓冲区长度(字节数)
	\return 如果执行成功，返回RTDB_S_OK  \n
			其它返回值请参阅状态码定义
	*/
	virtual int GetTableName(char* Buffer, unsigned BufferSize ) = 0;
	//!订阅字段，获取该字段对应的句柄
	/*!
	字段只有在订阅以后才能进行读写操作，使用句柄进行读写操作能够提高程序执行速度
	\param FieldName 要订阅的字段名
	\param pHandle 输出参数，该字段对应的句柄
	\return 如果执行成功，返回RTDB_S_OK  \n
			其它返回值请参阅状态码定义
	\sa ReadField(), WriteField()
	*/
	virtual int TakeField(const char* FieldName, unsigned* pHandle = 0) = 0;
	//!执行查询操作(打开记录集)
	/*!
	\param Options 查询条件，查询条件的格式为"字段名 cmp 值"，其中cmp可以为"=="(等于), 
	"!="(不等于), ">"(大于), "<"(小于), ">="(大于等于), "<="(小于等于)几种比较操作，并且 
	多个查询条件可以结合"&&"(与)或者"||"(或)进行多条件查询；如果要进行全表记录集操作，则
	可以不带参数调用该方法
	\return 如果执行成功，返回RTDB_S_OK  \n
			其它返回值请参阅状态码定义
			执行成功以后，游标定位于第一个有效位置之前，
			可以直接调用MoveNext来遍历记录集直到MoveNext返回RTDB_S_FALSE
	\sa GetOptions()
	*/
	virtual int Search(const char* Options = 0 ) = 0;
	//!定位到ID字段值等于IDValue的记录
	/*!
	实时库中每张表都有一个ID字段，表中记录以ID字段值为主键升序排列。
	该方法在只有在该记录集是全表记录集时才有效
	\param IDValue 要定位记录的ID字段值
	\return 如果符合条件的记录存在，返回RTDB_S_OK，记录游标定位于该记录位置  \n
			如果符合条件的记录不存在，返回RTDB_S_NOTFOUND，记录游标定位于这样一个位置：\n
			在该位置执行插入操作，并将新记录的ID字段值置为IDValue能够保持ID字段的升序排列
			其它返回值请参阅状态码定义
	\sa Search()
	\warning 该方法在访问远程数据库时无效
	*/
	virtual int Locate(int IDValue) = 0;
	//!清空查询结果
	/*!
	调用该方法以后，当前记录集会关闭。此后可以重新调用Search方法得到一个新的记录集
	\return 如果执行成功，返回RTDB_S_OK  \n
			其它返回值请参阅状态码定义
	\sa Search()
	*/
	virtual int Clear() = 0;
	//!取得结果集记录个数
	/*!
	\param pCount 输出参数，当前记录集记录个数
	\return 如果执行成功，返回RTDB_S_OK  \n
			其它返回值请参阅状态码定义
	\sa Search()
	*/
	virtual int GetRecordCount(unsigned* pCount ) = 0;
	//!当前结果集是否为空
	/*!
	\param pYes 输出参数，当前记录集记录个数是否为0
	\return 如果执行成功，返回RTDB_S_OK  \n
			其它返回值请参阅状态码定义
	\sa Search()
	*/
	virtual int IsEmpty(bool* pYes ) = 0;
	//!记录集游标移动到位置Position
	/*!
	\param Position 游标位置
	\return 如果执行成功，返回RTDB_S_OK  \n
			其它返回值请参阅状态码定义
	\sa GetCurrentPosition()
	*/
	virtual int MoveTo(unsigned Position) = 0;
	//!记录集游标是否处于记录集头部(无效位置)
	/*!
	记录集头部和尾部位置为无效游标位置
	\param pYes 输出参数，记录集游标是否处于记录集头部
	\return 如果执行成功，返回RTDB_S_OK  \n
			其它返回值请参阅状态码定义
	\sa IsEOF()
	*/
	virtual int IsBOF(bool* pYes ) = 0;
	//!记录集游标是否处于记录集尾部（无效位置）
	/*!
	记录集头部和尾部位置为无效游标位置
	\param pYes 输出参数，记录集游标是否处于记录集尾部部
	\return 如果执行成功，返回RTDB_S_OK  \n
			其它返回值请参阅状态码定义
	\sa IsBOF()
	*/
	virtual int IsEOF(bool* pYes ) = 0;
	//!记录集游标移动到第一条记录位置
	/*!
	\return 如果执行成功，返回RTDB_S_OK  \n
			如果记录集为空，返回RTDB_S_FALSE \n
			其它返回值请参阅状态码定义
	\sa MoveNext(), MovePrev(), MoveLast()
	*/
	virtual int MoveFirst() = 0;
	//!记录集游标移动到当前记录的下一条记录位置
	/*!
	\return 如果执行成功，返回RTDB_S_OK  \n
			如果当前游标移动到无效位置，则返回RTDB_S_FALSE \n
			其它返回值请参阅状态码定义
	\sa MoveFirst(), MovePrev(), MoveLast()
	*/
	virtual int MoveNext() = 0;
	//!记录集游标移动到当前记录的前一条记录位置
	/*!
	\return 如果执行成功，返回RTDB_S_OK  \n
			如果当前游标移动到无效位置，则返回RTDB_S_FALSE \n
			其它返回值请参阅状态码定义
	\sa MoveFirst(), MoveNext(), MoveLast()
	*/
	virtual int MovePrev() = 0;
	//!记录集游标移动到最后一条记录位置
	/*!
	\return 如果执行成功，返回RTDB_S_OK  \n
			如果记录集为空，返回RTDB_S_FALSE \n
			其它返回值请参阅状态码定义
	\sa MoveFirst(), MoveNext(), MovePrev()
	*/
	virtual int MoveLast() = 0;
	//!取得记录集游标当前位置
	/*!
	\param pPosition 输出参数，记录集游标当前位置
	\return 如果执行成功，返回RTDB_S_OK  \n
			如果记录集为空，返回RTDB_S_FALSE \n
			其它返回值请参阅状态码定义
	\sa MoveFirst(), MoveNext(), MovePrev()
	*/
	virtual int GetCurrentPosition(unsigned* pPosition ) = 0;
	//!通过字段名读字段值
	/*!
	\param FieldName 字段名
	\param Buffer 缓冲区地址，读到的Count条记录在缓冲区中连续存放，以字段长度为单位
	\param BufferSize 缓冲区长度(字节数)
	\param Count 记录个数
	\return 如果Buffer==NULL, 返回执行该操作需要的缓冲区长度
			如果读操作执行成功，返回RTDB_S_OK  \n
			其它返回值请参阅状态码定义
	\sa WriteField()
	*/
	virtual int ReadField(const char* FieldName, void* Buffer, unsigned BufferSize, unsigned Count = 1 ) = 0;	
	//!通过字段名写字段值
	/*!
	\param FieldName 字段名
	\param Buffer 缓冲区地址，要写入的Count条记录在缓冲区中连续存放，以字段长度为单位
	\param BufferSize 缓冲区长度(字节数)
	\param Count 记录个数
	\return 如果执行成功，返回RTDB_S_OK  \n
			其它返回值请参阅状态码定义
	\sa ReadField()
	\warning 该方法在访问远程数据库时一次只能写入一条记录
	*/
	virtual int WriteField(const char* FieldName, void* Buffer, unsigned BufferSize, unsigned Count = 1 ) = 0;
	//!通过字段句柄读字段值
	/*!
	\param Handle 字段句柄
	\param Buffer 缓冲区地址，读到的Count条记录在缓冲区中连续存放，以字段长度为单位, 远程操作环境下，
		一次只能写一条记录，并且字符串字段的最大长度不能超过512字节
	\param BufferSize 缓冲区长度(字节数)
	\param Count 记录个数
	\return 如果Buffer==NULL, 返回执行该操作需要的缓冲区长度
			如果读操作执行成功，返回RTDB_S_OK  \n
			其它返回值请参阅状态码定义
	\sa TakeField(), WriteField()

	*/
	virtual int ReadField(unsigned Handle, void* Buffer, unsigned BufferSize, unsigned Count = 1 ) = 0;
	//!通过字段句柄读字段值
	/*!
	\param Handle 字段句柄
	\param Buffer 缓冲区地址，要写入的Count条记录在缓冲区中连续存放，以字段长度为单位
	\param BufferSize 缓冲区长度(字节数)
	\param Count 记录个数
	\return 如果执行成功，返回RTDB_S_OK  \n
			其它返回值请参阅状态码定义
	\sa TakeField(), ReadField()
	\warning 该方法在访问远程数据库时一次只能写入一条记录
	*/
	virtual int WriteField(unsigned Handle, void* Buffer, unsigned BufferSize, unsigned Count = 1 ) = 0;
	//!刷新字段缓冲区
	/*!
	\param FieldName 字段名
	\warning 该方法已过时，不再使用
	\return RTDB_S_OK  			
	*/
	virtual int Refresh(const char* FieldName ) = 0;
	//!刷新字段缓冲区
	/*!
	\param Handle 字段句柄
	\return RTDB_S_OK  	
	\warning 该方法已过时，不再使用
	*/
	virtual int Refresh(unsigned Handle ) = 0;
	//!读当前记录(所有字段)
	/*!
	\param Buffer 缓冲区地址，该缓冲区是一个特定的结构体。该结构体的内存布局由
		数据库定义文件(dbdef文件)决定，由gdbformat生成
	\param BufferSize 缓冲区长度(字节数)
	\param Count 记录个数
	\return 如果执行成功，返回RTDB_S_OK  \n
			其它返回值请参阅状态码定义
	\sa WriteRecord()
	\warning 目前仅支持在访问本地实时库时使用该方法，并且一次只能读一条记录。
	*/
	virtual int ReadRecord(void* Buffer, unsigned BufferSize, unsigned Count = 1) = 0;
	//!写当前记录(所有字段)
	/*!
	\param Buffer 缓冲区地址，该缓冲区是一个特定的结构体。该结构体的内存布局由
		数据库定义文件(dbdef文件)决定，由gdbformat生成
	\param BufferSize 缓冲区长度(字节数)
	\param Count 记录个数
	\return 如果执行成功，返回RTDB_S_OK  \n
			其它返回值请参阅状态码定义
	\sa ReadRecord()
	\warning 目前仅支持在访问本地实时库时使用该方法，并且一次只能读一条记录。
	*/
	virtual int WriteRecord(void* Buffer, unsigned BufferSize, unsigned Count = 1) = 0;
	//!在记录集最后面插入Count条空记录，并将记录集游标移到新增加的第一条记录上（同Append）
	/*!
	\param Count 记录个数
	\return 如果执行成功，返回RTDB_S_OK  \n
			其它返回值请参阅状态码定义
	\sa Delete()，Append()
	\warning 目前仅支持在访问本地实时库时使用该方法，
	*/
	virtual int Insert(unsigned Count = 1 ) = 0;
	//!删除当前记录开始的Count条记录，记录集游标不动，即定位到被删除记录的下一条记录上
	/*!
	\param Count 记录个数
	\return 如果执行成功，返回RTDB_S_OK  \n
			其它返回值请参阅状态码定义
	\sa Insert()，Append()
	\warning 目前仅支持在访问本地实时库时使用该方法，执行该方法以后，查询记录集不再有效
	*/
	virtual int Delete(unsigned Count = 1 ) = 0;
	//!在记录集的尾部增加Count条空记录，并将记录集游标移到新增加的第一条记录上
	/*!
	\param Count 记录个数
	\return 如果执行成功，返回RTDB_S_OK  \n
			其它返回值请参阅状态码定义
	\sa Delete()Insert()
	\warning 目前仅支持在访问本地实时库时使用该方法，
	*/
	virtual int Append(unsigned Count = 1 ) = 0;
	//!执行高级查询操作(打开记录集，支持位操作符)
	/*!
	\param Options 查询条件，查询条件的格式为"字段名 cmp 值"，其中cmp可以为"=="(等于), 
	"!="(不等于), ">"(大于), "<"(小于), ">="(大于等于), "<="(小于等于)几种比较操作，并且 
	多个查询条件可以结合"&&"(与)或者"||"(或)进行多条件查询；如果要进行全表记录集操作，则
	可以不带参数调用该方法
	\return 如果执行成功，返回RTDB_S_OK  \n
	其它返回值请参阅状态码定义
	执行成功以后，游标定位于第一个有效位置之前，
	可以直接调用MoveNext来遍历记录集直到MoveNext返回RTDB_S_FALSE
	\sa GetOptions()
	*/
	virtual int Search2(const char* Options = 0 ) = 0;
};


//!实时库字段类型
#define RTDB_DT_UNKNOWN	GDB_DT_UNKNOWN
#define RTDB_DT_INT	GDB_DT_INT
#define RTDB_DT_FLOAT	GDB_DT_FLOAT
#define RTDB_DT_TIME	GDB_DT_TIME
#define RTDB_DT_STRING	GDB_DT_CHAR

//!实时库字段缓存策略
#define RTDB_USE_READ_BUFFER	1			//通常是静态配置字段，在运行时不会改变，要改变也只能通过在线更新来完成
#define RTDB_WRITE_TIMER1_BUFFER	2		//使用周期1批量写入该字段到实时库中
#define RTDB_WRITE_TIMER2_BUFFER	4		//使用周期2批量写入该字段到实时库中

/*!
\class IRTDBFieldSchema
\brief 字段模型访问接口
\example test_fieldschema_local.cpp
*/
class IRTDBFieldSchema : public IICSUnknown 
{
public:
	//!得到当前字段名字
	/*!
	\param Buffer 缓冲区地址
	\param BufferSize 缓冲区长度(字节数)
	\return 如果执行成功，返回RTDB_S_OK  \n
			其它返回值请参阅状态码定义
	*/
	virtual int GetName(char* Buffer, unsigned BufferSize ) = 0;
	//!得到当前字段类型
	/*!
	\param pType 输出参数，表类型，参见表类型定义
	\return 如果执行成功，返回RTDB_S_OK  \n
			其它返回值请参阅状态码定义
	*/
	virtual int GetType(unsigned* pType ) = 0;
	//!得到当前字段长度(字节数)
	/*!
	\param pSize 输出参数，表容量
	\return 如果执行成功，返回RTDB_S_OK  \n
			其它返回值请参阅状态码定义
	*/
	virtual int GetSize(unsigned* pSize ) = 0;
	//!判断当前字段是否为主键字段
	/*!
	\param pYes 输出参数，是否主键
	\return 如果执行成功，返回RTDB_S_OK  \n
			其它返回值请参阅状态码定义
	*/
	virtual int IsKey(bool* pYes ) = 0;
	//!判断当前字段是否建有索引
	/*!
	\param pYes 输出参数，是否建有索引
	\return 如果执行成功，返回RTDB_S_OK  \n
			其它返回值请参阅状态码定义
	*/
	virtual int IsIndex(bool* pYes ) = 0;
	//!判断当前字段内容是否会同步
	/*!
	\param pYes 输出参数，是否同步
	\return 如果执行成功，返回RTDB_S_OK  \n
			其它返回值请参阅状态码定义
	*/
	virtual int IsSynchronized(bool* pYes ) = 0;
	//!获取字段属性标志, 用于扩展
	/*!
	\param pFlag 输出参数，字段属性标志
	\return 如果执行成功，返回RTDB_S_OK  \n
			其它返回值请参阅状态码定义
	*/
	virtual int GetFlag(int* pFlag ) = 0;
	//!描述信息
	/*!
	\param Buffer 缓冲区地址
	\param BufferSize 缓冲区长度(字节数)
	\return 如果执行成功，返回RTDB_S_OK  \n
	其它返回值请参阅状态码定义
	*/
	virtual int GetDescription(char* Buffer, unsigned BufferSize ) = 0;
	//!设置字段缓存策略
	/*!
	\param Buffer 缓冲区地址
	\param BufferSize 缓冲区长度(字节数)
	\return 如果执行成功，返回RTDB_S_OK  \n
	其它返回值请参阅状态码定义
	*/
	virtual int SetBufferPolicy(int BufferPolicy ) = 0;
};

//!表类型
#define RTDB_TABLE_UNKNOWN	0	//!<未知类型
#define RTDB_TABLE_GLOBAL	1	//!<全局表
#define RTDB_TABLE_CIRTUAL	2	//!<循环数据表
#define RTDB_TABLE_TABLE	4	//!<普通数据表
#define RTDB_TABLE_SYSTEM	8	//!<系统表

/*!
\class IRTDBTableSchema
\brief 表模型访问接口
\example test_tableschema_local.cpp
*/
class IRTDBTableSchema : public IICSUnknown
{
public:
	//!得到当前表名字
	/*!
	\param Buffer 缓冲区地址
	\param BufferSize 缓冲区长度(字节数)
	\return 如果执行成功，返回RTDB_S_OK  \n
			其它返回值请参阅状态码定义
	*/
	virtual int GetName(char* Buffer, unsigned BufferSize ) = 0;
	//!得到当前表类型
	/*!
	\param pType 输出参数，表类型，参见表类型定义,目前用户定义表全是普通数据表
	\return 如果执行成功，返回RTDB_S_OK  \n
			其它返回值请参阅状态码定义
	*/
	virtual int GetType(unsigned* pType ) = 0;
	//!得到当前表容量，即表能够容纳的最大记录数
	/*!
	\param pSize 输出参数，表容量
	\return 如果执行成功，返回RTDB_S_OK  \n
			其它返回值请参阅状态码定义
	*/
	virtual int GetSize(unsigned* pSize ) = 0;
	//!得到当前表拥有的字段个数
	/*!
	\param pCount 输出参数，字段个数
	\return 如果执行成功，返回RTDB_S_OK  \n
			其它返回值请参阅状态码定义
	*/
	virtual int GetFieldCount(unsigned* pCount ) = 0;
	//!得到一个新的字段模型访问接口
	/*!
	\param FieldName 字段名
	\param ppFieldSchema 输出参数，*ppFieldSchema指向新创建字段模型对象的IRTDBFieldSchema接口
	\return 如果执行成功，返回RTDB_S_OK  \n
			其它返回值请参阅状态码定义
	*/
	virtual int GetFieldSchema(const char* FieldName, IRTDBFieldSchema** ppFieldSchema ) = 0;
	//!得到一个新的字段模型访问接口
	/*!
	\param FieldIndex 字段索引顺序号，从1开始，最大值==字段的个数
	\param ppFieldSchema 输出参数，*ppFieldSchema指向新创建字段模型对象的IRTDBFieldSchema接口
	\return 如果执行成功，返回RTDB_S_OK  \n
			其它返回值请参阅状态码定义
	*/
	virtual int GetFieldSchema(unsigned FieldIndex, IRTDBFieldSchema** ppFieldSchema ) = 0;
	//!获取表描述信息
	/*!
	\param Buffer 缓冲区地址
	\param BufferSize 缓冲区长度(字节数)
	\return 如果执行成功，返回RTDB_S_OK  \n
	其它返回值请参阅状态码定义
	*/
	virtual int GetDescription(char* Buffer, unsigned BufferSize ) = 0;
};

/*!
\class IRTDBDatabase
\brief 数据库对象访问接口
\example test_database_local.cpp
*/
class IRTDBDatabase : public IICSUnknown
{
public:
	//!打开数据库
	/*!
	\param DBName 实时数据库名字
	\param MiscParams 实时库限定参数，格式为"App=xx;Fam=xx", 默认为"App＝ics8000;fam＝xuji"
	\return 如果执行成功，返回RTDB_S_OK  \n
			其它返回值请参阅状态码定义
	\sa GetName(), GetMiscParams()
	*/
	virtual int Open(const char* DBName, const char* MiscParams = 0 ) = 0;
	//!关闭当前数据库(过时方法，实时库在退出时自动关闭)
	/*!
	\return 如果执行成功，返回RTDB_S_OK  \n
			其它返回值请参阅状态码定义
	\sa Open(), IsOpened()
	*/
	virtual int Close() = 0;
	//!当前实时库是否处于打开状态
	/*!
	\param pYes 输出参数，如果*pYes == true，数据库处于打开状态\n
						  如果*pYes == false，数据库处于关闭状态				  
	\return 如果执行成功，返回RTDB_S_OK  \n
			其它返回值请参阅状态码定义
	\sa Open(), Close()
	*/
	virtual int IsOpened( bool *pYes ) = 0;
	//!得到当前数据库名字
	/*!
	\param Buffer 缓冲区地址
	\param BufferSize 缓冲区长度(字节数)
	\return 如果执行成功，返回RTDB_S_OK  \n
			其它返回值请参阅状态码定义
	\sa Open()
	*/
	virtual int GetName(char* Buffer, unsigned BufferSize ) = 0;
	//!得到当前数据库限定参数
	/*!
	\param Buffer 缓冲区地址
	\param BufferSize 缓冲区长度(字节数)
	\return 如果执行成功，返回RTDB_S_OK  \n
			其它返回值请参阅状态码定义
	\sa Open()
	*/
	virtual int GetMiscParams(char* Buffer, unsigned BufferSize ) = 0;
	//!得到当前数据库拥有的数据表的个数
	/*!
	\param pCount 输出参数，表的个数
	\return 如果执行成功，返回RTDB_S_OK  \n
			其它返回值请参阅状态码定义
	\sa Open()
	*/
	virtual int GetTableCount(unsigned* pCount) = 0;
	//!得到表模型访问接口
	/*!
	\param TableName 表名字
	\param ppTableSchema 输出参数，*ppTableSchema指向新创建表模型对象的IRTDBTableSchema接口
	\return 如果执行成功，返回RTDB_S_OK  \n
			其它返回值请参阅状态码定义
	*/	
	virtual int GetTableSchema(const char* TableName, IRTDBTableSchema** ppTableSchema ) = 0;
	//!得到表模型访问接口
	/*!
	\param TableIndex 表索引顺序号，从1开始，最大值==表的个数
	\param ppTableSchema 输出参数，*ppTableSchema指向新创建表模型对象的IRTDBTableSchema接口
	\return 如果执行成功，返回RTDB_S_OK  \n
			其它返回值请参阅状态码定义
	*/
	virtual int GetTableSchema(unsigned TableIndex, IRTDBTableSchema** ppTableSchema ) = 0;
	//!得到一个新的表数据查询接口
	/*!
	\param TableName 表名字
	\param ppQuery 输出参数，*ppQuery指向新创建查询对象的IRTDBQuery接口
	\return 如果执行成功，返回RTDB_S_OK  \n
			其它返回值请参阅状态码定义
	*/	
	virtual int GetQuery(const char* TableName, IRTDBQuery** ppQuery ) = 0;
	//!得到一个新的表数据查询接口
	/*!
	\param TableIndex 表索引顺序号，从1开始，最大值==表的个数
	\param ppQuery 输出参数，*ppQuery指向新创建查询对象的IRTDBQuery接口
	\return 如果执行成功，返回RTDB_S_OK  \n
			其它返回值请参阅状态码定义
	*/
	virtual int GetQuery(unsigned TableIndex, IRTDBQuery** ppQuery ) = 0;
	//!清空数据库
	/*!
	\return 如果执行成功，返回RTDB_S_OK  \n
			其它返回值请参阅状态码定义
	*/
	virtual int Initialize() = 0;
	//!重建字段索引
	/*!
	\return 如果执行成功，返回RTDB_S_OK  \n
			其它返回值请参阅状态码定义
	*/
	virtual int RebuildFieldIndex(const char* FieldName, const char* TableName) = 0;
	//!重建表索引
	/*!
	\return 如果执行成功，返回RTDB_S_OK  \n
			其它返回值请参阅状态码定义
	*/
	virtual int RebuildTableIndex(const char* TableName) = 0;
	//!重建所有索引
	/*!
	\return 如果执行成功，返回RTDB_S_OK  \n
			其它返回值请参阅状态码定义
	*/
	virtual int RebuildAllIndex() = 0;
	//!刷新内部缓冲，在线更新完成后调用
	/*!
	\return 如果执行成功，返回RTDB_S_OK  \n
	其它返回值请参阅状态码定义
	*/
	virtual int Refresh() = 0;
};

//!要求服务器类型
#define RTDB_REQUIRE_ANY		1
#define RTDB_REQUIRE_PRIMARY	2
#define RTDB_REQUIRE_STANDBY	3

//!连接状态改变通知，回调函数原型定义
/*!
\param nStatus 当前连接状态 \n 如果连接建立，则nStatus == RTDB_S_CONNECTED 
	\n如果连接中断，则nStatus == RTDB_S_DISCONNECTED

\sa IRTDBConnection::SetConnectCallback()
*/
typedef void (*ConnectCB)(int nStatus );

/*!
\class IRTDBConnection
\brief 实时库连接对象管理接口
\example test_rtdbconnection.cpp
*/
class IRTDBConnection : public IICSUnknown
{
public:
	//!设置远程服务器地址,如果连接本地服务器，则不需要调用SetHostName，或者以NULL为参数调用
	/*!
	\param HostName 远程服务器地址，格式为"Host1=192.168.1.18,192.168.4.230;Host2=192.168.1.109,192.168.4.44"
	\return 如果执行成功，返回RTDB_S_OK  \n
			其它返回值请参阅状态码定义
	\sa GetHostName()	
	*/
	virtual int SetHostName(const char* HostName ) = 0;
	//!设置连接实时数据库的用户名
	/*!
	\param UserName 用户名
	\return 如果执行成功，返回RTDB_S_OK  \n
			其它返回值请参阅状态码定义
	\sa GetUserName()
	*/
	virtual int SetUserName(const char* UserName ) = 0;
	//!设置用户密码
	/*!
	\param Password 用户密码
	\return 如果执行成功，返回RTDB_S_OK  \n
			其它返回值请参阅状态码定义
	\sa GetPassword()
	*/
	virtual int SetPassword(const char* Password ) = 0;
	//!设置远程服务器的监听端口号
	/*!
	\param MiscParams 远程服务器的socket端口号，格式为"RequiredServer=xxx;Socket=xxxx",默认端口号为8040
		如果RequiredServer == 1, 不关心实时库服务器的主备状态；
		如果RequiredServer == 2, 自动连接主服务器；
		如果 RequiredServer == 3, 自动连接备服务器。
	\return 如果执行成功，返回RTDB_S_OK  \n
			其它返回值请参阅状态码定义
	\sa GetMiscParams()
	*/
	virtual int SetMiscParams(const char* MiscParams ) = 0;
	//!设置连接状态改变通知回调函数
	/*!
	\param Function 回调函数指针
	\return 如果执行成功，返回RTDB_S_OK  \n
			其它返回值请参阅状态码定义
	\sa ConnectCB
	*/
	virtual int SetConnectCallback(ConnectCB Function) = 0;
	//!连接数据库服务器
	/*!
	\param ConnectString 连接字符串，格式为"HostName=xx;UserName=xx;Password=xx;MiscParams=xx"
	\return 如果执行成功，返回RTDB_S_OK  \n
			其它返回值请参阅状态码定义
	\sa SetHostName(), SetUserName(), SetPassword(), SetMiscParams(), SetConnectCallback()
	*/
	virtual int Connect(const char* ConnectString) = 0;
	//!连接数据库服务器
	/*!
	\return 如果执行成功，返回RTDB_S_OK  \n
			其它返回值请参阅状态码定义
	\sa SetHostName(), SetUserName(), SetPassword(), SetMiscParams(), SetConnectCallback()
	*/
	virtual int Connect() = 0;
	//!断开数据库服务器，本地实时库不能断开连接
	/*!
	\return 如果执行成功，返回RTDB_S_OK  \n
			其它返回值请参阅状态码定义
	\sa Connect(), SetConnectCallback()
	*/
	virtual int Disconnect() = 0;
	//!当前对象是否处于连接状态
	/*!
	\param pYes 输出参数，如果*pYes == true,则连接成功；否则，连接失败
	\return 如果执行成功，返回RTDB_S_OK  \n
			其它返回值请参阅状态码定义
	\sa Connect()
	*/
	virtual int IsConnected( bool* pYes ) = 0;
	//!取得先前设置的远程服务器地址
	/*!
	\param Buffer 缓冲区地址
	\param BufferSize 缓冲区长度（字节数）
	\return 如果执行成功，返回RTDB_S_OK  \n
			其它返回值请参阅状态码定义
	\sa SetHostName()
	*/
	virtual int GetHostName(char* Buffer, unsigned BufferSize ) = 0;
	//!取得先前设置的远程服务器用户名,由于windows上编译名字冲突问题，从GetUserName更名为GetUserNameStr
	/*!
	\param Buffer 缓冲区地址
	\param BufferSize 缓冲区长度（字节数）
	\return 如果执行成功，返回RTDB_S_OK  \n
			其它返回值请参阅状态码定义
	\sa SetUserName()
	*/
	virtual int GetUserNameStr(char* Buffer, unsigned BufferSize ) = 0;
	//!取得先前设置的用户访问密码
	/*!
	\param Buffer 缓冲区地址
	\param BufferSize 缓冲区长度（字节数）
	\return 如果执行成功，返回RTDB_S_OK  \n
			其它返回值请参阅状态码定义
	\sa SetPassword()
	*/
	virtual int GetPassword(char* Buffer, unsigned BufferSize ) = 0;
	//!取得先前设置的连接端口号
	/*!
	\param Buffer 缓冲区地址
	\param BufferSize 缓冲区长度（字节数）
	\return 如果执行成功，返回RTDB_S_OK  \n
			其它返回值请参阅状态码定义
	\sa SetMiscParams()
	*/
	virtual int GetMiscParams(char* Buffer, unsigned BufferSize ) = 0;
	//!获得一个新的数据库对象
	/*!
	\param ppDatabase *ppDatabase指向新创建对象的IRTDBDatabase接口
	\return 如果执行成功，返回RTDB_S_OK  \n
			其它返回值请参阅状态码定义
	\sa SetMiscParams()
	*/
	virtual int GetDatabase(IRTDBDatabase** ppDatabase ) = 0;
	//!开始一个新的事务	
	/*!
	调用该方法成功以后，所有的修改实时库操作都将在内部缓冲区中进行
	\return 如果执行成功，返回RTDB_S_OK  \n
			其它返回值请参阅状态码定义
	\sa CommitTransaction(), RollbackTransaction()
	*/
	virtual int BeginTrasaction() = 0;
	//!提交当前事务
	/*!
	从上次调用BeginTransaction以来的修改操作都将被写入实时库中
	\return 如果执行成功，返回RTDB_S_OK  \n
			其它返回值请参阅状态码定义
	\sa BeginTrasaction()
	*/
	virtual int CommitTransaction() = 0;
	//!回滚当前事务
	/*!
	从上次调用BeginTransaction以来的修改操作都将被恢复
	\return 如果执行成功，返回RTDB_S_OK  \n
			其它返回值请参阅状态码定义
	\sa BeginTrasaction()
	*/
	virtual int RollbackTransaction() = 0;
	//!暂停或者恢复同步操作
	/*!
	如果启动同步操作，则由gaia保证用户在主服务器上进行的更新实时库操作都将在备服务器上重演以保持一致
	\param Yes 如果为Yes == true,则停止双机同步操作\n
			   如果为Yes == false, 则启动双机同步操作
	\return 如果执行成功，返回RTDB_S_OK  \n
			其它返回值请参阅状态码定义	
	*/
	virtual int DisableSyncronize(bool Yes) = 0;
	//!是否启用实时库缓存机制
	/*!
	\param Yes 如果为Yes == true,使用实时库缓存机制\n
	如果为Yes == false, 不使用实时库缓存机制（默认）
	\return 如果执行成功，返回RTDB_S_OK  \n
	其它返回值请参阅状态码定义	
	*/
	virtual int UseRtdbBuffer(bool yes) = 0;
	//!更新实时库缓冲和索引（在线更新完成以后调用）
	/*!
	\return 如果执行成功，返回RTDB_S_OK  \n
	其它返回值请参阅状态码定义	
	*/
	virtual int UpdateRtdbBuffer() = 0;
	
};

//!状态码定义
#define RTDB_S_OK 0			//!<成功
#define RTDB_S_FALSE -1		//!<失败
#define RTDB_S_INVALID_PARAM	10001	//!<无效的参数
#define RTDB_S_NO_ENOUGH_BUFFER	10002	//!<缓冲区不足
#define RTDB_S_CONNECTED	10003	//!<连接建立
#define RTDB_S_DISCONNECTED	10004	//!<连接中断
#define RTDB_S_RECONNECT	10005	//!<重复连接
#define RTDB_S_NOMEMORY		10006	//!<内存不足
#define RTDB_S_REOPEN		10007	//!<重复打开
#define RTDB_S_NOTOPEN		10008	//!<数据库没有打开
#define RTDB_S_NOTSURPPORT	10009	//!<不支持的操作
#define RTDB_S_NOTFOUND		10010	//!<没有找到
#define RTDB_S_TIMEOUT		10011	//!<超时
#define RTDB_S_OUTOFRANGE	10012	//!<越界
#define RTDB_S_ROLENOTMATCH	10013	//!<服务器的主备角色不符合要求
#define RTDB_S_VERSION_INCOMPATIBLE 10014 //!<远程访问通信协议不兼容
#define RTDB_S_INTERNAL_ERROR 10015 //!<远程访问通信协议不兼容
#endif
