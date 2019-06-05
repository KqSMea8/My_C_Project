//istationareadao.h

#ifndef _ISTATIONAREADAO_PENGSHIKANG_20140120_H_
#define _ISTATIONAREADAO_PENGSHIKANG_20140120_H_

#include "../ibasicdao.h"                        // for IBasicDao
#include <string>
#include <vector>

#define STATIONAREADAO_CLASSID    "cstationareadao"
#define STATIONAREADAO_INTFID     "istationareadao"

class IStationAreaDao : virtual public IBasicDao
{
public:
	//根据厂站ID获得记录ID集合
	virtual bool FindObjectsByStationId(int stationId, int*& idSet, int& count) = 0;
	//根据厂站责任区表记录ID得到厂站责任区字符串
	virtual const char* GetStationAreaIdById(int id) = 0;
	//根据厂站ID获得厂站责任区集合
	virtual bool GetStationAreaIDs(int stationId, std::vector<std::string>& coll) = 0;
};

#endif
