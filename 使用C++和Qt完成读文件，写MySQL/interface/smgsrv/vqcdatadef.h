//vqcdatadef.h
#ifndef _VQCDATADEFINE_PENGSHIKANG_20080714_H_
#define _VQCDATADEFINE_PENGSHIKANG_20080714_H_

#include "../icsvalue.h"                         // for intarray

struct VqcRange
{
	VqcRange() : upper(0.0), lower(0.0) {};
	float upper;//����ֵ
	float lower;//����ֵ
};

struct VqcSettingInfo
{
	VqcSettingInfo() : dCtrlV(), dRefV(), dCtrlVLk(), dRefVLk(), dQCos(), fReverseQ(0.0), isAvcType(0), avcPlanId(0) {};
	VqcRange dCtrlV;//���Ʋ��ѹ(��ô)
	VqcRange dRefV;//�ο����ѹ(��ô)
	VqcRange dCtrlVLk;//���Ʋ������ѹ(��ô)
	VqcRange dRefVLk;//�ο��������ѹ(��ô)
	VqcRange dQCos;//��������_�޹�ֵ
	float fAimU;//Ŀ���ѹ
	float fReverseQ;//������޹�����
	int isAvcType;//0--Vqc; 1--Avc
	int avcPlanId;
};

struct BusDeviceInfo//ĸ�ߴ��е��豸��Ϣ
{
	int busId;//����ĸ��ID
	int bus2Id;//����ĸ��ID��0��ʾ������ĸ��
	int connPos;//ĸ�����ӹ�ϵ��¼λ��
	int transPorts[4];//ĸ��������ѹ���ࣨ��ѹ��Pos + 2bit(��ѹ���+1)����0��ʾδ���ӱ�ѹ��
	intarray aryAddRPC;//�������޹����ʵĲ���װ�ü���
	intarray aryCutRPC;//�ɼ����޹����ʵĲ���װ�ü���
	intarray aryAdjRPC;//�ɵ����޹����ʵĲ���װ�ü���
	intarray aryStor;//�ɵ����޹����ʵĴ���װ�ü���
	intarray aryGener;//�ɵ����޹����ʵķ��������(�����޹��Ӵ�С)
	intarray aryGener1;//�ɵ����޹����ʵķ��������(�ɼ��޹��Ӵ�С)
	intarray aryGener2;//�ɵ����޹����ʵķ����ID����(�������ѹ�Ӵ�С)
	int ctrlBusType;  //ĸ�ߵĵ�ѹ�޹���������
	bool isConnect;//ĸ�������Ƿ���ͨ
	float curVolt;//��ǰ��ѹֵ
	float totalI; //��������������ܡ����ɵĵ�������ֵ���ܺ�
	float maxAddQ;//ͨ��Ͷ���޹�����װ���������ӵ��޹�����{����}(2+)
	float minAddQ;//ͨ��Ͷ���޹�����װ����С�����ӵ��޹�����{����}
	float maxCutQ;//ͨ��Ͷ���޹�����װ�����ɼ��ٵ��޹�����{����}(2-)
	float minCutQ;//ͨ��Ͷ���޹�����װ����С�ɼ��ٵ��޹�����{����}
	float maxIncQ;//�ɵ����޹�����װ�õ����ɷ����޹�����{����}(3+)
	float maxDecQ;//�ɵ����޹�����װ�õ����������޹�����{����}(3-)
	float curRpcQ1;//�ɵ��޹�����װ�õĵ�ǰ�޹�����(4+-)
	float maxRpcS;//�ɵ����޹�����װ�õ����޹�����
	float canIncQ;//ͨ�����ڷ�����������ӵ��޹�����{����}(1+)
	float canDecQ;//ͨ�����ڷ�������ɼ��ٵ��޹�����{����}(1-)
	float curGenQ;//�ɵ��ڷ������ǰ�������޹�����
	float curGenS;//�ɵ��ڷ������ǰ�ܵ�װ������
	float curGenQo;//�ɵ���������������޹�������
	float maxGenQ;//�ɵ��ڷ������ǰ�ܵ�����޹�����
	float maxGenQ1;//�Ը����޹���ʽ���ڵĿɵ��������������޹�����
	float curStorQ;//����װ�õ�ǰ�ܵķ����޹�����
	float maxStorQ;//����װ�õ�ǰ�ܵ�����ŵ��޹�����
	float curStorS;//����װ�õ�ǰ�ܵ�PCS����
	float curStorQo;//����װ�õ�ǰ�ܵ����޹�������
};

enum VQCType
{
	BT_Normal,  //0��������VQC���ڿ���
		BT_CtrlVolt,//1����ѹ����ĸ��
		BT_RefVolt, //2����ѹ�ο�ĸ��
};

enum VQCStrategy
{
	VS_NOACTION,    // 0��������
		VS_TAPASCEND,   // 1�����߷ֽ�ͷ��λ
		VS_TAPDESCEND,  // 2�����ͷֽ�ͷ��λ
		VS_RPCRUN,      // 3��Ͷ���޹������豸�������޹�������
		VS_RPCCUT,      // 4���г��޹������豸�������޹�������
		VS_GRPINC,      // 5�����ӵ�Դ�޹�����
		VS_GRPDEC,      // 6�����ٵ�Դ�޹�����
		VS_SRPADJ,      // 7������SVC/SVG��ѹ
};

enum VQCAreaType//VQC����ϵͳ����
{
	AT_0BUS,//��Ч����ϵͳ
	AT_1BUS,//��ĸ�ߵ���ϵͳ
	AT_2BUS,//˫ĸ�ߵ���ϵͳ
	AT_3BUS,//��ĸ�ߵ���ϵͳ
	AT_4BUS,//��ĸ�ߵ���ϵͳ
	AT_1BUS_1TRANS,//��ĸ����ѹ������ϵͳ
	AT_2BUS_1TRANS,//˫ĸ����ѹ������ϵͳ
	AT_3BUS_1TRANS,//��ĸ����ѹ������ϵͳ[����]
	AT_4BUS_1TRANS,//��ĸ����ѹ������ϵͳ[����]
	AT_1BUS_2TRANS,//��ĸ˫��ѹ������ϵͳ
	AT_2BUS_2TRANS,//˫ĸ˫��ѹ������ϵͳ
	AT_3BUS_2TRANS,//��ĸ˫��ѹ������ϵͳ[����]
	AT_4BUS_2TRANS,//��ĸ˫��ѹ������ϵͳ
	AT_1BUS_3TRANS,//��ĸ����ѹ������ϵͳ[����]
	AT_2BUS_3TRANS,//˫ĸ����ѹ������ϵͳ[����]
	AT_3BUS_3TRANS,//��ĸ����ѹ������ϵͳ
	AT_4BUS_3TRANS,//��ĸ����ѹ������ϵͳ[����]
	AT_1BUS_4TRANS,//��ĸ�ı�ѹ������ϵͳ[����]
	AT_2BUS_4TRANS,//˫ĸ�ı�ѹ������ϵͳ
	AT_3BUS_4TRANS,//��ĸ�ı�ѹ������ϵͳ[����]
	AT_4BUS_4TRANS,//��ĸ�ı�ѹ������ϵͳ
};

struct VQCAreaInfo//VQC����ϵͳ��Ϣ
{
	int id;
	int type;//VQC����ϵͳ���� -- [˫ĸ��|��ĸ��]����ϵͳ��[˫ĸ����ѹ��|��ĸ����ѹ��]����ϵͳ��[˫ĸ˫��ѹ��|��ĸ˫��ѹ��]����ϵͳ
	int trans[4];//��ѹ��λ��
	int ctrlBus[4];//��ѹ����ĸ��λ��
	int refBus[4];//��ѹ�ο�ĸ��λ��
	int rpBus[4];//�޹�����ĸ��λ��
	intarray aryBus;//ĸ�߼���
	intarray aryPcc;//PCC����
	intarray aryLine;//��·�˼���

	VqcRange dCtrlV;//���Ʋ��ѹ��Χ                        [��ʱ����صĶ�ֵ]
	VqcRange dQCos;//��������_�޹���Χ                      [��ʱ���ʵ�ʵ�ѹ���]
	float reverseQ;//������޹�����
	float addRpcU;//Ͷ���޹�����װ����С�����ߵĵ�ѹ        [���޹�����ĸ�ߵ�RPC���]
	float cutRpcU;//Ͷ���޹�����װ����С�ɽ��͵ĵ�ѹ        [���޹�����ĸ�ߵ�RPC���]
	float addRpcQ;//Ͷ���޹�����װ����С�ɼ��ٵ��޹����繦��[���޹�����ĸ�ߵ�RPC���]
	float cutRpcQ;//Ͷ���޹�����װ����С�����ӵ��޹����繦��[���޹�����ĸ�ߵ�RPC���]
	float actTapU;//��һ���ֽ�ͷӰ����С�����ߵĵ�ѹ        [���ѹ�����]
	float actTapQ;//��һ���ֽ�ͷӰ����С�����ӵ��޹����繦��[���ѹ�����]
	float maxOffsU;//Ͷ��1��λ�޹��������ĸ�ߵĵ�ѹ���仯��
	float maxOffsQ;//Ͷ��1��λ�޹������������Ľ����޹��������仯��
	
	
	float baseU;//���ѹ[����ֵ]
	float curU[2];//��ǰʵ�ʵ�ѹ{����ֵ������ֵ}
	float offsU;//��ѹԽ����
	float curP;//��ǰʵ���й�����[�ⲿ����ĸ��Ϊ��]
	float curQ[2];//��ǰʵ���޹����ʡ�ʵ�ʹ��繦������[�ⲿ����ĸ��Ϊ��]
	float offsQ;//�޹�Խ����

	float adjGenS;//Ͷ�˵Ŀɵ��������������װ������ ok
	float adjGenQ;//Ͷ�˵Ŀɵ�������������ܷ����޹����� ok
	float adjGenQo;//Ͷ�˵Ŀɵ���������������޹������� ok
	float maxGenQ;//Ͷ�˵Ŀɵ������������������޹�����
	float maxGenQ1;//Ͷ�˵��Ը����޹���ʽ���ڵĿɵ������������������޹�����
	float addAdjGenQ;//Ͷ�˵Ŀɵ���������������������ӷ����޹����� ok
	float cutAdjGenQ;//Ͷ�˵Ŀɵ�����������������ɼ��ٷ����޹����� ok
	float curRpcS;//Ͷ�˵ĵ������翹�����ܷ����޹�����
	float curRpcQ;//Ͷ�˵Ŀɵ��޹�����װ�õ��ܷ����޹�����
	float maxCanIncQ;//�����޹� // cutRpcQ+maxRpcQOut+addAdjGenQ
	float maxCanDecQ;//�ɼ��޹� // addRpcQ+maxRpcQIn+adjGenQ
	float maxRpcIncQ;//SVG�����޹�
	float maxRpcDecQ;//SVG�ɼ��޹�
	float curStorQ;//����װ�õ�ǰ�ܵķ����޹�����
	float maxStorQ;//����װ�õ�ǰ�ܵ�����ŵ��޹�����
	float curStorS;//����װ�õ�ǰ�ܵ�PCS����
	float senStorQo;//Ͷ�˴���װ�õ����޹������� ok


	int areaNo;//��ǰ״̬��17��ͼ�е����š�1~9��12��14��16��18��22��24��26��28��30��31
	int straPos;//��ǰ״̬�����Ĳ��Լ�¼λ�á�-1��ʾ�޲���
	int isCosfa;//�޹�����Ŀ���Ƿ�Ϊ���������� 0--���ѹ��1--�޹����ʣ�2--����������3--�޹��������䣻4--�����������䡣
	int isPlant;//��ѹ�޹��������͡�0����ѹվVQC��1����ѹվVQC��2����ѹվAVC��վ��3����ѹվAVC��վ��4:  AVC��վ��
	int straTypeId;//��ѹ�޹����ڲ�������ID
	int paramState;//���ò���״̬��0���޴��󣻷�0��������
	int hasAdjust;//�Ƿ��в��Ե��ڡ�0���ޣ�1���С�
	int localFlag;//���ر�־��0--�޲��ԣ�1--Զ��AVC��2--����AVC��3--����VQC��

	int nCtrlVoltId; // ��ѹ����ĸ�ߵĵ�ѹ�ȼ�ID
	int nRpcVoltId;  // �޹�����ĸ�ߵĵ�ѹ�ȼ�ID
	float maxDecQ;   // ��ѹ�ο�ĸ��������ٵ�����޹���
	float maxIncQ;   // ��ѹ�ο�ĸ���������ӵ�����޹���
	VqcRange dLockV; // ���Ʋ������ѹ��Χ
};

#endif
