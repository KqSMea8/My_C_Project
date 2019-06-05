/*********************************************************
 * scadalib_settingarea.h
 * contents: Isettingarea interface
 * date: 2009-09-23 code generated by scadalib_gen(hongkeqin@xjgc.com)
 *********************************************************/

#ifndef SCADALIB_settingarea_H_
#define SCADALIB_settingarea_H_

#include "../icsunknown.h"
#include "./scadalib_typedef.h"
#include "./irecordset.h"


//forward declarations
class Isetting;

class Isettingarea : public IRecordSet
{
public:
	//associations
	virtual Isetting* Relevantsetting() = 0;

	//
	virtual int Getid() = 0;

	virtual void Setid(int id) = 0;

	virtual int Getsettingid() = 0;

	virtual void Setsettingid(int settingid) = 0;

	virtual int Getsettingarea() = 0;

	virtual void Setsettingarea(int settingarea) = 0;

	virtual string_type Getsettingvalue() = 0;

	virtual void Setsettingvalue(const char* settingvalue) = 0;

	virtual int Getdeleteflag() = 0;

	virtual void Setdeleteflag(int deleteflag) = 0;


};

#endif