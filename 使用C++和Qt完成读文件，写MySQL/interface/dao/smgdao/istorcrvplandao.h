//istorcrvplandao.h

#ifndef _ISTORAGECURVEPLANDAO_PENGSHIKANG_20110314_H_
#define _ISTORAGECURVEPLANDAO_PENGSHIKANG_20110314_H_

#include "../ibasicdao.h"                        // for IBasicDao

#define STORCURVEPLANDAO_CLASSID    "cstorcurveplandao"
#define STORCURVEPLANDAO_INTFID     "istorcurveplandao"

class IStorCurvePlanDao : virtual public IBasicDao
{
public:
	//���ݴ��ܷŵ����߼ƻ�λ�õõ���΢��ID
	virtual int GetSubMicGridID(int pos) = 0;
	
	//���ݴ��ܷŵ����߼ƻ�λ�ö�ȡ�Ƿ���Ч��־
	virtual int IsEnable(int pos) = 0;

	//������΢��ID�õ���Ч�Ĵ��ܷŵ����߼ƻ�ID
	virtual int GetEnableCurvePlanId(int mgId) = 0;
};

#endif
