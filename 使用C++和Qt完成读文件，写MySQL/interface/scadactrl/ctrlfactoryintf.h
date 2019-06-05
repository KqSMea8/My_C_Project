/*******************************************************
 * ctrlfactoryintf.h -- scada���ƹ����ӿ�
 * 
 * date: 2008.07.08 hongkeqin@xjgc.com
 *******************************************************/

#ifndef __CTRLFACTORYINTF_H_20080708
#define __CTRLFACTORYINTF_H_20080708

#include "../icsunknown.h"
#include "./scadactrl_typedef.h"
#include "./scadactrl_defines.h"
//std header
#include <vector>

class IControlTypeBase;
class IScadaControlType;
class IScadaOperateType;
class IScadaSettingType;

/***
 * �������͹����ӿ�
 * ����: ��ȡ��������
 ***/
class IControlFactory : public IICSUnknown
{
public:
	/*
	 * ��ȡ��ǰ���п��������б�
	 * ����:��
	 * ����: const std::vector<IControlTypeBase*>&
		!!ע��: �û��������������ÿ����������ü���
		���������ر�˵��, ���صĽӿڶ������û��ͷ�
	 */
	virtual const std::vector<IControlTypeBase*>& ListTypes() = 0;
	
	/*
	 * �����������Ʒ��ؿ�������(����)
	 * ����:
	   tpName -- ��������
	 * ����: IControlTypeBase*
	 */
	virtual IControlTypeBase* GetTypeByName(const char* tpName) = 0;

	/*
	 * �����������Ʒ��ؿ�������
	 * ����:
	   tpName -- ��������
	 * ����: IScadaControlType*
	 */
	virtual IScadaControlType* GetControlTypeByName(const char* tpName) = 0;

	/*
	 * �����������Ʒ��ز�������
	 * ����:
	   tpName -- ��������
	 * ����: IScadaOperateType*
	 */
	virtual IScadaOperateType* GetOperateTypeByName(const char* tpName) = 0;
	/*
	 * �����������Ʒ�����������
	 * ����:
	   tpName -- ��������
	 * ����: IScadaSettingType*
	 */
	virtual IScadaSettingType* GetSettingTypeByName(const char* tpName) = 0;

public:
    static const char* GetIntfName() {return IID_IControlFactory;}; 
};

#endif