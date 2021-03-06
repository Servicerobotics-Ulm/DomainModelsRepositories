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

#ifndef COMMDISPARITYIMAGE_JSON_TRANSFORMATION_H_
#define COMMDISPARITYIMAGE_JSON_TRANSFORMATION_H_

#include <nlohmann/json.hpp>

#include <DomainVision/CommDisparityImageData.hh>

namespace DomainVisionIDL {

	void to_json(const DomainVisionIDL::CommDisparityImage& obj, nlohmann::json& j);
	void from_json(const nlohmann::json& j, DomainVisionIDL::CommDisparityImage& obj);
	
} // end namespace DomainVisionIDL

#endif // COMMDISPARITYIMAGE_JSON_TRANSFORMATION_H_
