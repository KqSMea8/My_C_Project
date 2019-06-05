//imglinedao.h

#ifndef _IMGLINEDAO_PENGSHIKANG_20100927_H_
#define _IMGLINEDAO_PENGSHIKANG_20100927_H_

#include "imgddao.h"                             // for IMgdDao

#define MGLINEDAO_CLASSID    "cmglinedao"
#define MGLINEDAO_INTFID     "imglinedao"

class IMGLineDao : virtual public IMgdDao
{
public:
	//������·λ�õõ���·����
	virtual int GetLineType(int pos) = 0;
	//������·λ�õõ�2������ĸ��ID
	virtual int GetBus2ID(int pos) = 0;
	
	//������·λ�õõ�2�˿���״̬ң��ID
	virtual int GetPos2ID(int pos) = 0;
	//������·λ�õõ�2�˿���״̬��ң��ID
	virtual int GetPosCtrl2ID(int pos) = 0;
	//������·λ�õõ�2�˿���״̬��ң��ID
	virtual int GetCutCtrl2ID(int pos) = 0;
	
	//������·λ�õõ�2��P��Qң��ID
	virtual bool GetPQ2_IDs(int pos, int& nP2Id, int& nQ2Id) = 0;
	//������·λ�õõ�2��Pң��ID
	virtual int GetP2ID(int pos) = 0;
	//������·λ�õõ�2��Qң��ID
	virtual int GetQ2ID(int pos) = 0;
	
	//������·λ�õõ�2�˵�ǰ����״̬
	virtual int GetCurPos2(int pos) = 0;
	//������·λ�õõ�2�˵�ǰ�й�����
	virtual double GetCurP2(int pos) = 0;
	//������·λ������2�˵�ǰ�й�����
	virtual bool SetCurP2(int pos, double currP2) = 0;
	//������·λ�õõ�2�˵�ǰ�޹�����
	virtual double GetCurQ2(int pos) = 0;
	//������·λ������2�˵�ǰ�޹�����
	virtual bool SetCurQ2(int pos, double currQ2) = 0;
};

#endif
