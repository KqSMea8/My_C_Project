//ipfrcsdao.h

#ifndef _IPFORCASTDAO_SUNRUI_20130528_H_
#define _IPFORCASTDAO_SUNRUI_20130528_H_

#include "../ibasicdao.h"                        // for IBasicDao

#define PFORCASTDAO_CLASSID    "cpfrcsdao"
#define PFORCASTDAO_INTFID     "ipfrcsdao"

class IPForcastDao  : virtual public IBasicDao 
{
public:
	//根据超超短期预测位置获取微电网id
	virtual int GetSMGID(int pos) = 0;
	//根据超超短期预测位置获取启动标志
	virtual bool GetStartFlag(int pos) = 0;
	//根据超超短期预测位置获取功率类型
	virtual int GetPType(int pos) = 0;
	//根据超超短期预测位置获取预测间隔
	virtual int GetSPan(int pos) = 0;
	//根据超超短期预测位置获取预测数据间隔
	virtual int GetDataSPan(int pos) = 0;
	//根据超超短期预测位置获取预测数据集
	virtual bool GetForPData(int pos, double* data) = 0;
	//根据超超短期预测位置设置预测数据集
	virtual bool SetForPData(int pos, double* data) = 0;
	
	//根据超超短期预测位置得到计算表达式
	virtual const char* GetCalculateExpress(int pos) = 0;
	//根据超超短期预测位置获取预测平均值
	virtual double GetForPAverage(int pos) = 0;
	//根据超超短期预测位置设置预测平均值
	virtual bool SetForPAverage(int pos, double dAvg) = 0;

};

#endif
