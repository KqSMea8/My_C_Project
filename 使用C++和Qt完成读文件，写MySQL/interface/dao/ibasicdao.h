//ibasicdao.h

#ifndef _IBASICDAO_PENGSHIKANG_20100802_H_
#define _IBASICDAO_PENGSHIKANG_20100802_H_

#include "../icsunknown.h"

#define SCADADAO_MODULE    "scadadao"
#define SMGDAO_MODULE      "smgdao"
#define STRGDAO_MODULE     "strgdao"

class IBasicDao : virtual public IICSUnknown
{
public:
	//访问全表字段信息的加锁与解锁
	virtual void Lock() = 0;//访问全表字段信息前加锁
	virtual void Unlock() = 0;//访问全表字段信息后解锁

	//得到数据表名称
	virtual const char* GetTableName() = 0;
	//得到数据表记录对象个数
	virtual int GetObjectCount() = 0;
	
	//初始化数据表字段索引集
	virtual void GetFieldIndexs() = 0;
	//读取数据表的静态信息
	//virtual void ReadStaticInfo() = 0;
	virtual void ReadStaticInfo(int fldNum=0, const char nameList[][64]=0, const char* strFilter="DELETEFLAG==0", bool onlyRead=false) = 0;

	//读取数据表的动态信息
	virtual void ReadDynamicInfo() = 0;
	//将数据表的动态信息写入库中
	virtual void WriteDynamicInfo() = 0;

	//根据数据表记录ID得到记录位置
	virtual int GetPositionByID(int nId, bool bRequery=false) = 0;
	//根据数据表记录位置得到记录ID
	virtual int GetIdentifierByPos(int nPos) = 0;

	//根据数据表记录位置得到该记录对象的名称
	virtual const char* GetName(int nPos) = 0;
	//根据数据表记录位置判断该记录是否已被删除
	virtual bool IsDeleted(int nPos) = 0;

	//根据查询条件获得记录ID集合
	//注意：指针idSet在外部不要分配内存，它在接口函数内采用new[]操作分配内存，
	//      它的释放在外部由用户采用delete[]操作完成。
	virtual int FindObjectsByFilter(int& count, int*& idSet, const char* strFilter, bool onlyRead=true, int fldCount=0, const char fldList[][64]=0) = 0;

protected:
	//得到名称索引
	virtual int GetIndex_Name() = 0;
	//使用名称索引
	virtual int UseIndex_Name() = 0;
	//得到删除标志索引
	virtual int GetIndex_DeleteFlag() = 0;
	//使用删除标志索引
	virtual int UseIndex_DeleteFlag() = 0;
	//读取基本的字段信息
	virtual void LoadBaseField() = 0;
	//将字段名称集转换为合法的字段索引集
	virtual bool GetFieldIndexsByNames(int inCount, const char nameList[][64], int& outCount, int*& indexList) = 0;

public:
	//给数据库设置事务处理
	virtual bool BeginTransaction() = 0;
	//结束数据库的事务处理（自动提交或回滚）。
	//对该数据库的所有数据访问操作均正确完成时提交，否则回滚。
	virtual bool EndTransaction(char* strInfo=0) = 0;
};

#endif
