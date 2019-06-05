//itransyddao.h

#ifndef _ITRANSYDDAO_WANGXIA_20140403_H_
#define _ITRANSYDDAO_WANGXIA_20140403_H_

#include "../ibasicdao.h"                        // for IBasicDao

#define TRANSYDDAO_CLASSID    "ctransyddao"
#define TRANSYDDAO_INTFID     "itransyddao"

class ITransydDao : virtual public IBasicDao
{
public:
	//����Զ��ת����λ�õõ���ң�������
	virtual int GetMeasType(int pos) = 0;
	//����Զ��ת����λ�õõ���ң���ID
	virtual int GetMeasId(int pos) = 0;
	//����Զ��ת����λ�õõ�ASDU����
	virtual int GetMsgType(int pos) = 0;

	//����Զ��ת����λ�õõ�AVCװ�õ�ַ
	virtual int GetIedAddr(int pos) = 0;
	//����Զ��ת����λ�õõ�AVC��Ϣ��ַ
	virtual int GetInfoAddr(int pos) = 0;
	//����Զ��ת����λ�õõ�AVC������ַ
	virtual int GetSecAddr(int pos) = 0;

	//����Զ��ת����λ�õõ��ɼ�Դ��
	virtual int GetSourceNo(int pos) = 0;
	//����Զ��ת����λ�õõ��ɼ����
	virtual int GetDotId(int pos) = 0;

	//����Զ��ת����λ�õõ�ת��ϵ��
	virtual double GetFactor(int pos) = 0;
};

#endif
