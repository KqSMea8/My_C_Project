/*****************************************************************************/
/*��̵����ɷ����޹�˾                                     ��Ȩ��		     */
/*****************************************************************************/
/* ��Դ���뼰������ĵ�Ϊ���������̵����ɷ����޹�˾�������У�δ��������    */
/* �ɲ��������޸Ļ򷢲�������׷����صķ������Ρ�                          */
/*                                                                           */
/*                      ���������̹ɷ����޹�˾                             */
/*                      www.xjgc.com                                         */
/*                      (0374) 321 2924                                      */
/*                                                                           */
/*****************************************************************************/

/*
    ��Ŀ����    ��  ͨѶ������
    �ļ���      ��  CSFDPInterface.h
    ����        ��  
    �汾        ��  0.0.1
    ����        ��  �߽���
    ����        ��  2008.6
*/
#ifndef CSFAPPINTERFACE_H
#define CSFAPPINTERFACE_H

#include "csfcdeinterface.h"
#include "csfcfginterface.h"

#ifdef WIN32
#ifdef CSFAPPINTERFACE_DLL                    
class _declspec(dllimport) ICSF_APP_CallBackInterface;
class _declspec(dllexport) ICSF_APP_Interface;
extern "C" 
	_declspec(dllexport) ICSFUnknown* GetCSFUnknown();
#else                                           
class _declspec(dllexport) ICSF_APP_CallBackInterface;
class _declspec(dllimport) ICSF_APP_Interface;
extern "C" 
	_declspec(dllimport) ICSFUnknown* GetCSFUnknown();
#endif
#else//UNIX,LINUX��(gnu)
class ICSFUnknown;
class ICSF_APP_CallBackInterface;
class ICSF_APP_Interface;
extern "C" 
	  ICSFUnknown* GetCSFUnknown();
#endif


/*************************************************
  ������:  ICSF_APP_CallBackInterface
  ������:  CSF���ⲿӦ�ý����ӿڶ���
*************************************************/
class ICSF_APP_CallBackInterface  :public ICSF_CDE_ExchCallBackInterface,
								   public ICSF_CDE_CfgCallBackInteface,
								   public ICSF_CDE_ModeCallBackInteface//���÷��������
{
public:
		/**
		����:nSrcId ����id
		nCSFId A/B����־ 0:A�� 1:B�� 
			   0xffffffff��ʾ�÷���ʧȥ��ϵ
		bState ͨ�� 0:��,1��ͨ��,2��ͨ // ������ 20111228 ע��
		*/
	virtual void SrcStateChanged(CSF_UINT32 nSrcId,
		CSF_UINT32 nCSFId,
		CSF_UINT32 nDpId,
		CSF_BOOLEAN bState)	= 0;

	/**
		����:nNode ǰ�û�id;nProt Э��id
	
			nState ��½��� 0:���ɹ�,1:�ɹ�
		ע��:��tcp�����Ͽ�ʱ,�һ���������½ʧ�ܵ�
	*/
	virtual void LoginReturn(CSF_UINT8 nNode,CSF_UINT8 nProt,CSF_UINT8 nState) =0;
};

/*************************************************
  ������:  ICSF_APP_Interface
  ������:  CSF���Ӧ�÷���ӿڶ���
*************************************************/
class ICSF_APP_Interface :  public ICSFUnknown
{
public:
	/***************************************************************************
	������Initialize
	���ܣ���ʼ����ģ�飨CSF��Ӧ�÷���ӿ�AppInterface��
	������int m_nAppid app���ݵ�Ӧ��id
	���أ�CSF_INT32��0���ɹ�����ʼ���ɹ�
	                 1��ʧ�ܣ���ʼ��ʧ��

	˵�����û���ʹ�ñ�ģ��ʱ��Ӧ�����ȵ��ô˺���
	***************************************************************************/
	virtual CSF_INT32 Initialize (unsigned int m_nAppid)                                =  0;

	/***************************************************************************
	������Finalize
	���ܣ�����ģ����ʹ����Դ
	��������
	���أ���

	˵�����û����˳�����ʱ����Ҫ���ñ������ͷ���Դ
	***************************************************************************/
	virtual void Finalize ()                                       =  0;

	/***************************************************************************
	������SetAppWorkState
	���ܣ�����Ŀǰ��Ӧ�÷���ӿڵĹ���״̬
	������CSF_BOOLEAN bWork  0-����ʾ��  1-����ʾ��

    ˵���������̨Ӧ�ò��õ�������ϵͳ��
	      ��Ҫ���ô˺���֪ͨCSF����ӿڱ�����ǰ������״̬
	***************************************************************************/
	virtual void SetAppWorkState(CSF_BOOLEAN bWork)                =  0;


	/***************************************************************************
	���ƣ�  Advise
	������  ���ûص��ӿ�
	������  ICSF_APP_CallBackInterface* pCallback���ص��ӿ�
	����ֵ����

	˵����  ���ûص��ӿ�
	***************************************************************************/
	virtual void Advise(ICSF_APP_CallBackInterface* pCallback)=0;
public:
	ICSF_CDE_ExchInteface*  m_pExchInterface;
	ICSF_CDE_CfgInteface* m_pCfgInterface;
};

#endif
