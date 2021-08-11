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

#include "CommDetectedMarkerEventParameterJSON.hh"

#include "CommTrackingObjectsJSON/CommDetectedMarkerListJSON.hh"

namespace CommTrackingObjectsIDL {

void to_json(const CommTrackingObjectsIDL::CommDetectedMarkerEventParameter& obj, nlohmann::json& j)
{
	// markers: CommDetectedMarkerList
	to_json(obj.markers, j["markers"]);
}

/**
 * this transformation handles missing values and checks for correct types:
 * - missing primitive type values (including simple arrays) are set to zero values
 * - missing object type values are skipped entirely
 * - types are checked before performing the type-cast operation
 */
void from_json(const nlohmann::json& j, CommTrackingObjectsIDL::CommDetectedMarkerEventParameter& obj)
{
	// markers: CommDetectedMarkerList
	if(j.contains("markers") && j["markers"].is_object()) {
		//from_json(j["markers"], obj.markers);
		obj.markers = j["markers"].get<CommTrackingObjectsIDL::CommDetectedMarkerList>();
	}
}

} // end namespace CommTrackingObjectsIDL
