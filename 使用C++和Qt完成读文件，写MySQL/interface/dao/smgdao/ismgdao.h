//ismgdao.h

#ifndef _ISMGDAO_PENGSHIKANG_20131217_H_
#define _ISMGDAO_PENGSHIKANG_20131217_H_

class IDALibrary;
class IBasicDao;

class IBusConnDao;
class IExchCurvePlanDao;
class IExPowCurveDao;
class IGenStatDao;
class IGeneratorStatDao;
class IIsdmainpsDao;
class IModelDao;
class IModelCtrlDao;
class IModelRunStyleDao;
class ISmgRunstyleDao;
class ISmoothCtrlDao;
class IStorCurvePlanDao;
class IStorCurveDao;
class IStyleCtrlDao;
class ISysInfoDao;
class IWeatherDao;

class IBusDao;
class IGeneratorDao;
class ILoadDao;
class IMGLineDao;
class IPccDao;
class IReactCompDao;
class ISMicgridDao;
class IStorageDao;
class ITransformerDao;

class IVqcParamDao;
class IVqcRunDataDao;
class IVqcQSettingDao;
class IVqcSettingDao;
class IVqcSetTypeDao;
class IVqcStraDao;
class IAvcSetPlanDao;
class IAvcPlanCurDao;
class IVqcStraTypeDao;

class IVoltAdjCoefDao;
class IGeneratorGroupDao;
class IBatStationDao;

class ISmgDao
{
public:
	virtual IDALibrary* GetSmgLibrary() = 0;
	virtual bool SetSmgLibrary(IDALibrary* pLibrary) = 0;
	virtual bool RefreshRtdbLibrary() = 0;
	virtual IBusConnDao* GetBusConnDao(IBasicDao** ppTblDao=0, bool* bNew=0) = 0;
	virtual IExchCurvePlanDao* GetExchCrvPlanDao(IBasicDao** ppTblDao=0, bool* bNew=0) = 0;
	virtual IExPowCurveDao* GetExPowCrvDao(IBasicDao** ppTblDao=0, bool* bNew=0) = 0;
	virtual IGenStatDao* GetGenStatDao(IBasicDao** ppTblDao=0, bool* bNew=0) = 0;
	virtual IGeneratorStatDao* GetGenRunStatDao(IBasicDao** ppTblDao=0, bool* bNew=0) = 0;
	virtual IIsdmainpsDao* GetIsdmainpsDao(IBasicDao** ppTblDao=0, bool* bNew=0) = 0;
	virtual IModelDao* GetModelDao(IBasicDao** ppTblDao=0, bool* bNew=0) = 0;
	virtual IModelCtrlDao* GetModelCtrlDao(IBasicDao** ppTblDao=0, bool* bNew=0) = 0;
	virtual IModelRunStyleDao* GetModelRunStyleDao(IBasicDao** ppTblDao=0, bool* bNew=0) = 0;
	virtual ISmgRunstyleDao* GetSmgRunstyleDao(IBasicDao** ppTblDao=0, bool* bNew=0) = 0;
	virtual ISmoothCtrlDao* GetSmoothCtrlDao(IBasicDao** ppTblDao=0, bool* bNew=0) = 0;
	virtual IStorCurvePlanDao* GetStorCrvPlanDao(IBasicDao** ppTblDao=0, bool* bNew=0) = 0;
	virtual IStorCurveDao* GetStorCrvDao(IBasicDao** ppTblDao=0, bool* bNew=0) = 0;
	virtual IStyleCtrlDao* GetStyleCtrlDao(IBasicDao** ppTblDao=0, bool* bNew=0) = 0;
	virtual ISysInfoDao* GetSysInfoDao(IBasicDao** ppTblDao=0, bool* bNew=0) = 0;
	virtual IWeatherDao* GetWeatherDao(IBasicDao** ppTblDao=0, bool* bNew=0) = 0;

	virtual IBusDao* GetBusDao(IBasicDao** ppTblDao=0, bool* bNew=0) = 0;
	virtual IGeneratorDao* GetGeneratorDao(IBasicDao** ppTblDao=0, bool* bNew=0) = 0;
	virtual ILoadDao* GetLoadDao(IBasicDao** ppTblDao=0, bool* bNew=0) = 0;
	virtual IMGLineDao* GetMGLineDao(IBasicDao** ppTblDao=0, bool* bNew=0) = 0;
	virtual IPccDao* GetPccDao(IBasicDao** ppTblDao=0, bool* bNew=0) = 0;
	virtual IReactCompDao* GetReactCompDao(IBasicDao** ppTblDao=0, bool* bNew=0) = 0;
	virtual ISMicgridDao* GetSMicgridDao(IBasicDao** ppTblDao=0, bool* bNew=0) = 0;
	virtual IStorageDao* GetStorageDao(IBasicDao** ppTblDao=0, bool* bNew=0) = 0;
	virtual ITransformerDao* GetTransformerDao(IBasicDao** ppTblDao=0, bool* bNew=0) = 0;

	virtual IVqcParamDao* GetVqcParamDao(IBasicDao** ppTblDao=0, bool* bNew=0) = 0;
	virtual IVqcRunDataDao* GetVqcRunDataDao(IBasicDao** ppTblDao=0, bool* bNew=0) = 0;
	virtual IVqcQSettingDao* GetVqcQSettingDao(IBasicDao** ppTblDao=0, bool* bNew=0) = 0;
	virtual IVqcSettingDao* GetVqcSettingDao(IBasicDao** ppTblDao=0, bool* bNew=0) = 0;
	virtual IVqcSetTypeDao* GetVqcSetTypeDao(IBasicDao** ppTblDao=0, bool* bNew=0) = 0;
	virtual IVqcStraDao* GetVqcStraDao(IBasicDao** ppTblDao=0, bool* bNew=0) = 0;
	virtual IAvcSetPlanDao* GetAvcSetPlanDao(IBasicDao** ppTblDao=0, bool* bNew=0) = 0;
	virtual IAvcPlanCurDao* GetAvcCurveDao(IBasicDao** ppTblDao=0, bool* bNew=0) = 0;
	virtual IVqcStraTypeDao* GetVqcStraTypeDao(IBasicDao** ppTblDao=0, bool* bNew=0) = 0;

	virtual IVoltAdjCoefDao* GetVoltAdjCoefDao(IBasicDao** ppTblDao=0, bool* bNew=0) = 0;
	virtual IGeneratorGroupDao* GetGeneratorGroupDao(IBasicDao** ppTblDao=0, bool* bNew=0) = 0;
	virtual IBatStationDao* GetBatStationDao(IBasicDao** ppTblDao=0, bool* bNew=0) = 0;
};

#endif
