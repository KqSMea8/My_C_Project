//isettingenumdao.h

#ifndef _ISETTINGENUMDAO_PENGSHIKANG_20131224_H_
#define _ISETTINGENUMDAO_PENGSHIKANG_20131224_H_

#include "../ibasicdao.h"                        // for IBasicDao
#include <QStringList>                           // for QStringList

#define SETTINGENUMDAO_CLASSID    "csettingenumdao"
#define SETTINGENUMDAO_INTFID     "isettingenumdao"

//����ö�����ݶ���
class ISettEnumDao : virtual public IBasicDao
{
public:	
	//����ö�����ݼ�¼λ�õõ�ö��ֵ����
	virtual const char* GetEnumValues(int pos) = 0;
	//����ö�����ݼ�¼λ�õõ�ö����������
	virtual const char* GetEnumDescrips(int pos) = 0;
	//����ö�����ݼ�¼λ�õõ�ö��ֵ���Լ���
	virtual const char* GetEnumVal_Names(int pos) = 0;
	//����ö�����ݼ�¼λ�õõ�ö��ֵ�����б�
	virtual bool GetEnumVal_NameList(int pos, QStringList& valNames) = 0;
};

#endif
