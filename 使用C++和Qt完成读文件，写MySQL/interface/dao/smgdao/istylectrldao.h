//istylectrldao.h

#ifndef _ISTYLECTRLDAO_SUNRUI_20130311_H_
#define _ISTYLECTRLDAO_SUNRUI_20130311_H_

#include "../ibasicdao.h"                        // for IBasicDao
#include "../../icsvalue.h"                      // for intarray

#define STYLECTRLDAO_CLASSID    "cstylectrldao"
#define STYLECTRLDAO_INTFID     "istylectrldao"

class IStyleCtrlDao  : virtual public IBasicDao 
{
public:
	//根据微电网倒闸操作位置得到所属运行方式ID
	virtual int GetRunStyleID(int pos) = 0;
	//根据微电网倒闸操作位置得到控制量ID
	virtual int GetCtrlID(int pos) = 0;
	//根据微电网倒闸操作位置得到控制类型值
	virtual int GetCtrlType(int pos) = 0;
	//根据微电网倒闸操作位置得到控制优先级
	virtual int GetPriority(int pos) = 0;
	//创建倒闸操作列表
	virtual void CreateStyleList() = 0;
	//得到模式切换ID对应的所有倒闸操作的列表
	virtual bool GetStyleList(int switchmodelid, intarray& list) = 0;
	//是否配置倒闸操作
	virtual bool CanStyleOpr(int switchmodelid) = 0;
};

#endif
