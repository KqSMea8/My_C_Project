//imultsrcdao.h

#ifndef _IMULTSRCDAO_PENGSHIKANG_20081204_H_
#define _IMULTSRCDAO_PENGSHIKANG_20081204_H_

#include "../ibasicdao.h"                        // for IBasicDao
#include "../../icsvalue.h"                      // for icsvariant
#include "imultsrcobj.h"                         // for IMultSrcObj
#include <q3sortedlist.h>                        // for Q3SortedList

#define MULTSRCDAO_CLASSID    "cmultsrcdao"
#define MULTSRCDAO_INTFID     "imultsrcdao"

class IMultSrcDao : virtual public IBasicDao
{
public:
	//���ݲɼ�����Դ�Ͳɼ���λ�õõ�����Դλ��
	virtual int GetPositionByID(int nSrcId, int nPntId, int& nObjId, bool bRequery=false) = 0;
	//���ö�����Դ������
	virtual bool SetMultSrcValue(int pos, void* pRawValue, double rawTime, int nQuality) = 0;
	virtual bool SetMultSrcQuality(int pos, int nQuality) = 0;

	virtual bool GetMultSrcValue(int pos, icsvariant& rawValue, double& rawTime, int& nQuality) = 0;
	
	//�������ݶ���ID�õ���Ӧ�Ķ�����Դ����
	virtual Q3SortedList<IMultSrcObj>* GetMultSrcSetByObjectId(int nObjId) = 0;	

	//���ݶ�Դ���ݱ�λ�õõ���Ӧ�Ĳɼ�����Դ��Դ�ź͵��
	virtual bool GetCommSrcID(int pos, int& nSrcId, int& nPntId) = 0;

	//���ݿص����ID������ԴID�õ�������Դ����
	virtual IMultSrcObj* GetMultSrcObjByObjectID(int nObjId, int nSrcId) = 0;

	//���ݶ�Դ���ݱ�λ�õõ���Ӧ�Ĳɼ�����ֵ
	virtual icsvalue GetMultSrcRawValue(int pos) = 0;

	//���ݶ�Դ���ݱ�λ�õõ���Ӧ�Ĳɼ����ݶ���ID
	virtual int GetDataObjectID(int pos) = 0;
};

#endif
