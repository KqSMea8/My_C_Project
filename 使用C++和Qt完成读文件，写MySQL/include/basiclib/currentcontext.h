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
	//���ַ�ʽ���õ�ǰ̬
	CURRENTCONTEXT_API bool	SetCurrentContextInt(int  nContext);

	//��ģ������ע���ɫ����ͻ���,ģ������󳤶���32�������ᱻ�ض�
	CURRENTCONTEXT_API bool SetCurrentContextString(const char*  szContext);
	
	//��ȡ��ǰ̬��������ʽ��
	CURRENTCONTEXT_API int GetCurrentContextInt();

	//��ȡ��ǰ̬���ַ�����ʽ��
	CURRENTCONTEXT_API const char* GetCurrentContextString();

	//ע�ᵱǰ̬���֪ͨ
	bool RegisterChangeNotify(NotifyCB cb);

	/*
	�����ĸ������ֱ������κ��ַ�����ʽ���úͻ�ȡ��ǰ̬��
	���κ��ַ���һһ��Ӧ�����Ӧ��ϵ�ɸ�ģ���ڲ����ӳ�䡣
	��ȡ��ǰ̬ʱ�������0��ʧ�ܡ�

	��ϵͳ��֧�ֵ�̬
	����̬	�ַ���̬	̬˵��
	1	SCADA	ʵʱ����̬
	2	FUTURE	δ������̬
	3	SIMUL	��������̬
	4	FAULT	�¹�׷��̬
	*/
}

typedef	bool (*MySetCurrentContextInt)(int );
typedef bool (*MySetCurrentContextString)(const char*);
typedef const char* (*MyGetCurrentContextString)();
typedef int (*MyGetCurrentContextInt)();
#endif