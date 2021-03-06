//--------------------------------------------------------------------------
// Code generated by the SmartSoft MDSD Toolchain
// The SmartSoft Toolchain has been developed by:
//  
// Service Robotics Research Center
// University of Applied Sciences Ulm
// Prittwitzstr. 10
// 89075 Ulm (Germany)
//
// Information about the SmartSoft MDSD Toolchain is available at:
// www.servicerobotik-ulm.de
//
// Please do not modify this file. It will be re-generated
// running the code generator.
//--------------------------------------------------------------------------

#include "CommRobotinoObjects/CommLicenseKey.hh"

#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/SelfDescription.hpp>
#pragma once

namespace SeRoNet {
namespace CommunicationObjects {
namespace Description {
	
// serialization for CommRobotinoObjectsIDL::CommLicenseKey
template <>
IDescription::shp_t SelfDescription(CommRobotinoObjectsIDL::CommLicenseKey *obj, std::string name);

// serialization for CommLicenseKey
template <>
inline IDescription::shp_t SelfDescription(CommRobotinoObjects::CommLicenseKey *obj, std::string name)
{
	return SelfDescription(&(obj->set()),name); 
} // end SelfDescription

} // end namespace Description
} // end namespace CommunicationObjects
} // end namespace SeRoNet
