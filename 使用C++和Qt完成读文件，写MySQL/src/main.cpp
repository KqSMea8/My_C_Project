/************************************************************************/
/*  clw write 20190527：储能文件解析，写mysql服务
/*  main.cpp 主函数
/************************************************************************/
#include <fstream>
#include <iostream>

#include <stdio.h>
#include <qapplication.h>
#include <qtextcodec.h>

#include "fileparser.h"
#include "./common/writelog.h" // for WriteLogToFile
#include "../interface/appmgr/appmgr.h" // for AppmgrSyncAbort()

using namespace std;
using std::string;

#ifndef PROCESSNAME
	#define PROCESSNAME  "esfileserver"
#endif

int main( int argc, char* argv[])
{
	//设置日志
	printf("文件生成服务esfileserver开始运行！\n");
	WriteLogToFile(LOGFILENAME, "文件生成服务开始运行！");
	
	QApplication app( argc, argv);
	
	//AppmgrSyncAbort(PROCESSNAME);  // 注册 appmgr, 参数为进程名

#ifdef Q_OS_WIN
	QTextCodec *codec = QTextCodec::codecForName("GBK");
#endif
#ifdef Q_OS_LINUX
	QTextCodec *codec = QTextCodec::codecForName("UTF8"); //clw note 20190603：应该不需要
#endif

	QTextCodec::setCodecForTr(codec);
	QTextCodec::setCodecForLocale(codec);
	QTextCodec::setCodecForCStrings(codec);

	//启动线程。
	FileParser::Instance()->start();

	return app.exec();
}


















