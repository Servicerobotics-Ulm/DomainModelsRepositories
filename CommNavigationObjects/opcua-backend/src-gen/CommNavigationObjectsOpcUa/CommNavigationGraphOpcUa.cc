#include "CommNavigationGraphOpcUa.hh"

#define SERONET_NO_DEPRECATED
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ComplexType.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ElementPrimitives.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/SelfDescriptionArray.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ElementArray.hpp>

#include "CommNavigationObjectsOpcUa/CommNavigationGraphVertexOpcUa.hh"
#include "CommNavigationObjectsOpcUa/CommNavigationGraphEdgeOpcUa.hh"

namespace SeRoNet {
namespace CommunicationObjects {
namespace Description {
	
// serialization for CommNavigationObjectsIDL::CommNavigationGraph
template <>
IDescription::shp_t SelfDescription(CommNavigationObjectsIDL::CommNavigationGraph *obj, std::string name)
{
	auto ret = std::make_shared<SeRoNet::CommunicationObjects::Description::ComplexType>(name);
	// add vertices
	ret->add(
		SelfDescription(&(obj->vertices), "Vertices")
	);
	// add edges
	ret->add(
		SelfDescription(&(obj->edges), "Edges")
	);
	// add pathWidth
	ret->add(
		SelfDescription(&(obj->pathWidth), "PathWidth")
	);
	// add valid
	ret->add(
		SelfDescription(&(obj->valid), "Valid")
	);
	return ret;
} // end SelfDescription

} // end namespace Description
} // end namespace CommunicationObjects
} // end namespace SeRoNet
