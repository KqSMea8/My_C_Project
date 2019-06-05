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
	//根据业务表名配置位置得到业务表名称
	virtual bool GetBussTableName(int pos, char* tableName) = 0;
	//根据业务表名配置位置得到业务表主键1名称
	virtual bool GetBussTableMainKey1(int pos, char* keyName) = 0;
	//根据业务表名配置位置得到业务表主键2名称
	virtual bool GetBussTableMainKey2(int pos, char* keyName) = 0;
	//根据业务表名配置位置得到业务表信息更新周期定时器ID
	virtual int GetBussInfoUpdateTimerId(int pos) = 0;
	//根据定时器类型ID得到对应的业务表配置表信息集合
	virtual BussTblSet* GetBussTblSetByTimerId(int nTimerId) = 0;
};

#endif
