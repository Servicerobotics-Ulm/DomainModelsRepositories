#include "CommJointManipulationTargetOpcUa.hh"

#define SERONET_NO_DEPRECATED
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ComplexType.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ElementPrimitives.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/SelfDescriptionArray.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ElementArray.hpp>


namespace SeRoNet {
namespace CommunicationObjects {
namespace Description {
	
// serialization for CommManipulatorObjectsIDL::CommJointManipulationTarget
template <>
IDescription::shp_t SelfDescription(CommManipulatorObjectsIDL::CommJointManipulationTarget *obj, std::string name)
{
	auto ret = std::make_shared<SeRoNet::CommunicationObjects::Description::ComplexType>(name);
	// add joint_angles
	ret->add(
		SelfDescription(&(obj->joint_angles), "Joint_angles")
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
	return ret;
} // end SelfDescription

} // end namespace Description
} // end namespace CommunicationObjects
} // end namespace SeRoNet
