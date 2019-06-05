//iisdmainpsdao.h
//----0810_zff_new_add----------------------//
#ifndef _IISDMAINPSDAO_ZHANGFEIFEI_20120810_H_
#define _IISDMAINPSDAO_ZHANGFEIFEI_20120810_H_

#include "../ibasicdao.h"                        // for IBasicDao

#define ISDMAINPSDAO_CLASSID    "cisdmainpsdao"
#define ISDMAINPSDAO_INTFID     "iisdmainpsdao"

class IIsdmainpsDao : virtual public IBasicDao
{
public:
	//根据设备ID得到微电网运行方式主电源表记录的位置
	virtual int GetPositionByEquipID(int eqpId, int runType) = 0;

	//根据微电网运行方式主电源位置得到运行方式ID
	virtual int GetRunStyleID(int pos) = 0;
    //根据微电网运行方式主电源位置得到设备ID
    virtual int GetEquipID(int pos) = 0;
    //根据微电网运行方式主电源位置得到启动优先级
	virtual int GetPriority(int pos) = 0;
	//根据微电网运行方式主电源位置得到离网目标功率控制是否生效
	virtual int IsEnableAimPower(int pos) = 0; 
	//根据微电网运行方式主电源位置得到离网最大目标功率
	virtual double GetMaxAimPower(int pos) = 0;
	//根据微电网运行方式主电源位置得到离网最小目标功率
	virtual double GetMinAimPower(int pos) = 0;
	
	//根据主发电设备ID累加主发电设备的总目标功率
	virtual bool AccumulateMainAimPower(int runType, int eqpId, float& minAimP, float& maxAimP) = 0;
};

#endif