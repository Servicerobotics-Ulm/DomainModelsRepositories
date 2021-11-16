#include "CommInverseKinematicsRequestOpcUa.hh"

#define SERONET_NO_DEPRECATED
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ComplexType.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ElementPrimitives.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/SelfDescriptionArray.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ElementArray.hpp>

#include "CommBasicObjectsOpcUa/CommPose3dOpcUa.hh"

namespace SeRoNet {
namespace CommunicationObjects {
namespace Description {
	
// serialization for CommManipulatorObjectsIDL::CommInverseKinematicsRequest
template <>
IDescription::shp_t SelfDescription(CommManipulatorObjectsIDL::CommInverseKinematicsRequest *obj, std::string name)
{
	auto ret = std::make_shared<SeRoNet::CommunicationObjects::Description::ComplexType>(name);
	// add tcp_pose
	ret->add(
		SelfDescription(&(obj->tcp_pose), "Tcp_pose")
	);
	// add is_relative
	ret->add(
		SelfDescription(&(obj->is_relative), "Is_relative")
	);
	// add motion_constraints
	ret->add(
		SelfDescription(&(obj->motion_constraints), "Motion_constraints")
	);
	return ret;
} // end SelfDescription

} // end namespace Description
} // end namespace CommunicationObjects
} // end namespace SeRoNet
