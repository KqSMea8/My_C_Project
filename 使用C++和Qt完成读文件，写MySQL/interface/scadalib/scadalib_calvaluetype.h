/*********************************************************
 * scadalib_calvaluetype.h
 * contents: Icalvaluetype interface
 * date: 2009-09-23 code generated by scadalib_gen(hongkeqin@xjgc.com)
 *********************************************************/

#ifndef SCADALIB_calvaluetype_H_
#define SCADALIB_calvaluetype_H_

#include "../icsunknown.h"
#include "./scadalib_typedef.h"
#include "./irecordset.h"



class Icalvaluetype : public IRecordSet
{
public:
	virtual int Getid() = 0;

	virtual void Setid(int id) = 0;

	virtual string_type Getname() = 0;

	virtual void Setname(const char* name) = 0;


};

#endif