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

#include "CommObjectBeliefJSON.hh"

#include "CommBasicObjectsJSON/CommPose3dJSON.hh"

namespace CommObjectRecognitionObjectsIDL {

void to_json(const CommObjectRecognitionObjectsIDL::CommObjectBelief& obj, nlohmann::json& j)
{
	// type: String
	j["type"] = obj.type;
	// objClass: String
	j["objClass"] = obj.objClass;
	// probability: Double
	j["probability"] = obj.probability;
	// pose: CommPose3d
	to_json(obj.pose, j["pose"]);
	// cov: Double[]
	j["cov"] = obj.cov;
	// validPosePdf: Boolean
	j["validPosePdf"] = obj.validPosePdf;
	// validPose: Boolean
	j["validPose"] = obj.validPose;
}

/**
 * this transformation handles missing values and checks for correct types:
 * - missing primitive type values (including simple arrays) are set to zero values
 * - missing object type values are skipped entirely
 * - types are checked before performing the type-cast operation
 */
void from_json(const nlohmann::json& j, CommObjectRecognitionObjectsIDL::CommObjectBelief& obj)
{
	// type: String
	if(j.contains("type") && j["type"].is_string()) {
		obj.type = j["type"].get<std::string>();
	}
	// objClass: String
	if(j.contains("objClass") && j["objClass"].is_string()) {
		obj.objClass = j["objClass"].get<std::string>();
	}
	// probability: Double
	if(j.contains("probability") && j["probability"].is_number_float()) {
		obj.probability = j["probability"].get<double>();
	}
	// pose: CommPose3d
	if(j.contains("pose") && j["pose"].is_object()) {
		//from_json(j["pose"], obj.pose);
		obj.pose = j["pose"].get<CommBasicObjectsIDL::CommPose3d>();
	}
	// cov: Double[]
	if(j.contains("cov") && j["cov"].is_array()) {
		obj.cov = j["cov"].get<std::vector<double>>();
	}
	// validPosePdf: Boolean
	if(j.contains("validPosePdf") && j["validPosePdf"].is_boolean()) {
		obj.validPosePdf = j["validPosePdf"].get<bool>();
	}
	// validPose: Boolean
	if(j.contains("validPose") && j["validPose"].is_boolean()) {
		obj.validPose = j["validPose"].get<bool>();
	}
}

} // end namespace CommObjectRecognitionObjectsIDL
