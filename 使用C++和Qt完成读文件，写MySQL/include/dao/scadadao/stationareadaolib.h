// stationareadaolib.h: implement for the CStationAreaDao class.
#ifndef _STATIONAREADAOLIB_20140120_PENGSHIKANG_H_
#define _STATIONAREADAOLIB_20140120_PENGSHIKANG_H_

#include "../../commgr/intfobjptrb.h"       // for CIntfObjPtrB
#include "../../../interface/dao/scadadao/istationareadao.h" // for IStationAreaDao

//DLL输出的接口对象引用
class CStationAreaDao : public CIntfObjPtrB<IStationAreaDao>
{
public:
	CStationAreaDao() : CIntfObjPtrB<IStationAreaDao>
		(SCADADAO_MODULE, STATIONAREADAO_CLASSID, STATIONAREADAO_INTFID) { }
};

#endif 