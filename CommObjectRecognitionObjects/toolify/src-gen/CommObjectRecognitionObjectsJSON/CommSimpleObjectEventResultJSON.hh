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

#ifndef COMMSIMPLEOBJECTEVENTRESULT_JSON_TRANSFORMATION_H_
#define COMMSIMPLEOBJECTEVENTRESULT_JSON_TRANSFORMATION_H_

#include <nlohmann/json.hpp>

#include <CommObjectRecognitionObjects/CommSimpleObjectEventResultData.hh>

namespace CommObjectRecognitionObjectsIDL {

	void to_json(const CommObjectRecognitionObjectsIDL::CommSimpleObjectEventResult& obj, nlohmann::json& j);
	void from_json(const nlohmann::json& j, CommObjectRecognitionObjectsIDL::CommSimpleObjectEventResult& obj);
	
} // end namespace CommObjectRecognitionObjectsIDL

#endif // COMMSIMPLEOBJECTEVENTRESULT_JSON_TRANSFORMATION_H_
