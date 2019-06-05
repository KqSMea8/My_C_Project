#ifndef __HMI_TRENDIMPL_TIMER_THREAD_H_INCLUDED__
#define __HMI_TRENDIMPL_TIMER_THREAD_H_INCLUDED__

#include <qthread.h>
#include <q3intdict.h>
#include <QMutex>
#include <QMap>

class TimerThreadClient
{
public:
	virtual void OnTimer(int id) = 0;
};

class TimerThread : public QThread
{
public:	
	void UnregTimerClient(int id);
	int RegTimerClient(TimerThreadClient* client, double internal, bool bImmediately = false);
	TimerThread();
protected:
	void timerEvent(QTimerEvent *te);
	class TimerInfo
	{
	public:
		TimerInfo(TimerThreadClient* client,double internal,int nextShot){
			m_client = client;
			m_internal = internal;
			m_nextShot = nextShot;
		};
		TimerThreadClient* m_client;
		double m_internal;
		int m_nextShot;
	};
	virtual void run();
	bool m_bThread;			//true线程模式 false定时器模式

	//线程模式
	int m_nextID;
	Q3IntDict<TimerInfo> m_clients;	//ID-定时信息影射表
	QMutex m_mtxClientList;

	//定时器模式
	QMap<int,int> m_int_timerID;
};

extern TimerThread	theTimerThread;


#endif	//__HMI_TRENDIMPL_TIMER_THREAD_H_INCLUDED__