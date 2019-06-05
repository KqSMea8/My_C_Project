//ictrlvaltypdao.h

#ifndef _ICTRLVALUETYPEDAO_PENGSHIKANG_20130310_H_
#define _ICTRLVALUETYPEDAO_PENGSHIKANG_20130310_H_

#include "../ibasicdao.h"                        // for IBasicDao
#include "../../scadasrv/scadadatadef.h"         // for OPERATETYPE

#define CTRLVALTYPDAO_CLASSID    "cctrlvaltypdao"
#define CTRLVALTYPDAO_INTFID     "ictrlvaltypdao"


class ICtrlValTypDao : virtual public IBasicDao
{
public:
	//�Ƿ�Ϊ���ڿ�����ʶ��ң�ز������͵�ģʽ
	virtual bool IsControlCodeMode() = 0;

	//����ң�������ͺ�ң������ֵ�õ�ң��ֵ���ͼ�¼λ��
	virtual int GetPositionByOperateValue(int nMeasType, int nValue) = 0;
	
	//����ң�������ͺͲ������͵õ�ң����ֵ���ͼ�¼λ��
	virtual int GetPositionByOperateType(int nMeasType, OPERATETYPE nOprtType) = 0;
	
	//����ң�������ͺͲ������͵õ�ң������ֵ
	virtual int GetValueByOperateType(int nMeasType, OPERATETYPE nOprtType) = 0;
	
	//����ң��ֵ������λ�õõ�ң��ֵ
	virtual int GetCtrlValue(int pos) = 0;
	//����ң��ֵ������λ�õõ�ң������
	virtual OPERATETYPE GetCtrlType(int pos) = 0;
	//����ң��ֵ������λ�õõ��澯��ʽID
	virtual int GetAlarmId(int pos) = 0;
	//����ң��ֵ������λ�õõ�����ֵ�Ƿ�ΪĿ��ֵ
	virtual int GetJudgeAimval(int pos) = 0;
	//����ң��ֵ������λ�õõ�ң�ط���Ŀ��ֵ
	virtual int GetAimval(int pos) = 0;	
	//����ң��ֵ������λ�õõ����������
	virtual int GetMeasTypeId(int pos) = 0;
};

#endif
