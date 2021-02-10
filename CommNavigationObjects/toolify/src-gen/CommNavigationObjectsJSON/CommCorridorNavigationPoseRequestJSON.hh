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

#ifndef COMMCORRIDORNAVIGATIONPOSEREQUEST_JSON_TRANSFORMATION_H_
#define COMMCORRIDORNAVIGATIONPOSEREQUEST_JSON_TRANSFORMATION_H_

#include <nlohmann/json.hpp>

#include <CommNavigationObjects/CommCorridorNavigationPoseRequestData.hh>

namespace CommNavigationObjectsIDL {

	void to_json(const CommNavigationObjectsIDL::CommCorridorNavigationPoseRequest& obj, nlohmann::json& j);
	void from_json(const nlohmann::json& j, CommNavigationObjectsIDL::CommCorridorNavigationPoseRequest& obj);
	
} // end namespace CommNavigationObjectsIDL

#endif // COMMCORRIDORNAVIGATIONPOSEREQUEST_JSON_TRANSFORMATION_H_
