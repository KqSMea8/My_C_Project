// sysinfo.cpp: implementation of the PVSYS class.
//
//////////////////////////////////////////////////////////////////////

#include "sysconfig.h"
#include "staticvariable.h"
#include <qdatetime.h>
#include <qfile.h>
#include <q3textstream.h>
//Added by qt3to4:
#include <QSqlQuery>
#include <QVariant>
#include "../../include/other/icssettingslib.h"
#include <fstream>
#include <iostream>
#include "writelog.h" // for WriteLogToFile

#include "defs.h"

using namespace std;

#define PATH_SECTION_HISDB1  "plat_global/database/hisdb/hisdb1"  //历史库路径
#define PATH_SECTION_HISDB2  "plat_global/database/hisdb/hisdb2"
#define PATH_SECTION_MODELDB  "plat_global/database/modeldb"  //配置库路径

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

SysConfig::SysConfig()
 {

}

SysConfig::~SysConfig()
{

}
bool SysConfig::ReadModelDBCfg()
{
	bool bSuc = false;
	ifstream iscsettingFile;

	QFile file("../../ini/icssetting.xml");

	if(file.exists())
	{	
		bSuc = true;
	}
	else
	{
		iscsettingFile.open("../ini/icssetting.xml");
		WriteLogToFile(LOGFILENAME, "../ini/icssetting.xml  !!  \n");
		bSuc = true;
	}

	if(bSuc==true)
	{
		//read configurations from icssetting.xml 
		IICSSettings* pSettings = 0;
		CICSSettings libICSSetting;
		pSettings = libICSSetting.Self();
		if(pSettings)
		{
			char buf[BUF_LEN_MAX];
			if(true == pSettings->SetCurrentSectionPath(PATH_SECTION_MODELDB))//设置当前操作的节点路径，设置完毕后，以后操作都基于本节点进行
			{
				if(pSettings->ItemReadString("driver",buf, BUF_LEN_MAX))			//virtual bool ItemReadString(const char* item, char * sValueOut,int iSizeIn ) = 0;
				{															//\brief 重载函数，以字符串的方法设置配置项的值 
					g_dbdriver = buf;								    //@param[in] item 配置项名称
					g_Model.dbdriver = buf;								//@param[in] val  要设置的值
				}
																			//\return 设置成功返回 true 设置失败返回 false
				if(pSettings->ItemReadString("username", buf, BUF_LEN_MAX))
				{
					g_Model.dbuser = buf;
					printf("clw：g_Model.dbuser = %s\n", buf);
				}	
				else
					printf("clw：读不到icssetting的username等信息！");	
				if(pSettings->ItemReadString("password", buf, BUF_LEN_MAX))	
				{
					g_Model.dbpassword = buf;
					printf("clw：g_Model.dbpassword = %s\n", buf);
				}
				if(pSettings->ItemReadString("sername", buf, BUF_LEN_MAX))	
				{
					g_Model.dbname = buf;
					printf("clw：g_Model.dbname = %s\n", buf);
				}
				if(pSettings->ItemReadString("hostname", buf, BUF_LEN_MAX))	
				{
					g_Model.strIP = buf;
					printf("clw：g_Model.strIP = %s\n", buf);
				}
				iscsettingFile.close();
				iscsettingFile.clear();
				bSuc = true;
			}
			else bSuc = false;
		}
		else bSuc = false;

		iscsettingFile.close();
		iscsettingFile.clear();
	}
	return bSuc;
}

//读信息
bool SysConfig::ReadConfigInfo()
{
	bool bSuc = false;
	ifstream iscsettingFile;

	QFile file("../../ini/icssetting.xml");
	
	if(file.exists())
	{	
		bSuc = true;
	}
	else
	{
		iscsettingFile.open("../ini/icssetting.xml");
		WriteLogToFile(LOGFILENAME, "../ini/icssetting.xml  !!  \n");
		bSuc = true;
	}

	if(bSuc==true)
	{
		//read configurations from icssetting.xml 
		IICSSettings* pSettings = 0;
		CICSSettings libICSSetting;
		pSettings = libICSSetting.Self();
		if(pSettings)
		{
			char buf[BUF_LEN_MAX];
			if(true == pSettings->SetCurrentSectionPath(PATH_SECTION_HISDB1))//设置当前操作的节点路径，设置完毕后，以后操作都基于本节点进行
			{
				if(pSettings->ItemReadString("driver", buf, BUF_LEN_MAX))			//virtual bool ItemReadString(const char* item, char * sValueOut,int iSizeIn ) = 0;
				{															//\brief 重载函数，以字符串的方法设置配置项的值 
					g_dbdriver = buf;								    //@param[in] item 配置项名称
					g_His1.dbdriver = buf;								//@param[in] val  要设置的值
				}														//\return 设置成功返回 true 设置失败返回 false
				if(pSettings->ItemReadString("username", buf, BUF_LEN_MAX))
				{
					g_His1.dbuser = buf;
					printf("clw：g_His1.dbuser = %s\n", buf);
				}	
				else
					printf("clw：读不到icssetting的username等信息！");	
				if(pSettings->ItemReadString("password", buf, BUF_LEN_MAX))	
				{
					g_His1.dbpassword = buf;
					printf("clw：g_His1.dbpassword = %s\n", buf);
				}
				if(pSettings->ItemReadString("sername", buf, BUF_LEN_MAX))	
				{
					g_His1.dbname = buf;
					printf("clw：g_His1.dbname = %s\n", buf);
				}
				if(pSettings->ItemReadString("hostname", buf, BUF_LEN_MAX))	
				{
					g_His1.strIP = buf;
					printf("clw：g_His1.strIP = %s\n", buf);
				}

				iscsettingFile.close();
				iscsettingFile.clear();
				bSuc = true;
			}
			else bSuc = false;
		}
		else bSuc = false;

		iscsettingFile.close();
		iscsettingFile.clear();
	}
	return bSuc;
}

bool SysConfig::ConnectDatabas()
{
	bool isConn = true;
	if(ReadConfigInfo())
	{
		QString curData = QDateTime::currentDateTime().toString("yyyyMMddhhmmss");//读到当前时间
		g_pDB_His1 = QSqlDatabase::addDatabase(g_His1.dbdriver,"HIS1"+curData );
		//设置数据库联接的基本参数
		
		g_pDB_His1.setUserName(g_His1.dbuser);
		g_pDB_His1.setPassword(g_His1.dbpassword);
		//if(strcmp(g_dbdriver, "QMYSQL3") == 0)

		//printf("clw：g_dbdriver.left(4)=%s\n", g_dbdriver.left(4).toLatin1().data()) ;
		//printf("clw：g_dbdriver.left(4) == QOCI 是否为真%d\n",  g_dbdriver.left(4) == "QOCI");

		if(g_dbdriver.left(4) == "QOCI")  //clw add 20190603：for 达梦 Database；
		{
		//if(g_His1.dbdriver.toStdString().substr(0,4) == "QOCI")
			g_pDB_His1.setDatabaseName(g_His1.strIP);
			g_pDB_His1.setPort(5236);
			printf("clw：达梦数据库，setDatabaseName(%s)\n", g_His1.strIP.toLatin1().data());
		}
		else if(g_dbdriver.left(6) == "QMYSQL")
		{
			g_pDB_His1.setDatabaseName(g_His1.dbname);
			g_pDB_His1.setHostName(g_His1.strIP);
			printf("clw：mysql数据库，setDatabaseName(%s)\n", g_His1.dbname.toLatin1().data());
		}

		if ( !g_pDB_His1.open() )
		{
			printf("clw：数据库打开失败！\n");
			WriteLogToFile(LOGFILENAME, "clw：数据库打开失败！\n");
			isConn = false ;
		}
		else
		{
#ifdef Q_OS_WIN
			g_pDB_His1.exec("SET NAMES 'GBK'");
#endif

#ifdef Q_OS_LINUX
			g_pDB_His1.exec("SET NAMES 'UTF8'");
#endif
		}
		
	} 
	else
		isConn = false;

	return isConn;
}

bool SysConfig::ReConnectDatabas()
{
	//(1)先删除连接
	g_pDB_His1.close();

	//(2)连接
	bool ConnectCondition =true;
	ConnectCondition = ConnectDatabas();
	return ConnectCondition;
}

void SysConfig::DisconnectDatabase()
{
	g_pDB_His1.close();
// 	QString name;
// 	if(g_pDB_His1.isOpen())
// 	{
// 		name = g_pDB_His1.databaseName();
// 		QSqlDatabase::removeDatabase(name);
// 	}
}


//连接配置库
bool SysConfig::ConnectModelDB()
{
	bool isConn = true;
	if (g_pDB_Model.isOpen())
	{
		isConn =true;
	}
	else 
	{
		if ( !g_pDB_Model.open() )
		{
			if(ReadModelDBCfg())
			{
				QString curData = QDateTime::currentDateTime().toString("yyyyMMddhhmmss");//读到当前时间
				g_pDB_Model = QSqlDatabase::addDatabase(g_Model.dbdriver,"MODEL"+curData );
				//设置数据库联接的基本参数
				g_pDB_Model.setUserName(g_Model.dbuser);
				g_pDB_Model.setPassword(g_Model.dbpassword);
				//if(strcmp(g_dbdriver, "QMYSQL3") == 0)  

				if(g_dbdriver.left(4) == "QOCI")
				{
					//if(g_His1.dbdriver.toStdString().substr(0,4) == "QOCI")
					g_pDB_Model.setDatabaseName(g_His1.strIP);
					g_pDB_Model.setPort(5236);
					printf("clw：达梦数据库，setDatabaseName(%s)\n", g_His1.strIP.toLatin1().data());
				}
				else if(g_dbdriver.left(6) == "QMYSQL")
				{
					g_pDB_Model.setDatabaseName(g_His1.dbname);
					g_pDB_Model.setHostName(g_His1.strIP);
					printf("clw：mysql数据库，setDatabaseName(%s)\n", g_His1.dbname.toLatin1().data());
				}

				if ( !g_pDB_Model.open() )
				{
					printf("clw：数据库打开失败！\n");
					WriteLogToFile(LOGFILENAME, "clw：数据库打开失败！\n");
					isConn = false ;
				}
				else
				{
#ifdef Q_OS_WIN
					g_pDB_His1.exec("SET NAMES 'GBK'");
#endif

#ifdef Q_OS_LINUX
					g_pDB_His1.exec("SET NAMES 'UTF8'");
#endif
				}
			} 
			else
				isConn = false;
			
		}	
	}

	return isConn;
}

//断开配置库连接
void SysConfig::DisconnectModelDB()
{
	g_pDB_Model.close();

//  	QString name;
//  	if(g_pDB_Model.isOpen())
//  	{
//  		name = g_pDB_Model.databaseName();
//  		QSqlDatabase::removeDatabase(name);
// 
//  	}
}