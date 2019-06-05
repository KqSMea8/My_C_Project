//iloadmgr.h

#ifndef _ILOADMGR_SMG8000_20130301_H_
#define _ILOADMGR_SMG8000_20130301_H_

#define LOADMANAGER_CLASSID    "cLoadMgr"
#define LOADMANAGER_INTFID     "iLoadMgr"

#include "../icsunknown.h"                       // for IICSUnknown
#include "smgdatadef.h"                          // for MicgridObectInfo

class ILoadMgr : virtual public IICSUnknown 
{
public:
	//��ȡָ��΢�����п���Ͷ��ı��г�����λ��
	virtual int GetMinCanAddLoadPosInMicgrid(MicgridObectInfo* pCurMgObj, double& loadP) = 0;

	//��ȡ��΢������δͶ�븺�ɵ�����
	virtual int GetCutLoadCount(MicgridObectInfo* pCurMgObj) = 0;

	//ִ�лָ����ɲ���������ֵ��true--�ж�����false--�޶�����
	virtual bool RecallLoadForCombine(MicgridObectInfo* pCurMgObj, int ctrlReason, double& remainP, bool onlyOne) = 0;
	//����ʱִ�и��ɻָ�����
	virtual bool ExecLoadRecallStrategy(MicgridObectInfo* pCurMgObj, int ctrlReason, double& remainP, bool onlyOne) = 0;
	//�������ʵ���ʱִ�и����г�����
	virtual bool ExecLoadEmergeStrategy(MicgridObectInfo* pCurMgObj, int ctrlReason, double& remainP) = 0;

	//������ֵͶ����΢������С�ĸߵȼ����ɲ���
	virtual bool ActAddMinLoad(MicgridObectInfo* pCurMgObj, int ctrlReason, double mainSoc, double maxAddP, double& actP) = 0;
	//���ݴ���SOC״ִ̬���и��ɲ���
	virtual bool ActCutLoadByStorageSOC(MicgridObectInfo* pCurMgObj, int ctrlReason, double mainSoc, double maxCutP, int loadGrade, double& actP) = 0;
	//�г���΢�������еĸ��ɲ���
	virtual bool ActCutAllLoads(MicgridObectInfo* pCurMgObj, int ctrlReason) = 0;

	//////////////////////////////////////////////////////////////////////////////////////////
	//���º������ؽ����0--δ������1--������δ�ﵽĿ�ꣻ2--������ﵽĿ�ꡣ
	//decPtoMaxMP--�������г�\��Ͷ��ĸ��ɹ��ʣ�incPtoMinMP--���Զ��г�\��Ͷ��ĸ��ɹ��ʡ�
	//////////////////////////////////////////////////////////////////////////////////////////
	//�г��������������ʳ���,ƽ�⹦��ȱ������remainPΪ����
	virtual int IncreaseMicgridPowerByCutLoad(MicgridObectInfo* pCurMgObj, int ctrlReason, double decPtoMaxMP, double incPtoMinMP, double& remainP) = 0;
	//Ͷ�븺�������ٹ��ʳ���,ƽ�⹦��ӯ������remainPΪ����
	virtual int DecreaseMicgridPowerByAddLoad(MicgridObectInfo* pCurMgObj, int ctrlReason, double decPtoMaxMP, double incPtoMinMP, double& remainP) = 0;

	//������Ƶ�ʵı䶯�����ڸ���
	virtual void TestAdjustLoadByFrequency(MicgridObectInfo* pCurMgObj, double ratioP) = 0;
};

#endif