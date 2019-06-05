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

TMeasValue TMvalue;

struct DBValue
{
	//TMeasValue TMvalue;
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
	out << inValue.Ivalue;
	out << inValue.Svalue << inValue.Dvalue;
	return out;
}

inline QDataStream &operator >> (QDataStream &in, DBValue& outValue)
{
	in >> outValue.Ivalue;
	in >> outValue.Svalue >> outValue.Dvalue;
	return in;
}


class IPDRDataAccess
{
public:
	virtual bool ConnectCfg(const std::string& DBname) = 0;

	virtual int ReadModelDBbuckupAttr(const std::string& backupdate, std::string& filename, std::string& filepath) = 0;

	virtual int GetModelDBAttr(std::string& dbname, std::string& username, std::string& password, std::string& port) = 0;

	virtual int ReadRtdbData(const std::string& table_name, const std::string& field_list, QMap<int, QMap<QString, DBValue>>& rtdb_value_results) = 0;

	virtual int ReadRtdbValue(const std::string& table_name, const std::string& field_list, QMap<int, TMeasValue>& rtdb_value_results) = 0;

	virtual int ReadModelData(const std::string& table_name, const std::string& field_list, QMap<int, QMap<QString, DBValue>>& model_value_results) = 0;

	virtual int WriteRtdbData(int frameNum, QList<QMap<QString, QMap<int, QMap<QString, DBValue>>>>& table_list) = 0;

	virtual int WriteRtdbValue(int frameNum, QList<QMap<std::vector<std::string>, std::vector<TMeasValue>>>& hisdata_value_list) = 0;

	virtual int ReadHisData(const std::string& date_time, std::string& stationid, std::string& feederid_list, std::string& eventid, QList<QMap<QString, QMap<int, QMap<QString, DBValue>>>>& table_list) = 0;

	virtual int ReadHisValue(const std::string& event_id, const std::string& table_name, QList<QMap<int, TMeasValue>>& frame_value_list) = 0;

	virtual bool constructRtdbValue(QList<QMap<int, TMeasValue>>& analog_value, QList<QMap<int, TMeasValue>>& status_value, QList<QMap<std::vector<std::string>, std::vector<TMeasValue>>>& value_list) = 0;

	virtual bool ReadFieldAttr(std::string table_name, std::string field_list, FieldAttr& field_attr) = 0;

	virtual bool LoadPDRConfig(QMap<std::string, std::string>& m_PDRConfig) = 0;
};

extern "C" int pdr_dataaccess_Export  createPDRDataAccess(IPDRDataAccess** pp_pdrDataAccess);