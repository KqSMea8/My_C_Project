// settingdaolib.h: implement for the CSettingDao class.
#ifndef _SETTINGDAOLIB_20130311_PENGSHIKANG_H_
#define _SETTINGDAOLIB_20130311_PENGSHIKANG_H_

#include "../../../commgr/intfobjptrb.h"       // for CIntfObjPtrB
#include "../../../../interface/dao/scadadao/csfdao/isettingdao.h"    // for ISettingDao

//DLL����Ľӿڶ�������
class CSettingDao : public CIntfObjPtrB<ISettingDao>
{
public:
	CSettingDao() : CIntfObjPtrB<ISettingDao>
		(SCADADAO_MODULE, SETTINGDAO_CLASSID, SETTINGDAO_INTFID) { }
};

#endif 