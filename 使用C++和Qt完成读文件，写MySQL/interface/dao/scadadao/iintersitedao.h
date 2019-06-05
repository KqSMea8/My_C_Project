//iintersitedao.h

#ifndef _IINTERSITEDAO_WANGXIA_20140403_H_
#define _IINTERSITEDAO_WANGXIA_20140403_H_

#include "../ibasicdao.h"                        // for IBasicDao

#define INTERSITEDAO_CLASSID    "cintersitedao"
#define INTERSITEDAO_INTFID     "iintersitedao"

class IIntersiteDao : virtual public IBasicDao
{
public:
	//����ת��վ��λ�õõ�ת��վ������
	virtual const char* GetDescription(int pos) = 0;

	//����ת��վ��λ�õõ�ת��վ�����ͣ�2--SCADAת��վ�㣨SCADANODETYPE����6--Զ��ת��վ�㣨RTUNODETYPE����8--���ת��վ�㣨FDNODETYPE����
	virtual int GetType(int pos) = 0;

	//����ת��վ��λ�õõ�IP��ַ1
	virtual const char* GetIpAddr1(int pos) = 0;
	//����ת��վ��λ�õõ�IP��ַ2
	virtual const char* GetIpAddr2(int pos) = 0;

	//����ת��վ��λ�õõ��˿ں�1
	virtual int GetPort1(int pos) = 0;
	//����ת��վ��λ�õõ��˿ں�2
	virtual int GetPort2(int pos) = 0;

	//����ת��վ��λ�õõ�ת��վ��1״̬
	virtual int GetNetState1(int pos) = 0;
	//����ת��վ��λ�õõ�ת��վ��2״̬
	virtual int GetNetState2(int pos) = 0;

	//����ת��վ��ID��IP����ת��վ��״̬
	virtual bool SetNetState(int id, const char* strIp, int iState) = 0;
};

#endif
