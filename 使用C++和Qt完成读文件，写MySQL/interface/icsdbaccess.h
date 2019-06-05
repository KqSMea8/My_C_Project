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

#define STRMAXLEN   4096      // �ֶε��ַ���ֵ����󳤶�
#define FIELDNMLEN   128      // �ֶ���(�Ͳ�����)�ַ�������󳤶�

///////////////////////////////////////////////////////////////////////////////
//�������ݿ�
///////////////////////////////////////////////////////////////////////////////

enum LibraryType   // ���ݿ����Ͷ��塣
{
		LT_NULL,	//δָ�����ݿ�
		LT_RTGAIA,	//GAIAʵʱ���ݿ�
		LT_RTMYSQL,	//MySQLʵʱ���ݿ�
		LT_ODBC,	//ODBCͨ�ýӿ����ݿ�
		LT_ORACLE,	//Oracle���ݿ�
		LT_SQLSVR,	//MS SQL Server���ݿ�
		LT_SYBASE,	//Sybase Adaptive Server���ݿ�
		LT_HMYSQL,	//MySQL�������ݿ�
		LT_DBTWO,	//IBM DB2���ݿ�
		LT_TEXT,	//�ı��ļ������ݿ�
};

typedef struct // ���ݿ�����������Ϣ
{
    LibraryType libType;//���ݿ�����
	char librName[32];  //���ݿ��½��
	char userName[32];  //��½�û���
	char password[32];  //��½����
	char hostAddr[100]; //��������ַ
}DBCONFIG;

enum DAErrorCode    // ���ݷ���������Ϣ���붨��
{
		DAE_NoError, //�޴���
		DAE_Unknown, //��������
		DAE_BadLibType,//��Ч�����ݿ�����
		DAE_BadLibCfg,//��������ݿ�������Ϣ
		DAE_MakeLib, //�������ݿ����Ӷ���ʧ��
		DAE_NullLib, //�յ����ݿ�����ָ��
		DAE_OpenLib, //�����ݿ�����ʧ��
		DAE_Transact,//������ʧ��
		DAE_MakeRecs,//�������ݷ��ʶ���ʧ��
		DAE_NoExec,  //δ�������ݿ���ʵ�ִ�к���
		DAE_SqlSpell,//SQL���ƴд����
		
		DAE_NullJobLib,//δ����ҵ�����ÿ�=10
		DAE_NullJobID,//δ����ҵ��ID��
		DAE_NullDLL,//װ��DLL����ӿ�ʧ��
		DAE_ParamName,//����Ĳ�������Ч
		DAE_ZeroStep,//�޼��㲽��
		DAE_NullStep,//�޶�ӦID�ļ��㲽��
		DAE_NullHead,//��������㲽��
		DAE_OverCross,//����������õĲ����������ࣨ���ܳ���2����
		DAE_ParamSign,//�ַ����в������Ľ綨������Ӧ��Ϊ[pn]��
		DAE_UncoParam,//�ַ����еĲ�������ǰ��δ����
		DAE_NullParam,//�ַ����еĲ���û�ж�Ӧ��ֵ(�б�)
		DAE_Bijection,//һһ��Ӧ����д���Ԫ�ظ������ȵĲ�������
		DAE_BadLibID,//SQL������������ݿ�ID��Ϣ��Ч
		
		DAE_MinusCount, //ֵ�ĸ���<=0 
		DAE_BadDataType,//��Ч����������
		DAE_NoProcess,//δִ��
		
		DAE_NullDBSTab,//δ�ҵ�����Դ��DA_DATASOURCE����
		DAE_NullRecord,//Select SQL����������¼�����ܸ�������ֵ
		
		DAE_BadFileName,//��Ч�������ļ���
};

enum RecordsType  // ��¼�����Ͷ��塣
{
		RT_UNKNOWN, //δ�����¼����δִ��SQL���
		RT_UNQUERY, //�ǲ�ѯ��¼����ִ�����ݲ��ݡ����ݶ���SQL����洢����
		RT_SELECT,  //Select��¼����ִ�����ݲ�ѯSQL���(��ѯ��)
		RT_TABLE,   //���ݱ��¼�������ݿ��е����ݱ�(ʵ��)����ͼ(���)
};
//�ڴ棨ʵʱ�����ݿ�����ݱ��¼������ֻ����RT_TABLE��

enum ParamIOType  // ��������������Ͷ��塣���ڴ������Ĵ洢����
{
		PT_In=1,//�������
		PT_Out, //�������
		PT_IO,  //�����������
};

struct SQLPARAMS // SQL����洢���̵Ĳ�����Ϣ
{
	char name[64];      //�����ֶ�����
	icsvariant value;  //����ֵ
	ParamIOType ioType; //���������������
};


//!����״̬�ı�֪ͨ���ص�����ԭ�Ͷ���
typedef void (*ConnectCB)(int status);

typedef void (*BeforeUpdateAction)(); //ʵʱ�����߸���֮ǰ����Ϊ�ص�
typedef void  (*AfterUpdateAction)(); //ʵʱ�����߸���֮�����Ϊ�ص�

//���ݿ����
class IDALibrary : virtual public IICSUnknown
{
public:
	//!��������״̬�ı�֪ͨ�ص�����
	virtual bool SetConnectCallback(ConnectCB Function) = 0;
	
	//�����ݿ����ӡ���SetDbConfigInfo()���ʹ�á�
	virtual bool Open() = 0;
	
	//���´���ǰ�رյ����ݿ����ӡ�
	virtual bool Reopen() = 0;
	//�ж����ݿ������Ƿ��
	virtual bool IsOpen() = 0;
	//�ر����ݿ����ӡ�
	virtual void Close() = 0;
	
	//�õ����ݿ�����������Ϣ
	virtual DBCONFIG GetDbConfigInfo() = 0;
	
	//�õ����ݿ����ӵ�Ψһ��ʶ�������ؿ��ַ����������ݿ�����Ϊ�ա�
	virtual void GetLibraryID(char* strLibID) = 0;
	//�õ����������Ϣ���롣
	virtual DAErrorCode GetErrorCode() = 0;
	//�õ����������Ϣ�����ؿ��ַ�������ʾִ����ȷ��
	virtual void GetErrorInfo(char* strInfo) = 0;
	
	//�����ݿ�����������
	virtual bool BeginTransaction() = 0;
	//�������ݿ���������Զ��ύ��ع�����
	//�Ը����ݿ���������ݷ��ʲ�������ȷ���ʱ�ύ������ع���
	virtual bool EndTransaction(char* strInfo=0) = 0;
	//ǿ���ύ���ݿ�����������ύʧ�ܣ�����Ҫǿ�ƻع���
	virtual bool CommitTrans() = 0;
	//ǿ�ƻع����ݿ��������
	virtual bool RollbackTrans() = 0;
	
	//!�õ���ǰ���ݿ�ӵ�е����ݱ�ĸ���
	virtual int GetTableCount() = 0;
	
	//�������ݱ������ݿ��е������õ����ݱ�����
	virtual bool GetTableName(int tableIndex, char* tableName) = 0;
	//�������ݱ����Ƶõ����ݱ������ݿ��е�����
	virtual int GetTableIndex(const char* tableName) = 0;
	
	//�������ݱ����Ƶõ����ݱ�ʵ��: IRTDBQuery**��QSqlCursor**
	virtual bool GetTableEntity(const char* tableName, void** ppTable) = 0;
	//�������ݱ����Ƶõ����ݱ�ṹ: IRTDBTableSchema**��QSqlCursor**
	virtual bool GetTableSchema(void* pTable, void** ppSchema) = 0;

protected:
	//ע��ͬ�����߸��µ����ݱ�
	virtual void RegistSynchroTable(const char* tableName, void* pTable) = 0;
	//����ע��ͬ�����߸��µ����ݱ�
	virtual void UnregistSynchroTable(const char* tableName, void* pTable) = 0;
	friend class CGaiaTableIn;
	
public:
	static char *GetIntfName()
	{
		return IID_IDALibrary;
	};
};

//��ʷ���ݿ���
class IOdbcLibrary : virtual public IDALibrary
{
public:
//private:
	//�õ���ѯ��ʵ��: QSqlQuery**
	virtual bool GetQueryEntity(void** ppQuery) = 0;
	//friend class COdbcRecordsIn;
	//�õ���ѯ��ṹ: QSqlQuery*, QSqlRecord**
	virtual bool GetQuerySchema(void* pQuery, void** ppSchema) = 0;
	//friend class COdbcQueryIn;
	
public:
	static char *GetIntfName()
	{
		return IID_IOdbcLibrary;
	};
};

//Gaiaʵʱ���ݿ���
class IGaiaLibrary : virtual public IDALibrary
{
public:
	//����ʵʱ���޶�������Զ�̷������ļ����˿ں�
	virtual void SetGaiaParams(const char* miscParams, const char* portParams=0, bool rtdbBuffer=false) = 0;
	//�õ�ʵʱ���޶�������Զ�̷������ļ����˿ں�
	virtual void GetGaiaParams(char* miscParams, char* portParams, bool& rtdbBuffer) = 0;
	//ˢ��Rtdbintf�ڲ����塣���߸�����ɺ����
	virtual bool RefreshRtdb(const char* updateTableNames=0) = 0;

public:
	static char *GetIntfName()
	{
		return IID_IGaiaLibrary;
	};
};

//Mysqlʵʱ���ݿ���
class IMysqlLibrary : virtual public IDALibrary
{
public:
	//�õ����ݿ�ʵ��: MYSQL*
	virtual void* GetDatabase() = 0;
	
public:
	static char *GetIntfName()
	{
		return IID_IMysqlLibrary;
	};
};

/////////////////////////////////////////////////////////////////////////////////////////

//��¼������
class IDARecords : virtual public IICSUnknown
{
public:
	//ִ��SQL����洢���̡�strSQLΪSQL����洢�������ơ�
	//Ĭ�ϲ���������prmCount>0����ʾ��������
	virtual bool ExecSqlProcess(const char* strSQL, int prmCount=0, const SQLPARAMS params[]=0) = 0;
	
	//�رղ�ѯ��¼��
	virtual void CloseRecords() = 0;
	
	//�õ����������Ϣ���롣
	virtual DAErrorCode GetErrorCode() = 0;
	//�õ����������Ϣ�����ؿ��ַ�������ʾִ����ȷ��
	virtual void GetErrorInfo(char* strInfo) = 0;

	//�õ����ݿ����Ӷ���
	virtual IDALibrary* GetDatabase() = 0;
	//�õ���ѯ�����¼�����͡�
	virtual RecordsType GetRecordsType() = 0;

	//�õ��������Ӱ��ļ�¼����
	//�������ݲ�ѯ�����ز�ѯ��ļ�¼����
	//�������ݲ��ݣ���ɾ�ģ��������޸��˵����ݱ��¼����
	virtual int GetRecordCount() = 0;

public:
	static char *GetIntfName()
	{
		return IID_IDARecords;
	};
};

#define BOF_POS   -1    //��һ����¼֮ǰ��λ��
#define AOL_POS   -2    //���һ����¼֮���λ��
#define INV_POS   -3    //��Ч�ļ�¼λ�ã��ǲ�ѯ��¼����

//��ѯ��¼����
class IDAQuery : virtual public IDARecords
{
public:
	/*��ļ�¼����*/
	//�õ���ǰ��¼��λ��[-1��ʾ��һ��֮ǰ����2��ʾ���һ��֮��]
	virtual int GetPosition() = 0;
	//�ƶ���ǰ��¼����һ��[��ǰ��¼λ�úű�Ϊ0]
	virtual bool MoveFirst() = 0;
	//�ƶ���ǰ��¼����һ��
	virtual bool MoveNext() = 0;
	//�ƶ���ǰ��¼����һ��
	virtual bool MovePrev() = 0;
	//�ƶ���ǰ��¼�����һ��
	virtual bool MoveLast() = 0;
	//�ƶ���ǰ��¼��ָ��λ�á�relative��ʾ�Ƿ���Ե�ǰλ��ƫ�ơ�
	virtual bool MoveTo(int i, bool relative=false) = 0;

	/*����ֶ�����*/
	//�õ���ѯ����ֶ���
	virtual int GetFieldCount() = 0;
	//�����ֶ����Ƶõ��ֶ�λ�á��ֶ�λ�ô�0��ʼ������
	virtual int GetFieldIndex(const char* sField) = 0;
	//�����ֶ�λ�õõ��ֶ����ơ�
	virtual const char* GetFieldName(int index) = 0;
	//�õ��������ݱ�������ֶ�λ�ú��ֶ����ơ����ز�ѯ����ֶ�����
	virtual int GetAllFieldName(const char* fields[]) = 0;
	
	//�����ֶ����Ƶõ��ֶ���������
	virtual FIELDTYPE GetFieldType(const char* sField, int& size) = 0;
	//�����ֶ�λ�õõ��ֶ���������
	virtual FIELDTYPE GetFieldType(int index, int& size) = 0;
	
	/*���¼���ֶ�ֵ*/
	//�õ���ǰ��¼ָ���ֶ����Ƶ�����ֵ
	virtual bool GetFieldValue(const char* sField, icsvariant& fldValue) = 0;
	//�õ���ǰ��¼ָ���ֶ�λ�õ�����ֵ
	virtual bool GetFieldValue(int index, icsvariant& fldValue) = 0;
	//�õ�ָ����¼ָ���ֶ����Ƶ�����ֵ
	virtual bool GetFieldValue(int iRecord, const char* sField, icsvariant& fldValue) = 0;
	//�õ�ָ����¼ָ���ֶ�λ�õ�����ֵ
	virtual bool GetFieldValue(int iRecord, int index, icsvariant& fldValue) = 0;
	
	//�õ�ȫ����¼��ָ���ֶ����Ƶ�����ֵ�б�[����ΪrecordCount]
	virtual bool GetFieldValues(const char* sField, icsvariant pValues[]) = 0;
	//�õ�ȫ����¼��ָ���ֶ�λ�õ�����ֵ�б�[����ΪrecordCount]
	virtual bool GetFieldValues(int index, icsvariant pValues[]) = 0;
	//�õ�ȫ����¼��ָ���ֶ��б��Ӧ�Ķ�ά������ֵ[����Ϊ(fieldNum*recordCount)]
	virtual bool GetFieldValues(int fieldNum, const char* fields[], icsvariant pValues[]) = 0;
	
	//�õ�ָ���ֶ����Ƶ��������ݸ���������ֵ������
	virtual bool GetFieldBuffer(const char* sField, void* pBuffer, int nBufSize, int count) = 0;
	//�õ�ָ���ֶ�λ�õ��������ݸ���������ֵ������
	virtual bool GetFieldBuffer(int index, void* pBuffer, int nBufSize, int count) = 0;
	
	//�õ���ǰ��¼�����ֶε�����ֵ[����ΪfieldCount]
	virtual bool GetRecordValues(icsvariant pValues[]) = 0;
	//�õ�ָ����¼�����ֶε�����ֵ[����ΪfieldCount]
	virtual bool GetRecordValues(int iRecord, icsvariant pValues[]) = 0;
	//�õ��������ݱ�������ֶε�����ֵ[����Ϊ(fieldCount*recordCount)]
	virtual bool GetTableValues(icsvariant pValues[]) = 0;
	
public:
	static char *GetIntfName()
	{
		return IID_IDAQuery;
	};
};

//�������ݱ��¼����
class IDATable : virtual public IDAQuery
{
public:
	//�������ݱ����ƴ����ݿ��еĵ������ݱ�����ͼ����
	virtual bool OpenTable(const char* tableName, const char* strFilter=0, const char* strSort=0) = 0;
	//���õ����¼���Ĺ���������ִ�к󣬵�ǰ��¼λ��Ϊ0��
	virtual bool SetFilter(const char* strFilter) = 0;
	//��������������ID���ֶε�ֵ��λ��¼��
	virtual bool LocateByID(int nId) = 0;
	//���õ����¼��������������ִ�к󣬵�ǰ��¼λ��Ϊ0��
	//�˺�������Gaiaʵʱ���ݿ⣬�������κβ�����
	virtual bool SetSort(const char* strSort) = 0;
	
	//�õ�RT_TABLE���ͼ�¼�������ݱ�����
	virtual bool GetTableName(char* strTable) = 0;
	//�õ������¼���Ĺ���������
	virtual bool GetFilter(char* strFilter) = 0;
	//�õ������¼��������������
	virtual bool GetSort(char* strSort) = 0;

	//�����ֶ�λ�ö�Ӧ��ֵ��������Ӽ�¼��fieldIndexs=0����ʾ�ֶ�λ�ô���Ϊ:0,1,2,����
	virtual int AddRecord(int fieldNum, const icsvariant pValues[], const int fieldIndexs[]=0) = 0;
	//�����ֶ����ƶ�Ӧ��ֵ��������Ӽ�¼��
	virtual int AddRecord(int fieldNum, const char* fieldNames[], const icsvariant pValues[]) = 0;
	
	//�����ֶ�λ�ö�Ӧ��ֵ�������޸ļ�¼��ÿ��ֻ�޸ķ��Ϲ��������ĵ�һ����¼��
	//strFilter=0����ʾ��¼���ĵ�ǰ��¼��
	virtual int EditRecord(int fieldNum, const icsvariant pValues[], const int fieldIndexs[]=0, const char* strFilter=0) = 0;
	//�����ֶ����ƶ�Ӧ��ֵ�������޸ļ�¼��
	virtual int EditRecord(int fieldNum, const char* fieldNames[], const icsvariant pValues[], const char* strFilter=0) = 0;

	//!�ڵ�ǰ��¼��������µļ�¼����ǰ��¼ָ���¼�¼��ʹ�÷�ʽΪ��Add()��SetFieldValue()��Update()��
	virtual bool Add() = 0;
	//�޸ĵ�ǰ��¼���ѯ���ĵ�һ����¼��ʹ�÷�ʽΪ��Edit()��SetFieldValue()��Update()��
	//�˺�������Gaiaʵʱ���ݿ⣬�������κβ�����
	virtual bool Edit(const char* strFilter=0) = 0;
	//���õ�ǰ��¼��ָ���ֶ����Ƶ��ֶ�ֵ������bCmpTyp��ʾ�Ƿ�Ҫ��ƥ���ֶ��������͡�
	virtual bool SetFieldValue(const char* sField, const icsvariant& fldValue, bool bCmpTyp=false) = 0;
	//���õ�ǰ��¼��ָ���ֶ�λ�õ��ֶ�ֵ��
	virtual bool SetFieldValue(int index, const icsvariant& fldValue, bool bCmpTyp=false) = 0;
	//���õ�ǰ��¼�������ֶε��ֶ�ֵ��
	virtual bool SetRecordValue(const icsvariant pValues[], bool bCmpTyp=false) = 0;
	//����༭�ļ�¼��
	virtual int Update() = 0;

	//���ղ�ѯ����ɾ����¼��strFilter=0����ʾɾ����¼���ĵ�ǰ��¼��
	virtual int Delete(const char* strFilter=0) = 0;
	//!ɾ����ǰ��¼��ʼ��count����¼����¼���α겻��������λ����ɾ����¼����һ����¼��
	virtual int Delete(unsigned count) = 0;
	
	//����ָ���ֶ����Ƶ��������ݸ���������ֵ������
	virtual bool SetFieldBuffer(const char* sField, void* pBuffer, int nBufSize, int count) = 0;
	//����ָ���ֶ�λ�õ��������ݸ���������ֵ������
	virtual bool SetFieldBuffer(int index, void* pBuffer, int nBufSize, int count) = 0;
	
	//ˢ�¼�¼�� [���߸��º����]
	virtual bool Refresh() = 0;
	
public:
	static char *GetIntfName()
	{
		return IID_IDATable;
	};
};

#endif
