//isoedao.h

#ifndef _ISOEDAO_PENGSHIKANG_20090217_H_
#define _ISOEDAO_PENGSHIKANG_20090217_H_

#include "icsfdao.h"                             // for ICsfDao
#include "icsfalmintf.h"                         // for ICsfAlarmIntf

#define SOEDAO_CLASSID    "csoedao"
#define SOEDAO_INTFID     "isoedao"

class ISoeDao : virtual public ICsfDao, virtual public ICsfAlarmIntf
{
public:
	//���ݲɼ�����Դ�Ͳɼ���λ�õõ�SOE��λ��
	virtual int GetPositionByCommSrcID(int nSrcId, int nPntId) = 0;
	//����SOE��λ������SOEֵ(��ǰʱ�䡢�ɼ�ֵ������״̬)
	virtual bool SetSoeData(int pos, double dTime, int nValue, int nState) = 0;
	//����SOE��λ�õõ��ɼ�ֵ
	virtual int GetRawValue(int pos) = 0;
	//����SOE��ID�õ��ɼ�ֵ[�ɶ�������]
	virtual int GetRawValueById(int id, bool bRequery=false) = 0;
};

#endif
