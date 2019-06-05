//ibussclmncfgdao.h

#ifndef _IBUSSINESSCOLUMNCONFIGDAO_PENGSHIKANG_20160429_H_
#define _IBUSSINESSCOLUMNCONFIGDAO_PENGSHIKANG_20160429_H_

#include "../ibasicdao.h"                        // for IBasicDao
#include "../../scadasrv/busscfgdef.h"           // for IExpressMap、ExpSet

#define BUSSCLMNCFGDAO_CLASSID    "cbussclmncfgdao"
#define BUSSCLMNCFGDAO_INTFID     "ibussclmncfgdao"

class IBussClmnCfgDao : virtual public IBasicDao
{
public:
	//根据业务表字段配置位置得到数据来源表名称
	virtual bool GetRtdbTableName(int pos, char* tableName) = 0;
	//根据业务表字段配置位置得到业务表主键1对应数据来源表字段名
	virtual bool GetRtdbTableMainKey1(int pos, char* keyName) = 0;
	//根据业务表字段配置位置得到业务表主键2对应数据来源表字段名
	virtual bool GetRtdbTableMainKey2(int pos, char* keyName) = 0;
	//根据业务表字段配置位置得到数据来源表的测控量类型ID
	virtual int GetRtdbTableMeasTypeId(int pos) = 0;
	//根据业务表字段配置位置得到对应的业务表名称配置表的ID
	virtual int GetBussTblCfgID(int pos) = 0;
	//根据业务表字段配置位置得到业务表信息字段名
	virtual bool GetBussTableDataColumn(int pos, char* dtFldName) = 0;
	//根据业务表配置表ID得到对应的业务表配置信息
	virtual BussTbl* GetBussTblByTblCfgId(int nTblCfgId) = 0;
};

#endif
