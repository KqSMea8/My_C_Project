// exprmapdef.h
//
//////////////////////////////////////////////////////////////////////

#ifndef _BUSSINESSDDATATRANSDEFINE_H__PENGSHIKANG_20160510__INCLUDED_
#define _BUSSINESSDDATATRANSDEFINE_H__PENGSHIKANG_20160510__INCLUDED_


struct BussClmnInfo // 业务表对象属性的实时表位置信息
{
	int equipId;      //数据实时表记录设备ID
	//int clmnCount;    //业务表对象个数
	int* pValuePos;   //业务表字段配置_数组
};

struct BussTblInfo // 业务表记录信息
{
	int tblCfgId;            //‘业务表转存配置’表ID
	int clmnCount;           //业务表对象的实时字段数
	int objCount;            //业务表对象个数
	BussClmnInfo** pBussDatas;//业务表对象属性的实时表位置信息_数组
};

////////////////////////////////////////////////

struct EquipData // 一个数据实时表记录的设备信息
{
	int equipId;      //数据实时表记录设备ID
	int dataPos;      //数据实时表记录位置
};

struct MeasTypeSet // 一个‘数据测点类型ID’对应的记录设备信息集合
{
	int dataType;          //数据实时表类型 1:analog，2:status 3:accumulator 
	int eqpCount;          //数据实时表记录个数
	EquipData* pDataEquips;//记录设备信息_数组
};

////////////////////////////////////////////////

struct BussClmn // 一个‘业务表转存配置’的业务表字段配置
{
	int dataType;      //数据实时表类型 1:analog，2:status 3:accumulator 
	int measTypeId;    //数据测点类型ID
	char clmnName[64]; //业务表字段名称
};

struct BussTbl // 业务表配置
{
	int tblCfgId;        //‘业务表转存配置’表ID
	char tblName[64];    //业务表名称
	char keyName[64];    //业务表‘设备ID’主键字段名称
	int count;           //业务表数据实时字段个数
	BussClmn** pBussClmns;//业务表字段配置_数组
};

struct BussTblSet //一个定时器对应的业务表配置集合
{
	int count;           //业务表个数
	BussTbl** pBussTbls;  //业务表配置数组
};

#endif
