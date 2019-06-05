// fivedefenselib.h: implement for the CFiveDefenseLib class.
#ifndef _FIVEDEFENSELIB_2009_09_22_PENGSHIKANG_H_
#define _FIVEDEFENSELIB_2009_09_22_PENGSHIKANG_H_

#include "../commgr/intfobjptra.h"      // for CIntfObjPtrA
#include "../../interface/fivedefense/ifivedefense.h" // for IFiveDefense

//DLL����Ľӿڶ�������
class CFiveDefenseLib : public CIntfObjPtrA<IFiveDefense>
{
public:
	CFiveDefenseLib() 
		: CIntfObjPtrA<IFiveDefense>(DLL_FIVEDEFENSE, CLSID_FIVEDEFENSE, IID_IFIVEDEFENSE)
	{
		m_pObj = CreateObject();
	}
	
	//����һ���µĽӿڶ�����
	IFiveDefense* CreateFiveDefense()
	{
		return CreateObject();
	}

private:
};

#endif 
