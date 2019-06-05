#ifndef __IVDFAUTH_H__
#define __IVDFAUTH_H__

#include "icsunknown.h"

//ģ������
#ifndef MODULE_VDFAUTH
#define MODULE_VDFAUTH			"vdfauth"
#endif

//ģ���������
#ifndef METHOD_GETCLASSOBJECT
#define METHOD_GETCLASSOBJECT	"GetClassObject"
#endif

//ģ��ӿ�����
#ifndef CLSID_VDFAUTH
#define CLSID_VDFAUTH			"vdfauth"
#endif

//IVDFauth�ӿ�����
#ifndef IID_VDFAUTH
#define IID_VDFAUTH				"vdfauth"
#endif


//�ӿڵ��ý��
enum _VDFAUTHRESULT
{
	VUA_SUCCESS			= 0,	//���óɹ�
	VUA_CONTAINPERM		= 0,    //ӵ��Ȩ��
	VUA_FAILED			= 1,	//����ʧ��
	VUA_NOPERM			= 2,	//û��Ȩ��
	VUA_UNSET			= 3,	//û������
};

#define VUA_ONCE_OPER	0		//����֮һ: һ��ӵ�ж���д��ִ������һ������Ȩ��, ����ӵ��Ȩ�ޡ�
#define MAX_TAGNAME_LEN 512		//

class IVDFAuth : public IICSUnknown
{
public:
	/*!����     �������η���.

	* \����     szTagName (IN) :	�ļ���Ŀ¼·��.

	* \����ֵ						�ɹ����÷���VUA_SUCCESS(=0), ���򷵻�VUA_FAILED(=1)

	* \ע��							���������óɹ����Ǳ��û�ȡ�������سɹ�; 
	*							��szTagName=NULLʱ��û��ʵ����QApplicationʱ����VUA_FAILED(=1)
	*/
	virtual int UASet(const char *szTagName) = 0;


	/*!����     ��֤�ļ���Ŀ¼Ȩ��.

	* \����     szUserID (IN)	:	�û�ID

				szTagName (IN)	:	�ļ���Ŀ¼·��.

  				szOperID (IN)	:	��Ҫ��֤�Ĳ���ID. ��֤�κβ���֮һ�����������NULL.

	* \����ֵ						ӵ��Ȩ�޷���VUA_CONTAINPERM(=0), û��Ȩ��ʱ����VUA_NOPERM(=2), ��szTagNameû�б�����, 
								����VUA_UNSET(3), ����VUA_FAILED(=1)��ʾ��֤ʧ��.

	*/
	virtual int ValidateTag(const char *szUserID, const char *szTagName, const char *szOperID = VUA_ONCE_OPER) = 0;
};

//=============================================================================================================================//
#include <qlibrary.h>

/*!����     ����IVDFAuth�ӿ�, ����������ǽӿڵ�һ���֡�

* \����ֵ	�ɹ��������ؽӿڶ���ָ��,���򷵻�NULL.	

*/
inline IVDFAuth *CreateVDFAuthInterFace()
{
	QLibrary lib(MODULE_VDFAUTH);

	lib.setAutoUnload(false);
	lib.load();

	typedef bool (*PFNGETCLASSOBJECTMETHOD)(const char *, void**);
	
	PFNGETCLASSOBJECTMETHOD pFNGetObj = (PFNGETCLASSOBJECTMETHOD)(lib.resolve(METHOD_GETCLASSOBJECT));

	if(!pFNGetObj)
		return NULL;

	IVDFAuth *pIF = NULL;

	if(!pFNGetObj(CLSID_VDFAUTH, (void **)&pIF))
		return NULL;
	
	return pIF;
}

/*!����     ����IVDFAuth�ӿ�, ����������ǽӿڵ�һ���֡�

* \����     pIF (IN)	:	��Ҫ���ٵĽӿڶ���.

*/
inline void DestroyVDFAuthInterFace(IVDFAuth *pIF)
{
	if(pIF)
		pIF->Release();
}
//=============================================================================================================================//

#endif
