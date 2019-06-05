/*****************************************************************************/
/*��̵����ɷ����޹�˾                                     ��Ȩ��2007-2008   */
/*****************************************************************************/
/* ��Դ���뼰������ĵ�Ϊ���������̵����ɷ����޹�˾�������У�δ��������    */
/* �ɲ��������޸Ļ򷢲�������׷����صķ������Ρ�                          */
/*                                                                           */
/*                      ���������̹ɷ����޹�˾                             */
/*                      www.xjgc.com                                         */
/*                      (0374) 321 2924                                      */
/*                                                                           */
/*****************************************************************************/



#ifndef _M104INTERFACE_PENGSHIKANG_20140528_H
#define _M104INTERFACE_PENGSHIKANG_20140528_H

#ifdef  WIN32

	#ifdef  M104_EXPORTS
		//class _declspec(dllexport) CChannel;  
		//class _declspec(dllexport) Client;    
		class _declspec(dllexport) IM104Interface_fd;
		class _declspec(dllexport) IM104CallBackInterface_fd;
		extern "C" 
		{
		/*************************************************
		  ��������:   GetM104Channel_fd
		  ��������:   ��ȡͨ������

		  �������:   ��
		  �������:   ��
		  ����ֵ:     ��

		*************************************************/
			  _declspec(dllexport) IM104Interface_fd* GetM104Channel_fd();
		/*************************************************
		  ��������:   RelM104Channel_fd
		  ��������:   �ͷŶ���

		  �������:   ��
		  �������:   ��
		  ����ֵ:     ��

		*************************************************/
			  _declspec(dllexport) void RelM104Channel_fd();

		/*************************************************
		  ��������:   GetCurrentDTime_fd
		  ��������:   ʱ���ʽ�����
		  �������:   char* psTime  ʱ���ʽ�����ָ��
		  �������:   ��
		  ����ֵ:     ��

		*************************************************/
			  _declspec(dllexport) void GetCurrentDTime_fd(char* psTime);
		/*************************************************
		  ��������:   SetLog_fd
		  ��������:   ������־�������

		  �������:   char* sName  Ӧ�ó������ģ������
  ������������		  char* sLogName ������־�ļ�����
  ������������		  bool bSet true ������־������ԡ�false ȡ����־������� ��������������������
		  �������:   ��
		  ����ֵ:     ��

		*************************************************/
			  _declspec(dllexport) void SetLog_fd(char* sName,char* sLogName,bool bSet);
			  _declspec(dllexport)  void Ini_event_loop_fd();
		}
	#else
		//class _declspec(dllimport) CChannel;  
		//class _declspec(dllimport) Client;    
		class _declspec(dllimport) IM104Interface_fd;
		class _declspec(dllimport) IM104CallBackInterface_fd;
		extern "C" 
		{
			  _declspec(dllimport) IM104Interface_fd* GetM104Channel_fd();
			  _declspec(dllimport) void RelM104Channel_fd();
			  _declspec(dllimport) void GetCurrentDTime_fd(char* psTime);
			  _declspec(dllimport) void SetLog_fd(char* sName,char* sLogName,bool bSet);
			  _declspec(dllimport) void Ini_event_loop_fd();
		}
	#endif
#else
	//class CChannel;  
	//class Client;    
	class IM104Interface_fd;
	class IM104CallBackInterface_fd;

	extern "C" 
	{
		  IM104Interface_fd* GetM104Channel_fd();
		  void RelM104Channel_fd();
		  void Ini_event_loop_fd();
		  void GetCurrentDTime_fd(char* psTime);
		  void SetLog_fd(char* sName,char* sLogName,bool bSet);
	}

#endif


class IM104Interface_fd
{
public:
	/***************************************************************************
	������InitChannel
	���ܣ���ʼ��ͨ����Ϣ
	������unsigned int nChnlID1,ͨ��һ��ʶ
	      char* sIP1�������ӵ�M104ʵ��������һIP��ַ������ΪNULL
		  int nPort1�������ӵ�M104ʵ��������һ�����˿ڣ����������
		  int nChnlID2,nChnlID1,ͨ������ʶ
		  char* sIP2�������ӵ�M104ʵ���������IP��ַ����ΪNULL
		  int nPort1�������ӵ�M104ʵ��������������˿�	
	���أ�bool��true, ��ʼ���ɹ�
	            false,��ʼ��ʧ��
	****************************************************************************/
	virtual bool InitChannel(unsigned int nChnlID1,
		char* sIP1,
		int nPort1,
		int nChnlID2,
		char* sIP2,
		int nPort2
		)  = 0;

	/***************************************************************************
	������FiniM104
	���ܣ�����M104Ӧ�÷����
	��������
	���أ���
	****************************************************************************/
	virtual void FiniM104()                 = 0;
    virtual bool MsgSend(char * pBuf,short uLen) = 0;

	/***************************************************************************
	������SetTimer
	���ܣ����ö�ʱ��
	������unsigned long uTimerID ��ʱ����ʶ
	      unsigned long ulSpan   ��ʱ����ʱ�����λ����
	���أ�bool  true �ɹ� false ʧ��
	****************************************************************************/
	virtual bool SetTimer(unsigned long uTimerID,unsigned long ulSpan) = 0;

	/***************************************************************************
	������CancelTimer
	���ܣ�ȡ����ʱ��
	������unsigned long uTimerID ��ʱ����ʶ
	���أ���
	****************************************************************************/
	virtual bool CancelTimer(unsigned long uTimerID) = 0;

public:
	/***************************************************************************
	������Advise
	���ܣ�����M104Ӧ�÷���Ļص��ӿ�
	������M104CallBackInterface_fd* pCallBackInterface���ص��ӿ�
    ���أ���
	***************************************************************************/
	virtual void Advise(IM104CallBackInterface_fd* pCallBackInterface)   = 0;

	virtual void SetGrpID(int nGrpID) = 0;
	virtual void Set104T(int nT0,int nT1,int nT2,int nT3) =0;
	virtual void Set104KW (int nK,int nW) = 0;
};


/***************************************************
������:  M104CallBackInterface
������:  M104Ӧ�÷���Ļص��ӿ�
***************************************************/
class IM104CallBackInterface_fd
{
public:
	/***************************************************************************
	������MsgReturn
	���ܣ���ɽ������ݵĻص�
	������unsigned int nChnlID ͨ����ʶ
	      char * pBuf,���ձ��յ�ָ��
	      short sLen�����ձ��յĳ���
	���أ���
	***************************************************************************/
	virtual void  MsgReturn(unsigned int nChnlID,char * pBuf, short sLen) = 0;


	/***************************************************************************
	������ConnectState
	���ܣ�����ͨ��״̬
	������unsigned int nChnlID ͨ����ʶ
	      bool bConnect        ͨ��״̬ 0 �ϣ�1 �� ,2 ��
	���أ���
	***************************************************************************/
	virtual void ConnectState(unsigned int nChnlID,unsigned char uState) = 0 ;

	/***************************************************************************
	������OnTimerReturn
	���ܣ���ʱ������
	������unsigned long uTimerID ��ʱ����ʶ
	���أ���
	***************************************************************************/
	virtual void OnTimerReturn(unsigned long uTimerID) = 0;
};


#endif
