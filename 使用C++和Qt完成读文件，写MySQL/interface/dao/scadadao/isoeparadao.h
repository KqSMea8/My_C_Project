//isoeparadao.h

#ifndef _ISOEPARAMETERDAO_PENGSHIKANG_20090217_H_
#define _ISOEPARAMETERDAO_PENGSHIKANG_20090217_H_

#include "../ibasicdao.h"                        // for IBasicDao

#define SOEPARADAO_CLASSID    "csoeparadao"
#define SOEPARADAO_INTFID     "isoeparadao"

class ISoeParaDao : virtual public IBasicDao
{
public:
	//���ݲ�����ֵ���ͺ���ŵõ�SOE������λ��
	virtual int GetSoeParaPosBySeqNo(int nValType, int nSeqNo) = 0;
	//����SOE������λ�õõ����������ID
	virtual int GetMeasType(int pos) = 0;
	//����SOE������λ�õõ�������λID
	virtual int GetUnitId(int pos) = 0;
};

#endif
