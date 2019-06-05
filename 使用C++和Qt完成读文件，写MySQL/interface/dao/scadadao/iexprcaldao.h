//iexprcaldao.h

#ifndef _IEXPRCALDAO_PENGSHIKANG_20130310_H_
#define _IEXPRCALDAO_PENGSHIKANG_20130310_H_

#include "../ibasicdao.h"                        // for IBasicDao
#include "../../scadasrv/iexpressmap.h"          // for IExpressMap��ExpSet

#define EXPRCALDAO_CLASSID    "cexprcaldao"
#define EXPRCALDAO_INTFID     "iexprcaldao"

class IExprCalDao : virtual public IBasicDao
{
public:
	//���ù�ʽӳ�䴦�����
	virtual void SetExpressMap(IExpressMap* pExpressMap) = 0;

	//���ݶ�ʱ������ID�õ���Ӧ�Ĺ�ʽ�����¼��
	virtual ExpSet* GetExpSetByType(int nTypeId) = 0;
	
	//���ݹ�ʽ����λ�õõ���ʽ������Ϣ
	virtual bool GetExprConfigInfo(int pos, int& nTypeId, int& nEnable, int& nDelete) = 0;
	//���ݹ�ʽ����λ�õõ�������ʽ
	virtual const char* GetFormula(int pos) = 0;
	//����ǰ���ϴ���λ�õõ��Ƿ�ת����־
	virtual int GetDataTransFlag(int pos) = 0;

	//���ݹ�ʽ����λ�õõ�����ֵ
	virtual double GetCalValue(int pos) = 0;
	//���ݹ�ʽ����λ�õõ�����Ʒ������
	virtual int GetQuality(int pos) = 0;
	//���ݹ�ʽ����λ�õõ���ǰʱ��
	virtual double GetCurTime(int pos) = 0;
	
	//���ݹ�ʽ����λ�õõ���ʽ������
	virtual bool GetExprCalValue(int pos, double& calValue, double& calTime, int& nQuality) = 0;
	//���ݹ�ʽ����ID�õ���ʽ������
	virtual bool GetExprCalValueById(int id, double& calValue, double& calTime, int& nQuality) = 0;
	//���ݹ�ʽ����λ�����ù�ʽ������
	virtual bool SetExprCalValue(int pos, double calValue, double calTime, int nQuality) = 0;	
};

#endif
