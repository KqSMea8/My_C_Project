//isettingdao.h

#ifndef _ISETTINGDAO_PENGSHIKANG_20101126_H_
#define _ISETTINGDAO_PENGSHIKANG_20101126_H_

#include "icsfdao.h"                           // for ICsfDao

#define SETTINGDAO_CLASSID    "csettingdao"
#define SETTINGDAO_INTFID     "isettingdao"

class ISettingDao : virtual public ICsfDao
{
public:
	//���ݲɼ�����Դ�Ͳɼ���λ�õõ���ֵ��λ��
	virtual int GetPositionByCommSrcID(int nSrcId, int nPntId) = 0;
	
	//���ݶ�ֵ��λ�õõ���ֵֵ����
	virtual int GetSettValueType(int pos) = 0;
	
	//���ݶ�ֵ��λ�õõ���ֵֵ
	virtual const char* GetSettingValue(int pos) = 0;
	//���ݶ�ֵ��λ�����ö�ֵֵ
	virtual bool SetSettingValue(int pos, const char* sSettValue) = 0;

	//  -------------------------------------  WX Modify  -------------------------------------  //
	//���ݶ�ֵ��λ�û�ȡCPU��   
	virtual int GetCpuNo(int pos) = 0;
	
	//���ݶ�ֵ��λ�����ö�ֵ�༭��
	virtual bool SetEditArea(int pos, int& iEditArea) = 0;

	//���ݶ�ֵ��λ�����ö�ֵ������
	virtual bool SetActArea(int pos, int& iActArea) = 0;
	//  -------------------------------------  WX Modify  -------------------------------------  //
	
	//���ݶ�ֵ��λ�õõ���ֵ����
	virtual int GetSettingArea(int pos) = 0;
	//���ݶ�ֵ��λ�����ö�ֵ����
	virtual bool SetSettingArea(int pos, int nSettArea) = 0;

	//���ݶ�ֵ��λ�õõ�����ö���������Ͷ���ID
	virtual int GetSettingEnumId(int pos) = 0;
	//���ݶ�ֵ��λ�õõ����������Ͷ���ID
	virtual int GetCtrlWordDefId(int pos) = 0;
	//���ݶ�ֵ��λ�õõ�������λID
	virtual int GetMeasUnit(int pos) = 0;
	//���ݶ�ֵ��λ�õõ����ֵ
	virtual double GetMaxValue(int pos) = 0;
	//���ݶ�ֵ��λ�õõ���Сֵ
	virtual double GetMinValue(int pos) = 0;
};

#endif
