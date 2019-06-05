// exprmapdef.h
//
//////////////////////////////////////////////////////////////////////

#ifndef _EXPRESSMAPDEFINE_H__PENGSHIKANG_20120812__INCLUDED_
#define _EXPRESSMAPDEFINE_H__PENGSHIKANG_20120812__INCLUDED_

#define FORMULALENGTH 2048
#define MAXPARAMCOUNT 32

struct ExpPoint
{
	int type;          //�������� 1:yc��2:yx 3:ym 4:js
	int identifier;    //���ID
	int startIndex;    //��ʼλ��
	int folloIndex;    //�������֮����ַ���λ��
};

struct ExpMap
{
	int pos;
	int prmCount;
	ExpPoint prmSet[MAXPARAMCOUNT];//ExpPoint* prmSet;
	char express[FORMULALENGTH];
};

struct ExpSet //һ����ʽ����
{
	int count;         //����
	ExpMap* pObjects;  //��������
};

#endif
