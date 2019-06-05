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

	//����ͨ��
	void Lock()
	{
		Lock(0);
	}
	
	//����ͨ��
	void Unlock()
	{
		Unlock(0);
	}

	//����Ϣ����
	void LockRead()
	{
		Lock(1);
	}

	//����Ϣ����
	void UnlockRead()
	{
		Unlock(1); 
	}

	//д��Ϣ����
	void LockWrite()
	{
		Lock(2);
	}

	//д��Ϣ����
	void UnlockWrite()
	{
		Unlock(2);
	}

	//������Ϣ����
	void LockUpdate()
	{
		Lock(3);
	}
	
	//������Ϣ����
	void UnlockUpdate()
	{
		Unlock(3);
	}

protected:
	virtual void run() {};

	//����
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

	//����
	void Unlock(int no)
	{
		m_Mutex.lock();
		m_cLockStates[no] = 0;
		m_Mutex.unlock();
	}
	
private:
	QMutex m_Mutex; //��д��Ϣ��
	int m_nState;
	char m_cLockStates[4];//��״ֵ̬
};

#endif
