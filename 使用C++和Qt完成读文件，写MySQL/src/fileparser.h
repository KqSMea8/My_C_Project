#ifndef __ESFILEPARSER_20190531_H__
#define __ESFILEPARSER_20190531_H__

#include <string>
#include <vector>
#include <map>
#include <qthread.h>
#include <qstring.h>
//#include "savefile.h" // for CSaveFile  clw note 20190527��д��

#include <algorithm>
#ifdef _MSC_VER
#include <atlstr.h>		// for checkFile
#include <windows.h>		// for checkFile
#include <Shlwapi.h>	// for checkFile
#pragma comment(lib,"shlwapi.lib")// for checkFile 
#endif 

#include <qdir.h> // for GetFiles() 
#include <QDirIterator> // for GetFiles() 
#include <sys/stat.h> // for GetFiles() 
#include <sys/types.h> // for GetFiles() 

#include "./common/cdatetime.h"   // for CDateTime()
#include "../include/other/updaterealacfg.h" 
#include "../interface/iupdaterealcfgdt.h" //wx, for write rtdb

using namespace std;

struct stFileInfo
{
	map<string, string> m_map_nameInfo; //�洢ini�����ļ�������Ϣ����filetype=RNMXFHYC;
	map<string, vector<string> > m_map_nameVals;  //�洢ini�����ļ���վidֵ���Ӧ��txt��¼��idֵ����station1=1��#3;
};

class FileParser : public QThread
{
public:
	static FileParser* Instance();
	~FileParser();
	void Stop() { m_bExit = true; }


protected:
	virtual void run();


private:
	FileParser();
	
	//��ȡ·��path�µ������ļ���������files
	bool GetFiles(string path);
	
	//��esfilesetting.ini�ļ��ж���������Ϣ
	bool ReadInConfigPara();

	//���������ļ���idֵ��Ӧ��һ�м�¼
	bool ParseESFile(const char filepath[]);

	//�����ļ�·����ȡ�ļ���
	string GetFileNameByPath(string filepath);

	//���ļ���Ϣдmysql
	bool WriteFileInfoToDB();

	//�ƶ�srcDirĿ¼�µ��ļ���dstDir
	bool MoveFileToDst(string srcDir, string dstDir, bool coverFileIfExist);

	//����ɾ���ļ�
	int DeleteFileByTime(); //TODO��deprecated


#ifdef _MSC_VER
	//������־�ʹ���
	void DealWithLogs(char logLines[128], bool bCout, int outFreq);
#endif 
#ifdef Q_OS_LINUX
	//4. ������־�ʹ���
	void DealWithLogs(string logLines, bool bCout, int outFreq);
#endif 


	bool m_bExit;  //�Ƿ����ֹͣ�߳�
	static FileParser* m_pInst;

	vector<stFileInfo> m_vecFilesInfo; //ini�����ļ���������Ϣ�����籾��ĿĿǰ��6���ļ�����Ӧ6��stFileInfo�ṹ�����

	vector<string> m_vecFiles; //������������TXT���ļ�������
	vector<float> m_vecShortP;  // 96����ڹ���ֵ
	vector<vector<float> > m_vecStationShortPs;  //����station��96����ڹ���ֵ����
	
	int m_nFilesInfoIndex; //�ļ�����
	QString m_strForcastTime; //Ԥ��96�����ʼʱ�䡣����Ƕ���Ԥ�⣬��ʼ��ʱ��Ϊ����00:00:00��������Ԥ����ʼ��ʱ��Ϊ����ʱ�䡣

	IUpdateRealACfg* m_pUpdateRealACfg; //wx �ӿڶ�������дʵʱ���

	//�߳�ѭ��������Ϊ�˿��Ƶ�������
	int m_circleTimes;

	//����ʱ����ز���
	QString m_timeDQ;
	QString m_timeSecondDQ;

	//��ǰ������
	int m_startTime_minCount;
};
#endif /* __ESFILEPARSER_20190531_H__ */