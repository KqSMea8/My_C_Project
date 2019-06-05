// ihiscfgtrans.h
#ifndef _IHISCFGTRANS_H_
#define _IHISCFGTRANS_H_

//#include "icsunknown.h" // for IICSUnknown
#include "../include/common/intfobject.h"

#define DLL_HISCFGTRANS	"hiscfgtrans"
#define IID_HISCFGTRANS	"IHisCfgTrans"
#define CID_HISCFGTRANS	"CHisCfgTrans"

#include <vector>

class IHisCfgTrans: public CIntfObject
{
public:

	/*
	 �����״�ͬ��
	 0.�ɹ���1.��ȡicssettingʧ�ܣ�2.�������ÿ�ʧ�ܣ�3.������ʷ��1ʧ�ܣ�4.������ʷ��2ʧ�ܣ�
	 5.��ʷ��1sql���ִ��ʧ�ܣ�6.��ʷ��2sql���ִ��ʧ��;7.��ȡhdbsynchro.sqlʧ��
	 */
	virtual int HisCfgdataTrans() = 0; 

	/*
	���ÿ����ݸ���
	0.�ɹ���1.��ȡicssettingʧ�ܣ�2.�������ÿ�ʧ�ܣ�3.������ʷ��1ʧ�ܣ�4.������ʷ��2ʧ�ܣ�
	5.��ʷ��1sql���ִ��ʧ�ܣ�6.��ʷ��2sql���ִ��ʧ��;7.��ȡhdbsynchro.sqlʧ��
	*/
	virtual int updateCfg() = 0; 

};

#endif
