#include "CommNavigationGraphEdgeOpcUa.hh"

#define SERONET_NO_DEPRECATED
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ComplexType.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ElementPrimitives.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/SelfDescriptionArray.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ElementArray.hpp>


namespace SeRoNet {
namespace CommunicationObjects {
namespace Description {
	
// serialization for CommNavigationObjectsIDL::CommNavigationGraphEdge
template <>
IDescription::shp_t SelfDescription(CommNavigationObjectsIDL::CommNavigationGraphEdge *obj, std::string name)
{
	auto ret = std::make_shared<SeRoNet::CommunicationObjects::Description::ComplexType>(name);
	// add u
	ret->add(
		SelfDescription(&(obj->u), "U")
	);
	// add v
	ret->add(
		SelfDescription(&(obj->v), "V")
	);
	// add path
	ret->add(
		SelfDescription(&(obj->path), "Path")
	);
	// add way
	ret->add(
		SelfDescription(&(obj->way), "Way")
	);
	// add gap
	ret->add(
		SelfDescription(&(obj->gap), "Gap")
	);
	// add type
	ret->add(
		SelfDescription(&(obj->type), "Type")
	);
	return ret;
} // end SelfDescription

} // end namespace Description
} // end namespace CommunicationObjects
} // end namespace SeRoNet
