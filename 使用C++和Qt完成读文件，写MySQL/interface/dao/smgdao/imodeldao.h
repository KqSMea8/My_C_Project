//imodeldao.h

#ifndef _IMODELDAO_SUNRUI_20130311_H_
#define _IMODELDAO_SUNRUI_20130311_H_

#include "../ibasicdao.h"                        // for IBasicDao

#define MODELDAO_CLASSID    "cmodeldao"
#define MODELDAO_INTFID     "imodeldao"

class IModelRunStyleDao;
class ISmgRunstyleDao;

class IModelDao  : virtual public IBasicDao 
{
public:
	//��������ģʽ������΢�������з�ʽ���б�ֵ
	virtual void CreateSmgRunstyleIdList(IModelRunStyleDao* pModelRunStyle, ISmgRunstyleDao* pSmgRunstyle) = 0;

	//�õ���ǰ΢����ϵͳ������ģʽid
	virtual int GetSysCurRunModelId(int modePos) = 0;

	//�õ�ָ������ģʽid��΢����id������Դ���з�ʽ
	virtual bool GetRunstyleIdbyModelandMicgrid(int modelid, int micgridid, int& runstyleid) = 0;

	//��������ģʽλ�û�ȡ����ģʽ״̬ID
	virtual int GetStyleStateID(int pos) = 0;

};

#endif
