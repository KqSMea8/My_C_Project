//iblackstart.h


#ifndef _IBLACKSTART_ZHANGPENG_20130225_H_
#define _IBLACKSTART_ZHANGPENG_20130225_H_

#include "../icsunknown.h"                       // for IICSUnknown
#include "smgdatadef.h"                          // for MicgridObectInfo


class IGeneratorMgr;
class ILoadMgr;
class IStorageMgr;
class ISimulTest;
class IActionAlarm;
class ISysInfoDao;
class ISMicgridDao;
class ISmgRunstyleDao;
class IStorageDao;
class IGeneratorDao;

class IBlackStart : virtual public IICSUnknown 
{
public:	
	//是否人工黑启动
	virtual bool  IsAritificialBlackStart(int Pos) = 0;
	//执行自动黑启动操作
	virtual bool  ExecutingAutoBlackStart(int Pos) = 0;
	//执行人工黑启动操作
	virtual bool  ExecutingArtificialBlackStart(int Pos) = 0;
	//结束黑启动操作
	virtual bool  StopBlackStart(int Pos) = 0;

	//传入外部对象
	virtual void SetCurrentMicgridObject(MicgridObectInfo* pCurMgObj) = 0;
	virtual void SetGeneratorManager(IGeneratorMgr* pGenCtrlor) = 0;
	virtual void SetLoadManager(ILoadMgr* pLoadCtrlor) = 0;
	virtual void SetStorageManager(IStorageMgr* pStorCtrlor) = 0;
	virtual void SetSimulTest(ISimulTest * pTest) = 0;
	virtual void SetActionAlarm(IActionAlarm * pAlarm) = 0;

	virtual void SetSysInfoDao(ISysInfoDao* pSysInfo) = 0;
	virtual void SetSMicgridDao(ISMicgridDao* pSMicgrid) = 0;
	virtual void SetSmgRunstyleDao(ISmgRunstyleDao* pSmgRunstyle) = 0;
	virtual void SetStorageDao(IStorageDao* pStorage) = 0;
	virtual void SetGeneratorDao(IGeneratorDao* pGenerator) = 0;

};

#endif  //_IBLACKSTART_ZHANGPENG_20130225_H_
