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

#ifndef COMMNAVPATH_JSON_TRANSFORMATION_H_
#define COMMNAVPATH_JSON_TRANSFORMATION_H_

#include <nlohmann/json.hpp>

#include <DomainRobotFleetNavigation/CommNavPathData.hh>

namespace DomainRobotFleetNavigationIDL {

	void to_json(const DomainRobotFleetNavigationIDL::CommNavPath& obj, nlohmann::json& j);
	void from_json(const nlohmann::json& j, DomainRobotFleetNavigationIDL::CommNavPath& obj);
	
} // end namespace DomainRobotFleetNavigationIDL

#endif // COMMNAVPATH_JSON_TRANSFORMATION_H_
