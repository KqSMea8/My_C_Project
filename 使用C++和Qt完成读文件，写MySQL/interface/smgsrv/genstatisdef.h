// genstatisdef.h 

#ifndef _GENSTATISDEFINCE_PENSHIKANG_20150706_H_
#define _GENSTATISDEFINCE_PENSHIKANG_20150706_H_

enum GeneratorType
{
	GT_DG = 0,  //�ܷ���
	GT_PV,      //�������
	GT_WIND,    //��������
	GT_TURBINE, //ȼ���ֻ�
	GT_FUELCELL,//ȼ�ϵ��
	GT_INCOMBUS,//��ȼ��
	GT_HYDRAULIC,//ˮ�ֻ�
	GT_TYPE7,
	GT_TYPE8,
	GT_TYPE9,
	GT_TYPE10,
	GT_STORAGE, //���ش���
	GT_FLYWHEEL,//���ִ���
	GT_SUPCAPAC,//����������
	GT_SUPMAGNT,//�����Ŵ���
	GT_PUMPSTOR,//��ˮ����
	GT_TYPE16,
	GT_INVALID  //��Ч����
};

//���������ͳ����Ϣ�ṹ
typedef struct 
{
	double totalS; //�����������(kW)
	int totalNum;  //�������̨��
	double runS;   //�������������(kW)
	double maxP;   //���������й�����(kW), ���ڼ�����͸��
	int runNum;    //���������̨��
	double lmtS;   //������޵�����(kW)
	int lmtNum;    //������޵�̨��
	double curP;   //��ǰ�����й�����(kW)
	double curQ;   //��ǰ�����޹�����(kVar)
	double todayW; //���շ�����(kWh)
	double totalW; //�ۼƷ�����(kWh)
	int repairNum; //����̨��
	int standbyNum;//����̨��
	int faultNum;  //����̨��

	double calcPCapa;//��˷��������
	double curCalcP; //��˷������ǰ�й�����(kW)
	double adjPCapa; //�ɵ����������
	double adjMaxP;  //�ɵ�������й���������
	double adjMinP;  //�ɵ�������й���������
	double curAdjP;  //�ɵ��������ǰ�й�����(kW)
	double curFixP;  //���ɵ��������ǰ�й�����(kW)
	double curAdjPo; //�ɵ�������ܵ��й�������(kW)
	double totalPCapa;//�ܵĿɵ����������
	double maxPRate; //��˷��������󷢵���

}GeneClassStatisInfo;

#endif
