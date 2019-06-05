// fivedefensenewlib.h: implement for the CFiveDefenseNewLib class.
#ifndef _FIVEDEFENSENEWLIB_2014_04_04_PENGSHIKANG_H_
#define _FIVEDEFENSENEWLIB_2014_04_04_PENGSHIKANG_H_

#include "../commgr/intfobjptrb.h"               // for CIntfObjPtrB
#include "../../interface/fivedefense/idatatransfer.h" // for IDataTransfer

//DLL����Ľӿڶ�������
class CFiveDefenseNewLib : public CIntfObjPtrB<IDataTransfer>
{
public:
	CFiveDefenseNewLib(IDataTransferCallBack* pCallback, const char* familyName) 
		: CIntfObjPtrB<IDataTransfer>(DLL_DATATRANSFER, false, CLSID_DATATRANSFER, IID_DATATRANSFER)
	{
		void* pParams[2];
		pParams[0] = (void*)pCallback;     //�ͻ���ģ���ʶ
		pParams[1] = (void*)familyName;    //�û�ָ��
		m_pObj = CreateObject(pParams);
	}
	
	//����һ���µĽӿڶ�����
	/*IDataTransfer* CreateFDDataTransfer()
	{
		return CreateObject();
	}*/

private:
};

#endif 
