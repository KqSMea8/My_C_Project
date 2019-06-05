//ivqcparamdao.h

#ifndef _IVQCPARAMETERDAO_PENGSHIKANG_20120503_H_
#define _IVQCPARAMETERDAO_PENGSHIKANG_20120503_H_

#include "../../ibasicdao.h"                     // for IBasicDao

#define VQCPARAMDAO_CLASSID    "cvqcparamdao"
#define VQCPARAMDAO_INTFID     "ivqcparamdao"

class IVqcParamDao : virtual public IBasicDao
{
public:
	//得到系统躲扰动时间(秒)
	virtual int GetCsDisturbTime() = 0;
	//得到母线幅值不平衡度闭锁限值(标么)
	virtual double GetBalanceOfBusU() = 0;
	//得到变压器滑档判断时间(秒)
	virtual int GetSlipCheckTime() = 0;
	//得到变压器高压侧最大档位差
	virtual int GetMaxTapDiff() = 0;
	//得到VQC定值类型
	virtual int GetSettingTypeId() = 0;
	//得到电压无功控制类型
	// 0：降压站VQC；1：升压站VQC；2：降压站AVC子站；3：升压站AVC子站；4:  AVC主站。
	virtual int GetStationFlag() = 0;
	//得到当前调节系统个数
	virtual int GetAdjustAreaNum() = 0;
	//设置当前调节系统个数
	virtual bool SetAdjustAreaNum(int areaNum) = 0;
	//得到无功/功率因数调节死区百分值（%）
	virtual double GetRfPlusMargin() = 0;
	//得到当前电压调节死区百分值（%）
	virtual double GetVolPlusMargin() = 0;
	//电压无功最大连续控制次数
	virtual int GetMaxCtrlTimes() = 0;

	//得到两次电压指令超限闭锁定值
	virtual double GetVoltDiffLockValue() = 0;
};

#endif
