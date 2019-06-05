// exprmapdef.h
//
//////////////////////////////////////////////////////////////////////

#ifndef _EXPRESSMAPDEFINE_H__PENGSHIKANG_20120812__INCLUDED_
#define _EXPRESSMAPDEFINE_H__PENGSHIKANG_20120812__INCLUDED_

#define FORMULALENGTH 2048
#define MAXPARAMCOUNT 32

struct ExpPoint
{
	int type;          //参数类型 1:yc，2:yx 3:ym 4:js
	int identifier;    //测点ID
	int startIndex;    //起始位置
	int folloIndex;    //紧随参数之后的字符串位置
};

struct ExpMap
{
	int pos;
	int prmCount;
	ExpPoint prmSet[MAXPARAMCOUNT];//ExpPoint* prmSet;
	char express[FORMULALENGTH];
};

struct ExpSet //一类表达式集合
{
	int count;         //个数
	ExpMap* pObjects;  //对象数组
};

#endif
