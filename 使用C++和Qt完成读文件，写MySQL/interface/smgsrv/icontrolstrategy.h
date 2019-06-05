// icontrolstrategy.h: interface for the IControlStrategy class.
//
//////////////////////////////////////////////////////////////////////

#ifndef _ICONTROLSTRATEGY_H__PENGSHIKANG_20130304__INCLUDED_
#define _ICONTROLSTRATEGY_H__PENGSHIKANG_20130304__INCLUDED_

#include "../icsunknown.h"                       // for IICSUnknown
#include "smgdatadef.h"                          // for MicgridObectInfo

#define SMGCONTINENTPROCESS_MODULE     "smgcontiproc"
#define SMGCONTINENTPROCESS_CLASSID    "cSmgContinentProcess"
#define SMGCONTINENTPROCESS_INTFID     "iSmgContinentProcess"

class CMscDataAgcProc;

class IControlStrategy : virtual public IICSUnknown 
{
public:
	//ִ��΢�������Զ����Ʋ���
	virtual bool ExecuteStrategy(MicgridObectInfo* pCurMgObj, int proFlag, CMscDataAgcProc* pAgcStraSend) = 0;
	//������΢���й�����ƽ������ʵʱֵ
	virtual void UpdateSmoothCtrlInfo(MicgridObectInfo* pCurMgObj) = 0;
	//����PCC�Ľ�������[�������]
	virtual bool AdjustMainPowerForTest(int smgID, double exchangeP, bool isCombine) = 0;
};

#endif
