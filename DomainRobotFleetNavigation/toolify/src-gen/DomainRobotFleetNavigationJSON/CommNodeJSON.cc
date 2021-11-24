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

#include "CommNodeJSON.hh"


namespace DomainRobotFleetNavigationIDL {

void to_json(const DomainRobotFleetNavigationIDL::CommNode& obj, nlohmann::json& j)
{
	// id: Int32
	j["id"] = obj.id;
	// x: Double
	j["x"] = obj.x;
	// y: Double
	j["y"] = obj.y;
	// reserved: Boolean
	j["reserved"] = obj.reserved;
}

/**
 * this transformation handles missing values and checks for correct types:
 * - missing primitive type values (including simple arrays) are set to zero values
 * - missing object type values are skipped entirely
 * - types are checked before performing the type-cast operation
 */
void from_json(const nlohmann::json& j, DomainRobotFleetNavigationIDL::CommNode& obj)
{
	// id: Int32
	if(j.contains("id") && j["id"].is_number_integer()) {
		obj.id = j["id"].get<int>();
	}
	// x: Double
	if(j.contains("x") && j["x"].is_number_float()) {
		obj.x = j["x"].get<double>();
	}
	// y: Double
	if(j.contains("y") && j["y"].is_number_float()) {
		obj.y = j["y"].get<double>();
	}
	// reserved: Boolean
	if(j.contains("reserved") && j["reserved"].is_boolean()) {
		obj.reserved = j["reserved"].get<bool>();
	}
}

} // end namespace DomainRobotFleetNavigationIDL