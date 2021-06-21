#include "CommPrinterStatusOpcUa.hh"

#define SERONET_NO_DEPRECATED
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ComplexType.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ElementPrimitives.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/SelfDescriptionArray.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ElementArray.hpp>


namespace SeRoNet {
namespace CommunicationObjects {
namespace Description {
	
// serialization for DomainPrintIDL::CommPrinterStatus
template <>
IDescription::shp_t SelfDescription(DomainPrintIDL::CommPrinterStatus *obj, std::string name)
{
	auto ret = std::make_shared<SeRoNet::CommunicationObjects::Description::ComplexType>(name);
	// add status
	ret->add(
		SelfDescription(&(obj->status), "Status")
	);
	// add statusRIBWARN
	ret->add(
		SelfDescription(&(obj->statusRIBWARN), "StatusRIBWARN")
	);
	// add statusLBLWARN
	ret->add(
		SelfDescription(&(obj->statusLBLWARN), "StatusLBLWARN")
	);
	return ret;
} // end SelfDescription

} // end namespace Description
} // end namespace CommunicationObjects
} // end namespace SeRoNet
