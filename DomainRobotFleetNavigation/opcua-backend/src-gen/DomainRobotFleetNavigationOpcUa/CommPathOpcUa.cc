#include "CommPathOpcUa.hh"

#define SERONET_NO_DEPRECATED
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ComplexType.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ElementPrimitives.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/SelfDescriptionArray.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ElementArray.hpp>

#include "DomainRobotFleetNavigationOpcUa/CommNodeOpcUa.hh"

namespace SeRoNet {
namespace CommunicationObjects {
namespace Description {
	
// serialization for DomainRobotFleetNavigationIDL::CommPath
template <>
IDescription::shp_t SelfDescription(DomainRobotFleetNavigationIDL::CommPath *obj, std::string name)
{
	auto ret = std::make_shared<SeRoNet::CommunicationObjects::Description::ComplexType>(name);
	// add id
	ret->add(
		SelfDescription(&(obj->id), "Id")
	);
	// add direction
	ret->add(
		SelfDescription(&(obj->direction), "Direction")
	);
	// add width
	ret->add(
		SelfDescription(&(obj->width), "Width")
	);
	// add node
	ret->add(
		SelfDescription(&(obj->node), "Node")
	);
	return ret;
} // end SelfDescription

} // end namespace Description
} // end namespace CommunicationObjects
} // end namespace SeRoNet
