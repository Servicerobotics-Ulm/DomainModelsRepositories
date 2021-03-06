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

#include "CommCoordinatedNavigationResourceRequestJSON.hh"


namespace CommRobotinoObjectsIDL {

void to_json(const CommRobotinoObjectsIDL::CommCoordinatedNavigationResourceRequest& obj, nlohmann::json& j)
{
	// resourceID: Int32
	j["resourceID"] = obj.resourceID;
	// robotID: Int32
	j["robotID"] = obj.robotID;
	// actionType: CoordinatedNavigationResourceRequestActionType
	j["actionType"] = obj.actionType;
}

/**
 * this transformation handles missing values and checks for correct types:
 * - missing primitive type values (including simple arrays) are set to zero values
 * - missing object type values are skipped entirely
 * - types are checked before performing the type-cast operation
 */
void from_json(const nlohmann::json& j, CommRobotinoObjectsIDL::CommCoordinatedNavigationResourceRequest& obj)
{
	// resourceID: Int32
	if(j.contains("resourceID") && j["resourceID"].is_number_integer()) {
		obj.resourceID = j["resourceID"].get<int>();
	}
	// robotID: Int32
	if(j.contains("robotID") && j["robotID"].is_number_integer()) {
		obj.robotID = j["robotID"].get<int>();
	}
	// actionType: CoordinatedNavigationResourceRequestActionType
	if(j.contains("actionType") && j["actionType"].is_number_integer()) {
		obj.actionType = j["actionType"].get<int>();
	}
}

} // end namespace CommRobotinoObjectsIDL
