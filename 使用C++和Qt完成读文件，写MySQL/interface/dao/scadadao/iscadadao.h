//iscadadao.h

#ifndef _ISCADADAO_PENGSHIKANG_20131217_H_
#define _ISCADADAO_PENGSHIKANG_20131217_H_

class IDALibrary;
class IBasicDao;

class IAbruptDao;
class IACurveLmtDao;
class IAlmTypDao;
class IAPrdLmtDao;
class IBayDao;
class ICommSrcDao;
class ICtrlExpDao;
class ICtrlValTypDao;
class IEquipDao;
class IEquipTypeDao;
class IExprCalDao;
class IMeasTypeDao;
class IUnitDao;
class IPeriodDao;
class IPeriodTypeDao;
class ISettAreaDao;
class ISoeParaDao;
class ISoeValDao;
class IStationDao;
class IStatusValDao;
class ITagTypeDao;
class ITimerTypeDao;
class IVoltageDao;

class IDummyCalDao;
class IMultSrcDao;
class IDummyCalDao;
class IMultSrcDao;
class IDummyCalDao;
class IMultSrcDao;

class IAccumuDao;
class IAnalogDao;
class IControlDao;
class ISettingDao;
class ISoeDao;
class IStatusDao;

class IAccumPrdStatDao;
class IAnlgPrdStatDao;
class IAnlgStatDao;
class ISttsPrdStisDao;
class IStatusStisDao;

class IIntersiteDao;
class ITransydDao;

class IScadaDao
{
public:
	virtual IDALibrary* GetScadaLibrary() = 0;
	virtual bool SetScadaLibrary(IDALibrary* pLibrary) = 0;
	virtual bool RefreshRtdbLibrary() = 0;
	virtual IAbruptDao* GetAbruptDao(IBasicDao** ppTblDao=0, bool* bNew=0) = 0;
	virtual IACurveLmtDao* GetACurveLmtDao(IBasicDao** ppTblDao=0, bool* bNew=0) = 0;
	virtual IAlmTypDao* GetAlmTypDao(IBasicDao** ppTblDao=0, bool* bNew=0) = 0;
	virtual IAPrdLmtDao* GetAPrdLmtDao(IBasicDao** ppTblDao=0, bool* bNew=0) = 0;
	virtual IBayDao* GetBayDao(IBasicDao** ppTblDao=0, bool* bNew=0) = 0;
	virtual ICommSrcDao* GetCommSrcDao(IBasicDao** ppTblDao=0, bool* bNew=0) = 0;
	virtual ICtrlExpDao* GetCtrlExpDao(IBasicDao** ppTblDao=0, bool* bNew=0) = 0;
	virtual ICtrlValTypDao* GetCtrlValTypDao(IBasicDao** ppTblDao=0, bool* bNew=0) = 0;
	virtual IEquipDao* GetEquipDao(IBasicDao** ppTblDao=0, bool* bNew=0) = 0;
	virtual IEquipTypeDao* GetEquipTypeDao(IBasicDao** ppTblDao=0, bool* bNew=0) = 0;
	virtual IExprCalDao* GetExprCalDao(IBasicDao** ppTblDao=0, bool* bNew=0) = 0;
	virtual IMeasTypeDao* GetMeasTypeDao(IBasicDao** ppTblDao=0, bool* bNew=0) = 0;
	virtual IUnitDao* GetUnitDao(IBasicDao** ppTblDao=0, bool* bNew=0) = 0;
	virtual IPeriodDao* GetPeriodDao(IBasicDao** ppTblDao=0, bool* bNew=0) = 0;
	virtual IPeriodTypeDao* GetPrdTypeDao(IBasicDao** ppTblDao=0, bool* bNew=0) = 0;
	virtual ISettAreaDao* GetSettAreaDao(IBasicDao** ppTblDao=0, bool* bNew=0) = 0;
	virtual ISoeParaDao* GetSoeParaDao(IBasicDao** ppTblDao=0, bool* bNew=0) = 0;
	virtual ISoeValDao* GetSoeValDao(IBasicDao** ppTblDao=0, bool* bNew=0) = 0;
	virtual IStationDao* GetStationDao(IBasicDao** ppTblDao=0, bool* bNew=0) = 0;
	virtual IStatusValDao* GetStatusValDao(IBasicDao** ppTblDao=0, bool* bNew=0) = 0;
	virtual ITagTypeDao* GetTagTypeDao(IBasicDao** ppTblDao=0, bool* bNew=0) = 0;
	virtual ITimerTypeDao* GetTimerTypeDao(IBasicDao** ppTblDao=0, bool* bNew=0) = 0;
	virtual IVoltageDao* GetVoltageDao(IBasicDao** ppTblDao=0, bool* bNew=0) = 0;

	virtual IDummyCalDao* GetAccumuCalDao(IBasicDao** ppTblDao=0, bool* bNew=0) = 0;
	virtual IMultSrcDao* GetAcumSrcDao(IBasicDao** ppTblDao=0, bool* bNew=0) = 0;
	virtual IDummyCalDao* GetAnalogCalDao(IBasicDao** ppTblDao=0, bool* bNew=0) = 0;
	virtual IMultSrcDao* GetAnlgSrcDao(IBasicDao** ppTblDao=0, bool* bNew=0) = 0;
	virtual IDummyCalDao* GetStatusCalDao(IBasicDao** ppTblDao=0, bool* bNew=0) = 0;
	virtual IMultSrcDao* GetStatusSrcDao(IBasicDao** ppTblDao=0, bool* bNew=0) = 0;

	virtual IAccumuDao* GetAccumuDao(IBasicDao** ppTblDao=0, bool* bNew=0) = 0;
	virtual IAnalogDao* GetAnalogDao(IBasicDao** ppTblDao=0, bool* bNew=0) = 0;
	virtual IControlDao* GetControlDao(IBasicDao** ppTblDao=0, bool* bNew=0) = 0;
	virtual ISettingDao* GetSettingDao(IBasicDao** ppTblDao=0, bool* bNew=0) = 0;
	virtual ISoeDao* GetSoeDao(IBasicDao** ppTblDao=0, bool* bNew=0) = 0;
	virtual IStatusDao* GetStatusDao(IBasicDao** ppTblDao=0, bool* bNew=0) = 0;

	virtual IAccumPrdStatDao* GetAcPStatDao(IBasicDao** ppTblDao=0, bool* bNew=0) = 0;
	virtual IAnlgPrdStatDao* GetAPStatDao(IBasicDao** ppTblDao=0, bool* bNew=0) = 0;
	virtual IAnlgStatDao* GetAStatDao(IBasicDao** ppTblDao=0, bool* bNew=0) = 0;
	virtual ISttsPrdStisDao* GetSPStatDao(IBasicDao** ppTblDao=0, bool* bNew=0) = 0;
	virtual IStatusStisDao* GetSStatDao(IBasicDao** ppTblDao=0, bool* bNew=0) = 0;

	virtual IIntersiteDao* GetIntersiteDao(IBasicDao** ppTblDao=0, bool* bNew=0) = 0;
	virtual ITransydDao* GetTransydDao(IBasicDao** ppTblDao=0, bool* bNew=0) = 0;
};

#endif
