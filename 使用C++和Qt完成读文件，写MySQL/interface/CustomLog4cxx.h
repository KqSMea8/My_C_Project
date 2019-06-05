// WriteLog.h: interface for the CWRITELOG class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_WRITELOG_H__2174FC90_C9B8_4AD6_9D01_5C8352518E4C__INCLUDED_)
#define AFX_WRITELOG_H__2174FC90_C9B8_4AD6_9D01_5C8352518E4C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#pragma warning(disable :4231 4660 4786)

//#define LOG4CXX_STATIC

#include <log4cxx/logger.h>
#include <log4cxx/propertyconfigurator.h>
#include <log4cxx/xml/domconfigurator.h> 
#include <log4cxx/helpers/synchronized.h>
#include <log4cxx/helpers/mutex.h>
#include <log4cxx/helpers/pool.h>
#include <log4cxx/patternlayout.h>
#include <log4cxx/rollingfileappender.h>
#include <stdarg.h>
#include <qmutex.h>
#include <string>
#include <qlibrary.h>
#include <qstring.h>
#include <qtextstream.h> 

using namespace log4cxx;
using namespace log4cxx::helpers;

#ifdef LOG4CXX_STATIC
# ifdef _DEBUG
#  pragma comment(lib, "log4cxxSd.lib")
#  pragma comment(lib, "apr-1Sd.lib")
#  pragma comment(lib, "aprutil-1Sd.lib")
#  pragma comment(lib, "ws2_32.lib")
#  pragma comment(lib, "Mswsock.lib")
# else
#  pragma comment(lib, "log4cxxS.lib")
#  pragma comment(lib, "apr-1S.lib")
#  pragma comment(lib, "aprutil-1S.lib")
#  pragma comment(lib, "ws2_32.lib")
#  pragma comment(lib, "Mswsock.lib")
# endif
#  pragma comment(lib,"odbc32.lib")
#else
# ifdef _DEBUG
#  pragma comment(lib, "log4cxxd.lib")
# else
#  pragma comment(lib, "log4cxx.lib")
# endif
#endif


class CWRITELOG;

#define  OUTPUT_TYPE_TRACE		1
#define  OUTPUT_TYPE_DEBUG		2
#define  OUTPUT_TYPE_INFO		3
#define  OUTPUT_TYPE_WARN       4
#define  OUTPUT_TYPE_ERROR      5
#define  OUTPUT_TYPE_FATAL		6

#define LOG4CXX_INIT(X,Y) \
    do { \
     	CWRITELOG * p = CWRITELOG::instance(X,Y); \
	}  while(0)
  
#define LOGXJ_TRACE(X) \
	do {\
		CWRITELOG *Log__=CWRITELOG::instance(); \
		if(Log__->GetLogger()->isTraceEnabled())\
		{ \
		    Log__->SetType(OUTPUT_TYPE_TRACE); \
			Log__->FormatLog X;\
		} \
	}while(0)

#define LOGXJ_DEBUG(X) \
  do { \
    CWRITELOG *Log___ = CWRITELOG::instance (); \
	if(Log___->GetLogger()->isDebugEnabled())\
	{\
		Log___->SetType(OUTPUT_TYPE_DEBUG); \
		Log___->FormatLog X; \
	}\
  } while (0)

#define LOGXJ_INFO(X) \
  do { \
    CWRITELOG *Log___ = CWRITELOG::instance (); \
	if(Log___->GetLogger()->isInfoEnabled())\
	{\
		Log___->SetType(OUTPUT_TYPE_INFO); \
		Log___->FormatLog X; \
	}\
  } while (0)

#define LOGXJ_WARN(X) \
  do { \
    CWRITELOG *Log___ = CWRITELOG::instance (); \
	if(Log___->GetLogger()->isWarnEnabled())\
	{\
		Log___->SetType(OUTPUT_TYPE_WARN); \
		Log___->FormatLog X; \
	}\
  } while (0)

#define LOGXJ_ERROR(X) \
  do { \
   CWRITELOG *Log___ = CWRITELOG::instance (); \
   if(Log___->GetLogger()->isErrorEnabled())\
	{\
		Log___->SetType(OUTPUT_TYPE_ERROR); \
		Log___->FormatLog X; \
	}\
  } while (0)

#define LOGXJ_FATAL(X) \
  do { \
   CWRITELOG *Log___ = CWRITELOG::instance (); \
   if(Log___->GetLogger()->isFatalEnabled())\
	{\
		Log___->SetType(OUTPUT_TYPE_FATAL); \
		Log___->FormatLog X; \
	}\
  } while (0)

#define LOGXJ_HEX_INFO(X) \
  do { \
    CWRITELOG *Log___ = CWRITELOG::instance (); \
	if(Log___->GetLogger()->isInfoEnabled())\
	{\
		Log___->SetType(OUTPUT_TYPE_INFO); \
		Log___->log_hexdump X; \
	}\
  } while (0)

#define LOGXJ_HEX_TRACE(X) \
  do { \
   CWRITELOG *Log___ = CWRITELOG::instance (); \
   if(Log___->GetLogger()->isTraceEnabled())\
	{\
		Log___->SetType(OUTPUT_TYPE_TRACE); \
		Log___->log_hexdump X; \
	}\
  } while (0)

#define LOGXJ_HEX_DEBUG(X) \
  do { \
    CWRITELOG *Log___ = CWRITELOG::instance (); \
	if(Log___->GetLogger()->isDebugEnabled())\
	{\
		Log___->SetType(OUTPUT_TYPE_DEBUG); \
		Log___->log_hexdump X; \
	}\
  } while (0)

#define LOGXJ_HEX_WARN(X) \
  do { \
    CWRITELOG *Log___ = CWRITELOG::instance (); \
	if(Log___->GetLogger()->isWarnEnabled())\
	{\
		Log___->SetType(OUTPUT_TYPE_WARN); \
		Log___->log_hexdump X; \
	}\
  } while (0)


typedef void (*pMsgFun)(LoggerPtr, char * ,int );  //通道ID,通道状态

/*********************************************************************************/
/* 该类仅为方便Log4cxx读取配制信息生成日志的宏实现,其它情况没有做测试,请慎用。   */
/* 非读取配制信息的使用方式，见Log4cxx说明文档			    					 */
/*  功能:通过宏定义方便实现,格式化和十六制的输出								 */
/*  日期:2008.4.14	                                                             */
/*  修改:2008.7.12  增加线程安全保护以及配置文件是否已经配置功能                 */
/*  修改:2009.3.19  增加宏定义输出类名称以适应unix下动态库的不同名需求           */
/*  作者:xys																	 */
/*********************************************************************************/


class CWRITELOG  
{

public:
	static CWRITELOG * instance( char * szName = 0,char * szConfig = 0 )
	{
		if(0 == m_spInstance)
		{
			if (szName)
			{
				
				m_spInstance = new CWRITELOG(szName);
				
				if (szConfig)
				{
					m_spInstance->DoConfig(szConfig);
				}
				
			}else
			{
				m_spInstance = new CWRITELOG();
			}
		}
		
		return m_spInstance;
		
	}


	void FormatLog(const char* format, ...)
	{
		QMutexLocker locker( &m_mutex);

		va_list arg;
		char buf[LOG_LENGTH_MAX+1];
		memset(buf,0,LOG_LENGTH_MAX+1);
		va_start(arg, format);
#ifdef WIN32
		_vsnprintf(buf, sizeof(buf)-1,format, arg);
#else
		vsnprintf(buf, sizeof(buf)-1,format, arg);
#endif
		va_end(arg);
	
		if (m_pMsgFun ==NULL)
		{
			m_pMsgFun =(pMsgFun)m_lib.resolve("OnMsgComing");
		}

		if (m_pMsgFun)
		{
			m_pMsgFun(m_logger,buf,m_nType);

		}else
		{

		}

		return;

		switch(m_nType)
		{
		case OUTPUT_TYPE_TRACE:
			m_logger->trace(buf);
			break;
		case OUTPUT_TYPE_DEBUG:
			m_logger->debug(buf);
			break;
		case OUTPUT_TYPE_INFO:
			m_logger->info(buf);
			break;
		case OUTPUT_TYPE_WARN:
			m_logger->warn(buf);
			break;
		case OUTPUT_TYPE_ERROR:
			m_logger->error(buf);
			break;
		case OUTPUT_TYPE_FATAL:
			m_logger->fatal(buf);
			break;
		default:
			break;
		}
		
	}

	void SetType( int nType )
	{
		QMutexLocker locker( &m_mutex);
		m_nType = nType;	
	}

	int log_hexdump( const char *buffer, size_t size, const char *text = 0 )
	{
		QMutexLocker locker( &m_Hexmutex);
		unsigned char * tmpBuf =(unsigned char*)buffer;
		QString szHex,tmp;
		
		if (size > 256)
		{
			size = 256;
		}

		if (text)
		{
			FormatLog(text);
		}

		for(int i =0;i< size; i++)
		{
			szHex += tmp.sprintf(" %02x ",tmpBuf[i]);
		}

		//FormatLog(szHex.toUpper().ascii());
		FormatLog(qPrintable(szHex.toUpper()));

		return 0 ;

		
	}

	int log_hexdump( const unsigned char *buffer, size_t size, const char *text /*= 0*/ )
	{
		return log_hexdump((char*)buffer,size,text);
		
	}

    void DoConfig( char *szConfig )
	{
		if (m_repository && !m_repository->isConfigured())
		{
			if (strstr(szConfig,".xml"))
			{
				log4cxx::xml::DOMConfigurator::configureAndWatch(szConfig,60*1000);
			}else
			{
				PropertyConfigurator::configureAndWatch(szConfig);
			}
		}
		
		VersionInfo();
	}

	LoggerPtr GetLogger()
	{
		return m_logger;
	}

	CWRITELOG():m_lib("ControlLog4cxx")
	{
		m_logger = Logger::getLogger("xjLog");
		m_nType = OUTPUT_TYPE_TRACE;
		m_repository = m_logger->getLoggerRepository();
		m_szLogName = new char[6];
		strcpy(m_szLogName,"xjLog");
		m_pMsgFun = NULL;
	}

	CWRITELOG( char * szName ) :m_lib("ControlLog4cxx")
	{
		m_logger= Logger::getLogger(szName);
		m_nType = OUTPUT_TYPE_TRACE;
		m_repository = m_logger->getLoggerRepository();
		m_szLogName = new char[strlen(szName)+1];
		strcpy(m_szLogName,szName);
		m_pMsgFun = NULL;
	}	
	virtual ~CWRITELOG(){;}

	void VersionInfo()
	{
        QString str;
        //QTextOStream( &str ) << "模块 "<< m_szLogName <<"  编译时间为 "<<__DATE__<<"  "<<__TIME__ ;
        QTextStream( &str ) << "modle  "<< m_szLogName <<"CompileTime "<<__DATE__<<"  "<<__TIME__ ;
		SetType(OUTPUT_TYPE_DEBUG);
		//FormatLog(str.ascii());
		FormatLog(qPrintable(str));
	}

private:

	pMsgFun m_pMsgFun;
	QLibrary m_lib;
	LoggerPtr m_logger;
	int m_nType;
	char * m_szLogName;
    static CWRITELOG *m_spInstance;
	log4cxx::spi::LoggerRepositoryPtr m_repository;
	QMutex  m_mutex,m_Hexmutex;
};



#endif // !defined(AFX_WRITELOG_H__2174FC90_C9B8_4AD6_9D01_5C8352518E4C__INCLUDED_)
