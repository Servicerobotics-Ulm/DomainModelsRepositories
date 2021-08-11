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

#include "CommCdlRobotBlockedEventResultJSON.hh"

#include <CommNavigationObjects/enumCdlRobotBlockEventType.hh>

namespace CommNavigationObjectsIDL {

void to_json(const CommNavigationObjectsIDL::CommCdlRobotBlockedEventResult& obj, nlohmann::json& j)
{
	// state: CdlRobotBlockEventType
	j["state"] = CommNavigationObjects::CdlRobotBlockEventType(obj.state).to_string(false);
}

/**
 * this transformation handles missing values and checks for correct types:
 * - missing primitive type values (including simple arrays) are set to zero values
 * - missing object type values are skipped entirely
 * - types are checked before performing the type-cast operation
 */
void from_json(const nlohmann::json& j, CommNavigationObjectsIDL::CommCdlRobotBlockedEventResult& obj)
{
	// state: CdlRobotBlockEventType
	if(j.contains("state") && j["state"].is_string()) {
		obj.state = CommNavigationObjects::CdlRobotBlockEventType::from_string(j["state"].get<std::string>());
	}
}

} // end namespace CommNavigationObjectsIDL
