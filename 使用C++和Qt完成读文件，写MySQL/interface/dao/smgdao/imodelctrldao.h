//imodelctrldao.h

#ifndef _IMODELCTRLDAO_SUNRUI_20130311_H_
#define _IMODELCTRLDAO_SUNRUI_20130311_H_

#include "../ibasicdao.h"                        // for IBasicDao
#include "../../icsvalue.h"                      // for intarray

#define MODELCTRLDAO_CLASSID    "cmodelctrldao"
#define MODELCTRLDAO_INTFID     "imodelctrldao"

class IModelCtrlDao  : virtual public IBasicDao 
{
public:
	//根据模式切换位置得到原运行模式ID
	virtual int GetPriModelID(int pos) = 0;
	//根据模式切换位置得到目标运行模式ID
	virtual int GetAimModelID(int pos) = 0;

	//根据原模式ID和目标模式ID得到模式切换ID
	virtual int GetModelCtrlPos(int priid, int aimid) = 0;
	//根据模式切换位置创建倒闸操作列表值(按照优先级的值由小到大排序)
	virtual bool CreateStyleCtrlList(int id, intarray& posList) = 0;
	//根据模式切换位置得到顺序控制ID
	virtual int GetSQCtrlID(int pos) = 0;
};

#endif
