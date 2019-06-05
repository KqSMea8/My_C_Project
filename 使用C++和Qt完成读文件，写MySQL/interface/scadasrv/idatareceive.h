/******************************************************************
 *idatareceive.h -- ��Ϣ�ַ�����
 *****************************************************************/
#ifndef __IDATARECEIVE_PENGSHIKANG_H_20150515
#define __IDATARECEIVE_PENGSHIKANG_H_20150515

#include "../icsunknown.h"                       // for IICSUnknown

#define DATARECEIVE_CLASSID    "cdatareceive"
#define DATARECEIVE_INTFID     "idatareceive"

class IDataReceive : virtual public IICSUnknown 
{
public:
	//������Ϣ���ݴ���
	//������pBuffer--ǰ�ö�����̨�����·�����Ϣ���ģ�psPoster--ǰ�ö˻�����
	virtual void ReceiveData(unsigned char* pBuffer, char* psPoster) = 0;
};



#endif
