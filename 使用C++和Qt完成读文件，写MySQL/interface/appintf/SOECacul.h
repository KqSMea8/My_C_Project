//---------------------------------------------------------SOECacul.h------------------------------------------------------//

#ifndef _ICS_INCLUDE_SOECACUL_H_
#define _ICS_INCLUDE_SOECACUL_H_

#include "icsunknown.h"
#include "objsintf.h"

#define IID_ISOECacul	"ISOECacul"
#define MODULE_SOETR	"soetr"

class ISOECacul;

typedef bool (*RegisterSoeCacul)(ISOECacul* pCacul);

#define METHOD_REGISTERSOECACUL "RegisterCacul"

class ISOECacul : public IICSUnknown
{
public:
	virtual bool Cacul(ITaskObject * pOldStatus, ITaskObject* pNewStatus, int* pval, int quality, double span, char* face, double dt)=0;
	virtual bool Report(ITaskObject* pOldStatus, ITaskObject* pNewStatus, double* pval, int num, double dt)=0;
};

#endif
