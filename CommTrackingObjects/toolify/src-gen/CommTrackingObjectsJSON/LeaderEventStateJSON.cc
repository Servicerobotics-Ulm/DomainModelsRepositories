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

#include "LeaderEventStateJSON.hh"

#include <CommTrackingObjects/enumLeaderEventType.hh>

namespace CommTrackingObjectsIDL {

void to_json(const CommTrackingObjectsIDL::LeaderEventState& obj, nlohmann::json& j)
{
	// type: LeaderEventType
	j["type"] = CommTrackingObjects::LeaderEventType(obj.type).to_string(false);
	// goal_x: Int32
	j["goal_x"] = obj.goal_x;
	// goal_y: Int32
	j["goal_y"] = obj.goal_y;
}

/**
 * this transformation handles missing values and checks for correct types:
 * - missing primitive type values (including simple arrays) are set to zero values
 * - missing object type values are skipped entirely
 * - types are checked before performing the type-cast operation
 */
void from_json(const nlohmann::json& j, CommTrackingObjectsIDL::LeaderEventState& obj)
{
	// type: LeaderEventType
	if(j.contains("type") && j["type"].is_string()) {
		obj.type = CommTrackingObjects::LeaderEventType::from_string(j["type"].get<std::string>());
	}
	// goal_x: Int32
	if(j.contains("goal_x") && j["goal_x"].is_number_integer()) {
		obj.goal_x = j["goal_x"].get<int>();
	}
	// goal_y: Int32
	if(j.contains("goal_y") && j["goal_y"].is_number_integer()) {
		obj.goal_y = j["goal_y"].get<int>();
	}
}

} // end namespace CommTrackingObjectsIDL
