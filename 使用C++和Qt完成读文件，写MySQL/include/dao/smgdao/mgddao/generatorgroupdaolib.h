// generatorgroupdaolib.h: implement for the CGeneratorGroupDao class.
#ifndef _GENERATORGROUPDAOLIB_20170117_PENGSHIKANG_H_
#define _GENERATORGROUPDAOLIB_20170117_PENGSHIKANG_H_

#include "../../../commgr/intfobjptrb.h"         // for CIntfObjPtrB
#include "../../../../interface/dao/smgdao/mgddao/igeneratorgroupdao.h"// for IGeneratorGroupDao

class IAnalogDao;
class IStatusDao;

//DLL输出的接口对象引用
class CGeneratorGroupDao : public CIntfObjPtrB<IGeneratorGroupDao>
{
public:
	CGeneratorGroupDao(IAnalogDao* pAnalog, IStatusDao* pStatus) : CIntfObjPtrB<IGeneratorGroupDao>
		(SMGDAO_MODULE, GENERATORGROUPDAO_CLASSID, GENERATORGROUPDAO_INTFID)
	{
		void* m_pParams[2];
		m_pParams[0] = (void*)pAnalog;
		m_pParams[1] = (void*)pStatus;
		m_pObj = CreateObject(m_pParams);
	}
};

#endif 
