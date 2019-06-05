#ifndef _IDATASEND_PENGSHIKANG_20150515__H_
#define _IDATASEND_PENGSHIKANG_20150515__H_

#include "../icsunknown.h"                       // for IICSUnknown
#include "../icsvalue.h"                         // for icsvariant 
#include "dispatchtaskdata.h"                    // for DispatchTaskData

#define DATASEND_CLASSID      "cidatasend"
#define DATASEND_INTFID       "idatasend"

class IDataSend : virtual public IICSUnknown 
{
public:
	//1. ֱ�ӷ�����Ϣ�����ȶ�
	//1.1 ����ģ���������ȶ�
	virtual bool SendAnalogToMSCCenter(int id, double dValue, double timestamp) = 0;
	//1.2 ����״̬�������ȶ�
	virtual bool SendStatusToMSCCenter(int id, int nValue, int nQuality, double timestamp) = 0;
	//1.3 �����ۼ��������ȶ�
	virtual bool SendAccumuToMSCCenter(int id, double dValue, double timestamp) = 0;
	//1.4 ���ͼ����������ȶ�
	virtual bool SendExprcalToMSCCenter(int id, double dValue, double timestamp) = 0;
	//1.5 ���Ϳ��ƽ�������ȶ�
	virtual bool SendCtrlResultToMSCCenter(unsigned char msgType) = 0;
	//1.6 ���Ϳ����������װ��
	virtual bool SendControlToMSCCenter(int id, int nValue, bool isDouble=false) = 0;

	//2. ����ȶ˷��ͺ�̨���ݴ���������ߵ�֪ͨ
	virtual bool SendDataServerOnlineNotice() = 0;

	//3. ��������ֵ���� ���ڼ������ 
	//3.1 ��������������ֵ����
	virtual DispatchSetting* CreateDispatchValue(short taskType, int dataValue, int saveValue=0, int toHisSave=0, int senderType=0, const char* senderName="") = 0;
	//3.2 ��������ʵ����ֵ����
	virtual DispatchSetting* CreateDispatchValue(short taskType, float dataValue, int toHisSave=0, int senderType=0, const char* senderName="") = 0;
	//3.3 ��������ʵʱ��-���ÿ�ͬ����sql����
	virtual DispatchSetting* CreateDispatchValue(int toHisSave=0,const char* sql="") = 0;

	//4. ͨ�������Ķ��н��̷��͵���ѹ��ֵ�����ȶ�
	//4.1 ��ӵ���ѹ��ֵ������
	virtual void PushDispatchValue(DispatchSetting* dispValue) = 0;
	//4.2 ���͵���ѹ��ֵ�����ȶ�
	virtual bool PopDispatchValue(DispatchSetting* dispValue) = 0;

	//5. ֱ�ӷ��͵��Ƚ��
	//5.1 ���͵��Ƚ�������ƿͻ��˶�
	virtual bool SendControlResult(const char* sClient, short taskType, bool bSuccessed) = 0;
	//5.2 ���͵��Ƚ�������ȶ�
	virtual bool SendDispatchResult(short taskType, bool bSuccessed) = 0;

	//6. ֱ�ӷ���ѹ�塢����״̬����Ϣ�����ȶ�
	//6.1 ���͵���ѹ����ֵ�����ȶ�
	virtual bool SendDispatchSwitchValue(int updateInfo, int switchValue) = 0;
	//6.2 ���͵��Ƚ�����ͣ״̬�����ȶ�
	virtual bool SendDispatchEmergeValue(bool isSupport, int emergeValue) = 0;
	//6.3 ����ѹ�������ͱ���ѹ��ֵ�����ȶ�
	virtual bool SendLocalSwitchValue(int localFlag) = 0;
	//6.4 AVC����ѹ�������ͱ���ѹ��ֵ�����ȶ�--��ʱ����ģ�ͣ�Ҳ��Զ������ѹ�壬�����ٽ�AGC/AVC�ı���ѹ��ֿ�
	virtual bool SendAVCLocalSwitchValue(int localFlag) = 0;

	//7. ��ҵ�����ݷ��͵����ȶ�
	//7.1 �����޹��ɵ���/���ޡ�����/���޹����޹���/�µ��ڱ�����־�����ȶ�  2016.4.7����
	virtual bool SendAVCAdjustParaValue() = 0;
	//7.2 ����AGC��ز��������ȶ�  2016.8.22����
	//���й��ɵ���/���ޡ�����/���й����й�������/��������־���ɵ����������������ʧ�й����ʡ��й���������������־�����ɷ����־��
	virtual bool SendAGCAdjustParaValue() = 0;
};

#endif
