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

#ifndef COMMVIEWPOINTLOCATIONS_JSON_TRANSFORMATION_H_
#define COMMVIEWPOINTLOCATIONS_JSON_TRANSFORMATION_H_

#include <nlohmann/json.hpp>

#include <CommLocalizationObjects/CommViewpointLocationsData.hh>

namespace CommLocalizationObjectsIDL {

	void to_json(const CommLocalizationObjectsIDL::CommViewpointLocations& obj, nlohmann::json& j);
	void from_json(const nlohmann::json& j, CommLocalizationObjectsIDL::CommViewpointLocations& obj);
	
} // end namespace CommLocalizationObjectsIDL

#endif // COMMVIEWPOINTLOCATIONS_JSON_TRANSFORMATION_H_
