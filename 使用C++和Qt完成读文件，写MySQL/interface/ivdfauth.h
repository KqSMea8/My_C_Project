#ifndef __IVDFAUTH_H__
#define __IVDFAUTH_H__

#include "icsunknown.h"

//模块名称
#ifndef MODULE_VDFAUTH
#define MODULE_VDFAUTH			"vdfauth"
#endif

//模块入口名称
#ifndef METHOD_GETCLASSOBJECT
#define METHOD_GETCLASSOBJECT	"GetClassObject"
#endif

//模块接口名称
#ifndef CLSID_VDFAUTH
#define CLSID_VDFAUTH			"vdfauth"
#endif

//IVDFauth接口名称
#ifndef IID_VDFAUTH
#define IID_VDFAUTH				"vdfauth"
#endif


//接口调用结果
enum _VDFAUTHRESULT
{
	VUA_SUCCESS			= 0,	//调用成功
	VUA_CONTAINPERM		= 0,    //拥有权限
	VUA_FAILED			= 1,	//调用失败
	VUA_NOPERM			= 2,	//没有权限
	VUA_UNSET			= 3,	//没有设置
};

#define VUA_ONCE_OPER	0		//操作之一: 一旦拥有读、写、执行任意一个操作权限, 都将拥有权限。
#define MAX_TAGNAME_LEN 512		//

class IVDFAuth : public IICSUnknown
{
public:
	/*!功能     设置责任分区.

	* \参数     szTagName (IN) :	文件或目录路径.

	* \返回值						成功调用返回VUA_SUCCESS(=0), 否则返回VUA_FAILED(=1)

	* \注意							无论是设置成功或是被用户取消都返回成功; 
	*							当szTagName=NULL时或没有实例化QApplication时返回VUA_FAILED(=1)
	*/
	virtual int UASet(const char *szTagName) = 0;


	/*!功能     验证文件或目录权限.

	* \参数     szUserID (IN)	:	用户ID

				szTagName (IN)	:	文件或目录路径.

  				szOperID (IN)	:	需要验证的操作ID. 验证任何操作之一这个参数传入NULL.

	* \返回值						拥有权限返回VUA_CONTAINPERM(=0), 没有权限时返回VUA_NOPERM(=2), 若szTagName没有被设置, 
								返回VUA_UNSET(3), 返回VUA_FAILED(=1)表示验证失败.

	*/
	virtual int ValidateTag(const char *szUserID, const char *szTagName, const char *szOperID = VUA_ONCE_OPER) = 0;
};

//=============================================================================================================================//
#include <qlibrary.h>

/*!功能     创建IVDFAuth接口, 这个函数不是接口的一部分。

* \返回值	成功创建返回接口对象指针,否则返回NULL.	

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

/*!功能     销毁IVDFAuth接口, 这个函数不是接口的一部分。

* \参数     pIF (IN)	:	需要销毁的接口对象.

*/
inline void DestroyVDFAuthInterFace(IVDFAuth *pIF)
{
	if(pIF)
		pIF->Release();
}
//=============================================================================================================================//

#endif
