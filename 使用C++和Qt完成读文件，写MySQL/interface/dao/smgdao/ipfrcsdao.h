//ipfrcsdao.h

#ifndef _IPFORCASTDAO_SUNRUI_20130528_H_
#define _IPFORCASTDAO_SUNRUI_20130528_H_

#include "../ibasicdao.h"                        // for IBasicDao

#define PFORCASTDAO_CLASSID    "cpfrcsdao"
#define PFORCASTDAO_INTFID     "ipfrcsdao"

class IPForcastDao  : virtual public IBasicDao 
{
public:
	//���ݳ�������Ԥ��λ�û�ȡ΢����id
	virtual int GetSMGID(int pos) = 0;
	//���ݳ�������Ԥ��λ�û�ȡ������־
	virtual bool GetStartFlag(int pos) = 0;
	//���ݳ�������Ԥ��λ�û�ȡ��������
	virtual int GetPType(int pos) = 0;
	//���ݳ�������Ԥ��λ�û�ȡԤ����
	virtual int GetSPan(int pos) = 0;
	//���ݳ�������Ԥ��λ�û�ȡԤ�����ݼ��
	virtual int GetDataSPan(int pos) = 0;
	//���ݳ�������Ԥ��λ�û�ȡԤ�����ݼ�
	virtual bool GetForPData(int pos, double* data) = 0;
	//���ݳ�������Ԥ��λ������Ԥ�����ݼ�
	virtual bool SetForPData(int pos, double* data) = 0;
	
	//���ݳ�������Ԥ��λ�õõ�������ʽ
	virtual const char* GetCalculateExpress(int pos) = 0;
	//���ݳ�������Ԥ��λ�û�ȡԤ��ƽ��ֵ
	virtual double GetForPAverage(int pos) = 0;
	//���ݳ�������Ԥ��λ������Ԥ��ƽ��ֵ
	virtual bool SetForPAverage(int pos, double dAvg) = 0;

};

#endif
