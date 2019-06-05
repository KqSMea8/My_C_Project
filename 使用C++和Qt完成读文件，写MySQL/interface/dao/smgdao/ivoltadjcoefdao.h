//ivoltadjcoefdao.h

#ifndef _IVOLTAGEADJUSTCOEFICIENT_PENGSHIKANG_20170213_H_
#define _IVOLTAGEADJUSTCOEFICIENT_PENGSHIKANG_20170213_H_

#include "../ibasicdao.h"                        // for IBasicDao

#define VOLTADJCOEFDAO_CLASSID    "cvoltadjcoefdao"
#define VOLTADJCOEFDAO_INTFID     "ivoltadjcoefdao"

class IVoltAdjCoefDao  : virtual public IBasicDao 
{
public:
	//���ݽ���㼰���˵��ѹ�ȼ�ID�õ�Ͷ��1��λ�޹����𿼺˵���۵�ѹ�仯�ٷ��ʣ�%Ue/MVar��
	virtual double GetVoltageChangeCoef(int nJoinVoltId, int nChekVoltId) = 0;
	//���ݽ���㼰���˵��ѹ�ȼ�ID�õ�Ͷ��1��λ�޹����𿼺˵�����޹��仯�ٷ��ʣ�kVar/100kVar��
	virtual double GetReactPowerChangeCoef(int nJoinVoltId, int nChekVoltId) = 0;
};

#endif
