//iequiptypedao.h

#ifndef _IEQUIPTYPEDAO_PENGSHIKANG_20130310_H_
#define _IEQUIPTYPEDAO_PENGSHIKANG_20130310_H_

#include "../ibasicdao.h"                        // for IBasicDao

#define EQUIPTYPEDAO_CLASSID    "cequiptypedao"
#define EQUIPTYPEDAO_INTFID     "iequiptypedao"

class IEquipTypeDao : virtual public IBasicDao
{
public:
	//�����豸����λ�õõ��豸���ͱ���
	virtual const char* GetCode(int pos) = 0;
	//�����豸����λ�õõ��豸�������
	virtual int GetEquipClass(int pos) = 0;

	//�����豸ID�õ��Ƿ���˫λ���豸��˫λ���豸�仯�ӳ�ʱ��[�ɶ�������]
	virtual bool IsDoubleStatusByID(int id, int& nDelayTime, bool bRequery=false) = 0;
	//�����豸����λ���ж��豸�Ƿ���˫λ���豸
	virtual bool IsDoubleStatus(int pos) = 0;
	//�����豸����λ�õõ�˫λ���豸�仯�ӳ�ʱ��
	virtual int GetDpsDelayTime(int pos) = 0;
	//�����豸����ID�ж��豸�Ƿ�Ϊ��������Դ�����豸[�ɶ�������]
	virtual bool IsRenewableEnergyByID(int id, bool bRequery=false) = 0;	
};

#endif
