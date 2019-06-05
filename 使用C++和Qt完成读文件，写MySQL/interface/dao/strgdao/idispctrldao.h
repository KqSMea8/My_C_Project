//idispctrldao.h

#ifndef _IDISPCTRLDAO_20190531_YANGZHENYU_H_
#define _IDISPCTRLDAO_20190531_YANGZHENYU_H_

#include "../ibasicdao.h"                             // for IMgdDao

#define DISPCTRLDAO_CLASSID    "csdispctrldao"
#define DISPCTRLDAO_INTFID     "isdispctrldao"


class IDispctrldao : virtual public IBasicDao
{
public:	
	//静态
	//根据厂站控制区位置得到控制区ID
	virtual int GetPctrlID(int pos) = 0;
	//根据厂站控制区位置得到接收上级调度有功控制压板id
	virtual int GetReceivflagID(int pos) = 0;
	//根据厂站控制区位置得到上级有功调度值id
	virtual int GetDispatchpvalID(int pos) = 0;
	//根据厂站控制区位置得到上级有功调度控制超期时间(分钟)
	virtual double GetDispatchoverdue(int pos) = 0;

	//动态
	//根据厂站控制区位置得到有功控制总压板
	virtual int GetPctrlflag(int pos) = 0;
	//根据厂站控制区位置设置有功控制总压板
	virtual bool SetPctrlflag(int pos, int value) = 0;

	//根据厂站控制区位置得到上一级调度系统压板
	virtual int GetAgcreceivflag(int pos) = 0;
	//根据厂站控制区位置设置上一级调度系统压板
	virtual int SetSgcreceivflag(int pos, int value) = 0;

	//根据厂站控制区位置得到上一级调度系统调度值
	virtual double GetDispatchpVal(int pos) = 0;
	//根据厂站控制区位置设置上一级调度系统调度值
	virtual double SetSispatchpVal(int pos, double value) = 0;

	//根据厂站控制区位置得到上一级调度系统调度时间
	virtual double GetDispatchpTime(int pos) = 0;
	//根据厂站控制区位置设置上一级调度系统调度时间
	virtual bool SetSispatchpTime(int pos, double value) = 0;

	//根据厂站控制区位置得到上一次日前计划时间
	virtual double GetLastdayTime(int pos) = 0;
	//根据厂站控制区位置设置上一次日前计划时间
	virtual bool SetLastdayTime(int pos, double value) = 0;

	//根据厂站控制区位置得到上一次日内计划时间
	virtual double GetIndayTime(int pos) = 0;
	//根据厂站控制区位置设置上一次日内计划时间
	virtual bool SetIndayTime(int pos, double value) = 0;

	//根据厂站控制区位置得到本地有功调度设定值
	virtual double GetLocalpVal(int pos) = 0;
	//根据厂站控制区位置设置本地有功调度设定值
	virtual bool SetLocalpVal(int pos, double value) = 0;

	//根据厂站控制区位置得到本地有功调度设定时间
	virtual double GetLocalpTime(int pos) = 0;
	//根据厂站控制区位置设置本地有功调度设定时间
	virtual bool SetLocalpTime(int pos, double value) = 0;
};

#endif
