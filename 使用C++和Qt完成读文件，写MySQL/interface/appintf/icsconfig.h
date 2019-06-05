#ifndef _ICSCONFIG__H_
#define _ICSCONFIG__H_

#include "icsunknown.h"
#include "objsintf.h"
#include "qiptr.h"

#define IID_IICSConfigItem		"iicsconfigitem"
#define IID_IICSConfigSection	"iicsconfigsection"
#define IID_IICSConfigFile		"iicsconfigfile"

#define CLSID_XMLConfigFile		"xmlconfigfile"
#define CLSID_INIConfigFile		"iniconfigfile"
#define CLSID_ICS8000CFG		"ics800cfg"

/*
模块xmlconfig可以创建两种对象:
1,CLSID_XMLConfigFile	可以使用IICSConfigFile接口读写任何配置xml配置文件
2,CLSID_ICS8000CFG		读ics8000.xml配置文件(该对象自动调用LoadFromFile,且只调用一次)
*/
#define MODULE_XMLCONFIG		"xmlconfig"

//配置项接口
class IICSConfigItem : public IICSUnknown
{
public:
	virtual void Name(char* name, int size) = 0;
	virtual void Caption(char* caption, int size) = 0;
	virtual void SetCaption(const char* caption) = 0;
	virtual bool ReadBool(const bool dft = false) = 0;
	virtual bool WriteBool(bool b) = 0;
	virtual int ReadInt(const int dft = 0) = 0;
	virtual bool WriteInt(int i) = 0;
	virtual double ReadFloat(const double dft = 0.0) = 0;
	virtual bool WriteFloat(double d) = 0;
	virtual const char* ReadString(const char* dft = "") = 0;
	virtual bool WriteString(const char* p) = 0;
public:
	static char* GetIntfName()
    {
        return IID_IICSConfigItem;
    }; 
};

/*
	配置组接口:
	1,配置组的引用(名称)格式为:[section1/]...[sectionN/]section
	2,配置项的引用(名称)格式为:[section1/]...[sectionN/]item
	3,组和项目的名称都为ASCII码,且不区分大小写
*/
class IICSConfigSection : public IICSUnknown
{
public:	
	virtual void Name(char* name, int size) = 0;
	virtual void Caption(char* caption, int size) = 0;
	virtual void SetCaption(const char* caption) = 0;
	//如果存在该配置项目,返回存在的配置项,否则则创建新的配置项(包括路径)
	virtual bool NewItem(const char* item, IICSConfigItem** ppItem) = 0;
	//删除配置项
	virtual bool DelItem(const char* item) = 0;	
	//如果存在配置组,返回存在的配置组,否则创建新的配置组(包括路径)
	virtual bool NewSection(const char* section, IICSConfigSection** ppSection) = 0;
	//删除配置组
	virtual bool DelSection(const char* section) = 0;
	//查找配置组
	virtual bool FindSection(const char* section, IICSConfigSection** ppSection) = 0;
	//判断是否存在指定的配置组
	virtual bool ExistSection(const char* section) = 0;
	//查找配置项
	virtual bool FindItem(const char* item, IICSConfigItem** ppItem) = 0;
	//判断是否存在指定的配置项
	virtual bool ExistItem(const char* item) = 0;
	//枚举子配置组(仅一级从属关系)
	virtual bool EnumSection(IICSEnum** ppEnum) = 0;
	//枚举配置项(仅一级从属关系)
	virtual bool EnumItem(IICSEnum** ppEnum) = 0;
	/*
	以下写配置项的执行效果:如果不存在指定的配置项则创建该配置项(包括路径)
	*/
	virtual bool ReadBool(const char* item, const bool dft = false) = 0;
	virtual bool WriteBool(const char* item, bool b) = 0;
	virtual int ReadInt(const char* item, const int dft = 0) = 0;
	virtual bool WriteInt(const char* item, int i) = 0;
	virtual double ReadFloat(const char* item, const double dft = 0.0) = 0;
	virtual bool WriteFloat(const char* item, double d) = 0;
	virtual const char* ReadString(const char* item, const char* dft = "") = 0;
	virtual bool WriteString(const char* item, const char* p) = 0;
public:
	static char* GetIntfName()
    {
        return IID_IICSConfigSection;
    }; 
};

//配置文件接口
class IICSConfigFile : public IICSConfigSection
{
public:
	//从配置文件加载配置
	virtual bool LoadFromFile(const char* filename) = 0;
	//把配置写进配置文件
	virtual bool SaveToFile(const char* filename) = 0;
public:
	static char* GetIntfName()
    {
		return IID_IICSConfigFile;
	};
};

typedef CQIPtr<IICSConfigSection>	ICSConfigSection;
typedef CQIPtr<IICSConfigFile>		ICSConfigFile;
typedef CQIPtr<IICSConfigItem>		ICSConfigItem;

#endif
