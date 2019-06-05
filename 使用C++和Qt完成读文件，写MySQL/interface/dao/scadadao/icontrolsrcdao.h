//icontrolsrcdao.h

#ifndef _ICONTROLSRCDAO_PENGSHIKANG_20180801_H_
#define _ICONTROLSRCDAO_PENGSHIKANG_20180801_H_

#include "../ibasicdao.h"                        // for IBasicDao
#include "../../icsvalue.h"                      // for icsvariant
#include "imultsrcobj.h"                         // for IMultSrcObj
#include <q3sortedlist.h>                        // for Q3SortedList

#define CTRLSRCDAO_CLASSID    "ccontrolsrcdao"
#define CTRLSRCDAO_INTFID     "icontrolsrcdao"

class IControlSrcDao : virtual public IBasicDao
{
public:
	//�õ��ֶ�������
	virtual void GetFieldIndexs() = 0;
	//��ȡ���ݱ�ľ�̬��Ϣ
	virtual void ReadStaticInfo(int fldNum=0, const char nameList[][64]=0, const char* strFilter="DELETEFLAG==0", bool onlyRead=false) = 0;

	//���ݶ�����Դλ�õõ�ң����ID
	virtual int GetControlId(int pos) = 0;
	//���ݶ�����Դλ�õõ����ݲɼ�ԴID
	virtual int GetCommsrcId(int pos) = 0;
	//���ݶ�����Դλ�õõ����ݲɼ�Դ��ID
	virtual int GetPointId(int pos) = 0;
	//���ݶ�����Դλ�õõ����ȼ�
	virtual int GetPriority(int pos) = 0;

	//�������ݶ���ID�õ���Ӧ�Ķ�����Դ����
	virtual Q3SortedList<IMultSrcObj>* GetMultSrcSetByObjectId(int nObjId) = 0;

	//���ݿص����ID������ԴID�õ�������Դ����
	virtual IMultSrcObj* GetMultSrcObjByObjectID(int nObjId, int nSrcId) = 0;

};

#endif
