//itransyddao.h

#ifndef _ITRANSYDDAO_WANGXIA_20140403_H_
#define _ITRANSYDDAO_WANGXIA_20140403_H_

#include "../ibasicdao.h"                        // for IBasicDao

#define TRANSYDDAO_CLASSID    "ctransyddao"
#define TRANSYDDAO_INTFID     "itransyddao"

class ITransydDao : virtual public IBasicDao
{
public:
	//根据远动转发量位置得到四遥测点类型
	virtual int GetMeasType(int pos) = 0;
	//根据远动转发量位置得到四遥测点ID
	virtual int GetMeasId(int pos) = 0;
	//根据远动转发量位置得到ASDU类型
	virtual int GetMsgType(int pos) = 0;

	//根据远动转发量位置得到AVC装置地址
	virtual int GetIedAddr(int pos) = 0;
	//根据远动转发量位置得到AVC信息地址
	virtual int GetInfoAddr(int pos) = 0;
	//根据远动转发量位置得到AVC扇区地址
	virtual int GetSecAddr(int pos) = 0;

	//根据远动转发量位置得到采集源号
	virtual int GetSourceNo(int pos) = 0;
	//根据远动转发量位置得到采集点号
	virtual int GetDotId(int pos) = 0;

	//根据远动转发量位置得到转发系数
	virtual double GetFactor(int pos) = 0;
};

#endif
