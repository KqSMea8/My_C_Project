/*********************************************************
 * scadalib_topoline.h
 * contents: Itopoline interface
 * date: 2009-09-23 code generated by scadalib_gen(hongkeqin@xjgc.com)
 *********************************************************/

#ifndef SCADALIB_topoline_H_
#define SCADALIB_topoline_H_

#include "../icsunknown.h"
#include "./scadalib_typedef.h"
#include "./irecordset.h"


//forward declarations
class Itopoequip;
class Itopoisland;

class Itopoline : public IRecordSet
{
public:
	//associations
	virtual Itopoequip* Relevanttopoequip() = 0;

	virtual Itopoisland* Relevanttopoisland() = 0;

	//
	virtual int Getid() = 0;

	virtual void Setid(int id) = 0;

	virtual int Gettopoequipid() = 0;

	virtual void Settopoequipid(int topoequipid) = 0;

	virtual int Gettopoislandid() = 0;

	virtual void Settopoislandid(int topoislandid) = 0;

	virtual string_type Getname() = 0;

	virtual void Setname(const char* name) = 0;

	virtual int Getterminalid1() = 0;

	virtual void Setterminalid1(int terminalid1) = 0;

	virtual int Getterminalid2() = 0;

	virtual void Setterminalid2(int terminalid2) = 0;

	virtual int Gettoponodeid1() = 0;

	virtual void Settoponodeid1(int toponodeid1) = 0;

	virtual int Gettoponodeid2() = 0;

	virtual void Settoponodeid2(int toponodeid2) = 0;


};

#endif