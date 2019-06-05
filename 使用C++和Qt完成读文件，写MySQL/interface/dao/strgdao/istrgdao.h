//iscadadao.h

#ifndef _ISTRGDAO_20190601_H_
#define _ISTRGDAO_20190601_H_

class IDALibrary;
class IStrgstdao;
class IStbasicdao;
class IDispctrldao;
class IStrgDao
{
public:
	virtual IDALibrary* GetStrgLibrary() = 0;
	virtual bool SetStrgLibrary(IDALibrary* pLibrary) = 0;
	virtual bool RefreshRtdbLibrary() = 0;
	virtual IStbasicdao* GetStbasicDao(IBasicDao** ppTblDao=0, bool* bNew=0) = 0;
	virtual IStrgstdao* GetStrgstDao(IBasicDao** ppTblDao=0, bool* bNew=0) = 0;
	virtual IDispctrldao* GetDispctrldao(IBasicDao** ppTblDao=0, bool* bNew=0) = 0;

};

#endif
