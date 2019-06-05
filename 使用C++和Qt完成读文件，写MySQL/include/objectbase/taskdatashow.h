//taskdatashow.h
#ifndef _TASKDATASHOW_20080122_PENGSHIKANG_H_ 
#define _TASKDATASHOW_20080122_PENGSHIKANG_H_

#include <qfile.h>
#include <map>
#include "icsvariant.h"
#include "objectbase.h"

class IICSRtdbObject;
class IICSTaskObject;

typedef std::multimap<QString, icsarray*> ARYMAP;

//�õ��ֶ���������
void OBJECTBASE_EXPORT FieldTypeToString(FIELDTYPE ft, char* sType);

//�ж�icsvariant�����ֵ�Ƿ�Ϊ��ֵ
bool OBJECTBASE_EXPORT VariantIsNull(const icsvariant& var);
//����icsvariant�����ֵΪ��ֵ
void OBJECTBASE_EXPORT SetNullVariant(icsvariant& var);

//ʱ�������ֵת��Ϊ��׼ʱ���ַ���
void OBJECTBASE_EXPORT CDatetimeToString(double dTime, char* sTime);
//IICSUnknown�����ֵת��Ϊ�ַ���
void OBJECTBASE_EXPORT GetUnknownObjectString(char* strOut, IICSUnknown* pUnk);

//����Ԫ��ֵת��Ϊ�ַ���
void OBJECTBASE_EXPORT GetElementString(char* strOut, FIELDTYPE ft, void* pValue, int index=0);
//icsarray�����ֵת��Ϊ�ַ���
void OBJECTBASE_EXPORT GetArrayString(char* strOut, const icsarray& ary, const char* sep=",");
//icsvariant�����ֵת��Ϊ�ַ���
bool OBJECTBASE_EXPORT GetVariantString(char* strOut, const icsvariant& var, const char* sep=",", bool bShowNull=false);
//�õ��ֶ�����Ԫ����Ϣ�ַ���
QString OBJECTBASE_EXPORT ICSArrayToString(const char* name, icsarray* pAry, int index, int order1, int order2=-1);

//�������һ���µ��������
void OBJECTBASE_EXPORT CopyArray(icsarray& arySrc, icsarray* aryDest);
//�ͷ�����ռ�õ��ڴ�ռ�
void OBJECTBASE_EXPORT FreeArray(icsarray* pAry);
//�ͷ������б�ռ�õ��ڴ�ռ�
void OBJECTBASE_EXPORT FreeArrayList(ARYMAP& aryList);

//����icsvariant������Ϣ����ֵ���������������Ϣ��������������������б�
void DealICSVariant(const char* name, const icsvariant& valu, QString& strContext, 
	ARYMAP& arrayList, ARYMAP& childList);
//����һά����)���飬�õ�ָ����ŵĶ�ά���ӣ��������Ԫ��������
int OBJECTBASE_EXPORT GetHeadPosOfChildArray(icsarray* aryParent, int groupNo);

//�������һ����������Ԫ����Ϣ
void OBJECTBASE_EXPORT OutputArrayList(QString& strContext, ARYMAP& arrayList, ARYMAP& childList);

//��������ַ�����Ϣд����־�ļ�
void OBJECTBASE_EXPORT WriteLogToFile(const char* fileName, const char* outInfo, QIODevice::OpenMode mode, bool timestamp=true);

//����ת��ΪBYTE����
bool OBJECTBASE_EXPORT VariantToByte(const icsvariant& var, BYTE& bOut);
//����ת��Ϊshort����
bool OBJECTBASE_EXPORT VariantToShort(const icsvariant& var, short& sOut);
//����ת��Ϊint����
bool OBJECTBASE_EXPORT VariantToInt(const icsvariant& var, int& iOut);
//����ת��Ϊfloat����
bool OBJECTBASE_EXPORT VariantToFloat(const icsvariant& var, float& fOut);
//����ת��Ϊdouble����
bool OBJECTBASE_EXPORT VariantToDouble(const icsvariant& var, double& dOut);

#endif