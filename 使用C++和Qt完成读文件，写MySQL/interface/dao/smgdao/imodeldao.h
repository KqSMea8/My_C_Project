//imodeldao.h

#ifndef _IMODELDAO_SUNRUI_20130311_H_
#define _IMODELDAO_SUNRUI_20130311_H_

#include "../ibasicdao.h"                        // for IBasicDao

#define MODELDAO_CLASSID    "cmodeldao"
#define MODELDAO_INTFID     "imodeldao"

class IModelRunStyleDao;
class ISmgRunstyleDao;

class IModelDao  : virtual public IBasicDao 
{
public:
	//创建运行模式的所有微电网运行方式的列表值
	virtual void CreateSmgRunstyleIdList(IModelRunStyleDao* pModelRunStyle, ISmgRunstyleDao* pSmgRunstyle) = 0;

	//得到当前微电网系统的运行模式id
	virtual int GetSysCurRunModelId(int modePos) = 0;

	//得到指定运行模式id和微电网id的主电源运行方式
	virtual bool GetRunstyleIdbyModelandMicgrid(int modelid, int micgridid, int& runstyleid) = 0;

	//根据运行模式位置获取运行模式状态ID
	virtual int GetStyleStateID(int pos) = 0;

};

#endif
