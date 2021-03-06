//-----------------------------------------------------------------------------------
// Code generated by the Toolify Robotics GmbH extension for the SmartMDSD Toolchain 
// 
// Toolify Robotics GmbH
// Weinbergweg 216
// 89075 Ulm 
//
// Information about the SmartSoft MDSD Toolchain is available at:
// www.servicerobotik-ulm.de
//
// Please do not modify this file. It will be re-generated
// running the code generator.
//-----------------------------------------------------------------------------------

#include "CommLaserTrackedObjectJSON.hh"


namespace CommTrackingObjectsIDL {

void to_json(const CommTrackingObjectsIDL::CommLaserTrackedObject& obj, nlohmann::json& j)
{
	// id: UInt32
	j["id"] = obj.id;
	// first_point: UInt16
	j["first_point"] = obj.first_point;
	// last_point: UInt16
	j["last_point"] = obj.last_point;
}

/**
 * this transformation handles missing values and checks for correct types:
 * - missing primitive type values (including simple arrays) are set to zero values
 * - missing object type values are skipped entirely
 * - types are checked before performing the type-cast operation
 */
void from_json(const nlohmann::json& j, CommTrackingObjectsIDL::CommLaserTrackedObject& obj)
{
	// id: UInt32
	if(j.contains("id") && j["id"].is_number_unsigned()) {
		obj.id = j["id"].get<unsigned int>();
	}
	// first_point: UInt16
	if(j.contains("first_point") && j["first_point"].is_number_unsigned()) {
		obj.first_point = j["first_point"].get<unsigned short>();
	}
	// last_point: UInt16
	if(j.contains("last_point") && j["last_point"].is_number_unsigned()) {
		obj.last_point = j["last_point"].get<unsigned short>();
	}
}

} // end namespace CommTrackingObjectsIDL
