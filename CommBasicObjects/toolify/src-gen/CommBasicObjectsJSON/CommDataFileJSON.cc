//-----------------------------------------------------------------------------------
// Code generated by the Toolify Robotics GmbH extension for the SmartMDSD Toolchain 
// 
// Toolify Robotics GmbH
// Weinbergweg 216
// 89075 Ulm 
//
// Information about the SmartSoft MDSD Toolchain is available at:
// www.servicerobotik-ulm.de
//
// Please do not modify this file. It will be re-generated
// running the code generator.
//-----------------------------------------------------------------------------------

#include "CommDataFileJSON.hh"

#include "CommBasicObjectsJSON/CommTimeStampJSON.hh"

namespace CommBasicObjectsIDL {

void to_json(const CommBasicObjectsIDL::CommDataFile& obj, nlohmann::json& j)
{
	// filename: String
	j["filename"] = obj.filename;
	// filesize: UInt32
	j["filesize"] = obj.filesize;
	// timestamp: CommTimeStamp
	to_json(obj.timestamp, j["timestamp"]);
	// data: Int8[]
	j["data"] = obj.data;
	// valid: Boolean
	j["valid"] = obj.valid;
}

/**
 * this transformation handles missing values and checks for correct types:
 * - missing primitive type values (including simple arrays) are set to zero values
 * - missing object type values are skipped entirely
 * - types are checked before performing the type-cast operation
 */
void from_json(const nlohmann::json& j, CommBasicObjectsIDL::CommDataFile& obj)
{
	// filename: String
	if(j.contains("filename") && j["filename"].is_string()) {
		obj.filename = j["filename"].get<std::string>();
	}
	// filesize: UInt32
	if(j.contains("filesize") && j["filesize"].is_number_unsigned()) {
		obj.filesize = j["filesize"].get<unsigned int>();
	}
	// timestamp: CommTimeStamp
	if(j.contains("timestamp") && j["timestamp"].is_object()) {
		//from_json(j["timestamp"], obj.timestamp);
		obj.timestamp = j["timestamp"].get<CommBasicObjectsIDL::CommTimeStamp>();
	}
	// data: Int8[]
	if(j.contains("data") && j["data"].is_array()) {
		obj.data = j["data"].get<std::vector<char>>();
	}
	// valid: Boolean
	if(j.contains("valid") && j["valid"].is_boolean()) {
		obj.valid = j["valid"].get<bool>();
	}
}

} // end namespace CommBasicObjectsIDL