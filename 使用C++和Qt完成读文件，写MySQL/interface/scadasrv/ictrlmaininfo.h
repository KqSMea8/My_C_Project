/*******************************************************
 * ictrlmaininfo -- �����Scada������ҵ����������ݽӿ�
 *******************************************************/

#ifndef __ICONTROLMAININFOMATION_PENGSHIKANG_H_20171221
#define __ICONTROLMAININFOMATION_PENGSHIKANG_H_20171221

#include "scadadatadef.h"// for CONTROLORIGIN��AUTOEXECUTESELECTCMD

class IExpressCalculate;
class ICtrlRelatData;

class ICtrlMainInfo
{
public:
	//0--
	virtual void SetExprCalc(IExpressCalculate* pExprCalc) = 0;
	virtual void SetControlData(ICtrlRelatData* pCtrlData) = 0;
	virtual ICtrlRelatData* MakeControlData(int ctrlPos, int commsrcId) = 0;//(2_0)����ң�ع���������������ʹ�����
	virtual void InitializeMe(ICtrlRelatData* pCtrlData) = 0;

	//1-- ���ÿ������͡��Ƿ�������������㡣
	virtual void SetControlTypeAndCheckCtrl(int ctrlPos, bool bCheckControl) = 0;
	virtual int GetControlType() = 0;                           //�õ����Ʋ�������
	virtual bool IsSelectControl() = 0;                         //�Ƿ�Ϊѡ�ز���
	virtual void SetCheckControlFlag(bool bCheckControl) = 0;   //�����Ƿ���������������־[��δ��]
	virtual bool GetCheckControlFlag() = 0;                     //�õ��Ƿ���������������־

	//2-- �����Ƿ���Ҫ�ȴ����ƽ�����أ�Ⱥ��ʱ����Ϊfalse��
	virtual void SetNeedWaitFlagIn(bool needWait) = 0;
	//�ж��Ƿ���Ҫ�ȴ����ƽ�����أ�Ⱥ��ʱ����false��
	virtual bool GetNeedWaitFlagIn() = 0;
	//�жϿص��Ƿ���Ҫ�ȴ����ƽ��������
	virtual bool NeedWaitCtrlReturn() = 0;

	//3--m_bWaitReturned
	virtual void SetWaitReturned(bool bReturned) = 0;//�����Ƿ�ȴ����ƽ������ [����]
	virtual bool GetWaitReturned() = 0;

	//4-- m_bWaitChanged
	virtual bool NeedCheckChanged() = 0;			//�Ƿ���Ҫ��ң�ű�λ/ң��仯[�ȴ������������]
	virtual void InitWaitChangeFlag() = 0;          //��ʼ���Ƿ�ȴ����ƹ�������ֵ�仯
	virtual bool UpdateWaitChangeFlag() = 0;        //�����Ƿ�ȴ����ƹ�������ֵ�仯 _autoExec != AESC_CONTROL
	virtual bool InWaitChanging() = 0;              //����Ƿ�ȴ����ƹ�������ֵ�仯

	//5-- m_ctrlFlags
	virtual void InitControlFlag() = 0;
	virtual void UpdateControlFlag(int ctrlPos) = 0;
	virtual bool HasControlFlag(int iFlagCode) = 0;

	//6-- m_autoExec
	virtual void InitAutoExecFlag(bool bAutoCtrl) = 0;//��ʼ���Զ�ִ��ѡ�����־
	virtual void SetAutoExecFlag(char autoExec) = 0;
	virtual char GetAutoExecFlag() = 0; //����δ��
	virtual bool AutoToNoguard() = 0;   //����Ƿ�ѡ�ؽ�����غ��Զ�תֱ�ء� [����]

	//7-- m_cmdType
	virtual void InitCommandType() = 0;//��ʼ��ң�ؽ��ȱ�ʶΪ-1 [����]
	virtual void SetCommandType(char cmdType) = 0;
	virtual char GetCommandType() = 0;//ң�ؽ��ȱ�ʶ��-2���ȴ��໤�����أ�-1��δ��ʼ��0��ѡ����ƣ�1��ִ�п��ƣ�2���������ƣ�

	//8-- m_ctrlCode and m_ctrlValueID
	virtual void UpdateCtrlCodeAndValueID(int ctrlValPos) = 0;
	virtual OPERATETYPE GetControlCode() = 0;
	virtual int GetControlValueID() = 0;

	//9-- m_ctrlValue and m_aimValue
	virtual void UpdateAimValueAndCtrlValue(int ctrlId, const char* newValue) = 0;
	virtual void SetCtrlValueAndAimValue(float ctrlValue, double aimValue) = 0;//���ÿ���ֵ��Ŀ��ֵ[���������]
	virtual void GetCtrlValueAndAimValue(float& ctrlValue, double& aimValue) = 0;//��ȡ����ֵ��Ŀ��ֵ
	virtual void SetCtrlValue(float ctrlValue) = 0;//���ÿ���ֵ
	virtual void SetAimValue(double aimValue) = 0;//����Ŀ��ֵ
	virtual float GetCtrlValue() = 0;//���ÿ���ֵ
	virtual double GetAimValue() = 0;//��ȡĿ��ֵ

	// 10-- m_wfmode
	virtual void InitWFMode() = 0;//��ʼ���������ģʽ��m_wfmode = 0
	virtual void UpdateWFMode(int ctrlPos) = 0;//�����������ģʽ
	virtual bool HasWFCheck(int wfMode) = 0;   //�Ƿ����������

	//11-- m_userName and m_posterName
	//�����û�������Ϣ����������
	virtual void SetUserAndPosterName(const char* sUserName, const char* psPoster) = 0;
	//��ʼ���û�������Ϣ����������
	virtual void InitUserAndPosterName() = 0;
	//�����û���
	virtual void SetUserName(const char* sUserName) = 0;
	//��ʼ���û���
	virtual void InitUserName() = 0;
	//�õ��û���ָ��
	virtual const char* GetUserName() = 0;
	//��ȡ��Ϣ����������
	virtual void TakePosterName(char* psName) = 0;

	//��1�����ݿ�����λ�õõ������Ĳ��������͡�ң��ң����ID��
	virtual int GetRelativeMeasureObjectIdIn(int ctrlPos, int& measType) = 0;
	//��2�����ݿ�����λ�ú�ң����Ŀ��ֵ�õ����ƶ�Ӧ��ң����ID�����������롣
	virtual bool GetCtrlTypeByAimValueIn(int ctrlPos, int aimValue, int& statusId, OPERATETYPE& ctrlType) = 0;
	//��3�����ݿ�����λ�úͲ���������õ����ƶ�Ӧ�Ŀ���ֵ���ͼ�¼λ�á���������ֵ��
	virtual bool GetCtrlValueByCtrlTypeIn(int ctrlPos, OPERATETYPE ctrlType, int& ctrlValTypPos, int& ctrlValue) = 0;

	//��4�����ݿ������Ĳ��������롢���������ͺ�ID�õ����ƶ�Ӧ�Ĳ�����λ�ú�Ŀ��ֵ������ֵ��0, ʧ�ܣ�1, Ŀ��ֵΪ��ǰֵ��2, Ŀ��ֵΪ��ֵ��
	virtual int GetAimValueByDataType(OPERATETYPE ctrlType, int dataType, int dataID, int& dataPos, int& aimValue) = 0;
	//��5�����ݿ�����λ�úͲ���������õ����ƶ�Ӧ��Ŀ��ֵ������ֵ��0, ʧ�ܣ�1, Ŀ��ֵΪ��ǰֵ��2, Ŀ��ֵΪ��ֵ��
	virtual int GetAimValueByCtrlType(int ctrlPos, OPERATETYPE ctrlType, int& aimValue) = 0;
	//��6�����ݿ�����λ�úͿ���ֵ����ID�õ����ƶ�Ӧ�Ŀ���ֵ���ͼ�¼λ�á���������ֵ��ң����Ŀ��ֵ[ң�ر����]
	virtual bool GetAimValueByCtrlValTypID(int ctrlPos, int ctrlValTypId, int& ctrlValTypPos, int& ctrlValue, int& aimValue) = 0;
	//��7�����ݿ�����λ�úͿ�������ֵ�õ����ƶ�Ӧ�Ĳ�������͡�����ֵ���ͼ�¼λ�á���������ֵ��ң����Ŀ��ֵ[ң�ر����]
	virtual bool GetAimValueByCtrlValueIn(int ctrlPos, int ctrlValue, int& measTypeId, OPERATETYPE& ctrlType, int& ctrlValTypPos, int& aimValue) = 0;

	//��8�����ݿ�����λ�úͲ���������õ����ƶ�Ӧ�������͡�ID��λ�ú�Ŀ��ֵ������ֵ��0, ʧ�ܣ�1, Ŀ��ֵΪ��ǰֵ��2, Ŀ��ֵΪ��ֵ��
	virtual int GetControlAimValueIn(int ctrlPos, OPERATETYPE ctrlType, int& dataType, int& dataID, int& dataPos, int& aimValue) = 0;
	//��9�����ݿ�����λ�õõ����ƶ�Ӧ�������͡�ID��λ�ú͵�ǰֵ������ֵ��0, ʧ�ܣ�1, Ŀ��ֵΪ��ǰֵ��2, Ŀ��ֵΪ��ֵ��
	virtual bool GetControlCurValueIn(int ctrlPos, int& dataType, int& dataID, int& dataPos, double& curValue) = 0;
	//��10�����ݿ������������͡��������λ�ú�Ŀ��ֵ���������Ƿ��ѴﵽĿ��ֵ��
	virtual bool CheckControlEnabledIn(OPERATETYPE ctrlType, int dataPos, int aimValue) = 0;
	//��11�����ݿ�������������λ�á���ǰֵ��Ŀ��ֵ���������Ƿ��ѴﵽĿ��ֵ��
	virtual bool CheckAdjustEnabledIn(int dataPos, double curValue, double aimValue) = 0;

	//��12����������ID�Ƿ���Խ����Զ����Կ��ơ�autoType��1--AGC���ԣ�2--AVC����
	virtual bool CanAutoControlIn(int ctrlId, int ctrlType, int autoType) = 0;

	//(13)�õ����ƹ������������ʽ
	virtual bool GetDummyExpr(int exprPos, char* strExpr, char* sErrorInfo) = 0;
	//(14)��¼���Ƴɹ���Ϣ[ң�ر����]
	virtual void RecordControlSuccess(int ctrlId) = 0;

};

#endif