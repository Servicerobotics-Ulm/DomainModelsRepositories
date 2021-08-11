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

#include "CommCorridorNavigationPoseRequestEventStateJSON.hh"

#include <CommNavigationObjects/enumNodeRequestAnserType.hh>

namespace CommNavigationObjectsIDL {

void to_json(const CommNavigationObjectsIDL::CommCorridorNavigationPoseRequestEventState& obj, nlohmann::json& j)
{
	// newState: NodeRequestAnserType
	j["newState"] = CommNavigationObjects::NodeRequestAnserType(obj.newState).to_string(false);
}

/**
 * this transformation handles missing values and checks for correct types:
 * - missing primitive type values (including simple arrays) are set to zero values
 * - missing object type values are skipped entirely
 * - types are checked before performing the type-cast operation
 */
void from_json(const nlohmann::json& j, CommNavigationObjectsIDL::CommCorridorNavigationPoseRequestEventState& obj)
{
	// newState: NodeRequestAnserType
	if(j.contains("newState") && j["newState"].is_string()) {
		obj.newState = CommNavigationObjects::NodeRequestAnserType::from_string(j["newState"].get<std::string>());
	}
}

} // end namespace CommNavigationObjectsIDL
