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

#ifndef COMM3DPOINTCLOUD_JSON_TRANSFORMATION_H_
#define COMM3DPOINTCLOUD_JSON_TRANSFORMATION_H_

#include <nlohmann/json.hpp>

#include <DomainVision/Comm3dPointCloudData.hh>

namespace DomainVisionIDL {

	void to_json(const DomainVisionIDL::Comm3dPointCloud& obj, nlohmann::json& j);
	void from_json(const nlohmann::json& j, DomainVisionIDL::Comm3dPointCloud& obj);
	
} // end namespace DomainVisionIDL

#endif // COMM3DPOINTCLOUD_JSON_TRANSFORMATION_H_
