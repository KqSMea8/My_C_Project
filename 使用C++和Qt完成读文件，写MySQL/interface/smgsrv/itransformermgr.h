//itransformermgr.h


#ifndef _ITRANSFORMERMGR_ZHANGPENG_20130301_H_
#define _ITRANSFORMERMGR_ZHANGPENG_20130301_H_

#define TRANSFORMERMANAGER_CLASSID    "cTransformerMgr"
#define TRANSFORMERMANAGER_INTFID     "iTransformerMgr"

#include "../icsunknown.h"                       // for IICSUnknown
#include "vqcdatadef.h"                          // for VQCAreaInfo

class ITransformerMgr : virtual public IICSUnknown 
{
public:
	//���ڱ�ѹ���ֽ�ͷ
	virtual bool AdjustTransformerTap(VQCAreaInfo* pCurVQCArea, bool bAscend) = 0;
	//���ڷֽ�ͷ��λ���ѹ����ѹ��ĵ�ѹ�仯
	virtual bool TestVoltageChange(int pos, int windingNo, bool bAscend, int nBusID, float* pCurU) = 0;
};

#endif  //_ITRANSFORMERMGR_ZHANGPENG_20130301_H_
