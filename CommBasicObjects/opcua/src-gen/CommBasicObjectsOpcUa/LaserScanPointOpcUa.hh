//--------------------------------------------------------------------------
// Code generated by the SmartSoft MDSD Toolchain
// The SmartSoft Toolchain has been developed by:
//  
// Christian Schlegel (schlegel@hs-ulm.de)
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

#include "CommBasicObjects/LaserScanPoint.hh"
#include <SeRoNet/CommunicationObjects/Description/SelfDescription.hpp>
#include <SeRoNet/CommunicationObjects/Description/ElementPrimitives.hpp>
#pragma once


namespace SeRoNet {
namespace CommunicationObjects {
namespace Description {
// serialization for LaserScanPoint
template <>
ComplexType::shp_t SelfDescription(CommBasicObjects::LaserScanPoint *obj, std::string name)
{
	auto ret = std::make_shared<SeRoNet::CommunicationObjects::Description::ComplexType>(name);
	/// \todo check for ComplexObjects
	// add index
	ret->add(
		SeRoNet::CommunicationObjects::Description::IDescription::shp_t(
			new SeRoNet::CommunicationObjects::Description::ElementUInt16(
				"index",
				std::bind(&CommBasicObjects::LaserScanPoint::getIndex, obj),
				std::bind(&CommBasicObjects::LaserScanPoint::setIndex, obj, std::placeholders::_1)
			)
		)
	);
	// add distance
	ret->add(
		SeRoNet::CommunicationObjects::Description::IDescription::shp_t(
			new SeRoNet::CommunicationObjects::Description::ElementUInt16(
				"distance",
				std::bind(&CommBasicObjects::LaserScanPoint::getDistance, obj),
				std::bind(&CommBasicObjects::LaserScanPoint::setDistance, obj, std::placeholders::_1)
			)
		)
	);
	// add intensity
	ret->add(
		SeRoNet::CommunicationObjects::Description::IDescription::shp_t(
			new SeRoNet::CommunicationObjects::Description::ElementUInt8(
				"intensity",
				std::bind(&CommBasicObjects::LaserScanPoint::getIntensity, obj),
				std::bind(&CommBasicObjects::LaserScanPoint::setIntensity, obj, std::placeholders::_1)
			)
		)
	);
	return ret;
} // end SelfDescription
} // end namespace Description
} // end namespace CommunicationObjects
} // end namespace SeRoNet