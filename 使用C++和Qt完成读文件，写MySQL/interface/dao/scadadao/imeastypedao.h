//imeastypedao.h

#ifndef _IMEASTYPEDAO_PENGSHIKANG_20130310_H_
#define _IMEASTYPEDAO_PENGSHIKANG_20130310_H_

#include "../ibasicdao.h"                        // for IBasicDao

#define MEASTYPEDAO_CLASSID    "cmeastypedao"
#define MEASTYPEDAO_INTFID     "imeastypedao"

class IMeasTypeDao : virtual public IBasicDao
{
public:
	//��������������λ�õõ��Ƿ��޸�ң��ֵ
	virtual int GetYtValChangFlag(int pos) = 0;
	//��������������λ�õõ�ң��Ŀ��ֵ����ϵ��
	virtual double GetYtAimValCoff(int pos) = 0;
	//��������������λ�õõ�ң��Ŀ��ֵ�Ƿ�ȡ��
	virtual int GetYtAimvalInt(int pos) = 0;
	//��������������λ�ú�ң��Ŀ��ֵ��ȡң������ֵ
	virtual void TakeCtrlValueByAimValue(int pos, double aimValue, float& ctrlValue) = 0;
};

#endif
