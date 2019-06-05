//imglinedao.h

#ifndef _IMGLINEDAO_PENGSHIKANG_20100927_H_
#define _IMGLINEDAO_PENGSHIKANG_20100927_H_

#include "imgddao.h"                             // for IMgdDao

#define MGLINEDAO_CLASSID    "cmglinedao"
#define MGLINEDAO_INTFID     "imglinedao"

class IMGLineDao : virtual public IMgdDao
{
public:
	//根据线路位置得到线路类型
	virtual int GetLineType(int pos) = 0;
	//根据线路位置得到2端所连母线ID
	virtual int GetBus2ID(int pos) = 0;
	
	//根据线路位置得到2端开关状态遥信ID
	virtual int GetPos2ID(int pos) = 0;
	//根据线路位置得到2端开关状态合遥控ID
	virtual int GetPosCtrl2ID(int pos) = 0;
	//根据线路位置得到2端开关状态分遥控ID
	virtual int GetCutCtrl2ID(int pos) = 0;
	
	//根据线路位置得到2端P、Q遥测ID
	virtual bool GetPQ2_IDs(int pos, int& nP2Id, int& nQ2Id) = 0;
	//根据线路位置得到2端P遥测ID
	virtual int GetP2ID(int pos) = 0;
	//根据线路位置得到2端Q遥测ID
	virtual int GetQ2ID(int pos) = 0;
	
	//根据线路位置得到2端当前开关状态
	virtual int GetCurPos2(int pos) = 0;
	//根据线路位置得到2端当前有功出力
	virtual double GetCurP2(int pos) = 0;
	//根据线路位置设置2端当前有功出力
	virtual bool SetCurP2(int pos, double currP2) = 0;
	//根据线路位置得到2端当前无功出力
	virtual double GetCurQ2(int pos) = 0;
	//根据线路位置设置2端当前无功出力
	virtual bool SetCurQ2(int pos, double currQ2) = 0;
};

#endif
