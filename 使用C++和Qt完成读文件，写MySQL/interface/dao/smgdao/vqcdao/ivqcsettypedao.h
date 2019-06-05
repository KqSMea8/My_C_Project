//ivqcsettypedao.h

#ifndef _IVQCSETTINGTYPEDAO_PENGSHIKANG_20120531_H_
#define _IVQCSETTINGTYPEDAO_PENGSHIKANG_20120531_H_

#include "../../ibasicdao.h"                     // for IBasicDao

#define VQCSETTYPEDAO_CLASSID    "cvqcsettypedao"
#define VQCSETTYPEDAO_INTFID     "ivqcsettypedao"

class IVqcSetTypeDao : virtual public IBasicDao
{
public:
	//根据VQC定值类型位置得到无功\功率因素定值属性
	virtual int GetQCtrlMode(int pos) = 0;
	//根据VQC定值类型位置无功调节目标是否为无功
	virtual bool TargetIsRp(int pos) = 0;
	//根据VQC定值类型位置是否允许无功倒送
	virtual bool CanRpReverse(int pos) = 0;
	//根据VQC定值类型位置得到无功倒送上限
	virtual double GetMaxRpReverse(int pos) = 0;
	//根据VQC定值类型位置得到VQC调节策略类型
	virtual int GetStrategyType(int pos) = 0;
	//根据VQC定值类型位置读取是否有效标志
	virtual int IsEnable(int pos) = 0;
};

#endif
