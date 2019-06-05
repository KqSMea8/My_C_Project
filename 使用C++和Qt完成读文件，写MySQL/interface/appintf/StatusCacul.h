//--------------------------------------------------------StatusCacul.h-----------------------------------------------//

#ifndef _ICS_INCLUDE_STATUSCACUL_H_
#define _ICS_INCLUDE_STATUSCACUL_H_

#include "icsunknown.h"
#include "objsintf.h"

#define IID_IStatusCacul "IStatusCacul"
#define MODULE_STATUSTR	 "statustr"

class IStatusCacul;

typedef bool (*RegisterStatusCacul)(IStatusCacul* pCacul);

#define METHOD_REGISTERSTATUSCACUL "RegisterCacul"

class IStatusCacul : public IICSUnknown
{
public:
	virtual bool Cacul(ITaskObject * pOldStatus, ITaskObject* pNewStatus, int* value, int quality, double dt)=0;
};

#endif
