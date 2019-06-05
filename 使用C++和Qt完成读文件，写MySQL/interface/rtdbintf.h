#ifndef _RTDBINTERFACE_H
#define _RTDBINTERFACE_H

/*! \file rtdbintf.h
����ʵʱ��
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
//!ʹ��rtdbintf�ӿڿ����ں���
/*!
	\param ppUnk ������������ִ�гɹ���*ppUnkָ��ӿڿⴴ����ʵʱ�����Ӷ���
	\return ���ִ�гɹ�������RTDB_S_OK  \n
			��������ֵ�����״̬�붨��
	\warning һ��Ӧ�ó���������ֻ�ܵ���һ�θú���

	\example test_library.cpp
*/
extern "C" int Rtdbintf_Export CreateRtdbConnection(IRTDBConnection** ppUnk);

#include "icsunknown.h"

/*!
\class IRTDBQuery
\brief �����ݲ�ѯ�ӿ�(��¼��)
\example test_query_local.cpp
\example test_query_remote.cpp
*/
class IRTDBQuery : public IICSUnknown
{
public:
	//!��ȡ��ǰ��¼�����ĵ��ֶθ���
	/*!
	\param pCount �����������ǰ��¼���Ѿ����ĵ��ֶθ���
	\return ���ִ�гɹ�������RTDB_S_OK  \n
			��������ֵ�����״̬�붨��
	\sa TakeField()
	*/
	virtual int GetFieldCount(unsigned* pCount ) = 0;
	//!��ȡĳһ�ֶξ����Ӧ���ֶ���
	/*!
	\param Handle ����������ֶξ��
	\param Buffer ��������ַ������������ֶ���
	\param BufferSize ����������(�ֽ���)
	\return ���ִ�гɹ�������RTDB_S_OK  \n
			��������ֵ�����״̬�붨��
	\sa TakeField()
	*/
	virtual int GetFieldName(unsigned Handle, char* Buffer, unsigned BufferSize ) = 0;
	//!ȡ����ǰ����Search����ʱ����Ĳ�ѯ����
	/*!
	\param Buffer ��������ַ����������Ĳ�ѯ����
	\param BufferSize ����������(�ֽ���)
	\return ���ִ�гɹ�������RTDB_S_OK  \n
			��������ֵ�����״̬�붨��
	\sa Search()
	*/
	virtual int GetOptions(char* Buffer, unsigned BufferSize ) = 0;
	//!ȡ�õ�ǰ��¼�������������
	/*!
	\param Buffer ��������ַ����������ı�����
	\param BufferSize ����������(�ֽ���)
	\return ���ִ�гɹ�������RTDB_S_OK  \n
			��������ֵ�����״̬�붨��
	*/
	virtual int GetTableName(char* Buffer, unsigned BufferSize ) = 0;
	//!�����ֶΣ���ȡ���ֶζ�Ӧ�ľ��
	/*!
	�ֶ�ֻ���ڶ����Ժ���ܽ��ж�д������ʹ�þ�����ж�д�����ܹ���߳���ִ���ٶ�
	\param FieldName Ҫ���ĵ��ֶ���
	\param pHandle ������������ֶζ�Ӧ�ľ��
	\return ���ִ�гɹ�������RTDB_S_OK  \n
			��������ֵ�����״̬�붨��
	\sa ReadField(), WriteField()
	*/
	virtual int TakeField(const char* FieldName, unsigned* pHandle = 0) = 0;
	//!ִ�в�ѯ����(�򿪼�¼��)
	/*!
	\param Options ��ѯ��������ѯ�����ĸ�ʽΪ"�ֶ��� cmp ֵ"������cmp����Ϊ"=="(����), 
	"!="(������), ">"(����), "<"(С��), ">="(���ڵ���), "<="(С�ڵ���)���ֱȽϲ��������� 
	�����ѯ�������Խ��"&&"(��)����"||"(��)���ж�������ѯ�����Ҫ����ȫ���¼����������
	���Բ����������ø÷���
	\return ���ִ�гɹ�������RTDB_S_OK  \n
			��������ֵ�����״̬�붨��
			ִ�гɹ��Ժ��α궨λ�ڵ�һ����Чλ��֮ǰ��
			����ֱ�ӵ���MoveNext��������¼��ֱ��MoveNext����RTDB_S_FALSE
	\sa GetOptions()
	*/
	virtual int Search(const char* Options = 0 ) = 0;
	//!��λ��ID�ֶ�ֵ����IDValue�ļ�¼
	/*!
	ʵʱ����ÿ�ű���һ��ID�ֶΣ����м�¼��ID�ֶ�ֵΪ�����������С�
	�÷�����ֻ���ڸü�¼����ȫ���¼��ʱ����Ч
	\param IDValue Ҫ��λ��¼��ID�ֶ�ֵ
	\return ������������ļ�¼���ڣ�����RTDB_S_OK����¼�α궨λ�ڸü�¼λ��  \n
			������������ļ�¼�����ڣ�����RTDB_S_NOTFOUND����¼�α궨λ������һ��λ�ã�\n
			�ڸ�λ��ִ�в�������������¼�¼��ID�ֶ�ֵ��ΪIDValue�ܹ�����ID�ֶε���������
			��������ֵ�����״̬�붨��
	\sa Search()
	\warning �÷����ڷ���Զ�����ݿ�ʱ��Ч
	*/
	virtual int Locate(int IDValue) = 0;
	//!��ղ�ѯ���
	/*!
	���ø÷����Ժ󣬵�ǰ��¼����رա��˺�������µ���Search�����õ�һ���µļ�¼��
	\return ���ִ�гɹ�������RTDB_S_OK  \n
			��������ֵ�����״̬�붨��
	\sa Search()
	*/
	virtual int Clear() = 0;
	//!ȡ�ý������¼����
	/*!
	\param pCount �����������ǰ��¼����¼����
	\return ���ִ�гɹ�������RTDB_S_OK  \n
			��������ֵ�����״̬�붨��
	\sa Search()
	*/
	virtual int GetRecordCount(unsigned* pCount ) = 0;
	//!��ǰ������Ƿ�Ϊ��
	/*!
	\param pYes �����������ǰ��¼����¼�����Ƿ�Ϊ0
	\return ���ִ�гɹ�������RTDB_S_OK  \n
			��������ֵ�����״̬�붨��
	\sa Search()
	*/
	virtual int IsEmpty(bool* pYes ) = 0;
	//!��¼���α��ƶ���λ��Position
	/*!
	\param Position �α�λ��
	\return ���ִ�гɹ�������RTDB_S_OK  \n
			��������ֵ�����״̬�붨��
	\sa GetCurrentPosition()
	*/
	virtual int MoveTo(unsigned Position) = 0;
	//!��¼���α��Ƿ��ڼ�¼��ͷ��(��Чλ��)
	/*!
	��¼��ͷ����β��λ��Ϊ��Ч�α�λ��
	\param pYes �����������¼���α��Ƿ��ڼ�¼��ͷ��
	\return ���ִ�гɹ�������RTDB_S_OK  \n
			��������ֵ�����״̬�붨��
	\sa IsEOF()
	*/
	virtual int IsBOF(bool* pYes ) = 0;
	//!��¼���α��Ƿ��ڼ�¼��β������Чλ�ã�
	/*!
	��¼��ͷ����β��λ��Ϊ��Ч�α�λ��
	\param pYes �����������¼���α��Ƿ��ڼ�¼��β����
	\return ���ִ�гɹ�������RTDB_S_OK  \n
			��������ֵ�����״̬�붨��
	\sa IsBOF()
	*/
	virtual int IsEOF(bool* pYes ) = 0;
	//!��¼���α��ƶ�����һ����¼λ��
	/*!
	\return ���ִ�гɹ�������RTDB_S_OK  \n
			�����¼��Ϊ�գ�����RTDB_S_FALSE \n
			��������ֵ�����״̬�붨��
	\sa MoveNext(), MovePrev(), MoveLast()
	*/
	virtual int MoveFirst() = 0;
	//!��¼���α��ƶ�����ǰ��¼����һ����¼λ��
	/*!
	\return ���ִ�гɹ�������RTDB_S_OK  \n
			�����ǰ�α��ƶ�����Чλ�ã��򷵻�RTDB_S_FALSE \n
			��������ֵ�����״̬�붨��
	\sa MoveFirst(), MovePrev(), MoveLast()
	*/
	virtual int MoveNext() = 0;
	//!��¼���α��ƶ�����ǰ��¼��ǰһ����¼λ��
	/*!
	\return ���ִ�гɹ�������RTDB_S_OK  \n
			�����ǰ�α��ƶ�����Чλ�ã��򷵻�RTDB_S_FALSE \n
			��������ֵ�����״̬�붨��
	\sa MoveFirst(), MoveNext(), MoveLast()
	*/
	virtual int MovePrev() = 0;
	//!��¼���α��ƶ������һ����¼λ��
	/*!
	\return ���ִ�гɹ�������RTDB_S_OK  \n
			�����¼��Ϊ�գ�����RTDB_S_FALSE \n
			��������ֵ�����״̬�붨��
	\sa MoveFirst(), MoveNext(), MovePrev()
	*/
	virtual int MoveLast() = 0;
	//!ȡ�ü�¼���α굱ǰλ��
	/*!
	\param pPosition �����������¼���α굱ǰλ��
	\return ���ִ�гɹ�������RTDB_S_OK  \n
			�����¼��Ϊ�գ�����RTDB_S_FALSE \n
			��������ֵ�����״̬�붨��
	\sa MoveFirst(), MoveNext(), MovePrev()
	*/
	virtual int GetCurrentPosition(unsigned* pPosition ) = 0;
	//!ͨ���ֶ������ֶ�ֵ
	/*!
	\param FieldName �ֶ���
	\param Buffer ��������ַ��������Count����¼�ڻ�������������ţ����ֶγ���Ϊ��λ
	\param BufferSize ����������(�ֽ���)
	\param Count ��¼����
	\return ���Buffer==NULL, ����ִ�иò�����Ҫ�Ļ���������
			���������ִ�гɹ�������RTDB_S_OK  \n
			��������ֵ�����״̬�붨��
	\sa WriteField()
	*/
	virtual int ReadField(const char* FieldName, void* Buffer, unsigned BufferSize, unsigned Count = 1 ) = 0;	
	//!ͨ���ֶ���д�ֶ�ֵ
	/*!
	\param FieldName �ֶ���
	\param Buffer ��������ַ��Ҫд���Count����¼�ڻ�������������ţ����ֶγ���Ϊ��λ
	\param BufferSize ����������(�ֽ���)
	\param Count ��¼����
	\return ���ִ�гɹ�������RTDB_S_OK  \n
			��������ֵ�����״̬�붨��
	\sa ReadField()
	\warning �÷����ڷ���Զ�����ݿ�ʱһ��ֻ��д��һ����¼
	*/
	virtual int WriteField(const char* FieldName, void* Buffer, unsigned BufferSize, unsigned Count = 1 ) = 0;
	//!ͨ���ֶξ�����ֶ�ֵ
	/*!
	\param Handle �ֶξ��
	\param Buffer ��������ַ��������Count����¼�ڻ�������������ţ����ֶγ���Ϊ��λ, Զ�̲��������£�
		һ��ֻ��дһ����¼�������ַ����ֶε���󳤶Ȳ��ܳ���512�ֽ�
	\param BufferSize ����������(�ֽ���)
	\param Count ��¼����
	\return ���Buffer==NULL, ����ִ�иò�����Ҫ�Ļ���������
			���������ִ�гɹ�������RTDB_S_OK  \n
			��������ֵ�����״̬�붨��
	\sa TakeField(), WriteField()

	*/
	virtual int ReadField(unsigned Handle, void* Buffer, unsigned BufferSize, unsigned Count = 1 ) = 0;
	//!ͨ���ֶξ�����ֶ�ֵ
	/*!
	\param Handle �ֶξ��
	\param Buffer ��������ַ��Ҫд���Count����¼�ڻ�������������ţ����ֶγ���Ϊ��λ
	\param BufferSize ����������(�ֽ���)
	\param Count ��¼����
	\return ���ִ�гɹ�������RTDB_S_OK  \n
			��������ֵ�����״̬�붨��
	\sa TakeField(), ReadField()
	\warning �÷����ڷ���Զ�����ݿ�ʱһ��ֻ��д��һ����¼
	*/
	virtual int WriteField(unsigned Handle, void* Buffer, unsigned BufferSize, unsigned Count = 1 ) = 0;
	//!ˢ���ֶλ�����
	/*!
	\param FieldName �ֶ���
	\warning �÷����ѹ�ʱ������ʹ��
	\return RTDB_S_OK  			
	*/
	virtual int Refresh(const char* FieldName ) = 0;
	//!ˢ���ֶλ�����
	/*!
	\param Handle �ֶξ��
	\return RTDB_S_OK  	
	\warning �÷����ѹ�ʱ������ʹ��
	*/
	virtual int Refresh(unsigned Handle ) = 0;
	//!����ǰ��¼(�����ֶ�)
	/*!
	\param Buffer ��������ַ���û�������һ���ض��Ľṹ�塣�ýṹ����ڴ沼����
		���ݿⶨ���ļ�(dbdef�ļ�)��������gdbformat����
	\param BufferSize ����������(�ֽ���)
	\param Count ��¼����
	\return ���ִ�гɹ�������RTDB_S_OK  \n
			��������ֵ�����״̬�붨��
	\sa WriteRecord()
	\warning Ŀǰ��֧���ڷ��ʱ���ʵʱ��ʱʹ�ø÷���������һ��ֻ�ܶ�һ����¼��
	*/
	virtual int ReadRecord(void* Buffer, unsigned BufferSize, unsigned Count = 1) = 0;
	//!д��ǰ��¼(�����ֶ�)
	/*!
	\param Buffer ��������ַ���û�������һ���ض��Ľṹ�塣�ýṹ����ڴ沼����
		���ݿⶨ���ļ�(dbdef�ļ�)��������gdbformat����
	\param BufferSize ����������(�ֽ���)
	\param Count ��¼����
	\return ���ִ�гɹ�������RTDB_S_OK  \n
			��������ֵ�����״̬�붨��
	\sa ReadRecord()
	\warning Ŀǰ��֧���ڷ��ʱ���ʵʱ��ʱʹ�ø÷���������һ��ֻ�ܶ�һ����¼��
	*/
	virtual int WriteRecord(void* Buffer, unsigned BufferSize, unsigned Count = 1) = 0;
	//!�ڼ�¼����������Count���ռ�¼��������¼���α��Ƶ������ӵĵ�һ����¼�ϣ�ͬAppend��
	/*!
	\param Count ��¼����
	\return ���ִ�гɹ�������RTDB_S_OK  \n
			��������ֵ�����״̬�붨��
	\sa Delete()��Append()
	\warning Ŀǰ��֧���ڷ��ʱ���ʵʱ��ʱʹ�ø÷�����
	*/
	virtual int Insert(unsigned Count = 1 ) = 0;
	//!ɾ����ǰ��¼��ʼ��Count����¼����¼���α겻��������λ����ɾ����¼����һ����¼��
	/*!
	\param Count ��¼����
	\return ���ִ�гɹ�������RTDB_S_OK  \n
			��������ֵ�����״̬�붨��
	\sa Insert()��Append()
	\warning Ŀǰ��֧���ڷ��ʱ���ʵʱ��ʱʹ�ø÷�����ִ�и÷����Ժ󣬲�ѯ��¼��������Ч
	*/
	virtual int Delete(unsigned Count = 1 ) = 0;
	//!�ڼ�¼����β������Count���ռ�¼��������¼���α��Ƶ������ӵĵ�һ����¼��
	/*!
	\param Count ��¼����
	\return ���ִ�гɹ�������RTDB_S_OK  \n
			��������ֵ�����״̬�붨��
	\sa Delete()Insert()
	\warning Ŀǰ��֧���ڷ��ʱ���ʵʱ��ʱʹ�ø÷�����
	*/
	virtual int Append(unsigned Count = 1 ) = 0;
	//!ִ�и߼���ѯ����(�򿪼�¼����֧��λ������)
	/*!
	\param Options ��ѯ��������ѯ�����ĸ�ʽΪ"�ֶ��� cmp ֵ"������cmp����Ϊ"=="(����), 
	"!="(������), ">"(����), "<"(С��), ">="(���ڵ���), "<="(С�ڵ���)���ֱȽϲ��������� 
	�����ѯ�������Խ��"&&"(��)����"||"(��)���ж�������ѯ�����Ҫ����ȫ���¼����������
	���Բ����������ø÷���
	\return ���ִ�гɹ�������RTDB_S_OK  \n
	��������ֵ�����״̬�붨��
	ִ�гɹ��Ժ��α궨λ�ڵ�һ����Чλ��֮ǰ��
	����ֱ�ӵ���MoveNext��������¼��ֱ��MoveNext����RTDB_S_FALSE
	\sa GetOptions()
	*/
	virtual int Search2(const char* Options = 0 ) = 0;
};


//!ʵʱ���ֶ�����
#define RTDB_DT_UNKNOWN	GDB_DT_UNKNOWN
#define RTDB_DT_INT	GDB_DT_INT
#define RTDB_DT_FLOAT	GDB_DT_FLOAT
#define RTDB_DT_TIME	GDB_DT_TIME
#define RTDB_DT_STRING	GDB_DT_CHAR

//!ʵʱ���ֶλ������
#define RTDB_USE_READ_BUFFER	1			//ͨ���Ǿ�̬�����ֶΣ�������ʱ����ı䣬Ҫ�ı�Ҳֻ��ͨ�����߸��������
#define RTDB_WRITE_TIMER1_BUFFER	2		//ʹ������1����д����ֶε�ʵʱ����
#define RTDB_WRITE_TIMER2_BUFFER	4		//ʹ������2����д����ֶε�ʵʱ����

/*!
\class IRTDBFieldSchema
\brief �ֶ�ģ�ͷ��ʽӿ�
\example test_fieldschema_local.cpp
*/
class IRTDBFieldSchema : public IICSUnknown 
{
public:
	//!�õ���ǰ�ֶ�����
	/*!
	\param Buffer ��������ַ
	\param BufferSize ����������(�ֽ���)
	\return ���ִ�гɹ�������RTDB_S_OK  \n
			��������ֵ�����״̬�붨��
	*/
	virtual int GetName(char* Buffer, unsigned BufferSize ) = 0;
	//!�õ���ǰ�ֶ�����
	/*!
	\param pType ��������������ͣ��μ������Ͷ���
	\return ���ִ�гɹ�������RTDB_S_OK  \n
			��������ֵ�����״̬�붨��
	*/
	virtual int GetType(unsigned* pType ) = 0;
	//!�õ���ǰ�ֶγ���(�ֽ���)
	/*!
	\param pSize ���������������
	\return ���ִ�гɹ�������RTDB_S_OK  \n
			��������ֵ�����״̬�붨��
	*/
	virtual int GetSize(unsigned* pSize ) = 0;
	//!�жϵ�ǰ�ֶ��Ƿ�Ϊ�����ֶ�
	/*!
	\param pYes ����������Ƿ�����
	\return ���ִ�гɹ�������RTDB_S_OK  \n
			��������ֵ�����״̬�붨��
	*/
	virtual int IsKey(bool* pYes ) = 0;
	//!�жϵ�ǰ�ֶ��Ƿ�������
	/*!
	\param pYes ����������Ƿ�������
	\return ���ִ�гɹ�������RTDB_S_OK  \n
			��������ֵ�����״̬�붨��
	*/
	virtual int IsIndex(bool* pYes ) = 0;
	//!�жϵ�ǰ�ֶ������Ƿ��ͬ��
	/*!
	\param pYes ����������Ƿ�ͬ��
	\return ���ִ�гɹ�������RTDB_S_OK  \n
			��������ֵ�����״̬�붨��
	*/
	virtual int IsSynchronized(bool* pYes ) = 0;
	//!��ȡ�ֶ����Ա�־, ������չ
	/*!
	\param pFlag ����������ֶ����Ա�־
	\return ���ִ�гɹ�������RTDB_S_OK  \n
			��������ֵ�����״̬�붨��
	*/
	virtual int GetFlag(int* pFlag ) = 0;
	//!������Ϣ
	/*!
	\param Buffer ��������ַ
	\param BufferSize ����������(�ֽ���)
	\return ���ִ�гɹ�������RTDB_S_OK  \n
	��������ֵ�����״̬�붨��
	*/
	virtual int GetDescription(char* Buffer, unsigned BufferSize ) = 0;
	//!�����ֶλ������
	/*!
	\param Buffer ��������ַ
	\param BufferSize ����������(�ֽ���)
	\return ���ִ�гɹ�������RTDB_S_OK  \n
	��������ֵ�����״̬�붨��
	*/
	virtual int SetBufferPolicy(int BufferPolicy ) = 0;
};

//!������
#define RTDB_TABLE_UNKNOWN	0	//!<δ֪����
#define RTDB_TABLE_GLOBAL	1	//!<ȫ�ֱ�
#define RTDB_TABLE_CIRTUAL	2	//!<ѭ�����ݱ�
#define RTDB_TABLE_TABLE	4	//!<��ͨ���ݱ�
#define RTDB_TABLE_SYSTEM	8	//!<ϵͳ��

/*!
\class IRTDBTableSchema
\brief ��ģ�ͷ��ʽӿ�
\example test_tableschema_local.cpp
*/
class IRTDBTableSchema : public IICSUnknown
{
public:
	//!�õ���ǰ������
	/*!
	\param Buffer ��������ַ
	\param BufferSize ����������(�ֽ���)
	\return ���ִ�гɹ�������RTDB_S_OK  \n
			��������ֵ�����״̬�붨��
	*/
	virtual int GetName(char* Buffer, unsigned BufferSize ) = 0;
	//!�õ���ǰ������
	/*!
	\param pType ��������������ͣ��μ������Ͷ���,Ŀǰ�û������ȫ����ͨ���ݱ�
	\return ���ִ�гɹ�������RTDB_S_OK  \n
			��������ֵ�����״̬�붨��
	*/
	virtual int GetType(unsigned* pType ) = 0;
	//!�õ���ǰ�������������ܹ����ɵ�����¼��
	/*!
	\param pSize ���������������
	\return ���ִ�гɹ�������RTDB_S_OK  \n
			��������ֵ�����״̬�붨��
	*/
	virtual int GetSize(unsigned* pSize ) = 0;
	//!�õ���ǰ��ӵ�е��ֶθ���
	/*!
	\param pCount ����������ֶθ���
	\return ���ִ�гɹ�������RTDB_S_OK  \n
			��������ֵ�����״̬�붨��
	*/
	virtual int GetFieldCount(unsigned* pCount ) = 0;
	//!�õ�һ���µ��ֶ�ģ�ͷ��ʽӿ�
	/*!
	\param FieldName �ֶ���
	\param ppFieldSchema ���������*ppFieldSchemaָ���´����ֶ�ģ�Ͷ����IRTDBFieldSchema�ӿ�
	\return ���ִ�гɹ�������RTDB_S_OK  \n
			��������ֵ�����״̬�붨��
	*/
	virtual int GetFieldSchema(const char* FieldName, IRTDBFieldSchema** ppFieldSchema ) = 0;
	//!�õ�һ���µ��ֶ�ģ�ͷ��ʽӿ�
	/*!
	\param FieldIndex �ֶ�����˳��ţ���1��ʼ�����ֵ==�ֶεĸ���
	\param ppFieldSchema ���������*ppFieldSchemaָ���´����ֶ�ģ�Ͷ����IRTDBFieldSchema�ӿ�
	\return ���ִ�гɹ�������RTDB_S_OK  \n
			��������ֵ�����״̬�붨��
	*/
	virtual int GetFieldSchema(unsigned FieldIndex, IRTDBFieldSchema** ppFieldSchema ) = 0;
	//!��ȡ��������Ϣ
	/*!
	\param Buffer ��������ַ
	\param BufferSize ����������(�ֽ���)
	\return ���ִ�гɹ�������RTDB_S_OK  \n
	��������ֵ�����״̬�붨��
	*/
	virtual int GetDescription(char* Buffer, unsigned BufferSize ) = 0;
};

/*!
\class IRTDBDatabase
\brief ���ݿ������ʽӿ�
\example test_database_local.cpp
*/
class IRTDBDatabase : public IICSUnknown
{
public:
	//!�����ݿ�
	/*!
	\param DBName ʵʱ���ݿ�����
	\param MiscParams ʵʱ���޶���������ʽΪ"App=xx;Fam=xx", Ĭ��Ϊ"App��ics8000;fam��xuji"
	\return ���ִ�гɹ�������RTDB_S_OK  \n
			��������ֵ�����״̬�붨��
	\sa GetName(), GetMiscParams()
	*/
	virtual int Open(const char* DBName, const char* MiscParams = 0 ) = 0;
	//!�رյ�ǰ���ݿ�(��ʱ������ʵʱ�����˳�ʱ�Զ��ر�)
	/*!
	\return ���ִ�гɹ�������RTDB_S_OK  \n
			��������ֵ�����״̬�붨��
	\sa Open(), IsOpened()
	*/
	virtual int Close() = 0;
	//!��ǰʵʱ���Ƿ��ڴ�״̬
	/*!
	\param pYes ������������*pYes == true�����ݿ⴦�ڴ�״̬\n
						  ���*pYes == false�����ݿ⴦�ڹر�״̬				  
	\return ���ִ�гɹ�������RTDB_S_OK  \n
			��������ֵ�����״̬�붨��
	\sa Open(), Close()
	*/
	virtual int IsOpened( bool *pYes ) = 0;
	//!�õ���ǰ���ݿ�����
	/*!
	\param Buffer ��������ַ
	\param BufferSize ����������(�ֽ���)
	\return ���ִ�гɹ�������RTDB_S_OK  \n
			��������ֵ�����״̬�붨��
	\sa Open()
	*/
	virtual int GetName(char* Buffer, unsigned BufferSize ) = 0;
	//!�õ���ǰ���ݿ��޶�����
	/*!
	\param Buffer ��������ַ
	\param BufferSize ����������(�ֽ���)
	\return ���ִ�гɹ�������RTDB_S_OK  \n
			��������ֵ�����״̬�붨��
	\sa Open()
	*/
	virtual int GetMiscParams(char* Buffer, unsigned BufferSize ) = 0;
	//!�õ���ǰ���ݿ�ӵ�е����ݱ�ĸ���
	/*!
	\param pCount �����������ĸ���
	\return ���ִ�гɹ�������RTDB_S_OK  \n
			��������ֵ�����״̬�붨��
	\sa Open()
	*/
	virtual int GetTableCount(unsigned* pCount) = 0;
	//!�õ���ģ�ͷ��ʽӿ�
	/*!
	\param TableName ������
	\param ppTableSchema ���������*ppTableSchemaָ���´�����ģ�Ͷ����IRTDBTableSchema�ӿ�
	\return ���ִ�гɹ�������RTDB_S_OK  \n
			��������ֵ�����״̬�붨��
	*/	
	virtual int GetTableSchema(const char* TableName, IRTDBTableSchema** ppTableSchema ) = 0;
	//!�õ���ģ�ͷ��ʽӿ�
	/*!
	\param TableIndex ������˳��ţ���1��ʼ�����ֵ==��ĸ���
	\param ppTableSchema ���������*ppTableSchemaָ���´�����ģ�Ͷ����IRTDBTableSchema�ӿ�
	\return ���ִ�гɹ�������RTDB_S_OK  \n
			��������ֵ�����״̬�붨��
	*/
	virtual int GetTableSchema(unsigned TableIndex, IRTDBTableSchema** ppTableSchema ) = 0;
	//!�õ�һ���µı����ݲ�ѯ�ӿ�
	/*!
	\param TableName ������
	\param ppQuery ���������*ppQueryָ���´�����ѯ�����IRTDBQuery�ӿ�
	\return ���ִ�гɹ�������RTDB_S_OK  \n
			��������ֵ�����״̬�붨��
	*/	
	virtual int GetQuery(const char* TableName, IRTDBQuery** ppQuery ) = 0;
	//!�õ�һ���µı����ݲ�ѯ�ӿ�
	/*!
	\param TableIndex ������˳��ţ���1��ʼ�����ֵ==��ĸ���
	\param ppQuery ���������*ppQueryָ���´�����ѯ�����IRTDBQuery�ӿ�
	\return ���ִ�гɹ�������RTDB_S_OK  \n
			��������ֵ�����״̬�붨��
	*/
	virtual int GetQuery(unsigned TableIndex, IRTDBQuery** ppQuery ) = 0;
	//!������ݿ�
	/*!
	\return ���ִ�гɹ�������RTDB_S_OK  \n
			��������ֵ�����״̬�붨��
	*/
	virtual int Initialize() = 0;
	//!�ؽ��ֶ�����
	/*!
	\return ���ִ�гɹ�������RTDB_S_OK  \n
			��������ֵ�����״̬�붨��
	*/
	virtual int RebuildFieldIndex(const char* FieldName, const char* TableName) = 0;
	//!�ؽ�������
	/*!
	\return ���ִ�гɹ�������RTDB_S_OK  \n
			��������ֵ�����״̬�붨��
	*/
	virtual int RebuildTableIndex(const char* TableName) = 0;
	//!�ؽ���������
	/*!
	\return ���ִ�гɹ�������RTDB_S_OK  \n
			��������ֵ�����״̬�붨��
	*/
	virtual int RebuildAllIndex() = 0;
	//!ˢ���ڲ����壬���߸�����ɺ����
	/*!
	\return ���ִ�гɹ�������RTDB_S_OK  \n
	��������ֵ�����״̬�붨��
	*/
	virtual int Refresh() = 0;
};

//!Ҫ�����������
#define RTDB_REQUIRE_ANY		1
#define RTDB_REQUIRE_PRIMARY	2
#define RTDB_REQUIRE_STANDBY	3

//!����״̬�ı�֪ͨ���ص�����ԭ�Ͷ���
/*!
\param nStatus ��ǰ����״̬ \n ������ӽ�������nStatus == RTDB_S_CONNECTED 
	\n��������жϣ���nStatus == RTDB_S_DISCONNECTED

\sa IRTDBConnection::SetConnectCallback()
*/
typedef void (*ConnectCB)(int nStatus );

/*!
\class IRTDBConnection
\brief ʵʱ�����Ӷ������ӿ�
\example test_rtdbconnection.cpp
*/
class IRTDBConnection : public IICSUnknown
{
public:
	//!����Զ�̷�������ַ,������ӱ��ط�����������Ҫ����SetHostName��������NULLΪ��������
	/*!
	\param HostName Զ�̷�������ַ����ʽΪ"Host1=192.168.1.18,192.168.4.230;Host2=192.168.1.109,192.168.4.44"
	\return ���ִ�гɹ�������RTDB_S_OK  \n
			��������ֵ�����״̬�붨��
	\sa GetHostName()	
	*/
	virtual int SetHostName(const char* HostName ) = 0;
	//!��������ʵʱ���ݿ���û���
	/*!
	\param UserName �û���
	\return ���ִ�гɹ�������RTDB_S_OK  \n
			��������ֵ�����״̬�붨��
	\sa GetUserName()
	*/
	virtual int SetUserName(const char* UserName ) = 0;
	//!�����û�����
	/*!
	\param Password �û�����
	\return ���ִ�гɹ�������RTDB_S_OK  \n
			��������ֵ�����״̬�붨��
	\sa GetPassword()
	*/
	virtual int SetPassword(const char* Password ) = 0;
	//!����Զ�̷������ļ����˿ں�
	/*!
	\param MiscParams Զ�̷�������socket�˿ںţ���ʽΪ"RequiredServer=xxx;Socket=xxxx",Ĭ�϶˿ں�Ϊ8040
		���RequiredServer == 1, ������ʵʱ�������������״̬��
		���RequiredServer == 2, �Զ���������������
		��� RequiredServer == 3, �Զ����ӱ���������
	\return ���ִ�гɹ�������RTDB_S_OK  \n
			��������ֵ�����״̬�붨��
	\sa GetMiscParams()
	*/
	virtual int SetMiscParams(const char* MiscParams ) = 0;
	//!��������״̬�ı�֪ͨ�ص�����
	/*!
	\param Function �ص�����ָ��
	\return ���ִ�гɹ�������RTDB_S_OK  \n
			��������ֵ�����״̬�붨��
	\sa ConnectCB
	*/
	virtual int SetConnectCallback(ConnectCB Function) = 0;
	//!�������ݿ������
	/*!
	\param ConnectString �����ַ�������ʽΪ"HostName=xx;UserName=xx;Password=xx;MiscParams=xx"
	\return ���ִ�гɹ�������RTDB_S_OK  \n
			��������ֵ�����״̬�붨��
	\sa SetHostName(), SetUserName(), SetPassword(), SetMiscParams(), SetConnectCallback()
	*/
	virtual int Connect(const char* ConnectString) = 0;
	//!�������ݿ������
	/*!
	\return ���ִ�гɹ�������RTDB_S_OK  \n
			��������ֵ�����״̬�붨��
	\sa SetHostName(), SetUserName(), SetPassword(), SetMiscParams(), SetConnectCallback()
	*/
	virtual int Connect() = 0;
	//!�Ͽ����ݿ������������ʵʱ�ⲻ�ܶϿ�����
	/*!
	\return ���ִ�гɹ�������RTDB_S_OK  \n
			��������ֵ�����״̬�붨��
	\sa Connect(), SetConnectCallback()
	*/
	virtual int Disconnect() = 0;
	//!��ǰ�����Ƿ�������״̬
	/*!
	\param pYes ������������*pYes == true,�����ӳɹ�����������ʧ��
	\return ���ִ�гɹ�������RTDB_S_OK  \n
			��������ֵ�����״̬�붨��
	\sa Connect()
	*/
	virtual int IsConnected( bool* pYes ) = 0;
	//!ȡ����ǰ���õ�Զ�̷�������ַ
	/*!
	\param Buffer ��������ַ
	\param BufferSize ���������ȣ��ֽ�����
	\return ���ִ�гɹ�������RTDB_S_OK  \n
			��������ֵ�����״̬�붨��
	\sa SetHostName()
	*/
	virtual int GetHostName(char* Buffer, unsigned BufferSize ) = 0;
	//!ȡ����ǰ���õ�Զ�̷������û���,����windows�ϱ������ֳ�ͻ���⣬��GetUserName����ΪGetUserNameStr
	/*!
	\param Buffer ��������ַ
	\param BufferSize ���������ȣ��ֽ�����
	\return ���ִ�гɹ�������RTDB_S_OK  \n
			��������ֵ�����״̬�붨��
	\sa SetUserName()
	*/
	virtual int GetUserNameStr(char* Buffer, unsigned BufferSize ) = 0;
	//!ȡ����ǰ���õ��û���������
	/*!
	\param Buffer ��������ַ
	\param BufferSize ���������ȣ��ֽ�����
	\return ���ִ�гɹ�������RTDB_S_OK  \n
			��������ֵ�����״̬�붨��
	\sa SetPassword()
	*/
	virtual int GetPassword(char* Buffer, unsigned BufferSize ) = 0;
	//!ȡ����ǰ���õ����Ӷ˿ں�
	/*!
	\param Buffer ��������ַ
	\param BufferSize ���������ȣ��ֽ�����
	\return ���ִ�гɹ�������RTDB_S_OK  \n
			��������ֵ�����״̬�붨��
	\sa SetMiscParams()
	*/
	virtual int GetMiscParams(char* Buffer, unsigned BufferSize ) = 0;
	//!���һ���µ����ݿ����
	/*!
	\param ppDatabase *ppDatabaseָ���´��������IRTDBDatabase�ӿ�
	\return ���ִ�гɹ�������RTDB_S_OK  \n
			��������ֵ�����״̬�붨��
	\sa SetMiscParams()
	*/
	virtual int GetDatabase(IRTDBDatabase** ppDatabase ) = 0;
	//!��ʼһ���µ�����	
	/*!
	���ø÷����ɹ��Ժ����е��޸�ʵʱ������������ڲ��������н���
	\return ���ִ�гɹ�������RTDB_S_OK  \n
			��������ֵ�����״̬�붨��
	\sa CommitTransaction(), RollbackTransaction()
	*/
	virtual int BeginTrasaction() = 0;
	//!�ύ��ǰ����
	/*!
	���ϴε���BeginTransaction�������޸Ĳ���������д��ʵʱ����
	\return ���ִ�гɹ�������RTDB_S_OK  \n
			��������ֵ�����״̬�붨��
	\sa BeginTrasaction()
	*/
	virtual int CommitTransaction() = 0;
	//!�ع���ǰ����
	/*!
	���ϴε���BeginTransaction�������޸Ĳ����������ָ�
	\return ���ִ�гɹ�������RTDB_S_OK  \n
			��������ֵ�����״̬�붨��
	\sa BeginTrasaction()
	*/
	virtual int RollbackTransaction() = 0;
	//!��ͣ���߻ָ�ͬ������
	/*!
	�������ͬ������������gaia��֤�û������������Ͻ��еĸ���ʵʱ����������ڱ��������������Ա���һ��
	\param Yes ���ΪYes == true,��ֹͣ˫��ͬ������\n
			   ���ΪYes == false, ������˫��ͬ������
	\return ���ִ�гɹ�������RTDB_S_OK  \n
			��������ֵ�����״̬�붨��	
	*/
	virtual int DisableSyncronize(bool Yes) = 0;
	//!�Ƿ�����ʵʱ�⻺�����
	/*!
	\param Yes ���ΪYes == true,ʹ��ʵʱ�⻺�����\n
	���ΪYes == false, ��ʹ��ʵʱ�⻺����ƣ�Ĭ�ϣ�
	\return ���ִ�гɹ�������RTDB_S_OK  \n
	��������ֵ�����״̬�붨��	
	*/
	virtual int UseRtdbBuffer(bool yes) = 0;
	//!����ʵʱ�⻺������������߸�������Ժ���ã�
	/*!
	\return ���ִ�гɹ�������RTDB_S_OK  \n
	��������ֵ�����״̬�붨��	
	*/
	virtual int UpdateRtdbBuffer() = 0;
	
};

//!״̬�붨��
#define RTDB_S_OK 0			//!<�ɹ�
#define RTDB_S_FALSE -1		//!<ʧ��
#define RTDB_S_INVALID_PARAM	10001	//!<��Ч�Ĳ���
#define RTDB_S_NO_ENOUGH_BUFFER	10002	//!<����������
#define RTDB_S_CONNECTED	10003	//!<���ӽ���
#define RTDB_S_DISCONNECTED	10004	//!<�����ж�
#define RTDB_S_RECONNECT	10005	//!<�ظ�����
#define RTDB_S_NOMEMORY		10006	//!<�ڴ治��
#define RTDB_S_REOPEN		10007	//!<�ظ���
#define RTDB_S_NOTOPEN		10008	//!<���ݿ�û�д�
#define RTDB_S_NOTSURPPORT	10009	//!<��֧�ֵĲ���
#define RTDB_S_NOTFOUND		10010	//!<û���ҵ�
#define RTDB_S_TIMEOUT		10011	//!<��ʱ
#define RTDB_S_OUTOFRANGE	10012	//!<Խ��
#define RTDB_S_ROLENOTMATCH	10013	//!<��������������ɫ������Ҫ��
#define RTDB_S_VERSION_INCOMPATIBLE 10014 //!<Զ�̷���ͨ��Э�鲻����
#define RTDB_S_INTERNAL_ERROR 10015 //!<Զ�̷���ͨ��Э�鲻����
#endif
