#include "CommNavigationGraphVertexOpcUa.hh"

#define SERONET_NO_DEPRECATED
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ComplexType.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ElementPrimitives.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/SelfDescriptionArray.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ElementArray.hpp>


namespace SeRoNet {
namespace CommunicationObjects {
namespace Description {
	
// serialization for CommNavigationObjectsIDL::CommNavigationGraphVertex
template <>
IDescription::shp_t SelfDescription(CommNavigationObjectsIDL::CommNavigationGraphVertex *obj, std::string name)
{
	auto ret = std::make_shared<SeRoNet::CommunicationObjects::Description::ComplexType>(name);
	// add x
	ret->add(
		SelfDescription(&(obj->x), "X")
	);
	// add y
	ret->add(
		SelfDescription(&(obj->y), "Y")
	);
	// add pose
	ret->add(
		SelfDescription(&(obj->pose), "Pose")
	);
	// add path
	ret->add(
		SelfDescription(&(obj->path), "Path")
	);
	// add width
	ret->add(
		SelfDescription(&(obj->width), "Width")
	);
	// add type
	ret->add(
		SelfDescription(&(obj->type), "Type")
	);
	// add intersec_path
	ret->add(
		SelfDescription(&(obj->intersec_path), "Intersec_path")
	);
	return ret;
} // end SelfDescription

} // end namespace Description
} // end namespace CommunicationObjects
} // end namespace SeRoNet
