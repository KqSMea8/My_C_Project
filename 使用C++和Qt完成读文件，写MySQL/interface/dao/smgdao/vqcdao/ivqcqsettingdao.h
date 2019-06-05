//ivqcqsettingdao.h

#ifndef _IVQCQSETTINGPARAMDAO_PENGSHIKANG_20120531_H_
#define _IVQCQSETTINGPARAMDAO_PENGSHIKANG_20120531_H_

#include "../../ibasicdao.h"                     // for IBasicDao
#include "../../../smgsrv/vqcdatadef.h"          // for VqcRange��VqcSettingInfo

#define VQCQSETTINGDAO_CLASSID    "cvqcqsettingdao"
#define VQCQSETTINGDAO_INTFID     "ivqcqsettingdao"

class IVqcQSettingDao : virtual public IBasicDao
{
public:
	//����VQC��ֵ����ID�͵�ǰʱ��õ�VQC��ֵ��Ϣλ��
	virtual int GetPositionByTypeAndTime(int typeId, int nMinutes) = 0;
	
	//����VQC��ֵ����ID�͵�ǰ��ѹ�õ�VQC��ֵ��Ϣλ��
	virtual int GetPositionByTypeAndVoltage(int typeId, double dVoltage) = 0;
	
	//����VQC��ֵ��Ϣλ�ö�ȡVQC��ֵ����ID
	virtual int GetLimitType(int pos) = 0;
	
	//����VQC��ֵ��Ϣλ�õõ���ֵʱ�䷶Χ
	virtual void GetTimeRange(int pos, int& startTime, int& endTime) = 0;

	//����VQC��ֵ��Ϣλ�õõ���ֵ��ѹ��Χ
	virtual void GetVoltageRange(int pos, double& startVolt, double& endVolt) = 0;
	
	//����VQC��ֵ��Ϣλ�õõ���������_�޹���ֵ
	virtual void GetRePowerOrCosPowerLimitValues(int pos, double& upperVal, double& lowerVal) = 0;
	
	//����VQC��ֵ��Ϣλ�õõ�VQC��ֵ��Ϣ
	virtual void GetReactPowerSetting(int pos, VqcRange& rpSetting) = 0;
	virtual bool GetCurrentSettingValueByTypeId(int typeId, VqcSettingInfo& settingInfo) = 0;
	
};

#endif
