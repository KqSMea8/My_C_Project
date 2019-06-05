#ifndef _IHISDATAACCESS__H_
#define _IHISDATAACCESS__H_

#include "icsunknown.h"
#include "qiptr.h"

#define MODULE_HISDATAACCESS	"hisdataaccess"
#define IID_IHisDataAccess		"ihisdataaccess"
#define CLSID_HisDataAccess		"hisdataaccess"

#define DATAINDEX_NO_INV_VALUE		"#NOVALUE#"  /* �� ��Чֵ����  2008/08/26 */
#include <qdatetime.h>
#include <q3valuelist.h>
#include <qmap.h>
#include <qvariant.h>

//ģ����ʱ������ֵ
typedef struct tagAnalogPoint
{
	QDateTime time;		//ʱ��
	double value;		//ֵ
	int quality;		//Ʒ��
	short origin;		//��Դ
}AnalogPoint;
typedef Q3ValueList<AnalogPoint>QAnalogSerial;

//״̬��ʱ������ֵ
typedef struct tagStatusPoint
{
	QDateTime time;		//ʱ��
	int value;			//ֵ
	int faulttrip;		//������բ����
	short origin;		//��Դ
}StatusPoint;
typedef Q3ValueList<StatusPoint>QStatusSerial;

//�ۼ���ʱ������ֵ
typedef struct tagAccumulatorPoint
{
	QDateTime time;		//ʱ��
	double value;		//ֵ(��ǰֵ)
	double amountvalue;	//�ۼ�����
	int quality;		//Ʒ��
	short origin;		//��Դ
}AccumulatorPoint;
typedef Q3ValueList<AccumulatorPoint>QAccumulatorSerial;

//��ʷ�澯����ֵ
typedef struct tagAlarmPoint
{
	int       objid ;		//����ID
	int       alarmid ;		//��������
	QString	  objtype ;		//��������
	QDateTime thetime ;		//����ʱ��
	QString   description ;	//����
	QString   actuser ;		//ִ�У�ȷ����
	QDateTime confirmtime ; //ȷ��ʱ��
	QString   objdesc ;		//��������
	QString   report ;		//��������
}AlarmPoint;
typedef Q3ValueList<AlarmPoint> QAlarmSerial;

//��ʷ��������ö��
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

//ͳ����������-ֵӳ��
//typedef QMap<QString,QVariant>QStatMap;
typedef ICSMap<QString,QVariant> QStatMap;
typedef Q3ValueList<QVariant> valueList;
typedef ICSMap<QString,valueList> QStatValueMap;

typedef QMap<QString,QVariant> QStatValue;
typedef Q3ValueList<QStatValue> QStatObjectList;

//��ʷ���ݲ�ѯ�ӿ�
class IHisDataAccess : public IICSUnknown
{
public: 
	//��ѯģ����ʱ������ֵ
	virtual bool QueryAnalogSerial( int nID,
								const QDateTime& startTime, const QDateTime& endTime, int nMinutes, 
								QAnalogSerial& result ) = 0;

	//��ѯ״̬��ʱ������ֵ
	virtual bool QueryStatusSerial( int nID,
								const QDateTime& startTime, const QDateTime& endTime, int nMinutes, 
								QStatusSerial& result ) = 0;

	//��ѯ�ۼ���ʱ������ֵ
	virtual bool QueryAccumulatorSerial( int nID,
								const QDateTime& startTime, const QDateTime& endTime, int nMinutes, 
								QAccumulatorSerial& result ) = 0;

	//��ѯȫʱ��ͳ��ֵ
	virtual bool QueryStat( OBJTYPE type, int nID, 
								const QDateTime& startTime, const QDateTime& endTime,
								QStatMap& result ) = 0;

	//��ѯ��ʱ��ͳ��ֵ
	virtual bool QueryPeriodStat( OBJTYPE type, int nID, int nPeriod,
								const QDateTime& startTime, const QDateTime& endTime,
								QStatMap& result ) = 0;

	virtual void AddNullValue(bool bIsAdd = false , double dAddValue = -99999) = 0;

	/* ��ӣ���ѯͳ��������ֵ�Ľӿ�  2008/12/01 */
	//��ѯģ����ʱ������ֵ
	virtual bool QueryAnalogStatSerial( int nID,
								const QDateTime& startTime, const QDateTime& endTime, int nMinutes, 
								QStringList listStatName, QStatValueMap& result ) = 0;

	

	//��ѯ״̬��ʱ������ֵ
	virtual bool QueryStatusStatSerial( int nID,
								const QDateTime& startTime, const QDateTime& endTime, int nMinutes, 
								QStringList listStatName,QStatValueMap& result ) = 0;
	

	//��ѯ�ۼ���ʱ������ֵ
	virtual bool QueryAccumulatorStatSerial( int nID,
								const QDateTime& startTime, const QDateTime& endTime, int nMinutes, 
								QStringList listStatName,QStatValueMap& result ) = 0;
	
	/* ��ӽ���  2008/12/01 */

	/* ������ʷ�澯��Ϣ
	@parm	result			���������Ľ����(һ"ҳ"����)
	@parm   iTotolCountOut  �������������м�¼��
	@parm	startTime		����ʱ�䷶Χ����ʼ��Ĭ��Ϊ��ǰʱ���ǰ10��
	@parm	endtime			����ʱ�䷶Χ����ֹ��Ĭ��Ϊ��ǰʱ��

   ������������������������
   ����Ϊ��������ѡ��
   ������������������������
	@parm	iRecorderFrom	�Ӽ����Ľ���е�ָ��λ�ÿ�ʼ�������ݣ�Ĭ�ϴ��ʼ����0��������
	@parm	iRecorderLen	���ؼ�¼����Ŀ��Ĭ��ÿ����෵�� 2000 ������
	@parm	iObjIds			����ID�б��������ID�б��򷵻�����ID������
	@parm	iAlarmIds		���������б���������򲻸��ݸ澯���ͽ��й��ˡ�
	@parm	lObjType		���������б���������򲻸��ݶ������ͽ��й��ˡ�
	@parm	sDescFilter		�����а������ַ�������������򲻸���������Ϣ���й��ˡ�
	@parm	lActUsers		ִ�����б���������򲻸���ִ������Ϣ���й��ˡ�
	@parm	sObjDescFilter	���������а������ַ�������������򲻸��ݶ���������Ϣ���й��ˡ�
	@parm	sReportFilter	���������а������ַ�������������򲻸��ݸ���������Ϣ���й��ˡ�

	@parm	dConfirmTimeFrom	ȷ��ʱ�䣭��ʼ����������򲻸���ȷ��ʱ����й��ˡ�
	@parm	dConfirmTimeTo		ȷ��ʱ�䣭ֹ����������򲻸���ȷ��ʱ����й��ˡ�
	
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

/*//ģ����ͳ������
char* AnalogStat[][] = {
	//ԭʼ�洢(��ȫʱ��)
	{"avevalue",	"ƽ��ֵ"},
	{"maxdata",		"���ֵ"},
	{"maxdatatime",	"���ֵʱ��"},
	{"mindata",		"��Сֵ"},
	{"mindatatime",	"��Сֵʱ��"},
	//ԭʼ�洢(ȫʱ�估��ʱ��)
	{"uupercount",	"Խ�����޴���"},
	{"uupertime",	"Խ������ʱ��"},
	{"uppercount",	"Խ���޴���"},
	{"uppertime",	"Խ����ʱ��"},	
	{"lowercount",	"Խ���޴���"},	
	{"lowertime",	"Խ����ʱ��"},	
	{"llowercount",	"Խ�����޴���"},
	{"llowertime",	"Խ������ʱ��"},
	{"qualifytime",	"�ܺϸ�ʱ��"},
	{"totaltime",	"��ͳ��ʱ��"},
	//�Զ�����(ȫʱ�估��ʱ��)
	{"uuperrate",	"Խ��������"},
	{"upperrate",	"Խ������"}, 
	{"lowerrate",	"Խ������"},
	{"llowerrate",	"Խ��������"},
	{"qualifyrate",	"�ϸ���"}
};


//״̬��ͳ������
char* StatusStat[][] = {
	//ԭʼ�洢
	{"closecount",	"�ϴ���"},
	{"opencount",	"������"},
	{"closetime",	"��ʱ��"},
	{"opentime",	"��ʱ��"},
	{"totalruntime","������ʱ��"},
	{"totaltime",	"��ͳ��ʱ��"},
	//�Զ�����
	{"switchcount",	"��λ����"},
	{"openrate",	"Ͷ����"}, 
	{"closerate",	"�г���"}, 
	{"opencloserate","Ͷ�б�"}
};

//�ۼ���ͳ������
char* PulseStat[][] = { 
	{"amountvalue",	"�ۼ�ֵ"}
};*/

#endif 

