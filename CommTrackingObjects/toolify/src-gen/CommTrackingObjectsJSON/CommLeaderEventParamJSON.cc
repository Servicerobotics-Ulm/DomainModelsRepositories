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

#include "CommLeaderEventParamJSON.hh"


namespace CommTrackingObjectsIDL {

void to_json(const CommTrackingObjectsIDL::CommLeaderEventParam& obj, nlohmann::json& j)
{
	// type: LeaderEventType
	j["type"] = obj.type;
}

/**
 * this transformation handles missing values and checks for correct types:
 * - missing primitive type values (including simple arrays) are set to zero values
 * - missing object type values are skipped entirely
 * - types are checked before performing the type-cast operation
 */
void from_json(const nlohmann::json& j, CommTrackingObjectsIDL::CommLeaderEventParam& obj)
{
	// type: LeaderEventType
	if(j.contains("type") && j["type"].is_number_integer()) {
		obj.type = j["type"].get<int>();
	}
}

} // end namespace CommTrackingObjectsIDL
