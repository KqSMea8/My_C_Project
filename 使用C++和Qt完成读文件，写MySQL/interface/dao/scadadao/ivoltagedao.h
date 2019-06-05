//ivoltagedao.h

#ifndef _IVOLTAGEGRADEDAO_PENGSHIKANG_20120601_H_
#define _IVOLTAGEGRADEDAO_PENGSHIKANG_20120601_H_

#include "../ibasicdao.h"                        // for IBasicDao

#define VOLTAGEDAO_CLASSID    "cvoltagedao"
#define VOLTAGEDAO_INTFID     "ivoltagedao"

class IVoltageDao : virtual public IBasicDao
{
public:
	//���ݵ�ѹ�ȼ�ID�õ����ѹ(kV)
	virtual double GetRateVoltage(int id) = 0;
	//���ݵ�ѹ�ȼ�ID�õ��ϸ��ѹ����
	virtual double GetUpperVoltage(int id) = 0;
	//���ݵ�ѹ�ȼ�ID�õ��ϸ��ѹ����
	virtual double GetLowerVoltage(int id) = 0;
	//���ݵ�ѹ�ȼ�ID�õ�������ѹ����
	virtual double GetUUpperVoltage(int id) = 0;
	//���ݵ�ѹ�ȼ�ID�õ�������ѹ����
	virtual double GetLLowerVoltage(int id) = 0;
	//���ݵ�ѹ�ȼ�ID�õ���ѹʧѹ�ż�ֵ
	virtual double GetZeroVoltageThreshold(int id) = 0;
	//���ݵ�ѹ�ȼ�ID�ж�ָ����ѹֵ�Ƿ�λ�ںϸ����ڡ�
	// ����ֵ��0 --�ϸ�-1 --Խ�ϸ����ޣ�1 --Խ�ϸ����ޣ�
	//  -2 --Խ�������ޣ� 2 --Խ�������ޣ�-3 -- ʧѹ��
	virtual int IsNormalVoltage(int id, double dCurU) = 0;
	//���ݵ�ѹ�ȼ�ID�õ���ѹֵ�Ƿ��ԡ�kV��Ϊ��λ����
	virtual bool IsKVUnit(int id) = 0;
};

#endif
