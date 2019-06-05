// ionlinemodel.h
#ifndef _IONLINEMODEL_H_
#define _IONLINEMODEL_H_

#include "icsunknown.h" // for IICSUnknown

//#define DLL_ONLINEMODEL	"onlinemodel"
#define DLL_ONLINEMODEL	"onlinesmgmodeler"
#define IID_ONLINEMODEL	"IOnlineModel"
#define CID_ONLINEMODEL	"COnlineModel"

#include <vector>

class IOnlineModel: public IICSUnknown
{
public:


	/*
	 数据是否被修改，如果被修改(返回true)，则需要调用	updateRtdb 更新实时库
	 */
	virtual bool infoChanged() = 0; 

	/*
	updateRtdb 批量更新实时库
	*/
	virtual void updateRtdb() = 0; 


	/*
	isNeedUserAuth 是否需要弹出用户验证窗口
	输入参数：1.need 是否需要，默认值为不需要
	*/
	virtual void isNeedUserAuth(bool need=false) = 0;


	/*
	unalarm 报警抑制
	输入参数：1.type 测点类型，遥测为1，遥信为2,间隔为3
			  2.idlist 测点列表
			  3.alarmtype 抑制类型，报警抑制为1，报警抑制解除为0
	*/
	virtual void unalarm(int type, std::vector<int> idlist,int alarmtype=1) = 0;

	/*
	unalarm 报警抑制
	输入参数：1.type 测点类型，遥测为1，遥信为2
			  2.id 测点ID
	输出参数：报警抑制为0，报警为1
	*/
	virtual int getAlarmFlag(int type,int id) = 0;

	/*
	setStationLastDate 用于设置变电站安全运行日期的起始时间
	输入参数：1.stationid：厂站ID
	*/
	virtual void setStationFirstDate(int stationid) = 0;

	/*
	maxVal 用于返回计算值中的最大值
	输入参数：1.val  值表达式，格式为：值1,值2，值3.....
	*/
	virtual double maxVal(char* val) = 0;

	/*
	minVal 用于返回计算值中的最小值
	输入参数：1.val  值表达式，格式为：值1,值2，值3.....
	*/
	virtual double minVal(char* val) = 0;

	/*	setForcast 用于设置光伏发电预测光伏电站，限电/增容/检修计划实时建模*/
	//virtual void setForcast() = 0;

	/*	ForcastSampleRepair 用于光伏发电预测样本修复*/
	//virtual void ForcastSampleRepair() = 0;

	/*
	setStationWFmode 用于设置厂站五防模式
	输入参数：1.imode:五防模式
	*/
	virtual void setStationWFmode(int imode) = 0;

	/*setProFlagRYB 用于设置并网功能软压板
	输入参数：1.flagbit：各功能标志位  2.bexecute：功能投退
	*/
	virtual void setProFlagRYB(int flagbit,bool bexecute) = 0;

	/*主电源参数设置
	mainpid 为主电源ID*/
	virtual void setMainPDZ(int mainpid) = 0;

	/*分布式发电机参数设置
	generatorid 为分布式发电机ID*/
	virtual void setGeneratorDZ(int generatorid) = 0;

	/*储能设备参数设置
	storageid 为储能设备ID*/
	virtual void setStorageDZ(int storageid) = 0;

	/*黑启动顺控参数设置
	sqctrlid 为顺控ID*/
	virtual void setBstartDZ(int sqctrlid) = 0;

	/*储能控制曲线设置
	smgid 为微电网ID*/
	virtual void setStorageCurve(int smgid) = 0;

	/*交换功率曲线设置
	smgid 为微电网ID*/
	virtual void setExchpowcur(int smgid,int systype) = 0;

	/*五防压板    stationid 为厂站ID  stationid = 0时为全部厂站;bflag = 0为退出，bflag = 1为投入*/
	virtual void setWFFlag(int stationid,bool bflag) = 0;
	
	/*平滑出力设置 ismoothid 为平滑id*/
	virtual void setSmoothCtrl(int ismoothid) = 0;

	/*远方调度压板投退*/
	//virtual void setDispatch() = 0;

	/*禁止远方调度命令*/
	virtual void setBanYFDis(bool isF) = 0;

	/*设置分时段时间*/
	virtual void setPeriodStat() = 0;

};

#endif
