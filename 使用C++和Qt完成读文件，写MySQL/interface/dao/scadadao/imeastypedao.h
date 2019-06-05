//imeastypedao.h

#ifndef _IMEASTYPEDAO_PENGSHIKANG_20130310_H_
#define _IMEASTYPEDAO_PENGSHIKANG_20130310_H_

#include "../ibasicdao.h"                        // for IBasicDao

#define MEASTYPEDAO_CLASSID    "cmeastypedao"
#define MEASTYPEDAO_INTFID     "imeastypedao"

class IMeasTypeDao : virtual public IBasicDao
{
public:
	//根据量测类型量位置得到是否修改遥调值
	virtual int GetYtValChangFlag(int pos) = 0;
	//根据量测类型量位置得到遥调目标值比例系数
	virtual double GetYtAimValCoff(int pos) = 0;
	//根据量测类型量位置得到遥调目标值是否取整
	virtual int GetYtAimvalInt(int pos) = 0;
	//根据量测类型量位置和遥调目标值获取遥调控制值
	virtual void TakeCtrlValueByAimValue(int pos, double aimValue, float& ctrlValue) = 0;
};

#endif
