//ialarmtypedao.h

#ifndef _IALARMTYPEDAO_PENGSHIKANG_20130310_H_
#define _IALARMTYPEDAO_PENGSHIKANG_20130310_H_

#include "../ibasicdao.h"                        // for IBasicDao

#define ALMTYPDAO_CLASSID    "calmtypdao"
#define ALMTYPDAO_INTFID     "ialmtypdao"

class IAlmTypDao : virtual public IBasicDao
{
public:
	//����Խ�ޱ�������λ�ö�ȡ�Ƿ��ǰٷֱ�
	virtual int IsPercentum(int pos) = 0;

	//����Խ�ޱ�������λ�ö�ȡʱ�����ͱ�־
	virtual int GetPeroidFlag(int pos) = 0;

	//����Խ�ޱ�������λ�ö�ȡԽ�޻ָ�����
	virtual double GetDeadZone(int pos) = 0;

	//����Խ�ޱ�������λ�ö�ȡ�����ӳ�ʱ��
	virtual int GetAlarmDelayTime(int pos) = 0;

	//����Խ�ޱ�������λ�ö�ȡԽ�����ͻ�ֵ
	virtual double GetBaseValue(int pos) = 0;

	//����Խ�ޱ�������λ�ö�ȡ���ޱ���ֵ
	virtual double GetUpperValue(int pos) = 0;

	//����Խ�ޱ�������λ�ö�ȡ���ޱ���ֵ
	virtual double GetLowerValue(int pos) = 0;

	//����Խ�ޱ�������λ�ö�ȡ�����ޱ���ֵ
	virtual double GetUUpperValue(int pos) = 0;

	//����Խ�ޱ�������λ�ö�ȡ�����ޱ���ֵ
	virtual double GetLLowerValue(int pos) = 0;

	//����Խ�ޱ�������λ�ö�ȡԽ�������Ƿ����¹�
	virtual int IsFaultUL(int pos) = 0;

	//����Խ�ޱ�������λ�ö�ȡԽ�����������Ƿ����¹�
	virtual int IsFaultUL2(int pos) = 0;

	//����Խ�ޱ�������λ�ö�ȡԽ���޶�������
	virtual int GetUpperAct(int pos) = 0;

	//����Խ�ޱ�������λ�ö�ȡԽ���޶�������
	virtual int GetLowerAct(int pos) = 0;

	//����Խ�ޱ�������λ�ö�ȡԽ�����޶�������
	virtual int GetUUpperAct(int pos) = 0;

	//����Խ�ޱ�������λ�ö�ȡԽ�����޶�������
	virtual int GetLLowerAct(int pos) = 0;
};

#endif
