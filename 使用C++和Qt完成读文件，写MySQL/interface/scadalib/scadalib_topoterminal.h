/*********************************************************
 * scadalib_topoterminal.h
 * contents: Itopoterminal interface
 * date: 2009-09-23 code generated by scadalib_gen(hongkeqin@xjgc.com)
 *********************************************************/

#ifndef SCADALIB_topoterminal_H_
#define SCADALIB_topoterminal_H_

#include "../icsunknown.h"
#include "./scadalib_typedef.h"
#include "./irecordset.h"


//forward declarations
class Itopoconnnode;
class Itopoequip;

class Itopoterminal : public IRecordSet
{
public:
	//associations
	virtual Itopoconnnode* Relevantconnnode() = 0;

	virtual Itopoequip* Relevantequipment() = 0;

	//
	virtual int Getid() = 0;

	virtual void Setid(int id) = 0;

	virtual int Getequipmentid() = 0;

	virtual void Setequipmentid(int equipmentid) = 0;

	virtual int Getconnnodeid() = 0;

	virtual void Setconnnodeid(int connnodeid) = 0;

	virtual string_type Getname() = 0;

	virtual void Setname(const char* name) = 0;

	virtual int Getterminalno() = 0;

	virtual void Setterminalno(int terminalno) = 0;

	virtual int Getterminaltype() = 0;

	virtual void Setterminaltype(int terminaltype) = 0;

	virtual int Getdeleteflag() = 0;

	virtual void Setdeleteflag(int deleteflag) = 0;

	virtual int Getjointnum() = 0;

	virtual void Setjointnum(int jointnum) = 0;


};

#endif