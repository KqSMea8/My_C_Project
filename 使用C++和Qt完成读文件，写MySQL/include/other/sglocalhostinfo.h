#ifndef __SGLOCALHOSTINFO_H_20080428 
#define __SGLOCALHOSTINFO_H_20080428

/*
 * 主机信息实用类
 */
class SGLocalHostInfo
{
private:
	static SGLocalHostInfo* m_pInstance;
	SGLocalHostInfo();
public:
	~SGLocalHostInfo();
	static SGLocalHostInfo* Instance();
	void GetLocalMachine(char* name);
	int GetCurrentProcessID();
	void GetModelName(char* model);						//格式："机器名-进程ID"
	void GetPartName(const char* part, char* name);		//$name = $ModelName_$part

	void GetCurrentProcessName(char* name);				//获取当前进程名
	bool CreateInterProcMutex(const char* procname, void** ppMtx);	//创建进程间互斥锁
	void ReleaseInterProcMutex(void* pMtx);							//释放进程间互斥锁资源
};

#endif