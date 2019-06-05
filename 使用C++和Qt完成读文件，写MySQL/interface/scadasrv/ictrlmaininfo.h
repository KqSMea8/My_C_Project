/*******************************************************
 * ictrlmaininfo -- 服务端Scada控制主业务的主体数据接口
 *******************************************************/

#ifndef __ICONTROLMAININFOMATION_PENGSHIKANG_H_20171221
#define __ICONTROLMAININFOMATION_PENGSHIKANG_H_20171221

#include "scadadatadef.h"// for CONTROLORIGIN、AUTOEXECUTESELECTCMD

class IExpressCalculate;
class ICtrlRelatData;

class ICtrlMainInfo
{
public:
	//0--
	virtual void SetExprCalc(IExpressCalculate* pExprCalc) = 0;
	virtual void SetControlData(ICtrlRelatData* pCtrlData) = 0;
	virtual ICtrlRelatData* MakeControlData(int ctrlPos, int commsrcId) = 0;//(2_0)生成遥控关联对象的数据类型处理者
	virtual void InitializeMe(ICtrlRelatData* pCtrlData) = 0;

	//1-- 设置控制类型、是否检查控制条件满足。
	virtual void SetControlTypeAndCheckCtrl(int ctrlPos, bool bCheckControl) = 0;
	virtual int GetControlType() = 0;                           //得到控制操作类型
	virtual bool IsSelectControl() = 0;                         //是否为选控操作
	virtual void SetCheckControlFlag(bool bCheckControl) = 0;   //设置是否检查控制条件满足标志[暂未用]
	virtual bool GetCheckControlFlag() = 0;                     //得到是否检查控制条件满足标志

	//2-- 设置是否需要等待控制结果返回（群控时设置为false）
	virtual void SetNeedWaitFlagIn(bool needWait) = 0;
	//判断是否需要等待控制结果返回（群控时返回false）
	virtual bool GetNeedWaitFlagIn() = 0;
	//判断控点是否需要等待控制结果返回令
	virtual bool NeedWaitCtrlReturn() = 0;

	//3--m_bWaitReturned
	virtual void SetWaitReturned(bool bReturned) = 0;//设置是否等待控制结果返回 [有锁]
	virtual bool GetWaitReturned() = 0;

	//4-- m_bWaitChanged
	virtual bool NeedCheckChanged() = 0;			//是否需要判遥信变位/遥测变化[等待锁在外面添加]
	virtual void InitWaitChangeFlag() = 0;          //初始化是否等待控制关联测点的值变化
	virtual bool UpdateWaitChangeFlag() = 0;        //更新是否等待控制关联测点的值变化 _autoExec != AESC_CONTROL
	virtual bool InWaitChanging() = 0;              //检查是否等待控制关联测点的值变化

	//5-- m_ctrlFlags
	virtual void InitControlFlag() = 0;
	virtual void UpdateControlFlag(int ctrlPos) = 0;
	virtual bool HasControlFlag(int iFlagCode) = 0;

	//6-- m_autoExec
	virtual void InitAutoExecFlag(bool bAutoCtrl) = 0;//初始化自动执行选择令标志
	virtual void SetAutoExecFlag(char autoExec) = 0;
	virtual char GetAutoExecFlag() = 0; //有锁未用
	virtual bool AutoToNoguard() = 0;   //检测是否‘选控结果返回后自动转直控’ [有锁]

	//7-- m_cmdType
	virtual void InitCommandType() = 0;//初始化遥控进度标识为-1 [无锁]
	virtual void SetCommandType(char cmdType) = 0;
	virtual char GetCommandType() = 0;//遥控进度标识：-2：等待监护机返回；-1：未开始；0：选择控制；1：执行控制；2：撤销控制；

	//8-- m_ctrlCode and m_ctrlValueID
	virtual void UpdateCtrlCodeAndValueID(int ctrlValPos) = 0;
	virtual OPERATETYPE GetControlCode() = 0;
	virtual int GetControlValueID() = 0;

	//9-- m_ctrlValue and m_aimValue
	virtual void UpdateAimValueAndCtrlValue(int ctrlId, const char* newValue) = 0;
	virtual void SetCtrlValueAndAimValue(float ctrlValue, double aimValue) = 0;//设置控制值和目标值[五防控制用]
	virtual void GetCtrlValueAndAimValue(float& ctrlValue, double& aimValue) = 0;//获取控制值和目标值
	virtual void SetCtrlValue(float ctrlValue) = 0;//设置控制值
	virtual void SetAimValue(double aimValue) = 0;//设置目标值
	virtual float GetCtrlValue() = 0;//设置控制值
	virtual double GetAimValue() = 0;//获取目标值

	// 10-- m_wfmode
	virtual void InitWFMode() = 0;//初始化五防处理模式：m_wfmode = 0
	virtual void UpdateWFMode(int ctrlPos) = 0;//更新五防处理模式
	virtual bool HasWFCheck(int wfMode) = 0;   //是否进行五防检查

	//11-- m_userName and m_posterName
	//设置用户名和消息发送者名称
	virtual void SetUserAndPosterName(const char* sUserName, const char* psPoster) = 0;
	//初始化用户名和消息发送者名称
	virtual void InitUserAndPosterName() = 0;
	//设置用户名
	virtual void SetUserName(const char* sUserName) = 0;
	//初始化用户名
	virtual void InitUserName() = 0;
	//得到用户名指针
	virtual const char* GetUserName() = 0;
	//提取消息发送者名称
	virtual void TakePosterName(char* psName) = 0;

	//（1）根据控制量位置得到关联的测量量类型、遥信遥测量ID。
	virtual int GetRelativeMeasureObjectIdIn(int ctrlPos, int& measType) = 0;
	//（2）根据控制量位置和遥信量目标值得到控制对应的遥信量ID、操作类型码。
	virtual bool GetCtrlTypeByAimValueIn(int ctrlPos, int aimValue, int& statusId, OPERATETYPE& ctrlType) = 0;
	//（3）根据控制量位置和操作类型码得到控制对应的控制值类型记录位置、控制命令值。
	virtual bool GetCtrlValueByCtrlTypeIn(int ctrlPos, OPERATETYPE ctrlType, int& ctrlValTypPos, int& ctrlValue) = 0;

	//（4）根据控制量的操作类型码、测量点类型和ID得到控制对应的测量点位置和目标值。返回值：0, 失败；1, 目标值为当前值；2, 目标值为新值。
	virtual int GetAimValueByDataType(OPERATETYPE ctrlType, int dataType, int dataID, int& dataPos, int& aimValue) = 0;
	//（5）根据控制量位置和操作类型码得到控制对应的目标值。返回值：0, 失败；1, 目标值为当前值；2, 目标值为新值。
	virtual int GetAimValueByCtrlType(int ctrlPos, OPERATETYPE ctrlType, int& aimValue) = 0;
	//（6）根据控制量位置和控制值类型ID得到控制对应的控制值类型记录位置、控制命令值和遥信量目标值[遥控表访问]
	virtual bool GetAimValueByCtrlValTypID(int ctrlPos, int ctrlValTypId, int& ctrlValTypPos, int& ctrlValue, int& aimValue) = 0;
	//（7）根据控制量位置和控制命令值得到控制对应的测控量类型、控制值类型记录位置、控制命令值和遥信量目标值[遥控表访问]
	virtual bool GetAimValueByCtrlValueIn(int ctrlPos, int ctrlValue, int& measTypeId, OPERATETYPE& ctrlType, int& ctrlValTypPos, int& aimValue) = 0;

	//（8）根据控制量位置和操作类型码得到控制对应测点的类型、ID、位置和目标值。返回值：0, 失败；1, 目标值为当前值；2, 目标值为新值。
	virtual int GetControlAimValueIn(int ctrlPos, OPERATETYPE ctrlType, int& dataType, int& dataID, int& dataPos, int& aimValue) = 0;
	//（9）根据控制量位置得到控制对应测点的类型、ID、位置和当前值。返回值：0, 失败；1, 目标值为当前值；2, 目标值为新值。
	virtual bool GetControlCurValueIn(int ctrlPos, int& dataType, int& dataID, int& dataPos, double& curValue) = 0;
	//（10）根据控制量操作类型、关联测点位置和目标值，检测控制是否已达到目标值。
	virtual bool CheckControlEnabledIn(OPERATETYPE ctrlType, int dataPos, int aimValue) = 0;
	//（11）根据控制量关联测点的位置、当前值和目标值，检测控制是否已达到目标值。
	virtual bool CheckAdjustEnabledIn(int dataPos, double curValue, double aimValue) = 0;

	//（12）检查控制量ID是否可以进行自动策略控制。autoType：1--AGC策略；2--AVC策略
	virtual bool CanAutoControlIn(int ctrlId, int ctrlType, int autoType) = 0;

	//(13)得到控制关联测点的虚点表达式
	virtual bool GetDummyExpr(int exprPos, char* strExpr, char* sErrorInfo) = 0;
	//(14)记录控制成功信息[遥控表访问]
	virtual void RecordControlSuccess(int ctrlId) = 0;

};

#endif