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

#ifndef SIMPLEOBJECTEVENTSTATE_JSON_TRANSFORMATION_H_
#define SIMPLEOBJECTEVENTSTATE_JSON_TRANSFORMATION_H_

#include <nlohmann/json.hpp>

#include <CommObjectRecognitionObjects/SimpleObjectEventStateData.hh>

namespace CommObjectRecognitionObjectsIDL {

	void to_json(const CommObjectRecognitionObjectsIDL::SimpleObjectEventState& obj, nlohmann::json& j);
	void from_json(const nlohmann::json& j, CommObjectRecognitionObjectsIDL::SimpleObjectEventState& obj);
	
} // end namespace CommObjectRecognitionObjectsIDL

#endif // SIMPLEOBJECTEVENTSTATE_JSON_TRANSFORMATION_H_