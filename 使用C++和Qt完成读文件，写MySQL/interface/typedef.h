#ifndef _TYPEDEF__H_
#define _TYPEDEF__H_
#include "icsunknown.h"
#include "icsvalue.h"

#ifdef _MSC_VER
#ifdef ICSTYPEINFO
#define ICS_EXPORT __declspec(dllexport)
#else
#define ICS_EXPORT __declspec(dllimport)
#endif
#else
#define ICS_EXPORT
#endif

typedef unsigned short wchar;
typedef wchar UCS2;

//typedef unsigned char BYTE;

//定义存放在variant里面的字符串最大长度为255
#define MaxStringLen 255

/*
变体类型枚举定义
*/
/*typedef enum
{   ft_empty, ft_byte, ft_short, ft_int, ft_long, ft_time, ft_float, ft_double, 
    ft_string, ft_IUnknown, ft_bytearray, ft_shortarray, ft_intarray, 
    ft_longarry, ft_floatarray, ft_doublearray, ft_timearray, ft_stringarray, 
}FIELDTYPE;

class IICSUnknown;*/

/*
对于数据的指针指向的数据定义
 0    1  elem1   elem2  ......
 ______________________________
|   |   |      |      |
|___|___|______|______|__________

注: 
    1 前两个字节是一个short型数据,表示数据元素的个数,长度后面是连续的数据元素
    2 指针指向第一个数据元素(并非数据长度)
*/
typedef struct
{
    FIELDTYPE type;
    union
    {
        BYTE bValue;
        short sValue;
        int iValue;     
        double tValue;
        float fValue;
        double dValue;
        IICSUnknown* intf;
        char strValue[MaxStringLen];
        BYTE* pbValue;
        short* psValue;
        int* piValue;
        float* pfValue;
        double* pdValue;
        char** pstrValue;
    }value;
}variant;

const int FIELDNAME_LEN = 64;
const int FIELDCAPTION_LEN = 64;
const int TYPENAME_LEN = 64;
const int TYPECAPTION_LEN = 64;

#endif
