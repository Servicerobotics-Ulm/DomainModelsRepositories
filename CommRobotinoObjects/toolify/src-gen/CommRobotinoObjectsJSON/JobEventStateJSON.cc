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

#include "JobEventStateJSON.hh"

#include "CommBasicObjectsJSON/CommTCLMessageJSON.hh"

namespace CommRobotinoObjectsIDL {

void to_json(const CommRobotinoObjectsIDL::JobEventState& obj, nlohmann::json& j)
{
	// robotTarget: String
	j["robotTarget"] = obj.robotTarget;
	// job: CommTCLMessage
	to_json(obj.job, j["job"]);
}

/**
 * this transformation handles missing values and checks for correct types:
 * - missing primitive type values (including simple arrays) are set to zero values
 * - missing object type values are skipped entirely
 * - types are checked before performing the type-cast operation
 */
void from_json(const nlohmann::json& j, CommRobotinoObjectsIDL::JobEventState& obj)
{
	// robotTarget: String
	if(j.contains("robotTarget") && j["robotTarget"].is_string()) {
		obj.robotTarget = j["robotTarget"].get<std::string>();
	}
	// job: CommTCLMessage
	if(j.contains("job") && j["job"].is_object()) {
		//from_json(j["job"], obj.job);
		obj.job = j["job"].get<CommBasicObjectsIDL::CommTCLMessage>();
	}
}

} // end namespace CommRobotinoObjectsIDL