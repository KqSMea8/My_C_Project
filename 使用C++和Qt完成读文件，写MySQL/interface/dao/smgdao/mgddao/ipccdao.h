//ipccdao.h

#ifndef _IPCCDAO_PENGSHIKANG_20100324_H_
#define _IPCCDAO_PENGSHIKANG_20100324_H_

#include "imgddao.h"                             // for IMgdDao

#define PCCDAO_CLASSID    "cpccdao"
#define PCCDAO_INTFID     "ipccdao"

class IPccDao : virtual public IMgdDao
{
public:
	//���ݹ������ӵ�λ�ø��������ѹ��Ƶ��
	virtual void UpdateDisnetUF(int pos, double& dValueU, double& dValueF) = 0;
	
	//���ݹ������ӵ�λ�õõ������ϼ�΢������·ID
	virtual int GetLineID(int pos) = 0;
	//���ݹ������ӵ�λ�õõ������ѹң��ID
	virtual int GetUID(int pos) = 0;
	//���ݹ������ӵ�λ�õõ�����Ƶ��ң��ID
	virtual int GetFID(int pos) = 0;
	//���ݹ������ӵ�λ�õõ����൱ǰ��ѹ
	virtual double GetCurU(int pos) = 0;
	//���ݹ������ӵ�λ�õõ����൱ǰƵ��
	virtual double GetCurF(int pos) = 0;	

	//���ݹ������ӵ�λ�õõ���������ң��ID
	virtual int GetSaleEnergyID(int pos) = 0;
	//���ݹ������ӵ�λ�õõ���������ң��ID
	virtual int GetUseEnergyID(int pos) = 0;
	//���ݹ������ӵ�λ�õõ�������������
	virtual double GetTodaySaleEnergy(int pos) = 0;
	//���ݹ������ӵ�λ�õõ��ۼ���������
	virtual double GetTotalSaleEnergy(int pos) = 0;
	//���ݹ������ӵ�λ�õõ�������������
	virtual double GetTodayUseEnergy(int pos) = 0;
	//���ݹ������ӵ�λ�õõ��ۼ���������
	virtual double GetTotalUseEnergy(int pos) = 0;

	//���ݹ������ӵ�λ�����ý�����������
	virtual bool SetTodaySaleEnergy(int pos, double dTodaySaleWh) = 0;
	//���ݹ������ӵ�λ�������ۼ���������
	virtual bool SetTotalSaleEnergy(int pos, double dTotalSaleWh) = 0;
	//���ݹ������ӵ�λ�����ý�����������
	virtual bool SetTodayUseEnergy(int pos, double dTodayUseWh) = 0;
	//���ݹ������ӵ�λ�������ۼ���������
	virtual bool SetTotalUseEnergy(int pos, double dTotalUseWh) = 0;
};

#endif
