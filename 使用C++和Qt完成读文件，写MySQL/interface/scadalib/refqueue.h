/*********************************************************
 * refqueue.h
 * date: 2008-06-12 hongkeqin@xjgc.com
 * contents: 引用计数队列容器：自动管理引用计数器的增加和减少
 *********************************************************/
#ifndef _REFQUEUE__H_20080612
#define _REFQUEUE__H_20080612

#include <list>

/*
 * 引用计数队列容器：自动管理引用计数器的增加和减少
 * reference queue container: automaticly adding and releasing COM-like objects' reference number
 * 模版参数value_type 必须为COM-like接口指针，提供AddRef()和Release()方法，e.g. IICSUnknown*
 * 用法：RefQueue是先进先出队列，其用法与STL container相似，可通过iterator遍历
 * date: 2008-06-12 hongkeqin@xjgc.com
 */
template<class value_type>
class RefQueue
{
public:
	typedef std::list<value_type> rep;
	typedef rep::reference reference;
	typedef rep::iterator iterator;
	typedef RefQueue<value_type> self;
	
	RefQueue() : m_rep() {}

	RefQueue(RefQueue& coll) : m_rep(coll.m_rep)
	{
		iterator it = m_rep.begin();
		for(; it != m_rep.end(); ++it)
			(*it)->AddRef();	
	}

	iterator Begin()
	{
		return m_rep.begin();
	}

	iterator End()
	{
		return m_rep.end();
	}

	void Push(value_type v)
	{
		m_rep.push_back(v);
		v->AddRef();
	}

	void Pop()
	{
		m_rep.front()->Release();
		m_rep.pop_front();
	}

	size_t Size()
	{
		return m_rep.size();
	}
	
	void Clear()
	{
		clearReference();
		m_rep.clear();
	}
	
	self& operator=(RefQueue& o)
	{
		if(this != &o)
		{
			clearReference();
			m_rep = o.m_rep;
			iterator it = m_rep.begin();
			for(; it != m_rep.end(); ++it)
				(*it)->AddRef();
		}
		return *this;
	}

	~RefQueue() 
	{
		clearReference();
	}

private:
	void clearReference()
	{
		iterator it = m_rep.begin();
		for(; it != m_rep.end(); ++it)
			(*it)->Release();
	}
	std::list<value_type> m_rep;	
};

#endif