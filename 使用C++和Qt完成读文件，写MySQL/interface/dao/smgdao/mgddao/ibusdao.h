//ibusdao.h

#ifndef _IBUSDAO_PENGSHIKANG_20100324_H_
#define _IBUSDAO_PENGSHIKANG_20100324_H_

#include "../../ibasicdao.h"                     // for IBasicDao
#include "../../../smgsrv/vqcdatadef.h"          // for BusDeviceInfo��VQCAreaInfo

#define BUSDAO_CLASSID    "cbusdao"
#define BUSDAO_INTFID     "ibusdao"

class IEquipDao;
class IAnalogDao;
class IVoltageDao;
class ISMicgridDao;
class ICommSrcDao;

class IBusDao : virtual public IBasicDao
{
public:
	//���òɼ�����Դ����
	virtual void SetCommSrcDao(ICommSrcDao* pCommSrc) = 0;
	//�����豸ʵ�����
	virtual void SetEquipDao(IEquipDao* pEquip) = 0;
	//����ģ����ʵ�����
	virtual void SetAnalogDao(IAnalogDao* pAnalog) = 0;
	//���õ�ѹ�ȼ�ʵ�����
	virtual void SetVoltageDao(IVoltageDao* pVoltage) = 0;
	//����΢����ʵ�����
	virtual void SetSMicgridDao(ISMicgridDao* pSMicgrid) = 0;

	//����ĸ�������豸��̬��Ϣ��ʼ��[����VQC]
	virtual void InitAllBusDeviceDynamicInfo() = 0;
	//��ʼ������VQC����ϵͳ���޹����߼�����Ϣ
	virtual void InitAllRepowSourcesOfAdjustArea(int pccNum, int lineNum) = 0;
	//��ʼ������ĸ�ߵ�VQC����ϵͳ����Ϣ
	virtual void InitAllAdjustAreaNos() = 0;
	//��ʼ������ĸ������VQC����ϵͳ�ľ���ͼ������Ϣ
	virtual void InitAllVqcZoneNos() = 0;

	//����ĸ�ߵ�λ�����ø���������ʵʱֵ
	virtual void SetMeasureValues(int pos, double& dValueU, double& dValueF) = 0;
	
	//����ĸ��λ�õõ�ĸ�������豸��Ϣ
	virtual BusDeviceInfo* GetBusDeviceInfo(int pos) = 0;
	//����ĸ��ID�õ�ĸ�������豸��Ϣ
	virtual BusDeviceInfo* GetBusDeviceInfoById(int id) = 0;
	
	//����ĸ��λ�õõ�·��
	virtual const char* GetPathReference(int pos) = 0;
	//����ĸ��λ�õõ���΢��ID
	virtual int GetSubMicGridID(int pos) = 0;
	//����ĸ��λ�õõ��������ĻID
	virtual int GetActiveIslandId(int pos) = 0;
	//����ĸ�߶���ID�ж����Ƿ���ָ����΢�����������
	virtual bool InMicgridActiveIslandByID(int id, int mgPos) = 0;

	//����ĸ��λ�õõ�Uң��ID
	virtual int GetUID(int pos) = 0;
	//����ĸ��λ�õõ�Fң��ID
	virtual int GetFID(int pos) = 0;
	//����ĸ��λ�õõ���ǰ��ѹ
	virtual double GetCurU(int pos) = 0;
	//����ĸ��λ�õõ���ǰƵ��
	virtual double GetCurF(int pos) = 0;
	//����ĸ��λ�õõ���ǰ��ѹ��Ƶ��
	virtual bool GetCurUFById(int id, double& curU, double& curF) = 0;
	
	//����ĸ��λ�õõ�ĸ��������������
	virtual int GetAdjustAreaNo(int pos) = 0;
	//����ĸ��λ������ĸ��������������
	virtual bool SetAdjustAreaNo(int pos, int adjustNo) = 0;
	//����ĸ��ID����ĸ��������������
	virtual bool SetAdjustAreaNoByID(int id, int adjustNo) = 0;
	
	//����ĸ��λ�õõ�VQC��ǰ�����
	virtual int GetVoltRepowerAreaNo(int pos) = 0;
	//����ĸ��λ������VQC��ǰ�����
	virtual bool SetVoltRepowerAreaNo(int pos, int zoneNo) = 0;
	
	//����ĸ��λ�õõ���ѹ�޹�����ĸ�����͡�0--�ο�ĸ�ߣ�1--��ѹ�޹�����ĸ�ߣ�2--��ѹ����ĸ�ߣ�3--�޹�����ĸ�ߡ�
	virtual int GetVoltageControlType(int pos) = 0;
	
	//����VQC��������ID�õ�VQC�����������
	virtual VQCAreaInfo* GetAdjustAreaByID(int areaId) = 0;
	//�����޹�����ĸ��λ�õõ�VQC�����������
	virtual VQCAreaInfo* GetAdjustAreaByRPCBusPos(int busPos) = 0;
	
	//����ĸ��λ�õõ����ѹ
	virtual double GetBaseVoltage(int pos) = 0;
	virtual double GetBaseVoltageByID(int id) = 0;
	virtual bool IsNormalVoltage(int pos) = 0;
	virtual bool IsActive(int pos) = 0;

	//���º���ģ����Ʋ���ʱʹ��
	//����ĸ�߶���ID���õ�ǰ��ѹ��Ƶ��Ϊ����ֵ
	virtual bool TestBusVolt_FreqToNormalByID(int id) = 0;
	//����ĸ�߶���λ�����õ�ǰ��ѹΪָ��ֵ
	virtual bool TestSetBusVoltage(int pos, float curU) = 0;
	//����ĸ��λ�����õ�ǰƵ��Ϊָ��ֵ
	virtual bool TestSetBusFrequency(int pos, float curF) = 0;
	//������΢��ID������΢��������ĸ�ߵ�ѹΪ����ֵ
	virtual bool TestMicgridVoltageToNormal(int dadMgId) = 0;
	//������΢��ID������΢��������ĸ��Ƶ��Ϊ����ֵ
	virtual bool TestMicgridFrequencyToNormal(int dadMgId) = 0;
	//������΢��ID������΢��������ĸ��Ƶ��Ϊָ��ֵ
	virtual bool TestSetMicgridFrequency(int dadMgId, float newF) = 0;

	//����ĸ�߶���λ�õõ�����ͨ����ͨ״̬
	virtual int GetSrcConnectState(int pos) = 0;
	//����ĸ�߶���λ����������ͨ����ͨ״̬
	virtual bool SeSrcConnectState(int pos, int srcState) = 0;
	//�ͷ����е�ĸ�������豸��Ϣ�Ŀռ�
	virtual void FreeAllBusDeviceInfoMemory() = 0;
	//����ĸ��λ�õõ���ǰ��ѹƷ��
	virtual int GetCurUQuality(int pos) = 0;
	//����ĸ��λ�õõ���ǰƵ��Ʒ��
	virtual int GetCurFQuality(int pos) = 0;
	//����ĸ��λ�ü��ĸ��ʵʱ����Ʒ���Ƿ��쳣
	virtual bool InnormalRtDataByQuality(int pos) = 0;

	//��ȡ��������ĸ��λ���б�
	virtual const intarray& GetCtrlBusList() = 0;

};

#endif
