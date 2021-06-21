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

#include "CommPrinterStatusJSON.hh"


namespace DomainPrintIDL {

void to_json(const DomainPrintIDL::CommPrinterStatus& obj, nlohmann::json& j)
{
	// status: PrinterStatusEnum
	j["status"] = obj.status;
	// statusRIBWARN: Boolean
	j["statusRIBWARN"] = obj.statusRIBWARN;
	// statusLBLWARN: Boolean
	j["statusLBLWARN"] = obj.statusLBLWARN;
}

/**
 * this transformation handles missing values and checks for correct types:
 * - missing primitive type values (including simple arrays) are set to zero values
 * - missing object type values are skipped entirely
 * - types are checked before performing the type-cast operation
 */
void from_json(const nlohmann::json& j, DomainPrintIDL::CommPrinterStatus& obj)
{
	// status: PrinterStatusEnum
	if(j.contains("status") && j["status"].is_number_integer()) {
		obj.status = j["status"].get<int>();
	}
	// statusRIBWARN: Boolean
	if(j.contains("statusRIBWARN") && j["statusRIBWARN"].is_boolean()) {
		obj.statusRIBWARN = j["statusRIBWARN"].get<bool>();
	}
	// statusLBLWARN: Boolean
	if(j.contains("statusLBLWARN") && j["statusLBLWARN"].is_boolean()) {
		obj.statusLBLWARN = j["statusLBLWARN"].get<bool>();
	}
}

} // end namespace DomainPrintIDL
