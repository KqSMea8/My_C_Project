#ifndef PDRCONTROL_ICE
#define PDRCONTROL_ICE

module modulePDR
{
	struct PDRApplyObj
	{
		string equipObj;
		string faultTime;
		double startTime;
		double endTime;
		int startFrame;
		int endFrame;
		string stationName;
		string feederName;
		string clientName;
		int playspeed;
		int interval;
	};

	struct analogTMeasValue
	{
		double dtUpdateTime;//更新数据的后台时间
		double dtDataTime;//前置上送数据时标
		double dRawValue; //前置上送的原始值
		double dCalValue; //计算值，熟数据
		int nQuality; //质量码	
	};

	struct hisalarmInfo
	{
		int objid;
		int alarmid;
		string objtype;
		double thetime;
		string description;
		string report;
		string actuser;
		double confirmtime;
		string objdesc;
		string thetimestr;
	};
	
	sequence<analogTMeasValue> AnalogValueSequence;

	sequence<hisalarmInfo> AlarmInfoSequence;

    interface PDRcontrol
    {     
	 //bool initialize();

	 //void setPDRPlayAttr(string faulttime, int startframe, int endframe, double starttime, double endtime, string stationname, string feedername);
	//回放申请
	 bool getplaybackhandler(PDRApplyObj applyobj);

	 //void playbyframe(int frame);
	 void jointheplayback(string clientName);
	//启动追忆播放
	 void play();

	//暂停追忆播放
	 void pause();

	//停止追忆播放
	 void stop();

	//播放前一帧
	 int PreviousFrame();

	//播放后一帧
	 int LatterFrame();

	//播放第几帧
	 void SetFrame(int FrameNum);

	//设置播放速度
	 void setplayspeed(int speedNum);

	//查询正在播放的事故
	//返回值PTREventSeq: 返回正在播放的回放参数列表
	 //void getplayingclient(string clientList, string equipObj, string faultTime);
	 
	 int getInitstatus();
	
	 int getplayframe();
	
	 string getplayingclientlist();
	 
	 string getplayingequipObj();
	 
	 string getplayingfaultTime();
	 
	 void connectCheck();
	 
	 void getanalogValue(int analogid, out AnalogValueSequence analogvalues);

	 void getalarminfo(out AlarmInfoSequence alarminfos);
    };

};

#endif
