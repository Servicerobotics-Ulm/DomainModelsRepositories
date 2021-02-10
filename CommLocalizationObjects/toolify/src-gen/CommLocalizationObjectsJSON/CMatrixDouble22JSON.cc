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

#include "CMatrixDouble22JSON.hh"


namespace CommLocalizationObjectsIDL {

void to_json(const CommLocalizationObjectsIDL::CMatrixDouble22& obj, nlohmann::json& j)
{
	// m_00: Double
	j["m_00"] = obj.m_00;
	// m_01: Double
	j["m_01"] = obj.m_01;
	// m_10: Double
	j["m_10"] = obj.m_10;
	// m_11: Double
	j["m_11"] = obj.m_11;
}

/**
 * this transformation handles missing values and checks for correct types:
 * - missing primitive type values (including simple arrays) are set to zero values
 * - missing object type values are skipped entirely
 * - types are checked before performing the type-cast operation
 */
void from_json(const nlohmann::json& j, CommLocalizationObjectsIDL::CMatrixDouble22& obj)
{
	// m_00: Double
	if(j.contains("m_00") && j["m_00"].is_number_float()) {
		obj.m_00 = j["m_00"].get<double>();
	}
	// m_01: Double
	if(j.contains("m_01") && j["m_01"].is_number_float()) {
		obj.m_01 = j["m_01"].get<double>();
	}
	// m_10: Double
	if(j.contains("m_10") && j["m_10"].is_number_float()) {
		obj.m_10 = j["m_10"].get<double>();
	}
	// m_11: Double
	if(j.contains("m_11") && j["m_11"].is_number_float()) {
		obj.m_11 = j["m_11"].get<double>();
	}
}

} // end namespace CommLocalizationObjectsIDL
