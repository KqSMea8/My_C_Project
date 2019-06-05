/*******************************************************
 * scadactrlintf.h -- scada���ƽӿڶ���
 * 
 * date: 2008.07.08 hongkeqin@xjgc.com
 * revised:
		.�޸�IScadaOperate�ӿ� 2008.08.06 hongkeqin@xjgc.com
 *******************************************************/

#ifndef __SCADACTRLINTF_H_20080708
#define __SCADACTRLINTF_H_20080708

#include "../icsunknown.h"
#include "./scadactrl_typedef.h"
#include "./scadactrl_defines.h"
//std header
#include <vector>

class IScadaControlType;
class IControlValue;
class IScadaOperateType;
class IScadaSettingType;
class IScadaRingType;

/***
 * ���ƻ���ӿ�
 ***/
class IControlBase : public IICSUnknown
{
public:
	/* ��ô���������Ϣ
	 * ����: ��
	 * ����: const char* ��������
	 */
	virtual const char* ErrorMsg() = 0;
   
	/* 
	 * ��õ�ǰ���ƶ���Ŀ���ģʽ 
	 * ����: ��
	 * ����: ����ģʽ
	   CRequestItem::ControlMode -- CRequestItem::RealMode ��ʵģʽ
									CRequestItem::EmulationMode ģ��Ԥ��ģʽ
	 */
	virtual CRequestItem::ControlMode Mode() = 0;

	/*
	 * ��õ�ǰ���ƶ����趨�ĳ�ʱʱ��
	 * ����: ��
	 * ����: int ��ʱʱ��(��λ: ����)
		> 0 -- ��ʱʱ��; -1 -- �û�δ����,��ϵͳĬ������; 0 -- ������ʱ; 
	 */
	virtual int TimeOut() = 0;

	/*
	 * ���õ�ǰ���ƶ���ĳ�ʱʱ��
	 * ����:
	   msec -- ��ʱʱ��(��λ: ����)
	 * ����: void
	 */
	virtual void SetTimeOut(int msec) = 0;

	/*
	 * ��õ�ǰ���ƶ�����û���Ϣ
	 * ����: ��
	 * ����: const char* �û�ID 
	 */
	virtual const char* UserID() = 0;

	/*
	 * �趨��ǰ���ƶ�����û���Ϣ
	 * ����:
	   userID -- const char* �û�ID
	 * ����: void
	 */
	virtual void SetUser(const char* userID) = 0;

	/*
	 * ��ã���ǰ���Ƶģ�������վID
	 * ����: ��
	 * ����: const char* ����վID 
	 */
	virtual const char* WorkstationID() = 0;

	/*
	 * �趨��ǰ���ƵĹ���վID
	 * ����:
	   wkstationID -- const char* ����վID
	 * ����: void
	 */
	virtual void SetWorkstation(const char* wkstationID) = 0;

	/*
	 * �������
	 * ����: ��
	 * ����: void 
	 */
	virtual void Clear() = 0;

	/*
	 * �趨�첽���ƻص��ӿ�(���첽����ʹ��)
	 * ����:
	   ptr -- IAsyncReturn* �ص��ӿ�ָ��
	 * ����: void
	 */
	virtual void SetCallBack(IAsyncReturn* ptr) = 0;

public:
    static const char* GetIntfName() {return IID_IControlBase;}; 

};

/***
 * Scada���ƽӿ�
 ***/
class IScadaControl : public IControlBase
{
public:
	/*
	 * ��ȡ��ǰ���ƶ���Ŀ�������
	 * ����:��
	 * ����: IScadaControlType* �������ͽӿ�ָ��
	 */
	virtual IScadaControlType* Type() = 0;

	/*
	 * ö�����п���ֵ������ֵ��һ����Ч��
	 * ����: ��
	 * ����: std::vector<IControlValue*> ����ֵ����
		!!ע��: vector������������ǰ���û����ͷ�����ÿ����������ü���
		���������ر�˵��, ���صĽӿڶ������û��ͷ�
	 */
	virtual std::vector<IControlValue*> ListValues() = 0;

	/*
	 * ���ݿ��ƶ���IDö�ٿ���ֵ
	 * ����:
	   controlID -- ���ƶ���ID
	 * ����: std::vector<IControlValue*> ����ֵ����
		!!ע��: vector������������ǰ���û����ͷ�����ÿ����������ü���
		���������ر�˵��, ���صĽӿڶ������û��ͷ�
	 */
	virtual std::vector<IControlValue*> ListValues(int controlID) = 0;

	/*
	 * ִ�п���
	 * ����:
	   controlID -- ���ƶ���ID
	   ctrlValueID -- ����ֵID ( IControlValue*->ID() )
	 * ����: int
			 0-�ɹ��� 1-ʧ�ܣ�2-��ʱ��3-���Ʊ��ܾ���4-ң�س����ɹ���5-ϵͳ�Զ�ȡ����6-�û�ȡ������
	 */
	virtual int Execute(int controlID, int ctrlValueID) = 0;

	/*
	 * ִ�п���
	 * ����:
	   controlID -- ���ƶ���ID
	   ctrlValueID -- ����ֵID ( IControlValue*->ID() )
	   userID -- const char* �û�ID
	   wkstationID -- const char* ����վID
	 * ����: int
			 0-�ɹ��� 1-ʧ�ܣ�2-��ʱ��3-���Ʊ��ܾ���4-ң�س����ɹ���5-ϵͳ�Զ�ȡ����6-�û�ȡ������
	 */
	virtual int Execute(int controlID, int ctrlValueID, const char* userID, const char* wkstationID) = 0;

		/*
	 * ִ�п���
	 * ����:
	   controlID -- ���ƶ���ID
	   ctrlValueID -- ����ֵID ( IControlValue*->ID() )
	   CRequestItem::ScadaObjType -- scada����
	   */

	virtual int Execute(int controlID, int ctrlValueID,CRequestItem::ScadaObjType objType) = 0;
	virtual int StyleSwitch(int styleid) = 0;//ģʽ�л�
	virtual int SequenceCtrl(int ctrlid) = 0;//˳��
	virtual int GroupCtrl(int ftype) = 0;//�����Ⱥ��


	virtual bool BeginGroupControl() = 0;  //��֪��ʲô���� 
	virtual bool EndGroupControl() = 0;	//��֪��ʲô���� 
	
public:
    static const char* GetIntfName() {return IID_IScadaControl;}; 
};

/***
 * Scada�����ӿ�
 ***/
class IScadaOperate : public IControlBase
{
public:
	/*
	 * ��ȡ��ǰ��������Ĳ�������
	 * ����: ��
	 * ����: IScadaOperateType* �������ͽӿ�ָ��
	 */
	virtual IScadaOperateType* Type() = 0;

	/*
	 * ö�����п���ֵ������ֵ��һ����Ч, IControl*->IsValid()�����壩
	 * ����: ��
	 * ����: std::vector<IControlValue*> ����ֵ����
		!!ע��: vector������������ǰ���û����ͷ�����ÿ����������ü���
		���������ر�˵��, ���صĽӿڶ������û��ͷ�
	 */
	virtual std::vector<IControlValue*> ListValues() = 0;

	/*
	 * ���ݲ�����������ö�����п���ֵ������ֵ��һ����Ч��
	 * ����:
	   objType -- CRequestItem::ScadaObjType ������������
	 * ����: std::vector<IControlValue*> ����ֵ����
		!!ע��: vector������������ǰ���û����ͷ�����ÿ����������ü���
		���������ر�˵��, ���صĽӿڶ������û��ͷ�
	 */
	virtual std::vector<IControlValue*> ListValues(CRequestItem::ScadaObjType objType) = 0;

	/*
	 * ���ݲ�������ID������ö�����п���ֵ
	 * ����:
	   id -- ��������ID
	   objType -- CRequestItem::ScadaObjType ������������
	 * ����: std::vector<IControlValue*> ����ֵ����
		!!ע��: vector������������ǰ���û����ͷ�����ÿ����������ü���
		���������ر�˵��, ���صĽӿڶ������û��ͷ�
	 */
	virtual std::vector<IControlValue*> ListValues(int id, CRequestItem::ScadaObjType objType) = 0;

	/*
	 * ִ�в���
	 * ����:
	   id -- ��������ID
	   objType -- CRequestItem::ScadaObjType ������������
	   ctrlValueID -- ����ֵID ( IControlValue*->ID() )
	 * ����: int
			 0-�ɹ�; 1-ʧ��; 2-��ʱ; 3-�������ܾ���6-�û�ȡ������
	 */
	virtual int Execute(int id, CRequestItem::ScadaObjType objType, int ctrlValueID) = 0; 

	/*
	 * ִ�в���
	 * ����:
	   id -- ��������ID
	   objType -- CRequestItem::ScadaObjType ������������
	   ctrlValueID -- ����ֵID ( IControlValue*->ID() )
	   userID -- const char* �û�ID
	   wkstationID -- const char* ����վID
	 * ����: int
			 0-�ɹ�; 1-ʧ��; 2-��ʱ; 3-�������ܾ���6-�û�ȡ������
	 */
	virtual int Execute(int id, CRequestItem::ScadaObjType objType, int ctrlValueID, const char* userID, const char* wkstationID) = 0;

public:
    static const char* GetIntfName() {return IID_IScadaOperate;}; 

};

/***
 * Scada���ýӿ�
 ***/
class IScadaSetting : public IControlBase
{
public:
	/*
	 * ��ȡ��ǰ���ö������������
	 * ����:��
	 * ����: IScadaSettingType* �������ͽӿ�ָ��
	 */
	virtual IScadaSettingType* Type() = 0;

	/*
	* ������Ϣ�ٻ�
	* ����:
	commsrcID -- srcԴ��
	cpuID -- CPU��
	* ����: void 
	* !!�����������첽���ƣ��ɻص�����IAsyncReturn::OnReturn(...)֪ͨ�û�����
	*/
	virtual void CallBase(int commsrcID, int cpuID) = 0;

	/*
	 * ��ֵ�ٻ�
	 * ����:
	   commsrcID -- ���ö���ID
	   cpuID -- cpuid
	   nArea     -- ��ֵ��
	   nCount	 -- [Out] �����С
	   pPoints	 -- [Out] �����С
	   pcoes	 -- [Out] ϵ��(����)
	   pvals	 -- [Out] ֵ(����)
	 * ����: void 
	 * !!�����������첽���ƣ��ɻص�����IAsyncReturn::OnReturn(...)֪ͨ�û�����
	 */
	virtual void CallSetting(int commsrcID, int cpuID, int& nArea, int& nCount, int* pPoints, double* pcoes, double* pvals) = 0;

	/*
	 * �汾�ٻ�
	 * ����:
	   settingID  -- ���ö���ID
	   idString	  -- [Out] C�ַ���
	   softwareId -- [Out] ���ID
	 * ����: void 
	 * !!�����������첽���ƣ��ɻص�����IAsyncReturn::OnReturn(...)֪ͨ�û�����
		 ���������ر�˵����������ͬ�����û���
	 */
	virtual void CallVersion(int commsrcID,char* strVender, char* strSoftver, char* strMode, int bufSize) = 0;

	/*
	 * �޸Ķ�ֵ
	 * ����:
	   settingID -- ���ö���ID
	   nArea     -- ��ֵ��
	   nStart	 -- ��ʼ���
	   nSize	 -- �����С
	   pcoes	 -- ϵ��(����)
	   pvals	 -- ֵ(����)
	 * ����: int
			 0-�ɹ�; 1-ʧ��; 2-��ʱ; 3-���ñ��ܾ���6-�û�ȡ������
	 */
	virtual int ModifySetting(int commsrcID,  int nArea, int nStartPoint, int nCount, const double* pcoes, const double* pvals) = 0;

	/*
	 * ��ֵ���л�
	 * ����:
	   settingID -- ���ö���ID
	   cpuID -- cpuid
	   nArea     -- ��ֵ��
	 * ����: int
			 0-�ɹ�; 1-ʧ��; 2-��ʱ; 3-���ñ��ܾ���6-�û�ȡ������
	 */
	virtual int SwitchArea(int commsrcID, int nArea) = 0;
	virtual int SwitchActArea(int commsrcID, int cpuID, int nArea) = 0;
	virtual int SwitchEditArea(int commsrcID, int cpuID, int nArea) = 0;

	virtual void PresetSetting(int commsrcID, int cpuID, int nArea, int nStartPoint, int nCount, const double* pcoes, const double* pvals) = 0;
	virtual void PresetSetting_ByS(int commsrcID, int cpuID, int nArea, int nStartPoint, int nCount, const double* pcoes, const double* pvals) = 0;
	virtual void SaveOrCancel(int commsrcID, int cpuID, int nArea, int nPoint, bool bSave) = 0;
	virtual void ScadaSetting(int commsrcID,int cpu, int iarea,int settingid) = 0;


public:
    static const char* GetIntfName() {return IID_IScadaSetting;}; 
};

/*
class IScadaRing : public IControlBase
{
public:
	virtual IScadaRingType* Type() = 0;
	virtual bool RingBell() = 0;
	virtual bool RingWhistle() = 0;
	virtual bool MuteBell() = 0;
	virtual bool MuteWhistle() = 0;

	static const char* GetInfName()
	{
		return IID_IScadaRing;
	}
};
*/

#endif