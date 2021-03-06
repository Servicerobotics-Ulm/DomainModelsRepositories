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

#ifndef COMMSPEECHINPUTEVENTPARAMETER_JSON_TRANSFORMATION_H_
#define COMMSPEECHINPUTEVENTPARAMETER_JSON_TRANSFORMATION_H_

#include <nlohmann/json.hpp>

#include <DomainSpeech/CommSpeechInputEventParameterData.hh>

namespace DomainSpeechIDL {

	void to_json(const DomainSpeechIDL::CommSpeechInputEventParameter& obj, nlohmann::json& j);
	void from_json(const nlohmann::json& j, DomainSpeechIDL::CommSpeechInputEventParameter& obj);
	
} // end namespace DomainSpeechIDL

#endif // COMMSPEECHINPUTEVENTPARAMETER_JSON_TRANSFORMATION_H_
