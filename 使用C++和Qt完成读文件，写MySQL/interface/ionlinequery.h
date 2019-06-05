// ionlinequery.h
#ifndef _IONLINEQUERY_H_
#define _IONLINEQUERY_H_

#include "icsunknown.h" // for IICSUnknown

#define DLL_ONLINEQUERY	"onlinequery"
#define IID_ONLINEQUERY	"IOnlinequery"
#define CID_ONLINEQUERY	"COnlinequery"


class IOnlineQuery: public IICSUnknown
{
public:

	/*
	failureData �쳣�������
	���������
	���ز�����
	*/
	virtual void failureData() = 0; 

	/*
	unalarm  �������Ʋ�ѯ
	���������
	���ز�����
	*/
	virtual void unalarm() = 0; 

	/*
	equipTag �����豸���
	���������
	���ز�����
	*/
	virtual void equipTag() = 0;

	/*
	overrun ����Խ��
	���������analogID ң��ID
	���ز�����
	*/
 	virtual void overrun(int analogID) = 0; 

	/*
	statusChange ���ձ�λ
	���������statusID  ң��ID
	���ز�����
	*/
	virtual void statusChange(int statusID) = 0; 

	/*
	statusCtrl ���տ���
	���������controlID  ң��ID
	���ز�����
	*/
	virtual void statusCtrl(int controlID) = 0; 

};

#endif
