#include "CommManipulationTrajectoryOpcUa.hh"

#define SERONET_NO_DEPRECATED
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ComplexType.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ElementPrimitives.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/SelfDescriptionArray.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ElementArray.hpp>

#include "CommManipulatorObjectsOpcUa/CommJointManipulationTargetOpcUa.hh"
#include "CommManipulatorObjectsOpcUa/CommCartesianManipulationTargetOpcUa.hh"

namespace SeRoNet {
namespace CommunicationObjects {
namespace Description {
	
// serialization for CommManipulatorObjectsIDL::CommManipulationTrajectory
template <>
IDescription::shp_t SelfDescription(CommManipulatorObjectsIDL::CommManipulationTrajectory *obj, std::string name)
{
	auto ret = std::make_shared<SeRoNet::CommunicationObjects::Description::ComplexType>(name);
	// add joint_angles
	ret->add(
		SelfDescription(&(obj->joint_angles), "Joint_angles")
	);
	// add tcp_poses
	ret->add(
		SelfDescription(&(obj->tcp_poses), "Tcp_poses")
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
