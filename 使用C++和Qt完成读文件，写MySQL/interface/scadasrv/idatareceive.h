/******************************************************************
 *idatareceive.h -- 消息分发中心
 *****************************************************************/
#ifndef __IDATARECEIVE_PENGSHIKANG_H_20150515
#define __IDATARECEIVE_PENGSHIKANG_H_20150515

#include "../icsunknown.h"                       // for IICSUnknown

#define DATARECEIVE_CLASSID    "cdatareceive"
#define DATARECEIVE_INTFID     "idatareceive"

class IDataReceive : virtual public IICSUnknown 
{
public:
	//接收消息数据处理
	//参数：pBuffer--前置端往后台服务下发的消息报文；psPoster--前置端机器名
	virtual void ReceiveData(unsigned char* pBuffer, char* psPoster) = 0;
};



#endif
