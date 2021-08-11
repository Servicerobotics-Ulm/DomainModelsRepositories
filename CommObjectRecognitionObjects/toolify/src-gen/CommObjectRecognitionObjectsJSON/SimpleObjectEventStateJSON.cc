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

#include "SimpleObjectEventStateJSON.hh"

#include <CommObjectRecognitionObjects/enumSimpleObjectState.hh>

namespace CommObjectRecognitionObjectsIDL {

void to_json(const CommObjectRecognitionObjectsIDL::SimpleObjectEventState& obj, nlohmann::json& j)
{
	// newState: SimpleObjectState
	j["newState"] = CommObjectRecognitionObjects::SimpleObjectState(obj.newState).to_string(false);
	// x: Int32
	j["x"] = obj.x;
	// y: Int32
	j["y"] = obj.y;
}

/**
 * this transformation handles missing values and checks for correct types:
 * - missing primitive type values (including simple arrays) are set to zero values
 * - missing object type values are skipped entirely
 * - types are checked before performing the type-cast operation
 */
void from_json(const nlohmann::json& j, CommObjectRecognitionObjectsIDL::SimpleObjectEventState& obj)
{
	// newState: SimpleObjectState
	if(j.contains("newState") && j["newState"].is_string()) {
		obj.newState = CommObjectRecognitionObjects::SimpleObjectState::from_string(j["newState"].get<std::string>());
	}
	// x: Int32
	if(j.contains("x") && j["x"].is_number_integer()) {
		obj.x = j["x"].get<int>();
	}
	// y: Int32
	if(j.contains("y") && j["y"].is_number_integer()) {
		obj.y = j["y"].get<int>();
	}
}

} // end namespace CommObjectRecognitionObjectsIDL
