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

#include "CommDetectedMarkerListJSON.hh"

#include "CommTrackingObjectsJSON/CommDetectedMarkerJSON.hh"
#include "CommBasicObjectsJSON/CommPose3dJSON.hh"
#include "CommBasicObjectsJSON/CommBaseStateJSON.hh"

namespace CommTrackingObjectsIDL {

void to_json(const CommTrackingObjectsIDL::CommDetectedMarkerList& obj, nlohmann::json& j)
{
	// markers: CommDetectedMarker[]
	for(size_t idx=0; idx < obj.markers.size(); idx++) {
		nlohmann::json array_element;
		to_json(obj.markers.at(idx), array_element);
		j["markers"].emplace_back(array_element);
	}
	// sensor_pose: CommPose3d
	to_json(obj.sensor_pose, j["sensor_pose"]);
	// base_state: CommBaseState
	to_json(obj.base_state, j["base_state"]);
	// single_pose: Boolean
	j["single_pose"] = obj.single_pose;
	// valid: Boolean
	j["valid"] = obj.valid;
}

/**
 * this transformation handles missing values and checks for correct types:
 * - missing primitive type values (including simple arrays) are set to zero values
 * - missing object type values are skipped entirely
 * - types are checked before performing the type-cast operation
 */
void from_json(const nlohmann::json& j, CommTrackingObjectsIDL::CommDetectedMarkerList& obj)
{
	// markers: CommDetectedMarker[]
	if(j.contains("markers") && j["markers"].is_array()) {
		auto jmarkers = j["markers"];
		obj.markers.resize(jmarkers.size());
		for(size_t idx=0; idx < jmarkers.size(); idx++) {
			// convert the json array values individually
			if(jmarkers.at(idx).is_object()) {
				// from_json(jmarkers.at(idx), obj.markers.at(idx));
				obj.markers[idx] = jmarkers[idx].get<CommTrackingObjectsIDL::CommDetectedMarker>();
			}
		}
	}
	// sensor_pose: CommPose3d
	if(j.contains("sensor_pose") && j["sensor_pose"].is_object()) {
		//from_json(j["sensor_pose"], obj.sensor_pose);
		obj.sensor_pose = j["sensor_pose"].get<CommBasicObjectsIDL::CommPose3d>();
	}
	// base_state: CommBaseState
	if(j.contains("base_state") && j["base_state"].is_object()) {
		//from_json(j["base_state"], obj.base_state);
		obj.base_state = j["base_state"].get<CommBasicObjectsIDL::CommBaseState>();
	}
	// single_pose: Boolean
	if(j.contains("single_pose") && j["single_pose"].is_boolean()) {
		obj.single_pose = j["single_pose"].get<bool>();
	}
	// valid: Boolean
	if(j.contains("valid") && j["valid"].is_boolean()) {
		obj.valid = j["valid"].get<bool>();
	}
}

} // end namespace CommTrackingObjectsIDL