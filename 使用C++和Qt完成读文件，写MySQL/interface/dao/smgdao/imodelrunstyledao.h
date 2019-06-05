//imodelrunstyledao.h

#ifndef _IMODELRUNSTYLEDAO_SUNRUI_20130311_H_
#define _IMODELRUNSTYLEDAO_SUNRUI_20130311_H_

#include "../ibasicdao.h"                        // for IBasicDao

#define MODELRUNSTYLEDAO_CLASSID    "cmodelrunstyledao"
#define MODELRUNSTYLEDAO_INTFID     "imodelrunstyledao"

class IModelRunStyleDao  : virtual public IBasicDao 
{
public:
	//根据运行模式下主电源方式位置得到运行方式ID
	virtual int GetRunStyleID(int pos) = 0;
	//根据运行模式下主电源方式得到所属运行模式ID
	virtual int GetModelStyleID(int pos) = 0;
};

#endif
