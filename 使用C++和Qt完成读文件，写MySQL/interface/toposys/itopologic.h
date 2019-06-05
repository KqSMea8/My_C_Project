/////////////////////////////////////////////////////////////
//文件名：			itopologic.h: interface for the ITopologic class.
//接口说明：		参见各接口函数的注释部分
//主要功能：		网络拓扑分析函数的头文件
//开发者：			彭世康
//开发日期：		2012.06.03
//版本：			1.0版；
//版权信息:			许继软件技术中心
//更改记录：		创建时间：2012-06-03, 创建人：彭世康（Peng Shikang, psk）
/////////////////////////////////////////////////////////////

#ifndef __INTFNEWTOPOLOGIC_PENGSHIKANG_20120603_HEADER__
#define __INTFNEWTOPOLOGIC_PENGSHIKANG_20120603_HEADER__

#include "topodatadef.h"   //for TopoNetwork, etc.
#include "../icsunknown.h" //for IICSUnknown

#define MODULE_TOPOLOGIC      "topologic"
#define CLSID_TOPOLOGIC       "cls_topologic"
#define IID_TOPOLOGIC         "intf_topologic"

/*
ITopologic接口
*/
class ITopologic : public IICSUnknown
{
public: 
	
	////////////////////////////////////////////////////////////////////////////////
	/* 以下函数输入拓扑分析模型数据 */
	////////////////////////////////////////////////////////////////////////////////
	
	//(1)输入静态信息
	//输入网络总体信息，参数pNetwork为输入的系统信息指针。
	virtual bool SetNetworkInfo(const TopoNetwork* pNetwork) = 0;
	//输入设备类型信息，参数pEqpTypes为输入的设备类型数组首地址，数组长度由pNetwork决定。
	virtual bool SetEquipTypeInfo(const TopoEquipType* pEqpTypes) = 0;
	//输入设备信息，参数pEquip为输入的设备数组首地址，数组长度由pNetwork决定。
	virtual bool SetEquipmentInfo(const TopoEquipment* pEquips) = 0;
	//输入连接关系信息，参数pConns为输入的连接关系数组首地址，数组长度由pNetwork决定。
	virtual bool SetConnectionInfo(const TopoConnection* pConns) = 0;

	//(2)输入动态信息
	//更新开关设备的实时通断状态信息，参数pSwitchs为开关设备状态数组首地址，数组长度由pNetwork决定。
	virtual bool UpdateSwitchEquipState(const TopoSwitch* pSwitchs) = 0;
	
	////////////////////////////////////////////////////////////////////////////////
	/* 以下函数执行拓扑分析 */
	////////////////////////////////////////////////////////////////////////////////
	
	//全系统设备参与的完整拓扑分析（常用于服务启动时进行一次全系统的拓扑分析）
	virtual TOPOERRCODE EntireTopologyAnalyze() = 0;
	
	//在上一次拓扑分析的基础上，根据当前元件的通断变化情况进行更新式拓扑分析。（最常用）
	virtual TOPOERRCODE UpdateTopologyAnalyze() = 0;

	////////////////////////////////////////////////////////////////////////////////
	/* 以下函数输出拓扑分析结果。调用的前提：已成功执行了整体拓扑分析，即m_nErrorCode==TPR_Succeed。*/
	////////////////////////////////////////////////////////////////////////////////
	
	//得到最大连接节点号
	virtual int GetMaxJoinNo() = 0;
	//得到最大拓扑岛号
	virtual int GetMaxIslandNo() = 0;
	//得到最大计算节点号
	virtual int GetMaxNodeNo() = 0;
	//得到最大计算支路号
	virtual int GetMaxBranchNo() = 0;
	
	//得到设备ID对应的设备在数组中的位置（下标）。-1表示不存在。
	virtual int GetTopoEquipPosById(int id) = 0;
	//得到连接关系ID对应的连接关系在数组中的位置（下标）。-1表示不存在。
	virtual int GetTopoConnectPosById(int id) = 0;
	//根据设备首末端子号得到对应的计算支路编号。0表示不存在。
	virtual int GetTopoBranchNoByPortNo(int equipId, int portNo1, int portNo2) = 0;
	
	//输出拓扑网络总体分析结果信息
	virtual const TopoNetOut* GetTopoNetOutInfo() = 0;
	//输出所有设备拓扑结果信息，数组长度由pNetwork决定。
	virtual const TopoEquipOut* GetTopoEquipOutInfo() = 0;
	//输出所有连接关系拓扑结果信息，数组长度由pNetwork决定。
	virtual const TopoConnectOut* GetTopoConnectOutInfo() = 0;
	//输出所有连接节点信息，数组长度由pTopoNetOut决定。
	virtual const TopoJoin* GetJoinSetInfo() = 0;
	//输出所有计算节点信息，数组长度由pTopoNetOut决定。
	virtual const TopoNode* GetNodeSetInfo() = 0;
	//输出所有计算支路信息，数组长度由pTopoNetOut决定。
	virtual const TopoBranch* GetBranchSetInfo() = 0;
	//输出所有拓扑岛信息，数组长度由pTopoNetOut决定。
	virtual const TopoIsland* GetIslandSetInfo() = 0;

	//得到设备ID对应的设备输出对象信息
	virtual bool GetTopoEquipOutObject(int id, TopoEquipOut& tpEquip) = 0;
	//得到连接关系ID对应的连接关系输出对象信息
	virtual bool GetTopoConnectOutObject(int id, TopoConnectOut& tpConn) = 0;
	//输出指定编号的连接节点对象信息
	virtual bool GetJoinObject(int no, TopoJoin& tpJoin) = 0;
	//输出指定编号的拓扑岛对象信息
	virtual bool GetIslandObject(int no, TopoIsland& tpIsland) = 0;
	//输出指定编号的计算节点对象信息
	virtual bool GetNodeObject(int no, TopoNode& tpNode) = 0;
	//输出指定编号的计算支路对象信息
	virtual bool GetBranchObject(int no, TopoBranch& tpBranch) = 0;

	//得到指定节点的供电来源路径
	virtual bool GetSourceEquipList(int eqpId, intarray& srcEquips, int& srcCount) = 0;

	//得到指定节点影响的供电范围
	virtual bool GetLoadEquipList(int eqpId, intarray& pLoadEquips) = 0;

	//搜索由于断路器跳闸所引起的失电设备
	virtual SearchEquip* GetLossEquipArray(int brkID, int& returnCount)=0;

	//从一个开关出发，搜索转供联络开关
	virtual int* GetLianluoSwitch(int switchID, int* geliIDs, int geliCount, bool bMustAlive, int& returnCount) = 0;
	
	virtual bool UpdateStorageEquipState(const TopoStorage* pStorages) = 0;



	
    //这个函数仅给智能指针模板用
    static char* GetIntfName()
    {
        return IID_TOPOLOGIC;
    }; 
};

#endif //__INTFNEWTOPOLOGIC_PENGSHIKANG_20120603_HEADER__
