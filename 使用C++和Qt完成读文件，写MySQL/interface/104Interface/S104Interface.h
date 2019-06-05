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



#ifndef _S104INTERFACE_H
#define _S104INTERFACE_H

#ifdef  WIN32

#ifdef  S104APCI_EXPORTS

class _declspec(dllexport) IS104Interface;
class _declspec(dllexport) IS104CallBackInterface;
extern "C" 
{
/*************************************************
  ��������:   GetS104
  ��������:   ��ȡͨ������

  �������:   ��
  �������:   ��
  ����ֵ:     ��

*************************************************/
      _declspec(dllexport) IS104Interface * GetS104();

/*************************************************
  ��������:   GetCurrentDTime
  ��������:   ʱ���ʽ�����
  �������:   char* psTime  ʱ���ʽ�����ָ��
  �������:   ��
  ����ֵ:     ��

*************************************************/
	  _declspec(dllexport) void GetCurrentDTime(char* psTime);
/*************************************************
  ��������:   SetLog
  ��������:   ������־�������

  �������:   char* sName  Ӧ�ó������ģ������
  ������������char* sLogName ������־�ļ�����
  ������������bool bSet true ������־������ԡ�false ȡ����־������� ��������������������
  �������:   ��
  ����ֵ:     ��

*************************************************/
	  _declspec(dllexport) void SetLog(char* sName,char* sLogName,bool bSet);
}
#else
class _declspec(dllimport) IS104Interface;
class _declspec(dllimport) IS104CallBackInterface;
extern "C" 
{
	  _declspec(dllimport) IS104Interface * GetS104();
	  _declspec(dllimport) void GetCurrentDTime(char* psTime);
	  _declspec(dllimport) void SetLog(char* sName,char* sLogName,bool bSet);
}
#endif
#else

class IS104Interface;
class IS104CallBackInterface;

extern "C" 
{
      IS104Interface * GetS104();
	  void GetCurrentDTime(char* psTime);
	  void SetLog(char* sName,char* sLogName,bool bSet);
}
#endif


class IS104Interface
{
public:
	/***************************************************************************
	������InitChannel
	���ܣ���ʼ��ͨ����Ϣ
	������char* sIP1�������ӵ�S104ʵ��������һIP��ַ������ΪNULL
		  int nPort1�������ӵ�S104ʵ��������һ�����˿ڣ����������
		  char* sIP2�������ӵ�S104ʵ���������IP��ַ����ΪNULL
		  int nPort1�������ӵ�S104ʵ��������������˿�	
	���أ�bool��true, ��ʼ���ɹ�
	            false,��ʼ��ʧ��
	****************************************************************************/
	virtual bool InitChannel(char* sIP1,
		int nPort1,
		char* sIP2,
		int nPort2
		)  = 0;

	/***************************************************************************
	������AddChannelGrp
	���ܣ����������ӵ�ͨ������Ϣ
	������int nChnlGrp, �����ӵ�ͨ����ID
	      char* sIP1,   �����ӵ�M104ʵ��������ͨ��һIP��ַ������ΪNULL
		  int nChnlID1�������ӵ�M104ʵ��������ͨ��һID�����������
		  char* sIP2��  �����ӵ�M104ʵ��������ͨ����IP��ַ����ΪNULL
		  int nChnlID2�������ӵ�M104ʵ��������ͨ����ID����Ϊ��	
	���أ�bool��true, ��ʼ���ɹ�
	            false,��ʼ��ʧ��
	****************************************************************************/
	virtual bool AddChannelGrp(int nChnlGrp,
		char* sIP1,
		int nChnlID1,
		char* sIP2 = 0,
		int nChnlID2 = 0
		)  = 0;

	/***************************************************************************
	������FiniM104
	���ܣ�����M104Ӧ�÷����
	��������
	���أ���
	****************************************************************************/
	virtual void FiniS104()                 = 0;
    virtual bool MsgSend(int nChnlID, char * pBuf,short uLen ) = 0;
	virtual bool MsgSend(char * pBuf,short uLen, char * szIPandPort) = 0;
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
	������M104CallBackInterface* pCallBackInterface���ص��ӿ�
	      bool bConfig �Ƿ���Ҫ�������ӿͻ���IP�����Ϊfalse,����Ҫ����
		  AddChannelGrp����
    ���أ���
	***************************************************************************/
	virtual void Advise(IS104CallBackInterface* pCallBackInterface,bool bConfig = false)   = 0;
};


/***************************************************
������:  M104CallBackInterface
������:  M104Ӧ�÷���Ļص��ӿ�
***************************************************/
class IS104CallBackInterface
{
public:
	/***************************************************************************
	������MsgReturn
	���ܣ���ɽ������ݵĻص�
	������int nChnlID  ͨ����ʶ
	      char * pBuf,���ձ��յ�ָ��
	      short sLen�����ձ��յĳ���
	���أ���
	***************************************************************************/
	virtual void  MsgReturn(int nChnlID ,char * pBuf, short sLen) = 0;
 	/***************************************************************************
	������MsgReturn
	���ܣ���ɽ������ݵĻص�
	������int nChnlID  ͨ����ʶ
	      char * pBuf,���ձ��յ�ָ��
	      char * szIPandPort �ͻ���IP+�˿�
	���أ���
	***************************************************************************/
   virtual void  MsgReturn(char * pBuf, short sLen,char * szIPandPort) = 0;

	/***************************************************************************
	������ConnectState
	���ܣ�����ͨ��״̬
	������unsigned int nChnlID ͨ����ʶ
	      bool bConnect        ͨ��״̬ 0 �ϣ�1 �� ,2 ��
	���أ���
	***************************************************************************/
	virtual void ConnectState(unsigned int nChnlID,unsigned char uState) = 0 ;
	/***************************************************************************
	������ConnectState
	���ܣ�����ͨ��״̬
	������char * szIPandPort �ͻ���IP+�˿�
	      bool bConnect        ͨ��״̬ 0 �ϣ�1 �� ,2 ��
	���أ���
	***************************************************************************/
	virtual void ConnectState(char * szIPandPort,unsigned char uState) = 0;
	/***************************************************************************
	������OnTimerReturn
	���ܣ���ʱ������
	������unsigned long uTimerID ��ʱ����ʶ
	���أ���
	***************************************************************************/
	virtual void OnTimerReturn(unsigned long uTimerID) = 0;
	/***************************************************************************
	������OnRawMsg
	���ܣ�ԭʼ���Ļص�
	������unsigned char * pBuf ������ʼ��ַ
	      short nLen           ���ĳ���
		  char uDirect         ���ķ��� 1 ���յ��ı��ģ�0 ���͵ı���
		  unsigned char * szIP ͨѶԶ����IP

	���أ���
	***************************************************************************/
	virtual void OnRawMsg(unsigned char * pBuf,short nLen,char uDirect,unsigned char * szIP) = 0;

	/***************************************************************************
	������OnRawMsg
	���ܣ�ԭʼ���Ļص�
	������unsigned char * pBuf ������ʼ��ַ
	      short nLen           ���ĳ���
		  char uDirect         ���ķ��� 1 ���յ��ı��ģ�0 ���͵ı���
		  unsigned short  sIedAddr װ�õ�ַ

	���أ���
	***************************************************************************/
	virtual void OnRawMsg(unsigned short  sIedAddr,unsigned char * pBuf,short nLen,char uDirect) = 0;
	
	virtual void  MsgShow(char * pBuf, short sLen,char * szIPandPort, int iDirect) = 0;
};


#endif
