// genstatisdef.h 

#ifndef _GENSTATISDEFINCE_PENSHIKANG_20150706_H_
#define _GENSTATISDEFINCE_PENSHIKANG_20150706_H_

enum GeneratorType
{
	GT_DG = 0,  //总发电
	GT_PV,      //光伏发电
	GT_WIND,    //风力发电
	GT_TURBINE, //燃气轮机
	GT_FUELCELL,//燃料电池
	GT_INCOMBUS,//内燃机
	GT_HYDRAULIC,//水轮机
	GT_TYPE7,
	GT_TYPE8,
	GT_TYPE9,
	GT_TYPE10,
	GT_STORAGE, //蓄电池储能
	GT_FLYWHEEL,//飞轮储能
	GT_SUPCAPAC,//超级电容器
	GT_SUPMAGNT,//超导磁储能
	GT_PUMPSTOR,//抽水储能
	GT_TYPE16,
	GT_INVALID  //无效发电
};

//发电机分类统计信息结构
typedef struct 
{
	double totalS; //发电机总容量(kW)
	int totalNum;  //发电机总台数
	double runS;   //发电机开机容量(kW)
	double maxP;   //发电机最大有功出力(kW), 用于计算渗透率
	int runNum;    //发电机开机台数
	double lmtS;   //发电机限电容量(kW)
	int lmtNum;    //发电机限电台数
	double curP;   //当前发电有功出力(kW)
	double curQ;   //当前发电无功出力(kVar)
	double todayW; //今日发电量(kWh)
	double totalW; //累计发电量(kWh)
	int repairNum; //检修台数
	int standbyNum;//待机台数
	int faultNum;  //故障台数

	double calcPCapa;//标杆发电机容量
	double curCalcP; //标杆发电机当前有功出力(kW)
	double adjPCapa; //可调发电机容量
	double adjMaxP;  //可调发电机有功出力上限
	double adjMinP;  //可调发电机有功出力下限
	double curAdjP;  //可调发电机当前有功出力(kW)
	double curFixP;  //不可调发电机当前有功出力(kW)
	double curAdjPo; //可调发电机总的有功灵敏度(kW)
	double totalPCapa;//总的可调发电机容量
	double maxPRate; //标杆发电机的最大发电率

}GeneClassStatisInfo;

#endif
