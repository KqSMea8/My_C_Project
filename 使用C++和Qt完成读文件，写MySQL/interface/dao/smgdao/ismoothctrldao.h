//ismoothctrldao.h

#ifndef _ICSMOOTHCTRLDAO_PENGSHIKANG_20110712_H_
#define _ICSMOOTHCTRLDAO_PENGSHIKANG_20110712_H_

#include "../ibasicdao.h"                        // for IBasicDao
#include "../../smgsrv/smgdatadef.h"             // for MicgridObectInfo

#define SMOOTHCTRLDAO_CLASSID    "csmoothctrldao"
#define SMOOTHCTRLDAO_INTFID     "ismoothctrldao"

class ISmoothCtrlDao : virtual public IBasicDao
{
public:
	//将数据表的静态信息输入指定的MicgridObectInfo对象
	virtual bool InitSmoothInfoOfMicgrid(MicgridObectInfo* pCurMgObj) = 0;
	
	//写入系统信息表的各个量测量值
	virtual void WriteDynamicInfo1(MicgridObectInfo* pCurMgObj) = 0;
	
	//将数据表的动态信息写入库中
	virtual void WriteDynamicInfo1() = 0;
	
	virtual int GetPositionByMGID(int mgid) = 0;
	virtual int GetMGID(int pos) = 0;        //得到微电网ID
	virtual bool IsEnable(int pos) = 0;      //是否生效
	virtual int GetAimType(int pos) = 0;     //得到目标类型
	virtual double GetMaxRatio(int pos) = 0; //得到最大允许变化率
	virtual int GetCtrlTimes(int pos) = 0;   //得到定量控制持续次数
	virtual double GetPrevExchP(int pos) = 0;//得到先前交换功率
	virtual double GetPrevGenP(int pos) = 0; //得到先前发电功率
	virtual double GetPrevStorP(int pos) = 0;//得到先前实际储能功率
	virtual double GetPrevStorPlanP(int pos) = 0;//得到先前计划储能功率
	virtual double GetPrevLoadP(int pos) = 0;//得到先前负荷功率
	virtual double GetPrevBaseP(int pos) = 0;//得到先前基准功率
	virtual double GetPrevAimP(int pos) = 0; //得到先前目标功率
	virtual double GetCurBaseP(int pos) = 0; //得到当前基准目标功率
	virtual double GetCurAimP(int pos) = 0;  //得到当前目标功率
	virtual double GetCurRatio(int pos) = 0; //得到当前变化率
	virtual double GetCurCompP(int pos) = 0; //得到当前补偿功率
	virtual int GetStartFlag(int pos) = 0;   //得到启动控制标志
	
	virtual bool SetCurBaseP(int pos, double baseP) = 0; //设置当前基准目标功率
	virtual bool SetCurAimP(int pos, double aimP) = 0;   //设置当前目标功率
	virtual bool SetCurRatio(int pos, double ratio) = 0; //设置当前变化率
	virtual bool SetCurCompP(int pos, double compP) = 0; //设置当前补偿功率
	virtual bool SetStartFlag(int pos, int startFlag) = 0;//设置启动控制标志
};

#endif
