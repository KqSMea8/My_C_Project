/*********************************************************
 * scadalib_tagtype.h
 * contents: Itagtype interface
 * date: 2009-09-23 code generated by scadalib_gen(hongkeqin@xjgc.com)
 *********************************************************/

#ifndef SCADALIB_tagtype_H_
#define SCADALIB_tagtype_H_

#include "../icsunknown.h"
#include "./scadalib_typedef.h"
#include "./irecordset.h"



class Itagtype : public IRecordSet
{
public:
	virtual int Getid() = 0;

	virtual void Setid(int id) = 0;

	virtual string_type Getpicturepath() = 0;

	virtual void Setpicturepath(const char* picturepath) = 0;

	virtual string_type Getname() = 0;

	virtual void Setname(const char* name) = 0;

	virtual string_type Getdescription() = 0;

	virtual void Setdescription(const char* description) = 0;


};

#endif