//icsptrlist.h
#ifndef _ICSPTRLIST_PENGSHIKANG_20081125_H_
#define _ICSPTRLIST_PENGSHIKANG_20081125_H_

#include <q3ptrlist.h>
#include "icslock.h"                             // for CICSLock

template <class type>
class CICSPtrList
{
private:
	Q3PtrList<type> m_icsPtrList;
	CICSLock m_mutex;
	
protected:
	void lock()
	{
		m_mutex.Lock();
	}
	
	void unlock()
	{
		m_mutex.Unlock();
	}
	
public:
	CICSPtrList () {}
	
	virtual ~CICSPtrList () {}
	
	uint count () const
	{
		//lock();
		const uint num = m_icsPtrList.count();
		//unlock();
		return num;
	}
	
	bool isEmpty () const
	{
		lock();
		bool b = m_icsPtrList.isEmpty();
		unlock();
		return b;
	}
	
	bool insert ( uint index, const type * item )
	{
		lock();
		bool b = m_icsPtrList.insert(index, item);
		unlock();
		return b;
	}
	
	void prepend ( const type * item )
	{
		lock();
		m_icsPtrList.prepend(item);
		unlock();
	}
	
	void append ( const type * item )
	{
		lock();
		m_icsPtrList.append(item);
		unlock();
	}
	
	bool remove ()
	{
		lock();
		bool b = m_icsPtrList.remove();
		unlock();
		return b;
	}
	
	bool remove ( uint index )
	{
		lock();
		bool b = m_icsPtrList.remove(index);
		unlock();
		return b;
	}
	
	bool remove ( const type * item )
	{
		lock();
		bool b = m_icsPtrList.remove(item);
		unlock();
		return b;
	}
	
	type * take ()
	{
		lock();
		type * t = m_icsPtrList.take();
		unlock();
		return t;
	}
	
	type * take ( uint index )
	{
		lock();
		type * t = m_icsPtrList.take(index);
		unlock();
		return t;
	}
	
	virtual void clear ()
	{
		lock();
		m_icsPtrList.clear();
		unlock();
	}
	
	int find ( const type * item )
	{
		lock();
		int index = m_icsPtrList.find(item);
		unlock();
		return index;
	}
	
	uint contains ( const type * item ) const
	{
		lock();
		uint num = m_icsPtrList.contains(item);
		unlock();
		return num;
	}
	
	bool replace ( uint index, const type * item )
	{
		lock();
		bool b = m_icsPtrList.replace(index, item);
		unlock();
		return b;
	}
	
	int at () const
	{
		lock();
		int index = m_icsPtrList.at();
		unlock();
		return index;
	}
	
	type * at ( uint index ) const
	{
		lock();
		type * t = m_icsPtrList.at(index);
		unlock();
		return t;
	}
	
	type * current ()
	{
		lock();
		type * t = m_icsPtrList.current();
		unlock();
		return t;
	}
	
	type * first ()
	{
		lock();
		type * t = m_icsPtrList.first();
		unlock();
		return t;
	}
	
	type * last ()
	{
		lock();
		type * t = m_icsPtrList.last();
		unlock();
		return t;
	}
	
	type * next ()
	{
		lock();
		type * t = m_icsPtrList.next();
		unlock();
		return t;
	}
	
	type * prev ()
	{
		lock();
		type * t = m_icsPtrList.prev();
		unlock();
		return t;
	}
	
};

#endif
