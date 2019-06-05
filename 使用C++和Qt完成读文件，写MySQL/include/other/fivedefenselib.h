// fivedefenselib.h: implement for the CFiveDefenseLib class.
#ifndef _FIVEDEFENSELIB_2009_09_22_PENGSHIKANG_H_
#define _FIVEDEFENSELIB_2009_09_22_PENGSHIKANG_H_

#include "../commgr/intfobjptra.h"      // for CIntfObjPtrA
#include "../../interface/fivedefense/ifivedefense.h" // for IFiveDefense

//DLL输出的接口对象引用
class CFiveDefenseLib : public CIntfObjPtrA<IFiveDefense>
{
public:
	CFiveDefenseLib() 
		: CIntfObjPtrA<IFiveDefense>(DLL_FIVEDEFENSE, CLSID_FIVEDEFENSE, IID_IFIVEDEFENSE)
	{
		m_pObj = CreateObject();
	}
	
	//创建一个新的接口对象保留
	IFiveDefense* CreateFiveDefense()
	{
		return CreateObject();
	}

private:
};

#endif 
