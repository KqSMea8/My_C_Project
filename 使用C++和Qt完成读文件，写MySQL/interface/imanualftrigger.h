
#ifndef _IMANUALFTRIGGER_H_
#define _IMANUALFTRIGGER_H_

#include "icsunknown.h" // for IICSUnknown

#define DLL_MANUALFTRIGGER	"manualftrigger"
#define IID_MANUALFTRIGGER	"IManualFtrigger"
#define CID_MANUALFTRIGGER	"CManualFtrigger"

#include <vector>

class IManualFtrigger:  public IICSUnknown
{
public:

	/*
	 触发人工事故
	 输入参数：1.EquipID  设备ID
	 */
	virtual void ManualFault(int EquipID) = 0; 

};

#endif
