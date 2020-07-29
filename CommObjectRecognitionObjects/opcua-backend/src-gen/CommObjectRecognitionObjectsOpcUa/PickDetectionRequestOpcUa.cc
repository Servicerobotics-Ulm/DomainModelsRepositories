#include "PickDetectionRequestOpcUa.hh"

#define SERONET_NO_DEPRECATED
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ComplexType.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ElementPrimitives.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/SelfDescriptionArray.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ElementArray.hpp>


namespace SeRoNet {
namespace CommunicationObjects {
namespace Description {
	
// serialization for CommObjectRecognitionObjectsIDL::PickDetectionRequest
template <>
IDescription::shp_t SelfDescription(CommObjectRecognitionObjectsIDL::PickDetectionRequest *obj, std::string name)
{
	auto ret = std::make_shared<SeRoNet::CommunicationObjects::Description::ComplexType>(name);
	// add workspaceID
	ret->add(
		SelfDescription(&(obj->workspaceID), "WorkspaceID")
	);
	// add pickmodelID
	ret->add(
		SelfDescription(&(obj->pickmodelID), "PickmodelID")
	);
	return ret;
} // end SelfDescription

} // end namespace Description
} // end namespace CommunicationObjects
} // end namespace SeRoNet
