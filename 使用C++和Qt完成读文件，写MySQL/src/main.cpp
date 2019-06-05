/************************************************************************/
/*  clw write 20190527�������ļ�������дmysql����
/*  main.cpp ������
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
	//������־
	printf("�ļ����ɷ���esfileserver��ʼ���У�\n");
	WriteLogToFile(LOGFILENAME, "�ļ����ɷ���ʼ���У�");
	
	QApplication app( argc, argv);
	
	//AppmgrSyncAbort(PROCESSNAME);  // ע�� appmgr, ����Ϊ������

#ifdef Q_OS_WIN
	QTextCodec *codec = QTextCodec::codecForName("GBK");
#endif
#ifdef Q_OS_LINUX
	QTextCodec *codec = QTextCodec::codecForName("UTF8"); //clw note 20190603��Ӧ�ò���Ҫ
#endif

	QTextCodec::setCodecForTr(codec);
	QTextCodec::setCodecForLocale(codec);
	QTextCodec::setCodecForCStrings(codec);

	//�����̡߳�
	FileParser::Instance()->start();

	return app.exec();
}


















