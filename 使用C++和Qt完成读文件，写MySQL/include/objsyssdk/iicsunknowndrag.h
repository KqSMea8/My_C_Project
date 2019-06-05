#ifndef __OBJECT_SYSTEM_OBJECTDRAG_H_INCLUDED__
#define __OBJECT_SYSTEM_OBJECTDRAG_H_INCLUDED__

#include "objsyscommexpdef.h"
#include <q3dragobject.h>
#include <q3ptrlist.h>
#include "icsunknown.h"
class OBJSYSCOMMON_CLASS IICSUnknownDrag : public Q3StoredDrag
{
public:
    IICSUnknownDrag( IICSUnknown* pIUnk, QWidget *dragsource, const char *name = 0 );
    IICSUnknownDrag( QWidget * dragSource = 0, const char * name = 0 );
	~IICSUnknownDrag();
    void SetIUnknown( IICSUnknown* pIUnk);
    void AppendIUnknown( IICSUnknown* pIUnk);
	static bool decode( QMimeSource *ms, const char* iid, void** ppI, int index = 0 );
	static bool decode( QMimeSource *ms, const char* iid, Q3PtrList<IICSUnknown>& list );
    static int canDecode( QMimeSource *ms );
private:
    Q3PtrList<IICSUnknown> m_IUnkList;
};

#endif	//__OBJECT_SYSTEM_OBJECTDRAG_H_INCLUDED__