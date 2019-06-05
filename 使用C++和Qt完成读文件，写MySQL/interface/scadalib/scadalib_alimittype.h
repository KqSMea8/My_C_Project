/*********************************************************
 * scadalib_alimittype.h
 * contents: Ialimittype interface
 * date: 2009-09-23 code generated by scadalib_gen(hongkeqin@xjgc.com)
 *********************************************************/

#ifndef SCADALIB_alimittype_H_
#define SCADALIB_alimittype_H_

#include "../icsunknown.h"
#include "./scadalib_typedef.h"
#include "./irecordset.h"



class Ialimittype : public IRecordSet
{
public:
	virtual int Getid() = 0;

	virtual void Setid(int id) = 0;

	virtual string_type Getname() = 0;

	virtual void Setname(const char* name) = 0;

	virtual int Getispercentum() = 0;

	virtual void Setispercentum(int ispercentum) = 0;

	virtual int Getperiodflag() = 0;

	virtual void Setperiodflag(int periodflag) = 0;

	virtual double Getdeadzone() = 0;

	virtual void Setdeadzone(double deadzone) = 0;

	virtual int Getdelaytime() = 0;

	virtual void Setdelaytime(int delaytime) = 0;

	virtual double Getbasevalue() = 0;

	virtual void Setbasevalue(double basevalue) = 0;

	virtual double Getuppervalue() = 0;

	virtual void Setuppervalue(double uppervalue) = 0;

	virtual double Getlowervalue() = 0;

	virtual void Setlowervalue(double lowervalue) = 0;

	virtual double Getuuppervalue() = 0;

	virtual void Setuuppervalue(double uuppervalue) = 0;

	virtual double Getllowervalue() = 0;

	virtual void Setllowervalue(double llowervalue) = 0;

	virtual int Getisfaultul() = 0;

	virtual void Setisfaultul(int isfaultul) = 0;

	virtual int Getisfaultuull() = 0;

	virtual void Setisfaultuull(int isfaultuull) = 0;

	virtual int Getupperalarmact() = 0;

	virtual void Setupperalarmact(int upperalarmact) = 0;

	virtual int Getloweralarmact() = 0;

	virtual void Setloweralarmact(int loweralarmact) = 0;

	virtual int Getuupperalarmact() = 0;

	virtual void Setuupperalarmact(int uupperalarmact) = 0;

	virtual int Getlloweralarmact() = 0;

	virtual void Setlloweralarmact(int lloweralarmact) = 0;

	virtual double Getuppervalue3() = 0;

	virtual void Setuppervalue3(double uppervalue3) = 0;

	virtual double Getlowervalue3() = 0;

	virtual void Setlowervalue3(double lowervalue3) = 0;

	virtual double Getuppervalue4() = 0;

	virtual void Setuppervalue4(double uppervalue4) = 0;

	virtual double Getlowervalue4() = 0;

	virtual void Setlowervalue4(double lowervalue4) = 0;

	virtual int Getisfault3() = 0;

	virtual void Setisfault3(int isfault3) = 0;

	virtual int Getisfault4() = 0;

	virtual void Setisfault4(int isfault4) = 0;

	virtual int Getupperalarmact3() = 0;

	virtual void Setupperalarmact3(int upperalarmact3) = 0;

	virtual int Getloweralarmact3() = 0;

	virtual void Setloweralarmact3(int loweralarmact3) = 0;

	virtual int Getupperalarmact4() = 0;

	virtual void Setupperalarmact4(int upperalarmact4) = 0;

	virtual int Getloweralarmac4() = 0;

	virtual void Setloweralarmac4(int loweralarmac4) = 0;


};

#endif