//ibayareadao.h

#ifndef _IBAYAREADAO_PENGSHIKANG_20140120_H_
#define _IBAYAREADAO_PENGSHIKANG_20140120_H_

#include "../ibasicdao.h"                        // for IBasicDao
#include <string>
#include <vector>

#define BAYAREADAO_CLASSID    "cbayareadao"
#define BAYAREADAO_INTFID     "ibayareadao"

class IBayAreaDao : virtual public IBasicDao
{
public:
	//根据间隔ID获得记录ID集合
	virtual bool FindObjectsByBayId(int bayId, int*& idSet, int& count) = 0;
	//根据间隔责任区表记录ID得到间隔责任区字符串
	virtual const char* GetBayAreaIdById(int id) = 0;
	//根据间隔ID获得间隔责任区集合
	virtual bool GetBayAreaIDs(int bayId, std::vector<std::string>& coll) = 0;
};

#endif
