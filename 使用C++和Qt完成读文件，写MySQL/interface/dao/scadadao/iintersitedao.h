//iintersitedao.h

#ifndef _IINTERSITEDAO_WANGXIA_20140403_H_
#define _IINTERSITEDAO_WANGXIA_20140403_H_

#include "../ibasicdao.h"                        // for IBasicDao

#define INTERSITEDAO_CLASSID    "cintersitedao"
#define INTERSITEDAO_INTFID     "iintersitedao"

class IIntersiteDao : virtual public IBasicDao
{
public:
	//根据转发站点位置得到转发站点描述
	virtual const char* GetDescription(int pos) = 0;

	//根据转发站点位置得到转发站点类型：2--SCADA转发站点（SCADANODETYPE）；6--远动转发站点（RTUNODETYPE）；8--五防转发站点（FDNODETYPE）；
	virtual int GetType(int pos) = 0;

	//根据转发站点位置得到IP地址1
	virtual const char* GetIpAddr1(int pos) = 0;
	//根据转发站点位置得到IP地址2
	virtual const char* GetIpAddr2(int pos) = 0;

	//根据转发站点位置得到端口号1
	virtual int GetPort1(int pos) = 0;
	//根据转发站点位置得到端口号2
	virtual int GetPort2(int pos) = 0;

	//根据转发站点位置得到转发站点1状态
	virtual int GetNetState1(int pos) = 0;
	//根据转发站点位置得到转发站点2状态
	virtual int GetNetState2(int pos) = 0;

	//根据转发站点ID和IP设置转发站点状态
	virtual bool SetNetState(int id, const char* strIp, int iState) = 0;
};

#endif
