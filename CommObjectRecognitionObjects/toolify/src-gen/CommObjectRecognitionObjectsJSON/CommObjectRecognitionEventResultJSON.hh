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

#ifndef COMMOBJECTRECOGNITIONEVENTRESULT_JSON_TRANSFORMATION_H_
#define COMMOBJECTRECOGNITIONEVENTRESULT_JSON_TRANSFORMATION_H_

#include <nlohmann/json.hpp>

#include <CommObjectRecognitionObjects/CommObjectRecognitionEventResultData.hh>

namespace CommObjectRecognitionObjectsIDL {

	void to_json(const CommObjectRecognitionObjectsIDL::CommObjectRecognitionEventResult& obj, nlohmann::json& j);
	void from_json(const nlohmann::json& j, CommObjectRecognitionObjectsIDL::CommObjectRecognitionEventResult& obj);
	
} // end namespace CommObjectRecognitionObjectsIDL

#endif // COMMOBJECTRECOGNITIONEVENTRESULT_JSON_TRANSFORMATION_H_
