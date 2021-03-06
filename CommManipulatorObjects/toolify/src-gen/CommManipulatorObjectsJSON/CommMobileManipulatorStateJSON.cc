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

#include "CommMobileManipulatorStateJSON.hh"

#include "CommManipulatorObjectsJSON/CommManipulatorStateJSON.hh"
#include "CommBasicObjectsJSON/CommBaseStateJSON.hh"

namespace CommManipulatorObjectsIDL {

void to_json(const CommManipulatorObjectsIDL::CommMobileManipulatorState& obj, nlohmann::json& j)
{
	// manipulator_state: CommManipulatorState
	to_json(obj.manipulator_state, j["manipulator_state"]);
	// base_state: CommBaseState
	to_json(obj.base_state, j["base_state"]);
}

/**
 * this transformation handles missing values and checks for correct types:
 * - missing primitive type values (including simple arrays) are set to zero values
 * - missing object type values are skipped entirely
 * - types are checked before performing the type-cast operation
 */
void from_json(const nlohmann::json& j, CommManipulatorObjectsIDL::CommMobileManipulatorState& obj)
{
	// manipulator_state: CommManipulatorState
	if(j.contains("manipulator_state") && j["manipulator_state"].is_object()) {
		//from_json(j["manipulator_state"], obj.manipulator_state);
		obj.manipulator_state = j["manipulator_state"].get<CommManipulatorObjectsIDL::CommManipulatorState>();
	}
	// base_state: CommBaseState
	if(j.contains("base_state") && j["base_state"].is_object()) {
		//from_json(j["base_state"], obj.base_state);
		obj.base_state = j["base_state"].get<CommBasicObjectsIDL::CommBaseState>();
	}
}

} // end namespace CommManipulatorObjectsIDL
