#include "CommManipulatorStateOpcUa.hh"

#define SERONET_NO_DEPRECATED
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ComplexType.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ElementPrimitives.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/SelfDescriptionArray.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ElementArray.hpp>

#include "CommBasicObjectsOpcUa/CommPose3dOpcUa.hh"
#include "CommBasicObjectsOpcUa/CommPose3dOpcUa.hh"

namespace SeRoNet {
namespace CommunicationObjects {
namespace Description {
	
// serialization for CommManipulatorObjectsIDL::CommManipulatorState
template <>
IDescription::shp_t SelfDescription(CommManipulatorObjectsIDL::CommManipulatorState *obj, std::string name)
{
	auto ret = std::make_shared<SeRoNet::CommunicationObjects::Description::ComplexType>(name);
	// add id
	ret->add(
		SelfDescription(&(obj->id), "Id")
	);
	// add joint_angles
	ret->add(
		SelfDescription(&(obj->joint_angles), "Joint_angles")
	);
	// add pose_tcp
	ret->add(
		SelfDescription(&(obj->pose_tcp), "Pose_tcp")
	);
	// add motion_constraints
	ret->add(
		SelfDescription(&(obj->motion_constraints), "Motion_constraints")
	);
	// add pose_manipulator
	ret->add(
		SelfDescription(&(obj->pose_manipulator), "Pose_manipulator")
	);
	// add is_valid
	ret->add(
		SelfDescription(&(obj->is_valid), "Is_valid")
	);
	return ret;
} // end SelfDescription

} // end namespace Description
} // end namespace CommunicationObjects
} // end namespace SeRoNet
