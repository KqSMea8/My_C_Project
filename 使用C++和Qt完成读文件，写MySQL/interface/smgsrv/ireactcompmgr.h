//ireactcompmgr.h


#ifndef _IREACTCOMPMGR_ZHANGPENG_20130301_H_
#define _IREACTCOMPMGR_ZHANGPENG_20130301_H_

#define REACTCOMPMANAGER_CLASSID    "cReactCompMgr"
#define REACTCOMPMANAGER_INTFID     "iReactCompMgr"

#include "../icsunknown.h"                       // for IICSUnknown
#include "vqcdatadef.h"                          // for VQCAreaInfo

class IReactCompMgr : virtual public IICSUnknown 
{
public:
	//ִ��Ͷ���豸�����޹���������
	virtual bool ActDecreaseReactPower(VQCAreaInfo* pCurVQCArea) = 0;
	//ִ��Ͷ���豸�����޹���������
	virtual bool ActIncreaseReactPower(VQCAreaInfo* pCurVQCArea) = 0;
	//ִ�е����豸�޹���������
	virtual bool ActAdjustReactPower(VQCAreaInfo* pCurVQCArea) = 0;
	//ִ�е����޹������豸�豸��ѹ����������ֵ��0 --�޶���(�Ѵ�Ŀ��)��1--����ʧ�ܣ�2--���ڳɹ���
	virtual int ActAdjustRPCVoltage(VQCAreaInfo* pCurVQCArea, bool toZero=false) = 0;
	//���ݸ������޹�����ִ�е����豸�޹���������
	virtual bool DoActAdjustReactPower(VQCAreaInfo* pCurVQCArea, double needQ, double& dActQ) = 0;
	//������Ҫ���޹���������ϵͳ�����пɵ��޹������豸���޹�����
	virtual bool IncreaseReactPowerByNeedQ(VQCAreaInfo* pCurVQCArea, double dNeedQ, double& dActQ) = 0;
	//����ϵͳ�пɵ��޹������豸���޹�����,��֤��ŵ緽��һ��
	virtual bool AdjustReactPowerForAccord(VQCAreaInfo* pCurVQCArea, double& dActQ) = 0;

	//�л�������Դģʽ
	virtual bool IntoMainMode(int pos, int ctrlReason) = 0;
	//�л���������Դģʽ
	virtual bool IntoUnmainMode(int pos, int ctrlReason, double curQ) = 0;
};

#endif  //_IREACTCOMPMGR_ZHANGPENG_20130301_H_
