//iequipmentdao.h

#ifndef _IEQUIPMENTDAO_PENGSHIKANG_20081203_H_
#define _IEQUIPMENTDAO_PENGSHIKANG_20081203_H_

#include "../ibasicdao.h"                        // for IBasicDao

#define EQUIPDAO_CLASSID    "cequipdao"
#define EQUIPDAO_INTFID     "iequipdao"

class ITagTypeDao;
class IVoltageDao;
class IAnalogDao;
class IStatusDao;

class IEquipDao : virtual public IBasicDao
{
public:
	//���ù�������ʵ�����
	virtual void SetTagTypeDao(ITagTypeDao* pTagType) = 0;
	//���õ�ѹ�ȼ�ʵ�����
	virtual void SetVoltageDao(IVoltageDao* pVoltage) = 0;
	//����ģ����ʵ�����
	virtual void SetAnalogDao(IAnalogDao* pAnalog) = 0;

	//�����豸λ�õõ�����
	virtual const char* GetDescription(int pos) = 0;
	//�����豸λ�õõ����ID
	virtual int GetBayId(int pos) = 0;
	//�����豸λ�õõ���վID
	virtual int GetStationId(int pos) = 0;
	//�����豸λ���жϸ��豸�Ƿ��й���
	virtual bool HasFault(int pos) = 0;

	//�����豸ID�õ��豸�������
	virtual int GetEquipClassByID(int id) = 0;
	//�����豸λ�õõ��豸�������
	virtual int GetEquipClass(int pos) = 0;
	//�����豸ID�õ��豸���ͱ���
	virtual int GetTypeCodeByID(int id) = 0;
	//�����豸λ�õõ��豸���ͱ���
	virtual int GetTypeCode(int pos) = 0;
	//�����豸ID�õ���ѹ�ȼ�ID
	virtual int GetVoltageGradeByID(int id) = 0;
	//�����豸λ�õõ���ѹ�ȼ�ID
	virtual int GetVoltageGrade(int pos) = 0;
	//�����豸ID�õ����ѹ
	virtual double GetBaseVoltageByID(int id) = 0;
	//�����豸λ�õõ����ѹ
	virtual double GetBaseVoltage(int pos) = 0;
	//�����豸λ���жϵ�ѹ״̬�Ƿ�����
	virtual bool IsNormalVoltage(int pos) = 0;
	//�����豸λ���ж��豸�Ƿ����
	virtual bool IsActive(int pos) = 0;

	//�����豸λ���ж��豸�Ƿ��ڹ���״̬
	virtual bool IsTag(int pos) = 0;
	//�����豸ID�ж��豸�Ƿ��ڹ���״̬
	virtual bool IsTagByID(int id) = 0;
	//�����豸λ���ж��豸�Ƿ�ұ�����״̬
	virtual bool IsLockTag(int pos, char* tagName=0) = 0;
	//�����豸λ�������豸�Ƿ��ڹ���״̬
	virtual bool SetTagFlag(int pos, int isTag) = 0;

	//�����豸λ�õõ���������ID
	virtual int GetTagTypeId(int pos) = 0;
	//�����豸λ�����ù�������ID
	virtual bool SetTagTypeId(int pos, int tagTypId) = 0;

	//�����豸λ�û�ȡ�豸�Ĺ�����Ϣ
	virtual bool GetTagInfo(int pos, bool& isTag, int& tagTypId, char* tagOper, double& tagTime) = 0;
	//�����豸λ�������豸�Ĺ�����Ϣ
	virtual bool SetTagInfo(int pos, bool isTag, int tagTypId, const char* tagOper, double tagTime) = 0;

	//�����豸λ�õõ�������־
	virtual int GetLockFlag(int pos) = 0;
	//�����豸λ�����ñ�����־
	virtual bool SetLockFlag(int pos, int lockFlag) = 0;

	//�����豸ID�õ��Ƿ���˫λ���豸��˫λ���豸�仯�ӳ�ʱ��
	virtual bool IsDoubleStatusByID(int id, int& nDelayTime) = 0;
	//�����豸λ���ж��豸�Ƿ���˫λ���豸
	virtual bool IsDoubleStatus(int pos) = 0;
	//�����豸λ�õõ�˫λ���豸�仯�ӳ�ʱ��
	virtual int GetDpsDelayTime(int pos) = 0;

	//����豸�Ŀ���״̬��IDֵ
	virtual void ClearStatusPos() = 0;
	
	//�����豸λ�������豸�Ŀ���״̬��ID
	virtual bool SetStatusPos(int pos, int nStatusPos) = 0;
	//�����豸λ�õõ��豸�Ŀ���״̬��ID
	virtual bool GetStatusPos(int pos, int& nStatusPos1, int& nStatusPos2) = 0;

	//�����豸ID�����豸�Ŀ���״̬��ID
	virtual bool SetStatusPosByEquipID(int id, int nStatusPos) = 0;
	//�����豸λ�õõ��豸�Ŀ���״̬��ID
	virtual bool GetStatusPosByEquipID(int id, int& nStatusPos1, int& nStatusPos2) = 0;

	//�����豸λ�õõ�����ϵͳ��ʽ
	virtual int GetJoinType(int pos) = 0;
	//�����豸λ�õõ��ϼ��豸ID
	virtual int GetSupperEquipId(int pos) = 0;
	//�����豸λ�õõ��ϼ��豸λ��
	virtual int GetSupperEquipPos(int pos) = 0;
	//�����豸λ�õõ��豸���Ʊ������ʽ
	virtual const char* GetLockControlExpr(int pos) = 0;
	//�����豸λ�õõ�����ֵ�Ƿ�������ͳ��
	virtual int GetStatFlag(int pos) = 0;
	//�����豸λ���ж��豸�Ƿ�������Ʋ���
	virtual int DisabledControl(int pos) = 0;
	//�����豸λ�������豸�Ƿ�������Ʋ���
	virtual bool SetLockControl(int pos, int isLockCtrl) = 0;

	//�����豸λ���ж��豸�Ƿ��ڻ��
	virtual bool InActiveIsland(int pos) = 0;
	//�����豸λ�õõ��������˵�ID
	virtual int GetIslandId(int pos) = 0;
	//�����豸λ�õõ��������˻ID
	virtual int GetActiveIslandId(int pos) = 0;

	//�����豸λ�õõ��豸�¹ʱ�־
	virtual int GetFaultFlag(int pos) = 0;
	//�����豸λ�õõ��豸�¹�����
	virtual int GetFaultType(int pos) = 0;
	//�����豸λ�õõ��豸�¹ʲ��ID
	virtual int GetFaultPointId(int pos) = 0;
	//�����豸λ�õõ��豸�¹ʷ���ʱ��
	virtual double GetFaultTime(int pos) = 0;
	//�����豸λ�������豸�¹���Ϣ
	virtual bool SetFaultInfo(int pos, int faultType, int faultPntId, double faultTime) = 0;
	//�����豸λ��ȷ���豸�¹���Ϣ
	virtual bool AckFaultInfo(int pos) = 0;
	//�����豸λ�������豸�¹���Ϣ
	virtual bool UnflickerFaultInfo(int pos, int faultType) = 0;

	//�Ƿ������˵�ѹң��ID
	virtual bool HasVoltageAnalog() = 0;
	//�����豸λ�õõ���ѹң��ID
	virtual int GetVoltageAnalogId(int pos) = 0;
	//�����豸λ�õõ�Ƶ��ң��ID
	virtual int GetFrequencyAnalogId(int pos) = 0;

	//��ȡ�豸������˶�̬��Ϣ
	virtual void ReadTopoDynamicInfo() = 0;
	//�����豸λ���ж��豸�Ƿ��ܿ���[δ�й��ϱ�־]
	virtual bool CanControl(int pos) = 0;

	//�����豸λ�õõ���ѹ�ϸ�״̬��-3--ʧѹ��-2--Խ�������ޣ�-1--Խ���ޣ�0--�ϸ�1--Խ���ޣ�2--Խ�������ޡ�
	virtual int GetEquipUState(int pos) = 0;
	//�����豸ID�õ��������ѹֵ��
	virtual double GetVoltageByEquipID(int id) = 0;

	//�����豸λ�õõ��豸ͨ��״̬ID
	virtual int GetNetStateId(int id) = 0;
	//�����豸λ�õõ��豸��ǰͨ��״̬
	virtual int GetNetState(int id) = 0;
	//����ң����ʵ�����
	virtual void SetStatusDao(IStatusDao* pStatus) = 0;
};

#endif
