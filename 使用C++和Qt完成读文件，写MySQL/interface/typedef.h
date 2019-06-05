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

//��������variant������ַ�����󳤶�Ϊ255
#define MaxStringLen 255

/*
��������ö�ٶ���
*/
/*typedef enum
{   ft_empty, ft_byte, ft_short, ft_int, ft_long, ft_time, ft_float, ft_double, 
    ft_string, ft_IUnknown, ft_bytearray, ft_shortarray, ft_intarray, 
    ft_longarry, ft_floatarray, ft_doublearray, ft_timearray, ft_stringarray, 
}FIELDTYPE;

class IICSUnknown;*/

/*
�������ݵ�ָ��ָ������ݶ���
 0    1  elem1   elem2  ......
 ______________________________
|   |   |      |      |
|___|___|______|______|__________

ע: 
    1 ǰ�����ֽ���һ��short������,��ʾ����Ԫ�صĸ���,���Ⱥ���������������Ԫ��
    2 ָ��ָ���һ������Ԫ��(�������ݳ���)
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
