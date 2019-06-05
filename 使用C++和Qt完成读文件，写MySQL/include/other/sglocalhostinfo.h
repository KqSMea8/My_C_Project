#ifndef __SGLOCALHOSTINFO_H_20080428 
#define __SGLOCALHOSTINFO_H_20080428

/*
 * ������Ϣʵ����
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
	void GetModelName(char* model);						//��ʽ��"������-����ID"
	void GetPartName(const char* part, char* name);		//$name = $ModelName_$part

	void GetCurrentProcessName(char* name);				//��ȡ��ǰ������
	bool CreateInterProcMutex(const char* procname, void** ppMtx);	//�������̼以����
	void ReleaseInterProcMutex(void* pMtx);							//�ͷŽ��̼以������Դ
};

#endif