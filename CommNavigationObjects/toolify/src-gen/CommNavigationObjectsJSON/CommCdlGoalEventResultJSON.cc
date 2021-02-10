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

#include "CommCdlGoalEventResultJSON.hh"


namespace CommNavigationObjectsIDL {

void to_json(const CommNavigationObjectsIDL::CommCdlGoalEventResult& obj, nlohmann::json& j)
{
	// state: CdlGoalEventType
	j["state"] = obj.state;
}

/**
 * this transformation handles missing values and checks for correct types:
 * - missing primitive type values (including simple arrays) are set to zero values
 * - missing object type values are skipped entirely
 * - types are checked before performing the type-cast operation
 */
void from_json(const nlohmann::json& j, CommNavigationObjectsIDL::CommCdlGoalEventResult& obj)
{
	// state: CdlGoalEventType
	if(j.contains("state") && j["state"].is_number_integer()) {
		obj.state = j["state"].get<int>();
	}
}

} // end namespace CommNavigationObjectsIDL
