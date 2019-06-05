//idatatransfer.h
#ifndef IDATATRANSFER_PENGSHIKANG_20140320_H
#define IDATATRANSFER_PENGSHIKANG_20140320_H

#include "../icsunknown.h"              // for IICSUnknown

#define DLL_DATATRANSFER           "fivedefense"
#define CLSID_DATATRANSFER         "cdatatransfer"
#define IID_DATATRANSFER           "idatatransfer"

class IDataTransferCallBack;

/************************************************************************/
/* IDataTransfer����ת���ӿ�
/* ���ܣ����ϵͳ�����װ��ת����ң���ݣ�
/************************************************************************/
class IDataTransfer : virtual public IICSUnknown
{
public:
	//���ûص��ӿ�
	virtual void Advise(IDataTransferCallBack* pCallback) = 0;

	//��Զ�����������ң��iDescSystem=0�������iDescSystem=1��Զ����
	//(1)���ϵͳ�����װ��ת��ң������
	virtual void SendStatus(int iDescSystem, int iID,int iValue, double dTime, int iQuality, bool bManSet=false) = 0;
	//(2)���ϵͳ�����װ��ת��ң������
	virtual void SendAnalog(int iDescSystem, int iID,double dValue, double dTime, int iQuality, bool bManSet=false) = 0;
	//���ϵͳ�����װ��ת��SOE����
	virtual void SendSoe(int iDescSystem, int iID, int iValue, double dSpan, char *pCFace, double dTime) = 0; 
	//(3)���ϵͳ�����װ�÷���ң��Ч����
	virtual void SendControl(int iDescSystem, int iCtrlCmdType, int iID, int iOldValue, int iNewValue, bool bDouble) = 0;
	//���ϵͳ�����װ��ת�����ƽ����Ϣ
	virtual void SendControlBack(int iDescSystem, int iCtrlBackType, int iID,bool bExecSuccess,double dTime) = 0;
};

//���װ������ϵͳ��������
class IDataTransferCallBack
{
public:
	//(1)������ط���ң��ֵ
	virtual void SetAnalogValueByID(int idAnalog, double value, int quality, double dt) = 0;
	//(2)������ط���ң��ֵ
	virtual void SetStatusValueByID(int idStatus, int value, int quality, double dt) = 0;
	//(?)������ط���SOEֵ
	virtual void SetSOEValueByID(int idStatus, int value, double span, char* cFace, double dt) = 0;
	//(3)��������ر���/����
	virtual void PreventControl(int idControl, bool bLock, double dt) = 0;
	//(4)������ط���У����
	virtual void PreventBack(int idControl,bool bSucc,double dt) = 0;
	//������ط���ִ������
	virtual void ExecuteOrderBackByID(int idControl, bool bSucc, double dt) = 0;
	//������ط���ѡ����
	virtual bool SendSwitchSelectByID(int idControl, int old_val, int new_val, bool bDouble) = 0;
	//������ط���ֱ����
	virtual bool SendSwitchExcuteByID(int idControl, int old_val, int new_val, bool bDouble) = 0;
	//������ط��ͳ�����
	virtual bool SendSwitchCancelByID(int idControl, int old_val, int new_val, bool bDouble) = 0;
	//(5)������ط���ͨ��״̬�仯��Ϣ
	virtual bool SendChannelState( int iChnlType, int iNodeId, char* sIp, int iState ) = 0;
};


#endif