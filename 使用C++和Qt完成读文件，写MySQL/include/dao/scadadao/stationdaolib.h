// stationdaolib.h: implement for the CStationDao class.
#ifndef _STATIONDAOLIB_20130311_PENGSHIKANG_H_
#define _STATIONDAOLIB_20130311_PENGSHIKANG_H_

#include "../../commgr/intfobjptrb.h"       // for CIntfObjPtrB
#include "../../../interface/dao/scadadao/istationdao.h"    // for IStationDao

//DLL输出的接口对象引用
class CStationDao : public CIntfObjPtrB<IStationDao>
{
public:
	CStationDao() : CIntfObjPtrB<IStationDao>
		(SCADADAO_MODULE, STATIONDAO_CLASSID, STATIONDAO_INTFID) { }
};

#endif 