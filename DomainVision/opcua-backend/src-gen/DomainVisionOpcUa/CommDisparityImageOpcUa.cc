#include "CommDisparityImageOpcUa.hh"

#define SERONET_NO_DEPRECATED
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ComplexType.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ElementPrimitives.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/SelfDescriptionArray.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ElementArray.hpp>

#include "DomainVisionOpcUa/CommVideoImageOpcUa.hh"
#include "DomainVisionOpcUa/CommImageRegionOfInterestOpcUa.hh"

namespace SeRoNet {
namespace CommunicationObjects {
namespace Description {
	
// serialization for DomainVisionIDL::CommDisparityImage
template <>
IDescription::shp_t SelfDescription(DomainVisionIDL::CommDisparityImage *obj, std::string name)
{
	auto ret = std::make_shared<SeRoNet::CommunicationObjects::Description::ComplexType>(name);
	// add image
	ret->add(
		SelfDescription(&(obj->image), "Image")
	);
	// add f
	ret->add(
		SelfDescription(&(obj->f), "F")
	);
	// add t
	ret->add(
		SelfDescription(&(obj->t), "T")
	);
	// add valid_window
	ret->add(
		SelfDescription(&(obj->valid_window), "Valid_window")
	);
	// add min_disparity
	ret->add(
		SelfDescription(&(obj->min_disparity), "Min_disparity")
	);
	// add max_disparity
	ret->add(
		SelfDescription(&(obj->max_disparity), "Max_disparity")
	);
	// add delta_d
	ret->add(
		SelfDescription(&(obj->delta_d), "Delta_d")
	);
	return ret;
} // end SelfDescription

} // end namespace Description
} // end namespace CommunicationObjects
} // end namespace SeRoNet
