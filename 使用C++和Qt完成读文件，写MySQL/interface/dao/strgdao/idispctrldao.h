//idispctrldao.h

#ifndef _IDISPCTRLDAO_20190531_YANGZHENYU_H_
#define _IDISPCTRLDAO_20190531_YANGZHENYU_H_

#include "../ibasicdao.h"                             // for IMgdDao

#define DISPCTRLDAO_CLASSID    "csdispctrldao"
#define DISPCTRLDAO_INTFID     "isdispctrldao"


class IDispctrldao : virtual public IBasicDao
{
public:	
	//��̬
	//���ݳ�վ������λ�õõ�������ID
	virtual int GetPctrlID(int pos) = 0;
	//���ݳ�վ������λ�õõ������ϼ������й�����ѹ��id
	virtual int GetReceivflagID(int pos) = 0;
	//���ݳ�վ������λ�õõ��ϼ��й�����ֵid
	virtual int GetDispatchpvalID(int pos) = 0;
	//���ݳ�վ������λ�õõ��ϼ��й����ȿ��Ƴ���ʱ��(����)
	virtual double GetDispatchoverdue(int pos) = 0;

	//��̬
	//���ݳ�վ������λ�õõ��й�������ѹ��
	virtual int GetPctrlflag(int pos) = 0;
	//���ݳ�վ������λ�������й�������ѹ��
	virtual bool SetPctrlflag(int pos, int value) = 0;

	//���ݳ�վ������λ�õõ���һ������ϵͳѹ��
	virtual int GetAgcreceivflag(int pos) = 0;
	//���ݳ�վ������λ��������һ������ϵͳѹ��
	virtual int SetSgcreceivflag(int pos, int value) = 0;

	//���ݳ�վ������λ�õõ���һ������ϵͳ����ֵ
	virtual double GetDispatchpVal(int pos) = 0;
	//���ݳ�վ������λ��������һ������ϵͳ����ֵ
	virtual double SetSispatchpVal(int pos, double value) = 0;

	//���ݳ�վ������λ�õõ���һ������ϵͳ����ʱ��
	virtual double GetDispatchpTime(int pos) = 0;
	//���ݳ�վ������λ��������һ������ϵͳ����ʱ��
	virtual bool SetSispatchpTime(int pos, double value) = 0;

	//���ݳ�վ������λ�õõ���һ����ǰ�ƻ�ʱ��
	virtual double GetLastdayTime(int pos) = 0;
	//���ݳ�վ������λ��������һ����ǰ�ƻ�ʱ��
	virtual bool SetLastdayTime(int pos, double value) = 0;

	//���ݳ�վ������λ�õõ���һ�����ڼƻ�ʱ��
	virtual double GetIndayTime(int pos) = 0;
	//���ݳ�վ������λ��������һ�����ڼƻ�ʱ��
	virtual bool SetIndayTime(int pos, double value) = 0;

	//���ݳ�վ������λ�õõ������й������趨ֵ
	virtual double GetLocalpVal(int pos) = 0;
	//���ݳ�վ������λ�����ñ����й������趨ֵ
	virtual bool SetLocalpVal(int pos, double value) = 0;

	//���ݳ�վ������λ�õõ������й������趨ʱ��
	virtual double GetLocalpTime(int pos) = 0;
	//���ݳ�վ������λ�����ñ����й������趨ʱ��
	virtual bool SetLocalpTime(int pos, double value) = 0;
};

#endif
