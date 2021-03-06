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

#include "CommManipulatorEventStateJSON.hh"


namespace CommManipulatorObjectsIDL {

void to_json(const CommManipulatorObjectsIDL::CommManipulatorEventState& obj, nlohmann::json& j)
{
	// event: ManipulatorEvent
	j["event"] = obj.event;
}

/**
 * this transformation handles missing values and checks for correct types:
 * - missing primitive type values (including simple arrays) are set to zero values
 * - missing object type values are skipped entirely
 * - types are checked before performing the type-cast operation
 */
void from_json(const nlohmann::json& j, CommManipulatorObjectsIDL::CommManipulatorEventState& obj)
{
	// event: ManipulatorEvent
	if(j.contains("event") && j["event"].is_number_integer()) {
		obj.event = j["event"].get<int>();
	}
}

} // end namespace CommManipulatorObjectsIDL
