// istichctrl.h
//
//////////////////////////////////////////////////////////////////////

#ifndef _ISWITCHCTRL__H__INTERFACE_
#define _ISWITCHCTRL__H__INTERFACE_

#include "../icsunknown.h"                       // for IICSUnknown
#include "smgdatadef.h"

#define SWITCHCTRL_MODULE     "stichctrl"
#define SWITCHCTRL_CLASSID    "cswitchctrl"
#define SWITCHCTR_INTFID      "iswitchctrl"


class ISwitchCtrl /*: virtual public IICSUnknown*/
{
public:
	//�õ���ǰģʽ�л�ID
	virtual bool GetCurModelID(int& modelid) = 0;
	
	//����ת����
	virtual bool CombineToIsland(MicgridObectInfo* pCurMgObj) = 0;

	//����ת����
	virtual bool IslandToCombine(MicgridObectInfo* pCurMgObj) = 0;

	//����Դ����ת��Դ�л�������pcs
	virtual bool RotatToPCS(MicgridObectInfo* pCurMgObj) = 0;

	//����Դ�Ӵ���pcs�л�����ת��Դ
	virtual bool PCSToRotat(MicgridObectInfo* pCurMgObj) = 0;

	//����΢������ģʽ
	virtual void RefreshMicgridModelFlags() = 0;
	
	//΢��ϵͳģʽ�л�
	virtual bool SwitchCtrl(int aimstyleid) = 0;

	//��ʼ������ģʽ�л��б�
	virtual void CreatSwitchObjList() = 0;

};

#endif