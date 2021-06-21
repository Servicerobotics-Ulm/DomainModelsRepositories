#include "CommVisualLocalizationFeatureMapOpcUa.hh"

#define SERONET_NO_DEPRECATED
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ComplexType.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ElementPrimitives.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/SelfDescriptionArray.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ElementArray.hpp>

#include "CommLocalizationObjectsOpcUa/CommVisualLocalizationFeatureOpcUa.hh"

namespace SeRoNet {
namespace CommunicationObjects {
namespace Description {
	
// serialization for CommLocalizationObjectsIDL::CommVisualLocalizationFeatureMap
template <>
IDescription::shp_t SelfDescription(CommLocalizationObjectsIDL::CommVisualLocalizationFeatureMap *obj, std::string name)
{
	auto ret = std::make_shared<SeRoNet::CommunicationObjects::Description::ComplexType>(name);
	// add features
	ret->add(
		SelfDescription(&(obj->features), "Features")
	);
	// add isValid
	ret->add(
		SelfDescription(&(obj->isValid), "IsValid")
	);
	return ret;
} // end SelfDescription

} // end namespace Description
} // end namespace CommunicationObjects
} // end namespace SeRoNet
