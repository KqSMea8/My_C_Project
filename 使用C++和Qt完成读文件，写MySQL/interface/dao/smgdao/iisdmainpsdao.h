//iisdmainpsdao.h
//----0810_zff_new_add----------------------//
#ifndef _IISDMAINPSDAO_ZHANGFEIFEI_20120810_H_
#define _IISDMAINPSDAO_ZHANGFEIFEI_20120810_H_

#include "../ibasicdao.h"                        // for IBasicDao

#define ISDMAINPSDAO_CLASSID    "cisdmainpsdao"
#define ISDMAINPSDAO_INTFID     "iisdmainpsdao"

class IIsdmainpsDao : virtual public IBasicDao
{
public:
	//�����豸ID�õ�΢�������з�ʽ����Դ���¼��λ��
	virtual int GetPositionByEquipID(int eqpId, int runType) = 0;

	//����΢�������з�ʽ����Դλ�õõ����з�ʽID
	virtual int GetRunStyleID(int pos) = 0;
    //����΢�������з�ʽ����Դλ�õõ��豸ID
    virtual int GetEquipID(int pos) = 0;
    //����΢�������з�ʽ����Դλ�õõ��������ȼ�
	virtual int GetPriority(int pos) = 0;
	//����΢�������з�ʽ����Դλ�õõ�����Ŀ�깦�ʿ����Ƿ���Ч
	virtual int IsEnableAimPower(int pos) = 0; 
	//����΢�������з�ʽ����Դλ�õõ��������Ŀ�깦��
	virtual double GetMaxAimPower(int pos) = 0;
	//����΢�������з�ʽ����Դλ�õõ�������СĿ�깦��
	virtual double GetMinAimPower(int pos) = 0;
	
	//�����������豸ID�ۼ��������豸����Ŀ�깦��
	virtual bool AccumulateMainAimPower(int runType, int eqpId, float& minAimP, float& maxAimP) = 0;
};

#endif