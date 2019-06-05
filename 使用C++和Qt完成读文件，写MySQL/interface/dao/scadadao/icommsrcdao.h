//icommsrcdao.h

#ifndef _ICOMMSRCDAO_PENGSHIKANG_20130310_H_
#define _ICOMMSRCDAO_PENGSHIKANG_20130310_H_

#include "../ibasicdao.h"                        // for IBasicDao

#define COMMSRCDAO_CLASSID    "ccommsrcdao"
#define COMMSRCDAO_INTFID     "icommsrcdao"

class ICommSrcDao : virtual public IBasicDao
{
public:	
	//根据数据采集源ID得到采集源厂站名称
	virtual const char* GetNameById(int id) = 0;
	//得到数据采集源的通道状态
	virtual int GetCommSrcState(int pos, bool isAChnl=true) = 0;
	virtual bool IsConnected(int pos) = 0;
	//设置数据采集源的通道状态
	virtual bool SetCommSrcState(int pos, int state) = 0;
	virtual bool SetCommSrcState2(int pos, int state) = 0;
	//设置数据采集源初始状态信息为0
	virtual void InitializeSatate() = 0;

	//根据数据采集源位置得到所属间隔ID
	virtual int GetBayId(int pos) = 0;
	//根据数据采集源位置得到所属厂站ID
	virtual int GetStationId(int pos) = 0;

	//是否存在双源
	virtual bool IsMultCommSrc(int pos) = 0;
	//得到同胞数据源ID
	virtual int GetBrotherSrcId(int pos) = 0;
	//得到同胞数据源位置+
	virtual int GetBrotherSrcPos(int pos) = 0;
	//主备状态的状态量ID
	virtual int GetRoleStatusID(int pos) = 0;
	//是否为主数据源
	virtual bool IsMainCommsrcFlag(int pos) = 0;
	//设置主数据源标志+
	virtual bool SetMainCommsrcFlag(int pos, bool isMain) = 0;
};

#endif
