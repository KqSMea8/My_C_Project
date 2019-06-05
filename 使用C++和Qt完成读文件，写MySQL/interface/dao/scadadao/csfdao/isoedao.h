//isoedao.h

#ifndef _ISOEDAO_PENGSHIKANG_20090217_H_
#define _ISOEDAO_PENGSHIKANG_20090217_H_

#include "icsfdao.h"                             // for ICsfDao
#include "icsfalmintf.h"                         // for ICsfAlarmIntf

#define SOEDAO_CLASSID    "csoedao"
#define SOEDAO_INTFID     "isoedao"

class ISoeDao : virtual public ICsfDao, virtual public ICsfAlarmIntf
{
public:
	//根据采集数据源和采集点位置得到SOE量位置
	virtual int GetPositionByCommSrcID(int nSrcId, int nPntId) = 0;
	//根据SOE量位置设置SOE值(当前时间、采集值、操作状态)
	virtual bool SetSoeData(int pos, double dTime, int nValue, int nState) = 0;
	//根据SOE量位置得到采集值
	virtual int GetRawValue(int pos) = 0;
	//根据SOE量ID得到采集值[可独立调用]
	virtual int GetRawValueById(int id, bool bRequery=false) = 0;
};

#endif
