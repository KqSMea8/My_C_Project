//ibaseinfo.h

#ifndef _IBASEINFO_PENGSHIKANG_20130315_H_
#define _IBASEINFO_PENGSHIKANG_20130315_H_

class IGaiaTable;

class IBaseInfo
{
public:
	virtual void LockWrite() = 0;//动态字段信息加锁
	virtual void UnlockWrite() = 0;//动态字段信息解锁
	virtual void LockRead() = 0;//静态字段信息加锁
	virtual void UnlockRead() = 0;//静态字段信息解锁
	virtual void LockUpdate() = 0;//数据正在处理加锁
	virtual void UnlockUpdate() = 0;//数据正在处理解锁
	virtual void Lock() = 0;
	virtual void Unlock() = 0;
	
	//得到数据表名称
	virtual const char* GetTableName() = 0;
	virtual IGaiaTable*& GetTableEntity() = 0;
	
	//根据数据表记录位置得到布尔型的只读字段值
	virtual bool GetBoolReadableFieldValue(int pos, int index, bool bDefault=false) = 0;
	//根据数据表记录位置得到布尔型的可写字段值
	virtual bool GetBoolWritableFieldValue(int pos, int index, bool bDefault=false) = 0;
	//根据数据表记录位置得到整数型的只读字段值
	virtual int GetIntReadableFieldValue(int pos, int index, int nDefault=0) = 0;
	//根据数据表记录位置得到整数型的可写字段值
	virtual int GetIntWritableFieldValue(int pos, int index, int nDefault=0) = 0;
	//根据数据表记录位置得到实数型的只读字段值
	virtual double GetDoubleReadableFieldValue(int pos, int index, double dDefault=0.0) = 0;
	//根据数据表记录位置得到实数型的可写字段值
	virtual double GetDoubleWritableFieldValue(int pos, int index, double dDefault=0.0) = 0;
};

#endif
