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
ģ��xmlconfig���Դ������ֶ���:
1,CLSID_XMLConfigFile	����ʹ��IICSConfigFile�ӿڶ�д�κ�����xml�����ļ�
2,CLSID_ICS8000CFG		��ics8000.xml�����ļ�(�ö����Զ�����LoadFromFile,��ֻ����һ��)
*/
#define MODULE_XMLCONFIG		"xmlconfig"

//������ӿ�
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
	������ӿ�:
	1,�����������(����)��ʽΪ:[section1/]...[sectionN/]section
	2,�����������(����)��ʽΪ:[section1/]...[sectionN/]item
	3,�����Ŀ�����ƶ�ΪASCII��,�Ҳ����ִ�Сд
*/
class IICSConfigSection : public IICSUnknown
{
public:	
	virtual void Name(char* name, int size) = 0;
	virtual void Caption(char* caption, int size) = 0;
	virtual void SetCaption(const char* caption) = 0;
	//������ڸ�������Ŀ,���ش��ڵ�������,�����򴴽��µ�������(����·��)
	virtual bool NewItem(const char* item, IICSConfigItem** ppItem) = 0;
	//ɾ��������
	virtual bool DelItem(const char* item) = 0;	
	//�������������,���ش��ڵ�������,���򴴽��µ�������(����·��)
	virtual bool NewSection(const char* section, IICSConfigSection** ppSection) = 0;
	//ɾ��������
	virtual bool DelSection(const char* section) = 0;
	//����������
	virtual bool FindSection(const char* section, IICSConfigSection** ppSection) = 0;
	//�ж��Ƿ����ָ����������
	virtual bool ExistSection(const char* section) = 0;
	//����������
	virtual bool FindItem(const char* item, IICSConfigItem** ppItem) = 0;
	//�ж��Ƿ����ָ����������
	virtual bool ExistItem(const char* item) = 0;
	//ö����������(��һ��������ϵ)
	virtual bool EnumSection(IICSEnum** ppEnum) = 0;
	//ö��������(��һ��������ϵ)
	virtual bool EnumItem(IICSEnum** ppEnum) = 0;
	/*
	����д�������ִ��Ч��:���������ָ�����������򴴽���������(����·��)
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

//�����ļ��ӿ�
class IICSConfigFile : public IICSConfigSection
{
public:
	//�������ļ���������
	virtual bool LoadFromFile(const char* filename) = 0;
	//������д�������ļ�
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
