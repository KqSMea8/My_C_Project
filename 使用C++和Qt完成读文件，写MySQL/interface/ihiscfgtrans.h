// ihiscfgtrans.h
#ifndef _IHISCFGTRANS_H_
#define _IHISCFGTRANS_H_

//#include "icsunknown.h" // for IICSUnknown
#include "../include/common/intfobject.h"

#define DLL_HISCFGTRANS	"hiscfgtrans"
#define IID_HISCFGTRANS	"IHisCfgTrans"
#define CID_HISCFGTRANS	"CHisCfgTrans"

#include <vector>

class IHisCfgTrans: public CIntfObject
{
public:

	/*
	 数据首次同步
	 0.成功；1.读取icssetting失败；2.连接配置库失败；3.连接历史库1失败；4.连接历史库2失败；
	 5.历史库1sql语句执行失败；6.历史库2sql语句执行失败;7.读取hdbsynchro.sql失败
	 */
	virtual int HisCfgdataTrans() = 0; 

	/*
	配置库数据更新
	0.成功；1.读取icssetting失败；2.连接配置库失败；3.连接历史库1失败；4.连接历史库2失败；
	5.历史库1sql语句执行失败；6.历史库2sql语句执行失败;7.读取hdbsynchro.sql失败
	*/
	virtual int updateCfg() = 0; 

};

#endif
