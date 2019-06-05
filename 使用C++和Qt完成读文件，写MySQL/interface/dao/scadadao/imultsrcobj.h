//imultsrcobj.h
#ifndef _IMULTSRCOBJ_PENGSHIKANG_20090421_H_
#define _IMULTSRCOBJ_PENGSHIKANG_20090421_H_

class IMultSrcObj
{
public:
	virtual const int GetPriority() = 0;
	virtual const int GetPosition() = 0;
	virtual const int GetCommSrcId() = 0;
	virtual const int GetCommPointId() = 0;
	
	virtual const bool operator < (IMultSrcObj& obj) = 0;
	virtual const bool operator > (IMultSrcObj& obj) = 0;
	virtual const bool operator == (IMultSrcObj& obj) = 0;
	virtual const bool operator <= (IMultSrcObj& obj) = 0;
	virtual const bool operator >= (IMultSrcObj& obj) = 0;
	virtual const bool operator != (IMultSrcObj& obj) = 0;
};

#endif
