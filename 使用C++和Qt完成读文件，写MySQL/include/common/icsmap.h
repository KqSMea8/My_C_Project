//icsmap.h
#ifndef _ICSMAP_PENGSHIKANG_20081125_H_
#define _ICSMAP_PENGSHIKANG_20081125_H_

#include <qmap.h>
#include "icslock.h"  // for CICSLock

template <class Key, class T>
class CICSMap
{
private:
	typedef QMapIterator<Key, T> iterator;
	
	QMap<Key, T> m_icsMap;
	CICSLock m_mutex;

public:
	CICSMap () {}

	virtual ~CICSMap () {}

	iterator begin ()
	{
		lock();
		iterator it = m_icsMap.begin();
		unlock();
		return it;
	}
	
	iterator end ()
	{
		lock();
		iterator it = m_icsMap.end();
		unlock();
		return it;
	}
	
	iterator find ( const Key & k )
	{
		lock();
		iterator it = m_icsMap.find(k);
		unlock();
		return it;
	}
	
	T & operator[] ( const Key & k )
	{
		lock();
		T* t = &m_icsMap[k];
		unlock();
		return *t;
	}
	
	size_t size () const
	{
		lock();
		size_t num = m_icsMap.size();
		unlock();
		return num;
	}
	
	size_t count () const
	{
		lock();
		size_t num = m_icsMap.count();
		unlock();
		return num;
	}
	
	bool empty () const
	{
		lock();
		bool b = m_icsMap.empty();
		unlock();
		return b;
	}
	
	iterator insert ( const Key & key, const T & value, bool overwrite = true )
	{
		lock();
		iterator it = m_icsMap.insert(key, value, overwrite);
		unlock();
		return it;
	}
	
	void remove ( iterator it )
	{
		lock();
		m_icsMap.remove(it);
		unlock();
	}
	
	void remove ( const Key & k )
	{
		lock();
		m_icsMap.remove(k);
		unlock();
	}
	
	void clear ()
	{
		lock();
		m_icsMap.clear();
		unlock();
	}
	
protected:
	void lock()
	{
		m_mutex.Lock();
	}
	
	void unlock()
	{
		m_mutex.Unlock();
	}
	
};

//typedef CICSMap CMyMap;

#endif
