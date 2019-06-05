//iaccumudao.h

#ifndef _IACCUMULATORDAO_PENGSHIKANG_20100805_H_
#define _IACCUMULATORDAO_PENGSHIKANG_20100805_H_

#include "irawdao.h"                           // for IRawDao

#define ACCUMUDAO_CLASSID    "caccumudao"
#define ACCUMUDAO_INTFID     "iaccumudao"

class IAccumuDao : virtual public IRawDao
{
public:
	//�����ݱ�Ķ�̬��Ϣд�����
	virtual void WriteDynamicInfo1() = 0;
		
	//�����ۼ����������������ݣ�
	virtual bool SetAccumuValue(int nAcumPos, int nSrcId, int nPntId, double curTime, 
		double rawValue, int curQualt) = 0;
	
	//�����ۼ����������������ݣ�
	virtual bool SetAccumuValue(int nAcumPos, int nSrcId, int nPntId, double curTime, double rawValue, 
		int curQualt, double relValue, double incValue, double amoValue, double accValue) = 0;
	
	//�����ۼ���λ�õõ��ۼ�������
	virtual int GetAccumuType(int pos) = 0;
	//�����ۼ���λ�õõ�������λ
	virtual int GetMeasUnit(int pos) = 0;
	//�����ۼ���λ���ж��Ƿ��ʱ��ͳ��
	virtual int IsPeriodStatistic(int pos) = 0;
	//�����ۼ���λ�õõ���ϵ��
	virtual double GetScaleFactor(int pos) = 0;
	//�����ۼ���λ�õõ���ϵ��
	virtual double GetOffset(int pos) = 0;
	//�����ۼ���λ�ü����ۼ�������ֵ
	virtual bool IncreaseValue(int pos, double calValue, double& increVal, double& amontVal, double& accValue) = 0;
	
	//�����ۼ���λ�õõ�������������
	virtual double GetMaxValue(int pos) = 0;
	//�����ۼ���λ�õõ�������������
	virtual double GetMinValue(int pos) = 0;
	//�жϵ�ǰֵ�Ƿ�Ϊ����ֵ
	virtual bool IsNormalValue(int pos, double curVal) = 0;

	//�����ۼ���λ�õõ���������ֵ
	virtual double GetUpperValue(int pos) = 0;
	
	//�����ۼ���λ�õõ����ֵ
	virtual double GetRelativeValue(int pos) = 0;
	//�����ۼ���λ�õõ�����ֵ
	virtual double GetIncrementValue(int pos) = 0;
	
	//��ȡʱ��ͳ�Ʊ��ͳ�ƴ洢��־
	virtual void ReadSaveFlags() = 0;
	//�������ݶ���λ�õõ�ͳ�ƴ洢��־
	virtual int GetSaveFlag(int pos) = 0;
	//��λָ����¼λ�õ�ͳ�ƴ洢��־
	virtual bool ResetSaveFlag(int pos) = 0;
	
	//�����ۼ���λ�õõ�����ֵ
	virtual double GetCalValue(int pos) = 0;
	//�����ۼ���ID�õ�����ֵ
	virtual double GetCalValueById(int id, bool* ok=0) = 0;

	//�����ۼ���λ�õõ����ۼ�ֵ
	virtual double GetTotalValue(int pos) = 0;
};

#endif
