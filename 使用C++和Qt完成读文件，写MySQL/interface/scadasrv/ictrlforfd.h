/*******************************************************
 * ictrlforfd.h -- ����˿�����ҵ����ӿ�
 *******************************************************/

#ifndef __ICONTROLMAINLOGICFORFIVEDEFENSE_PENGSHIKANG_H_20150604
#define __ICONTROLMAINLOGICFORFIVEDEFENSE_PENGSHIKANG_H_20150604

class IControlForFD
{
public:
	//���װ������ִ��ѡ����
	virtual bool ExecuteSelectCmdForFD(int ctrlId, int oldValue, int newValue, bool isDouble) = 0;
	//���װ������ִ��ֱ����
	virtual bool ExecuteControlCmdForFD(int ctrlId, int oldValue, int newValue, bool isDouble) = 0;
	//���װ������ִ�г�����
	virtual bool ExecuteCancelCmdForFD(int ctrlId, int oldValue, int newValue, bool isDouble) = 0;
	//���װ�÷���ִ�в������
	virtual bool ExecuteResultBackFromFD(int ctrlId, bool bSuccess, double actTime) = 0;
};

#endif