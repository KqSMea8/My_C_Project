// exprmapdef.h
//
//////////////////////////////////////////////////////////////////////

#ifndef _BUSSINESSDDATATRANSDEFINE_H__PENGSHIKANG_20160510__INCLUDED_
#define _BUSSINESSDDATATRANSDEFINE_H__PENGSHIKANG_20160510__INCLUDED_


struct BussClmnInfo // ҵ���������Ե�ʵʱ��λ����Ϣ
{
	int equipId;      //����ʵʱ���¼�豸ID
	//int clmnCount;    //ҵ���������
	int* pValuePos;   //ҵ����ֶ�����_����
};

struct BussTblInfo // ҵ����¼��Ϣ
{
	int tblCfgId;            //��ҵ���ת�����á���ID
	int clmnCount;           //ҵ�������ʵʱ�ֶ���
	int objCount;            //ҵ���������
	BussClmnInfo** pBussDatas;//ҵ���������Ե�ʵʱ��λ����Ϣ_����
};

////////////////////////////////////////////////

struct EquipData // һ������ʵʱ���¼���豸��Ϣ
{
	int equipId;      //����ʵʱ���¼�豸ID
	int dataPos;      //����ʵʱ���¼λ��
};

struct MeasTypeSet // һ�������ݲ������ID����Ӧ�ļ�¼�豸��Ϣ����
{
	int dataType;          //����ʵʱ������ 1:analog��2:status 3:accumulator 
	int eqpCount;          //����ʵʱ���¼����
	EquipData* pDataEquips;//��¼�豸��Ϣ_����
};

////////////////////////////////////////////////

struct BussClmn // һ����ҵ���ת�����á���ҵ����ֶ�����
{
	int dataType;      //����ʵʱ������ 1:analog��2:status 3:accumulator 
	int measTypeId;    //���ݲ������ID
	char clmnName[64]; //ҵ����ֶ�����
};

struct BussTbl // ҵ�������
{
	int tblCfgId;        //��ҵ���ת�����á���ID
	char tblName[64];    //ҵ�������
	char keyName[64];    //ҵ����豸ID�������ֶ�����
	int count;           //ҵ�������ʵʱ�ֶθ���
	BussClmn** pBussClmns;//ҵ����ֶ�����_����
};

struct BussTblSet //һ����ʱ����Ӧ��ҵ������ü���
{
	int count;           //ҵ������
	BussTbl** pBussTbls;  //ҵ�����������
};

#endif
