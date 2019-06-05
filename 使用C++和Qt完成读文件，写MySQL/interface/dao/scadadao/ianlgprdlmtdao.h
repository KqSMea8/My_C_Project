//ianlgprdlmtdao.h

#ifndef _IANALOGPEROIDLIMITDAO_PENGSHIKANG_20130310_H_
#define _IANALOGPEROIDLIMITDAO_PENGSHIKANG_20130310_H_

#include "../ibasicdao.h"                        // for IBasicDao

#define APRDLMTDAO_CLASSID    "caprdlmtdao"
#define APRDLMTDAO_INTFID     "iaprdlmtdao"

class IAPrdLmtDao : virtual public IBasicDao
{
public:
	//����ģ����Խ������ID��ʱ������ID�õ�ģ����ʱ��Խ������λ��
	virtual int GetPositionByID(int nALmtTyp, int nPrdTyp) = 0;

	//����ģ����ʱ��Խ������λ�ö�ȡ���ޱ���ֵ
	virtual double GetUpperValue(int pos) = 0;
	//����ģ����ʱ��Խ������λ�ö�ȡ���ޱ���ֵ
	virtual double GetLowerValue(int pos) = 0;	
};

#endif
