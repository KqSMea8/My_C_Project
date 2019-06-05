// iexpresscalcu.h
#ifndef _IEXPRESSCALCU_H_
#define _IEXPRESSCALCU_H_

#include "icsunknown.h" // for IICSUnknown

//���ݼ���ӿ�
#define DLL_EXPRESSCALCU	"expresscalcu"
#define IID_EXPRESSCALCU	"IExpressCalcu"
#define CID_EXPRESSCALCU	"CExpressCalcu"


class IExpressCalcu: public IICSUnknown
{
public:
	//���ؽ��0�ɹ���1�����ʽΪ�գ�2�����ʽ����ȷ��3��������Ϊ0,  4:���㳬ֵ�� 5:ʵʱ������ʧ�� ,6:����ID������
	//��������quality��
	///���ݱ��ʽ������
	virtual	int calcuExp(const char* exp,double* result,int* quality) = 0;  
	//ͨ������ID������
	virtual	int calcuExpCalID(int expCalID,double* result,int* quality) = 0; 
	//�����û��Զ������Ի���
	virtual	void customerCal() = 0; 
};

#endif
