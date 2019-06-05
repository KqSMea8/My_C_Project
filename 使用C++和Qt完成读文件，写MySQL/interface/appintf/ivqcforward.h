/*******************************************************************************************************
 * ivqcforward.h -- VQC����ת���ӿڶ���
 * 
 * date: 2008.12.27 hongkeqin@xjgc.com
 * revised:
		����IRecvData�ص��ӿڶ���
		����RegisterCallBack(...)����
		����ForwardData(int, VQC_T::tCMDTYPE, const QVariant&, VQC_T::tRETVAL)���� 2009.05.12
		�޸�ForwardData(int, VQC_T::tCMDTYPE, const QVariant&, VQC_T::tRETVAL)˵�� 2009.06.09
 *******************************************************************************************************/

#ifndef _IVQCFORWARD_H_
#define _IVQCFORWARD_H_

#include "icsunknown.h"
#include "vqcforwardtypes.h"
//std header
#include <qvariant.h>

#define CLSID_VQCFORWARD	"A57D592C-5B47-4fe5-B30A-183266D40400"
#define IID_IVQCFORWARD		"ivqcforward"
#define IID_ICVTFORWARD		"icvtforward"
#define IID_ISMFORWARD		"ismforward"
#define MODULE_VQCFORWARD	"vqcforward"

class IRecvData
{
public:
	/*
	 * 1. ���� Զ�˷�������������
	 * 1.1 ��cmdType=VQC_T::CALLDATAʱ����ʾ���٣���ʱid, var������Ч
	 * ������
	   id -- ����ID
	   cmdType -- ָ������
	   var -- QVariant ��������
	 * ���أ�void
	 */
	virtual void OnRecv(int id, VQC_T::tCMDTYPE cmdType, const QVariant& var) = 0;

	//virtual void OnRecv(IICSStream* pStream);
};

 /***
 * VQC����ת���ӿ�
 ***/
class IVQCForward : public IICSUnknown
{
public:
	
	/*
	 * ת������
	 * ������
	   id -- ����ID
	   var -- QVariant ��ת������
	   timeStamp -- ����ʱ��
	 * ���أ�int
			 0--�ɹ�; -1--ʧ��;
	 */
	virtual int ForwardData(int id, const QVariant& var, double timeStamp) = 0; 
	
	/* ��ô���������Ϣ
	 * ��������
	 * ����: const char* ��������
	 */
	virtual const char* ErrorMsg() = 0;

	/* ע��ص��ӿ� [�ص��ӿ����ڽ���Զ�˷�������������]
	 * ������
		ptr -- �ص��ӿ�
	 * ���أ�void
	 */
	virtual void RegisterCallBack(IRecvData* ptr) = 0;

	/*
	 * 1. ת������ [����ת����������ִ�к�Ľ��]
	 * 2. ��Ӧ�������ݣ���ʱcmdType=VQC_T::CALLDATA, ����ret��Ч 09.06.09
	 * ����:
	   id -- ����ID
	   cmdType -- ָ������
	   var -- QVariant ��������
	   ret -- ������������
	 * ����: int
			 0--�ɹ�; -1--ʧ��;
	 */
	virtual int ForwardData(int id, VQC_T::tCMDTYPE cmdType, const QVariant& var, VQC_T::tRETVAL ret) = 0; 
	
public:
    static const char* GetIntfName() { return IID_IVQCFORWARD; } 

};


 /***
 * CVT����ת���ӿ�
 ***/
class ICVTForward : public IICSUnknown
{
public:
	
	/*
	 * ת��ң������
	 * ������
	   id -- ң��ID
	   val -- ֵ
	   timeStamp -- ����ʱ��
	 * ���أ�int
			 0--�ɹ�; -1--ʧ��;
	 */
	virtual int ForwardStatus(int id, int val, double timeStamp) = 0; 
	
	/*
	 * ת��ң������
	 * ������
	   id -- ID
	   val -- ֵ
	   timeStamp -- ����ʱ��
	 * ���أ�int
			 0--�ɹ�; -1--ʧ��;
	 */
	virtual int ForwardAnalog(int id, double val, double timeStamp) = 0; 

	/* ��ô���������Ϣ
	 * ��������
	 * ����: const char* ��������
	 */
	virtual const char* ErrorMsg() = 0;

	/* ע��ص��ӿ� [�ص��ӿ����ڽ���Զ�˷�������������]
	 * ������
		ptr -- �ص��ӿ�
	 * ���أ�void
	 */
	virtual void RegisterCallBack(IRecvData* ptr) = 0;

	/*
	 * 1. ת������ [����ת����������ִ�к�Ľ��]
	 * 2. ��Ӧ�������ݣ���ʱcmdType=VQC_T::CALLDATA, ����ret��Ч
	 * ����:
	   id -- ����ID
	   cmdType -- ָ������
	   var -- QVariant ��������
	   ret -- ������������
	 * ����: int
			 0--�ɹ�; -1--ʧ��;
	 */
	virtual int ForwardData(int id, VQC_T::tCMDTYPE cmdType, const QVariant& var, VQC_T::tRETVAL ret) = 0; 
	
public:
    static const char* GetIntfName() { return IID_ICVTFORWARD; } 

};


/***
 *  �ӵ�ѡ�ߣ�SM������ת���ӿ�
 ***/
class ISMForward : public IICSUnknown
{
public:
	
	/*
	 * ת��ң������
	 * ������
	   id -- ң��ID
	   val -- ֵ
	   timeStamp -- ����ʱ��
	 * ���أ�int
			 0--�ɹ�; -1--ʧ��;
	 */
	virtual int ForwardStatus(int id, int val, double timeStamp) = 0; 
	
	/*
	 * ת��ң������
	 * ������
	   id -- ID
	   val -- ֵ
	   timeStamp -- ����ʱ��
	 * ���أ�int
			 0--�ɹ�; -1--ʧ��;
	 */
	virtual int ForwardAnalog(int id, double val, double timeStamp) = 0; 

	/* ��ô���������Ϣ
	 * ��������
	 * ����: const char* ��������
	 */
	virtual const char* ErrorMsg() = 0;

	/* ע��ص��ӿ� [�ص��ӿ����ڽ���Զ�˷�������������]
	 * ������
		ptr -- �ص��ӿ�
	 * ���أ�void
	 */
	virtual void RegisterCallBack(IRecvData* ptr) = 0;

	/*
	 * 1. ת������ [����ת����������ִ�к�Ľ��]
	 * 2. ��Ӧ�������ݣ���ʱcmdType=VQC_T::CALLDATA, ����ret��Ч
	 * ����:
	   id -- ����ID
	   cmdType -- ָ������
	   var -- QVariant ��������
	   ret -- ������������
	 * ����: int
			 0--�ɹ�; -1--ʧ��;
	 */
	virtual int ForwardData(int id, VQC_T::tCMDTYPE cmdType, const QVariant& var, VQC_T::tRETVAL ret) = 0; 
	
public:
    static const char* GetIntfName() { return IID_ICVTFORWARD; } 

};

#endif 
