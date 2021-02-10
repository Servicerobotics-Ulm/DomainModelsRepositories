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

#ifndef COMMOBJECTRECOGNITIONOBJECTPROPERTIES_JSON_TRANSFORMATION_H_
#define COMMOBJECTRECOGNITIONOBJECTPROPERTIES_JSON_TRANSFORMATION_H_

#include <nlohmann/json.hpp>

#include <CommObjectRecognitionObjects/CommObjectRecognitionObjectPropertiesData.hh>

namespace CommObjectRecognitionObjectsIDL {

	void to_json(const CommObjectRecognitionObjectsIDL::CommObjectRecognitionObjectProperties& obj, nlohmann::json& j);
	void from_json(const nlohmann::json& j, CommObjectRecognitionObjectsIDL::CommObjectRecognitionObjectProperties& obj);
	
} // end namespace CommObjectRecognitionObjectsIDL

#endif // COMMOBJECTRECOGNITIONOBJECTPROPERTIES_JSON_TRANSFORMATION_H_
