//icheckonlineupdate.h

#ifndef _ICHECKONLINEUPDATE_PENGSHIKANG_20101011_H_
#define _ICHECKONLINEUPDATE_PENGSHIKANG_20101011_H_

enum WRITERTDBSTATE
{
	CANWRITERTDB, NEEDREAD, NEEDUPDATE, CANUPDATE,
};

class ICheckOnlineUpdate
{
public:
	//设置写数据库表的状态
	virtual void SetWriteState(WRITERTDBSTATE bCanWrite) = 0;
	//得到写数据库表的状态
	virtual WRITERTDBSTATE GetWriteState() = 0;
	//现在是否能写数据库表
	virtual bool CanWrite() = 0;
	//现在是否不能写数据库表
	//static bool CannotWrite();
	
	//对于数据库在线更新事件加锁访问数据库表的线程处理
	virtual void LockProcess(const char* sType) = 0;
	virtual bool TryLockProcess() = 0;
	//对于数据库在线更新事件解锁访问数据库表的线程处理
	virtual void UnlockProcess(bool bLog=true) = 0;
	//对于数据库在线更新事件等待所有正在访问数据库表的线程处理结束
	virtual void WaitUntilProcessesFinish() = 0;

	//开始加载数据库表的静态信息
	virtual void StartLoadRtdb() = 0;
	//停止加载数据库表的静态信息
	virtual void StopLoadRtdb() = 0;
	//处于等待状态，直到停止加载数据库表静态信息为止
	virtual void WaitUntilStopLoadRtdb() = 0;

	//准备在线更新的数据库表名称集合
	virtual bool PrepareUpdateTableSet(const char* insertTables, const char* editTables) = 0;
	//创建在线更新的数据库表名称集合
	virtual void CreateUpdateTableSet() = 0;
	//是否存在在线更新的数据库表集合
	virtual bool HasUpdateTableSet() = 0;
	//指定的数据库表名称是否需要在线更新
	virtual bool UpdatedTable(const char* curTable) = 0;
	//释放在线更新的数据库表名称集合
	virtual void FreeUpdateTableSet() = 0;
};

#endif
