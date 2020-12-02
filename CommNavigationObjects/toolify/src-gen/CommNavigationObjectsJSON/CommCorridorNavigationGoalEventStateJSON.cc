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

#include "CommCorridorNavigationGoalEventStateJSON.hh"

#include "CommBasicObjectsJSON/CommPosition3dJSON.hh"

namespace CommNavigationObjectsIDL {

void to_json(const CommNavigationObjectsIDL::CommCorridorNavigationGoalEventState& obj, nlohmann::json& j)
{
	// newState: PathNavigationEventType
	j["newState"] = obj.newState;
	// nextGoal: CommPosition3d
	to_json(obj.nextGoal, j["nextGoal"]);
}

/**
 * this transformation handles missing values and checks for correct types:
 * - missing primitive type values (including simple arrays) are set to zero values
 * - missing object type values are skipped entirely
 * - types are checked before performing the type-cast operation
 */
void from_json(const nlohmann::json& j, CommNavigationObjectsIDL::CommCorridorNavigationGoalEventState& obj)
{
	// newState: PathNavigationEventType
	if(j.contains("newState") && j["newState"].is_number_integer()) {
		obj.newState = j["newState"].get<int>();
	}
	// nextGoal: CommPosition3d
	if(j.contains("nextGoal") && j["nextGoal"].is_object()) {
		//from_json(j["nextGoal"], obj.nextGoal);
		obj.nextGoal = j["nextGoal"].get<CommBasicObjectsIDL::CommPosition3d>();
	}
}

} // end namespace CommNavigationObjectsIDL
