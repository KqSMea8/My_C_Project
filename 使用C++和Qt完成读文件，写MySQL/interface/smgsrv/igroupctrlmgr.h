// igroupctrlmgr.h: interface for the IGroupCtrlMgr class.
//
//////////////////////////////////////////////////////////////////////

#ifndef AFX_IGROUPCTRLMGR_H__PENGSHIKANG_20151012__INCLUDED_
#define AFX_IGROUPCTRLMGR_H__PENGSHIKANG_20151012__INCLUDED_

#define GROUPCTRLMANAGER_CLASSID    "cGroupCtrlMgr"
#define GROUPCTRLMANAGER_INTFID     "iGroupCtrlMgr"

#include "../icsunknown.h"                       // for IICSUnknown

class IGroupCtrlMgr : virtual public IICSUnknown
{
public:
	//是否采用组播方式进行群控
	virtual int UseGroupCtrl() = 0;
	//发送组播的群控命令
	virtual bool SendGroupCtrlInfo(short ctrlKind, float ctrlValue) = 0;
	//设置群控返回结果
	virtual bool SetGroupControlResult(short grpCtrlKind, int nResult) = 0;
	//判断群控返回是否成功
	virtual bool IsGroupControlSuccess(short grpCtrlKind) = 0;
};

#endif
