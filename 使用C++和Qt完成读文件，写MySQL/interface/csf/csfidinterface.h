/*****************************************************************************/
/*��̵����ɷ����޹�˾                                     ��Ȩ��2006-2007   */
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
    �ļ���      ��  CSFIdInterface.h
    ����        ��  ���ļ�����������csfid�Ľӿ�
    �汾        ��  0.0.1
    ����        ��  ��տΰ
    ����        ��  2008.7
*/

#ifndef CSFIDINTERFACE_H
#define CSFIDINTERFACE_H

	/***************************************************************************
	������GetCSFId
	���ܣ�����Э����ر�ʶ�ֻ�ȡCSFID
	������
          int nProtocal��Э���ʶ
                  
          int nParaNum��Э���������ʶ�֣�����

          int* pnPara�����Э��������飬

    ���أ�CSF_INT64��������csfid
    ˵����
          1. 104��Լ�������£�
		     nProtocal = 4
			 nParaNum  = 4
             pnPara������˳�����������Ϊ��ASDU���ͣ�װ�õ�ַ��������ַ����Ϣ���ַ��
	***************************************************************************/


#ifdef WIN32
#ifdef CSFIDGRENTE_DLL_FILE  
extern "C"       
      _declspec(dllexport) CSF_INT64 GetCSFId(int nProtocal,int nParaNum,int* pnPara);
#else                                   
extern "C" 
      _declspec(dllimport) CSF_INT64 GetCSFId(int nProtocal,int nParaNum,int* pnPara);
#endif//#ifdef PROTMODEL_DLL_FILE 
#else//UNIX,LINUX�ȣ�gnu��
extern "C" 
      CSF_INT64 GetCSFId(int nProtocal,int nParaNum,int* pnPara);
#endif

#endif
