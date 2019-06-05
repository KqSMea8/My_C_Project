#ifndef _OPERATEINTERFACE__H_
#define _OPERATEINTERFACE__H_

#include "operateintf.h"

#define IID_IControlClientInfo	"IControlClientInfo"
#define IID_ICommand			"ICommand"
#define IID_ICallFile			"icallfile"
#define IID_ICallFileSinker		"icallfilesinker"
#define IID_ICallFileSvc		"icallfilesvc"
#define OPCLSID_CallFile		"callfile"


class IControlClientInfo : public IICSUnknown
{
public:
	virtual void SetClientModule(const char* module)=0;
	virtual void GetClientModule(char* module, int nSize)=0;
	virtual void SetControlTag(int tag)=0;
	virtual int GetControlTag()=0;
public:
	static char* GetIntfName(){return IID_IControlClientInfo;}
};

class IFileCommand : public IICSUnknown
{
public:
	virtual void SendCommand(IICSUnknown* pOrderSender)=0;	
	virtual void SendBack()=0;
public:
	static char* GetIntfName(){return IID_ICommand;}
};

class QString;
class QStringList;
class ICallFileSinker : public IICSUnknown
{
public:
	virtual void FileListReture(const QStringList& lstFileList) = 0;
	virtual void FileReture(const QString& sFilePath) = 0;
	virtual void PeriodFilesReture(const QString& sFilePath, const QStringList& lstFileName) = 0;
public:
	static char* GetIntfName(){return IID_ICallFileSinker;}
};

class ICallFile : public IICSUnknown
{
public:
	virtual void SetCallFileSinker(ICallFileSinker* pSinker) = 0;
	virtual bool GetFileList(int IEDid, double timeBegin, double timeEnd) = 0;
	virtual bool GetFile(int IEDid, const char * sFileName) = 0;
	virtual bool GetPeriodFiles(int IEDid, double timeBegin, double timeEnd) = 0;
public:
	static char* GetIntfName(){return IID_ICallFile;}
};

#endif 
