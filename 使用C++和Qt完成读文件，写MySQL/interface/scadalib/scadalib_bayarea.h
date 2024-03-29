/*********************************************************
 * scadalib_bayarea.h
 * contents: Ibayarea interface
 * date: 2009-09-23 code generated by scadalib_gen(hongkeqin@xjgc.com)
 *********************************************************/

#ifndef SCADALIB_bayarea_H_
#define SCADALIB_bayarea_H_

#include "../icsunknown.h"
#include "./scadalib_typedef.h"
#include "./irecordset.h"


//forward declarations
class Ibay;

class Ibayarea : public IRecordSet
{
public:
	//associations
	virtual Ibay* Relevantbay() = 0;

	//
	virtual int Getid() = 0;

	virtual void Setid(int id) = 0;

	virtual int Getbayid() = 0;

	virtual void Setbayid(int bayid) = 0;

	virtual string_type Getareaid() = 0;

	virtual void Setareaid(const char* areaid) = 0;


};

#endif