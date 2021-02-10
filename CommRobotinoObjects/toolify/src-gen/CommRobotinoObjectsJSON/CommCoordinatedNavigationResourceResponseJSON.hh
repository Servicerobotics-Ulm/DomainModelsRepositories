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

#ifndef COMMCOORDINATEDNAVIGATIONRESOURCERESPONSE_JSON_TRANSFORMATION_H_
#define COMMCOORDINATEDNAVIGATIONRESOURCERESPONSE_JSON_TRANSFORMATION_H_

#include <nlohmann/json.hpp>

#include <CommRobotinoObjects/CommCoordinatedNavigationResourceResponseData.hh>

namespace CommRobotinoObjectsIDL {

	void to_json(const CommRobotinoObjectsIDL::CommCoordinatedNavigationResourceResponse& obj, nlohmann::json& j);
	void from_json(const nlohmann::json& j, CommRobotinoObjectsIDL::CommCoordinatedNavigationResourceResponse& obj);
	
} // end namespace CommRobotinoObjectsIDL

#endif // COMMCOORDINATEDNAVIGATIONRESOURCERESPONSE_JSON_TRANSFORMATION_H_
