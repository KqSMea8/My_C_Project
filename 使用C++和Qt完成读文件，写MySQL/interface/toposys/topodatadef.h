////////////////////////////////////////////////////////////////////
//文件名：			topodatadef.h
//接口函数：		无
//接口说明：		无
//主要功能：		定义网络拓扑分析接口输入输出的对象数据结构
//开发者：			彭世康
//开发日期：		2012.06.03
//版本：			1.0版；
//版权信息:			许继软件技术中心
//更改记录：		创建时间：2012-06-03, 创建人：彭世康（Peng Shikang, psk）
////////////////////////////////////////////////////////////////////
#ifndef __TOPODATADEFINE_PENGSHIKANG_20120603_HEADER__
#define __TOPODATADEFINE_PENGSHIKANG_20120603_HEADER__

#define MAXIDADDONE 65536


//////////////////////////////////////////////////////////////////////////////////////
/*对象数据结构定义*/
//////////////////////////////////////////////////////////////////////////////////////

typedef unsigned char  UCHAR;
typedef unsigned short UWORD;
typedef unsigned int   UINT;

#include <interface/icsvalue.h>  // for TopoNetwork

//////////////////////////////////////////////////////////////////////////////////////
//输入模型
//////////////////////////////////////////////////////////////////////////////////////
/*
struct intarray
{
	UINT count;
	int* values;
};
*/
//设备类型
/*
enum EQUIPTYPE
{
	ET_Invalid,              //无效设备类型
	ET_Ground,		         //接地
	ET_Generator,            //发电机
	ET_Load,                 //负荷
	ET_Storage,              //储能
	ET_QCompens,             //并联无功补偿器
	ET_Bus,                  //母线
	ET_Line,                 //线路
	ET_2WindingTrans,        //两绕组变压器
	ET_3WindingTrans,        //三绕组变压器
	ET_Capacitor,            //串联电容器
	ET_Reactor,              //串联电抗器
	ET_Breaker,              //断路器开关
	ET_Switch,               //刀闸开关
	ET_Count                 //设备类型种数
};
*/

typedef int EQUIPTYPE;

//端子类型
enum PORTTYPE                // 端子类型
{
	PT_NotPort = 0,		     //非拓扑端子（为普通图形元素）
	PT_LinkPort = 1,		 //普通拓扑端子（连接口）
	PT_Import = 2,			 //输入端子（入口、源端子、电源端子）
	PT_Export = 3,			 //输出端子（出口、宿端子、负荷端子）
	PT_GrobalPort = 4,		 //全局等效端子（公共的接地端子）
	PT_ImportExport = 5,
	PT_IsolatedPort = 6,	 //孤立端子（与同一元件中其他端子不连通）
	PT_Count                 //端子类型种数
};

//拓扑网络总体信息
struct TopoNetwork           //拓扑网络总体信息
{
	char strName[64];          //(i)系统名称
	UINT iNodeNumForIsland;    //(i)有效岛需要的最少节点数，默认为2
	UINT iInNodeNumForActIsla; //(i)活岛需要的最少电源节点数，默认为1
	UINT iOutNodeNumForActIsla;//(i)活岛需要的最少负荷节点数，默认为1
	UINT iAnalCycleInSecond;   //(i)拓扑分析周期间隔（秒数），默认为2
	UINT iEquipTypeCount;      //(o)设备类型种数
	UINT iEquipmentCount;      //(o)总设备台数
	UINT iSwitchEquipCount;    //(o)总开关设备台数
	UINT iConnectionCount;     //(o)总连接关系条数
	UINT iStorageEquipCount;        //储能设备数量
};

//设备类型的端子信息
struct TopoEquipType         //设备类型的端子信息
{
	EQUIPTYPE eType;         //(i)设备类型
	UCHAR cPortTypes[8];     //(i)拓扑端子类型数组。cPortTypes[0]，拓扑端子个数，取值为1~4；cPortTypes[6]，是否为开关设备；
	                         // cPortTypes[7]，是否为支路设备，0--非支路；1--支路；2--断路器。
	                         // cPortTypes[1~4]，拓扑端子类型元素，取值为0时对应于非拓扑端子、无效端子。
							/*三卷变中性点，可以定义为普通拓扑端子、全局等效端子。
							假设三卷变的高压侧、中压侧、低压侧、中性点的端子序号分别为1、2、3、4，
							端子1、2、3均为普通拓扑端子，
							若4定义为普通拓扑端子（元素值为0），则在元件内部，端子1、2、3均有支路与普通端子4连通；
							若4定义为全局等效端子（元素值为4），则在元件内部，端子1、2、3均有支路与接地端子4连通。
							*/
};

//拓扑设备信息
struct TopoEquipment         //拓扑设备信息
{
	int id;                  //(i)设备ID，主键，>0。
	EQUIPTYPE eType;         //(i)设备类型
	bool isSwitch;           //(o)是否为开关设备
	int statusId;
};

//开关设备的实时通断状态信息
struct TopoSwitch
{
	int iEquipId;            //(i)开关设备ID，主键，>0。
	int iStatusId;           //(i)开关设备的状态量ID。
	int eConnectFlag;        //(o)连通状态，0--断开或退出，1--连通或运行
	bool asBranch;           //(o)是否为支路设备，默认为0。
	int eIsNew;              //(o)是否为新的输出数据，0--否，1--是
};

//储能设备
struct TopoStorage
{
	int iEquipId;            //(i)设备ID，主键，>0。
	int iVFModStatID;           //(i)状态量ID。
	int iVFModValue;        //(o)0--负荷，1--电源
	int eIsNew;          //(o)是否为新的输出数据，0--否，1--是
};

//设备连接关系信息
struct TopoConnection        //设备连接关系信息
{
	int id;                  //(i)连接关系ID，主键，>0，一般从1开始编号
	int iEquipId1;           //(i)拓扑设备1的ID
	int iPortNo1;            //(i)拓扑设备1的端子编号，取值为1~4。
	int iEquipId2;           //(i)拓扑设备2的ID
	int iPortNo2;            //(i)拓扑设备2的端子编号，取值为1~4。
};


//////////////////////////////////////////////////////////////////////////////////////
//输出模型
//////////////////////////////////////////////////////////////////////////////////////

//节点类型
enum NODETYPE                //节点类型
{
	NT_NullNode = 0,         //空节点（联络节点）
	NT_LinkNode = 1,		 //普通节点（联络节点）
	NT_InNode = 2,			 //输入节点（入口节点、源节点、电源节点）
	NT_OutNode = 3,			 //输出节点（出口节点、宿节点、负荷节点）
	NT_GrobalNode = 4,		 //全局等效节点（公共的接地节点）
	NT_AllNode = 5,	         //输入输出节点（电源负荷节点）
};

//拓扑分析错误编码
enum TOPOERRCODE
{
	TPR_Succeed,             //拓扑分析正常完成
	TPR_NotStart,            //拓扑分析未开始
	TPR_MallocFail,          //内存分配失败
};

//拓扑网络总体输出信息
struct TopoNetOut            //拓扑网络总体输出信息
{
	int iJoinCount;          //(o)总连接（物理）结点个数.
	int iNodeCount;          //(o)总计算结点个数.
	int iBranchCount;        //(o)总计算支路条数
	int iIslandCount;        //(o)总有效岛个数.
	int iActIslaCount;       //(o)总活岛个数.
	int iMaxJoinNo;          //(o)最大连接结点编号.
	int iMaxNodeNo;          //(o)最大计算结点编号.
	int iMaxBranchNo;        //(o)最大计算支路编号
	int iMaxIslandNo;        //(o)最大有效岛编号.
	int iAnalTimeInMilSec;   //(o)拓扑分析时间，以毫秒计.
	TOPOERRCODE eResultCode; //(o)拓扑分析错误编码
};

//拓扑设备输出信息
struct TopoEquipOut          //拓扑设备输出信息
{
	int iEquipId;            //(i)设备ID
	UWORD iPortJoinNo[4];    //(o)每一个端子对应的连接结点号，0--无连接结点，>0--有效连接结点
	UWORD iPortNodeNo[4];    //(o)每一个端子对应的计算结点号，0--无计算结点，>0--有效计算结点
	int iIslandNo;           //(o)所属岛号，-1--未知岛，0--无效岛，>0--有效岛
	int eActiveFlag;         //(o)岛是否为活岛，0--死岛，1--活岛
	int eIsNew;              //(o)是否为新的输出数据，0--否，1--是
};

//设备连接关系输出信息
struct TopoConnectOut        //设备连接关系信息
{
	int iConnId;             //(i)连接关系ID
	int iJoinNo;             //(o)所属连接结点号，0--无连接结点，>0--有效连接结点
	int iNodeNo;             //(o)所属计算结点号，0--无计算结点，>0--有效计算结点
	int eIsNew;              //(o)是否为新的输出数据，0--否，1--是
};

//连接结点
struct TopoJoin              //输出，由拓扑分析业务（1）自动生成
{
	int iNo;                 //(o)连接结点号，主键，>=0有效，一般从1开始编号，负值表示该连接结点为无效的连接结点。1~65535
	int iPortCount;          //(o)包含的端子数
	NODETYPE eTypeFlag;      //(o)结点类别。
	int iNodeNo;             //(o)所属计算结点号，0--无计算结点，>0--有效计算结点
	int iIslandNo;           //(o)所属拓扑岛号，-1--未知岛，0--无效岛，>0--有效岛
	int eIsNew;              //(o)是否为新的输出数据，0--否，1--是
	int* pDots;              //连接节点中所包含的设备端点数组
};

//计算结点
struct TopoNode              //输出，由拓扑分析业务（2）自动生成
{
	int iNo;                 //(o)结点号，主键，>=0有效，一般从1开始编号，负值表示该计算节点为无效的计算节点。
	NODETYPE eTypeFlag;      //(o)结点类别。
	int iIslandNo;           //(o)所属拓扑岛号
	int iInnerNo;            //(o)岛内结点号，在拓扑岛内重新从1开始连续编号。
	UWORD iParent;           //(o)父节点ID
	int eIsNew;              //(o)是否为新的输出数据，0--否，1--是
	int* pDots;              //计算节点中所包含的连接节点数组
	int joinCount;            //计算节点包含的连接节点数
};

//计算支路
struct TopoBranch             //输出，由拓扑分析业务（2）自动生成
{
	int iNo;                  //(o)支路号，主键，>=0有效，一般从1开始编号，负值表示该计算支路为无效的计算支路。
	int iEquipId;             //(i)所属设备ID
	int iPort1No;             //(i)设备首端端子号
	int iPort2No;             //(i)设备末端端子号
	int iNode1No;             //(o)首端计算结点号
	int iNode2No;             //(o)末端计算结点号：为0时，表示末端子悬空（为无效结点）；与首端计算结点号相同时，表示接地支路。
	int iIslandNo;            //(o)所属拓扑岛号
	int eIsNew;               //(o)是否为新的输出数据，0--否，1--是
};

//拓扑岛
struct TopoIsland            //输出，由拓扑分析业务（2）自动生成
{
	int iNo;                 //(o)拓扑岛号，主键，>=0有效，一般从1开始编号，负值表示该拓扑岛为无效的拓扑岛信息。
	int iBranchCount;        //(o)计算支路条数
	int iNodeCount;          //(o)计算结点个数
	int iPowerCount;         //(o)电源结点数.
	int iLoadCount;          //(o)负荷结点数.
	int iBothCount;          //(o)电源负荷结点数.
	int iGroundCount;        //(o)对地结点数.
	int eActiveFlag;         //(o)是否为活岛，0--死岛，1--活岛
	int eIsNew;              //(o)是否为新的输出数据，0--否，1--是
};

struct SearchEquip
{
	int equipID;
	int parentIndex;
};


#endif // __TOPODATADEFINE_PENGSHIKANG_20120603_HEADER__
