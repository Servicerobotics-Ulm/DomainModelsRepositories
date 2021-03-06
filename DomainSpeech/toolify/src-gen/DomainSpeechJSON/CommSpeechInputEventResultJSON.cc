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

#include "CommSpeechInputEventResultJSON.hh"


namespace DomainSpeechIDL {

void to_json(const DomainSpeechIDL::CommSpeechInputEventResult& obj, nlohmann::json& j)
{
	// text: String
	j["text"] = obj.text;
	// confidence: Double
	j["confidence"] = obj.confidence;
	// semantic: String
	j["semantic"] = obj.semantic;
}

/**
 * this transformation handles missing values and checks for correct types:
 * - missing primitive type values (including simple arrays) are set to zero values
 * - missing object type values are skipped entirely
 * - types are checked before performing the type-cast operation
 */
void from_json(const nlohmann::json& j, DomainSpeechIDL::CommSpeechInputEventResult& obj)
{
	// text: String
	if(j.contains("text") && j["text"].is_string()) {
		obj.text = j["text"].get<std::string>();
	}
	// confidence: Double
	if(j.contains("confidence") && j["confidence"].is_number_float()) {
		obj.confidence = j["confidence"].get<double>();
	}
	// semantic: String
	if(j.contains("semantic") && j["semantic"].is_string()) {
		obj.semantic = j["semantic"].get<std::string>();
	}
}

} // end namespace DomainSpeechIDL
