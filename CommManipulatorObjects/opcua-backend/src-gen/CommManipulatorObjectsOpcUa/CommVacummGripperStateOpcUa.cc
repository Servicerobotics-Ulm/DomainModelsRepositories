#include "CommVacummGripperStateOpcUa.hh"

#define SERONET_NO_DEPRECATED
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ComplexType.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ElementPrimitives.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/SelfDescriptionArray.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ElementArray.hpp>


namespace SeRoNet {
namespace CommunicationObjects {
namespace Description {
	
// serialization for CommManipulatorObjectsIDL::CommVacummGripperState
template <>
IDescription::shp_t SelfDescription(CommManipulatorObjectsIDL::CommVacummGripperState *obj, std::string name)
{
	auto ret = std::make_shared<SeRoNet::CommunicationObjects::Description::ComplexType>(name);
	// add state
	ret->add(
		SelfDescription(&(obj->state), "State")
	);
	// add vacuumLevel
	ret->add(
		SelfDescription(&(obj->vacuumLevel), "VacuumLevel")
	);
	return ret;
} // end SelfDescription

} // end namespace Description
} // end namespace CommunicationObjects
} // end namespace SeRoNet
