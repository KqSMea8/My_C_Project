//==============================================AnalogCal.h==================================================//
#ifndef  INCLUDE_ORDERSENDER_H 
#define  INCLUDE_ORDERSENDER_H 

#include "objsintf.h"
//#include "ICSUnknown.h"

class IOrderSender : public IICSUnknown
{
public:
	//����ѡ���Ԥ��ָ�
	virtual bool SendSwitchSelectByID(int idControl, int old_val, int new_val, bool bDouble)=0;
	virtual bool SendSwitchSelectByObj(ITaskObject* pControl, int old_val, int new_val, bool bDouble)=0;

	//5����ѡ���Ԥ��ָ�
	virtual bool SendGradsSelectByID(int idControl, int old_val, int new_val)=0;
	virtual bool SendGradsSelectByObj(ITaskObject* pControl, int old_val, int new_val)=0;

	//6
	virtual bool SendLongSelectByID(int idControl, int old_val, int new_val)=0;
	virtual bool SendLongSelectByObj(ITaskObject* pControl, int old_val, int new_val)=0;

	//7����ѡ���Ԥ��ָ�
	virtual bool SendFloatSelectByID(int idControl, double old_val, double new_val)=0;
	virtual bool SendFloatSelectByObj(ITaskObject* pControl, double old_val, double new_val)=0;

	//8����ִ���ȷ��ָ�
	virtual bool SendSwitchExcuteByID(int idControl, int old_val, int new_val, bool bDouble)=0;
	virtual bool SendSwitchExcuteByObj(ITaskObject* pControl, int old_val, int new_val, bool bDouble)=0;

	//9����ִ���ȷ��ָ�
	virtual bool SendGradsExcuteByID(int idControl, int old_val, int new_val)=0;
	virtual bool SendGradsExcuteByObj(ITaskObject* pControl, int old_val, int new_val)=0;

	//10����ִ���ȷ��ָ�
	virtual bool SendLongExcuteByID(int idControl, int old_val, int new_val)=0;
	virtual bool SendLongExcuteByObj(ITaskObject* pControl, int old_val, int new_val)=0;

	//11����ִ���ȷ��ָ�
	virtual bool SendFloatExcuteByID(int idControl, double old_val, double new_val)=0;
	virtual bool SendFloatExcuteByObj(ITaskObject* pControl, double old_val, double new_val)=0;

	//12���ͳ���ָ��
	virtual bool SendSwitchCancelByID(int idControl, int old_val, int new_val, bool bDouble)=0;
	virtual bool SendSwitchCancelByObj(ITaskObject* pControl, int old_val, int new_val, bool bDouble)=0;

	//13���ͳ���ָ��
	virtual bool SendGradsCancelByID(int idControl, int old_val, int new_val)=0;
	virtual bool SendGradsCancelByObj(ITaskObject* pControl, int old_val, int new_val)=0;

	//14���ͳ���ָ��
	virtual bool SendLongCancelByID(int idControl, int old_val, int new_val)=0;
	virtual bool SendLongCancelByObj(ITaskObject* pControl, int old_val, int new_val)=0;

	//15���ͳ���ָ��
	virtual bool SendFloatCancelByID(int idControl, double old_val, double new_val)=0;
	virtual bool SendFloatCancelByObj(ITaskObject* pControl, double old_val, double new_val)=0;

	//����������ָ��
	virtual bool SendPreventByID(int idControl,int nValue,bool bDouble)=0;
	virtual bool SendPreventByObj(ITaskObject* pControl,int nValue,bool bDouble)=0;

	//�����ת��ң��ң��ֵ
	virtual bool SendAnalogToPrevent(int idAnalog, double value)=0;
	virtual bool SendStatusToPrevent(int idStatus, int val, bool dbflag)=0;

	virtual bool SCADALockReq(int chgrpid, int idControl) = 0;
};


class ISettingOrderSender : public IICSUnknown
{	
public:
	//��ֵ�ٻ�
	virtual bool  SendCallSetting(long idIED, long nCPUNO, long nZone)=0;

	//��ֵ�޸�Ԥ��                                                                                                ϵ��           ֵ   
	virtual bool  SendSelSetting(long idIED, long nCPUNO, long nZone, long nSize, long nStart,double* pcoes, double* pvals)=0;

	//��ֵ���л�
	virtual bool  SendSwitchSetting(long idIED, long nCPUNO, long nZone)=0;

	//��ֵ�޸�Ԥ��ȡ��
	virtual bool  SendCancelSetting(long idIED, long nCPUNO, long nZone)=0;

	//��ֵ�޸�ִ��
	virtual bool SendAckSetting(long idIED, long nCPUNO, long nZone)=0;

	//��ֵ�汾��
	virtual bool SendAskSettingVer(long idIED,long nCPUNO)=0;
	//���������ٻ�
	virtual bool  SendCallProtect(long nDevNo, long nCpuNo, long nSinNo) =0;
	//�����¼����Լ챨���ٻ�
    virtual bool  SendCallEvent(int idIED, int iSinNo) =0;

	virtual bool SendAnalogManSet(bool bSet, int iIedid, int iId, double Value) = 0;
	virtual bool SendPulseManSet(bool bSet, int iIedid, int iId, double value) = 0;
	virtual bool SendStatusManSet(bool bSet, int iIedid, int iId, int Value) = 0;
	virtual bool SendCallZone(int idIED, int iLD) = 0;
};
#endif // INCLUDE ANALOGCAL H 
