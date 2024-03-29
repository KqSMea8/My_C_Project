/*********************************************************
 * scadalib_alarmpara.h
 * contents: Ialarmpara interface
 * date: 2009-09-23 code generated by scadalib_gen(hongkeqin@xjgc.com)
 *********************************************************/

#ifndef SCADALIB_alarmpara_H_
#define SCADALIB_alarmpara_H_

#include "../icsunknown.h"
#include "./scadalib_typedef.h"
#include "./irecordset.h"


//forward declarations
class Ialarm;

class Ialarmpara : public IRecordSet
{
public:
	//associations
	virtual Ialarm* Relevantalarm() = 0;

	//
	virtual int Getid() = 0;

	virtual void Setid(int id) = 0;

	virtual int Getalarmid() = 0;

	virtual void Setalarmid(int alarmid) = 0;

	virtual string_type Getname() = 0;

	virtual void Setname(const char* name) = 0;

	virtual string_type Getdescription() = 0;

	virtual void Setdescription(const char* description) = 0;

	virtual int Getdatatype() = 0;

	virtual void Setdatatype(int datatype) = 0;

	virtual int Getissave() = 0;

	virtual void Setissave(int issave) = 0;


};

#endif