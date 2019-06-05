//isettingareadao.h

#ifndef _ISETTINGAREADAO_PENGSHIKANG_20101126_H_
#define _ISETTINGAREADAO_PENGSHIKANG_20101126_H_

#include "../ibasicdao.h"                        // for IBasicDao

#define SETTINGAREADAO_CLASSID    "csettingareadao"
#define SETTINGAREADAO_INTFID     "isettingareadao"

class ISettAreaDao : virtual public IBasicDao
{
public:	
	//���ݶ�ֵ���źͶ�ֵ��ID�õ���ֵ�����λ��
	virtual int GetPositionBySettingID(int nAreaNo, int nSettingId) = 0;
	
	//���ݶ�ֵ��λ�õõ���ֵ����
	virtual int GetSettingArea(int pos) = 0;
	//���ݶ�ֵ��λ�õõ���ֵ����ID
	virtual int GetSettingId(int pos) = 0;

	//���ݶ�ֵ��λ�õõ���ֵֵ
	virtual const char* GetSettingValue(int pos) = 0;
	//���ݶ�ֵ��λ�����ö�ֵֵ
	virtual bool SetSettingValue(int pos, const char* sSettValue) = 0;
	
	//���ݶ�ֵ��λ�õõ���ֵ�ٻ�����ʱ��
	virtual double GetSettingTime(int pos) = 0;
	//���ݶ�ֵ��λ�����ö�ֵ�ٻ�����ʱ��
	virtual bool SetSettingTime(int pos, double dSettTime) = 0;
};

#endif
