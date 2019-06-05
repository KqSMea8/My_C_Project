////////////////////////////////////////////////////////////////////
//�ļ�����			topodatadef.h
//�ӿں�����		��
//�ӿ�˵����		��
//��Ҫ���ܣ�		�����������˷����ӿ���������Ķ������ݽṹ
//�����ߣ�			������
//�������ڣ�		2012.06.03
//�汾��			1.0�棻
//��Ȩ��Ϣ:			��������������
//���ļ�¼��		����ʱ�䣺2012-06-03, �����ˣ���������Peng Shikang, psk��
////////////////////////////////////////////////////////////////////
#ifndef __TOPODATADEFINE_PENGSHIKANG_20120603_HEADER__
#define __TOPODATADEFINE_PENGSHIKANG_20120603_HEADER__

#define MAXIDADDONE 65536


//////////////////////////////////////////////////////////////////////////////////////
/*�������ݽṹ����*/
//////////////////////////////////////////////////////////////////////////////////////

typedef unsigned char  UCHAR;
typedef unsigned short UWORD;
typedef unsigned int   UINT;

#include <interface/icsvalue.h>  // for TopoNetwork

//////////////////////////////////////////////////////////////////////////////////////
//����ģ��
//////////////////////////////////////////////////////////////////////////////////////
/*
struct intarray
{
	UINT count;
	int* values;
};
*/
//�豸����
/*
enum EQUIPTYPE
{
	ET_Invalid,              //��Ч�豸����
	ET_Ground,		         //�ӵ�
	ET_Generator,            //�����
	ET_Load,                 //����
	ET_Storage,              //����
	ET_QCompens,             //�����޹�������
	ET_Bus,                  //ĸ��
	ET_Line,                 //��·
	ET_2WindingTrans,        //�������ѹ��
	ET_3WindingTrans,        //�������ѹ��
	ET_Capacitor,            //����������
	ET_Reactor,              //�����翹��
	ET_Breaker,              //��·������
	ET_Switch,               //��բ����
	ET_Count                 //�豸��������
};
*/

typedef int EQUIPTYPE;

//��������
enum PORTTYPE                // ��������
{
	PT_NotPort = 0,		     //�����˶��ӣ�Ϊ��ͨͼ��Ԫ�أ�
	PT_LinkPort = 1,		 //��ͨ���˶��ӣ����ӿڣ�
	PT_Import = 2,			 //������ӣ���ڡ�Դ���ӡ���Դ���ӣ�
	PT_Export = 3,			 //������ӣ����ڡ��޶��ӡ����ɶ��ӣ�
	PT_GrobalPort = 4,		 //ȫ�ֵ�Ч���ӣ������Ľӵض��ӣ�
	PT_ImportExport = 5,
	PT_IsolatedPort = 6,	 //�������ӣ���ͬһԪ�����������Ӳ���ͨ��
	PT_Count                 //������������
};

//��������������Ϣ
struct TopoNetwork           //��������������Ϣ
{
	char strName[64];          //(i)ϵͳ����
	UINT iNodeNumForIsland;    //(i)��Ч����Ҫ�����ٽڵ�����Ĭ��Ϊ2
	UINT iInNodeNumForActIsla; //(i)���Ҫ�����ٵ�Դ�ڵ�����Ĭ��Ϊ1
	UINT iOutNodeNumForActIsla;//(i)���Ҫ�����ٸ��ɽڵ�����Ĭ��Ϊ1
	UINT iAnalCycleInSecond;   //(i)���˷������ڼ������������Ĭ��Ϊ2
	UINT iEquipTypeCount;      //(o)�豸��������
	UINT iEquipmentCount;      //(o)���豸̨��
	UINT iSwitchEquipCount;    //(o)�ܿ����豸̨��
	UINT iConnectionCount;     //(o)�����ӹ�ϵ����
	UINT iStorageEquipCount;        //�����豸����
};

//�豸���͵Ķ�����Ϣ
struct TopoEquipType         //�豸���͵Ķ�����Ϣ
{
	EQUIPTYPE eType;         //(i)�豸����
	UCHAR cPortTypes[8];     //(i)���˶����������顣cPortTypes[0]�����˶��Ӹ�����ȡֵΪ1~4��cPortTypes[6]���Ƿ�Ϊ�����豸��
	                         // cPortTypes[7]���Ƿ�Ϊ֧·�豸��0--��֧·��1--֧·��2--��·����
	                         // cPortTypes[1~4]�����˶�������Ԫ�أ�ȡֵΪ0ʱ��Ӧ�ڷ����˶��ӡ���Ч���ӡ�
							/*��������Ե㣬���Զ���Ϊ��ͨ���˶��ӡ�ȫ�ֵ�Ч���ӡ�
							���������ĸ�ѹ�ࡢ��ѹ�ࡢ��ѹ�ࡢ���Ե�Ķ�����ŷֱ�Ϊ1��2��3��4��
							����1��2��3��Ϊ��ͨ���˶��ӣ�
							��4����Ϊ��ͨ���˶��ӣ�Ԫ��ֵΪ0��������Ԫ���ڲ�������1��2��3����֧·����ͨ����4��ͨ��
							��4����Ϊȫ�ֵ�Ч���ӣ�Ԫ��ֵΪ4��������Ԫ���ڲ�������1��2��3����֧·��ӵض���4��ͨ��
							*/
};

//�����豸��Ϣ
struct TopoEquipment         //�����豸��Ϣ
{
	int id;                  //(i)�豸ID��������>0��
	EQUIPTYPE eType;         //(i)�豸����
	bool isSwitch;           //(o)�Ƿ�Ϊ�����豸
	int statusId;
};

//�����豸��ʵʱͨ��״̬��Ϣ
struct TopoSwitch
{
	int iEquipId;            //(i)�����豸ID��������>0��
	int iStatusId;           //(i)�����豸��״̬��ID��
	int eConnectFlag;        //(o)��ͨ״̬��0--�Ͽ����˳���1--��ͨ������
	bool asBranch;           //(o)�Ƿ�Ϊ֧·�豸��Ĭ��Ϊ0��
	int eIsNew;              //(o)�Ƿ�Ϊ�µ�������ݣ�0--��1--��
};

//�����豸
struct TopoStorage
{
	int iEquipId;            //(i)�豸ID��������>0��
	int iVFModStatID;           //(i)״̬��ID��
	int iVFModValue;        //(o)0--���ɣ�1--��Դ
	int eIsNew;          //(o)�Ƿ�Ϊ�µ�������ݣ�0--��1--��
};

//�豸���ӹ�ϵ��Ϣ
struct TopoConnection        //�豸���ӹ�ϵ��Ϣ
{
	int id;                  //(i)���ӹ�ϵID��������>0��һ���1��ʼ���
	int iEquipId1;           //(i)�����豸1��ID
	int iPortNo1;            //(i)�����豸1�Ķ��ӱ�ţ�ȡֵΪ1~4��
	int iEquipId2;           //(i)�����豸2��ID
	int iPortNo2;            //(i)�����豸2�Ķ��ӱ�ţ�ȡֵΪ1~4��
};


//////////////////////////////////////////////////////////////////////////////////////
//���ģ��
//////////////////////////////////////////////////////////////////////////////////////

//�ڵ�����
enum NODETYPE                //�ڵ�����
{
	NT_NullNode = 0,         //�սڵ㣨����ڵ㣩
	NT_LinkNode = 1,		 //��ͨ�ڵ㣨����ڵ㣩
	NT_InNode = 2,			 //����ڵ㣨��ڽڵ㡢Դ�ڵ㡢��Դ�ڵ㣩
	NT_OutNode = 3,			 //����ڵ㣨���ڽڵ㡢�޽ڵ㡢���ɽڵ㣩
	NT_GrobalNode = 4,		 //ȫ�ֵ�Ч�ڵ㣨�����Ľӵؽڵ㣩
	NT_AllNode = 5,	         //��������ڵ㣨��Դ���ɽڵ㣩
};

//���˷����������
enum TOPOERRCODE
{
	TPR_Succeed,             //���˷����������
	TPR_NotStart,            //���˷���δ��ʼ
	TPR_MallocFail,          //�ڴ����ʧ��
};

//�����������������Ϣ
struct TopoNetOut            //�����������������Ϣ
{
	int iJoinCount;          //(o)�����ӣ�����������.
	int iNodeCount;          //(o)�ܼ��������.
	int iBranchCount;        //(o)�ܼ���֧·����
	int iIslandCount;        //(o)����Ч������.
	int iActIslaCount;       //(o)�ܻ����.
	int iMaxJoinNo;          //(o)������ӽ����.
	int iMaxNodeNo;          //(o)����������.
	int iMaxBranchNo;        //(o)������֧·���
	int iMaxIslandNo;        //(o)�����Ч�����.
	int iAnalTimeInMilSec;   //(o)���˷���ʱ�䣬�Ժ����.
	TOPOERRCODE eResultCode; //(o)���˷����������
};

//�����豸�����Ϣ
struct TopoEquipOut          //�����豸�����Ϣ
{
	int iEquipId;            //(i)�豸ID
	UWORD iPortJoinNo[4];    //(o)ÿһ�����Ӷ�Ӧ�����ӽ��ţ�0--�����ӽ�㣬>0--��Ч���ӽ��
	UWORD iPortNodeNo[4];    //(o)ÿһ�����Ӷ�Ӧ�ļ�����ţ�0--�޼����㣬>0--��Ч������
	int iIslandNo;           //(o)�������ţ�-1--δ֪����0--��Ч����>0--��Ч��
	int eActiveFlag;         //(o)���Ƿ�Ϊ���0--������1--�
	int eIsNew;              //(o)�Ƿ�Ϊ�µ�������ݣ�0--��1--��
};

//�豸���ӹ�ϵ�����Ϣ
struct TopoConnectOut        //�豸���ӹ�ϵ��Ϣ
{
	int iConnId;             //(i)���ӹ�ϵID
	int iJoinNo;             //(o)�������ӽ��ţ�0--�����ӽ�㣬>0--��Ч���ӽ��
	int iNodeNo;             //(o)����������ţ�0--�޼����㣬>0--��Ч������
	int eIsNew;              //(o)�Ƿ�Ϊ�µ�������ݣ�0--��1--��
};

//���ӽ��
struct TopoJoin              //����������˷���ҵ��1���Զ�����
{
	int iNo;                 //(o)���ӽ��ţ�������>=0��Ч��һ���1��ʼ��ţ���ֵ��ʾ�����ӽ��Ϊ��Ч�����ӽ�㡣1~65535
	int iPortCount;          //(o)�����Ķ�����
	NODETYPE eTypeFlag;      //(o)������
	int iNodeNo;             //(o)����������ţ�0--�޼����㣬>0--��Ч������
	int iIslandNo;           //(o)�������˵��ţ�-1--δ֪����0--��Ч����>0--��Ч��
	int eIsNew;              //(o)�Ƿ�Ϊ�µ�������ݣ�0--��1--��
	int* pDots;              //���ӽڵ������������豸�˵�����
};

//������
struct TopoNode              //����������˷���ҵ��2���Զ�����
{
	int iNo;                 //(o)���ţ�������>=0��Ч��һ���1��ʼ��ţ���ֵ��ʾ�ü���ڵ�Ϊ��Ч�ļ���ڵ㡣
	NODETYPE eTypeFlag;      //(o)������
	int iIslandNo;           //(o)�������˵���
	int iInnerNo;            //(o)���ڽ��ţ������˵������´�1��ʼ������š�
	UWORD iParent;           //(o)���ڵ�ID
	int eIsNew;              //(o)�Ƿ�Ϊ�µ�������ݣ�0--��1--��
	int* pDots;              //����ڵ��������������ӽڵ�����
	int joinCount;            //����ڵ���������ӽڵ���
};

//����֧·
struct TopoBranch             //����������˷���ҵ��2���Զ�����
{
	int iNo;                  //(o)֧·�ţ�������>=0��Ч��һ���1��ʼ��ţ���ֵ��ʾ�ü���֧·Ϊ��Ч�ļ���֧·��
	int iEquipId;             //(i)�����豸ID
	int iPort1No;             //(i)�豸�׶˶��Ӻ�
	int iPort2No;             //(i)�豸ĩ�˶��Ӻ�
	int iNode1No;             //(o)�׶˼������
	int iNode2No;             //(o)ĩ�˼�����ţ�Ϊ0ʱ����ʾĩ�������գ�Ϊ��Ч��㣩�����׶˼��������ͬʱ����ʾ�ӵ�֧·��
	int iIslandNo;            //(o)�������˵���
	int eIsNew;               //(o)�Ƿ�Ϊ�µ�������ݣ�0--��1--��
};

//���˵�
struct TopoIsland            //����������˷���ҵ��2���Զ�����
{
	int iNo;                 //(o)���˵��ţ�������>=0��Ч��һ���1��ʼ��ţ���ֵ��ʾ�����˵�Ϊ��Ч�����˵���Ϣ��
	int iBranchCount;        //(o)����֧·����
	int iNodeCount;          //(o)���������
	int iPowerCount;         //(o)��Դ�����.
	int iLoadCount;          //(o)���ɽ����.
	int iBothCount;          //(o)��Դ���ɽ����.
	int iGroundCount;        //(o)�Եؽ����.
	int eActiveFlag;         //(o)�Ƿ�Ϊ���0--������1--�
	int eIsNew;              //(o)�Ƿ�Ϊ�µ�������ݣ�0--��1--��
};

struct SearchEquip
{
	int equipID;
	int parentIndex;
};


#endif // __TOPODATADEFINE_PENGSHIKANG_20120603_HEADER__
