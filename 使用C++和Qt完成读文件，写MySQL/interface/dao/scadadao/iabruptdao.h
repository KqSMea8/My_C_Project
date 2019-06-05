//iabruptdao.h

#ifndef _IABRUPTDAO_PENGSHIKANG_20081201_H_
#define _IABRUPTDAO_PENGSHIKANG_20081201_H_

#include "../ibasicdao.h"                        // for IBasicDao

#define ABRUPTDAO_CLASSID    "cabruptdao"
#define ABRUPTDAO_INTFID     "iabruptdao"

class IAbruptDao : virtual public IBasicDao
{
public:
	//�������䱨������λ�ö�ȡ�Ƿ��Ǳ仯��
	virtual int IsDiff(int pos) = 0;
	//�������䱨������λ�ö�ȡ�仯����
	virtual int GetTrend(int pos) = 0;
	//�������䱨������λ�ö�ȡ�仯�ż�ֵ
	virtual double GetGradeValue(int pos) = 0;
	//�������䱨������λ�ö�ȡ����ȷ��ʱ���ż�
	virtual int GetQualtyTimeLmt(int pos) = 0;
	//�������䱨������λ�ö�ȡ���䱨���ӳ�ʱ��
	virtual int GetAlarmTimeLmt(int pos) = 0;
	//�������䱨������λ�ö�ȡ�Ƿ�Ϊ�¹�����
	virtual int IsFault(int pos) = 0;
	//�������䱨������λ�ö�ȡ���䱨����������
	virtual int GetAbruptAct(int pos) = 0;
};

#endif
