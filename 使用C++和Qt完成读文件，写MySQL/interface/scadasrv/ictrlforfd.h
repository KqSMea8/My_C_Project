/*******************************************************
 * ictrlforfd.h -- 服务端控制主业务类接口
 *******************************************************/

#ifndef __ICONTROLMAINLOGICFORFIVEDEFENSE_PENGSHIKANG_H_20150604
#define __ICONTROLMAINLOGICFORFIVEDEFENSE_PENGSHIKANG_H_20150604

class IControlForFD
{
public:
	//五防装置请求执行选控令
	virtual bool ExecuteSelectCmdForFD(int ctrlId, int oldValue, int newValue, bool isDouble) = 0;
	//五防装置请求执行直控令
	virtual bool ExecuteControlCmdForFD(int ctrlId, int oldValue, int newValue, bool isDouble) = 0;
	//五防装置请求执行撤销令
	virtual bool ExecuteCancelCmdForFD(int ctrlId, int oldValue, int newValue, bool isDouble) = 0;
	//五防装置返回执行操作结果
	virtual bool ExecuteResultBackFromFD(int ctrlId, bool bSuccess, double actTime) = 0;
};

#endif