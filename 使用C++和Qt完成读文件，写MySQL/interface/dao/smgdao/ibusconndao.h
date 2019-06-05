//ibusconndao.h

#ifndef _IBUSCONNECTDAO_PENGSHIKANG_20120522_H_
#define _IBUSCONNECTDAO_PENGSHIKANG_20120522_H_

#include "../ibasicdao.h"                        // for IBasicDao

#define BUSCONNDAO_CLASSID    "cbusconndao"
#define BUSCONNDAO_INTFID     "ibusconndao"

class IBusConnDao : virtual public IBasicDao
{
public:
	//��ʼ�����е�ĸ���ھӹ�ϵ��Ϣ
	virtual void InitAllBusNaborStaticInfo() = 0;
	
	//����ĸ�����ӹ�ϵλ�õõ�ĸ��1��ĸ��2��ID
	virtual bool GetBus1AndBus2ID(int pos, int& bus1Id, int& bus2Id) = 0;
	
	//����ĸ�����ӹ�ϵλ�õõ����Ӷ�·��״̬��ID
	virtual int GetPosID(int pos) = 0;
	//����ĸ�����ӹ�ϵλ�õõ����Ӷ�·��״̬��ֵ
	virtual int GetCurPos(int pos) = 0;
	//����ĸ�����ӹ�ϵλ���������Ӷ�·��״̬��ֵ
	virtual int SetCurPos(int pos, int nValue) = 0;
	
	//����ĸ�����ӹ�ϵ��λ�����ø���������ʵʱֵ
	virtual bool SetMeasureValues(int pos, int& nBrkPos) = 0;
};

#endif
