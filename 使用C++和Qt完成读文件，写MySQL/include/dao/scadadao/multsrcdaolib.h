// multsrcdaolib.h: implement for the CMultSrcDao class.
#ifndef _MULTSRCDAOLIB_20130311_PENGSHIKANG_H_
#define _MULTSRCDAOLIB_20130311_PENGSHIKANG_H_

#include "../../commgr/intfobjptrb.h"            // for CIntfObjPtrB
#include "../../../interface/dao/scadadao/imultsrcdao.h"   // for IMultSrcDao

//DLL����Ľӿڶ�������
class CMultSrcDao : public CIntfObjPtrB<IMultSrcDao>
{
public:
	CMultSrcDao(const char* tableName, const char* idFldName) : CIntfObjPtrB<IMultSrcDao>
		(SCADADAO_MODULE, false, MULTSRCDAO_CLASSID, MULTSRCDAO_INTFID)
	{
		void* m_pParams[2];
		m_pParams[0] = (void*)tableName;//���ݱ�����
		m_pParams[1] = (void*)idFldName;//ID�ֶ�����
		m_pObj = CreateObject(m_pParams);
	}
};

#endif 