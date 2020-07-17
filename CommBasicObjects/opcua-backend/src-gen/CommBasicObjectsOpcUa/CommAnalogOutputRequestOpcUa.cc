#include "CommAnalogOutputRequestOpcUa.hh"

#define SERONET_NO_DEPRECATED
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ComplexType.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ElementPrimitives.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/SelfDescriptionArray.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ElementArray.hpp>


namespace SeRoNet {
namespace CommunicationObjects {
namespace Description {
	
// serialization for CommBasicObjectsIDL::CommAnalogOutputRequest
template <>
IDescription::shp_t SelfDescription(CommBasicObjectsIDL::CommAnalogOutputRequest *obj, std::string name)
{
	auto ret = std::make_shared<SeRoNet::CommunicationObjects::Description::ComplexType>(name);
	// add outputNumber
	ret->add(
		SelfDescription(&(obj->outputNumber), "OutputNumber")
	);
	// add outputValue
	ret->add(
		SelfDescription(&(obj->outputValue), "OutputValue")
	);
	return ret;
} // end SelfDescription

} // end namespace Description
} // end namespace CommunicationObjects
} // end namespace SeRoNet
