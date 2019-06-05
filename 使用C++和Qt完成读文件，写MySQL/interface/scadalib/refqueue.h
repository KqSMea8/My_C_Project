/*********************************************************
 * refqueue.h
 * date: 2008-06-12 hongkeqin@xjgc.com
 * contents: ���ü��������������Զ��������ü����������Ӻͼ���
 *********************************************************/
#ifndef _REFQUEUE__H_20080612
#define _REFQUEUE__H_20080612

#include <list>

/*
 * ���ü��������������Զ��������ü����������Ӻͼ���
 * reference queue container: automaticly adding and releasing COM-like objects' reference number
 * ģ�����value_type ����ΪCOM-like�ӿ�ָ�룬�ṩAddRef()��Release()������e.g. IICSUnknown*
 * �÷���RefQueue���Ƚ��ȳ����У����÷���STL container���ƣ���ͨ��iterator����
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