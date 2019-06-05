//icsfdao.h

#ifndef _ICSFDAO_PENGSHIKANG_20100915_H_
#define _ICSFDAO_PENGSHIKANG_20100915_H_

#include "../../ibasicdao.h"                        // for IBasicDao
#include "../../../icsvalue.h"                      // for icsarray

#define CsfDao_CLASSID    "ccsfdao"
#define CsfDao_INTFID     "icsfdao"

struct DataMeasType // 一个测点数据信息
{
	int dataId;    //数据ID
	int dataPos;   //数据位置 
	int measTypeId;//数据的测点类型ID
};

struct DataMeasTypeSet //一个设备对应的测点数据集合
{
	int measCount;            //测点个数
	DataMeasType** pMeasTypes;//测点数据信息_数组
};

class ICsfDao : virtual public IBasicDao
{
public:
	//根据前置上传量位置得到厂站ID
	virtual int GetStationId(int pos) = 0;
	//根据前置上传量位置得到间隔ID
	virtual int GetBayId(int pos) = 0;
	//根据前置上传量位置得到设备ID
	virtual int GetEquipId(int pos) = 0;
	//根据前置上传量位置得到测控量类型ID
	virtual int GetMeasType(int pos) = 0;

	//根据前置上传量位置得到描述
	virtual const char* GetDescription(int pos) = 0;
	//根据前置上传量位置得到路径
	virtual const char* GetPathName(int pos) = 0;
	//根据前置上传量位置得到路径参引
	virtual const char* GetPathReference(int pos) = 0;
	//根据前置上传量位置得到是否转发标志
	virtual int GetDataTransFlag(int pos) = 0;

	//根据前置上传量的路径参引得到记录位置
	virtual int GetPositionByPathRef(const char* pathRef) = 0;

	//根据定值量位置得到采集数据源号
	virtual int GetRawSourceId(int pos) = 0;
	//根据定值量位置得到采集数据点号
	virtual int GetRawPointId(int pos) = 0;
	
	//根据前置上传量位置得到采集数据的采集源和采集点号
	virtual void GetRawSrcPointId(int pos, int& nSrcId, int& nPntId) = 0;
	//根据前置上传量位置设置采集数据的采集源和采集点号
	virtual void SetRawSrcPointId(int pos, int nSrcId, int nPntId) = 0;
	
	//根据前置上传量位置得到当前时间
	virtual double GetCurTime(int pos) = 0;
	//根据前置上传量位置设置当前时间
	virtual bool SetCurTime(int pos, double dTime) = 0;
	
	//根据前置上传量位置得到操作报警状态
	virtual int GetOperateState(int pos) = 0;
	//根据前置上传量位置设置操作报警状态
	virtual bool SetOperateState(int pos, int nOprState) = 0;
	
	//根据前置上传量位置得到闭锁标志
	virtual int GetLockFlag(int pos) = 0;
	//根据前置上传量位置设置闭锁标志
	virtual bool SetLockFlag(int pos, int lockFlag) = 0;

	//根据指定设备ID获得该设备某一类型采集量的所有ID列表
	virtual DataMeasTypeSet* GetMeasArrayByEquipId(int eqpId) = 0;

protected:
	//读取前置上传的非采集量表的全部静态信息
	virtual int ReadCsfStaticInfo(const char* strFilter, bool onlyRead, int fldNum, const char nameList[][64]) = 0;
	//读取前置采集量表的全部静态信息
	virtual int ReadRawStaticInfo(const char* strFilter, bool onlyRead, int fldNum, const char nameList[][64]) = 0;

	//使用当前时间字段索引
	virtual int UseIndex_CurrTime() = 0;
	//使用操作报警状态字段索引
	virtual int UseIndex_OperState() = 0;
	//使用闭锁标志字段索引
	virtual int UseIndex_LockFlag() = 0;
	//使用是否转发标志字段索引
	virtual int UseIndex_TransFlag() = 0;

	//使用当前数据来源RTU号索引
	virtual int UseIndex_CommSrc() = 0;
	//使用当前采集测点号索引
	virtual int UseIndex_CommPnt() = 0;

};

#endif
