#include "CommKeyValueOpcUa.hh"

#define SERONET_NO_DEPRECATED
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ComplexType.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ElementPrimitives.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/SelfDescriptionArray.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ElementArray.hpp>


namespace SeRoNet {
namespace CommunicationObjects {
namespace Description {
	
// serialization for DomainPrintIDL::CommKeyValue
template <>
IDescription::shp_t SelfDescription(DomainPrintIDL::CommKeyValue *obj, std::string name)
{
	auto ret = std::make_shared<SeRoNet::CommunicationObjects::Description::ComplexType>(name);
	// add key
	ret->add(
		SelfDescription(&(obj->key), "Key")
	);
	// add value
	ret->add(
		SelfDescription(&(obj->value), "Value")
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
