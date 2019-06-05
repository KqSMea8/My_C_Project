//ivqcstratypedao.h

#ifndef _IVQCSTRATEGYTYPEDAO_PENGSHIKANG_20160819_H_
#define _IVQCSTRATEGYTYPEDAO_PENGSHIKANG_20160819_H_

#include "../../ibasicdao.h"                     // for IBasicDao

#define VQCSTRATYPEDAO_CLASSID    "cvqcstratypedao"
#define VQCSTRATYPEDAO_INTFID     "ivqcstratypedao"

class IVqcStraTypeDao : virtual public IBasicDao
{
public:
	//����VQC��������λ�õõ���ѹ�޹����Ƴ�վ����
	//    0����ѹվVQC��1����ѹվVQC��2����ѹվAVC��վ��3����ѹվAVC��վ��4:  AVC��վ��
	virtual int GetStationFlag(int pos) = 0;
	//����VQC��������λ�õõ���ѹ�޹����Ʋ�������
	//    1���ۺ��Ż���2����ѹ����,	3���޹�����, 4��ֻ����ѹ, 5��ֻ���޹�
	virtual int GetVqcStrategyType(int pos) = 0;
	//����VQC��������ID�õ���ѹ�޹����Ʋ�������
	//    1���ۺ��Ż���2����ѹ����,	3���޹�����, 4��ֻ����ѹ, 5��ֻ���޹�
	virtual int GetVqcStrategyTypeByID(int id) = 0;
};

#endif
