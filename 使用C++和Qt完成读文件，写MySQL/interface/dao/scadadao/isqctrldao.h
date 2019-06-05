//isqctrldao.h

#ifndef _ISQCTRLDAO_SUNRUI_20140425_H_
#define _ISQCTRLDAO_SUNRUI_20140425_H_

#include "../ibasicdao.h"                        // for IBasicDao
#include "../../icsvalue.h"                      // for intarray

#define SQCTRLDAO_CLASSID    "csqctrldao"
#define SQCTRLDAO_INTFID     "isqctrldao"

class ISqCtrlDao : virtual public IBasicDao
{
public:
	//根据顺控计划位置读取启动类型
	virtual int GetStartType(int pos) = 0;
	//根据顺控计划位置读取启动条件
	virtual const char* GetStartInfo(int pos) = 0;
	//根据顺控计划位置读取启动周期ID
	virtual int GetStartCycID(int pos) = 0;
	//根据顺控计划位置读取是否需要预演
	virtual int IsPreview(int pos) = 0;

	//根据顺控计划位置读取当前执行人
	virtual const char* GetOptUser(int pos) = 0;
	//根据顺控计划位置读取当前执行状态
	virtual int GetOptState(int pos) = 0;
	//根据顺控计划位置设置当前执行结果
	virtual bool SetOptInfo(int pos, int nOptState, const char* actUser) = 0;
	//根据顺控计划位置读取当前启动条件状态。0、不满足启动条件；1、启动条件转变为满足；2、已执行顺控操作。
	virtual int GetExpState(int pos) = 0;
	//根据顺控计划位置设置当前启动条件状态
	virtual bool SetExpState(int pos, int nExpState) = 0;

	//根据定时器类型ID得到对应的定时执行顺控计划记录集
	virtual intarray* GetSqCtrlSetByTimerType(int nTimerId) = 0;

};

#endif
