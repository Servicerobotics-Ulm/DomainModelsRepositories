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

#include "CommExternalProgramArgumentJSON.hh"


namespace DomainExternalSystemsIDL {

void to_json(const DomainExternalSystemsIDL::CommExternalProgramArgument& obj, nlohmann::json& j)
{
	// name: String
	j["name"] = obj.name;
	// type: String
	j["type"] = obj.type;
	// value: String
	j["value"] = obj.value;
}

/**
 * this transformation handles missing values and checks for correct types:
 * - missing primitive type values (including simple arrays) are set to zero values
 * - missing object type values are skipped entirely
 * - types are checked before performing the type-cast operation
 */
void from_json(const nlohmann::json& j, DomainExternalSystemsIDL::CommExternalProgramArgument& obj)
{
	// name: String
	if(j.contains("name") && j["name"].is_string()) {
		obj.name = j["name"].get<std::string>();
	}
	// type: String
	if(j.contains("type") && j["type"].is_string()) {
		obj.type = j["type"].get<std::string>();
	}
	// value: String
	if(j.contains("value") && j["value"].is_string()) {
		obj.value = j["value"].get<std::string>();
	}
}

} // end namespace DomainExternalSystemsIDL
