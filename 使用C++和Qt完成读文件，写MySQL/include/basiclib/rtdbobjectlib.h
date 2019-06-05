// rtdbobjectlib.h: implement for the CTaskIndexLib class.
#ifndef ICSRTDBOBJECTLIB_2018_06_20_PENGSHIKANG_H_
#define ICSRTDBOBJECTLIB_2018_06_20_PENGSHIKANG_H_

#include "../commgr/intfobjptrb.h"               // for CIntfObjPtrB
#include "../../interface/objsintf.h"            // for IICSRtdbObject

#define DLL_ICSRtdbObjectFD            "rtdbobjforfd"

//DLL����Ľӿڶ�������
class CRtdbObjectFD : public CIntfObjPtrB<IICSRtdbObject>
{
public:
	CRtdbObjectFD(const char* tblName) 
		: CIntfObjPtrB<IICSRtdbObject>(DLL_ICSRtdbObjectFD, false, CLSID_IICSCommonObject, IID_IICSRtdbObject)
	{
		m_pParams[0] = (void*)tblName; //ʵʱ�����ݱ�����
		m_pParams[1] = 0;       //����ָ��
		m_pParams[2] = 0;       //����ָ��
		m_pParams[3] = 0;       //����ָ��
		this->m_pObj = CreateObject(m_pParams);
	}
	
	//����һ���µĽӿڶ�����
	IICSRtdbObject* CreateRtdbObject(const char* tblName)
	{
		m_pParams[0] = (void*)tblName; //ʵʱ�����ݱ�����
		m_pParams[1] = 0;       //����ָ��
		m_pParams[2] = 0;       //����ָ��
		m_pParams[3] = 0;       //����ָ��
		return CreateObject(m_pParams);
	}

private:
	void* m_pParams[4];
};

#endif 
