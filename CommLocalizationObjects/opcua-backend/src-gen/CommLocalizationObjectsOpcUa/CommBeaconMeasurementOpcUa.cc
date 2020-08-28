#include "CommBeaconMeasurementOpcUa.hh"

#define SERONET_NO_DEPRECATED
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ComplexType.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ElementPrimitives.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/SelfDescriptionArray.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ElementArray.hpp>

#include "CommBasicObjectsOpcUa/CommTimeStampOpcUa.hh"

namespace SeRoNet {
namespace CommunicationObjects {
namespace Description {
	
// serialization for CommLocalizationObjectsIDL::CommBeaconMeasurement
template <>
IDescription::shp_t SelfDescription(CommLocalizationObjectsIDL::CommBeaconMeasurement *obj, std::string name)
{
	auto ret = std::make_shared<SeRoNet::CommunicationObjects::Description::ComplexType>(name);
	// add timeStamp
	ret->add(
		SelfDescription(&(obj->timeStamp), "TimeStamp")
	);
	// add uuid
	ret->add(
		SelfDescription(&(obj->uuid), "Uuid")
	);
	// add major
	ret->add(
		SelfDescription(&(obj->major), "Major")
	);
	// add minor
	ret->add(
		SelfDescription(&(obj->minor), "Minor")
	);
	// add rssi
	ret->add(
		SelfDescription(&(obj->rssi), "Rssi")
	);
	// add txPower
	ret->add(
		SelfDescription(&(obj->txPower), "TxPower")
	);
	// add distance
	ret->add(
		SelfDescription(&(obj->distance), "Distance")
	);
	// add distanceIsValid
	ret->add(
		SelfDescription(&(obj->distanceIsValid), "DistanceIsValid")
	);
	return ret;
} // end SelfDescription

} // end namespace Description
} // end namespace CommunicationObjects
} // end namespace SeRoNet
