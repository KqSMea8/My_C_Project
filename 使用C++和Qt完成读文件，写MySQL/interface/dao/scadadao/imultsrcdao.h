//imultsrcdao.h

#ifndef _IMULTSRCDAO_PENGSHIKANG_20081204_H_
#define _IMULTSRCDAO_PENGSHIKANG_20081204_H_

#include "../ibasicdao.h"                        // for IBasicDao
#include "../../icsvalue.h"                      // for icsvariant
#include "imultsrcobj.h"                         // for IMultSrcObj
#include <q3sortedlist.h>                        // for Q3SortedList

#define MULTSRCDAO_CLASSID    "cmultsrcdao"
#define MULTSRCDAO_INTFID     "imultsrcdao"

class IMultSrcDao : virtual public IBasicDao
{
public:
	//根据采集数据源和采集点位置得到数据源位置
	virtual int GetPositionByID(int nSrcId, int nPntId, int& nObjId, bool bRequery=false) = 0;
	//设置多数据源处理结果
	virtual bool SetMultSrcValue(int pos, void* pRawValue, double rawTime, int nQuality) = 0;
	virtual bool SetMultSrcQuality(int pos, int nQuality) = 0;

	virtual bool GetMultSrcValue(int pos, icsvariant& rawValue, double& rawTime, int& nQuality) = 0;
	
	//根据数据对象ID得到对应的多数据源对象集
	virtual Q3SortedList<IMultSrcObj>* GetMultSrcSetByObjectId(int nObjId) = 0;	

	//根据多源数据表位置得到对应的采集数据源的源号和点号
	virtual bool GetCommSrcID(int pos, int& nSrcId, int& nPntId) = 0;

	//根据控点对象ID和数据源ID得到多数据源对象
	virtual IMultSrcObj* GetMultSrcObjByObjectID(int nObjId, int nSrcId) = 0;

	//根据多源数据表位置得到对应的采集数据值
	virtual icsvalue GetMultSrcRawValue(int pos) = 0;

	//根据多源数据表位置得到对应的采集数据对象ID
	virtual int GetDataObjectID(int pos) = 0;
};

#endif
