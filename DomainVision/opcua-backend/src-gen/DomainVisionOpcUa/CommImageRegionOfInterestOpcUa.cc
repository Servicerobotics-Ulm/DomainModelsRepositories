#include "CommImageRegionOfInterestOpcUa.hh"

#define SERONET_NO_DEPRECATED
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ComplexType.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ElementPrimitives.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/SelfDescriptionArray.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ElementArray.hpp>


namespace SeRoNet {
namespace CommunicationObjects {
namespace Description {
	
// serialization for DomainVisionIDL::CommImageRegionOfInterest
template <>
IDescription::shp_t SelfDescription(DomainVisionIDL::CommImageRegionOfInterest *obj, std::string name)
{
	auto ret = std::make_shared<SeRoNet::CommunicationObjects::Description::ComplexType>(name);
	// add x_offset
	ret->add(
		SelfDescription(&(obj->x_offset), "X_offset")
	);
	// add y_offset
	ret->add(
		SelfDescription(&(obj->y_offset), "Y_offset")
	);
	// add height
	ret->add(
		SelfDescription(&(obj->height), "Height")
	);
	// add width
	ret->add(
		SelfDescription(&(obj->width), "Width")
	);
	// add do_rectify
	ret->add(
		SelfDescription(&(obj->do_rectify), "Do_rectify")
	);
	return ret;
} // end SelfDescription

} // end namespace Description
} // end namespace CommunicationObjects
} // end namespace SeRoNet
