//idataproxy.h
#ifndef _IDATAPROXY_2008_05_13_PENGSHIKANG_INCLUDED_
#define _IDATAPROXY_2008_05_13_PENGSHIKANG_INCLUDED_

#include "icsunknown.h"              // for IICSUnknown
#include "csf/dataobject_scada.h"    // for IICSDAObject

//#ifdef _MSC_VER
	#define DLL_DATAPROXY             "dataproxy"
//#else
//	#define DLL_DATAPROXY             "/home/ics8000/lib/icslib/dataproxy"
//#endif
#define CID_DATAPROXY           "cdataproxy"
#define IID_DATAPROXY           "idataproxy"

#ifndef PVOID
	typedef void* PVOID;
#endif

struct CAPP_SDO_Status
{
	double                   m_dTimeStamp;//��ֵԭʼʱ��
	int                      m_nRawValue; //״̬����ԭʼֵ
	unsigned short           m_nSrcId;    //���������Դ��
    unsigned short           m_nPntId;    //����Ĳɼ����
	int                      m_nEqpPos;   //�����豸ID
	int                      m_nBayPos;   //�������ID
	int                      m_nFacPos;   //������վID
};//Ӧ�ò�״̬������

struct CAPP_SDO_Analog
{
	double                   m_dTimeStamp;//��ֵԭʼʱ��
	double                   m_fRawValue; //ģ������ԭʼֵ
    unsigned short           m_nPntId;    //����Ĳɼ����
};//Ӧ�ò�ģ��������

struct CAPP_SDO_Soe
{
	double                   m_dTimeStamp;//��ֵԭʼʱ��
	double                   m_dTimeSpan; //���ʱ��
	short*                   m_pfRecord;  //���Ӳ���
	short                    m_nRawValue; //SOE����ԭʼֵ
	unsigned short           m_nNum;      //���Ӳ�������Ŀ
	unsigned short           m_nSrcId;    //���������Դ��
    unsigned short           m_nPntId;    //����Ĳɼ����
};//Ӧ�ò�SOE����

//Ӧ�ò�״̬��
#define   APP_OBJTYPE_STATUS          151
//Ӧ�ò�ģ����
#define   APP_OBJTYPE_ANALOG          152
//Ӧ�ò�SOE���󣨹��ϱ��棩
#define   APP_OBJTYPE_EVENTREPORT     161

//�����в�������
enum OperateType
{
		RECEIVEDAT,//�������������ϴ�������Ҫ���н���ȷ��
		RECEIVEACK,//�������������ϴ�����Ҫ���н���ȷ��
		GETFROMSRC,//ֱ�Ӵ�����Դ��ȡ����
		GETFROMBUF,//��CSF��ܵ����ݻ����ȡ����
		SELECTCTRL,//ѡ��
		OPERATCTRL,//ִ�п���
		CANCELCTRL,//��������
		CALLVERSION,//�汾�ٻ�
		MODIFYSETTING,//��ֵ�޸�
		SWITCHAREA, //�л���ֵ��
		PRESETSETTING, //Ԥװ��ֵ
		SAVESETTING, //�̻���ֵ
		CANCELSETTING, //ȡ��Ԥװ
		SETTING,		//��ֵ��װ
		SWITCHACTAREA, //�л�������    WX Modify
		SWITCHEDITAREA //�л��༭��    WX Modify
};

struct CSFDATASET //�����в�����CSF���ݼ��ṹ
{
	CSF_UINT32 operateId;//���β�����Ψһ��ʶ��
	CSF_UINT32 nSrcId;   //���β���������ԴID
	CSF_UINT32 type;     //���β��������ݶ�������
	CSF_UINT32 count;    //���β��������ݶ������
	PVOID* pObjects;//���β��������ݶ���ָ������
};

//class CDataProxyApp(CSF_UINT8 nAppId, IDataProxyCallback* pUser, CSF_UINT32 count, CSF_UINT8 dataTypes[], bool bBufferData);

//������Ϣ���нӿ�
class IDataProxyApp : virtual public IICSUnknown
{
public:
    /* �õ����ݶ���״̬ 
	   ����ֵ�����ݶ���״̬����ֵ�ĺ���Ϊ��
		   0, CSF��δ��½�ɹ�
		   1, ���ݶ��ĳɹ�
		   2, ���ݶ���ʧ��
		   3, ����Ҫ�������ݶ���
	*/
	virtual int GetSubscriptionState() = 0;
	
	/* Ͷ��һ����� 
	   ������
		nOperType������Ͷ�ݵĲ������͡�
		nTimeout������Ͷ�����õĳ�ʱʱ�䡣
		pObjects������Ͷ�ݲ�����CSF���ݼ���
		����ֵ��
		true,����Ͷ���Ѿ������ɡ�
		false,����Ͷ���޷���ɡ�
	*/
	virtual bool Post(OperateType nOperType, long nTimeout, CCSFTransBlock& transBlock) = 0;
	virtual bool Post(OperateType nOperType, long nTimeout, CSFDATASET* pObjects) = 0;
	
	/* ���ڽ��յ���һ��������ȷ�� 
	   ������
	    pObjects��Ӧ���߽��յ���CSF���ݼ���
	*/
	virtual bool ReceiveAck(CSFDATASET* pObjects) = 0;
	
	//����CSFͨѶ�ͻ���������ɫ
	virtual void SetRole(bool bMaster) = 0;


	/////////////////////////////////////////////////////////////////////////
	//���½ӿ��������߱��ǰ���ն˵�������Ϣ
	/////////////////////////////////////////////////////////////////////////

	/* ��ȡCSF������������ģʽ
	������
	   nNode��ͨѶ����ID
	   nProt��Э�����ģ��Id
    ���أ�0��ʧ�ܣ���ʾ���ݴ���Ŀǰ�޷����մ�ָ�
		  1�����ã�2�����ԣ�3������
	*/
	virtual int GetRunMode(int nNode, int nProt) = 0;
	
	/* �������Դͨ��
	   ������
	    count��������ӵ�����Դͨ������
	    pSrcChnls��������ӵ�����Դͨ������   
       ����ֵ��0���ɹ���ɴ���
	           1��ʧ�ܣ�
			   2��ʧ�ܣ�ָ�����ݴ�����գ���AddSrcChnlReturn()�ص�����δ��Ӧ
 	*/
	virtual int AddDataChannel(int count, CCSF_SrcChnl* pSrcChnls) = 0;

	/* ��Ӷ���
	   ������
          count,������ӵĶ������
          pObjects,������ӵĶ�������
          nNode��ͨѶ����ID
          nProt��Э�����ģ��Id
	   ���أ�0���ɹ�����ʾָ���ܽ��գ�����ɴ���
		     1��ʧ�ܣ���ʾ���Ŀǰ�޷����մ�ָ��
		     2: ʧ�ܣ���ʾ�����ظ�
		     3: ʧ�ܣ�ָ����ݴ�����գ���AddObjReturn()�ص�����δ��Ӧ
	*/
	virtual int AddObject(int count, CCSF_Object* pObjects,
							int nNode=1, int nProt=1)                 = 0;
	
	/* �޸Ķ���
	   ���أ�0���ɹ�����ʾָ���ܽ��գ�����ɴ���
			 1��ʧ�ܣ���ʾ���Ŀǰ�޷����մ�ָ��
			 2��ʧ�ܣ���ʾ�޷��޸ĵ�����
		     3: ʧ�ܣ�ָ����ݴ�����գ���SetObjReturn()�ص�����δ��Ӧ
    */
	virtual int SetObject(int count, CCSF_Object* pObjects,
							int nNode=1, int nProt=1)                 = 0;
	
	/* �޸Ķ���
	   ������
		  count,������ӵĶ������
		  pObjIds,���ݶ���Id����;
		  pCsfIds,���ݶ���CSFId����;
          nType,��������
          nNode��ͨѶ����ID
          nProt��Э�����ģ��Id
	   ���أ�0���ɹ�����ʾָ���ܽ��գ�����ɴ���
		  1��ʧ�ܣ���ʾ���Ŀǰ�޷����մ�ָ��
		  2��ʧ�ܣ���ʾ�޷��޸ĵ�����
		  3: ʧ�ܣ�ָ����ݴ�����գ���SetObjReturn()�ص�����δ��Ӧ
    */
	virtual int SetObjectByCSFId(int count, CSF_UINT32* pObjIds, CSF_UINT64* pCsfIds,
							CSF_UINT8 nType, int nNode=1, int nProt=1) = 0;

	/* ��ȡ����ԴID
	   ������          
		  count,���ص�����Դ����
		  pSrcIds,���ص�����ԴId����;
       ˵����Ӧ���ߵ��øú���ǰ����pSrcIds=NULL�����øú�������Ӧ����
	   ����delete pSrcIdsȥ�ͷ�pSrcIdsռ�õ��ڴ�ռ䡣
	*/
	virtual bool GetDataSourceID(int& count, CSF_INT32* pSrcIds)      = 0;

	/* ����ָ��������ԴID��ȡ����Դͨ��
	   ������          
	     nSrcId, ָ��������ԴID�����nSrcId=0����ʾ��ȡȫ������Դͨ����
	     count,���ص�����Դͨ������
	     pSrcChnls,���ص�����Դͨ������;
       ˵����Ӧ���ߵ��øú���ǰ����pSrcChnls=NULL�����øú�������Ӧ����
	   ����delete pSrcChnlsȥ�ͷ�pSrcChnlsռ�õ��ڴ�ռ䡣
	*/
	virtual bool GetDataChannelBySrcID(int& count, CCSF_SrcChnl* pSrcChnls, int nSrcId=0) = 0;

	/* ����CSFID��ȡ���� 
	˵����Ӧ���ߵ��øú���ǰ����pObject=NULL�����øú�������Ӧ����
	   ����delete pObjectȥ�ͷ�pObjectռ�õ��ڴ�ռ䡣
	*/
	virtual bool GetObjectByCsfID(CCSF_Object* pObject, 
							CSF_UINT64 nCsfId, int nNode=1, int nProt=1) = 0;
	
	/* �������ͻ�ȡ���� 
	˵����Ӧ���ߵ��øú���ǰ����pObjects=NULL�����øú�������Ӧ����
	   ����delete pObjectsȥ�ͷ�pObjectsռ�õ��ڴ�ռ䡣
	*/
	virtual bool GetObjectsByType(int count, CCSF_Object* pObjects,
							CSF_UCHAR nType, int nNode=1, int nProt=1) = 0;
	
	/* ���ݸ�����CSFID�����ͻ�ȡ����
	˵����Ӧ���ߵ��øú���ǰ����pObjects=NULL�����øú�������Ӧ����
	   ����delete pObjectsȥ�ͷ�pObjectsռ�õ��ڴ�ռ䡣
	*/
	virtual bool GetObjectsByElder(int count, CCSF_Object* pObjects,
							CSF_UINT64 nElderId, CSF_UCHAR  subType,		
							int nNode=1, int nProt=1)                  = 0;

	/* �������ݶ�������ͻ�ȡ�������ݶ����Id�Ͳ���
	˵����Ӧ���ߵ��øú���ǰ����strRefs��pObjIdsΪNULL�����øú�������Ӧ����
	   ����delete strRefs/pObjIdsȥ�ͷ�strRefs��pObjIdsռ�õ��ڴ�ռ䡣
	*/
	virtual bool GetAllObjIdAndRefByType(int count, 
							CSF_CHAR strRefs[][1024], CSF_UINT64* pObjIds,
							CSF_UINT8 nType,int nNode=1, int nProt=1)  = 0;

	//ǰ�ÿͻ������³�ʼ����@@@��2010-11-24
	virtual int ClearConfig() = 0;

	// ����CSFͨѶ�ͻ�����CSFͨѶ������������ //
	virtual bool UpdateCsfClient() = 0;

	// �Ƿ��¼DEBUG��־ //
	virtual void SetDebugLog(bool isDebug) = 0;

	// ������־�ļ��� //
	virtual void SetLogFileName(const char* fileName) = 0;

	static char *GetIntfName()
	{
		return IID_DATAPROXY;
	};

};

//������Ϣ���нӿ�
class IDataProxyCallback
{
public:
    /* ���յ�һ����� 
	   ������
	   nOperType�����ν��ղ����Ĳ������͡�
	   nResult�����ν��ղ����Ľ��ֵ���京��Ϊ��
		   0,�����ϴ�������
		   1,��ʾȫ���ɹ�����ٲ�������������������е�����ֵ��Ч�������ɹ��ģ�
		   2,��ʾȫ���ɹ���ɿ�����������������е�����ֵ��Ч��������ģ�
		   3,��ʾ���ֳɹ�����ٲ�������������������е�����ֵ��Ч�������ɹ��ģ�
		   4,��ʾ�������ʧ�ܣ����������е�����ֵ��Ч������ʧ�ܵģ�
		   5,��ʾ�ٲ��������ʧ�ܣ����������е�����ֵ��Ч��������ģ�
		   6,��ʾ�ٲ��������ʧ�ܣ��ж��ָ��ͬʱ�·���ͬһ����Դ��csf����޷����պ�����ָ�
		   7,��ʾ�ٲ����ʧ�ܣ���ʱ�޷�������Դ��ȡ���ݣ�nOperType��GETFROMSRCʱ���ܷ�����
	   pObjects�����ν��յ���CSF���ݼ���
	*/
    virtual void OnReceive(OperateType nOperType, int nResult, CSFDATASET* pObjects) = 0;

	//ͨ��״̬���
	virtual void OnChannelState(CSF_UINT32 nSrcId, CSF_UINT32 nCSFId,
		CSF_UINT32 nDpId, CSF_BOOLEAN bState) = 0;
};

#endif
