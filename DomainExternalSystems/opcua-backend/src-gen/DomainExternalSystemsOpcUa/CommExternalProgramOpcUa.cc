#include "CommExternalProgramOpcUa.hh"

#define SERONET_NO_DEPRECATED
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ComplexType.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ElementPrimitives.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/SelfDescriptionArray.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ElementArray.hpp>

#include "DomainExternalSystemsOpcUa/CommExternalProgramArgumentOpcUa.hh"
#include "DomainExternalSystemsOpcUa/CommExternalProgramArgumentOpcUa.hh"

namespace SeRoNet {
namespace CommunicationObjects {
namespace Description {
	
// serialization for DomainExternalSystemsIDL::CommExternalProgram
template <>
IDescription::shp_t SelfDescription(DomainExternalSystemsIDL::CommExternalProgram *obj, std::string name)
{
	auto ret = std::make_shared<SeRoNet::CommunicationObjects::Description::ComplexType>(name);
	// add name
	ret->add(
		SelfDescription(&(obj->name), "Name")
	);
	// add description
	ret->add(
		SelfDescription(&(obj->description), "Description")
	);
	// add isExecutable
	ret->add(
		SelfDescription(&(obj->isExecutable), "IsExecutable")
	);
	// add arguments
	ret->add(
		SelfDescription(&(obj->arguments), "Arguments")
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
