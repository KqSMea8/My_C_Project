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
	//���ݳ�վID��ü�¼ID����
	virtual bool FindObjectsByStationId(int stationId, int*& idSet, int& count) = 0;
	//���ݳ�վ���������¼ID�õ���վ�������ַ���
	virtual const char* GetStationAreaIdById(int id) = 0;
	//���ݳ�վID��ó�վ����������
	virtual bool GetStationAreaIDs(int stationId, std::vector<std::string>& coll) = 0;
};

#endif
