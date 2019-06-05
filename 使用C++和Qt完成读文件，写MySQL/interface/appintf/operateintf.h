/**********************************************************************
�� �� ��:		OperateIntf.h
��    ��:		��������ӿ�
�޸ļ�¼:       created by jianshend on 2005-07-15
                add method name(exported by module OperateEnum)
					------Modified by jianshen on 2005-08-23
				add operate serialize
					------Modified by jianshen on 2005-12-15
**********************************************************************/

#ifndef _OPERATEINTF__H_
#define _OPERATEINTF__H_

#include "objsintf.h"

#define IID_IICSOperateType		"IICSOperateType"
#define IID_IICSOperate			"IICSOperate"

class IICSOperateType;
class IICSOperate;

//�������ͽӿ�
class IICSOperateType : public IICSUnknown
{
public:
	//��ȡ��������
	virtual void GetName(char* name, int size)=0;

	//��ȡ����������
	virtual void GetCaption(char* caption, int size, IICSRtdbObject* pObject = 0)=0;

	//��ȡ������ض����������Ϣ
	virtual void GetObjTypeInfo(IICSTypeInfo** pTypeInfo)=0;

	//��ȡʵ�ָò��������ģ������
	virtual void GetOperateModule(char* module, int size)=0;

	//��ȡ���������������
	virtual void GetOperateClassName(char* name, int size)=0;

	/*
	����  �ܡ�	�ж϶���һ������ò�����ִ��
	����  ����	��
	������ֵ��	�����Ƿ��ִ��
	��˵  ����	���һ�ֲ������Ͷ�Ӧĳ�������Ƿ��ִ��                                                                                                                                                                                                                                                                                                                       
	*/
	virtual bool IsEnable(IICSRtdbObject* pObject)=0;

	/*
	����  �ܡ�	�ж϶���һ������ò��������Ƿ���Ч
	����  ����	��
	������ֵ��	�����Ƿ���Ч
	��˵  ����	1,����������Ͷ�Ӧһ��������Ч��ö�����Ҽ��˵���Ӧ��ʾ�и����Ͳ����Ĳ˵���
				2,������ĳһ�������ִ����ض��Ըö�����Ч,���Ƿ�������һ��
	*/
	virtual bool IsValid(IICSRtdbObject* pObject)=0;
	virtual bool CreateOperate(IICSRtdbObject* pObject, IICSOperate** pOperate)=0;
	virtual bool CanOperate(IUserObject* pUser)=0;
public:
	static	char* GetIntfName(){return IID_IICSOperateType;};
};

//����ģʽ:
//OPMD_NORMAL:	��ͨģʽ	-----	���������������,Ԥ���,������ʾ,ִ�����в���
//OPMD_QUIET :	����ʾģʽ	-----	�����������������,Ԥ���,������ʾ,������Ҫ�˹���Ԥ����
//ע:	1.�еĲ����Ĳ��������Լ���������������OPMD_QUIET��������
//		2.��ȫʵ��OPMD_QUIETģʽ��ҪΪ�����ṩ����������Ϣ�ӿ��Լ���ȡ���ò����ӿ�[δʵ��]
enum OPERATEMODE{OPMD_NORMAL, OPMD_QUIET , OPMD_YK};

class IICSOperate : public IICSUnknown
{
public:
	//��ȡ������ض���
	virtual void GetObject(IICSRtdbObject** ppObject)=0;

	//���ò�����ض���
	virtual void SetObject(IICSRtdbObject* pObject)=0;

	//��ȡ����Ա
	virtual void GetUser(IICSRtdbObject** ppUser)=0;

	//���ò���Ա
	virtual void SetUser(IICSRtdbObject* pUser)=0;

	//��ȡ��������
	virtual void GetActDesc(char* desc, int size)=0;

	//���ò�������
	virtual void SetActDesc(char* desc)=0;

	/*
	����  �ܡ�	���������Ҫ����ز���
	����  ����	��
	������ֵ��	���سɹ�ʧ��
	��˵  ����	���ô˺���,����������Լ���������(��Ҫʱ)��ʾ����Ա���������صĲ���
	*/
	virtual bool InputOperate()=0;

	/*
	����  �ܡ�	����Ԥ����
	����  ����	��
	������ֵ��	���سɹ�ʧ��
	��˵  ����	�˺������ڿͻ��˶Խ�Ҫ���еĲ�������Ԥ���ж�,����ò�������ʲô����²���ִ��,
				������ᵯ���Ի�����ʾ���ܽ��е�ԭ��,����ɹ�����ԶԸò��������ύ
	*/
	virtual bool Preprocess()=0;

	/*
	����  �ܡ�	�ύ����
	����  ����	��
	������ֵ��	���سɹ�ʧ��
	��˵  ����	�˺�������Ѹò����ύ��Ӧ�÷�����,����ʾ������ʾ����Ա��ǰ�Ĳ���״̬
				(����:��ʾ�����Ľ������Լ���ǰ�Ĳ�������)
	*/
	virtual bool Commit()=0;

	/*
	����  �ܡ�	�жϲ����Ƿ����
	����  ����	��
	������ֵ��	���سɹ�ʧ��
	��˵  ����	ʹ�ô˺����ж��Ƿ���Խ�����һ������
	*/
	virtual bool IsComplete()=0;
	
	/*
	����  �ܡ�	�жϲ����Ƿ�ɹ�
	����  ����	��
	������ֵ��	���سɹ�ʧ��
	*/
	virtual bool IsSuccess()=0;

	//
	virtual void GetOperateType(IICSOperateType** ppType)=0;

	//�ɷ�������ģ��(OperateService)����,�ͻ��˲�����
	virtual bool Execute()=0;

	//���ò���ģʽ
	virtual void SetMode(OPERATEMODE opMode)=0;
	//��ȡ������
	virtual int GetErrorCode()=0;
	//���ݴ������ȡ��������
	virtual bool GetErrorDesc(int errorcode, char* buf, int bufsize)=0;
	//�����Ƿ�ǿ���û���֤,Ĭ�ϲ�ǿ���û�����
	virtual bool SetUserCheck(bool b)=0;
public:
	static	char* GetIntfName(){return IID_IICSOperate;};
};

#define  IID_IFacelessOperate	"ifacelessoperate"

class IFacelessOperate : public IICSOperate
{
public:
	virtual void Terminate() = 0;
};

//�������ö��ģ������
#define MODULE_OPERATEENUM		"OperateEnum"
#define MODULE_OPRERATECOMPS	"OperateComps"
#define MODULE_ELEMCTRLCLIENT	"EleCtrlClient"

//���干���OperateEnum��������������
#define METHOD_REGISTEROPTYPE      "RegisterOperateType"
#define METHOD_UNREGISTEROPTYPE    "UnregisterOperateType"
#define METHOD_QUERYOPSBYTYPE      "QueryOperateByTypeInfo"
#define METHOD_QUERYOPSBYOBJ       "QueryOperateByObject"
#define METHOD_CREATEOPERTETYPE    "CreateOperateType"

/*
��˵  ����	1,����ע��������͵ĺ���ָ������
			2,�ú����ɹ����OperateEnum����,������к�����ΪRegisterOperateType
			3,�õ���������ҵ���߼�����ģ�����,�ͻ��˸�ģ���������
*/
typedef	bool (*RegisterOperateMethod)(IICSOperateType* pType);

/*
��˵  ����	1,����ע���������͵ĺ���ָ������
			2,�ú����ɹ����OperateEnum����,������к�����ΪUnregisterOperateType
			3,�õ���������ҵ���߼�����ģ�����,�ͻ��˸�ģ���������
*/
typedef bool (*UnregisterOperateMethod)(IICSOperateType* pType);

/*
��˵  ����	1,�����ѯ�������͵ĺ���ָ������
			2,�ú����ɹ����OperateEnum����,������к�����ΪQueryOperateByTypeInfo
			3,�õ��������ɿͻ��˵���
			4,	pTypeInfo[in]		������ض����������Ϣ
				ppEnum[out]			���ض���������ز�����ö�ٽӿ�		
*/
typedef bool (*QueryOperateByTypeMethod)(IICSTypeInfo* pTypeInfo, IICSEnum** ppEnum);

/*
��˵  ����	1,�����ѯ�������͵ĺ���ָ������
			2,�ú����ɹ����OperateEnum����,������к�����ΪQueryOperateByObject
			3,�õ��������ɿͻ��˵���
			4,	pObject[in]			������ض���ӿ�
				ppEnum[out]			���ض�����ز�����ö�ٽӿ�		
*/
typedef bool (*QueryOperateByObjectMethod)(IICSRtdbObject* pObject, IICSEnum** ppEnum);

typedef bool (*CreateOperateTypeMethod)(const char* TypeName, IICSOperateType** ppType);


#define METHOD_COMMITOPERATE	"CommitOperate"
typedef bool (*CommitOperateMethod)(IICSOperate* pOperate);
#define MODULE_OPERATECLIENT	"OperateClient"

//��������ָ��
typedef CQIPtr<IICSOperateType> ICSOperateType;
typedef CQIPtr<IICSOperate> ICSOperate;

#endif

