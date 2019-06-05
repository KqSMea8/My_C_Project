//iexprcaldao.h

#ifndef _IEXPRCALDAO_PENGSHIKANG_20130310_H_
#define _IEXPRCALDAO_PENGSHIKANG_20130310_H_

#include "../ibasicdao.h"                        // for IBasicDao
#include "../../scadasrv/iexpressmap.h"          // for IExpressMap、ExpSet

#define EXPRCALDAO_CLASSID    "cexprcaldao"
#define EXPRCALDAO_INTFID     "iexprcaldao"

class IExprCalDao : virtual public IBasicDao
{
public:
	//设置公式映射处理对象
	virtual void SetExpressMap(IExpressMap* pExpressMap) = 0;

	//根据定时器类型ID得到对应的公式计算记录集
	virtual ExpSet* GetExpSetByType(int nTypeId) = 0;
	
	//根据公式计算位置得到公式配置信息
	virtual bool GetExprConfigInfo(int pos, int& nTypeId, int& nEnable, int& nDelete) = 0;
	//根据公式计算位置得到计算表达式
	virtual const char* GetFormula(int pos) = 0;
	//根据前置上传量位置得到是否转发标志
	virtual int GetDataTransFlag(int pos) = 0;

	//根据公式计算位置得到计算值
	virtual double GetCalValue(int pos) = 0;
	//根据公式计算位置得到数据品质因数
	virtual int GetQuality(int pos) = 0;
	//根据公式计算位置得到当前时间
	virtual double GetCurTime(int pos) = 0;
	
	//根据公式计算位置得到公式计算结果
	virtual bool GetExprCalValue(int pos, double& calValue, double& calTime, int& nQuality) = 0;
	//根据公式计算ID得到公式计算结果
	virtual bool GetExprCalValueById(int id, double& calValue, double& calTime, int& nQuality) = 0;
	//根据公式计算位置设置公式计算结果
	virtual bool SetExprCalValue(int pos, double calValue, double calTime, int nQuality) = 0;	
};

#endif
