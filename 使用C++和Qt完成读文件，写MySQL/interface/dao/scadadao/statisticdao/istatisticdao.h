//istatisticdao.h

#ifndef _ISTATISTICSDAO_PENGSHIKANG_20130310_H_
#define _ISTATISTICSDAO_PENGSHIKANG_20130310_H_

#include "../../ibasicdao.h"                     // for IBasicDao
#include "../../../icsvalue.h"                   // for intarray

#define STATISTICDAO_CLASSID    "cstatisticdao"
#define STATISTICDAO_INTFID     "istatisticdao"

class IStatisticDao : virtual public IBasicDao
{
public:
	//д��ͳ�Ʊ�Ķ�̬��Ϣ
	virtual void WriteDynamicInfo1() = 0;
	
	//���ݶ�ʱ������IDͳ�ƶ�Ӧ�Ĺ�ʽ�����¼��
	virtual int StatisticsDatasByTimerId(int timerId) = 0;
	
	//���ݴ洢����ID�õ���Ӧ�Ĳ�����ݼ�¼��
	virtual intarray* GetDataIdSetByType(int nTypeId) = 0;

	//����״̬��ͳ��λ�õõ����һ��ͳ��ʱ��
	virtual double GetStatisticsTime(int pos) = 0;
	
	//��ȡͳ�Ʊ��ͳ�ƴ洢��־
	virtual void ReadSaveFlags() = 0;
	//�������ݶ���λ�õõ�ͳ�ƴ洢��־
	virtual int GetSaveFlag(int pos) = 0;
	//��λָ����¼λ�õ�ͳ�ƴ洢��־
	virtual bool ResetSaveFlag(int pos) = 0;
	
	//�������ݶ���λ�õõ�ͳ�ƴ洢����ID
	virtual int GetSaveTimerId(int pos) = 0;

protected:
	virtual int GetIndex_StaticTime() = 0;
	virtual int GetIndex_SaveFlag() = 0;
	//�Ƿ�洢��־δ�䶯
	virtual bool IsOldSaveFlag() = 0;
	//��ʼ��ȫ��¼ͳ�ƴ洢��־�ڴ�
	virtual void InitSaveFlagMemory() = 0;
	//����ȫ��¼ͳ�ƴ洢��־�ڴ�
	virtual void MallocSaveFlagMemory(int statNum) = 0;
	//�ͷ�ȫ��¼ͳ�ƴ洢��־�ڴ�
	virtual void FreeSaveFlagMemory() = 0;

};

#endif
