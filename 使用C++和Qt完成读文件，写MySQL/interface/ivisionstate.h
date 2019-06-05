#ifndef __VISIONSTATE__H_
#define __VISIONSTATE__H_

#include "objsintf.h"

#define IID_IVisionState		"ivisionstate"
#define IID_IVisionStateEvent	"ivisoneventstate"
#define CLSID_VisionState		"visionstate"
#define MOUDLE_VISIONSTATE		"visionstate"

#define ISimulateState IVisionState
#define ISimulateStateEvent IVisionStateEvent

//�������ֲ���״̬{��������״̬,ģ�����״̬,���򻯲�������}
typedef enum{ SIM_NORMAL = 0, SIM_OPERATE, SIM_PROGRAM, SIM_TICKET }VISIONSTATE;

class IVisionStateEvent;
class IVisionState : public IICSUnknown
{
public:
	virtual bool SwitchState(VISIONSTATE src, VISIONSTATE dst) = 0;
	virtual VISIONSTATE GetCurState() = 0;
	virtual bool GetObject(const char* clsid, int objid, int& val) = 0;
	virtual void RegEventSinker(IVisionStateEvent* pVisionStateEvent) = 0;
	virtual void UnRegEventSinker(IVisionStateEvent* pVisionStateEvent) = 0;

	virtual void AddObject(VISIONSTATE state, int objid,int val) = 0;
	virtual void DelObject(VISIONSTATE state, const char* clsid, int objid) = 0;
	virtual void ClearObject(VISIONSTATE state) = 0;
public:
    static char *GetIntfName()
    {
        return IID_IVisionState;
    };
};

//������մ��¼�ӦPostEvent��������
class IVisionStateEvent : public IICSUnknown
{
public:
	virtual void OnSwitchState(VISIONSTATE src, VISIONSTATE dst) = 0;
public:
    static char *GetIntfName()
    {
        return IID_IVisionStateEvent;
    };
};

#endif
