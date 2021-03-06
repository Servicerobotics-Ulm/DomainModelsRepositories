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

#include "CommTimeStampJSON.hh"


namespace CommBasicObjectsIDL {

void to_json(const CommBasicObjectsIDL::CommTimeStamp& obj, nlohmann::json& j)
{
	// sec: UInt32
	j["sec"] = obj.sec;
	// usec: UInt32
	j["usec"] = obj.usec;
}

/**
 * this transformation handles missing values and checks for correct types:
 * - missing primitive type values (including simple arrays) are set to zero values
 * - missing object type values are skipped entirely
 * - types are checked before performing the type-cast operation
 */
void from_json(const nlohmann::json& j, CommBasicObjectsIDL::CommTimeStamp& obj)
{
	// sec: UInt32
	if(j.contains("sec") && j["sec"].is_number_unsigned()) {
		obj.sec = j["sec"].get<unsigned int>();
	}
	// usec: UInt32
	if(j.contains("usec") && j["usec"].is_number_unsigned()) {
		obj.usec = j["usec"].get<unsigned int>();
	}
}

} // end namespace CommBasicObjectsIDL
