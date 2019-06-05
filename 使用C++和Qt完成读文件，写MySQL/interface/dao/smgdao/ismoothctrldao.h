//ismoothctrldao.h

#ifndef _ICSMOOTHCTRLDAO_PENGSHIKANG_20110712_H_
#define _ICSMOOTHCTRLDAO_PENGSHIKANG_20110712_H_

#include "../ibasicdao.h"                        // for IBasicDao
#include "../../smgsrv/smgdatadef.h"             // for MicgridObectInfo

#define SMOOTHCTRLDAO_CLASSID    "csmoothctrldao"
#define SMOOTHCTRLDAO_INTFID     "ismoothctrldao"

class ISmoothCtrlDao : virtual public IBasicDao
{
public:
	//�����ݱ�ľ�̬��Ϣ����ָ����MicgridObectInfo����
	virtual bool InitSmoothInfoOfMicgrid(MicgridObectInfo* pCurMgObj) = 0;
	
	//д��ϵͳ��Ϣ��ĸ���������ֵ
	virtual void WriteDynamicInfo1(MicgridObectInfo* pCurMgObj) = 0;
	
	//�����ݱ�Ķ�̬��Ϣд�����
	virtual void WriteDynamicInfo1() = 0;
	
	virtual int GetPositionByMGID(int mgid) = 0;
	virtual int GetMGID(int pos) = 0;        //�õ�΢����ID
	virtual bool IsEnable(int pos) = 0;      //�Ƿ���Ч
	virtual int GetAimType(int pos) = 0;     //�õ�Ŀ������
	virtual double GetMaxRatio(int pos) = 0; //�õ��������仯��
	virtual int GetCtrlTimes(int pos) = 0;   //�õ��������Ƴ�������
	virtual double GetPrevExchP(int pos) = 0;//�õ���ǰ��������
	virtual double GetPrevGenP(int pos) = 0; //�õ���ǰ���繦��
	virtual double GetPrevStorP(int pos) = 0;//�õ���ǰʵ�ʴ��ܹ���
	virtual double GetPrevStorPlanP(int pos) = 0;//�õ���ǰ�ƻ����ܹ���
	virtual double GetPrevLoadP(int pos) = 0;//�õ���ǰ���ɹ���
	virtual double GetPrevBaseP(int pos) = 0;//�õ���ǰ��׼����
	virtual double GetPrevAimP(int pos) = 0; //�õ���ǰĿ�깦��
	virtual double GetCurBaseP(int pos) = 0; //�õ���ǰ��׼Ŀ�깦��
	virtual double GetCurAimP(int pos) = 0;  //�õ���ǰĿ�깦��
	virtual double GetCurRatio(int pos) = 0; //�õ���ǰ�仯��
	virtual double GetCurCompP(int pos) = 0; //�õ���ǰ��������
	virtual int GetStartFlag(int pos) = 0;   //�õ��������Ʊ�־
	
	virtual bool SetCurBaseP(int pos, double baseP) = 0; //���õ�ǰ��׼Ŀ�깦��
	virtual bool SetCurAimP(int pos, double aimP) = 0;   //���õ�ǰĿ�깦��
	virtual bool SetCurRatio(int pos, double ratio) = 0; //���õ�ǰ�仯��
	virtual bool SetCurCompP(int pos, double compP) = 0; //���õ�ǰ��������
	virtual bool SetStartFlag(int pos, int startFlag) = 0;//�����������Ʊ�־
};

#endif
