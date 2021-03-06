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

#include "PropertyItemEntryJSON.hh"


namespace CommBasicObjectsIDL {

void to_json(const CommBasicObjectsIDL::PropertyItemEntry& obj, nlohmann::json& j)
{
	// key: String
	j["key"] = obj.key;
	// value: String
	j["value"] = obj.value;
	// parent: UInt32
	j["parent"] = obj.parent;
}

/**
 * this transformation handles missing values and checks for correct types:
 * - missing primitive type values (including simple arrays) are set to zero values
 * - missing object type values are skipped entirely
 * - types are checked before performing the type-cast operation
 */
void from_json(const nlohmann::json& j, CommBasicObjectsIDL::PropertyItemEntry& obj)
{
	// key: String
	if(j.contains("key") && j["key"].is_string()) {
		obj.key = j["key"].get<std::string>();
	}
	// value: String
	if(j.contains("value") && j["value"].is_string()) {
		obj.value = j["value"].get<std::string>();
	}
	// parent: UInt32
	if(j.contains("parent") && j["parent"].is_number_unsigned()) {
		obj.parent = j["parent"].get<unsigned int>();
	}
}

} // end namespace CommBasicObjectsIDL
