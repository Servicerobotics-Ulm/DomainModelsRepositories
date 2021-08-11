#include "CommDetectedMarkerListOpcUa.hh"

#define SERONET_NO_DEPRECATED
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ComplexType.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ElementPrimitives.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/SelfDescriptionArray.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ElementArray.hpp>

#include "CommTrackingObjectsOpcUa/CommDetectedMarkerOpcUa.hh"
#include "CommBasicObjectsOpcUa/CommPose3dOpcUa.hh"
#include "CommBasicObjectsOpcUa/CommBaseStateOpcUa.hh"

namespace SeRoNet {
namespace CommunicationObjects {
namespace Description {
	
// serialization for CommTrackingObjectsIDL::CommDetectedMarkerList
template <>
IDescription::shp_t SelfDescription(CommTrackingObjectsIDL::CommDetectedMarkerList *obj, std::string name)
{
	auto ret = std::make_shared<SeRoNet::CommunicationObjects::Description::ComplexType>(name);
	// add markers
	ret->add(
		SelfDescription(&(obj->markers), "Markers")
	);
	// add sensor_pose
	ret->add(
		SelfDescription(&(obj->sensor_pose), "Sensor_pose")
	);
	// add base_state
	ret->add(
		SelfDescription(&(obj->base_state), "Base_state")
	);
	// add single_pose
	ret->add(
		SelfDescription(&(obj->single_pose), "Single_pose")
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
