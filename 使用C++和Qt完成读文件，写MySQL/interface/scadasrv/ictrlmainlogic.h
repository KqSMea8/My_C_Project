/*******************************************************
 * ictrlmainlogic.h -- ����˿�����ҵ����ӿ�
 *******************************************************/

#ifndef __ICONTROLMAINLOGIC_PENGSHIKANG_H_20130301
#define __ICONTROLMAINLOGIC_PENGSHIKANG_H_20130301

#include "scadadatadef.h"                        // for OPERATETYPE��ControlLogInfo

class ICtrlMainInfo;
class ICtrlRelatData;

class ICtrlMainLogic
{
public:
	//��������ID�Ƿ���Ч
	virtual bool CheckAndStartControl(int sid, int ctrlId, int& ctrlPos, CONTROLORIGIN ctrlQrigin, bool bCheckControl, bool bCanWait, bool isSelCtrl=false, bool isMultSrc=false) = 0;
	//���ݿ�����λ�úͲ������͵õ����ƶ�Ӧ�Ŀ�������ֵ��
	virtual bool GetCtrlValueByCtrlType(int ctrlPos, OPERATETYPE ctrlType, int& ctrlValTypPos, int& ctrlValue) = 0;
	//���µ�ǰ������Ϣ
	virtual void UpdateControlLogInfo(ControlLogInfo* pCtrlInfo) = 0;
	//�Զ�ִ�п�������
	virtual int AutoExecuteCommand(int ctrlPos, float ctrlValue, int ctrlValTypPos, double aimValue, const ControlLogInfo* pCtrlInfo, 
		AUTOEXECUTESELECTCMD aescType=AESC_SELECT, int relativeID=0, int relativeType=1, bool needGuard=false, const char* userName="") = 0;

	//�����Ƿ���Ҫ�ȴ����ƽ�����أ�Ⱥ��ʱ����Ϊfalse��
	virtual bool SetNeedWaitFlag(bool needWait) = 0;

	virtual ICtrlMainInfo* GetControlMainInfo() = 0;
	virtual ICtrlRelatData* GetCtrlRelatedData() = 0;
};

#endif