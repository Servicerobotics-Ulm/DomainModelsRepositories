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

#include "CommMobileManipulatorProgramsJSON.hh"


namespace CommManipulatorObjectsIDL {

void to_json(const CommManipulatorObjectsIDL::CommMobileManipulatorPrograms& obj, nlohmann::json& j)
{
	// names: String[]
	j["names"] = obj.names;
	// isValid: Boolean
	j["isValid"] = obj.isValid;
}

/**
 * this transformation handles missing values and checks for correct types:
 * - missing primitive type values (including simple arrays) are set to zero values
 * - missing object type values are skipped entirely
 * - types are checked before performing the type-cast operation
 */
void from_json(const nlohmann::json& j, CommManipulatorObjectsIDL::CommMobileManipulatorPrograms& obj)
{
	// names: String[]
	if(j.contains("names") && j["names"].is_array()) {
		obj.names = j["names"].get<std::vector<std::string>>();
	}
	// isValid: Boolean
	if(j.contains("isValid") && j["isValid"].is_boolean()) {
		obj.isValid = j["isValid"].get<bool>();
	}
}

} // end namespace CommManipulatorObjectsIDL