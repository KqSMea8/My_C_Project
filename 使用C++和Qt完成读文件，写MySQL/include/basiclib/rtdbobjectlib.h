// rtdbobjectlib.h: implement for the CTaskIndexLib class.
#ifndef ICSRTDBOBJECTLIB_2018_06_20_PENGSHIKANG_H_
#define ICSRTDBOBJECTLIB_2018_06_20_PENGSHIKANG_H_

#include "../commgr/intfobjptrb.h"               // for CIntfObjPtrB
#include "../../interface/objsintf.h"            // for IICSRtdbObject

#define DLL_ICSRtdbObjectFD            "rtdbobjforfd"

//DLL输出的接口对象引用
class CRtdbObjectFD : public CIntfObjPtrB<IICSRtdbObject>
{
public:
	CRtdbObjectFD(const char* tblName) 
		: CIntfObjPtrB<IICSRtdbObject>(DLL_ICSRtdbObjectFD, false, CLSID_IICSCommonObject, IID_IICSRtdbObject)
	{
		m_pParams[0] = (void*)tblName; //实时库数据表名称
		m_pParams[1] = 0;       //备用指针
		m_pParams[2] = 0;       //备用指针
		m_pParams[3] = 0;       //备用指针
		this->m_pObj = CreateObject(m_pParams);
	}
	
	//创建一个新的接口对象保留
	IICSRtdbObject* CreateRtdbObject(const char* tblName)
	{
		m_pParams[0] = (void*)tblName; //实时库数据表名称
		m_pParams[1] = 0;       //备用指针
		m_pParams[2] = 0;       //备用指针
		m_pParams[3] = 0;       //备用指针
		return CreateObject(m_pParams);
	}

private:
	void* m_pParams[4];
};

#endif 
