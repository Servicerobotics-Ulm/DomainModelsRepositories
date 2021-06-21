#include "CommExternalProgramArgumentOpcUa.hh"

#define SERONET_NO_DEPRECATED
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ComplexType.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ElementPrimitives.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/SelfDescriptionArray.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ElementArray.hpp>


namespace SeRoNet {
namespace CommunicationObjects {
namespace Description {
	
// serialization for DomainExternalSystemsIDL::CommExternalProgramArgument
template <>
IDescription::shp_t SelfDescription(DomainExternalSystemsIDL::CommExternalProgramArgument *obj, std::string name)
{
	auto ret = std::make_shared<SeRoNet::CommunicationObjects::Description::ComplexType>(name);
	// add name
	ret->add(
		SelfDescription(&(obj->name), "Name")
	);
	// add type
	ret->add(
		SelfDescription(&(obj->type), "Type")
	);
	// add value
	ret->add(
		SelfDescription(&(obj->value), "Value")
	);
	return ret;
} // end SelfDescription

} // end namespace Description
} // end namespace CommunicationObjects
} // end namespace SeRoNet
