//ibusconndao.h

#ifndef _IBUSCONNECTDAO_PENGSHIKANG_20120522_H_
#define _IBUSCONNECTDAO_PENGSHIKANG_20120522_H_

#include "../ibasicdao.h"                        // for IBasicDao

#define BUSCONNDAO_CLASSID    "cbusconndao"
#define BUSCONNDAO_INTFID     "ibusconndao"

class IBusConnDao : virtual public IBasicDao
{
public:
	//初始化所有的母线邻居关系信息
	virtual void InitAllBusNaborStaticInfo() = 0;
	
	//根据母线连接关系位置得到母线1和母线2的ID
	virtual bool GetBus1AndBus2ID(int pos, int& bus1Id, int& bus2Id) = 0;
	
	//根据母线连接关系位置得到连接断路器状态量ID
	virtual int GetPosID(int pos) = 0;
	//根据母线连接关系位置得到连接断路器状态量值
	virtual int GetCurPos(int pos) = 0;
	//根据母线连接关系位置设置连接断路器状态量值
	virtual int SetCurPos(int pos, int nValue) = 0;
	
	//根据母线连接关系的位置设置各个量测量实时值
	virtual bool SetMeasureValues(int pos, int& nBrkPos) = 0;
};

#endif
