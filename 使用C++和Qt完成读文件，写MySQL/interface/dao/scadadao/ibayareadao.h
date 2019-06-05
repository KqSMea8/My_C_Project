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
	//���ݼ��ID��ü�¼ID����
	virtual bool FindObjectsByBayId(int bayId, int*& idSet, int& count) = 0;
	//���ݼ�����������¼ID�õ�����������ַ���
	virtual const char* GetBayAreaIdById(int id) = 0;
	//���ݼ��ID��ü������������
	virtual bool GetBayAreaIDs(int bayId, std::vector<std::string>& coll) = 0;
};

#endif
