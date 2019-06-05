//igentypestatdao.h

#ifndef _IGENERATORTYPESTATISTICSDAO_PENGSHIKANG_20120518_H_
#define _IGENERATORTYPESTATISTICSDAO_PENGSHIKANG_20120518_H_

#include "../ibasicdao.h"                        // for IBasicDao
#include "../../smgsrv/genstatisdef.h"           // for GeneClassStatisInfo

#define GENSTATDAO_CLASSID    "cgenstatdao"
#define GENSTATDAO_INTFID     "igenstatdao"

class IGenStatDao : virtual public IBasicDao
{
public:
	//�����ݱ�Ķ�̬��Ϣд�����[save]
	virtual void WriteDynamicInfo1() = 0;

	//���ݷ��������ID����΢��ID�õ��������ͳ�Ƽ�¼��λ��
	virtual int GetPositionByGenTypeAndSmgID(int genType, int smgId) = 0;
	
	//���ݷ������ͳ�Ʊ��λ�����ø���������ʵʱֵ
	virtual void SetMeasureValues(int pos, GeneClassStatisInfo* pGenSttsInfo) = 0;
	
	//���ݷ������ͳ�Ʊ�λ�õõ������豸����ID
	virtual int GetGeneratorTypeID(int pos) = 0;
	//���ݷ������ͳ�Ʊ�λ�õõ���΢��ID
	virtual int GetSubMicGridID(int pos) = 0;
	
	//���ݷ������ͳ�Ʊ�λ�õõ���ǰ���й�
	virtual double GetCurTotalP(int pos) = 0;
	//���ݷ������ͳ�Ʊ�λ�õõ���ǰ���޹�
	virtual double GetCurTotalQ(int pos) = 0;
	
	//���ݷ������ͳ�Ʊ������ͺ�΢����ID�õ���ǰ���й�
	virtual double GetCurTotalP(int genType, int smgId) = 0;
	//���ݷ������ͳ�Ʊ������ͺ�΢����ID�õ���ǰ���޹�
	virtual double GetCurTotalQ(int genType, int smgId) = 0;	

	//���ݷ������ͳ�Ʊ�λ�õõ�������
	virtual double GetTotalGenCapacity(int pos) = 0;
	//���ݷ������ͳ�Ʊ�λ������������
	virtual bool SetTotalGenCapacity(int pos, double genCapa) = 0;

	//���ݷ������ͳ�Ʊ�λ�õõ���������
	virtual double GetRunGenCapacity(int pos) = 0;
	//���ݷ������ͳ�Ʊ�λ�����ÿ�������
	virtual bool SetRunGenCapacity(int pos, double genCapa) = 0;
	//���ݷ������ͳ�Ʊ�λ�õõ��޵�����
	virtual double GetLimitGenCapacity(int pos) = 0;
	//���ݷ������ͳ�Ʊ�λ�������޵�����
	virtual bool SeLimitGenCapacity(int pos, double genCapa) = 0;

	//���ݷ������ͳ�Ʊ�λ�õõ���̨��
	virtual int GetTotalGenCount(int pos) = 0;
	//���ݷ������ͳ�Ʊ�λ��������̨��
	virtual bool SetTotalGenCount(int pos, int genNum) = 0;
	//���ݷ������ͳ�Ʊ�λ�õõ���ǰ����̨��
	virtual int GetRunGenCount(int pos) = 0;
	//���ݷ������ͳ�Ʊ�λ�����õ�ǰ����̨��
	virtual bool SetRunGenCount(int pos, int genNum) = 0;
	//���ݷ������ͳ�Ʊ�λ�õõ���ǰ�޵�̨��
	virtual int GetLimitGenCount(int pos) = 0;
	//���ݷ������ͳ�Ʊ�λ�����õ�ǰ�޵�̨��
	virtual bool SetLimitGenCount(int pos, int genNum) = 0;

	//���ݷ������ͳ�Ʊ�λ�õõ���ǰ������
	virtual double GetRunGenRate(int pos) = 0;
	//���ݷ������ͳ�Ʊ�λ�����õ�ǰ������
	virtual bool SetRunGenRate(int pos, double runRate) = 0;
	//���ݷ������ͳ�Ʊ�λ�õõ���ǰ�޵���
	virtual double GetLimitGenRate(int pos) = 0;
	//���ݷ������ͳ�Ʊ�λ�����õ�ǰ�޵���
	virtual bool SetLimitGenRate(int pos, double runRate) = 0;

	//���ݷ������ͳ�Ʊ�λ�õõ����շ�����
	virtual double GetTodayEnergy(int pos) = 0;          
	//���ݷ������ͳ�Ʊ�λ�õõ��ۼƷ�����
	virtual double GetTotalEnergy(int pos) = 0;  
	//���ݷ������ͳ�Ʊ�λ�û��ܽ��շ��������ۼƷ�����			
	virtual void SummaryGenEnergy(int pos, double todayW, double totalW) = 0;

	//���ݷ������ͳ�Ʊ�λ�õõ����һ��ͳ��ʱ��
	virtual double GetStatisticsTime(int pos) = 0;
	//���ݷ������ͳ�Ʊ�λ���������һ��ͳ��ʱ��
	virtual bool SetStatisticsTime(int pos, double sttsTime) = 0;

	//���ݷ������ͳ�Ʊ�λ�õõ�����̨��
	virtual int GetRepairNum(int pos) = 0;
	//���ݷ������ͳ�Ʊ�λ�õõ�����̨��
	virtual int GetStandbyNum(int pos) = 0;
	//���ݷ������ͳ�Ʊ�λ�õõ�����̨��
	virtual int GetFaultNum(int pos) = 0;

	//���ݷ������ͳ�Ʊ�λ�õõ��ɵ�����
	virtual double GetAdjPCapacity(int pos) = 0;
	//���ݷ������ͳ�Ʊ�λ�õõ��й��ɵ�����
	virtual double GetAdjPUpperLimit(int pos) = 0;
	//���ݷ������ͳ�Ʊ�λ�õõ��й��ɵ�����
	virtual double GetAdjPLowerLimit(int pos) = 0;
	//���ݷ������ͳ�Ʊ�λ�õõ������й�
	virtual double GetPIncreaseLimit(int pos) = 0;
	//���ݷ������ͳ�Ʊ�λ�õõ��ɼ��й�
	virtual double GetDecreaseLimit(int pos) = 0;
	//���ݷ������ͳ�Ʊ�λ�õõ����������ʧ�й�����
	virtual double GetLossPower(int pos) = 0;
	//���ݷ������ͳ�Ʊ�λ�õõ��й��ϵ��ڱ�����־
	virtual int GetPIncLockFlag(int pos) = 0;
	//���ݷ������ͳ�Ʊ�λ�õõ��й��µ��ڱ�����־
	virtual int GetPDecLockFlag(int pos) = 0;
	//���ݷ������ͳ�Ʊ�λ�õõ��޹�����δ�޵�ʱ�����۷����й�����
	virtual double GetNaturalGeneratePower(int pos) = 0;
	//���ݷ������ͳ�Ʊ�λ�õõ�δ�޵�ʱ�Ŀ��÷����й�����
	virtual double GetRealGeneratePower(int pos) = 0;

};

#endif
