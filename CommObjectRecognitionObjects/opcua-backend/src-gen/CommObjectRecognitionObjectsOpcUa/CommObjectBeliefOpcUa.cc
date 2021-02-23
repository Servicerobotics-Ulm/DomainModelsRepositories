#include "CommObjectBeliefOpcUa.hh"

#define SERONET_NO_DEPRECATED
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ComplexType.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ElementPrimitives.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/SelfDescriptionArray.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ElementArray.hpp>

#include "CommBasicObjectsOpcUa/CommPose3dOpcUa.hh"

namespace SeRoNet {
namespace CommunicationObjects {
namespace Description {
	
// serialization for CommObjectRecognitionObjectsIDL::CommObjectBelief
template <>
IDescription::shp_t SelfDescription(CommObjectRecognitionObjectsIDL::CommObjectBelief *obj, std::string name)
{
	auto ret = std::make_shared<SeRoNet::CommunicationObjects::Description::ComplexType>(name);
	// add type
	ret->add(
		SelfDescription(&(obj->type), "Type")
	);
	// add objClass
	ret->add(
		SelfDescription(&(obj->objClass), "ObjClass")
	);
	// add probability
	ret->add(
		SelfDescription(&(obj->probability), "Probability")
	);
	// add pose
	ret->add(
		SelfDescription(&(obj->pose), "Pose")
	);
	// add cov
	ret->add(
		SelfDescription(&(obj->cov), "Cov")
	);
	// add validPosePdf
	ret->add(
		SelfDescription(&(obj->validPosePdf), "ValidPosePdf")
	);
	// add validPose
	ret->add(
		SelfDescription(&(obj->validPose), "ValidPose")
	);
	return ret;
} // end SelfDescription

} // end namespace Description
} // end namespace CommunicationObjects
} // end namespace SeRoNet
