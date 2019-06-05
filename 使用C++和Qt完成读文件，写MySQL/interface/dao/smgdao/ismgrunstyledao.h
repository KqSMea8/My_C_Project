// ismgrunstyledao.h: interface for the ISmgRunstyleDao class.

#ifndef _ISMGRUNSTYLESDAO_ZHANGPENG_20120810_H_
#define _ISMGRUNSTYLESDAO_ZHANGPENG_20120810_H_

#include "../ibasicdao.h"                        // for IBasicDao
#include "../../icsvalue.h"                      // for intarray

#define SMGRUNSTYLEDAO_CLASSID    "csmgrunstyledao"
#define SMGRUNSTYLEDAO_INTFID     "ismgrunstyledao"

class ISmgRunstyleDao  : virtual public IBasicDao 
{
public:
	//根据微电网ID和主电源类型得到微电网运行方式位置
	virtual int GetPositionByMgMainps(int mgId, int mpsFlag) = 0;
	//设置指定运行方式ID的主电源列表值
	virtual void SetMainGenIdList(int pos, intarray* pIdList) = 0;
	//得到指定运行方式位置创建主电源列表值
	virtual bool CreateMainGenIdList(int pos, intarray& idList) = 0;
	
	//根据微电网运行方式位置得到所属微电网
	virtual int GetMgId(int pos) = 0;
	//根据微电网运行方式位置得到主电源类型
	virtual int GetMainpsFlag(int pos) = 0;
	//根据微电网运行方式位置得到切换控制属性
	virtual int GetCtrlAttr(int pos) = 0;
	//根据微电网运行方式位置得到是否需要分析预测数据
	virtual int GetCheckForecast(int pos) = 0;
	//根据微电网运行方式位置得到黑启动顺序控制ID
	virtual int GetBlackStartID(int pos) = 0;

};

#endif // !defined _SMGRUNSTYLESDAO_ZHANGPENG_20120810_H_
