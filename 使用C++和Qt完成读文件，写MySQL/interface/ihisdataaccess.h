#ifndef _IHISDATAACCESS__H_
#define _IHISDATAACCESS__H_

#include "icsunknown.h"
#include "qiptr.h"

#define MODULE_HISDATAACCESS	"hisdataaccess"
#define IID_IHisDataAccess		"ihisdataaccess"
#define CLSID_HisDataAccess		"hisdataaccess"

#define DATAINDEX_NO_INV_VALUE		"#NOVALUE#"  /* 无 有效值返回  2008/08/26 */
#include <qdatetime.h>
#include <q3valuelist.h>
#include <qmap.h>
#include <qvariant.h>

//模拟量时间序列值
typedef struct tagAnalogPoint
{
	QDateTime time;		//时间
	double value;		//值
	int quality;		//品质
	short origin;		//来源
}AnalogPoint;
typedef Q3ValueList<AnalogPoint>QAnalogSerial;

//状态量时间序列值
typedef struct tagStatusPoint
{
	QDateTime time;		//时间
	int value;			//值
	int faulttrip;		//动作跳闸次数
	short origin;		//来源
}StatusPoint;
typedef Q3ValueList<StatusPoint>QStatusSerial;

//累加量时间序列值
typedef struct tagAccumulatorPoint
{
	QDateTime time;		//时间
	double value;		//值(当前值)
	double amountvalue;	//累计增量
	int quality;		//品质
	short origin;		//来源
}AccumulatorPoint;
typedef Q3ValueList<AccumulatorPoint>QAccumulatorSerial;

//历史告警对象值
typedef struct tagAlarmPoint
{
	int       objid ;		//对象ID
	int       alarmid ;		//报警类型
	QString	  objtype ;		//对象类型
	QDateTime thetime ;		//发生时间
	QString   description ;	//描述
	QString   actuser ;		//执行／确认人
	QDateTime confirmtime ; //确认时间
	QString   objdesc ;		//对象名称
	QString   report ;		//附件报告
}AlarmPoint;
typedef Q3ValueList<AlarmPoint> QAlarmSerial;

//历史对象类型枚举
typedef enum tagOBJTYPE
{
	OT_ANALOG = 0,
	OT_STATUS,
	OT_ACCUMULATOR
}OBJTYPE;

#include "icsmap.h"
#include <q3ptrlist.h>

#define ICSHISACCESS_STEPTYPE_MONTH "-9"
#define ICSHISACCESS_STEPTYPE_XUN   "-8"

//统计属性名称-值映射
//typedef QMap<QString,QVariant>QStatMap;
typedef ICSMap<QString,QVariant> QStatMap;
typedef Q3ValueList<QVariant> valueList;
typedef ICSMap<QString,valueList> QStatValueMap;

typedef QMap<QString,QVariant> QStatValue;
typedef Q3ValueList<QStatValue> QStatObjectList;

//历史数据查询接口
class IHisDataAccess : public IICSUnknown
{
public: 
	//查询模拟量时间序列值
	virtual bool QueryAnalogSerial( int nID,
								const QDateTime& startTime, const QDateTime& endTime, int nMinutes, 
								QAnalogSerial& result ) = 0;

	//查询状态量时间序列值
	virtual bool QueryStatusSerial( int nID,
								const QDateTime& startTime, const QDateTime& endTime, int nMinutes, 
								QStatusSerial& result ) = 0;

	//查询累加量时间序列值
	virtual bool QueryAccumulatorSerial( int nID,
								const QDateTime& startTime, const QDateTime& endTime, int nMinutes, 
								QAccumulatorSerial& result ) = 0;

	//查询全时间统计值
	virtual bool QueryStat( OBJTYPE type, int nID, 
								const QDateTime& startTime, const QDateTime& endTime,
								QStatMap& result ) = 0;

	//查询分时段统计值
	virtual bool QueryPeriodStat( OBJTYPE type, int nID, int nPeriod,
								const QDateTime& startTime, const QDateTime& endTime,
								QStatMap& result ) = 0;

	virtual void AddNullValue(bool bIsAdd = false , double dAddValue = -99999) = 0;

	/* 添加，查询统计量序列值的接口  2008/12/01 */
	//查询模拟量时间序列值
	virtual bool QueryAnalogStatSerial( int nID,
								const QDateTime& startTime, const QDateTime& endTime, int nMinutes, 
								QStringList listStatName, QStatValueMap& result ) = 0;

	

	//查询状态量时间序列值
	virtual bool QueryStatusStatSerial( int nID,
								const QDateTime& startTime, const QDateTime& endTime, int nMinutes, 
								QStringList listStatName,QStatValueMap& result ) = 0;
	

	//查询累加量时间序列值
	virtual bool QueryAccumulatorStatSerial( int nID,
								const QDateTime& startTime, const QDateTime& endTime, int nMinutes, 
								QStringList listStatName,QStatValueMap& result ) = 0;
	
	/* 添加结束  2008/12/01 */

	/* 检索历史告警信息
	@parm	result			符合条件的结果集(一"页"数据)
	@parm   iTotolCountOut  符合条件的所有记录数
	@parm	startTime		发生时间范围－起始。默认为当前时间的前10年
	@parm	endtime			发生时间范围－终止。默认为当前时间

   －－－－－－－－－－－－
   以下为各个过滤选项
   －－－－－－－－－－－－
	@parm	iRecorderFrom	从检索的结果中的指定位置开始返回数据，默认从最开始（第0条）返回
	@parm	iRecorderLen	返回记录的数目，默认每次最多返回 2000 条数据
	@parm	iObjIds			对象ID列表。如果不设ID列表则返回所有ID的数据
	@parm	iAlarmIds		报警类型列表。如果不设则不根据告警类型进行过滤。
	@parm	lObjType		对象类型列表。如果不设则不根据对象类型进行过滤。
	@parm	sDescFilter		描述中包含的字符串。如果不设则不根据描述信息进行过滤。
	@parm	lActUsers		执行人列表。如果不设则不根据执行人信息进行过滤。
	@parm	sObjDescFilter	对象名称中包含的字符串。如果不设则不根据对象名称信息进行过滤。
	@parm	sReportFilter	附件报告中包含的字符串。如果不设则不根据附件报告信息进行过滤。

	@parm	dConfirmTimeFrom	确认时间－起始。如果不设则不根据确认时间进行过滤。
	@parm	dConfirmTimeTo		确认时间－止。如果不设则不根据确认时间进行过滤。
	
	2009/02/13 */
	virtual bool QueryHisAlarm(QAlarmSerial & result ,
		int&			  iTotolCountOut  ,	               
		const QDateTime&  startTime 		= QDateTime::currentDateTime().addMonths(-120), 
		const QDateTime&  endTime			= QDateTime::currentDateTime(),
		int               iRecorderFrom		= 0 ,
		int               iRecorderLen		= 2000 ,
		Q3ValueList<int> * lObjIds			= NULL,
		Q3ValueList<int> * lAlarmIds			= NULL, 
		QStringList *     lObjType			= NULL,
		QString           sDescFilter		= QString(""),
		QStringList *     lActUsers			= NULL,
		QString           sObjDescFilter	= QString(""),
		QString           sReportFilter		= QString(""),
		QDateTime *		  dConfirmTimeFrom	= NULL,
		QDateTime *       dConfirmTimeTo	= NULL		
		) = 0;


	virtual bool QueryStatSerial( OBJTYPE type, int nID,
								const QDateTime& startTime, const QDateTime& endTime, int nMinutes, 
								QStringList listStatName, QStatObjectList& result ) = 0;



public:
    static char* GetIntfName()
    {
        return IID_IHisDataAccess;
    }; 
};

typedef CQIPtr<IHisDataAccess>	HisDataAccess;

/*//模拟量统计属性
char* AnalogStat[][] = {
	//原始存储(仅全时间)
	{"avevalue",	"平均值"},
	{"maxdata",		"最大值"},
	{"maxdatatime",	"最大值时间"},
	{"mindata",		"最小值"},
	{"mindatatime",	"最小值时间"},
	//原始存储(全时间及分时段)
	{"uupercount",	"越上上限次数"},
	{"uupertime",	"越上上限时间"},
	{"uppercount",	"越上限次数"},
	{"uppertime",	"越上限时间"},	
	{"lowercount",	"越下限次数"},	
	{"lowertime",	"越下限时间"},	
	{"llowercount",	"越下下限次数"},
	{"llowertime",	"越下下限时间"},
	{"qualifytime",	"总合格时间"},
	{"totaltime",	"总统计时间"},
	//自动计算(全时间及分时段)
	{"uuperrate",	"越上上限率"},
	{"upperrate",	"越上限率"}, 
	{"lowerrate",	"越下限率"},
	{"llowerrate",	"越下下限率"},
	{"qualifyrate",	"合格率"}
};


//状态量统计属性
char* StatusStat[][] = {
	//原始存储
	{"closecount",	"合次数"},
	{"opencount",	"开次数"},
	{"closetime",	"合时间"},
	{"opentime",	"开时间"},
	{"totalruntime","总运行时间"},
	{"totaltime",	"总统计时间"},
	//自动计算
	{"switchcount",	"变位次数"},
	{"openrate",	"投入率"}, 
	{"closerate",	"切除率"}, 
	{"opencloserate","投切比"}
};

//累加量统计属性
char* PulseStat[][] = { 
	{"amountvalue",	"累加值"}
};*/

#endif 

