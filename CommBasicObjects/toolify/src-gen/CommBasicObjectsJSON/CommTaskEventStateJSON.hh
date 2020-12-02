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

#ifndef COMMTASKEVENTSTATE_JSON_TRANSFORMATION_H_
#define COMMTASKEVENTSTATE_JSON_TRANSFORMATION_H_

#include <nlohmann/json.hpp>

#include <CommBasicObjects/CommTaskEventStateData.hh>

namespace CommBasicObjectsIDL {

	void to_json(const CommBasicObjectsIDL::CommTaskEventState& obj, nlohmann::json& j);
	void from_json(const nlohmann::json& j, CommBasicObjectsIDL::CommTaskEventState& obj);
	
} // end namespace CommBasicObjectsIDL

#endif // COMMTASKEVENTSTATE_JSON_TRANSFORMATION_H_
