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

#ifndef COMMROBOTINOPOWEROUTPUTVALUE_JSON_TRANSFORMATION_H_
#define COMMROBOTINOPOWEROUTPUTVALUE_JSON_TRANSFORMATION_H_

#include <nlohmann/json.hpp>

#include <CommRobotinoObjects/CommRobotinoPowerOutputValueData.hh>

namespace CommRobotinoObjectsIDL {

	void to_json(const CommRobotinoObjectsIDL::CommRobotinoPowerOutputValue& obj, nlohmann::json& j);
	void from_json(const nlohmann::json& j, CommRobotinoObjectsIDL::CommRobotinoPowerOutputValue& obj);
	
} // end namespace CommRobotinoObjectsIDL

#endif // COMMROBOTINOPOWEROUTPUTVALUE_JSON_TRANSFORMATION_H_
