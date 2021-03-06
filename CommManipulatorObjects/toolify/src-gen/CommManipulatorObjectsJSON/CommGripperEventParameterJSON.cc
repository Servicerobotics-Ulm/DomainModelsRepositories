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

#include "CommGripperEventParameterJSON.hh"


namespace CommManipulatorObjectsIDL {

void to_json(const CommManipulatorObjectsIDL::CommGripperEventParameter& obj, nlohmann::json& j)
{
	// gripper_event: GripperEvent
	j["gripper_event"] = obj.gripper_event;
}

/**
 * this transformation handles missing values and checks for correct types:
 * - missing primitive type values (including simple arrays) are set to zero values
 * - missing object type values are skipped entirely
 * - types are checked before performing the type-cast operation
 */
void from_json(const nlohmann::json& j, CommManipulatorObjectsIDL::CommGripperEventParameter& obj)
{
	// gripper_event: GripperEvent
	if(j.contains("gripper_event") && j["gripper_event"].is_number_integer()) {
		obj.gripper_event = j["gripper_event"].get<int>();
	}
}

} // end namespace CommManipulatorObjectsIDL
