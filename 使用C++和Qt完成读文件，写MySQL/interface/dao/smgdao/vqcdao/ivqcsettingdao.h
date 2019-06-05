//ivqcsettingdao.h

#ifndef _IVQCSETTINGPARAMDAO_PENGSHIKANG_20120503_H_
#define _IVQCSETTINGPARAMDAO_PENGSHIKANG_20120503_H_

#include "../../ibasicdao.h"                     // for IBasicDao
#include "../../../smgsrv/vqcdatadef.h"          // for VqcRange��VqcSettingInfo

#define VQCSETTINGDAO_CLASSID    "cvqcsettingdao"
#define VQCSETTINGDAO_INTFID     "ivqcsettingdao"

class IVqcSettingDao : virtual public IBasicDao
{
public:
	//����VQC��ֵ����ID�͵�ǰʱ��õ�VQC��ֵ��Ϣλ��
	virtual int GetPositionByTypeAndTime(int typeId, int nMinutes) = 0;
	
	//����VQC��ֵ��Ϣλ�ö�ȡVQC��ֵ����ID
	virtual int GetLimitType(int pos) = 0;
	
	//����VQC��ֵ��Ϣλ�õõ���ֵʱ�䷶Χ
	virtual void GetTimeRange(int pos, int& startTime, int& endTime) = 0;
	
	//����VQC��ֵ��Ϣλ�õõ����Ʋ��ѹ��ֵ
	virtual void GetControlVoltageLimitValues(int pos, double& upperVal, double& lowerVal) = 0;
	//����VQC��ֵ��Ϣλ�õõ��ο����ѹ��ֵ
	virtual void GetReferenceVoltageLimitValues(int pos, double& upperVal, double& lowerVal) = 0;
	//����VQC��ֵ��Ϣλ�õõ����Ʋ������ѹ��ֵ
	virtual void GetControlVoltageLockValues(int pos, double& upperVal, double& lowerVal) = 0;
	//����VQC��ֵ��Ϣλ�õõ��ο��������ѹ��ֵ
	virtual void GetReferenceVoltageLockValues(int pos, double& upperVal, double& lowerVal) = 0;
	
	//����VQC��ֵ��Ϣλ�õõ�VQC��ֵ��Ϣ
	virtual void GetVoltageSetting(int pos, VqcSettingInfo& settingInfo) = 0;
	virtual bool GetCurrentVoltageSettingByType(int typeId, VqcSettingInfo& settingInfo) = 0;
	
};

#endif
