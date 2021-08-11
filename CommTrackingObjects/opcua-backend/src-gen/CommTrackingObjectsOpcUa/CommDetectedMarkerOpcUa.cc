#include "CommDetectedMarkerOpcUa.hh"

#define SERONET_NO_DEPRECATED
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ComplexType.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ElementPrimitives.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/SelfDescriptionArray.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ElementArray.hpp>

#include "CommBasicObjectsOpcUa/CommPose3dOpcUa.hh"
#include "CommBasicObjectsOpcUa/CommPose3dOpcUa.hh"
#include "CommBasicObjectsOpcUa/CommBaseStateOpcUa.hh"

namespace SeRoNet {
namespace CommunicationObjects {
namespace Description {
	
// serialization for CommTrackingObjectsIDL::CommDetectedMarker
template <>
IDescription::shp_t SelfDescription(CommTrackingObjectsIDL::CommDetectedMarker *obj, std::string name)
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
	// add sensor_pose
	ret->add(
		SelfDescription(&(obj->sensor_pose), "Sensor_pose")
	);
	// add base_state
	ret->add(
		SelfDescription(&(obj->base_state), "Base_state")
	);
	return ret;
} // end SelfDescription

} // end namespace Description
} // end namespace CommunicationObjects
} // end namespace SeRoNet
