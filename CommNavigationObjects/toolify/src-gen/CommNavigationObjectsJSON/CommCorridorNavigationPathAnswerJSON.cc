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

#include "CommCorridorNavigationPathAnswerJSON.hh"

#include "CommNavigationObjectsJSON/CommNavigationPathsJSON.hh"

namespace CommNavigationObjectsIDL {

void to_json(const CommNavigationObjectsIDL::CommCorridorNavigationPathAnswer& obj, nlohmann::json& j)
{
	// valid: Boolean
	j["valid"] = obj.valid;
	// paths: CommNavigationPaths
	to_json(obj.paths, j["paths"]);
}

/**
 * this transformation handles missing values and checks for correct types:
 * - missing primitive type values (including simple arrays) are set to zero values
 * - missing object type values are skipped entirely
 * - types are checked before performing the type-cast operation
 */
void from_json(const nlohmann::json& j, CommNavigationObjectsIDL::CommCorridorNavigationPathAnswer& obj)
{
	// valid: Boolean
	if(j.contains("valid") && j["valid"].is_boolean()) {
		obj.valid = j["valid"].get<bool>();
	}
	// paths: CommNavigationPaths
	if(j.contains("paths") && j["paths"].is_object()) {
		//from_json(j["paths"], obj.paths);
		obj.paths = j["paths"].get<CommNavigationObjectsIDL::CommNavigationPaths>();
	}
}

} // end namespace CommNavigationObjectsIDL