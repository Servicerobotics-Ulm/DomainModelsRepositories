#include "CommStereoImageOpcUa.hh"

#define SERONET_NO_DEPRECATED
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ComplexType.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ElementPrimitives.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/SelfDescriptionArray.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ElementArray.hpp>

#include "DomainVisionOpcUa/CommVideoImageOpcUa.hh"
#include "DomainVisionOpcUa/CommVideoImageOpcUa.hh"
#include "DomainVisionOpcUa/CommDisparityImageOpcUa.hh"

namespace SeRoNet {
namespace CommunicationObjects {
namespace Description {
	
// serialization for DomainVisionIDL::CommStereoImage
template <>
IDescription::shp_t SelfDescription(DomainVisionIDL::CommStereoImage *obj, std::string name)
{
	auto ret = std::make_shared<SeRoNet::CommunicationObjects::Description::ComplexType>(name);
	// add left
	ret->add(
		SelfDescription(&(obj->left), "Left")
	);
	// add right
	ret->add(
		SelfDescription(&(obj->right), "Right")
	);
	// add hasDispertyMap
	ret->add(
		SelfDescription(&(obj->hasDispertyMap), "HasDispertyMap")
	);
	// add disparityMap
	ret->add(
		SelfDescription(&(obj->disparityMap), "DisparityMap")
	);
	return ret;
} // end SelfDescription

} // end namespace Description
} // end namespace CommunicationObjects
} // end namespace SeRoNet
