//ibusconndao.h

#ifndef _IBATSTATIONDAO_ZHANGMENG_20180708_H_
#define _IBATSTATIONDAO_ZHANGMENG_20180708_H_

#include "../ibasicdao.h"                        // for IBasicDao

#define BATSTATIONDAO_CLASSID    "cbatstationdao"
#define BATSTATIONDAO_INTFID     "ibatstationdao"

class IBatStationDao : virtual public IBasicDao
{
public:
	virtual int GetSvTimerIDByPos(int pos)=0;//�洢����
	virtual int GetcondiByPos(int pos)=0;//ȫվ��ŵ�״̬
	virtual double GetsocByPos(int pos)=0;//ȫվSOC
	virtual double GetsohByPos(int pos)=0;//ȫվSOH
	virtual double GettemperatureByPos(int pos)=0;//ȫվ���ƽ���¶�
	virtual double GettodayincyclesByPos(int pos)=0;//���������
	virtual double GettodayoutcyclesByPos(int pos)=0;//����ŵ����
	virtual double GetinableTByPos(int pos)=0;//��ǰ���ʳ�����ʱ��
	virtual double GetoutableTByPos(int pos)=0;//��ǰ���ʷŵ����ʱ��
	virtual double GetMaxPinableTByPos(int pos)=0;//����ʳ�����ʱ��
	virtual double GetMaxPoutableTByPos(int pos)=0;//����ʷŵ����ʱ��
	virtual double GetoutableQTByPos(int pos)=0;//�����޹�����ʱ��
	virtual double GetinablePByPos(int pos)=0;//���ó�繦��
	virtual double GetoutablePByPos(int pos)=0;//���÷ŵ繦��
	virtual double GetinablePtByPos(int pos)=0;//�ɳ����
	virtual double GetoutablePtByPos(int pos)=0;//�ɷŵ���
	virtual double GetoutableQByPos(int pos)=0;//�����޹�����
	virtual double GettodayinPtByPos(int pos)=0;//���������
	virtual double GettodayoutPtByPos(int pos)=0;//����ŵ����
	virtual double GettotalinPtByPos(int pos)=0;//�ۼ��ܳ����
	virtual double GettotaloutPtByPos(int pos)=0;//�ۼ��ܷŵ���
	virtual double GetmaxPinByPos(int pos)=0;//����繦��
	virtual double GetmaxPoutByPos(int pos)=0;//���ŵ繦��
	virtual double GetablecapByPos(int pos)=0;//��������
	virtual double Getdata1ByPos(int pos)=0;//Ԥ��1
	virtual double Getdata2ByPos(int pos)=0;//Ԥ��2
	virtual double Getdata3ByPos(int pos)=0;//Ԥ��3
	virtual double Getdata4ByPos(int pos)=0;//Ԥ��4
	
};

#endif
