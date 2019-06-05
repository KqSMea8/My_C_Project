//ivqcsettypedao.h

#ifndef _IVQCSETTINGTYPEDAO_PENGSHIKANG_20120531_H_
#define _IVQCSETTINGTYPEDAO_PENGSHIKANG_20120531_H_

#include "../../ibasicdao.h"                     // for IBasicDao

#define VQCSETTYPEDAO_CLASSID    "cvqcsettypedao"
#define VQCSETTYPEDAO_INTFID     "ivqcsettypedao"

class IVqcSetTypeDao : virtual public IBasicDao
{
public:
	//����VQC��ֵ����λ�õõ��޹�\�������ض�ֵ����
	virtual int GetQCtrlMode(int pos) = 0;
	//����VQC��ֵ����λ���޹�����Ŀ���Ƿ�Ϊ�޹�
	virtual bool TargetIsRp(int pos) = 0;
	//����VQC��ֵ����λ���Ƿ������޹�����
	virtual bool CanRpReverse(int pos) = 0;
	//����VQC��ֵ����λ�õõ��޹���������
	virtual double GetMaxRpReverse(int pos) = 0;
	//����VQC��ֵ����λ�õõ�VQC���ڲ�������
	virtual int GetStrategyType(int pos) = 0;
	//����VQC��ֵ����λ�ö�ȡ�Ƿ���Ч��־
	virtual int IsEnable(int pos) = 0;
};

#endif
