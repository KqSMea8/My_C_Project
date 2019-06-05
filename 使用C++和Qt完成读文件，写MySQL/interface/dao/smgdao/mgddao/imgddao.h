//imgddao.h

#ifndef _IMGDDAO_PENGSHIKANG_20100921_H_
#define _IMGDDAO_PENGSHIKANG_20100921_H_

#include "../../ibasicdao.h"                     // for IBasicDao
#include "../../../smgsrv/smgdatadef.h"          // for MicgridObectInfo��BusDeviceInfo

#define MGDDAO_CLASSID    "cmgddao"
#define MGDDAO_INTFID     "imgddao"

class ICommSrcDao;
class IEquipDao;
class IAnalogDao;
class IStatusDao;
class IAccumuDao;
class IControlDao;
class ISMicgridDao;
class IBusDao;
class IMGLineDao;
class ITransformerDao;

struct MgdOuterObject
{
	ICommSrcDao*& _pCommSrc;
	IEquipDao*& _pEquip;//����Ϊ�գ�NULL��
	IAnalogDao*& _pAnalog;//����Ϊ�գ�NULL��
	IStatusDao*& _pStatus;//����Ϊ�գ�NULL��
	IAccumuDao*& _pAccumul;//����Ϊ�գ�NULL��
	IControlDao*& _pControl;//����Ϊ�գ�NULL��
	ISMicgridDao*& _pSMicgrid;//����Ϊ�գ�NULL��
	IBusDao*& _pBus;
	IMGLineDao*& _pMGLine;
	ITransformerDao*& _pTransformer;
	MgdOuterObject(ICommSrcDao*& pCommSrc, IEquipDao*& pEquip, IAnalogDao*& pAnalog, IStatusDao*& pStatus, IAccumuDao*& pAccumul, IControlDao*& pControl, 
		ISMicgridDao*& pSMicgrid, IBusDao*& pBus, IMGLineDao*& pMGLine, ITransformerDao*& pTransformer) 
		: _pCommSrc(pCommSrc), _pEquip(pEquip), _pAnalog(pAnalog), _pStatus(pStatus), _pAccumul(pAccumul), _pControl(pControl), 
		  _pSMicgrid(pSMicgrid), _pBus(pBus), _pMGLine(pMGLine), _pTransformer(pTransformer){ }
};

class IMgdDao : virtual public IBasicDao
{
public:	
	//��ʼ���������ⲿʵ�����
	virtual void InitOuterObject(const MgdOuterObject& outerObject) = 0;

	//����΢�������λ�����ø���������ʵʱֵ
	virtual void SetMeasureValues(int pos, int& nBrkPos, double& dBrkTime, double& dValueP, double& dValueQ, double& dValueI, bool isGen=false) = 0;

	//��ָ��λ�õ�΢����������Ѱ���ǰ�й��Ӵ�С����Ķ����б���
	virtual void AddObjectIntoSortedPowerList(int pos, intarray& posList) = 0;
	
	//����������Ĺ��ʶ����б�����������,ƽ�⹦��ȱ������
	virtual bool IncreasePowerFromSortedList(int* incList, int incCount, double lowerP, double upperP, 
										int actFlag, int* actList, int& actCount, double& lackP) = 0;
	//����������Ĺ��ʶ����б������͹���,ƽ�⹦��ӯ������
	virtual bool DecreasePowerFromSortedList(int* decList, int decCount, double lowerP, double upperP, 
										int actFlag, int* actList, int& actCount, double& surplusP) = 0;
	virtual bool DecreasePowerFromSortedList(int* decList, int decCount, double maxplusP, 
										int actFlag, int* actList, int& actCount, double& surplusP) = 0;
	//����΢������λ�õõ������
	virtual double GetCapacity(int pos) = 0;
	//����΢������λ�õõ�·��
	virtual const char* GetPathReference(int pos) = 0;
	//����΢������λ�õõ�����ĸ��ID
	virtual int GetBusID(int pos) = 0;
	//����΢������λ�õõ�������Ķ��ѹ
	virtual double GetBaseVoltage(int pos) = 0;
	//����΢������λ���ж�������ĵ�ѹ״̬�Ƿ�����
	virtual bool IsNormalVoltage(int pos) = 0;
	//����΢������λ���ж����ϼ������ѹ�Ƿ�������״̬
	virtual bool IsNormalBusVoltage(int pos) = 0;
	//����΢������λ���ж����Ƿ�����ָ��΢����
	virtual bool IsMemberOfMicgrid(int pos, int mgId, bool chechVF=true) = 0;
	//����΢������λ�õõ��������΢��ID
	virtual int GetSelfMicgridID(int pos) = 0;
	//����΢������λ�õõ����ϼ�����������΢��ID
	virtual int GetSubMicGridID(int pos, bool chechVF=true) = 0;
	//����΢������λ�õõ����ϼ����������ĸ�΢��ID
	virtual int GetRootMicGridID(int pos, bool chechVF=true) = 0;
	//����΢������λ�õõ����ϼ�����������΢������
	virtual MicgridObectInfo* GetSubMicGrid(int pos, bool chechVF=true) = 0;
	//����΢������λ�õõ����ϼ����������ĸ�΢������
	virtual MicgridObectInfo* GetRootMicGrid(int pos, bool chechVF=true) = 0;
	//����΢������λ�õõ����ϼ�����������΢����ID�ͻID
	virtual bool GetMicgridIdAndActiveIslandId(int pos, int& mgId, int& isleId) = 0;

	//����΢������λ�õõ�����״̬ң��ID
	virtual int GetPosID(int pos) = 0;
	//����΢������λ�õõ�����״̬��ң��ID
	virtual int GetPosCtrlID(int pos) = 0;
	//����΢������λ�õõ�����״̬��ң��ID
	virtual int GetCutCtrlID(int pos) = 0;

	//����΢������λ�õõ�P��Q��Iң��ID
	virtual bool GetPQI_IDs(int pos, int& nPId, int& nQId, int& nIId) = 0;
	//����΢������λ�õõ�Pң��ID
	virtual int GetPID(int pos) = 0;
	//����΢������λ�õõ�Qң��ID
	virtual int GetQID(int pos) = 0;
	//����΢������λ�õõ�Iң��ID
	virtual int GetIID(int pos) = 0;

	//����΢������λ�õõ���ǰ����״̬
	virtual int GetCurPos(int pos) = 0;
	//����΢������λ�����õ�ǰ����״̬
	virtual bool SetCurPos(int pos, int kgPos) = 0;
	//����΢������λ�õõ���ǰ�й�����
	virtual double GetCurP(int pos) = 0;
	//����΢������λ�����õ�ǰ�й�����
	virtual bool SetCurP(int pos, double currP) = 0;
	//����΢������λ�õõ���ǰ�޹�����
	virtual double GetCurQ(int pos) = 0;
	//����΢������λ�����õ�ǰ�޹�����
	virtual bool SetCurQ(int pos, double currQ) = 0;
	//����΢������λ�õõ���ǰ����
	virtual double GetCurI(int pos) = 0;
	
	//����΢������λ�õõ�PƷ��
	virtual int GetPQlty(int pos) = 0;
	//����΢������λ�õõ�QƷ��
	virtual int GetQQlty(int pos) = 0;
	//����΢������λ�õõ�IƷ��
	virtual int GetIQlty(int pos) = 0;
	
	//����΢������λ�õõ����Ƽƻ�����λ��
	virtual int GetPlanPos(int pos) = 0;
	//����΢������λ�����ÿ��Ƽƻ�����λ��
	virtual bool SetPlanPos(int pos, int planPos) = 0;
	
	//����΢������λ�õõ����Ƽƻ��й�����
	virtual double GetPlanP(int pos) = 0;
	//����΢������λ�����ÿ��Ƽƻ��й�����
	virtual bool SetPlanP(int pos, double planP) = 0;
	
	//����΢������λ�õõ����Ƽƻ��޹�����
	virtual double GetPlanQ(int pos) = 0;
	//����΢������λ�����ÿ��Ƽƻ��޹�����
	virtual bool SetPlanQ(int pos, double planQ) = 0;
	
	//����΢������λ�õõ�����ǰ�й�����
	virtual double GetOldP(int pos) = 0;
	//����΢������λ����������ǰ�й�����[����]
	virtual bool SetOldP(int pos, double oldP) = 0;

	//����΢������λ�õõ��й�ң��ID
	virtual int GetPCtrlID(int pos) = 0;
	//����΢������λ�õõ��޹�ң��ID
	virtual int GetQCtrlID(int pos) = 0;
	//����΢������λ�ø��¼ƻ�����		
	virtual void UpdatePlanPQ(int pos) = 0;

	//�ж�ָ��λ�õ�΢�������Ƿ��˹��������й����ڲ���
	virtual bool ManuLockAdjustP(int pos) = 0;
	//�ж�ָ��λ�õ�΢�������Ƿ��˹��������޹����ڲ���
	virtual bool ManuLockAdjustQ(int pos) = 0;

	//����ң��ID�õ�ң����ʵ������ֵ		
	virtual double GetPlanValueByCtrlId(int ctrlId, bool& bOk) = 0;
	//����΢������λ�õõ�����ͨ����ͨ״̬
	virtual int GetSrcConnectState(int pos) = 0;
	//����΢������λ����������ͨ����ͨ״̬
	virtual bool SeSrcConnectState(int pos, int srcState) = 0;

	//����΢������λ�õõ��й���������־
	virtual int GetPIncLock(int pos) = 0;
	//����΢������λ�������й���������־
	virtual bool SetPIncLock(int pos, int pIncLock) = 0;

	//����΢������λ�õõ��й���������־
	virtual int GetPDecLock(int pos) = 0;
	//����΢������λ�������й���������־
	virtual bool SetPDecLock(int pos, int pDecLock) = 0;

	//����΢������λ�õõ��޹���������־
	virtual int GetQIncLock(int pos) = 0;
	//����΢������λ�������޹���������־
	virtual bool SetQIncLock(int pos, int qIncLock) = 0;

	//����΢������λ�õõ��޹���������־
	virtual int GetQDecLock(int pos) = 0;
	//����΢������λ�������޹���������־
	virtual bool SetQDecLock(int pos, int qDecLock) = 0;

protected:
	//ʹ�ÿ���״̬ң��ID����
	virtual int UseIndex_PosID() = 0; 
	//ʹ���й�ң��ID����
	virtual int UseIndex_PCtrlID() = 0;
	//ʹ���޹�ң��ID����
	virtual int UseIndex_QCtrlID() = 0;
	//ʹ�ö��������
	virtual int UseIndex_Capacity() = 0;
	//ʹ�õ�ǰ�й���������
	virtual int UseIndex_CurP() = 0;
	//ʹ�õ�ǰ�޹���������
	virtual int UseIndex_CurQ() = 0;
	//ʹ��ģ����ʵ�����
	virtual IAnalogDao* UseAnalogDao() = 0;
	//ʹ��״̬��ʵ�����
	virtual IStatusDao* UseStatusDao() = 0;
	//ʹ�ÿ�����ʵ�����
	virtual IControlDao* UseControlDao() = 0;
	//ʹ�üƻ��й���������
	virtual int UseIndex_PlanP() = 0;
	//ʹ�üƻ��޹���������
	virtual int UseIndex_PlanQ() = 0;
	//�ж��Ƿ�Ϊ�������״̬
	virtual bool IsTest() = 0;
	//ʹ��ң����ʵ�����
	virtual IAccumuDao* UseAccumuDao() = 0;

public:
	//����΢������λ�õõ��ϼ��豸λ�á�eqpType��0--δ֪��1--ĸ�ߣ�2--��·��3--��ѹ����
	virtual bool GetParentEquipPos(int pos, int& eqpPos, int& objPos, int& eqpType, bool chechVF=true) = 0;
	//����΢������λ���ж��޹�ң��ֵ�Ƿ������ԣ����������޹�Ϊ����
	virtual bool IsCapcitiveQCtrlValue(int pos) = 0;

};

//�ۺ�����״̬���ͣ�0��ͣ�ˣ�1:����������2��ȫ�������У�3���޹������У�4�����ޣ�5������[���޻������]��6������[������]
enum RUNSTATETYPE
{
	RST_STOP, RST_BACKUP, RST_MAXPOWER, RST_LIMITPOWER, RST_REPAIR, RST_FAULT, RST_ISLAND, 
};

#endif
