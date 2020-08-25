#include "CommImageObjectRecognitionResultsOpcUa.hh"

#define SERONET_NO_DEPRECATED
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ComplexType.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ElementPrimitives.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/SelfDescriptionArray.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ElementArray.hpp>

#include "CommObjectRecognitionObjectsOpcUa/CommImageObjectRecognitionResultOpcUa.hh"
#include "CommBasicObjectsOpcUa/CommTimeStampOpcUa.hh"

namespace SeRoNet {
namespace CommunicationObjects {
namespace Description {
	
// serialization for CommObjectRecognitionObjectsIDL::CommImageObjectRecognitionResults
template <>
IDescription::shp_t SelfDescription(CommObjectRecognitionObjectsIDL::CommImageObjectRecognitionResults *obj, std::string name)
{
	auto ret = std::make_shared<SeRoNet::CommunicationObjects::Description::ComplexType>(name);
	// add objects
	ret->add(
		SelfDescription(&(obj->objects), "Objects")
	);
	// add timestamp
	ret->add(
		SelfDescription(&(obj->timestamp), "Timestamp")
	);
	// add environmentId
	ret->add(
		SelfDescription(&(obj->environmentId), "EnvironmentId")
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
