#include "CommExternalProgramResponseOpcUa.hh"

#define SERONET_NO_DEPRECATED
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ComplexType.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ElementPrimitives.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/SelfDescriptionArray.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ElementArray.hpp>

#include "DomainExternalSystemsOpcUa/CommExternalProgramArgumentOpcUa.hh"

namespace SeRoNet {
namespace CommunicationObjects {
namespace Description {
	
// serialization for DomainExternalSystemsIDL::CommExternalProgramResponse
template <>
IDescription::shp_t SelfDescription(DomainExternalSystemsIDL::CommExternalProgramResponse *obj, std::string name)
{
	auto ret = std::make_shared<SeRoNet::CommunicationObjects::Description::ComplexType>(name);
	// add status
	ret->add(
		SelfDescription(&(obj->status), "Status")
	);
	// add result
	ret->add(
		SelfDescription(&(obj->result), "Result")
	);
	// add resultArgs
	ret->add(
		SelfDescription(&(obj->resultArgs), "ResultArgs")
	);
	return ret;
} // end SelfDescription

} // end namespace Description
} // end namespace CommunicationObjects
} // end namespace SeRoNet
