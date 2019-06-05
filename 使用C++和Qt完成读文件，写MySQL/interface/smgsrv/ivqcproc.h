//ivqcproc.h
#ifndef _IVQCPROC_ZHANG_PENG_20130225_20150317_H_
#define _IVQCPROC_ZHANG_PENG_20130225_20150317_H_

//#include "icontrolstrategy.h"
#include "../icsunknown.h"                       // for IICSUnknown

#define VOLTAGECONTROL_MODULE     "vqcproc"
#define VOLTAGECONTROL_CLASSID    "cVoltageControl"
#define VOLTAGECONTROL_INTFID     "iVoltageControl"

class IStorageMgr;
class IGeneratorMgr;
class ITransformerMgr;
class IReactCompMgr;

class IAutoCtrl;
class IActionAlarm;
class IScadaDao;
class ISmgDao;

class IVqcProc : virtual public IICSUnknown // virtual public IControlStrategy 
{
public:
	//��ʼ��VQCʵʱ��ľ�̬��Ϣ
	virtual void InitializeVqcRtdbInfo() = 0;
	//�����������ݱ��ʵʱ�޹�����ֵ
	virtual int RefreshAllReactPowerValues(int& nLocalFlag, int& nAreaNoChange) = 0;
	//ʵʱ���е�ѹ��������
	virtual bool RealVoltageControl(int adjustCount) = 0;

	virtual bool NewAvcControl(int adjustNo, double dValue, int nCtrlType) = 0;

	//�������е�ѹ�޹��豸���ʵʱ�޹�����ֵ��
	virtual void RefreshAllReactPowerData() = 0;

};

#endif
