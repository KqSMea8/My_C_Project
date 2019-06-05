//ictrlworddefdao.h

#ifndef _ICTRLWORDDEFINEDAO_PENGSHIKANG_20131224_H_
#define _ICTRLWORDDEFINEDAO_PENGSHIKANG_20131224_H_

#include "../ibasicdao.h"                        // for IBasicDao

#define CTRLWORDDEFDAO_CLASSID    "cctrlworddefdao"
#define CTRLWORDDEFDAO_INTFID     "ictrlworddefdao"

//���������Ͷ���
class ICtrlWordDefDao : virtual public IBasicDao
{
public:
	//���ݿ��������ͼ�¼λ�õõ�ָ��λ��λ����
	virtual bool GetBitMeaning(int pos, int nBit, char* strMeaning) = 0;
};

#endif
