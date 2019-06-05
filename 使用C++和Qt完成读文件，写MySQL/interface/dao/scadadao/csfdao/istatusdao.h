//istatusdao.h

#ifndef _ISTATUSDAO_PENGSHIKANG_20081204_H_
#define _ISTATUSDAO_PENGSHIKANG_20081204_H_

#include "irawdao.h"                             // for IRawDao
#include "icsfalmintf.h"                         // for ICsfAlarmIntf
#include <qmap.h>

#define STATUSDAO_CLASSID    "cstatusdao"
#define STATUSDAO_INTFID     "istatusdao"

//�����ң������������
//#define ISSWITCHSTATE         20101 //����״̬
#define ISFAULTSIGN           20202 //�¹����ź�
#define ISALARMSIGN           20203 //Ԥ�����ź�
#define ISSOESIGN             80101 //SOE�ź�

class IStatusDao : virtual public IRawDao, virtual public ICsfAlarmIntf
{
public:	
	//����״̬��������
	virtual void SetStatusDiscord(int pos) = 0;//����˫λ��״̬����һ��Ʒ������
	virtual void SetStatisticCount(int pos, int nChangeNum, int nAccidNum) = 0;//״̬����λ���¹���բͳ�ƴ���
	virtual void SetStatusBadValue(int pos, CAPP_SDO_Status* pObject, int curQualt, int surgeNum, bool writPrevValu) = 0;
	virtual void SetStatusGoodValue(int pos, CAPP_SDO_Status* pObject, int curQualt, int curValue, int nChangeNum, int nAccidNum, bool& hasGzMsg) = 0;
	
	//��ȡ��ʱ����״̬������
	virtual int GetWaitStatusCount() = 0;
	//����ID��ȡ״̬������ʱ�����б��е�λ��
	virtual int GetWaitStatusPos(int nObjId) = 0;
	//�����ʱ����״̬����ַ����
	virtual void OutputWaitPtrList(QMap<int, int>& waitPosById) = 0;

	//����ͨѶ�ɼ�����ԴID�õ��¹����ź�״̬���͡�psk-20140514:�޸ķ�������
	virtual STATUSTYPE GetFaultSignValueOfSrcId(int nSrcId) = 0;
	//����ͨѶ�ɼ�����ԴID����¹����ź�״ֵ̬
	virtual void ClearFaultSignValueOfSrcId(int nSrcId) = 0;
	//����ͨѶ�ɼ�����ԴID�õ�Ԥ�����ź�״̬���͡�psk-20140514:�޸ķ�������
	virtual STATUSTYPE GetAlarmSignValueOfSrcId(int nSrcId) = 0;
	//����ͨѶ�ɼ�����ԴID���Ԥ�����ź�״ֵ̬
	virtual void ClearAlarmSignValueOfSrcId(int nSrcId) = 0;

	//����״̬��λ�õõ��ɼ�ʱ��
	virtual double GetRawTime(int pos) = 0;

	//����״̬��λ�õõ������־
	virtual int GetProcessFlag(int pos) = 0;
	//����״̬��λ�õõ��ӳٱ���ʱ��
	virtual int GetDelayTime(int pos) = 0;
	
	//����״̬��λ�õõ��ϴ�ֵ
	virtual int GetLastValue(int pos) = 0;
	//����״̬��λ�õõ��ϴ�ֵʱ��
	virtual double GetLastTime(int pos) = 0;
	//����״̬��λ�������ϴ�ֵ��ʱ��
	virtual void WriteLastValueAndTime(int pos) = 0;
	
	//����״̬��λ�õõ�����״̬
	virtual int GetGZState(int pos) = 0;
	//����״̬��λ�����ù���״̬
	virtual bool SetGZState(int pos, int nValue) = 0;
	
	//����״̬��λ�õõ��񵴴���
	virtual int GetSurgeTimes(int pos) = 0;
	//����״̬��λ�������񵴴���
	virtual bool SetSurgeTimes(int pos, int nValue) = 0;
	
	//����״̬��λ�õõ��ƴα�������ͳ��
	virtual int GetChangeCount(int pos) = 0;
	//����״̬��λ�����üƴα�������ͳ��
	virtual bool SetChangeCount(int pos, int nValue) = 0;
	
	//����״̬��λ�õõ��¹���բ����ͳ��
	virtual int GetFaultCount(int pos) = 0;
	//����״̬��λ�������¹���բ����ͳ��
	virtual bool SetFaultCount(int pos, int nValue) = 0;
	
	//����״̬��λ�õõ��ƴα���������ֵ
	virtual int GetChangeCountMax(int pos) = 0;
	//����״̬��λ�õõ��ƴγ��޸澯����
	virtual int GetChangeAlarmAct(int pos) = 0;
	
	//����״̬��λ�õõ��¹���բ������ֵ
	virtual int GetFaultCountMax(int pos) = 0;
	//����״̬��λ�õõ��¹ʴ������޸澯����
	virtual int GetFaultAlarmAct(int pos) = 0;
	
	//����״̬��λ�õõ����鳬ʱ�澯ʱ��
	virtual int GetRevertTimeLimit(int pos) = 0;
	//����״̬��λ�õõ����鳬ʱ�澯����
	virtual int GetRevertAlarmAct(int pos) = 0;
	
	//����״̬��λ�õõ���ǰ����ֵ
	virtual int GetCalValue(int pos) = 0;
	//����״̬��ID�õ���ǰ����ֵ
	virtual int GetCalValueById(int id, bool* ok=0) = 0;
	
	//����״̬��λ�õõ���ǰ״̬���͡�psk-20140514:���
	virtual STATUSTYPE GetStateType(int pos) = 0;
	//����״̬��ID�õ���ǰ״̬���͡�
	virtual STATUSTYPE GetStateTypeById(int id, bool bRequery=false) = 0;

	virtual bool ExistBayFault(int bayId) = 0;
	virtual bool ExistBayAlarm(int bayId) = 0;
	virtual bool ExistBayGzState(int bayId) = 0;
	virtual bool ExistStationFault(int facId) = 0;
	virtual bool ExistStationAlarm(int facId) = 0;
	virtual bool ExistStationGzState(int facId) = 0;

	//����ң��λ�ö�ȡͳ�ƴ洢���ڣ�������ʷ�洢��
	virtual int GetSaveTimerID(int pos) = 0;
};

#endif
