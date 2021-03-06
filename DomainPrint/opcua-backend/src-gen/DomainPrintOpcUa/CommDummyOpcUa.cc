#include "CommDummyOpcUa.hh"

#define SERONET_NO_DEPRECATED
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ComplexType.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ElementPrimitives.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/SelfDescriptionArray.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ElementArray.hpp>

#include "CommBasicObjectsOpcUa/CommVoidOpcUa.hh"

namespace SeRoNet {
namespace CommunicationObjects {
namespace Description {
	
// serialization for DomainPrintIDL::CommDummy
template <>
IDescription::shp_t SelfDescription(DomainPrintIDL::CommDummy *obj, std::string name)
{
	auto ret = std::make_shared<SeRoNet::CommunicationObjects::Description::ComplexType>(name);
	// add dummy
	ret->add(
		SelfDescription(&(obj->dummy), "Dummy")
	);
	return ret;
} // end SelfDescription

} // end namespace Description
} // end namespace CommunicationObjects
} // end namespace SeRoNet
