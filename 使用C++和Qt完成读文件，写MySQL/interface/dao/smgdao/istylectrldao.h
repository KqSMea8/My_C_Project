//istylectrldao.h

#ifndef _ISTYLECTRLDAO_SUNRUI_20130311_H_
#define _ISTYLECTRLDAO_SUNRUI_20130311_H_

#include "../ibasicdao.h"                        // for IBasicDao
#include "../../icsvalue.h"                      // for intarray

#define STYLECTRLDAO_CLASSID    "cstylectrldao"
#define STYLECTRLDAO_INTFID     "istylectrldao"

class IStyleCtrlDao  : virtual public IBasicDao 
{
public:
	//����΢������բ����λ�õõ��������з�ʽID
	virtual int GetRunStyleID(int pos) = 0;
	//����΢������բ����λ�õõ�������ID
	virtual int GetCtrlID(int pos) = 0;
	//����΢������բ����λ�õõ���������ֵ
	virtual int GetCtrlType(int pos) = 0;
	//����΢������բ����λ�õõ��������ȼ�
	virtual int GetPriority(int pos) = 0;
	//������բ�����б�
	virtual void CreateStyleList() = 0;
	//�õ�ģʽ�л�ID��Ӧ�����е�բ�������б�
	virtual bool GetStyleList(int switchmodelid, intarray& list) = 0;
	//�Ƿ����õ�բ����
	virtual bool CanStyleOpr(int switchmodelid) = 0;
};

#endif
