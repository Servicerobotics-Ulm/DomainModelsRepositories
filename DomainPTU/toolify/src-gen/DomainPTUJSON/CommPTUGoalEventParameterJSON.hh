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

#ifndef COMMPTUGOALEVENTPARAMETER_JSON_TRANSFORMATION_H_
#define COMMPTUGOALEVENTPARAMETER_JSON_TRANSFORMATION_H_

#include <nlohmann/json.hpp>

#include <DomainPTU/CommPTUGoalEventParameterData.hh>

namespace DomainPTUIDL {

	void to_json(const DomainPTUIDL::CommPTUGoalEventParameter& obj, nlohmann::json& j);
	void from_json(const nlohmann::json& j, DomainPTUIDL::CommPTUGoalEventParameter& obj);
	
} // end namespace DomainPTUIDL

#endif // COMMPTUGOALEVENTPARAMETER_JSON_TRANSFORMATION_H_
