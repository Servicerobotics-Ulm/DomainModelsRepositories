#include "CommPrintProcessDataOpcUa.hh"

#define SERONET_NO_DEPRECATED
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ComplexType.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ElementPrimitives.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/SelfDescriptionArray.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ElementArray.hpp>

#include "DomainPrintOpcUa/CommKeyValueOpcUa.hh"

namespace SeRoNet {
namespace CommunicationObjects {
namespace Description {
	
// serialization for DomainPrintIDL::CommPrintProcessData
template <>
IDescription::shp_t SelfDescription(DomainPrintIDL::CommPrintProcessData *obj, std::string name)
{
	auto ret = std::make_shared<SeRoNet::CommunicationObjects::Description::ComplexType>(name);
	// add data
	ret->add(
		SelfDescription(&(obj->data), "Data")
	);
	// add templateID
	ret->add(
		SelfDescription(&(obj->templateID), "TemplateID")
	);
	// add applicationMode
	ret->add(
		SelfDescription(&(obj->applicationMode), "ApplicationMode")
	);
	return ret;
} // end SelfDescription

} // end namespace Description
} // end namespace CommunicationObjects
} // end namespace SeRoNet
