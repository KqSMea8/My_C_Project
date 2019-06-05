//ismicgriddao.h

#ifndef _ICSMICGRIDDAO_PENGSHIKANG_20100324_H_
#define _ICSMICGRIDDAO_PENGSHIKANG_20100324_H_

#include "../../ibasicdao.h"                     // for IBasicDao
#include "../../../scadasrv/scadadatadef.h"      // for ControlLogInfo
#include "../../../smgsrv/smgdatadef.h"          // for MicgridObectInfo
#include "../../../smgsrv/genstatisdef.h"        // for GeneClassStatisInfo

#define CSMICGRIDDAO_CLASSID    "csmicgriddao"
#define CSMICGRIDDAO_INTFID     "ismicgriddao"

class IVoltageDao;
class ISysInfoDao;
class ISmoothCtrlDao;

class ISMicgridDao : virtual public IBasicDao
{
public:
	//�����ݱ�Ķ�̬��Ϣд�����
	virtual void WriteDynamicInfo1() = 0;

	virtual void SetVoltageDao(IVoltageDao* pVoltage) = 0;//���õ�ѹ�ȼ�ʵ�����
	virtual void SetSysInfoDao(ISysInfoDao* pSysInfo) = 0;//����ϵͳ��Ϣʵ�����
	virtual void SetSmoothCtrlDao(ISmoothCtrlDao* pSmoothCtrl) = 0;//����ƽ������ʵ�����
	
	virtual void InitAllMicgridObjectStaticInfo(bool isSwiMgObj=false) = 0;//������΢����̬��Ϣ��ʼ��
	virtual void InitAllMicgridObjectDynamicInfo(bool isSwiMgObj=false) = 0;//������΢����̬��Ϣ��ʼ��
	virtual void InitAllMicgridBufferPowerInfo() = 0;//��ʼ��������΢�����ۼƹ�����Ϣ
	
	virtual double GetBaseU(int pos) = 0;            //�õ�ϵͳ��׼��ѹ	
	virtual double GetMaxU(int pos) = 0;             //�õ�ϵͳ��������ѹ
	virtual double GetMinU(int pos) = 0;             //�õ�ϵͳ��С�����ѹ
	virtual double GetMaxF(int pos) = 0;             //�õ�ϵͳ�������Ƶ��
	virtual double GetMinF(int pos) = 0;             //�õ�ϵͳ��С����Ƶ��
	virtual double GetAimF(int pos) = 0;             //�õ��µ�Ŀ��Ƶ��
	virtual double GetLoadAdjustCoef(int pos) = 0;   //�õ����ɵ���ϵ��
	virtual int GetParentMicgridID(int pos) = 0;     //�õ��ϼ�΢����ID
	virtual int GetConnectStatusID(int pos) = 0;     //�õ�������־״̬��ID
	virtual int GetConnectFlag(int pos) = 0;         //�õ�΢�����������б�־
	virtual bool IsRootMicgridPos(int pos) = 0;      //�ж��Ƿ�Ϊ��΢����
	virtual bool IsSonMicgridID(int id, int dadId) = 0;//�Ƿ�Ϊָ��΢����ID����΢����ID
	virtual int GetRootMicgridIDById(int id) = 0;    //�õ���΢����ID
	virtual double GetTurnTime(int pos) = 0;         //�õ�����Ĳ������л�ʱ��
	virtual double GetStaticTime(int pos) = 0;       //�õ�ͳ�ƿ�ʼʱ��
	virtual double GetIslandRunTime(int pos) = 0;    //�õ��µ�������ʱ��
	virtual int GetVoltGradeId(int pos) = 0;         //�õ�ϵͳ��ѹ�ȼ�ID	
	virtual double GetSysU(int pos) = 0;             //�õ�ϵͳ��ѹ
	virtual double GetSysUById(int id) = 0;          //�õ�ϵͳ��ѹ
	virtual double GetSysF(int pos) = 0;             //�õ�ϵͳƵ��
	virtual int GetSysUState(int pos, double& smgU) = 0;//�õ�ϵͳ��ѹ�ϸ�״̬��-2--δ������-1--Խ���ޣ�0--�ϸ�1--Խ���ޡ�
	virtual int GetSysFState(int pos, double& smgF) = 0;//�õ�ϵͳƵ�ʺϸ�״̬��-2--δ������-1--Խ���ޣ�0--�ϸ�1--Խ���ޡ�
	virtual double GetExchangeP(int pos) = 0;        //�õ������й�����
	virtual double GetExchangeQ(int pos) = 0;        //�õ������޹�����
	virtual double GetLackingP(int pos) = 0;         //�õ������й�ȱ��
	virtual double GetLackingQ(int pos) = 0;         //�õ������޹�ȱ��
	virtual double GetTotalGenP(int pos) = 0;        //�õ��ܷ����й�����
	virtual double GetTotalGenQ(int pos) = 0;        //�õ��ܷ����޹�����
	//virtual double GetWindP(int pos) = 0;            //�õ����������й����� delete_by_zp_130315
	//virtual double GetWindQ(int pos) = 0;            //�õ����������޹����� delete_by_zp_130315
	//virtual double GetPvP(int pos) = 0;              //�õ���������й����� delete_by_zp_130315
	//virtual double GetPvQ(int pos) = 0;              //�õ���������޹����� delete_by_zp_130315
	//virtual double GetTurbineP(int pos) = 0;         //�õ�ȼ���ֻ��й����� delete_by_zp_130315
	//virtual double GetTurbineQ(int pos) = 0;         //�õ�ȼ���ֻ��޹����� delete_by_zp_130315
	//virtual double GetFuelcellP(int pos) = 0;        //�õ�ȼ�ϵ���й����� delete_by_zp_130315
	//virtual double GetFuelcellQ(int pos) = 0;        //�õ�ȼ�ϵ���޹����� delete_by_zp_130315
	virtual double GetStorageP(int pos) = 0;         //�õ������й�����
	virtual double GetStorageQ(int pos) = 0;         //�õ������޹�����
	virtual double GetStorageMaxP(int pos) = 0;      //�õ���������й�����
	virtual double GetTotalLoadP(int pos) = 0;       //�õ����й�����
	virtual double GetTotalLoadQ(int pos) = 0;       //�õ����޹�����
	virtual double GetSensitiveLoadP(int pos) = 0;   //�õ����������й�
	virtual double GetSensitiveLoadQ(int pos) = 0;   //�õ����������޹�
	virtual double GetControllableLoadP(int pos) = 0;//�õ��ɿظ����й�
	virtual double GetControllableLoadQ(int pos) = 0;//�õ��ɿظ����޹�
	virtual double GetCutedLoadP(int pos) = 0;       //�õ����и����й�
	virtual double GetCutedLoadQ(int pos) = 0;       //�õ����и����޹�
	//--------------zff_0814_0815_new_add-----------------------------//
	virtual double GetMaxVol2(int pos) = 0;          //�õ�ϵͳ��ѹ������������
	virtual double GetMinVol2(int pos) = 0;          //�õ�ϵͳ��ѹ������������
	virtual double GetMaxF2(int pos) = 0;            //�õ�ϵͳƵ�ʽ�����������
	virtual double GetMinF2(int pos) = 0;            //�õ�ϵͳƵ�ʽ�����������

	virtual int GetCurStyleId(int pos) = 0;          //�õ���ǰ���з�ʽID
    virtual double GetLastSwitchTime(int pos) = 0;   //�õ��ϴ����з�ʽ�л�ʱ��
	virtual bool SetLastSwitchTime(int pos, double switchtime) = 0;   //�����ϴ����з�ʽ�л�ʱ��   --sunr add
 	virtual bool SetCurStyle(int pos, int styleId) = 0;//���õ�ǰ���з�ʽID
   //--------------------------------------------------------//
	virtual int ModifyConnectFlag(int pos, bool isConnect, double curTime) = 0;//�޸�΢�����������б�־
	virtual bool SetStaticTime(int pos, double durTime) = 0;//����ͳ�ƿ�ʼʱ��
	virtual bool SetIslandRunTime(int pos, double runTime) = 0;//���ùµ�������ʱ��
	virtual bool SetAimF(int pos, double aimF) = 0;//���ùµ�Ŀ��Ƶ��
	virtual bool SetSysUF(int pos, double sysU, double sysF) = 0;//����ϵͳ��ѹ
	virtual bool SetExchangePQ(int pos, double valueP, double valueQ) = 0;//���ý�������
	virtual bool SetLackingPQ(int pos, double valueP, double valueQ) = 0;//���ù�������ȱ��
	//������΢���ܵķ��繦��. ������isRefGener--�Ƿ�Ϊ��˷������canAdjP--�Ƿ�Ϊ���ʿɵ������
	virtual bool IncreaseTotalGenPQ(MicgridObectInfo* pCurMgObj, const GeneClassStatisInfo& genSttsInfo, 
		int genType, int runState, bool isRefGener, bool canAdjP) = 0;
	virtual bool IncreaseTotalLoadPQ(MicgridObectInfo* pCurMgObj, int loadType, double valueP, double valueQ) = 0; //������΢���ܵĸ��ɹ���

	//����ָ��λ��΢���Ľ������ʺ�ȱ���
	virtual void SetExchangeAndLackingPQ(int pos) = 0;

	virtual MicgridObectInfo* GetMicgridObject(int pos) = 0;
	virtual MicgridObectInfo* GetSwitchSMGObject(int pos) = 0;
	virtual void InitSmoothAttrOfMicgridObject(MicgridObectInfo* pCurMgObj) = 0;//��΢����ƽ�����ƾ�̬��Ϣ��ʼ��
	
	virtual int GetStartState(int pos) = 0;       //�õ�������״̬
	virtual double GetStartTime(int pos) = 0;     //�õ���������ʼʱ��
	virtual double GetCurRemainP(int pos) = 0;    //�õ���ǰ����Դ����������
	virtual int GetCurActType(int pos) = 0;       //�õ���ǰ��������
	virtual int GetCurObjectId(int pos) = 0;      //�õ���ǰ��������ID
	virtual int GetCurObjectType(int pos) = 0;    //�õ���ǰ������������
	virtual double GetCurTime(int pos) = 0;       //�õ���ǰ����ʱ��
	virtual double GetPrevreMainP(int pos) = 0;   //�õ���ǰ����Դ����������
	virtual int GetPrevActType(int pos) = 0;      //�õ���ǰ��������
	virtual int GetPrevObjectId(int pos) = 0;     //�õ���ǰ��������ID
	virtual bool SetStartState(int pos, int start) = 0;      //���ú�����״̬
	virtual bool SetStartTime(int pos, double time) = 0;     //���ú�������ʼʱ��
	virtual bool SetCurRemainP(int pos, double remainP) = 0; //���õ�ǰ����Դ����������
	virtual bool SetCurActType(int pos, int actType) = 0;    //���õ�ǰ��������
	virtual bool SetCurObjectId(int pos, int objectId) = 0;  //���õ�ǰ��������ID
	virtual bool SetCurObjectType(int pos, int objType) = 0; //���õ�ǰ������������
	virtual bool SetCurTime(int pos, double time) = 0;       //���õ�ǰ����ʱ��
	virtual bool SetPrevreMainP(int pos, double remainP) = 0;//������ǰ����Դ����������
	virtual bool SetPrevActType(int pos, int actType) = 0;   //������ǰ��������
	virtual bool SetPrevObjectId(int pos, int objectId) = 0; //������ǰ��������ID
	virtual void InitCurControlInfo(int id, bool needGuard, ControlLogInfo& ctrlInfo) = 0;//��ʼ����ǰ������Ϣ
	virtual bool GetCurControlInfo(int pos, ControlLogInfo& ctrlInfo) = 0;//�õ���ǰ������Ϣ
	virtual bool SetCurControlInfoByID(int id, const ControlLogInfo& ctrlInfo, bool isBefore=false) = 0;//���õ�ǰ������Ϣ
	virtual bool SetCurControlInfo(int pos, const ControlLogInfo& ctrlInfo, bool isBefore=false) = 0;//���õ�ǰ������Ϣ
	virtual bool SetCurControlState(int pos, int ctrlReason) = 0;//���õ�ǰ�����������������

	virtual bool IsEnableStart(int pos) = 0;      //�ж��Ƿ���ں���������
	virtual bool InitAutoBlackStart(int pos, double curTime) = 0;//�����Զ�������״̬
	virtual bool EndBlackStart(int pos, double curTime) = 0;
	virtual bool RecordBlackStart(int pos, int actType, int objectId, double remainP, double curTime) = 0;
	virtual bool RecordBlackStartByID(int id, int actType, int objectId) = 0;

	//-------------sunr add-------------------//
	virtual double GetMaxWindRate(int pos) = 0;              //�õ������������������͸��
	virtual double GetMaxPVRate(int pos) = 0;                //�õ������������������͸��
	virtual double GetCurWindRate(int pos) = 0;              //�õ��������統ǰ��͸��
	virtual double GetCurPVRate(int pos) = 0;                //�õ������ǰ��͸��
	virtual bool SetCurWindRate(int pos, double rate) = 0;   //���÷������統ǰ��͸��
	virtual bool SetCurPVRate(int pos, double rate) = 0;     //���ù����ǰ��͸��
	virtual bool IsActive(int pos) = 0;                      //�ж�΢�����Ƿ����
	virtual switchgridobj* GetSwitchObject(int pos) = 0;
	virtual int GetStorFreqCtrlStateId(int pos) = 0;         //�õ����ܵ�Ƶ�ʵ���״̬ID��ң����ID��
	virtual int GetStorVoltCtrlStateId(int pos) = 0;         //�õ����ܵĵ�ѹ����״̬ID��ң����ID��

	virtual double GetCurCap(int pos) = 0;                   //�õ�΢����ǰ��������
	virtual double GetSpareCap(int pos) = 0;                 //�õ�΢����ǰ��������
	virtual int GetCurCheckType(int pos) = 0;                //�õ���ǰ�����������
	virtual int GetCtrlReason(int pos) = 0;                  //�õ���ǰ����ԭ��

	virtual bool SetCurCap(int pos, double& cap) = 0;        //����΢����ǰ��������
	virtual bool SetSpareCap(int pos, double& cap) = 0;      //����΢����ǰ��������
	virtual bool SetCurCheckType(int pos, int& type) = 0;    //���õ�ǰ�����������
	virtual bool SetCtrlReason(int pos, int& reason) = 0;    //���õ�ǰ����ԭ��
	virtual double GetTotalGenCapacity(int pos) = 0;         //�õ�΢��װ������
	//΢�����й���������һ�ε���������
	virtual double GetMicgridMaxAdjustPower(MicgridObectInfo* pCurMgObj) = 0;

	//�õ���ǰAGCִ�мƻ�ID
	virtual int GetCurAGCPlanID(int pos) = 0;
	//�õ���ǰAGC�й�Ŀ��ֵ
	virtual double GetCurAGCAimVal(int pos) = 0;
	//���浱ǰAGCִ�мƻ�ID���й�Ŀ��ֵ
	virtual bool SaveCurAGCPlanValue(int pos, int agcPlanId, double aimPower) = 0;
	//�Ƿ���ڡ���ǰAGCִ�мƻ�ID���ֶ�
	virtual bool HasAGCPlanID() = 0;

	//��ȡ��ǰ���Ƽ�¼�洢��־
	virtual int ReadSaveFlag(int pos) = 0;
	//���浱ǰ������Ϣ
	virtual bool SaveCurControlInfo(int pos) = 0;

	//�õ�AGC�������״̬
	virtual bool CanControlAgc(int pos) = 0;
	//���汣��AGC�������״̬��־
	virtual bool SaveCanCtrlAgcFlag(int pos, bool canCtrl) = 0;

};
#endif
