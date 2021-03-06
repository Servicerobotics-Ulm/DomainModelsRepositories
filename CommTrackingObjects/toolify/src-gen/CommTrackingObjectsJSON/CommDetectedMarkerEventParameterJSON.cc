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


namespace CommTrackingObjectsIDL {

void to_json(const CommTrackingObjectsIDL::CommDetectedMarkerEventParameter& obj, nlohmann::json& j)
{
	// tag_ids: UInt32[]
	j["tag_ids"] = obj.tag_ids;
}

/**
 * this transformation handles missing values and checks for correct types:
 * - missing primitive type values (including simple arrays) are set to zero values
 * - missing object type values are skipped entirely
 * - types are checked before performing the type-cast operation
 */
void from_json(const nlohmann::json& j, CommTrackingObjectsIDL::CommDetectedMarkerEventParameter& obj)
{
	// tag_ids: UInt32[]
	if(j.contains("tag_ids") && j["tag_ids"].is_array()) {
		obj.tag_ids = j["tag_ids"].get<std::vector<unsigned int>>();
	}
}

} // end namespace CommTrackingObjectsIDL
