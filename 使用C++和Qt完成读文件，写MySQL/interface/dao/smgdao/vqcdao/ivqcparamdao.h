//ivqcparamdao.h

#ifndef _IVQCPARAMETERDAO_PENGSHIKANG_20120503_H_
#define _IVQCPARAMETERDAO_PENGSHIKANG_20120503_H_

#include "../../ibasicdao.h"                     // for IBasicDao

#define VQCPARAMDAO_CLASSID    "cvqcparamdao"
#define VQCPARAMDAO_INTFID     "ivqcparamdao"

class IVqcParamDao : virtual public IBasicDao
{
public:
	//�õ�ϵͳ���Ŷ�ʱ��(��)
	virtual int GetCsDisturbTime() = 0;
	//�õ�ĸ�߷�ֵ��ƽ��ȱ�����ֵ(��ô)
	virtual double GetBalanceOfBusU() = 0;
	//�õ���ѹ�������ж�ʱ��(��)
	virtual int GetSlipCheckTime() = 0;
	//�õ���ѹ����ѹ�����λ��
	virtual int GetMaxTapDiff() = 0;
	//�õ�VQC��ֵ����
	virtual int GetSettingTypeId() = 0;
	//�õ���ѹ�޹���������
	// 0����ѹվVQC��1����ѹվVQC��2����ѹվAVC��վ��3����ѹվAVC��վ��4:  AVC��վ��
	virtual int GetStationFlag() = 0;
	//�õ���ǰ����ϵͳ����
	virtual int GetAdjustAreaNum() = 0;
	//���õ�ǰ����ϵͳ����
	virtual bool SetAdjustAreaNum(int areaNum) = 0;
	//�õ��޹�/�����������������ٷ�ֵ��%��
	virtual double GetRfPlusMargin() = 0;
	//�õ���ǰ��ѹ���������ٷ�ֵ��%��
	virtual double GetVolPlusMargin() = 0;
	//��ѹ�޹�����������ƴ���
	virtual int GetMaxCtrlTimes() = 0;

	//�õ����ε�ѹָ��ޱ�����ֵ
	virtual double GetVoltDiffLockValue() = 0;
};

#endif
