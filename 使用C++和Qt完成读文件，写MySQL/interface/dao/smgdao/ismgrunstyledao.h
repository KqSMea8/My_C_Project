// ismgrunstyledao.h: interface for the ISmgRunstyleDao class.

#ifndef _ISMGRUNSTYLESDAO_ZHANGPENG_20120810_H_
#define _ISMGRUNSTYLESDAO_ZHANGPENG_20120810_H_

#include "../ibasicdao.h"                        // for IBasicDao
#include "../../icsvalue.h"                      // for intarray

#define SMGRUNSTYLEDAO_CLASSID    "csmgrunstyledao"
#define SMGRUNSTYLEDAO_INTFID     "ismgrunstyledao"

class ISmgRunstyleDao  : virtual public IBasicDao 
{
public:
	//����΢����ID������Դ���͵õ�΢�������з�ʽλ��
	virtual int GetPositionByMgMainps(int mgId, int mpsFlag) = 0;
	//����ָ�����з�ʽID������Դ�б�ֵ
	virtual void SetMainGenIdList(int pos, intarray* pIdList) = 0;
	//�õ�ָ�����з�ʽλ�ô�������Դ�б�ֵ
	virtual bool CreateMainGenIdList(int pos, intarray& idList) = 0;
	
	//����΢�������з�ʽλ�õõ�����΢����
	virtual int GetMgId(int pos) = 0;
	//����΢�������з�ʽλ�õõ�����Դ����
	virtual int GetMainpsFlag(int pos) = 0;
	//����΢�������з�ʽλ�õõ��л���������
	virtual int GetCtrlAttr(int pos) = 0;
	//����΢�������з�ʽλ�õõ��Ƿ���Ҫ����Ԥ������
	virtual int GetCheckForecast(int pos) = 0;
	//����΢�������з�ʽλ�õõ�������˳�����ID
	virtual int GetBlackStartID(int pos) = 0;

};

#endif // !defined _SMGRUNSTYLESDAO_ZHANGPENG_20120810_H_
