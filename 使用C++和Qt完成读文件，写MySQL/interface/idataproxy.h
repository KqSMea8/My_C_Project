//idataproxy.h
#ifndef _IDATAPROXY_2008_05_13_PENGSHIKANG_INCLUDED_
#define _IDATAPROXY_2008_05_13_PENGSHIKANG_INCLUDED_

#include "icsunknown.h"              // for IICSUnknown
#include "csf/dataobject_scada.h"    // for IICSDAObject

//#ifdef _MSC_VER
	#define DLL_DATAPROXY             "dataproxy"
//#else
//	#define DLL_DATAPROXY             "/home/ics8000/lib/icslib/dataproxy"
//#endif
#define CID_DATAPROXY           "cdataproxy"
#define IID_DATAPROXY           "idataproxy"

#ifndef PVOID
	typedef void* PVOID;
#endif

struct CAPP_SDO_Status
{
	double                   m_dTimeStamp;//本值原始时标
	int                      m_nRawValue; //状态量的原始值
	unsigned short           m_nSrcId;    //对象的数据源号
    unsigned short           m_nPntId;    //对象的采集点号
	int                      m_nEqpPos;   //所属设备ID
	int                      m_nBayPos;   //所属间隔ID
	int                      m_nFacPos;   //所属厂站ID
};//应用层状态量对象

struct CAPP_SDO_Analog
{
	double                   m_dTimeStamp;//本值原始时标
	double                   m_fRawValue; //模拟量的原始值
    unsigned short           m_nPntId;    //对象的采集点号
};//应用层模拟量对象

struct CAPP_SDO_Soe
{
	double                   m_dTimeStamp;//本值原始时标
	double                   m_dTimeSpan; //相对时间
	short*                   m_pfRecord;  //附加参数
	short                    m_nRawValue; //SOE量的原始值
	unsigned short           m_nNum;      //附加参数的数目
	unsigned short           m_nSrcId;    //对象的数据源号
    unsigned short           m_nPntId;    //对象的采集点号
};//应用层SOE对象

//应用层状态量
#define   APP_OBJTYPE_STATUS          151
//应用层模拟量
#define   APP_OBJTYPE_ANALOG          152
//应用层SOE对象（故障报告）
#define   APP_OBJTYPE_EVENTREPORT     161

//上下行操作类型
enum OperateType
{
		RECEIVEDAT,//订阅数据主动上传，不需要进行接收确认
		RECEIVEACK,//订阅数据主动上传，需要进行接收确认
		GETFROMSRC,//直接从数据源读取数据
		GETFROMBUF,//从CSF框架的数据缓存读取数据
		SELECTCTRL,//选控
		OPERATCTRL,//执行控制
		CANCELCTRL,//撤销控制
		CALLVERSION,//版本召唤
		MODIFYSETTING,//定值修改
		SWITCHAREA, //切换定值区
		PRESETSETTING, //预装定值
		SAVESETTING, //固化定值
		CANCELSETTING, //取消预装
		SETTING,		//定值下装
		SWITCHACTAREA, //切换激活区    WX Modify
		SWITCHEDITAREA //切换编辑区    WX Modify
};

struct CSFDATASET //上下行操作的CSF数据集结构
{
	CSF_UINT32 operateId;//本次操作的唯一标识号
	CSF_UINT32 nSrcId;   //本次操作的数据源ID
	CSF_UINT32 type;     //本次操作的数据对象类型
	CSF_UINT32 count;    //本次操作的数据对象个数
	PVOID* pObjects;//本次操作的数据对象指针数组
};

//class CDataProxyApp(CSF_UINT8 nAppId, IDataProxyCallback* pUser, CSF_UINT32 count, CSF_UINT8 dataTypes[], bool bBufferData);

//对象信息下行接口
class IDataProxyApp : virtual public IICSUnknown
{
public:
    /* 得到数据订阅状态 
	   返回值：数据订阅状态，其值的含义为：
		   0, CSF尚未登陆成功
		   1, 数据订阅成功
		   2, 数据订阅失败
		   3, 不需要进行数据订阅
	*/
	virtual int GetSubscriptionState() = 0;
	
	/* 投递一组对象 
	   参数：
		nOperType，本次投递的操作类型。
		nTimeout，本次投递设置的超时时间。
		pObjects，本次投递操作的CSF数据集；
		返回值：
		true,本次投递已经被接纳。
		false,本次投递无法完成。
	*/
	virtual bool Post(OperateType nOperType, long nTimeout, CCSFTransBlock& transBlock) = 0;
	virtual bool Post(OperateType nOperType, long nTimeout, CSFDATASET* pObjects) = 0;
	
	/* 对于接收到的一组对象进行确认 
	   参数：
	    pObjects，应用者接收到的CSF数据集；
	*/
	virtual bool ReceiveAck(CSFDATASET* pObjects) = 0;
	
	//设置CSF通讯客户端主备角色
	virtual void SetRole(bool bMaster) = 0;


	/////////////////////////////////////////////////////////////////////////
	//以下接口用于在线变更前置终端的配置信息
	/////////////////////////////////////////////////////////////////////////

	/* 获取CSF服务器的运行模式
	参数：
	   nNode，通讯主机ID
	   nProt，协议解析模块Id
    返回：0：失败，表示数据代理目前无法接收此指令；
		  1：配置；2：调试；3：运行
	*/
	virtual int GetRunMode(int nNode, int nProt) = 0;
	
	/* 添加数据源通道
	   参数：
	    count，本次添加的数据源通道个数
	    pSrcChnls，本次添加的数据源通道数组   
       返回值：0：成功完成处理；
	           1：失败；
			   2：失败，指令数据代理接收，但AddSrcChnlReturn()回调函数未响应
 	*/
	virtual int AddDataChannel(int count, CCSF_SrcChnl* pSrcChnls) = 0;

	/* 添加对象
	   参数：
          count,本次添加的对象个数
          pObjects,本次添加的对象数组
          nNode，通讯主机ID
          nProt，协议解析模块Id
	   返回：0：成功，表示指令被框架接收，并完成处理
		     1：失败，表示框架目前无法接收此指令
		     2: 失败，表示对象重复
		     3: 失败，指令被数据代理接收，但AddObjReturn()回调函数未响应
	*/
	virtual int AddObject(int count, CCSF_Object* pObjects,
							int nNode=1, int nProt=1)                 = 0;
	
	/* 修改对象
	   返回：0：成功，表示指令被框架接收，并完成处理
			 1：失败，表示框架目前无法接收此指令
			 2：失败，表示无法修改的属性
		     3: 失败，指令被数据代理接收，但SetObjReturn()回调函数未响应
    */
	virtual int SetObject(int count, CCSF_Object* pObjects,
							int nNode=1, int nProt=1)                 = 0;
	
	/* 修改对象
	   参数：
		  count,本次添加的对象个数
		  pObjIds,数据对象Id数组;
		  pCsfIds,数据对象CSFId数组;
          nType,对象类型
          nNode，通讯主机ID
          nProt，协议解析模块Id
	   返回：0：成功，表示指令被框架接收，并完成处理
		  1：失败，表示框架目前无法接收此指令
		  2：失败，表示无法修改的属性
		  3: 失败，指令被数据代理接收，但SetObjReturn()回调函数未响应
    */
	virtual int SetObjectByCSFId(int count, CSF_UINT32* pObjIds, CSF_UINT64* pCsfIds,
							CSF_UINT8 nType, int nNode=1, int nProt=1) = 0;

	/* 读取数据源ID
	   参数：          
		  count,返回的数据源个数
		  pSrcIds,返回的数据源Id数组;
       说明：应用者调用该函数前设置pSrcIds=NULL，调用该函数后由应用者
	   调用delete pSrcIds去释放pSrcIds占用的内存空间。
	*/
	virtual bool GetDataSourceID(int& count, CSF_INT32* pSrcIds)      = 0;

	/* 根据指定的数据源ID读取数据源通道
	   参数：          
	     nSrcId, 指定的数据源ID。如果nSrcId=0，表示读取全部数据源通道。
	     count,返回的数据源通道个数
	     pSrcChnls,返回的数据源通道数组;
       说明：应用者调用该函数前设置pSrcChnls=NULL，调用该函数后由应用者
	   调用delete pSrcChnls去释放pSrcChnls占用的内存空间。
	*/
	virtual bool GetDataChannelBySrcID(int& count, CCSF_SrcChnl* pSrcChnls, int nSrcId=0) = 0;

	/* 根据CSFID获取对象 
	说明：应用者调用该函数前设置pObject=NULL，调用该函数后由应用者
	   调用delete pObject去释放pObject占用的内存空间。
	*/
	virtual bool GetObjectByCsfID(CCSF_Object* pObject, 
							CSF_UINT64 nCsfId, int nNode=1, int nProt=1) = 0;
	
	/* 根据类型获取对象集 
	说明：应用者调用该函数前设置pObjects=NULL，调用该函数后由应用者
	   调用delete pObjects去释放pObjects占用的内存空间。
	*/
	virtual bool GetObjectsByType(int count, CCSF_Object* pObjects,
							CSF_UCHAR nType, int nNode=1, int nProt=1) = 0;
	
	/* 根据父对象CSFID和类型获取对象集
	说明：应用者调用该函数前设置pObjects=NULL，调用该函数后由应用者
	   调用delete pObjects去释放pObjects占用的内存空间。
	*/
	virtual bool GetObjectsByElder(int count, CCSF_Object* pObjects,
							CSF_UINT64 nElderId, CSF_UCHAR  subType,		
							int nNode=1, int nProt=1)                  = 0;

	/* 根据数据对象的类型获取所有数据对象的Id和参引
	说明：应用者调用该函数前设置strRefs、pObjIds为NULL，调用该函数后由应用者
	   调用delete strRefs/pObjIds去释放strRefs、pObjIds占用的内存空间。
	*/
	virtual bool GetAllObjIdAndRefByType(int count, 
							CSF_CHAR strRefs[][1024], CSF_UINT64* pObjIds,
							CSF_UINT8 nType,int nNode=1, int nProt=1)  = 0;

	//前置客户端重新初始化，@@@，2010-11-24
	virtual int ClearConfig() = 0;

	// 更新CSF通讯客户端与CSF通讯服务器的连接 //
	virtual bool UpdateCsfClient() = 0;

	// 是否记录DEBUG日志 //
	virtual void SetDebugLog(bool isDebug) = 0;

	// 设置日志文件名 //
	virtual void SetLogFileName(const char* fileName) = 0;

	static char *GetIntfName()
	{
		return IID_DATAPROXY;
	};

};

//对象信息上行接口
class IDataProxyCallback
{
public:
    /* 接收到一组对象 
	   参数：
	   nOperType，本次接收操作的操作类型。
	   nResult，本次接收操作的结果值，其含义为：
		   0,主动上传的数据
		   1,表示全部成功完成召测或控设操作，参数中所有的属性值有效（操作成功的）
		   2,表示全部成功完成控设操作，参数中所有的属性值无效（无意义的）
		   3,表示部分成功完成召测或控设操作，参数中所有的属性值有效（操作成功的）
		   4,表示控设操作失败，参数中所有的属性值有效（操作失败的）
		   5,表示召测或控设操作失败，参数中所有的属性值无效（无意义的）
		   6,表示召测或控设操作失败，有多个指令同时下发至同一数据源（csf框架无法接收后来者指令）
		   7,表示召测操作失败，此时无法从数据源获取数据（nOperType＝GETFROMSRC时可能发生）
	   pObjects，本次接收到的CSF数据集；
	*/
    virtual void OnReceive(OperateType nOperType, int nResult, CSFDATASET* pObjects) = 0;

	//通道状态变更
	virtual void OnChannelState(CSF_UINT32 nSrcId, CSF_UINT32 nCSFId,
		CSF_UINT32 nDpId, CSF_BOOLEAN bState) = 0;
};

#endif
