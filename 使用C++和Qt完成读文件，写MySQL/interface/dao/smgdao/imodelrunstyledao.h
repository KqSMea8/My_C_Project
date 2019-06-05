//imodelrunstyledao.h

#ifndef _IMODELRUNSTYLEDAO_SUNRUI_20130311_H_
#define _IMODELRUNSTYLEDAO_SUNRUI_20130311_H_

#include "../ibasicdao.h"                        // for IBasicDao

#define MODELRUNSTYLEDAO_CLASSID    "cmodelrunstyledao"
#define MODELRUNSTYLEDAO_INTFID     "imodelrunstyledao"

class IModelRunStyleDao  : virtual public IBasicDao 
{
public:
	//��������ģʽ������Դ��ʽλ�õõ����з�ʽID
	virtual int GetRunStyleID(int pos) = 0;
	//��������ģʽ������Դ��ʽ�õ���������ģʽID
	virtual int GetModelStyleID(int pos) = 0;
};

#endif
