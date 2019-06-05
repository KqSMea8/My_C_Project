//ictrlexpdao.h

#ifndef _ICTRLEXPDAO_PENGSHIKANG_20130310_H_
#define _ICTRLEXPDAO_PENGSHIKANG_20130310_H_

#include "../ibasicdao.h"                        // for IBasicDao

#define CTRLEXPDAO_CLASSID    "cctrlexpdao"
#define CTRLEXPDAO_INTFID     "ictrlexpdao"

class ICtrlExpDao : virtual public IBasicDao
{
public:	
	//����ң�������ͺ�ң��ֵ�õ�ң����������λ��
	virtual int GetPositionByCtrlValTyp(int nCtrlId, int nValTypId) = 0;
	
	//����ң��������λ�õõ������������ʽ
	virtual const char* GetOperatExpress(int pos) = 0;
};

#endif
