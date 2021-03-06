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

#include "CommMobileIRScanJSON.hh"

#include "CommBasicObjectsJSON/CommBaseStateJSON.hh"
#include "CommBasicObjectsJSON/CommIRScanJSON.hh"

namespace CommBasicObjectsIDL {

void to_json(const CommBasicObjectsIDL::CommMobileIRScan& obj, nlohmann::json& j)
{
	// is_valid: Boolean
	j["is_valid"] = obj.is_valid;
	// baseState: CommBaseState
	to_json(obj.baseState, j["baseState"]);
	// irScan: CommIRScan
	to_json(obj.irScan, j["irScan"]);
}

/**
 * this transformation handles missing values and checks for correct types:
 * - missing primitive type values (including simple arrays) are set to zero values
 * - missing object type values are skipped entirely
 * - types are checked before performing the type-cast operation
 */
void from_json(const nlohmann::json& j, CommBasicObjectsIDL::CommMobileIRScan& obj)
{
	// is_valid: Boolean
	if(j.contains("is_valid") && j["is_valid"].is_boolean()) {
		obj.is_valid = j["is_valid"].get<bool>();
	}
	// baseState: CommBaseState
	if(j.contains("baseState") && j["baseState"].is_object()) {
		//from_json(j["baseState"], obj.baseState);
		obj.baseState = j["baseState"].get<CommBasicObjectsIDL::CommBaseState>();
	}
	// irScan: CommIRScan
	if(j.contains("irScan") && j["irScan"].is_object()) {
		//from_json(j["irScan"], obj.irScan);
		obj.irScan = j["irScan"].get<CommBasicObjectsIDL::CommIRScan>();
	}
}

} // end namespace CommBasicObjectsIDL
