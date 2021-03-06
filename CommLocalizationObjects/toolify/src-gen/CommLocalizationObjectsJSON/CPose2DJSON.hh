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

#ifndef CPOSE2D_JSON_TRANSFORMATION_H_
#define CPOSE2D_JSON_TRANSFORMATION_H_

#include <nlohmann/json.hpp>

#include <CommLocalizationObjects/CPose2DData.hh>

namespace CommLocalizationObjectsIDL {

	void to_json(const CommLocalizationObjectsIDL::CPose2D& obj, nlohmann::json& j);
	void from_json(const nlohmann::json& j, CommLocalizationObjectsIDL::CPose2D& obj);
	
} // end namespace CommLocalizationObjectsIDL

#endif // CPOSE2D_JSON_TRANSFORMATION_H_
