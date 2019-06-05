// weatherdaolib.h: implement for the CWeatherDao class.
#ifndef _WEATHERDAOLIB_20130311_ZHANGPENG_H_
#define _WEATHERDAOLIB_20130311_ZHANGPENG_H_

#include "../../commgr/intfobjptrb.h"            // for CIntfObjPtrB
#include "../../../interface/dao/smgdao/iweatherdao.h"// for IWeatherDao

class IAnalogDao;

//DLL输出的接口对象引用
class CWeatherDao : public CIntfObjPtrB<IWeatherDao>
{
public:
	CWeatherDao(IAnalogDao* pAnalog) : CIntfObjPtrB<IWeatherDao>
		(SMGDAO_MODULE, WEATHERDAO_CLASSID, WEATHERDAO_INTFID, (void**)&pAnalog) { }
};

#endif
