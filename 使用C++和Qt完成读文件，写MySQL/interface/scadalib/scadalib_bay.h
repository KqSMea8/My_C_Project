/*********************************************************
 * scadalib_bay.h
 * contents: Ibay interface
 * date: 2009-09-23 code generated by scadalib_gen(hongkeqin@xjgc.com)
 *********************************************************/

#ifndef SCADALIB_bay_H_
#define SCADALIB_bay_H_

#include "../icsunknown.h"
#include "./scadalib_typedef.h"
#include "./irecordset.h"


//forward declarations
class Ivoltage;
class Ibay;
class Ibaytype;
class Istation;
class Ibay;

class Ibay : public IRecordSet
{
public:
	//associations
	virtual Ivoltage* Relevantvoltage() = 0;

	virtual Ibay* Relevanttobay() = 0;

	virtual Ibaytype* Relevantbaytype() = 0;

	virtual Istation* Relevantstation() = 0;

	virtual Ibay* Relevantsupbay() = 0;

	//
	virtual int Getid() = 0;

	virtual void Setid(int id) = 0;

	virtual int Getsupbayid() = 0;

	virtual void Setsupbayid(int supbayid) = 0;

	virtual int Getbaytypeid() = 0;

	virtual void Setbaytypeid(int baytypeid) = 0;

	virtual int Getvoltageid() = 0;

	virtual void Setvoltageid(int voltageid) = 0;

	virtual int Getstationid() = 0;

	virtual void Setstationid(int stationid) = 0;

	virtual int Gettobayid() = 0;

	virtual void Settobayid(int tobayid) = 0;

	virtual string_type Getcode() = 0;

	virtual void Setcode(const char* code) = 0;

	virtual string_type Getname() = 0;

	virtual void Setname(const char* name) = 0;

	virtual string_type Getdescription() = 0;

	virtual void Setdescription(const char* description) = 0;

	virtual string_type Getpathname() = 0;

	virtual void Setpathname(const char* pathname) = 0;

	virtual int Getproflag() = 0;

	virtual void Setproflag(int proflag) = 0;

	virtual int Getlockenable() = 0;

	virtual void Setlockenable(int lockenable) = 0;

	virtual int Getstatus() = 0;

	virtual void Setstatus(int status) = 0;

	virtual int Getfault() = 0;

	virtual void Setfault(int fault) = 0;

	virtual int Getalarm() = 0;

	virtual void Setalarm(int alarm) = 0;

	virtual int Getgzstate() = 0;

	virtual void Setgzstate(int gzstate) = 0;

	virtual int Getdeleteflag() = 0;

	virtual void Setdeleteflag(int deleteflag) = 0;

	virtual int Getreplacebayid() = 0;

	virtual void Setreplacebayid(int replacebayid) = 0;

	virtual string_type Getalarmpage() = 0;

	virtual void Setalarmpage(const char* alarmpage) = 0;

	virtual string_type Getfamily() = 0;

	virtual void Setfamily(const char* family) = 0;


};

#endif