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

#include "CommTrackingGoalJSON.hh"

#include <CommTrackingObjects/enumTrackingGoalType.hh>

namespace CommTrackingObjectsIDL {

void to_json(const CommTrackingObjectsIDL::CommTrackingGoal& obj, nlohmann::json& j)
{
	// trackingType: TrackingGoalType
	j["trackingType"] = CommTrackingObjects::TrackingGoalType(obj.trackingType).to_string(false);
	// angle: Double
	j["angle"] = obj.angle;
	// distance: Double
	j["distance"] = obj.distance;
	// x: Double
	j["x"] = obj.x;
	// y: Double
	j["y"] = obj.y;
	// isValid: Boolean
	j["isValid"] = obj.isValid;
	// cov: Double[]
	j["cov"] = obj.cov;
	// goalCount: UInt64
	j["goalCount"] = obj.goalCount;
}

/**
 * this transformation handles missing values and checks for correct types:
 * - missing primitive type values (including simple arrays) are set to zero values
 * - missing object type values are skipped entirely
 * - types are checked before performing the type-cast operation
 */
void from_json(const nlohmann::json& j, CommTrackingObjectsIDL::CommTrackingGoal& obj)
{
	// trackingType: TrackingGoalType
	if(j.contains("trackingType") && j["trackingType"].is_string()) {
		obj.trackingType = CommTrackingObjects::TrackingGoalType::from_string(j["trackingType"].get<std::string>());
	}
	// angle: Double
	if(j.contains("angle") && j["angle"].is_number_float()) {
		obj.angle = j["angle"].get<double>();
	}
	// distance: Double
	if(j.contains("distance") && j["distance"].is_number_float()) {
		obj.distance = j["distance"].get<double>();
	}
	// x: Double
	if(j.contains("x") && j["x"].is_number_float()) {
		obj.x = j["x"].get<double>();
	}
	// y: Double
	if(j.contains("y") && j["y"].is_number_float()) {
		obj.y = j["y"].get<double>();
	}
	// isValid: Boolean
	if(j.contains("isValid") && j["isValid"].is_boolean()) {
		obj.isValid = j["isValid"].get<bool>();
	}
	// cov: Double[]
	if(j.contains("cov") && j["cov"].is_array()) {
		obj.cov = j["cov"].get<std::vector<double>>();
	}
	// goalCount: UInt64
	if(j.contains("goalCount") && j["goalCount"].is_number_unsigned()) {
		obj.goalCount = j["goalCount"].get<unsigned long>();
	}
}

} // end namespace CommTrackingObjectsIDL
