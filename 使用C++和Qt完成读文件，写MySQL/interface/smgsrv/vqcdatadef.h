//vqcdatadef.h
#ifndef _VQCDATADEFINE_PENGSHIKANG_20080714_H_
#define _VQCDATADEFINE_PENGSHIKANG_20080714_H_

#include "../icsvalue.h"                         // for intarray

struct VqcRange
{
	VqcRange() : upper(0.0), lower(0.0) {};
	float upper;//上限值
	float lower;//下限值
};

struct VqcSettingInfo
{
	VqcSettingInfo() : dCtrlV(), dRefV(), dCtrlVLk(), dRefVLk(), dQCos(), fReverseQ(0.0), isAvcType(0), avcPlanId(0) {};
	VqcRange dCtrlV;//控制侧电压(标么)
	VqcRange dRefV;//参考侧电压(标么)
	VqcRange dCtrlVLk;//控制侧闭锁电压(标么)
	VqcRange dRefVLk;//参考侧闭锁电压(标么)
	VqcRange dQCos;//功率因数_无功值
	float fAimU;//目标电压
	float fReverseQ;//最大倒送无功功率
	int isAvcType;//0--Vqc; 1--Avc
	int avcPlanId;
};

struct BusDeviceInfo//母线带有的设备信息
{
	int busId;//自身母线ID
	int bus2Id;//相邻母线ID，0表示无相邻母线
	int connPos;//母线连接关系记录位置
	int transPorts[4];//母线所连变压器侧（变压器Pos + 2bit(电压侧号+1)），0表示未连接变压器
	intarray aryAddRPC;//可增加无功功率的补偿装置集合
	intarray aryCutRPC;//可减少无功功率的补偿装置集合
	intarray aryAdjRPC;//可调节无功功率的补偿装置集合
	intarray aryStor;//可调节无功功率的储能装置集合
	intarray aryGener;//可调节无功功率的发电机集合(可增无功从大到小)
	intarray aryGener1;//可调节无功功率的发电机集合(可减无功从大到小)
	intarray aryGener2;//可调节无功功率的发电机ID集合(并网点电压从大到小)
	int ctrlBusType;  //母线的电压无功控制类型
	bool isConnect;//母联开关是否连通
	float curVolt;//当前电压值
	float totalI; //所连发电机、储能、负荷的电流绝对值的总和
	float maxAddQ;//通过投切无功补偿装置最大可增加的无功功率{正数}(2+)
	float minAddQ;//通过投切无功补偿装置最小可增加的无功功率{正数}
	float maxCutQ;//通过投切无功补偿装置最大可减少的无功功率{正数}(2-)
	float minCutQ;//通过投切无功补偿装置最小可减少的无功功率{正数}
	float maxIncQ;//可调节无功补偿装置的最大可发出无功功率{正数}(3+)
	float maxDecQ;//可调节无功补偿装置的最大可吸收无功功率{正数}(3-)
	float curRpcQ1;//可调无功补偿装置的当前无功出力(4+-)
	float maxRpcS;//可调节无功补偿装置的总无功容量
	float canIncQ;//通过调节发电机最大可增加的无功功率{正数}(1+)
	float canDecQ;//通过调节发电机最大可减少的无功功率{正数}(1-)
	float curGenQ;//可调节发电机当前发出的无功功率
	float curGenS;//可调节发电机当前总的装机容量
	float curGenQo;//可调非主发电机的总无功零敏度
	float maxGenQ;//可调节发电机当前总的最大无功功率
	float maxGenQ1;//以感性无功方式调节的可调发电机的总最大无功功率
	float curStorQ;//储能装置当前总的发出无功功率
	float maxStorQ;//储能装置当前总的最大充放电无功功率
	float curStorS;//储能装置当前总的PCS容量
	float curStorQo;//储能装置当前总的总无功零敏度
};

enum VQCType
{
	BT_Normal,  //0：不参与VQC调节控制
		BT_CtrlVolt,//1：电压调节母线
		BT_RefVolt, //2：电压参考母线
};

enum VQCStrategy
{
	VS_NOACTION,    // 0：不动作
		VS_TAPASCEND,   // 1：升高分接头档位
		VS_TAPDESCEND,  // 2：降低分接头档位
		VS_RPCRUN,      // 3：投入无功补偿设备（增加无功出力）
		VS_RPCCUT,      // 4：切除无功补偿设备（减少无功出力）
		VS_GRPINC,      // 5：增加电源无功出力
		VS_GRPDEC,      // 6：减少电源无功出力
		VS_SRPADJ,      // 7：调节SVC/SVG电压
};

enum VQCAreaType//VQC调节系统类型
{
	AT_0BUS,//无效调节系统
	AT_1BUS,//单母线调节系统
	AT_2BUS,//双母线调节系统
	AT_3BUS,//三母线调节系统
	AT_4BUS,//四母线调节系统
	AT_1BUS_1TRANS,//单母单变压器调节系统
	AT_2BUS_1TRANS,//双母单变压器调节系统
	AT_3BUS_1TRANS,//三母单变压器调节系统[罕见]
	AT_4BUS_1TRANS,//四母单变压器调节系统[罕见]
	AT_1BUS_2TRANS,//单母双变压器调节系统
	AT_2BUS_2TRANS,//双母双变压器调节系统
	AT_3BUS_2TRANS,//三母双变压器调节系统[罕见]
	AT_4BUS_2TRANS,//四母双变压器调节系统
	AT_1BUS_3TRANS,//单母三变压器调节系统[罕见]
	AT_2BUS_3TRANS,//双母三变压器调节系统[罕见]
	AT_3BUS_3TRANS,//三母三变压器调节系统
	AT_4BUS_3TRANS,//四母三变压器调节系统[罕见]
	AT_1BUS_4TRANS,//单母四变压器调节系统[罕见]
	AT_2BUS_4TRANS,//双母四变压器调节系统
	AT_3BUS_4TRANS,//三母四变压器调节系统[罕见]
	AT_4BUS_4TRANS,//四母四变压器调节系统
};

struct VQCAreaInfo//VQC调节系统信息
{
	int id;
	int type;//VQC调节系统类型 -- [双母线|单母线]调节系统；[双母单变压器|单母单变压器]调节系统；[双母双变压器|单母双变压器]调节系统
	int trans[4];//变压器位置
	int ctrlBus[4];//电压控制母线位置
	int refBus[4];//电压参考母线位置
	int rpBus[4];//无功控制母线位置
	intarray aryBus;//母线集合
	intarray aryPcc;//PCC集合
	intarray aryLine;//线路端集合

	VqcRange dCtrlV;//控制侧电压范围                        [与时间相关的定值]
	VqcRange dQCos;//功率因数_无功范围                      [与时间或实际电压相关]
	float reverseQ;//最大倒送无功功率
	float addRpcU;//投切无功补偿装置最小可升高的电压        [与无功控制母线的RPC相关]
	float cutRpcU;//投切无功补偿装置最小可降低的电压        [与无功控制母线的RPC相关]
	float addRpcQ;//投切无功补偿装置最小可减少的无功供电功率[与无功控制母线的RPC相关]
	float cutRpcQ;//投切无功补偿装置最小可增加的无功供电功率[与无功控制母线的RPC相关]
	float actTapU;//升一档分接头影响最小可升高的电压        [与变压器相关]
	float actTapQ;//升一档分接头影响最小可增加的无功供电功率[与变压器相关]
	float maxOffsU;//投退1单位无功引起控制母线的电压最大变化量
	float maxOffsQ;//投退1单位无功引起与大电网的交换无功功率最大变化量
	
	
	float baseU;//额定电压[有名值]
	float curU[2];//当前实际电压{有名值，有名值}
	float offsU;//电压越限量
	float curP;//当前实际有功功率[外部输入母线为正]
	float curQ[2];//当前实际无功功率、实际供电功率因数[外部输入母线为正]
	float offsQ;//无功越限量

	float adjGenS;//投运的可调非主发电机的总装机容量 ok
	float adjGenQ;//投运的可调非主发电机的总发电无功功率 ok
	float adjGenQo;//投运的可调非主发电机的总无功零敏度 ok
	float maxGenQ;//投运的可调非主发电机的总最大无功功率
	float maxGenQ1;//投运的以感性无功方式调节的可调非主发电机的总最大无功功率
	float addAdjGenQ;//投运的可调非主发电机的总最大可增加发电无功功率 ok
	float cutAdjGenQ;//投运的可调非主发电机的总最大可减少发电无功功率 ok
	float curRpcS;//投运的电容器电抗器的总发出无功功率
	float curRpcQ;//投运的可调无功补偿装置的总发出无功功率
	float maxCanIncQ;//可增无功 // cutRpcQ+maxRpcQOut+addAdjGenQ
	float maxCanDecQ;//可减无功 // addRpcQ+maxRpcQIn+adjGenQ
	float maxRpcIncQ;//SVG可增无功
	float maxRpcDecQ;//SVG可减无功
	float curStorQ;//储能装置当前总的发出无功功率
	float maxStorQ;//储能装置当前总的最大充放电无功功率
	float curStorS;//储能装置当前总的PCS容量
	float senStorQo;//投运储能装置的总无功零敏度 ok


	int areaNo;//当前状态在17区图中的区号。1~9、12、14、16、18、22、24、26、28、30、31
	int straPos;//当前状态产生的策略记录位置。-1表示无策略
	int isCosfa;//无功控制目标是否为功率因数。 0--恒电压；1--无功功率；2--功率因数；3--无功功率区间；4--功率因数区间。
	int isPlant;//电压无功控制类型。0：降压站VQC；1：升压站VQC；2：降压站AVC子站；3：升压站AVC子站；4:  AVC主站。
	int straTypeId;//电压无功调节策略类型ID
	int paramState;//配置参数状态。0：无错误；非0：错误码
	int hasAdjust;//是否有策略调节。0：无；1：有。
	int localFlag;//本地标志。0--无策略；1--远程AVC；2--本地AVC；3--本地VQC。

	int nCtrlVoltId; // 电压控制母线的电压等级ID
	int nRpcVoltId;  // 无功控制母线的电压等级ID
	float maxDecQ;   // 电压参考母线允许减少的最大无功量
	float maxIncQ;   // 电压参考母线允许增加的最大无功量
	VqcRange dLockV; // 控制侧闭锁电压范围
};

#endif
