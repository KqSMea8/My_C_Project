//istatusvaldao.h

#ifndef _ISTATUSVALUETYPEDAO_PENGSHIKANG_20081204_H_
#define _ISTATUSVALUETYPEDAO_PENGSHIKANG_20081204_H_

#include "../ibasicdao.h"                        // for IBasicDao
#include "../../../interface/scadasrv/scadadatadef.h"// for STATUSTYPE

#define STATUSVALDAO_CLASSID    "cstatusvaldao"
#define STATUSVALDAO_INTFID     "istatusvaldao"

class IStatusValDao : virtual public IBasicDao
{
public:
	//�Ƿ�Ϊ����ң��������ʶ��ң�����͵�ģʽ
	virtual bool IsStatusCodeMode() = 0;

	//���ݲ�������ͺ�״̬��ֵ�õ�״̬��ֵ���ͼ�¼λ��
	virtual int GetPositionByStateValue(int nMeasType, int nValue) = 0;
	//���ݲ�������ͺ�״̬���͵õ�״̬��ֵ���ͼ�¼λ��
	virtual int GetPositionByStateType(int nMeasType, STATUSTYPE nStatType) = 0;
	
	//���ݲ�������ͺ�״̬��ֵ�õ�״̬����
	virtual STATUSTYPE GetStateTypeByStateValue(int nMeasType, int nValue) = 0;
	//���ݲ�������ͺ�״̬��ֵ�õ�״̬��������
	virtual void GetStateDescByStateValue(int nMeasType, int nValue, char* sValDesc) = 0;
	//���ݲ�������ͺ�״̬���͵õ�״̬��ֵ
	virtual int GetValueByStateType(int nMeasType, STATUSTYPE nStatType, bool& bOk) = 0;
	
	//����״̬��ֵ����λ�ö�ȡ״ֵ̬
	virtual int GetStateValue(int pos) = 0;
	//����״̬��ֵ����λ�ö�ȡ״̬����
	virtual STATUSTYPE GetStateType(int pos) = 0;
	//����״̬��ֵ����λ�ö�ȡ״̬��������
	virtual const char* GetStateDesc(int pos) = 0;
	
	//����״̬��ֵ����λ�ö�ȡ�¹ʱ�λ����ID
	virtual int GetFaultAlarmID(int pos) = 0;
	//����״̬��ֵ����λ�ö�ȡ������λ����ID
	virtual int GetCtrlAlarmID(int pos) = 0;

	//���ݲ�������Ͷ�ȡ״̬����
	virtual STATUSTYPE GetStateTypeByMeasType(int nMeasType) = 0;
	//���ݲ���������ж��Ƿ�Ϊ����Ͷ��״̬������
	virtual bool IsSwitchMeasType(int nMeasType) = 0;
	//���ݲ���������ж��Ƿ�Ϊ�¹��ź�״̬������
	virtual bool IsFaultMeasType(int nMeasType) = 0;
	//���ݲ���������ж��Ƿ�ΪԤ���ź�״̬������
	virtual bool IsAlarmMeasType(int nMeasType) = 0;
};

#endif
