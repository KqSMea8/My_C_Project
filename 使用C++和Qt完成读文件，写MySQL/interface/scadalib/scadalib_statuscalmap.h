/*********************************************************
 * scadalib_statuscalmap.h
 * contents: Istatuscalmap interface
 * date: 2009-09-23 code generated by scadalib_gen(hongkeqin@xjgc.com)
 *********************************************************/

#ifndef SCADALIB_statuscalmap_H_
#define SCADALIB_statuscalmap_H_

#include "../icsunknown.h"
#include "./scadalib_typedef.h"
#include "./irecordset.h"


//forward declarations
class Iexprcal;
class Istatus;

class Istatuscalmap : public IRecordSet
{
public:
	//associations
	virtual Iexprcal* Relevantexpcal() = 0;

	virtual Istatus* Relevant() = 0;

	//
	virtual int Getid() = 0;

	virtual void Setid(int id) = 0;

	virtual int Getexpcalid() = 0;

	virtual void Setexpcalid(int expcalid) = 0;


};

#endif