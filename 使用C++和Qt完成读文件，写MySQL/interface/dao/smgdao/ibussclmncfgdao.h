//ibussclmncfgdao.h

#ifndef _IBUSSINESSCOLUMNCONFIGDAO_PENGSHIKANG_20160429_H_
#define _IBUSSINESSCOLUMNCONFIGDAO_PENGSHIKANG_20160429_H_

#include "../ibasicdao.h"                        // for IBasicDao
#include "../../scadasrv/busscfgdef.h"           // for IExpressMap��ExpSet

#define BUSSCLMNCFGDAO_CLASSID    "cbussclmncfgdao"
#define BUSSCLMNCFGDAO_INTFID     "ibussclmncfgdao"

class IBussClmnCfgDao : virtual public IBasicDao
{
public:
	//����ҵ����ֶ�����λ�õõ�������Դ������
	virtual bool GetRtdbTableName(int pos, char* tableName) = 0;
	//����ҵ����ֶ�����λ�õõ�ҵ�������1��Ӧ������Դ���ֶ���
	virtual bool GetRtdbTableMainKey1(int pos, char* keyName) = 0;
	//����ҵ����ֶ�����λ�õõ�ҵ�������2��Ӧ������Դ���ֶ���
	virtual bool GetRtdbTableMainKey2(int pos, char* keyName) = 0;
	//����ҵ����ֶ�����λ�õõ�������Դ��Ĳ��������ID
	virtual int GetRtdbTableMeasTypeId(int pos) = 0;
	//����ҵ����ֶ�����λ�õõ���Ӧ��ҵ����������ñ��ID
	virtual int GetBussTblCfgID(int pos) = 0;
	//����ҵ����ֶ�����λ�õõ�ҵ�����Ϣ�ֶ���
	virtual bool GetBussTableDataColumn(int pos, char* dtFldName) = 0;
	//����ҵ������ñ�ID�õ���Ӧ��ҵ���������Ϣ
	virtual BussTbl* GetBussTblByTblCfgId(int nTblCfgId) = 0;
};

#endif
