//icommsrcdao.h

#ifndef _ICOMMSRCDAO_PENGSHIKANG_20130310_H_
#define _ICOMMSRCDAO_PENGSHIKANG_20130310_H_

#include "../ibasicdao.h"                        // for IBasicDao

#define COMMSRCDAO_CLASSID    "ccommsrcdao"
#define COMMSRCDAO_INTFID     "icommsrcdao"

class ICommSrcDao : virtual public IBasicDao
{
public:	
	//�������ݲɼ�ԴID�õ��ɼ�Դ��վ����
	virtual const char* GetNameById(int id) = 0;
	//�õ����ݲɼ�Դ��ͨ��״̬
	virtual int GetCommSrcState(int pos, bool isAChnl=true) = 0;
	virtual bool IsConnected(int pos) = 0;
	//�������ݲɼ�Դ��ͨ��״̬
	virtual bool SetCommSrcState(int pos, int state) = 0;
	virtual bool SetCommSrcState2(int pos, int state) = 0;
	//�������ݲɼ�Դ��ʼ״̬��ϢΪ0
	virtual void InitializeSatate() = 0;

	//�������ݲɼ�Դλ�õõ��������ID
	virtual int GetBayId(int pos) = 0;
	//�������ݲɼ�Դλ�õõ�������վID
	virtual int GetStationId(int pos) = 0;

	//�Ƿ����˫Դ
	virtual bool IsMultCommSrc(int pos) = 0;
	//�õ�ͬ������ԴID
	virtual int GetBrotherSrcId(int pos) = 0;
	//�õ�ͬ������Դλ��+
	virtual int GetBrotherSrcPos(int pos) = 0;
	//����״̬��״̬��ID
	virtual int GetRoleStatusID(int pos) = 0;
	//�Ƿ�Ϊ������Դ
	virtual bool IsMainCommsrcFlag(int pos) = 0;
	//����������Դ��־+
	virtual bool SetMainCommsrcFlag(int pos, bool isMain) = 0;
};

#endif
