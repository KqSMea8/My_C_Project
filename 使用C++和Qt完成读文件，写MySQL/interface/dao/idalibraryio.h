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
	//�õ����ݿ����ʵ��
	virtual IDALibrary* GetDALibraryEntity(const char* procName=0) = 0;
	//�������ݿ����ʵ��
	virtual void SetDALibraryEntity(IDALibrary* pLibrary) = 0;
	//����Family���Ƶõ����ݿ����ʵ��
	virtual IDALibrary* GetDALibraryEntityByFamilyName(const char* familyName) = 0;
};

#endif
