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
	//�Ƿ��˹�������
	virtual bool  IsAritificialBlackStart(int Pos) = 0;
	//ִ���Զ�����������
	virtual bool  ExecutingAutoBlackStart(int Pos) = 0;
	//ִ���˹�����������
	virtual bool  ExecutingArtificialBlackStart(int Pos) = 0;
	//��������������
	virtual bool  StopBlackStart(int Pos) = 0;

	//�����ⲿ����
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
