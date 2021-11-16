#include "CommCartesianManipulationTargetOpcUa.hh"

#define SERONET_NO_DEPRECATED
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ComplexType.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ElementPrimitives.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/SelfDescriptionArray.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ElementArray.hpp>

#include "CommBasicObjectsOpcUa/CommPose3dOpcUa.hh"

namespace SeRoNet {
namespace CommunicationObjects {
namespace Description {
	
// serialization for CommManipulatorObjectsIDL::CommCartesianManipulationTarget
template <>
IDescription::shp_t SelfDescription(CommManipulatorObjectsIDL::CommCartesianManipulationTarget *obj, std::string name)
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
	// add motion_type
	ret->add(
		SelfDescription(&(obj->motion_type), "Motion_type")
	);
	// add reach_type
	ret->add(
		SelfDescription(&(obj->reach_type), "Reach_type")
	);
	// add velocity
	ret->add(
		SelfDescription(&(obj->velocity), "Velocity")
	);
	// add acceleration
	ret->add(
		SelfDescription(&(obj->acceleration), "Acceleration")
	);
	// add reach_time
	ret->add(
		SelfDescription(&(obj->reach_time), "Reach_time")
	);
	// add blending_radius
	ret->add(
		SelfDescription(&(obj->blending_radius), "Blending_radius")
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
