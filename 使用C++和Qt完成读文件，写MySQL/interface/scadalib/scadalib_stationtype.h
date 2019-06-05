/*********************************************************
 * scadalib_stationtype.h
 * contents: Istationtype interface
 * date: 2009-09-23 code generated by scadalib_gen(hongkeqin@xjgc.com)
 *********************************************************/

#ifndef SCADALIB_stationtype_H_
#define SCADALIB_stationtype_H_

#include "../icsunknown.h"
#include "./scadalib_typedef.h"
#include "./irecordset.h"



class Istationtype : public IRecordSet
{
public:
	virtual int Getid() = 0;

	virtual void Setid(int id) = 0;

	virtual string_type Getname() = 0;

	virtual void Setname(const char* name) = 0;


};

#endif