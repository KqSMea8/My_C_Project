/*********************************************************
 * scadalib_measclass.h
 * contents: Imeasclass interface
 * date: 2009-09-23 code generated by scadalib_gen(hongkeqin@xjgc.com)
 *********************************************************/

#ifndef SCADALIB_measclass_H_
#define SCADALIB_measclass_H_

#include "../icsunknown.h"
#include "./scadalib_typedef.h"
#include "./irecordset.h"


//forward declarations
class Idataclass;

class Imeasclass : public IRecordSet
{
public:
	//associations
	virtual Idataclass* Relevantdaclass() = 0;

	//
	virtual int Getid() = 0;

	virtual void Setid(int id) = 0;

	virtual string_type Getname() = 0;

	virtual void Setname(const char* name) = 0;

	virtual int Getdaclassid() = 0;

	virtual void Setdaclassid(int daclassid) = 0;

	virtual string_type Getcode() = 0;

	virtual void Setcode(const char* code) = 0;


};

#endif