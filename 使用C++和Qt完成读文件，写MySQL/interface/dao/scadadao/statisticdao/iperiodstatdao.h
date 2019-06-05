//iperiodstatdao.h

#ifndef _IDATAPERIODSTATISTICSDAO_PENGSHIKANG_20130310_H_
#define _IDATAPERIODSTATISTICSDAO_PENGSHIKANG_20130310_H_

#include "istatisticdao.h"                       // for IStatisticDao

#define PERIODSTATDAO_CLASSID    "cperiodstatdao"
#define PERIODSTATDAO_INTFID     "iperiodstatdao"

class IPeriodStatDao : virtual public IStatisticDao
{
public:
	//�������ݶ���ID�õ�ʱ��ͳ�Ƽ�¼��λ��
	virtual int GetPositionByID(int nObjId, int nPrdId) = 0;
	virtual int GetObjectIdByPos(int pos) = 0;
	virtual bool InitAllPrdStatValues(int nObjId, double curTime) = 0;

protected:
	//�������ݶ���ID�ֶ�����
	virtual void SetIndex_DataId(int idxDataId) = 0;
	//�õ�ʱ������ID�ֶ�����
	virtual int GetIndex_PeriodType() = 0;
	virtual bool InitOnePrdStatValue(int nObjPos, double curTime) = 0;
};

#endif
