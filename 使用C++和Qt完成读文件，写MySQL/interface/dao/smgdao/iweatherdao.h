//iweatherdao.h

#ifndef _IWEARTHERDATADAO_PENGSHIKANG_20120521_H_
#define _IWEARTHERDATADAO_PENGSHIKANG_20120521_H_

#include "../ibasicdao.h"                        // for IBasicDao

#define WEATHERDAO_CLASSID    "cweatherdao"
#define WEATHERDAO_INTFID     "iweatherdao"

class IWeatherDao : virtual public IBasicDao
{
public:
	//�����������ݵ�λ�����ø���������ʵʱֵ
	virtual void SetMeasureValues(int pos, double& dWind, double& dHeat, double& dLight, double& dWet, double& dBaro) = 0;
	
	//������������λ�õõ���΢��ID
	virtual int GetSubMicGridID(int pos) = 0;

	//������������λ�õõ�����ң��ID
	virtual int GetWindID(int pos) = 0;
	//������������λ�õõ��¶�ң��ID
	virtual int GetHeatID(int pos) = 0;
	//������������λ�õõ�����ң��ID
	virtual int GetLightID(int pos) = 0;
	//������������λ�õõ�ʪ��ң��ID
	virtual int GetWetID(int pos) = 0;
	//������������λ�õõ���ѹң��ID
	virtual int GetBaroID(int pos) = 0;
	//������������λ�õõ���ǰ����
	virtual double GetCurWind(int pos) = 0;
	//������������λ�õõ���ǰ�¶�
	virtual double GetCurHeat(int pos) = 0;
	//������������λ�õõ���ǰ����
	virtual double GetCurLight(int pos) = 0;
	//������������λ�õõ���ǰʪ��
	virtual double GetCurWet(int pos) = 0;
	//������������λ�õõ���ǰ��ѹ
	virtual double GetCurBaro(int pos) = 0;

	//������������λ�õõ��豸ID
	virtual int GetEquipID(int pos) = 0;
	//������������λ�õõ�����ɢ�����ǿ��ң��ID
	virtual int GetSunScatRadiID(int pos) = 0;
	//������������λ�õõ���ǰ����ɢ�����ǿ��
	virtual double GetCurSunScatRadi(int pos) = 0;
	//������������λ�õõ������ܷ���ǿ��ң��ID
	virtual int GetSunTotalRadiID(int pos) = 0;
	//������������λ�õõ���ǰ�����ܷ���ǿ��
	virtual double GetCurSunTotalRadi(int pos) = 0;
	//������������λ�õõ�����ң��ID
	virtual int GetWindDirectionID(int pos) = 0;
	//������������λ�õõ���ǰ����
	virtual double GetCurWindDirection(int pos) = 0;

	//������΢����ID�õ���������λ��
	virtual int GetPositionByMicgridID(int mgId) = 0;
	//�����豸ID�õ���������λ��
	virtual int GetPositionByEquipmentID(int eqpId) = 0;
};

#endif
