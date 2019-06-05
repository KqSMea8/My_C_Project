//icontrolsrcdao.h

#ifndef _ICONTROLSRCDAO_PENGSHIKANG_20180801_H_
#define _ICONTROLSRCDAO_PENGSHIKANG_20180801_H_

#include "../ibasicdao.h"                        // for IBasicDao
#include "../../icsvalue.h"                      // for icsvariant
#include "imultsrcobj.h"                         // for IMultSrcObj
#include <q3sortedlist.h>                        // for Q3SortedList

#define CTRLSRCDAO_CLASSID    "ccontrolsrcdao"
#define CTRLSRCDAO_INTFID     "icontrolsrcdao"

class IControlSrcDao : virtual public IBasicDao
{
public:
	//得到字段索引集
	virtual void GetFieldIndexs() = 0;
	//读取数据表的静态信息
	virtual void ReadStaticInfo(int fldNum=0, const char nameList[][64]=0, const char* strFilter="DELETEFLAG==0", bool onlyRead=false) = 0;

	//根据多数据源位置得到遥控量ID
	virtual int GetControlId(int pos) = 0;
	//根据多数据源位置得到数据采集源ID
	virtual int GetCommsrcId(int pos) = 0;
	//根据多数据源位置得到数据采集源点ID
	virtual int GetPointId(int pos) = 0;
	//根据多数据源位置得到优先级
	virtual int GetPriority(int pos) = 0;

	//根据数据对象ID得到对应的多数据源对象集
	virtual Q3SortedList<IMultSrcObj>* GetMultSrcSetByObjectId(int nObjId) = 0;

	//根据控点对象ID和数据源ID得到多数据源对象
	virtual IMultSrcObj* GetMultSrcObjByObjectID(int nObjId, int nSrcId) = 0;

};

#endif
