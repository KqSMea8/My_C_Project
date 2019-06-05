//isqctrlitemdao.h

#ifndef _ISQCTRLITEMDAO_SUNRUI_20140425_H_
#define _ISQCTRLITEMDAO_SUNRUI_20140425_H_

#include "../ibasicdao.h"                        // for IBasicDao
#include "isqctrlitemobj.h"                      // for ISqctrlItemObj
#include <q3sortedlist.h>                        // for Q3SortedList

#define SQCTRLITEMDAO_CLASSID    "csqctrlitemdao"
#define SQCTRLITEMDAO_INTFID     "isqctrlitemdao"

class ISqCtrlitemDao : virtual public IBasicDao
{
public:
	//����˳�ؼƻ�ID�Ϳ��Ʋ���ŵõ�˳����λ��
	virtual int GetStepPos(int sqctrlid, int stepid) = 0;
	//����˳����λ�ö�ȡ˳����Ƽƻ�ID
	virtual int GetSqCtrlID(int pos) = 0;
	//����˳����λ�ö�ȡ���Ʋ����
	virtual int GetStepID(int pos) = 0;
	//����˳����λ�ö�ȡ���Ƶ�ID
	virtual int GetCtrlID(int pos) = 0;
	//����˳����λ�ö�ȡ����Ŀ��ֵ
	virtual double GetCtrlValue(int pos) = 0;
	//����˳����λ�ö�ȡ������������
	virtual const char* GetStartInfo(int pos) = 0;
	//����˳����λ�ö�ȡʧ�ܺ��Ƿ��������
	virtual int IsContinue(int pos) = 0;
	//����˳����λ�ö�ȡ�Ƿ���Ҫ�û�ȷ�ϲ�ִ��
	virtual int IsConfirm(int pos) = 0;
	//����˳����λ�ö�ȡ�Ƿ���Ҫ������һ��ִ��
	virtual int IsSkip(int pos) = 0;
	//����˳����λ�ö�ȡʧ�ܺ��ظ����ƴ���
	virtual int GetRepeattimes(int pos) = 0;
	//����˳����λ�ö�ȡ���ƽ�����ȴ�ʱ�䣨��λs��
	virtual int Getwaitsecond(int pos) = 0;
	//����˳����λ�ö�ȡ��ǰ����״̬
	virtual int GetCurState(int pos) = 0;
	//����˳����λ�ö�ȡң���Ƿ�ɹ�
	virtual int GetSuccessFlag(int pos) = 0;
	//����˳����λ�ö�ȡ�Ƿ�洢
	virtual int GetSaveFlag(int pos) = 0;

	//����˳����λ�����õ�ǰ����״̬
	virtual bool SetCurState(int pos, int state) = 0;
	//����˳����λ������ң�سɹ���־
	virtual bool SetSuccessFlag(int pos, int flag) = 0;
	//����˳����λ�������Ƿ�洢��־
	virtual bool SetSaveFlag(int pos, int flag) = 0;
	//����˳�������
	virtual bool SetSqctrlitemResult(int pos, int curState, bool isSuccess) = 0;

	//����˳��ID�õ���Ӧ��˳�������
	virtual Q3SortedList<ISqctrlItemObj>* GetSqctrlItemSetByObjectId(int nObjId) = 0;	

	//����˳����λ�����ÿ���Ŀ��ֵ
	virtual bool SetCtrlValue(int pos, double ctrlValue) = 0;
	//����˳����λ�ö�ȡ�������͡�0--ң��ң����1--ң��������2--ң��������3--ң��������
	virtual int GetOperateType(int pos) = 0;
	//����˳����λ�ö�ȡ����ֵ���ʽ��
	virtual bool GetOperateValueExpress(int pos, char CtrlValExpr[256]) = 0;

};

#endif
