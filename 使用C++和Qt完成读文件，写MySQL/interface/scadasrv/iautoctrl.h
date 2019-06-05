/*******************************************************
 * iautoctrl -- smg������Զ�������ҵ��ӿ�
 *******************************************************/

#ifndef IAUTOCTRL_PENGSHIKANG_20130301_H
#define IAUTOCTRL_PENGSHIKANG_20130301_H

#include "scadadatadef.h"                        // for OPERATETYPE��ControlLogInfo
#include "ictrlmainlogic.h"                      // for ICtrlMainLogic

class IAutoCtrl
{
public:
	//���ݿ��Ʋ��������Զ�ִ��ң�ز���
	virtual bool AutoExecuteControl(OPERATETYPE ctrlType, int ctrlId, bool bCheck, ControlLogInfo* pCtrlInfo, bool bCheckControl=true, AUTOEXECUTESELECTCMD aescType=AESC_SELECT, int relativeID=0, int relativeType=1) = 0;
	//���ݵ���Ŀ��ֵ�Զ�ִ��ң������
	virtual bool AutoExecuteAdjust(int ctrlId, float ctrlValue, double aimValue, bool bCheck, ControlLogInfo* pCtrlInfo, bool bCheckControl=true, bool isInductiveQ=false, AUTOEXECUTESELECTCMD aescType=AESC_SELECT, int relativeID=0) = 0;

	// ���ÿ����Ƿ�ȴ��������
	virtual bool SetWaitControlReturn(bool bWaitRet) = 0;
	// ��ȡ����������Ϣʱ�䣨���룩
	virtual int GetContinueControlRestTime() = 0;

	//��������ID�Ƿ���Խ����Զ����Կ���
	virtual bool CanAutoControl(int ctrlId, int ctrlType) = 0;

	//�����ⲿ����
	virtual void SetControlMainLogic(ICtrlMainLogic* pCtrlMain) = 0;
};

#endif