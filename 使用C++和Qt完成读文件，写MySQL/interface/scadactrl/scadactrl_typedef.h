/*******************************************************
 * scadactrl_typedef.h -- scadaö�ټ�typedef
 * 
 * date: 2008.07.08 hongkeqin@xjgc.com
 *******************************************************/

#ifndef __SCADACTRL_TYPEDEF_H_20080708
#define __SCADACTRL_TYPEDEF_H_20080708

#include "./scadactrl_defines.h"

/***
 *����ö�ٶ���
 ***/
typedef struct
{
	typedef enum {
		typeNone = 0, typeAnalog, typeStatus, typeAccumulator,
		typeControl, typeSetting, typeSettingArea, typeAlarm,
		typeStation, typeBay, typeEquip, typeSOE, typeSystem,
		typeObjEnd,
	} ScadaObjType; //SCADA����ö��

	typedef enum { 
		None = 0,
		RealMode,		//��ʵģʽ
		EmulationMode	//ģ��Ԥ��ģʽ
	} ControlMode;
	
} CRequestItem;

class IControlBase;
/***
 * �첽���ƻص��ӿ� �ɿ��ƿͻ��˵�����ʵ��
 ***/
class IAsyncReturn
{
public:
	/*
	 * ���Ʒ��ش�����
	 * ����:
	   result -- ���ƽ�� 0-�ɹ��� 1-ʧ�ܣ�2-��ʱ��3-���Ʊ��ܾ���4-ң�س����ɹ���5-ϵͳ�Զ�ȡ����6-�û�ȡ������
	   caller -- IControlBase* ���ؽ����Ӧ�Ŀ��Ʋ���
	 * ����: void
	 */
	virtual void OnReturn(int result, IControlBase* caller)=0;

public:
    static const char* GetIntfName() {return IID_IAsyncReturn;}; 
};

#endif