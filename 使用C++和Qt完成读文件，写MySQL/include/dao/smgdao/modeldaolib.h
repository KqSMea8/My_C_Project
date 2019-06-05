// modeldaolib.h: implement for the CModelDao class.
#ifndef _MODELDAOLIB_20131211_PENGSHIKANG_H_
#define _MODELDAOLIB_20131211_PENGSHIKANG_H_

#include "../../commgr/intfobjptrb.h"            // for CIntfObjPtrB
#include "../../../interface/dao/smgdao/imodeldao.h"// for IModelDao

class ISMicgridDao;
class ISysInfoDao;

//DLL输出的接口对象引用
class CModelDao : public CIntfObjPtrB<IModelDao>
{
public:
	CModelDao(ISMicgridDao* pSMicgrid, ISysInfoDao* pSysInfo) : CIntfObjPtrB<IModelDao>
		(SMGDAO_MODULE, MODELDAO_CLASSID, MODELDAO_INTFID) 
	{ 
		void* m_pParams[2];
		m_pParams[0] = (void*)pSMicgrid;
		m_pParams[1] = (void*)pSysInfo;
		m_pObj = CreateObject(m_pParams);
	}

};

#endif 
