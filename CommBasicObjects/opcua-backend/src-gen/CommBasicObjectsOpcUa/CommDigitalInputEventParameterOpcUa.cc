#include "CommDigitalInputEventParameterOpcUa.hh"

#define SERONET_NO_DEPRECATED
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ComplexType.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ElementPrimitives.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/SelfDescriptionArray.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ElementArray.hpp>


namespace SeRoNet {
namespace CommunicationObjects {
namespace Description {
	
// serialization for CommBasicObjectsIDL::CommDigitalInputEventParameter
template <>
IDescription::shp_t SelfDescription(CommBasicObjectsIDL::CommDigitalInputEventParameter *obj, std::string name)
{
	auto ret = std::make_shared<SeRoNet::CommunicationObjects::Description::ComplexType>(name);
	// add digitalInputValuesNumber
	ret->add(
		SelfDescription(&(obj->digitalInputValuesNumber), "DigitalInputValuesNumber")
	);
	// add digitalInputValue
	ret->add(
		SelfDescription(&(obj->digitalInputValue), "DigitalInputValue")
	);
	return ret;
} // end SelfDescription

} // end namespace Description
} // end namespace CommunicationObjects
} // end namespace SeRoNet
