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

#include "CommCorridorNavigationPoseAnswerJSON.hh"

#include <CommNavigationObjects/enumNodeRequestAnserType.hh>

namespace CommNavigationObjectsIDL {

void to_json(const CommNavigationObjectsIDL::CommCorridorNavigationPoseAnswer& obj, nlohmann::json& j)
{
	// result: NodeRequestAnserType
	j["result"] = CommNavigationObjects::NodeRequestAnserType(obj.result).to_string(false);
}

/**
 * this transformation handles missing values and checks for correct types:
 * - missing primitive type values (including simple arrays) are set to zero values
 * - missing object type values are skipped entirely
 * - types are checked before performing the type-cast operation
 */
void from_json(const nlohmann::json& j, CommNavigationObjectsIDL::CommCorridorNavigationPoseAnswer& obj)
{
	// result: NodeRequestAnserType
	if(j.contains("result") && j["result"].is_string()) {
		obj.result = CommNavigationObjects::NodeRequestAnserType::from_string(j["result"].get<std::string>());
	}
}

} // end namespace CommNavigationObjectsIDL