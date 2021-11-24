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

#ifndef SPEECHINPUTEVENTSTATE_JSON_TRANSFORMATION_H_
#define SPEECHINPUTEVENTSTATE_JSON_TRANSFORMATION_H_

#include <nlohmann/json.hpp>

#include <DomainSpeech/SpeechInputEventStateData.hh>

namespace DomainSpeechIDL {

	void to_json(const DomainSpeechIDL::SpeechInputEventState& obj, nlohmann::json& j);
	void from_json(const nlohmann::json& j, DomainSpeechIDL::SpeechInputEventState& obj);
	
} // end namespace DomainSpeechIDL

#endif // SPEECHINPUTEVENTSTATE_JSON_TRANSFORMATION_H_