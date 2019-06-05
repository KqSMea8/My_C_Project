//ibusstblcfgdao.h

#ifndef _IBUSSINESSTABLECONFIGDAO_PENGSHIKANG_20160429_H_
#define _IBUSSINESSTABLECONFIGDAO_PENGSHIKANG_20160429_H_

#include "../ibasicdao.h"                        // for IBasicDao
#include "../../scadasrv/busscfgdef.h"           // for BussTblSet

#define BUSSTBLCFGDAO_CLASSID    "cbusstblcfgdao"
#define BUSSTBLCFGDAO_INTFID     "ibusstblcfgdao"

class IBussTblCfgDao : virtual public IBasicDao
{
public:
	//����ҵ���������λ�õõ�ҵ�������
	virtual bool GetBussTableName(int pos, char* tableName) = 0;
	//����ҵ���������λ�õõ�ҵ�������1����
	virtual bool GetBussTableMainKey1(int pos, char* keyName) = 0;
	//����ҵ���������λ�õõ�ҵ�������2����
	virtual bool GetBussTableMainKey2(int pos, char* keyName) = 0;
	//����ҵ���������λ�õõ�ҵ�����Ϣ�������ڶ�ʱ��ID
	virtual int GetBussInfoUpdateTimerId(int pos) = 0;
	//���ݶ�ʱ������ID�õ���Ӧ��ҵ������ñ���Ϣ����
	virtual BussTblSet* GetBussTblSetByTimerId(int nTimerId) = 0;
};

#endif
