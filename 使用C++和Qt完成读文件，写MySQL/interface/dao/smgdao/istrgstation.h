
#ifndef _ISTRGSTATION_20190527_H
#define _ISTRGSTATION_20190527_H


#define STORAGEDAO_CLASSID    "cstoragedao"
#define STORAGEDAO_INTFID     "istoragedao"

class IEquipDao;
class IExprCalDao;
class ICommSrcDao;

class IStorageDao : virtual public IMgdDao
{
public:	
	//设置指定位置的储能装置处于恢复状态
	virtual void StartRecall(int pos) = 0;
	//将指定位置的储能装置结束恢复状态
	virtual void EndRecall(int pos) = 0;
	//判断指定位置的储能装置是否处于恢复状态
	virtual bool IsRecalling(int pos) = 0;
	//判断指定位置的储能装置是否允许结束恢复状态
	virtual bool CanEndRecall(int pos, bool isIsland) = 0;

	//判断指定位置的储能装置是否允许调节有功功率
	virtual bool CanAdjustPower(int pos) = 0;
	//判断指定位置的储能装置是否允许放电
	virtual bool CanDischange(int pos) = 0;
	//判断指定位置的储能装置是否允许充电
	virtual bool CanChange(int pos) = 0;

	//将指定位置的储能装置对象加入储能装置集合中
	virtual void AddObjectIntoStorageList(int pos, intarray& list) = 0;

	//根据储能装置位置更新运行信息
	virtual double UpdateRunInfo(int pos, IExprCalDao* pExprCal, ICommSrcDao* pCommSrc, bool& bBmsState, bool& bNeedStop) = 0;//使用m_idxMaxSocID等

	//根据储能装置位置得到最快响应时间（天）
	virtual double GetRespTime(int pos) = 0;
	//根据储能装置位置计算当前SOC档位值
	virtual int GetCurSocState(int pos) = 0;

	//根据储能装置位置得到配置的最大充放电无功功率[考虑可用比率]
	virtual double GetMaxChargePowerIn(int pos) = 0;
	//根据储能装置位置得到配置的最大充放电有功功率[考虑可用比率]
	virtual double GetMaxDischargePowerIn(int pos) = 0;

	//根据储能装置位置得到计算的最大充电有功功率[考虑可用比率和SOC]
	virtual double GetMaxChargePower(int pos) = 0;
	//根据储能装置位置得到计算的最大放电有功功率[考虑可用比率和SOC]
	virtual double GetMaxDischargePower(int pos) = 0;

	//根据储能装置位置得到配置的最优充电有功功率[考虑可用比率]
	virtual double GetOptimizeChargePowerIn(int pos) = 0;
	//根据储能装置位置得到配置的最优放电有功功率[考虑可用比率]
	virtual double GetOptimizeDischargePowerIn(int pos) = 0;

	//根据储能装置位置得到计算的最优充电有功功率[考虑可用比率和SOC]
	virtual double GetOptimizeChargePower(int pos, bool isMain=false) = 0;
	//根据储能装置位置得到计算的最优放电有功功率[考虑可用比率和SOC]
	virtual double GetOptimizeDischargePower(int pos, bool isMain=false) = 0;
	//根据储能装置位置得到目标放电有功功率[考虑可用比率和SOC]
	virtual double GetAimDischargePower(int pos, bool isMain=false) = 0;

	//根据储能装置位置得到设备允许最大剩余容量(%)
	virtual double GetMaxSocInIsland(int pos) = 0;
	//根据储能装置位置得到设备允许最小剩余容量(%)
	virtual double GetMinSocInIsland(int pos) = 0;

	//根据储能装置位置得到经济调度最大剩余容量(%)
	virtual double GetMaxSocInConnect(int pos) = 0;
	//根据储能装置位置得到经济调度最小剩余容量(%)
	virtual double GetMinSocInConnect(int pos) = 0;

	//根据储能装置位置得到功率因素遥调ID
	virtual int GetCosCtrlID(int pos) = 0;
	//根据储能装置位置得到剩余容量ID
	virtual int GetCurSocID(int pos) = 0;

	//根据储能装置位置得到剩余容量
	virtual double GetCurSoc(int pos) = 0;
	virtual double GetCurCapacity(int pos) = 0;

	//根据储能装置位置增加一次充电次数
	//virtual void IncreaseChargeCount(int pos) = 0;

	//根据储能装置位置增加一次放电次数
	//virtual void IncreaseDischargeCount(int pos) = 0;

	//根据储能装置位置得到充放电标志
	virtual int GetChargeFlag(int pos) = 0;

	//根据储能装置位置增加一次充电次数
	virtual void IncreaseChargeCount(int pos, double actTime) = 0;
	//根据储能装置位置增加一次放电次数
	virtual void IncreaseDischargeCount(int pos, double actTime) = 0;

	//根据储能装置位置得到最后一次控制时间
	virtual double GetRecentActTime(int pos) = 0;
	//根据发电机位置设置最后一次动作时间
	virtual bool SetRecentActTime(int pos, double actTime) = 0;

	//根据储能装置位置增长储能总的可调节功率
	virtual void IncreaseAdjustStorP(int pos, bool isIsland, float& dMaxDchgP, float& dMaxChgP) = 0;

	//根据储能装置位置得到PCS启动控制ID
	virtual int GetStartCtrlID(int pos) = 0;
	//根据储能装置位置得到PCS停止控制ID
	virtual int GetStopCtrlID(int pos) = 0;
	//根据储能装置位置得到PCS启停状态ID
	virtual int GetRunStateID(int pos) = 0;
	//根据储能装置位置得到VF模式控制ID
	virtual int GetVFmodeCtrlId(int pos) = 0;
	//根据储能装置位置得到PQ模式控制ID
	virtual int GetPQmodeCtrlId(int pos) = 0;
	//根据储能装置位置得到控制模式状态ID
	virtual int GetModeStateID(int pos) = 0;

	//根据储能装置位置得到储能用途属性
	virtual int GetUseType(int pos) = 0;
	//根据储能装置位置得到主电源模式
	virtual int GetMainModeType(int pos) = 0;
	//根据储能装置位置得到充放电整体效率
	virtual double GetConverseEffect(int pos) = 0;
	//根据储能装置位置得到发电成本
	virtual double GetProductCost(int pos) = 0;
	//根据储能装置位置得到有功遥调灵敏度功率值
	virtual double GetSensitivity(int pos) = 0;

	//根据储能装置位置得到当前控制者类型。0：软件策略可控；1：界面人工控制；2：深充深放计划控制
	virtual int GetControllerType(int pos) = 0;
	//根据储能装置位置设置当前控制者类型。0：软件策略可控；1：界面人工控制；2：深充深放计划控制
	virtual bool SetControllerType(int pos, int ctrlType) = 0;

	//根据储能装置位置得到当前VF控制模式
	virtual int GetCurVFModStat(int pos) = 0;
	//根据储能装置位置设置当前VF控制模式
	virtual bool SetCurVFModStat(int pos, int mode) = 0;

	//根据储能位置判断当前储能是否投入
	virtual bool IsAdded(int pos, bool bRefresh=false) = 0;
	//根据储能位置判断当前储能是否启动
	virtual bool IsStarted(int pos) = 0;
	//根据储能位置判断当前储能是否处于主发电机模式
	virtual bool IsMainMode(int pos) = 0;
	//根据储能位置判断当前储能是否处于PQ运行模式
	virtual bool IsPQMode(int pos) = 0;
	//根据储能位置得到抗冲击倍数
	virtual double GetAntiImpactRatio(int pos) = 0;
	//根据储能位置得到备用有功功率
	virtual double GetBackupPower(int pos) = 0;

	//根据储能位置得到PCS故障复归控制ID
	virtual int GetRevertCtrlId(int pos) = 0;

	//清除所有调控连续失败次数
	virtual void ClearAllFailTimes() = 0;
	//清除子微网内储能装置的调控连续失败次数
	virtual void ClearAllFailTimesInMicgrid(int mgId) = 0;

	//根据储能位置初始化启动连续失败次数。actType：0--复归；1--启动；2--全部
	virtual bool InitStartFailTimes(int pos, int actType) = 0;
	//根据储能位置增加启动连续失败次数。actType：0--复归；1--启动
	virtual bool IncreaseStartFailTimes(int pos, int actType) = 0;
	//根据储能位置得到启动连续失败次数
	virtual int GetStartFailTimes(int pos) = 0;
	//根据储能位置判断是否可启动。actType：0--复归；1--启动；2--全部
	virtual bool CanStart(int pos, int actType) = 0;

	//根据储能位置初始化调节连续失败次数。actType：0--有功；1--无功；2--全部
	virtual bool InitAdjustFailTimes(int pos, int actType) = 0;
	//根据储能位置增加调节连续失败次数。actType：0--有功；1--无功
	virtual bool IncreaseAdjustFailTimes(int pos, int actType) = 0;
	//根据储能位置得到调节连续失败次数
	virtual int GetAdjustFailTimes(int pos) = 0;
	//根据储能位置判断是否可调节。actType：0--调节有功；1--调节无功；2--全部
	virtual bool CanAdjust(int pos, int actType) = 0;

	//计算储能SOC档位
	virtual int CalculateSocPos(float minSoc, float maxSoc, float curSoc, float curP) = 0;

	//根据储能位置判断指定位置的储能装置是否人工闭锁了投入操作
	virtual bool ManuLockAdd(int pos) = 0;
	//根据储能位置判断指定位置的储能装置是否人工闭锁了切除操作
	virtual bool ManuLockCut(int pos) = 0;

	//根据储能位置得到有功调节目标值遥测ID
	virtual int GetCtrlAimPId(int pos) = 0;
	//根据储能位置得到无功调节目标值遥测ID
	virtual int GetCtrlAimQId(int pos) = 0;

	//根据储能位置得到PCS黑启动控制ID
	virtual int GetBlackStartCtrlID(int pos) = 0;
	//根据储能位置得到当前储能可用支路比率
	virtual double GetCurCapaRate(int pos) = 0;

	//根据储能位置得到PCS零值死区(kVar)
	virtual double GetPcsZeroValue(int pos) = 0;
	//根据储能位置得到PCS容量kW
	virtual double GetPcsCapacity(int pos) = 0;

	//根据储能设备位置得到当前运行状态
	virtual int GetCurRunState(int pos) = 0;
	//根据储能设备位置设置当前运行状态
	virtual bool SetCurRunState(int pos, int runState) = 0;

	//将指定位置的储能根据有功出力从大到小加入储能装置集合中
	virtual void AddObjectIntoStorageListByP(int pos, intarray& list) = 0; 
	//将指定位置的储能根据无功出力从大到小加入储能装置集合中
	virtual void AddObjectIntoStorageListByQ(int pos, intarray& list) = 0;

	//根据储能设备位置判断是否可调节有功功率
	virtual bool CanAdjustP(int pos) = 0;
	//根据储能设备位置判断是否可调节无功功率
	virtual bool CanAdjustQ(int pos) = 0;

	//计算储能设备的综合运行状态
	virtual RUNSTATETYPE CalcCurRunStateType(int pos, bool& canAdjP, IEquipDao* pEquip, int* eqpPos) = 0;

	//根据储能装置位置得到最大可调无功类型。 0：固定值  1：根据容量与当前有功实时计算
	virtual int GetQCtrlType(int pos) = 0;

};

#endif
