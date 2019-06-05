//imodelctrldao.h

#ifndef _IMODELCTRLDAO_SUNRUI_20130311_H_
#define _IMODELCTRLDAO_SUNRUI_20130311_H_

#include "../ibasicdao.h"                        // for IBasicDao
#include "../../icsvalue.h"                      // for intarray

#define MODELCTRLDAO_CLASSID    "cmodelctrldao"
#define MODELCTRLDAO_INTFID     "imodelctrldao"

class IModelCtrlDao  : virtual public IBasicDao 
{
public:
	//����ģʽ�л�λ�õõ�ԭ����ģʽID
	virtual int GetPriModelID(int pos) = 0;
	//����ģʽ�л�λ�õõ�Ŀ������ģʽID
	virtual int GetAimModelID(int pos) = 0;

	//����ԭģʽID��Ŀ��ģʽID�õ�ģʽ�л�ID
	virtual int GetModelCtrlPos(int priid, int aimid) = 0;
	//����ģʽ�л�λ�ô�����բ�����б�ֵ(�������ȼ���ֵ��С��������)
	virtual bool CreateStyleCtrlList(int id, intarray& posList) = 0;
	//����ģʽ�л�λ�õõ�˳�����ID
	virtual int GetSQCtrlID(int pos) = 0;
};

#endif
