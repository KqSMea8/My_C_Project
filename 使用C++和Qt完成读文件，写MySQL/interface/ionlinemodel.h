// ionlinemodel.h
#ifndef _IONLINEMODEL_H_
#define _IONLINEMODEL_H_

#include "icsunknown.h" // for IICSUnknown

//#define DLL_ONLINEMODEL	"onlinemodel"
#define DLL_ONLINEMODEL	"onlinesmgmodeler"
#define IID_ONLINEMODEL	"IOnlineModel"
#define CID_ONLINEMODEL	"COnlineModel"

#include <vector>

class IOnlineModel: public IICSUnknown
{
public:


	/*
	 �����Ƿ��޸ģ�������޸�(����true)������Ҫ����	updateRtdb ����ʵʱ��
	 */
	virtual bool infoChanged() = 0; 

	/*
	updateRtdb ��������ʵʱ��
	*/
	virtual void updateRtdb() = 0; 


	/*
	isNeedUserAuth �Ƿ���Ҫ�����û���֤����
	���������1.need �Ƿ���Ҫ��Ĭ��ֵΪ����Ҫ
	*/
	virtual void isNeedUserAuth(bool need=false) = 0;


	/*
	unalarm ��������
	���������1.type ������ͣ�ң��Ϊ1��ң��Ϊ2,���Ϊ3
			  2.idlist ����б�
			  3.alarmtype �������ͣ���������Ϊ1���������ƽ��Ϊ0
	*/
	virtual void unalarm(int type, std::vector<int> idlist,int alarmtype=1) = 0;

	/*
	unalarm ��������
	���������1.type ������ͣ�ң��Ϊ1��ң��Ϊ2
			  2.id ���ID
	�����������������Ϊ0������Ϊ1
	*/
	virtual int getAlarmFlag(int type,int id) = 0;

	/*
	setStationLastDate �������ñ��վ��ȫ�������ڵ���ʼʱ��
	���������1.stationid����վID
	*/
	virtual void setStationFirstDate(int stationid) = 0;

	/*
	maxVal ���ڷ��ؼ���ֵ�е����ֵ
	���������1.val  ֵ���ʽ����ʽΪ��ֵ1,ֵ2��ֵ3.....
	*/
	virtual double maxVal(char* val) = 0;

	/*
	minVal ���ڷ��ؼ���ֵ�е���Сֵ
	���������1.val  ֵ���ʽ����ʽΪ��ֵ1,ֵ2��ֵ3.....
	*/
	virtual double minVal(char* val) = 0;

	/*	setForcast �������ù������Ԥ������վ���޵�/����/���޼ƻ�ʵʱ��ģ*/
	//virtual void setForcast() = 0;

	/*	ForcastSampleRepair ���ڹ������Ԥ�������޸�*/
	//virtual void ForcastSampleRepair() = 0;

	/*
	setStationWFmode �������ó�վ���ģʽ
	���������1.imode:���ģʽ
	*/
	virtual void setStationWFmode(int imode) = 0;

	/*setProFlagRYB �������ò���������ѹ��
	���������1.flagbit�������ܱ�־λ  2.bexecute������Ͷ��
	*/
	virtual void setProFlagRYB(int flagbit,bool bexecute) = 0;

	/*����Դ��������
	mainpid Ϊ����ԴID*/
	virtual void setMainPDZ(int mainpid) = 0;

	/*�ֲ�ʽ�������������
	generatorid Ϊ�ֲ�ʽ�����ID*/
	virtual void setGeneratorDZ(int generatorid) = 0;

	/*�����豸��������
	storageid Ϊ�����豸ID*/
	virtual void setStorageDZ(int storageid) = 0;

	/*������˳�ز�������
	sqctrlid Ϊ˳��ID*/
	virtual void setBstartDZ(int sqctrlid) = 0;

	/*���ܿ�����������
	smgid Ϊ΢����ID*/
	virtual void setStorageCurve(int smgid) = 0;

	/*����������������
	smgid Ϊ΢����ID*/
	virtual void setExchpowcur(int smgid,int systype) = 0;

	/*���ѹ��    stationid Ϊ��վID  stationid = 0ʱΪȫ����վ;bflag = 0Ϊ�˳���bflag = 1ΪͶ��*/
	virtual void setWFFlag(int stationid,bool bflag) = 0;
	
	/*ƽ���������� ismoothid Ϊƽ��id*/
	virtual void setSmoothCtrl(int ismoothid) = 0;

	/*Զ������ѹ��Ͷ��*/
	//virtual void setDispatch() = 0;

	/*��ֹԶ����������*/
	virtual void setBanYFDis(bool isF) = 0;

	/*���÷�ʱ��ʱ��*/
	virtual void setPeriodStat() = 0;

};

#endif
