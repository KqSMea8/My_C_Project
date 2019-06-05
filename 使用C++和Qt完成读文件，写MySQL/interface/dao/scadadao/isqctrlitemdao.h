//isqctrlitemdao.h

#ifndef _ISQCTRLITEMDAO_SUNRUI_20140425_H_
#define _ISQCTRLITEMDAO_SUNRUI_20140425_H_

#include "../ibasicdao.h"                        // for IBasicDao
#include "isqctrlitemobj.h"                      // for ISqctrlItemObj
#include <q3sortedlist.h>                        // for Q3SortedList

#define SQCTRLITEMDAO_CLASSID    "csqctrlitemdao"
#define SQCTRLITEMDAO_INTFID     "isqctrlitemdao"

class ISqCtrlitemDao : virtual public IBasicDao
{
public:
	//根据顺控计划ID和控制步骤号得到顺控项位置
	virtual int GetStepPos(int sqctrlid, int stepid) = 0;
	//根据顺控项位置读取顺序控制计划ID
	virtual int GetSqCtrlID(int pos) = 0;
	//根据顺控项位置读取控制步骤号
	virtual int GetStepID(int pos) = 0;
	//根据顺控项位置读取控制点ID
	virtual int GetCtrlID(int pos) = 0;
	//根据顺控项位置读取控制目标值
	virtual double GetCtrlValue(int pos) = 0;
	//根据顺控项位置读取控制启动条件
	virtual const char* GetStartInfo(int pos) = 0;
	//根据顺控项位置读取失败后是否继续操作
	virtual int IsContinue(int pos) = 0;
	//根据顺控项位置读取是否需要用户确认才执行
	virtual int IsConfirm(int pos) = 0;
	//根据顺控项位置读取是否需要跳过这一步执行
	virtual int IsSkip(int pos) = 0;
	//根据顺控项位置读取失败后重复控制次数
	virtual int GetRepeattimes(int pos) = 0;
	//根据顺控项位置读取控制结束后等待时间（单位s）
	virtual int Getwaitsecond(int pos) = 0;
	//根据顺控项位置读取当前操作状态
	virtual int GetCurState(int pos) = 0;
	//根据顺控项位置读取遥控是否成功
	virtual int GetSuccessFlag(int pos) = 0;
	//根据顺控项位置读取是否存储
	virtual int GetSaveFlag(int pos) = 0;

	//根据顺控项位置设置当前操作状态
	virtual bool SetCurState(int pos, int state) = 0;
	//根据顺控项位置设置遥控成功标志
	virtual bool SetSuccessFlag(int pos, int flag) = 0;
	//根据顺控项位置设置是否存储标志
	virtual bool SetSaveFlag(int pos, int flag) = 0;
	//设置顺控项处理结果
	virtual bool SetSqctrlitemResult(int pos, int curState, bool isSuccess) = 0;

	//根据顺控ID得到对应的顺控项对象集
	virtual Q3SortedList<ISqctrlItemObj>* GetSqctrlItemSetByObjectId(int nObjId) = 0;	

	//根据顺控项位置设置控制目标值
	virtual bool SetCtrlValue(int pos, double ctrlValue) = 0;
	//根据顺控项位置读取操作类型。0--遥控遥调；1--遥测置数；2--遥信置数；3--遥脉置数。
	virtual int GetOperateType(int pos) = 0;
	//根据顺控项位置读取操作值表达式。
	virtual bool GetOperateValueExpress(int pos, char CtrlValExpr[256]) = 0;

};

#endif
