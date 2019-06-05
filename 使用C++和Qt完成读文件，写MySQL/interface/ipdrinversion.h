#ifndef IPDRINVERSION_H_
#define IPDRINVERSION_H_

#include "../include/common/intfobject.h"

#define DLL_PDRINVERSION	"pdrinversion"
#define IID_PDRINVERSION	"IPdrInversion"
#define CID_PDRINVERSION	"CPdrInversion"

#include <vector>

class IPdrInversion: public CIntfObject
{
public:
	virtual void setInversion() = 0;
};

#endif