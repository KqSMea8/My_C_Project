#ifndef _IGENERALCALL__H_
#define _IGENERALCALL__H_

#include "icsunknown.h"

#define IID_IGeneralComm		"igeneralcomm"
#define IID_IGeneralCommEx		"igeneralcommex"
#define IID_IGeneralCall		"igeneralcall"
#define IID_IGeneralCallEvent	"igeneralcallevent"

#define CLSID_GeneralCall		"generalcall"

//�����·��ӿ�,��ͨѶʵ��
class IGeneralComm : public IICSUnknown
{
public:
	//src��Ӧͨ����,lo��Ӧװ��ID
	virtual bool SendCallCmd(int src, int lo) = 0;
};

class IGeneralCommEx : public IICSUnknown
{
public:
	//�ٻ���������(objtype: ʹ��CSF�������Ͷ���)
	virtual bool GetObjValue(int objtype, int objid) = 0;
};



/*���ٻ�ԭ��
GT_COMMRECOVERY:	ͨѶ�ָ�
GT_INITIAL:			����վ��ʼ��
GT_OPERATION:		ҵ������
GT_MANUAL:			�ֶ�����
GT_GETDATA:			�����ٻ�����
*/
enum GENERALCALL_TYPE{GT_COMMRECOVERY = 0, GT_INITIAL, GT_OPERATION, GT_MANUAL, GT_GETDATA };

//���ٽӿ�,���ٻ�ģ��ʵ��
class IGeneralCall : public IICSUnknown
{
public:
	virtual bool AddCallCmd(int src, int lo, GENERALCALL_TYPE gt) = 0;
	virtual bool DelCallCmd(int src, int lo) = 0;
	virtual void SetGeneralComm(IGeneralComm* pComm) = 0;
};

//���ٻ�ͨѶ�¼��ӿ�:ͨѶ����,���ٻ�ģ�����
class IGeneralCallEvent : public IICSUnknown
{
public:
	virtual void OnCallConfirm(int src, int lo, bool bSuc) = 0;
	virtual void OnCallOver(int src, int lo, bool bSuc) = 0;
};

#define MODULE_GENERALCALL	"generalcall"

#endif
