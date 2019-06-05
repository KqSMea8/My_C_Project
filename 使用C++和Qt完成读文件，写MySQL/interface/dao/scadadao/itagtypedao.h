//itagtypedao.h

#ifndef _ITAGTYPEDAO_PENGSHIKANG_20100821_H_
#define _ITAGTYPEDAO_PENGSHIKANG_20100821_H_

#include "../ibasicdao.h"                        // for IBasicDao

#define TAGTYPEDAO_CLASSID    "ctagtypedao"
#define TAGTYPEDAO_INTFID     "itagtypedao"

class ITagTypeDao : virtual public IBasicDao
{
public:
	//���ݹ�������λ�õõ�����
	virtual const char* GetDescription(int pos) = 0;
	//���ݹ�������λ�õõ��Ƿ��������־
	virtual bool CanProcessFlag(int pos) = 0;
};

#endif
