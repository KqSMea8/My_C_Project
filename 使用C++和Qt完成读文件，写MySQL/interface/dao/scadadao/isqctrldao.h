//isqctrldao.h

#ifndef _ISQCTRLDAO_SUNRUI_20140425_H_
#define _ISQCTRLDAO_SUNRUI_20140425_H_

#include "../ibasicdao.h"                        // for IBasicDao
#include "../../icsvalue.h"                      // for intarray

#define SQCTRLDAO_CLASSID    "csqctrldao"
#define SQCTRLDAO_INTFID     "isqctrldao"

class ISqCtrlDao : virtual public IBasicDao
{
public:
	//����˳�ؼƻ�λ�ö�ȡ��������
	virtual int GetStartType(int pos) = 0;
	//����˳�ؼƻ�λ�ö�ȡ��������
	virtual const char* GetStartInfo(int pos) = 0;
	//����˳�ؼƻ�λ�ö�ȡ��������ID
	virtual int GetStartCycID(int pos) = 0;
	//����˳�ؼƻ�λ�ö�ȡ�Ƿ���ҪԤ��
	virtual int IsPreview(int pos) = 0;

	//����˳�ؼƻ�λ�ö�ȡ��ǰִ����
	virtual const char* GetOptUser(int pos) = 0;
	//����˳�ؼƻ�λ�ö�ȡ��ǰִ��״̬
	virtual int GetOptState(int pos) = 0;
	//����˳�ؼƻ�λ�����õ�ǰִ�н��
	virtual bool SetOptInfo(int pos, int nOptState, const char* actUser) = 0;
	//����˳�ؼƻ�λ�ö�ȡ��ǰ��������״̬��0������������������1����������ת��Ϊ���㣻2����ִ��˳�ز�����
	virtual int GetExpState(int pos) = 0;
	//����˳�ؼƻ�λ�����õ�ǰ��������״̬
	virtual bool SetExpState(int pos, int nExpState) = 0;

	//���ݶ�ʱ������ID�õ���Ӧ�Ķ�ʱִ��˳�ؼƻ���¼��
	virtual intarray* GetSqCtrlSetByTimerType(int nTimerId) = 0;

};

#endif
