#include "CommAmclHypothesisOpcUa.hh"

#define SERONET_NO_DEPRECATED
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ComplexType.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ElementPrimitives.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/SelfDescriptionArray.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ElementArray.hpp>

#include "CommBasicObjectsOpcUa/CommPose3dOpcUa.hh"

namespace SeRoNet {
namespace CommunicationObjects {
namespace Description {
	
// serialization for CommLocalizationObjectsIDL::CommAmclHypothesis
template <>
IDescription::shp_t SelfDescription(CommLocalizationObjectsIDL::CommAmclHypothesis *obj, std::string name)
{
	auto ret = std::make_shared<SeRoNet::CommunicationObjects::Description::ComplexType>(name);
	// add pose
	ret->add(
		SelfDescription(&(obj->pose), "Pose")
	);
	// add weight
	ret->add(
		SelfDescription(&(obj->weight), "Weight")
	);
	// add covMatrix
	ret->add(
		SelfDescription(&(obj->covMatrix), "CovMatrix")
	);
	return ret;
} // end SelfDescription

} // end namespace Description
} // end namespace CommunicationObjects
} // end namespace SeRoNet
