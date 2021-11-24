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

#include "CommKBRequestJSON.hh"


namespace CommBasicObjectsIDL {

void to_json(const CommBasicObjectsIDL::CommKBRequest& obj, nlohmann::json& j)
{
	// request: String
	j["request"] = obj.request;
}

/**
 * this transformation handles missing values and checks for correct types:
 * - missing primitive type values (including simple arrays) are set to zero values
 * - missing object type values are skipped entirely
 * - types are checked before performing the type-cast operation
 */
void from_json(const nlohmann::json& j, CommBasicObjectsIDL::CommKBRequest& obj)
{
	// request: String
	if(j.contains("request") && j["request"].is_string()) {
		obj.request = j["request"].get<std::string>();
	}
}

} // end namespace CommBasicObjectsIDL