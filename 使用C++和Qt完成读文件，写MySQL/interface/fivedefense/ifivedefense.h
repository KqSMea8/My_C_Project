//ifivedefense.h
#ifndef _IFIVEDEFENSE_2009_09_18_PENGSHIKANG_INCLUDED_
#define _IFIVEDEFENSE_2009_09_18_PENGSHIKANG_INCLUDED_

#include "../icsunknown.h"              // for IICSUnknown

#define DLL_FIVEDEFENSE           "fivedefense"
#define CLSID_FIVEDEFENSE         "cfivedefense"
#define IID_IFIVEDEFENSE          "ifivedefense"

//������Ϣ���нӿ�
class IFiveDefenseCallback;
class IFiveDefense : virtual public IICSUnknown
{
public:
	//��������-ע����������ص��ӿ�
	virtual void RegCallback( const char* szApp, IFiveDefenseCallback* pCallBack ) = 0;

	//��������-�������������ͨ�Žӿڷ���
	virtual void StartServer() = 0;
	//��������-��ֹ���������ͨ�Žӿڷ���
	virtual void StopServer() = 0;
	//��������-�������������ɫ�л�֪ͨ
	virtual void RoleChange(int StatMachine,int StatNet1,int StatNet2) = 0;

	//���������������ͱ仯����
	virtual void SendStatusChange(int nStatusID,int nType,int nValue,bool bManSet) = 0;//��˫��ֵ����
	virtual void SendAnalogChange(int nAnalogID, int nType, short sValue,bool bManSet) = 0;
	//������������������
	virtual void SendPrevent (int nStatusID,int nValue,bool bDouble) = 0;

public:
	static char* GetIntfName() {return IID_IFIVEDEFENSE;}
};

//������Ϣ���нӿ�
class IFiveDefenseCallback
{
public:
	//������������·�������
	virtual void OnPreventControl(int nStatusID, bool bLock, double dt) = 0;
	//����������������������
	virtual void OnPreventBack(int nStatusID,bool bSuccess,double dt) = 0;
	//����������������˹���λ�ź�
	virtual void OnStatusChange(int nStatusID,int value, int quality, double dt) = 0;//��˫��ֵ����
};

#endif
