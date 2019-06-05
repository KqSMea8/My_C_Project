#ifndef _EXPRESSIONAPI_H_
#define _EXPRESSIONAPI_H_

#include "icsunknown.h"

//����ӿ����Ƴ���
#define IID_IICSExpression		"IICSExpression"

//����������Ƴ���
#define CLSID_Expression		"expression"

/*
IICSExpression���ʽ�����ӿ�
*/
class IICSExpression : public IICSUnknown
{
public:
    /*
        ����  �ܡ�      ���ñ��ʽ
        ����  ����      express: ���ʽ�ַ���
    */
	virtual void SetExpression(const char* express) = 0;

    /*
        ����  �ܡ�      ���ʽ��Ч?
        ����  ����
    */
	virtual bool IsValid() = 0;

    /*
        ����  �ܡ�      ��ñ��ʽ�б�������
        ����  ����      
    */
	virtual int VarCount() = 0;

    /*
        ����  �ܡ�      ��ñ�������
        ����  ����      index: �������
    */
	virtual const char* VarName(int index) = 0;

    /*
        ����  �ܡ�      ���ñ�����ֵ
        ����  ����      index:������� val: ������ֵ
    */
	virtual void SetVarValue(int index, double val) = 0;

    /*
        ����  �ܡ�      ��ñ��ʽ����ֵ
        ����  ����      ��
    */
	virtual double Value() = 0;

    /*
        ����  �ܡ�      ���ʽ����Ĵ�����Ϣ(�﷨����)
        ����  ����      ��
    */
	virtual const char* GetLastError() = 0;
public:
    static char *GetIntfName()
    {
        return IID_IICSExpression;
    };
};

//���崴�������������Լ���������(for class)
//typedef bool (*GetClassObjectMethod)(char *classname, IICSUnknown** ppUnk);
//#define METHOD_GETCLASSOBJECT "GetClassObject"

//�������ģ������
#define MODULE_EXPRESSION	"expression"


#endif