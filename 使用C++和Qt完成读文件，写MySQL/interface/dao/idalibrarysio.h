//idalibraryio.h

#ifndef _IDATAACCESSLIBRARYINPUTOUTPUT_PENGSHIKANG_20131206_H_
#define _IDATAACCESSLIBRARYINPUTOUTPUT_PENGSHIKANG_20131206_H_

#include "../icsunknown.h"

#define DALIBRARYIO_CLASSID   "cdalibraryio"
#define DALIBRARYIO_INTFID    "idalibraryio"

class IDALibrary;

class IDALibrarysIO : virtual public IICSUnknown
{
public:
	//�������ݿ����ʵ��
	virtual void SetDALibraryEntitys(IDALibrary** ppLibrary, int nCount) = 0;
	//����Family���Ƶõ����ݿ����ʵ��
	virtual IDALibrary** GetDALibraryEntitysByFamilyName(const char* familyName, const char* paraFamilys) = 0;
};

#endif
