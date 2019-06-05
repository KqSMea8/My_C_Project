//icslock.h

#ifndef _ICSLOCK_PENGSHIKANG_20081129_H_
#define _ICSLOCK_PENGSHIKANG_20081129_H_

#include <string.h>
#include <qmutex.h>
#include <qthread.h>


class CICSLock : public QThread
{
public:
	CICSLock()
	{
		memset(m_cLockStates, 0, 4);
	}

	virtual ~CICSLock() {};

	//加普通锁
	void Lock()
	{
		Lock(0);
	}
	
	//解普通锁
	void Unlock()
	{
		Unlock(0);
	}

	//读信息加锁
	void LockRead()
	{
		Lock(1);
	}

	//读信息解锁
	void UnlockRead()
	{
		Unlock(1); 
	}

	//写信息加锁
	void LockWrite()
	{
		Lock(2);
	}

	//写信息解锁
	void UnlockWrite()
	{
		Unlock(2);
	}

	//更新信息加锁
	void LockUpdate()
	{
		Lock(3);
	}
	
	//更新信息解锁
	void UnlockUpdate()
	{
		Unlock(3);
	}

protected:
	virtual void run() {};

	//加锁
	void Lock(int no)
	{
		while(true)
		{
			m_Mutex.lock();
			if(m_cLockStates[no] == 0)
			{
				m_cLockStates[no] = -1;
				m_Mutex.unlock();
				return;
			}
			m_Mutex.unlock();
			QThread::msleep(5);	 //rest 5 millisecond
		}
	}

	//解锁
	void Unlock(int no)
	{
		m_Mutex.lock();
		m_cLockStates[no] = 0;
		m_Mutex.unlock();
	}
	
private:
	QMutex m_Mutex; //读写信息锁
	int m_nState;
	char m_cLockStates[4];//锁状态值
};

#endif
