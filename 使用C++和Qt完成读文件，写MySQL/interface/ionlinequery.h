// ionlinequery.h
#ifndef _IONLINEQUERY_H_
#define _IONLINEQUERY_H_

#include "icsunknown.h" // for IICSUnknown

#define DLL_ONLINEQUERY	"onlinequery"
#define IID_ONLINEQUERY	"IOnlinequery"
#define CID_ONLINEQUERY	"COnlinequery"


class IOnlineQuery: public IICSUnknown
{
public:

	/*
	failureData 异常数据浏览
	输入参数：
	返回参数：
	*/
	virtual void failureData() = 0; 

	/*
	unalarm  报警抑制查询
	输入参数：
	返回参数：
	*/
	virtual void unalarm() = 0; 

	/*
	equipTag 挂牌设备浏览
	输入参数：
	返回参数：
	*/
	virtual void equipTag() = 0;

	/*
	overrun 今日越限
	输入参数：analogID 遥测ID
	返回参数：
	*/
 	virtual void overrun(int analogID) = 0; 

	/*
	statusChange 今日变位
	输入参数：statusID  遥信ID
	返回参数：
	*/
	virtual void statusChange(int statusID) = 0; 

	/*
	statusCtrl 今日控制
	输入参数：controlID  遥控ID
	返回参数：
	*/
	virtual void statusCtrl(int controlID) = 0; 

};

#endif
