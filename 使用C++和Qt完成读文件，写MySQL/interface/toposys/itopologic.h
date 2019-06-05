/////////////////////////////////////////////////////////////
//�ļ�����			itopologic.h: interface for the ITopologic class.
//�ӿ�˵����		�μ����ӿں�����ע�Ͳ���
//��Ҫ���ܣ�		�������˷���������ͷ�ļ�
//�����ߣ�			������
//�������ڣ�		2012.06.03
//�汾��			1.0�棻
//��Ȩ��Ϣ:			��������������
//���ļ�¼��		����ʱ�䣺2012-06-03, �����ˣ���������Peng Shikang, psk��
/////////////////////////////////////////////////////////////

#ifndef __INTFNEWTOPOLOGIC_PENGSHIKANG_20120603_HEADER__
#define __INTFNEWTOPOLOGIC_PENGSHIKANG_20120603_HEADER__

#include "topodatadef.h"   //for TopoNetwork, etc.
#include "../icsunknown.h" //for IICSUnknown

#define MODULE_TOPOLOGIC      "topologic"
#define CLSID_TOPOLOGIC       "cls_topologic"
#define IID_TOPOLOGIC         "intf_topologic"

/*
ITopologic�ӿ�
*/
class ITopologic : public IICSUnknown
{
public: 
	
	////////////////////////////////////////////////////////////////////////////////
	/* ���º����������˷���ģ������ */
	////////////////////////////////////////////////////////////////////////////////
	
	//(1)���뾲̬��Ϣ
	//��������������Ϣ������pNetworkΪ�����ϵͳ��Ϣָ�롣
	virtual bool SetNetworkInfo(const TopoNetwork* pNetwork) = 0;
	//�����豸������Ϣ������pEqpTypesΪ������豸���������׵�ַ�����鳤����pNetwork������
	virtual bool SetEquipTypeInfo(const TopoEquipType* pEqpTypes) = 0;
	//�����豸��Ϣ������pEquipΪ������豸�����׵�ַ�����鳤����pNetwork������
	virtual bool SetEquipmentInfo(const TopoEquipment* pEquips) = 0;
	//�������ӹ�ϵ��Ϣ������pConnsΪ��������ӹ�ϵ�����׵�ַ�����鳤����pNetwork������
	virtual bool SetConnectionInfo(const TopoConnection* pConns) = 0;

	//(2)���붯̬��Ϣ
	//���¿����豸��ʵʱͨ��״̬��Ϣ������pSwitchsΪ�����豸״̬�����׵�ַ�����鳤����pNetwork������
	virtual bool UpdateSwitchEquipState(const TopoSwitch* pSwitchs) = 0;
	
	////////////////////////////////////////////////////////////////////////////////
	/* ���º���ִ�����˷��� */
	////////////////////////////////////////////////////////////////////////////////
	
	//ȫϵͳ�豸������������˷����������ڷ�������ʱ����һ��ȫϵͳ�����˷�����
	virtual TOPOERRCODE EntireTopologyAnalyze() = 0;
	
	//����һ�����˷����Ļ����ϣ����ݵ�ǰԪ����ͨ�ϱ仯������и���ʽ���˷���������ã�
	virtual TOPOERRCODE UpdateTopologyAnalyze() = 0;

	////////////////////////////////////////////////////////////////////////////////
	/* ���º���������˷�����������õ�ǰ�᣺�ѳɹ�ִ�����������˷�������m_nErrorCode==TPR_Succeed��*/
	////////////////////////////////////////////////////////////////////////////////
	
	//�õ�������ӽڵ��
	virtual int GetMaxJoinNo() = 0;
	//�õ�������˵���
	virtual int GetMaxIslandNo() = 0;
	//�õ�������ڵ��
	virtual int GetMaxNodeNo() = 0;
	//�õ�������֧·��
	virtual int GetMaxBranchNo() = 0;
	
	//�õ��豸ID��Ӧ���豸�������е�λ�ã��±꣩��-1��ʾ�����ڡ�
	virtual int GetTopoEquipPosById(int id) = 0;
	//�õ����ӹ�ϵID��Ӧ�����ӹ�ϵ�������е�λ�ã��±꣩��-1��ʾ�����ڡ�
	virtual int GetTopoConnectPosById(int id) = 0;
	//�����豸��ĩ���Ӻŵõ���Ӧ�ļ���֧·��š�0��ʾ�����ڡ�
	virtual int GetTopoBranchNoByPortNo(int equipId, int portNo1, int portNo2) = 0;
	
	//�����������������������Ϣ
	virtual const TopoNetOut* GetTopoNetOutInfo() = 0;
	//��������豸���˽����Ϣ�����鳤����pNetwork������
	virtual const TopoEquipOut* GetTopoEquipOutInfo() = 0;
	//����������ӹ�ϵ���˽����Ϣ�����鳤����pNetwork������
	virtual const TopoConnectOut* GetTopoConnectOutInfo() = 0;
	//����������ӽڵ���Ϣ�����鳤����pTopoNetOut������
	virtual const TopoJoin* GetJoinSetInfo() = 0;
	//������м���ڵ���Ϣ�����鳤����pTopoNetOut������
	virtual const TopoNode* GetNodeSetInfo() = 0;
	//������м���֧·��Ϣ�����鳤����pTopoNetOut������
	virtual const TopoBranch* GetBranchSetInfo() = 0;
	//����������˵���Ϣ�����鳤����pTopoNetOut������
	virtual const TopoIsland* GetIslandSetInfo() = 0;

	//�õ��豸ID��Ӧ���豸���������Ϣ
	virtual bool GetTopoEquipOutObject(int id, TopoEquipOut& tpEquip) = 0;
	//�õ����ӹ�ϵID��Ӧ�����ӹ�ϵ���������Ϣ
	virtual bool GetTopoConnectOutObject(int id, TopoConnectOut& tpConn) = 0;
	//���ָ����ŵ����ӽڵ������Ϣ
	virtual bool GetJoinObject(int no, TopoJoin& tpJoin) = 0;
	//���ָ����ŵ����˵�������Ϣ
	virtual bool GetIslandObject(int no, TopoIsland& tpIsland) = 0;
	//���ָ����ŵļ���ڵ������Ϣ
	virtual bool GetNodeObject(int no, TopoNode& tpNode) = 0;
	//���ָ����ŵļ���֧·������Ϣ
	virtual bool GetBranchObject(int no, TopoBranch& tpBranch) = 0;

	//�õ�ָ���ڵ�Ĺ�����Դ·��
	virtual bool GetSourceEquipList(int eqpId, intarray& srcEquips, int& srcCount) = 0;

	//�õ�ָ���ڵ�Ӱ��Ĺ��緶Χ
	virtual bool GetLoadEquipList(int eqpId, intarray& pLoadEquips) = 0;

	//�������ڶ�·����բ�������ʧ���豸
	virtual SearchEquip* GetLossEquipArray(int brkID, int& returnCount)=0;

	//��һ�����س���������ת�����翪��
	virtual int* GetLianluoSwitch(int switchID, int* geliIDs, int geliCount, bool bMustAlive, int& returnCount) = 0;
	
	virtual bool UpdateStorageEquipState(const TopoStorage* pStorages) = 0;



	
    //���������������ָ��ģ����
    static char* GetIntfName()
    {
        return IID_TOPOLOGIC;
    }; 
};

#endif //__INTFNEWTOPOLOGIC_PENGSHIKANG_20120603_HEADER__
