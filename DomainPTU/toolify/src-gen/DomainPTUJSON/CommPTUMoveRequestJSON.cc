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

#include "CommPTUMoveRequestJSON.hh"

#include "CommBasicObjectsJSON/CommPosition3dJSON.hh"
#include <DomainPTU/enumPTUMoveFlag.hh>

namespace DomainPTUIDL {

void to_json(const DomainPTUIDL::CommPTUMoveRequest& obj, nlohmann::json& j)
{
	// pan: Double
	j["pan"] = obj.pan;
	// tilt: Double
	j["tilt"] = obj.tilt;
	// point: CommPosition3d
	to_json(obj.point, j["point"]);
	// flag: PTUMoveFlag
	j["flag"] = DomainPTU::PTUMoveFlag(obj.flag).to_string(false);
}

/**
 * this transformation handles missing values and checks for correct types:
 * - missing primitive type values (including simple arrays) are set to zero values
 * - missing object type values are skipped entirely
 * - types are checked before performing the type-cast operation
 */
void from_json(const nlohmann::json& j, DomainPTUIDL::CommPTUMoveRequest& obj)
{
	// pan: Double
	if(j.contains("pan") && j["pan"].is_number_float()) {
		obj.pan = j["pan"].get<double>();
	}
	// tilt: Double
	if(j.contains("tilt") && j["tilt"].is_number_float()) {
		obj.tilt = j["tilt"].get<double>();
	}
	// point: CommPosition3d
	if(j.contains("point") && j["point"].is_object()) {
		//from_json(j["point"], obj.point);
		obj.point = j["point"].get<CommBasicObjectsIDL::CommPosition3d>();
	}
	// flag: PTUMoveFlag
	if(j.contains("flag") && j["flag"].is_string()) {
		obj.flag = DomainPTU::PTUMoveFlag::from_string(j["flag"].get<std::string>());
	}
}

} // end namespace DomainPTUIDL