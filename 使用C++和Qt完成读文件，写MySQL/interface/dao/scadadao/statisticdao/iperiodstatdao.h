//iperiodstatdao.h

#ifndef _IDATAPERIODSTATISTICSDAO_PENGSHIKANG_20130310_H_
#define _IDATAPERIODSTATISTICSDAO_PENGSHIKANG_20130310_H_

#include "istatisticdao.h"                       // for IStatisticDao

#define PERIODSTATDAO_CLASSID    "cperiodstatdao"
#define PERIODSTATDAO_INTFID     "iperiodstatdao"

class IPeriodStatDao : virtual public IStatisticDao
{
public:
	//根据数据对象ID得到时段统计记录的位置
	virtual int GetPositionByID(int nObjId, int nPrdId) = 0;
	virtual int GetObjectIdByPos(int pos) = 0;
	virtual bool InitAllPrdStatValues(int nObjId, double curTime) = 0;

protected:
	//设置数据对象ID字段索引
	virtual void SetIndex_DataId(int idxDataId) = 0;
	//得到时段类型ID字段索引
	virtual int GetIndex_PeriodType() = 0;
	virtual bool InitOnePrdStatValue(int nObjPos, double curTime) = 0;
};

#endif
