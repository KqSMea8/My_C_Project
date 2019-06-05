//idalibraryio.h

#ifndef _IDATAACCESSLIBRARYINPUTOUTPUT_PENGSHIKANG_20131206_H_
#define _IDATAACCESSLIBRARYINPUTOUTPUT_PENGSHIKANG_20131206_H_

#include "../icsunknown.h"

#define DALIBRARYIO_CLASSID   "cdalibraryio"
#define DALIBRARYIO_INTFID    "idalibraryio"

class IDALibrary;

class IDALibraryIO : virtual public IICSUnknown
{
public:
	//得到数据库访问实体
	virtual IDALibrary* GetDALibraryEntity(const char* procName=0) = 0;
	//设置数据库访问实体
	virtual void SetDALibraryEntity(IDALibrary* pLibrary) = 0;
	//根据Family名称得到数据库访问实体
	virtual IDALibrary* GetDALibraryEntityByFamilyName(const char* familyName) = 0;
};

#endif
