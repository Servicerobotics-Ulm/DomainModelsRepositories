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

#include "CommObjectRecognitionEnvironmentJSON.hh"

#include "CommObjectRecognitionObjectsJSON/CommObjectRecognitionObjectPropertiesJSON.hh"

namespace CommObjectRecognitionObjectsIDL {

void to_json(const CommObjectRecognitionObjectsIDL::CommObjectRecognitionEnvironment& obj, nlohmann::json& j)
{
	// is_valid: Boolean
	j["is_valid"] = obj.is_valid;
	// objects: CommObjectRecognitionObjectProperties[]
	for(size_t idx=0; idx < obj.objects.size(); idx++) {
		nlohmann::json array_element;
		to_json(obj.objects.at(idx), array_element);
		j["objects"].emplace_back(array_element);
	}
}

/**
 * this transformation handles missing values and checks for correct types:
 * - missing primitive type values (including simple arrays) are set to zero values
 * - missing object type values are skipped entirely
 * - types are checked before performing the type-cast operation
 */
void from_json(const nlohmann::json& j, CommObjectRecognitionObjectsIDL::CommObjectRecognitionEnvironment& obj)
{
	// is_valid: Boolean
	if(j.contains("is_valid") && j["is_valid"].is_boolean()) {
		obj.is_valid = j["is_valid"].get<bool>();
	}
	// objects: CommObjectRecognitionObjectProperties[]
	if(j.contains("objects") && j["objects"].is_array()) {
		auto jobjects = j["objects"];
		obj.objects.resize(jobjects.size());
		for(size_t idx=0; idx < jobjects.size(); idx++) {
			// convert the json array values individually
			if(jobjects.at(idx).is_object()) {
				// from_json(jobjects.at(idx), obj.objects.at(idx));
				obj.objects[idx] = jobjects[idx].get<CommObjectRecognitionObjectsIDL::CommObjectRecognitionObjectProperties>();
			}
		}
	}
}

} // end namespace CommObjectRecognitionObjectsIDL
