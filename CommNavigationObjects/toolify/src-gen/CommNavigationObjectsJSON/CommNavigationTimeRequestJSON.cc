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

#include "CommNavigationTimeRequestJSON.hh"


namespace CommNavigationObjectsIDL {

void to_json(const CommNavigationObjectsIDL::CommNavigationTimeRequest& obj, nlohmann::json& j)
{
	// startPose: UInt32
	j["startPose"] = obj.startPose;
	// goalPose: UInt32
	j["goalPose"] = obj.goalPose;
}

/**
 * this transformation handles missing values and checks for correct types:
 * - missing primitive type values (including simple arrays) are set to zero values
 * - missing object type values are skipped entirely
 * - types are checked before performing the type-cast operation
 */
void from_json(const nlohmann::json& j, CommNavigationObjectsIDL::CommNavigationTimeRequest& obj)
{
	// startPose: UInt32
	if(j.contains("startPose") && j["startPose"].is_number_unsigned()) {
		obj.startPose = j["startPose"].get<unsigned int>();
	}
	// goalPose: UInt32
	if(j.contains("goalPose") && j["goalPose"].is_number_unsigned()) {
		obj.goalPose = j["goalPose"].get<unsigned int>();
	}
}

} // end namespace CommNavigationObjectsIDL
