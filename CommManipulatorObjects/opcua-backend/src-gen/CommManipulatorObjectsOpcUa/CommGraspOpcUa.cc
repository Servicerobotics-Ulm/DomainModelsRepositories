#include "CommGraspOpcUa.hh"

#define SERONET_NO_DEPRECATED
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ComplexType.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ElementPrimitives.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/SelfDescriptionArray.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ElementArray.hpp>

#include "CommBasicObjectsOpcUa/CommPose3dOpcUa.hh"

namespace SeRoNet {
namespace CommunicationObjects {
namespace Description {
	
// serialization for CommManipulatorObjectsIDL::CommGrasp
template <>
IDescription::shp_t SelfDescription(CommManipulatorObjectsIDL::CommGrasp *obj, std::string name)
{
	auto ret = std::make_shared<SeRoNet::CommunicationObjects::Description::ComplexType>(name);
	// add id
	ret->add(
		SelfDescription(&(obj->id), "Id")
	);
	// add pose
	ret->add(
		SelfDescription(&(obj->pose), "Pose")
	);
	// add quality
	ret->add(
		SelfDescription(&(obj->quality), "Quality")
	);
	// add width
	ret->add(
		SelfDescription(&(obj->width), "Width")
	);
	return ret;
} // end SelfDescription

} // end namespace Description
} // end namespace CommunicationObjects
} // end namespace SeRoNet
