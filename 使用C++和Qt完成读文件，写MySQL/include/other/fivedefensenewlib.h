// fivedefensenewlib.h: implement for the CFiveDefenseNewLib class.
#ifndef _FIVEDEFENSENEWLIB_2014_04_04_PENGSHIKANG_H_
#define _FIVEDEFENSENEWLIB_2014_04_04_PENGSHIKANG_H_

#include "../commgr/intfobjptrb.h"               // for CIntfObjPtrB
#include "../../interface/fivedefense/idatatransfer.h" // for IDataTransfer

//DLL输出的接口对象引用
class CFiveDefenseNewLib : public CIntfObjPtrB<IDataTransfer>
{
public:
	CFiveDefenseNewLib(IDataTransferCallBack* pCallback, const char* familyName) 
		: CIntfObjPtrB<IDataTransfer>(DLL_DATATRANSFER, false, CLSID_DATATRANSFER, IID_DATATRANSFER)
	{
		void* pParams[2];
		pParams[0] = (void*)pCallback;     //客户端模块标识
		pParams[1] = (void*)familyName;    //用户指针
		m_pObj = CreateObject(pParams);
	}
	
	//创建一个新的接口对象保留
	/*IDataTransfer* CreateFDDataTransfer()
	{
		return CreateObject();
	}*/

private:
};

#endif 
