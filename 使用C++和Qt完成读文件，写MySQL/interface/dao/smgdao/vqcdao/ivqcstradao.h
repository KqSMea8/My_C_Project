//ivqcstradao.h

#ifndef _IVQCSTRATEGYDAO_PENGSHIKANG_20120507_H_
#define _IVQCSTRATEGYDAO_PENGSHIKANG_20120507_H_

#include "../../ibasicdao.h"                     // for IBasicDao

#define VQCSTRADAO_CLASSID    "cvqcstradao"
#define VQCSTRADAO_INTFID     "ivqcstradao"

class IVqcStraDao : virtual public IBasicDao
{
public:
	//����VQC���ڲ�������ID�͵������ŵõ����ڲ��Լ�¼λ��
	virtual int GetPositionByStraTypeAndZoneNo(int straType, int zoneNo) = 0;
	//����VQC���ڲ��Լ�¼λ�õõ���1����
	virtual int GetFirstStrategy(int pos) = 0;
	//����VQC���ڲ��Լ�¼λ�õõ���2����
	virtual int GetSecondStrategy(int pos) = 0;
	//����VQC���ڲ��Լ�¼λ�õõ���3����
	virtual int GetThirdStrategy(int pos) = 0;
	//����VQC���ڲ��Լ�¼λ�õõ���4����
	virtual int GetFourthStrategy(int pos) = 0;
	//����VQC���ڲ��Լ�¼λ�õõ���n������
	virtual int GetStrategyN(int pos, unsigned int n) = 0;
};

#endif
