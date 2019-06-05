//ianalogdao.h

#ifndef _IANALOGDAO_PENGSHIKANG_20081202_H_
#define _IANALOGDAO_PENGSHIKANG_20081202_H_

#include "irawdao.h"                             // for IRawDao
#include "icsfalmintf.h"                         // for ICsfAlarmIntf

#define ANALOGDAO_CLASSID    "canalogdao"
#define ANALOGDAO_INTFID     "ianalogldao"

class IAnalogDao : virtual public IRawDao, virtual public ICsfAlarmIntf
{
public:	
	//����ģ�����Ĳ���ֵ��Ʒ������
	virtual void SetAnalogValue(int nAnlgPos, int nSrcId, int nPntId, 
								double curTime, double rawValue, int curQualt) = 0;
	//����ģ����������
	virtual void SetAnalogValue(int nAnlgPos, int nSrcId, int nPntId, 
								double curTime, double rawValue, double calValue, int curQualt) = 0;
	
	//����ģ����λ�õõ�������λ
	virtual int GetMeasUnit(int pos) = 0;
	//����ģ����λ�õõ������־
	virtual int GetProcessFlag(int pos) = 0;
	//����ģ����λ�õõ���ϵ��
	virtual double GetScaleFactor(int pos) = 0;
	//����ģ����λ�õõ���ϵ��
	virtual double GetOffset(int pos) = 0;
	//����ģ����λ�õõ���Ư����ֵ
	virtual double GetZeroDb(int pos) = 0;

	//����ģ����λ�õõ��仯����ֵ(%)
	virtual double GetDiffDb(int pos) = 0;
	//����ģ����λ�õõ���������ʱ������ֵ
	virtual int GetOlddataTimeLmt(int pos) = 0;
	
	//����ģ����λ�õõ�������������
	virtual double GetMaxValue(int pos) = 0;
	//����ģ����λ�õõ�������������
	virtual double GetMinValue(int pos) = 0;
	//�жϵ�ǰֵ�Ƿ�Ϊ����ֵ
	virtual bool IsNormalValue(int pos, double curVal) = 0;
	
	//����ģ����λ�õõ��ϸ�����ֵ
	virtual double GetQualifyUpperValue(int pos) = 0;
	//����ģ����λ�õõ��ϸ�����ֵ
	virtual double GetQualifyLowerValue(int pos) = 0;
	//�жϵ�ǰֵ�Ƿ�Ϊ�ϸ�ֵ
	virtual bool IsQualifyValue(int pos, double curVal) = 0;

	//����ģ����λ�õõ��Ƿ������ֵ����
	virtual int GetUseLimitTypeFlag(int pos) = 0;
	//����ģ����λ�õõ�Խ������ID
	virtual int GetLimitType(int pos) = 0;
	//����ģ����λ�õõ���������ID
	virtual int GetAbruptType(int pos) = 0;
	//����ģ����λ�õõ�Խ�ޱ����ӳ�ʱ��
	virtual int GetDelayTime(int pos) = 0;
	//����ģ����λ�õõ�Խ�޻ָ�����
	virtual double GetDeadZone(int pos) = 0;
	//����ģ����λ�õõ�Խ�ޱ���������ֵ
	virtual double GetUpperValue(int pos) = 0;
	//����ģ����λ�õõ�Խ�ޱ���������ֵ
	virtual double GetLowerValue(int pos) = 0;
	//����ģ����λ�õõ�Խ���޸澯��������
	virtual int GetUpperAct(int pos) = 0;
	//����ģ����λ�õõ�Խ���޸澯��������
	virtual int GetLowerAct(int pos) = 0;

	//����ģ����λ�õõ�����ֵԽ��״̬
	virtual int GetAlarmState(int pos) = 0;
	//����ģ����λ����������ֵԽ��״̬
	virtual bool SetAlarmState(int pos, int nValue) = 0;
	
	//����ģ����λ�õõ�����ֵ����״̬
	virtual int GetAbruptState(int pos) = 0;
	//����ģ����λ����������ֵ����״̬
	virtual bool SetAbruptState(int pos, int nValue) = 0;
	
	//����ģ����λ�õõ�Խ��ʱ����
	virtual int GetExcepTime(int pos, bool isUULL=false) = 0;
	//����ģ����λ������Խ��ʱ����
	virtual bool SetExcepTime(int pos, int nValue, bool isUULL=false) = 0;
	//����ģ����λ���ۼ�Խ��ʱ����
	virtual int AddExcepTime(int pos, int nValue, bool isUULL=false) = 0;
	
	//����ģ����λ�õõ����ݲ���ʱ����
	virtual int GetUnchangeTime(int pos) = 0;
	//����ģ����λ���������ݲ���ʱ����
	virtual bool SetUnchangeTime(int pos, int nValue) = 0;
	//����ģ����λ���ۼ����ݲ���ʱ����
	virtual void AddUnchangeTime(int pos, int nValue) = 0;
	
	//����ģ����λ�õõ�����ʱ����
	virtual int GetAbruptTime(int pos) = 0;
	//����ģ����λ����������ʱ����
	virtual bool SetAbruptTime(int pos, int nValue) = 0;
	//����ģ����λ���ۼ�����ʱ����
	virtual void AddAbruptTime(int pos, int nValue) = 0;
	
	//����ģ����λ�õõ�����ֵ
	virtual double GetCalValue(int pos) = 0;
	//����ģ����ID�õ�����ֵ
	virtual double GetCalValueById(int id, bool* ok=0) = 0;

	//����ģ����λ������Խ�ޱ���״̬
	virtual void SetAlarmStateInfo(int pos, int nAlmState, int nExcpTime1, int nExcpTime2) = 0;
	//����ģ����λ��������Խ�ޱ���״̬
	virtual void SetNormalStateInfo(int pos) = 0;

	virtual bool TestControlChange(int id, float incValue, float* rsltValue=0) = 0;	

	//����ģ����λ�õõ�˫������澯��ֵ
	virtual double GetMaxRawOffset(int pos) = 0;
};

#endif
