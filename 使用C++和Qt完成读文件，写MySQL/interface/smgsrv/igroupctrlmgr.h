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
	//�Ƿ�����鲥��ʽ����Ⱥ��
	virtual int UseGroupCtrl() = 0;
	//�����鲥��Ⱥ������
	virtual bool SendGroupCtrlInfo(short ctrlKind, float ctrlValue) = 0;
	//����Ⱥ�ط��ؽ��
	virtual bool SetGroupControlResult(short grpCtrlKind, int nResult) = 0;
	//�ж�Ⱥ�ط����Ƿ�ɹ�
	virtual bool IsGroupControlSuccess(short grpCtrlKind) = 0;
};

#endif
