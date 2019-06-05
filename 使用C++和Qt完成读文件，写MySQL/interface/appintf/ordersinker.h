//==============================================AnalogCal.h==================================================//
#ifndef  INCLUDE_ORDERSINKER_H 
#define  INCLUDE_ORDERSINKER_H 

#include "objsintf.h"
#include "ProtectReportIntf.h"

class IOrderSinker : public IICSUnknown
{
public:
	//ѡ����أ�Ԥ��ָ�
	virtual void SelectOrderBack(int idControl, bool bSucc, double tm)=0;
	//ִ����أ�ȷ��ָ�
	virtual void ExcuteOrderBack(int idControl, bool bSucc, double dt)=0;
	//����ָ���
	virtual void CancelOrderBack(int idControl, bool bSucc, double dt)=0;
	//ѡ����أ�Ԥ��ָ�
	virtual void SelectOrderBackByObj(ITaskObject* pObject, bool bSucc, double tm)=0;
	//ִ����أ�ȷ��ָ�
	virtual void ExcuteOrderBackByObj(ITaskObject* pObject, bool bSucc, double dt)=0;
	//����ָ���
	virtual void CancelOrderBackByObj(ITaskObject* pObject, bool bSucc, double dt)=0;


	//���ң��
	virtual void PreventControl(int idControl, bool bLock, double dt)=0;

	//��������������
	virtual void PreventBack(int idControl,bool bSuccess,double dt) = 0; 

  	/*
	Զ���������󷵻�
	��in��int chgrpid	Զ��ͨ����ID
	��in��int controlid	����ң�ص��ID
	��in��int bLock	1:����;0:ͨ��
	��out��ref��bool	����
	*/	
	virtual void SCADALockRes(int chgrpid, int idControl, bool bLock) = 0;

	/*
	Զ��������վ����
	��in��Int chgrpid	Զ��ͨ����ID
	��in��Int controlid	����ң�ص��ID
	��out��ref��bool bLock	1:����;0:ͨ��
	*/
	virtual void YDLockReq(int chgrpid, int idControl, bool& bLock) = 0;
};

class ISettingOrderSinker : public IICSUnknown
{
public:
	//��ֵ�ٻ�����
	virtual void SettingCallReturn(long idIED, long nCPUNO, long nZone, long bSucc, long nSize, long nStart,double* pcoes, double* pvals)=0;

	//��ִֵ�����
	virtual void SettingReturn(long idIED, long nCPUNO, long nZone, long bSucc)=0;

	//��ֵ���л�����
	virtual void SettingSwitchReturn(long idIED, long nCPUNO, long nZone, long bSucc)=0;

	//��ֵ�޸�Ԥ������
	virtual void SettingSelReturn(long idIED, long nCPUNO, long nZone, long bSucc, long nSize, long nStart,double* pcoes, double* pvals)=0;

	//��ֵ�汾�ŷ���
	virtual void SettingVerReturn(long idIED,long nCPUNO,char* idString,char* softwareId)=0;

	//�����������ٻ�����
	virtual void ProtectCallReturn(char cResult, bool bActive,/*long bSucc,*/long nDev, long nCpu, \
						long nSin, IProtectObject* pObject)=0;
	//�����¼����Լ챨���ٻ�����
	virtual void EventCallReturn( char cResult, long nDev, long nSin, IProtectObject* pObject) =0;

	virtual void ManSetReturn(bool bSet, bool bSucc, int iIedid, int iId) = 0;

	virtual void ZoneCallReturn(bool bSucc, int iIedid, int iLd, int iZoneNum, int iCurntRun, int iCurntEdit) = 0;
};

#endif // INCLUDE ANALOGCAL H 
