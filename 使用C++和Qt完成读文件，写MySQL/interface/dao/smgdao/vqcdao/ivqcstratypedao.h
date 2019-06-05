//ivqcstratypedao.h

#ifndef _IVQCSTRATEGYTYPEDAO_PENGSHIKANG_20160819_H_
#define _IVQCSTRATEGYTYPEDAO_PENGSHIKANG_20160819_H_

#include "../../ibasicdao.h"                     // for IBasicDao

#define VQCSTRATYPEDAO_CLASSID    "cvqcstratypedao"
#define VQCSTRATYPEDAO_INTFID     "ivqcstratypedao"

class IVqcStraTypeDao : virtual public IBasicDao
{
public:
	//根据VQC策略类型位置得到电压无功控制厂站类型
	//    0：降压站VQC；1：升压站VQC；2：降压站AVC子站；3：升压站AVC子站；4:  AVC主站。
	virtual int GetStationFlag(int pos) = 0;
	//根据VQC策略类型位置得到电压无功控制策略类型
	//    1：综合优化，2：电压优先,	3：无功优先, 4：只调电压, 5：只调无功
	virtual int GetVqcStrategyType(int pos) = 0;
	//根据VQC策略类型ID得到电压无功控制策略类型
	//    1：综合优化，2：电压优先,	3：无功优先, 4：只调电压, 5：只调无功
	virtual int GetVqcStrategyTypeByID(int id) = 0;
};

#endif
