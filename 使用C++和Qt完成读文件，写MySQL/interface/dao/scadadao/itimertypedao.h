//itimertypedao.h

#ifndef _ITIMERTYPEDAO_PENGSHIKANG_20101012_H_
#define _ITIMERTYPEDAO_PENGSHIKANG_20101012_H_

#include "../ibasicdao.h"                        // for IBasicDao
//Added by qt3to4:
#include <Q3ValueList>

#define TIMERTYPEDAO_CLASSID    "ctimertypedao"
#define TIMERTYPEDAO_INTFID     "itimertypedao"

class ITimerTypeDao : virtual public IBasicDao
{
public:
	//���ݶ�ʱ������λ�õõ�������������
	virtual void GetCycleType(int pos, int& mode, int& span) = 0;
	//���ݶ�ʱ������λ�õõ�������ʼʱ��
	virtual double GetStartTime(int pos) = 0;

	//���ݶ�ʱ������λ�õõ���ʼ����ʱ��
	virtual double GetInitCalTime(int pos) = 0;
	//�õ�Ŀǰ�ü���Ķ�ʱ������
	virtual void GetTimeoutType(double* pCalTime, Q3ValueList<int>& typeList) = 0;  
};

#endif
