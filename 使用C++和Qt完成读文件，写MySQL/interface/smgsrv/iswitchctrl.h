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
	//得到当前模式切换ID
	virtual bool GetCurModelID(int& modelid) = 0;
	
	//并网转离网
	virtual bool CombineToIsland(MicgridObectInfo* pCurMgObj) = 0;

	//离网转并网
	virtual bool IslandToCombine(MicgridObectInfo* pCurMgObj) = 0;

	//主电源从旋转电源切换到储能pcs
	virtual bool RotatToPCS(MicgridObectInfo* pCurMgObj) = 0;

	//主电源从储能pcs切换到旋转电源
	virtual bool PCSToRotat(MicgridObectInfo* pCurMgObj) = 0;

	//更新微网运行模式
	virtual void RefreshMicgridModelFlags() = 0;
	
	//微网系统模式切换
	virtual bool SwitchCtrl(int aimstyleid) = 0;

	//初始化运行模式切换列表
	virtual void CreatSwitchObjList() = 0;

};

#endif