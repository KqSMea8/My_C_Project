/*******************************************************
 * scadactrltypeintf.h -- scada�������ͽӿڶ���
 * 
 * date: 2008.07.08 hongkeqin@xjgc.com
 *******************************************************/

#ifndef __SCADACTRLTYPEINTF_H_20080708
#define __SCADACTRLTYPEINTF_H_20080708

#include "../icsunknown.h"
#include "./scadactrl_typedef.h"
#include "./scadactrl_defines.h"

class IScadaControl;
class IScadaOperate;
class IScadaSetting;

/*****
 * �������ͻ���ӿ�
 *****/
class IControlTypeBase : public IICSUnknown
{
public:
	/*
	 * ��ȡ����
	 * ����: ��
	 * ����: const char* 
	 */
	virtual const char* Name() = 0;

	/*
	 * ��ȡ����
	 * ����: ��
	 * ����: const char* 
	 */
	virtual const char* Desc() = 0;

public:
    static const char* GetIntfName() {return IID_IControlTypeBase;}; 
};

/*****
 * Scada�������ͽӿ�
 *****/
class IScadaControlType : public IControlTypeBase
{
public:
	/*
	 * ����Scada���ƶ���
	 * ����: ��
	 * ����: IScadaControl*
	 */
	virtual IScadaControl* CreateControl() = 0;

public:
    static const char* GetIntfName() {return IID_IScadaControlType;}; 

};

/*****
 * Scada����ֵ���ͽӿ�
 *****/
class IControlValue : public IControlTypeBase
{
public:
	/*
	 * ��ȡ��ǰ����ֵ����ID
	 * ����: ��
	 * ����: int ��Ӧ�غϡ��ط֡���������ͣ�Ⱦ������͵�ID
	 */
	virtual int ID() = 0;

	/*
	 * ��ȡ��ǰ���Ʋ�������
	 * ����: ��
	 * ����: int ��Ӧ�غϡ��ط֡���������ͣ�Ⱦ������͵ı���ֵ
	 */
	virtual int Value() = 0;

	/*
	 * �����ݵ�ǰ״̬��ֵ�жϣ���ǰ����ֵ�Ƿ���Ч
	 * ����: ��
	 * ����: bool
			true -- ������Ч
			false -- ������Ч
	 */
	virtual bool IsValid() = 0;

public:
    static const char* GetIntfName() {return IID_IControlValue;}; 

};

/*****
 * Scada�������ͽӿ�
 *****/
class IScadaOperateType : public IControlTypeBase
{
public:
	/*
	 * ����Scada��������
	 * ����: ��
	 * ����: IScadaOperate*
	 */
	virtual IScadaOperate* CreateOperate() = 0;

public:
    static const char* GetIntfName() {return IID_IScadaOperateType;}; 
};

/*****
 * Scada�������ͽӿ�
 *****/
class IScadaSettingType : public IControlTypeBase
{
public:
	/*
	 * ����Scada���ö���
	 * ����: ��
	 * ����: IScadaOperate*
	 */
	virtual IScadaSetting* CreateSetting() = 0;

public:
    static const char* GetIntfName() {return IID_IScadaSettingType;}; 
};
#endif

