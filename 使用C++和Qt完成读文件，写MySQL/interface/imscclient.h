#ifndef IMSCCLIENT_H
#define IMSCCLIENT_H

#ifdef WIN32
#pragma pack(push) 
#endif
#pragma pack(1)

typedef struct TMSCMes{
	unsigned short  nType;      //��Ϣ����  ��>100��0��100����Ϣ����ʹ�ã�
	unsigned short	nLevel;     //��Ϣ���ȼ���1��3������1�ļ�����ͣ�
	long            nLength;    //��Ϣ�ĳ��ȣ����ֽڼǣ�
	unsigned char*  pBuf;       //��Ϣ����
}TMSCMES,*PTMSCMES;

typedef enum EMesTransType{
    By_MesType = 1,         //������Ϣ���ͷ���
	By_PartType,            //���ս���ģ�����ͷ���
	By_PartName             //������ָ����ĳһģ��
}EMESTRANSTYPE,*PEMESTRANSTYPE;

#ifdef WIN32
#pragma pack(pop)
#else 
#pragma pack()
#endif

#define		MSG_LEVEL_LOW		1	//�����ȼ�����
#define		MSG_LEVEL_NORMAL	2	//�������ȼ�����
#define		MSG_LEVEL_HIGH		3	//�����ȼ�

#ifdef WIN32
#ifdef MSCCLIENT_DLL_FILE
class _declspec(dllimport) IMSCClientCallBack  //������
#else
class _declspec(dllexport) IMSCClientCallBack  //������
#endif
#else
class IMSCClientCallBack
#endif

{
public:
    /*���յ�һ����Ϣ
	    ������   
		    pMsg���յ�����Ϣ�������߲����Ĵ˻�����ͷ�
		    nPoster������ϢͶ���ߵľ��
	    ����ֵ��
	        ��
    */
    virtual void OnRecv(PTMSCMES pMsg,char* psPoster) = 0;

    /*��ϢͶ�ݳ�ʱ
	    ������   
		    pMsg����Ͷ�ݵ���Ϣ�����������뿼�Ǹû�����ͷ�����
	    ����ֵ��
	        ��
    */
    virtual void OnPostTimeout(PTMSCMES pMsg) = 0;  

    /*��¼״̬�仯
	    ������   
		    lResult��
		          0: ��ʶ��¼�ɹ���������Ϣ���ĵ����ӻָ�(��¼��)��
		          1: �����ģ�����ƺ������ѵ�¼ģ���ظ�(��¼ʧ��)
			      2: ��Ϣ���ĵ��ڴ治�����µ�ģ���¼(��¼ʧ��)
			      3: ��¼�ɹ�������Ϣ���ĵ����ӶϿ�(״̬��Ϊ���ѵ�¼��)
	    ����ֵ��
	        ��
	    ˵����
	        ֻ�е�¼�ɹ������ܽ��պ�Ͷ����Ϣ��ʹ��ģ���ڵ������LogIn�����󣬿ͻ��˻��Զ����Բ�ά������Ϣ���ĵ���ϵ��
		    ����ϵ�жϣ���Ϣ�ͻ��˻���ô˺���֪ͨʹ��ģ�飻�ڵ�¼�ɹ�������ϵ�ָ�����Ϣ�ͻ���Ҳ����ô˺�������ͨ
		    ֪��ģ���ʼ��Ĭ��״̬Ϊ��δ��¼����
    */
    virtual void OnLogStaChange(long lResult) = 0;    

    /*��ѯģ�����
	    ������   
	        lPartnerNum��ģ����Ŀ
		    pPartners���ڴ�飬{һ��unsigned char�����ֳ��ȣ��������Ǹ�ģ������֣��ַ�����},
		               һ����lPartnerNum����˵Ľṹ
	    ����ֵ��
    */   
    virtual void OnQueryPartnersFinish(long lPartnerNum,
							   unsigned char* pPartners) = 0;

    /*��ѯ��ѯĳһģ�����Ϣ���
	    ������   
	        nType��ģ�������
            psPartName��ģ������ƻ�����
		    nAcquMsgNum�����ĵ���Ϣ������Ŀ
		    plMsgTypes�����ж��ĵ���Ϣ����
		    hModel����ģ�����������ӿ��ʶ
	    ����ֵ��
    */   
    virtual void OnQueryPartInfoFinish(unsigned short nType,
							   char* psPartName,
							   long nAcquMsgNum,
							   unsigned short *plMsgTypes,
							   char* psModel) = 0;
};

#ifdef WIN32
#ifdef MSCCLIENT_DLL_FILE
class _declspec(dllexport) IMSCClient
#else 
class _declspec(dllimport) IMSCClient
#endif
#else
class IMSCClient
#endif
{
public:
	
	/*Ͷ��һ����Ϣ
		������   
		pMsg����Ͷ�ݵ���Ϣ���ɵ�������IMESMAN_ONSENDFINISH�����������ͷ�
		eTType��ָ��Ͷ��Ҫ��
		nTransReference��ָ��Ͷ�ݲ���������eTType����ͬ
		    ��eTType��By_MesType����ֵ��Ч
			��eTType��By_PartType����ֵָ�������ߵ�����
			��eTType��By_PartName����ֵ��һ����char*����ָ������������
		lDeadline,����Ϣ�������ڣ��ڴ�ʱ������û�еִ���Ӧ�����ߣ�����ɾ��(��λ������)
		CallBackFunc��Ͷ����ɵĻص�����ָ��
		����ֵ��
		   true,����Ͷ���Ѿ������ɣ�����һ�������ɹ�����ʧ����ALLBACK_OnPostTimeout���ص�
		   false,����Ͷ���޷����
	*/
	virtual bool Post(PTMSCMES pMsg,
			EMESTRANSTYPE eTType,
			long nTransReference,
			unsigned long lDeadline) = 0;
	
	
	/*����Ϣ���Ľ��е�¼
		������   
			psPartName����¼�����ƣ�����������
			PartType����¼�����ͣ�ģ�����ͣ�
			lMesTypeNum��ģ�������ĵ���Ϣ������Ŀ
			pMesType��ģ�������ĵ�������Ϣ����
		����ֵ��
		    false�����ε�¼Ҫ�󱻽���
		    true�� ���ε�¼�޷�������
		˵����
		    1. ����Ϣ���ĵ�¼�󣬼�ʹ�����ĵ������жϣ���Ͷ����ָ������Ϣ�������ڣ����Ļ�Ϊ���ͻ�
			   ��������Ϣ�������ͻ����������½������Ӻ��յ������Ϣ����
			2. ��¼�Ƿ�ɹ������ߵ�ǰ����Ϣ���ĵ����������OnLogStaChange�ص�������֪��
	*/
	virtual bool LogIn(char* psPartName,
			unsigned short PartType,
			long lMesTypeNum,
			unsigned short* pMesType) = 0;
	
	/*����Ϣ���Ľ���ע��
		������   ��
		����ֵ�� 
		     true,  ��ָ���ѱ��ͻ��˳������
			 false�������ڴ�ԭ����ʱ�޷�����
		˵����
		     �ͻ��˱����������˳���������Ҫ����Ϣ����ʱ����Ϣ����ע����������Ϣ���Ļ����
			 �����Ϣ��������Ϊ�ÿͻ���������ΪͶ�ݵ���Ϣ�������ӶϿ�ʱ����
	*/
	virtual bool LogOut() = 0;
	
	
	/*����ģ����Ϣ��������δ���Ͷ��������Ϣ
		������   ��
		����ֵ�� ��
	*/   
	virtual void ClearQueue() = 0;
	
	
	/*��ѯ��ǰϵͳ������������Ϣ���ĵ�¼��ģ��
		������   
			nTimeOut,���β�����ʱ��Ҫ�󣬽�ʱ��ʧ�ܴ���
		����ֵ�� 
		    true,  ��ָ���ѱ��ͻ��˳������
			false�������ڴ�ԭ����ʱ�޷�����
	*/   
	virtual bool QueryPartners(unsigned long nTimeOut) = 0;
	
	/*��ѯ��ѯĳһģ�����Ϣ
		������   
			hPartner��ĳһģ��ľ��
			nTimeOut,���β�����ʱ��Ҫ�󣬽�ʱ��ʧ�ܴ���
			CallBackFunc����ѯ��ɵĻص�����ָ��
		����ֵ�� 
		    true,  ��ָ���ѱ��ͻ��˳������
			false�������ڴ�ԭ����ʱ�޷�����
	*/   
	virtual bool QueryPartInfo(char* psPartner,
			unsigned long nTimeOut) = 0;	

	/*������Ϣ�������Ŀͻ�������Ҫ�Ļص�����
		������   
			IMSCClientCallBack* pCallBacks ���ص��ӿڣ��μ�������
		����ֵ�� 
		    ��
	*/   
    virtual void SetCallBackInterface(IMSCClientCallBack* pCallBacks) = 0;
};


/*

��Ϣ������
��Ҫ���ڿ�ƽ̨������Ϣʱ���ֽ�˳��ת������.

InitBuffer:
��/��˫������,��ʼ��ʱָ�������������ַ������

SetXXXX(unsigned long lPos, unsigned XXX xV)
���ͷ�����,�����ݴ������ֽ���ת���������ֽ���,��д�뻺����Ӧƫ�Ƶ�ַ.

GetXXXX(unsigned long lPos, unsigned XXX & xV):
���շ�����,�ӻ�����Ӧƫ�Ƶ�ַȡ������,���������ֽ���ת���������ֽ���.

*/ 

#ifdef WIN32
#ifdef MSCCLIENT_DLL_FILE
class _declspec(dllexport) CMSCBuffer
#else 
class _declspec(dllimport) CMSCBuffer
#endif
#else
class CMSCBuffer
#endif
{
public:
	CMSCBuffer();
	~CMSCBuffer();
private:
	unsigned char* m_pBuf;
	unsigned short	m_sLength;
public:
	bool InitBuffer(unsigned char* pBuf, short nLength);
	bool SetShort(unsigned long lPos, unsigned short sV);
	bool SetLong(unsigned long lPos, unsigned long lV);
	bool SetFloat(unsigned long lPos, float fV);
	bool GetShort(unsigned long lPos, unsigned short & sV);
	bool GetLong(unsigned long lPos, unsigned long & lV);
	bool GetFloat(unsigned long lPos, float& fV);
//	bool GetBuffer(unsigned char* pBuf);
};


#ifdef WIN32

/*��ȡһ����Ϣ���Ŀͻ��˵Ľӿ�
	������   
	    hModel�������ӿ�ı�ʶ����ֵӦ����ȫϵͳ���������Ǳ�����Ψһ
		    ��ͬһ���̶�ε��ñ�����ʱ��Ӧ��������ͬ��ֵ
		CenterPort����Ϣ���ĵķ���˿�(����һ)
		CenterIP����Ϣ���ĵ�IP��ַ(����һ)
		CenterPort2����Ϣ���ĵķ���˿�(�����)
		CenterIP2����Ϣ���ĵ�IP��ַ(�����)
	����ֵ��
	˵����
	    ��Ϊ�������뽫CenterIP2��ΪNULL��0��
*/   
#ifdef MSCCLIENT_DLL_FILE
extern "C" _declspec(dllexport) IMSCClient* GetMSCClient(char* psModel,
						unsigned short CenterPort,char* CenterIP,
						unsigned short CenterPort2,char* CenterIP2);
#else
extern "C" _declspec(dllimport) IMSCClient* GetMSCClient(char* psModel,
                        unsigned short CenterPort,char* CenterIP,
						unsigned short CenterPort2,char* CenterIP2);
#endif


/*ɾ��һ������ʹ�õĽӿ�
	������   
	    IMSCClient* pClient �� ��ɾ���Ľӿ�
	����ֵ��
	˵����
*/   
#ifdef MSCCLIENT_DLL_FILE
extern "C" _declspec(dllexport) void RemoveMSCClient(IMSCClient* pInterface);
#else
extern "C" _declspec(dllimport) void RemoveMSCClient(IMSCClient* pInterface);
#endif


/*������Ϣ����ͻ�����־��¼����
     ������  ������־��·��������
	 ����ֵ����
	 ˵����
	         ������������
*/
#ifdef MSCCLIENT_DLL_FILE
extern "C" _declspec(dllexport) void BeginLog(char* psPath);
#else
extern "C" _declspec(dllimport) void BeginLog(char* psPath);
#endif


/*������Ϣ����
     ������ 
	 ����ֵ��0 , �µ���Ϣ������
	         1 , ����������Ҫ��
			 2 , �µ���Ϣ��������ͬ�������Ѿ����¹�
	 ˵����             
*/
#ifdef MSCCLIENT_DLL_FILE
extern "C" _declspec(dllexport) unsigned char  RefreshMSCenter(char* psModel,
					 unsigned short CenterPort,char* CenterIP,
					 unsigned short CenterPort2,char* CenterIP2);
#else
extern "C" _declspec(dllimport) unsigned char  RefreshMSCenter(char* psModel,
					 unsigned short CenterPort,char* CenterIP,
					 unsigned short CenterPort2,char* CenterIP2);
#endif

#else

extern "C"
IMSCClient* GetMSCClient(char* psModel,
						unsigned short CenterPort,char* CenterIP,
						unsigned short CenterPort2,char* CenterIP2);

extern "C"
void RemoveMSCClient(IMSCClient* pInterface);

extern "C"
unsigned char  RefreshMSCenter(char* psModel,
					 unsigned short CenterPort,char* CenterIP,
					 unsigned short CenterPort2,char* CenterIP2);

extern "C"
void BeginLog(char* psPath);
#endif

#endif
