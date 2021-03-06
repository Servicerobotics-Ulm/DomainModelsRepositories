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

#include "CommGripperEventJSON.hh"


namespace CommManipulatorObjectsIDL {

void to_json(const CommManipulatorObjectsIDL::CommGripperEvent& obj, nlohmann::json& j)
{
	// gripper_event: GripperEvent
	j["gripper_event"] = obj.gripper_event;
	// pos: Float
	j["pos"] = obj.pos;
}

/**
 * this transformation handles missing values and checks for correct types:
 * - missing primitive type values (including simple arrays) are set to zero values
 * - missing object type values are skipped entirely
 * - types are checked before performing the type-cast operation
 */
void from_json(const nlohmann::json& j, CommManipulatorObjectsIDL::CommGripperEvent& obj)
{
	// gripper_event: GripperEvent
	if(j.contains("gripper_event") && j["gripper_event"].is_number_integer()) {
		obj.gripper_event = j["gripper_event"].get<int>();
	}
	// pos: Float
	if(j.contains("pos") && j["pos"].is_number_float()) {
		obj.pos = j["pos"].get<float>();
	}
}

} // end namespace CommManipulatorObjectsIDL
