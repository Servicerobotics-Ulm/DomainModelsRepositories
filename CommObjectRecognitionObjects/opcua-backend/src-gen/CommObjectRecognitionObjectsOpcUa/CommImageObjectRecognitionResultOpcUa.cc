#include "CommImageObjectRecognitionResultOpcUa.hh"

#define SERONET_NO_DEPRECATED
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ComplexType.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ElementPrimitives.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/SelfDescriptionArray.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ElementArray.hpp>

#include "CommObjectRecognitionObjectsOpcUa/CommObjectBeliefOpcUa.hh"

namespace SeRoNet {
namespace CommunicationObjects {
namespace Description {
	
// serialization for CommObjectRecognitionObjectsIDL::CommImageObjectRecognitionResult
template <>
IDescription::shp_t SelfDescription(CommObjectRecognitionObjectsIDL::CommImageObjectRecognitionResult *obj, std::string name)
{
	auto ret = std::make_shared<SeRoNet::CommunicationObjects::Description::ComplexType>(name);
	// add xmin
	ret->add(
		SelfDescription(&(obj->xmin), "Xmin")
	);
	// add ymin
	ret->add(
		SelfDescription(&(obj->ymin), "Ymin")
	);
	// add xmax
	ret->add(
		SelfDescription(&(obj->xmax), "Xmax")
	);
	// add ymax
	ret->add(
		SelfDescription(&(obj->ymax), "Ymax")
	);
	// add validBoundingBox
	ret->add(
		SelfDescription(&(obj->validBoundingBox), "ValidBoundingBox")
	);
	// add belief
	ret->add(
		SelfDescription(&(obj->belief), "Belief")
	);
	// add objectId
	ret->add(
		SelfDescription(&(obj->objectId), "ObjectId")
	);
	return ret;
} // end SelfDescription

} // end namespace Description
} // end namespace CommunicationObjects
} // end namespace SeRoNet
