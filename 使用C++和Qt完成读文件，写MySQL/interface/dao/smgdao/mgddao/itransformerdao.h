//itransformerdao.h

#ifndef _ITRANSFORMERDAO_PENGSHIKANG_20120511_H_
#define _ITRANSFORMERDAO_PENGSHIKANG_20120511_H_

#include "../../ibasicdao.h"                        // for IBasicDao

#define TRANSFORMERDAO_CLASSID    "ctransformerdao"
#define TRANSFORMERDAO_INTFID     "itransformerdao"

class IEquipDao;
class IAnalogDao;
class IStatusDao;
class IBusDao;
class ICommSrcDao;
class IControlDao;

class ITransformerDao : virtual public IBasicDao
{
public:
	//设置采集数据源对象
	virtual void SetCommSrcDao(ICommSrcDao* pCommSrc) = 0;
	//设置模拟量实体对象
	virtual void SetAnalogDao(IAnalogDao* pAnalog) = 0;
	//设置状态量实体对象
	virtual void SetStatusDao(IStatusDao* pStatus) = 0;
	//设置控制量实体对象
	virtual void SetControlDao(IControlDao* pControl) = 0;
	//设置母线实体对象
	virtual void SetBusDao(IBusDao* pBus) = 0;

	//初始化所有的母线所连变压器信息
	virtual void InitAllBusTransNaborInfo() = 0;
	//初始化所有变压器对象的VQC调节系统号信息
	virtual void InitAllAdjustAreaNos() = 0;
	
	//根据变压器对象的位置设置各个量测量实时值
	virtual void SetMeasureValues(int pos, int* nBrkPos, int& nTapPos) = 0;
	
	//根据变压器对象位置得到额定容量
	virtual double GetCapacity(int pos) = 0;
	//根据变压器对象位置得到子微网ID
	virtual int GetSubMicGridID(int pos) = 0;
	//根据变压器对象位置得到变压器类型
	virtual int GetWindingType(int pos) = 0;
	//根据变压器对象位置判断是否为可调变压器
	virtual int IsControllable(int pos) = 0;
	//根据变压器对象位置得到分接头最大位置
	virtual int GetMaxTapPos(int pos) = 0;
	//根据变压器对象位置得到分接头档位无效掩码
	virtual int GetUnuseTapCode(int pos) = 0;
	//根据变压器对象位置和绕组编号得到该绕组侧所连接母线ID
	virtual int GetWindingBusID(int pos, int windingNo) = 0;
	//根据变压器对象位置和绕组编号得到该绕组侧所连开关遥信量ID
	virtual int GetWindingPosStatusID(int pos, int windingNo) = 0;
	//根据变压器对象位置和绕组编号得到该绕组侧所连开关状态值
	virtual int GetWindingSwitchPos(int pos, int windingNo) = 0;
	//根据变压器对象位置得到分接头每档动作时间
	virtual int GetTapActTime(int pos) = 0;
	//根据变压器对象位置得到同向动作时间间隔
	virtual int GetActTimespan(int pos) = 0;
	//根据变压器对象位置得到反向动作时间间隔
	virtual int GetReactTimespan(int pos) = 0;
	//根据变压器对象位置得到日动作最大次数
	virtual int GetMaxActTimesOfADay(int pos) = 0;
	//根据变压器对象位置得到日动作失败最大次数
	virtual int GetMaxFailTimesOfADay(int pos) = 0;
	//根据变压器对象位置得到持续升分接头最大次数
	virtual int GetMaxAscendTimes(int pos) = 0;
	//根据变压器对象位置得到持续降分接头最大次数
	virtual int GetMaxDescendTimes(int pos) = 0;
	//根据变压器对象位置得到分接头升则电压升标志
	virtual bool IsVoltageAgreeWithTapChange(int pos) = 0;
	//根据变压器对象位置得到档位状态量ID
	virtual int GetTapMeasId(int pos) = 0;
	//根据变压器对象位置得到档位升遥控量ID
	virtual int GetTapUpCtrlId(int pos) = 0;
	//根据变压器对象位置得到档位降遥控量ID
	virtual int GetTapDownCtrlId(int pos) = 0;
	//根据变压器对象位置得到档位停遥控量ID
	virtual int GetTapStopCtrlId(int pos) = 0;
	
	//根据变压器对象位置得到是否运行
	virtual bool IsRunning(int pos) = 0;
	//根据变压器对象位置得到变压器所属调节区号
	virtual int GetAdjustAreaNo(int pos) = 0;
	//根据变压器对象位置得到当前档位位置
	virtual int GetCurTapPos(int pos) = 0;
	//根据变压器对象位置得到上次档位位置
	virtual int GetOldTapPos(int pos) = 0;
	//根据变压器对象位置得到持续升分接头次数
	virtual int GetCurAscendTimes(int pos) = 0;
	//根据变压器对象位置得到持续降分接头次数
	virtual int GetCurDescendTimes(int pos) = 0;
	//根据变压器对象位置得到最后一次扰动时间
	virtual double GetRecentDisturbTime(int pos) = 0;
	//根据变压器对象位置得到最后一次动作时间
	virtual double GetRecentActTime(int pos) = 0;
	//根据变压器对象位置得到最后一次动作方向
	virtual int GetRecentActTrend(int pos) = 0;
	//根据变压器对象位置得到分接头是否已到最大位置
	virtual bool IsAtMaxTapPos(int pos) = 0;
	//根据变压器对象位置得到分接头是否已到最小位置
	virtual bool IsAtMinTapPos(int pos) = 0;
	//根据变压器对象位置得到动作连续失败次数
	virtual int GetContinueFailTimes(int pos) = 0;
	//根据变压器对象位置得到日失败次数
	virtual int GetActFailTimesOfToday(int pos) = 0;
	//根据变压器对象位置得到日动作次数
	virtual int GetActTimesOfToday(int pos) = 0;

	//根据变压器对象位置设置变压器所属调节区号
	virtual bool SetAdjustAreaNo(int pos, int adjustNo) = 0;
	//根据变压器对象位置和绕组编号设置该绕组侧所连开关状态值
	virtual bool SetWindingSwitchPos(int pos, int windingNo, int swiPos) = 0;
	//根据变压器对象位置设置当前档位位置
	virtual bool SetCurTapPos(int pos, int nValue) = 0;
	//根据变压器对象位置设置上次档位位置
	virtual bool SetOldTapPos(int pos, int nValue) = 0;
	//根据变压器对象位置设置持续升分接头次数
	virtual bool SetCurAscendTimes(int pos, int nValue) = 0;
	//根据变压器对象位置设置持续降分接头次数
	virtual bool SetCurDescendTimes(int pos, int nValue) = 0;
	//根据变压器对象位置设置最后一次扰动时间
	virtual bool SetRecentDisturbTime(int pos, double dValue) = 0;
	//根据变压器对象位置设置最后一次动作时间
	virtual bool SetRecentActTime(int pos, double dValue) = 0;
	//根据变压器对象位置设置最后一次动作方向
	virtual bool SetRecentActTrend(int pos, int nValue) = 0;
	//根据变压器对象位置设置分接头是否已到最大位置
	virtual bool SetAtMaxTapPos(int pos, bool bValue) = 0;
	//根据变压器对象位置设置分接头是否已到最小位置
	virtual bool SetAtMinTapPos(int pos, bool bValue) = 0;
	//根据变压器对象位置设置动作连续失败次数
	virtual bool SetContinueFailTimes(int pos, int nValue) = 0;
	//根据变压器对象位置设置日失败次数
	virtual bool SetActFailTimesOfToday(int pos, int nValue) = 0;
	//根据变压器对象位置设置日动作次数
	virtual bool SetActTimesOfToday(int pos, int nValue) = 0;
	
	//根据变压器对象位置和绕组编号得到该绕组侧电压或无功最大变化量
	virtual double GetWindingMaxOffset(int pos, int windingNo) = 0;
	//根据变压器对象位置和绕组编号得到该绕组侧电压或无功最小变化量
	virtual double GetWindingMinOffset(int pos, int windingNo) = 0;

	//根据变压器对象位置和绕组编号得到有功遥测ID
	virtual int GetTappId(int pos, int windingNo) = 0;
	//根据变压器对象位置和绕组编号得到无功遥测ID
	virtual int GetTapqId(int pos, int windingNo) = 0;
	//根据变压器对象位置和绕组编号得到有功
	virtual double GetTapp(int pos, int windingNo) = 0;
	//根据变压器对象位置和绕组编号得到无功
	virtual double GetTapq(int pos, int windingNo) = 0;

	//根据变压器对象位置得到数据通道连通状态
	virtual int GetSrcConnectState(int pos) = 0;
	//根据变压器对象位置设置数据通道连通状态
	virtual bool SeSrcConnectState(int pos, int srcState) = 0;
	//根据变压器对象位置和允许的过载率判断流过变压器潮流是否过载
	virtual bool IsOverPower(int pos, double dOverRate=1.0) = 0;

	//设置设备实体对象
	virtual void SetEquipDao(IEquipDao* pEquip) = 0;

};

#endif
