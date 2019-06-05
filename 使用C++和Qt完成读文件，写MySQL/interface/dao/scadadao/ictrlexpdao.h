//ictrlexpdao.h

#ifndef _ICTRLEXPDAO_PENGSHIKANG_20130310_H_
#define _ICTRLEXPDAO_PENGSHIKANG_20130310_H_

#include "../ibasicdao.h"                        // for IBasicDao

#define CTRLEXPDAO_CLASSID    "cctrlexpdao"
#define CTRLEXPDAO_INTFID     "ictrlexpdao"

class ICtrlExpDao : virtual public IBasicDao
{
public:	
	//根据遥控量类型和遥控值得到遥控条件处理位置
	virtual int GetPositionByCtrlValTyp(int nCtrlId, int nValTypId) = 0;
	
	//根据遥控条件量位置得到操作条件表达式
	virtual const char* GetOperatExpress(int pos) = 0;
};

#endif
