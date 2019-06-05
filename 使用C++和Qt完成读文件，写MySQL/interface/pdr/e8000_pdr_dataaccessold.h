#pragma once

#include <QMap>
#include <string>
#include <memory>

#include "rtdb\e8000_rtdbaccess_scada.h"
//#include <functional>
//#include <vector>


#if defined(_WIN32)
#ifdef pdr_dataaccess_BUILD_DLL
#define pdr_dataaccess_Export __declspec(dllexport)
#else
#define pdr_dataaccess_Export __declspec(dllimport)
#endif
#else
#define pdr_dataaccess_Export 
#endif

struct DBValue
{
	TMeasValue TMvalue;
	int Ivalue;
	double Dvalue;
	//std::string Svalue;
	QString Svalue;
	DBValue()
	{
		Ivalue = 0;
		Dvalue = 0;
		Svalue = QString("");
	}
};

struct FieldAttr
{
	std::vector<std::string> model_field;
	std::vector<std::string> model_fieldType;
	std::vector<std::string> rtdb_field;
	std::vector<std::string> rtdb_fieldType;
};

inline QDataStream &operator<<(QDataStream &out, const DBValue& inValue)
{
	out << inValue.TMvalue << inValue.Ivalue;
	out << inValue.Svalue << inValue.Dvalue;
	return out;
}

inline QDataStream &operator >> (QDataStream &in, DBValue& outValue)
{
	in >> outValue.TMvalue >> outValue.Ivalue;
	in >> outValue.Svalue >> outValue.Dvalue;
	return in;
}


class IPDRDataAccess
{
public:
	//连接本地模型库与实时库
	virtual bool ConnectCfg(const std::string& DBname) = 0;

	virtual int ReadModelDBbuckupAttr(const std::string& backupdate, std::string& filename, std::string& filepath) = 0;

	virtual int GetModelDBAttr(std::string& dbname, std::string& username, std::string& password, std::string& port) = 0;
	//按表名及字段读取实时库数据
	//输入参数：table_name   field_list（内容按‘，’隔开）
	//返回值rtdb_value_results： <id,<字段,结构体DBValue>>
	virtual int ReadRtdbData(const std::string& table_name, const std::string& field_list, QMap<int, QMap<QString, DBValue>>& rtdb_value_results) = 0;
	//按表名及字段读取模型库数据
	//输入参数：table_name   field_list（内容按‘，’隔开）
	//返回值rtdb_value_results： <id,<字段,结构体DBValue>>
	virtual int ReadModelData(const std::string& table_name, const std::string& field_list, QMap<int, QMap<QString, DBValue>>& model_value_results) = 0;

	virtual int WriteRtdbData(int frameNum, QList<QMap<QString, QMap<int, QMap<QString, DBValue>>>>& table_list) = 0;

	virtual int ReadHisData(const std::string& date_time, std::string& stationid, std::string& feederid_list, QList<QMap<QString, QMap<int, QMap<QString, DBValue>>>>& table_list) = 0;

	//按表名及字段名，从配置文件中读取其属性
	//输入参数：table_name   field_list（内容按‘，’隔开）
	//返回值field_attr结构体：包含所读模型库/实时库中字段的属性参数
	virtual bool ReadFieldAttr(std::string table_name, std::string field_list, FieldAttr& field_attr) = 0;
	//加载PDR配置信息文件
	//返回值m_PDRConfig：<表名,字段列表>
	virtual bool LoadPDRConfig(QMap<std::string, std::string>& m_PDRConfig) = 0;

};


extern "C" int pdr_dataaccess_Export  createPDRDataAccess(IPDRDataAccess** pp_pdrDataAccess);