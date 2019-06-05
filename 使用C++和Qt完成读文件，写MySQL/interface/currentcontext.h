#ifndef CURRENTCONTEXT_H
#define CURRENTCONTEXT_H

#ifdef _MSC_VER
	#ifdef CURRENTCONTEXT_EXPORT
		#define CURRENTCONTEXT_API __declspec(dllexport)
	#else
		#define CURRENTCONTEXT_API __declspec(dllimport)
	#endif
#else
	#define CURRENTCONTEXT_API
#endif

#define CONTEXT_SCADA_INT	1
#define CONTEXT_FUTURE_INT	2
#define CONTEXT_SIMUL_INT	3
#define CONTEXT_FAULT_INT	4

#define	CONTEXT_SCADA_STRING	"SCADA"
#define	CONTEXT_FUTURE_STRING	"FUTURE"
#define CONTEXT_SIMUL_STRING	"SIMUL"
#define CONTEXT_FAULT_STRING	"FAULT"

typedef void (*NotifyCB)(int);

extern "C"
{
	//数字方式设置当前态
	CURRENTCONTEXT_API bool	SetCurrentContextInt(int  nContext);

	//以模块名来注册角色分配客户端,模块名最大长度是32，超过会被截断
	CURRENTCONTEXT_API bool SetCurrentContextString(const char*  szContext);
	
	//获取当前态（整数形式）
	CURRENTCONTEXT_API int GetCurrentContextInt();

	//获取当前态（字符串形式）
	CURRENTCONTEXT_API const char* GetCurrentContextString();

	//注册当前态变更通知
	bool RegisterChangeNotify(NotifyCB cb);

	/*
	以上四个方法分别以整形和字符串形式设置和获取当前态，
	整形和字符串一一对应，其对应关系由该模块内部完成映射。
	获取当前态时如果返回0则失败。

	本系统拟支持的态
	整形态	字符串态	态说明
	1	SCADA	实时运行态
	2	FUTURE	未来运行态
	3	SIMUL	仿真运行态
	4	FAULT	事故追忆态
	*/
}

typedef	bool (*MySetCurrentContextInt)(int );
typedef bool (*MySetCurrentContextString)(const char*);
typedef const char* (*MyGetCurrentContextString)();
typedef int (*MyGetCurrentContextInt)();
#endif