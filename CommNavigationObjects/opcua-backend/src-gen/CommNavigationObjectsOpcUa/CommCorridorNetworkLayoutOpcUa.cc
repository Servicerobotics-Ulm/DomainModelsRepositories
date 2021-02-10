#include "CommCorridorNetworkLayoutOpcUa.hh"

#define SERONET_NO_DEPRECATED
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ComplexType.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ElementPrimitives.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/SelfDescriptionArray.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ElementArray.hpp>

#include "CommNavigationObjectsOpcUa/CommCorridorNetworkStatusOpcUa.hh"
#include "CommBasicObjectsOpcUa/CommDataFileOpcUa.hh"

namespace SeRoNet {
namespace CommunicationObjects {
namespace Description {
	
// serialization for CommNavigationObjectsIDL::CommCorridorNetworkLayout
template <>
IDescription::shp_t SelfDescription(CommNavigationObjectsIDL::CommCorridorNetworkLayout *obj, std::string name)
{
	auto ret = std::make_shared<SeRoNet::CommunicationObjects::Description::ComplexType>(name);
	// add networkStatus
	ret->add(
		SelfDescription(&(obj->networkStatus), "NetworkStatus")
	);
	// add layoutFile
	ret->add(
		SelfDescription(&(obj->layoutFile), "LayoutFile")
	);
	return ret;
} // end SelfDescription

} // end namespace Description
} // end namespace CommunicationObjects
} // end namespace SeRoNet
