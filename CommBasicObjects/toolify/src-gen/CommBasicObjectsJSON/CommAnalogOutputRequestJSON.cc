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

#include "CommAnalogOutputRequestJSON.hh"


namespace CommBasicObjectsIDL {

void to_json(const CommBasicObjectsIDL::CommAnalogOutputRequest& obj, nlohmann::json& j)
{
	// outputNumber: UInt32
	j["outputNumber"] = obj.outputNumber;
	// outputValue: Double
	j["outputValue"] = obj.outputValue;
}

/**
 * this transformation handles missing values and checks for correct types:
 * - missing primitive type values (including simple arrays) are set to zero values
 * - missing object type values are skipped entirely
 * - types are checked before performing the type-cast operation
 */
void from_json(const nlohmann::json& j, CommBasicObjectsIDL::CommAnalogOutputRequest& obj)
{
	// outputNumber: UInt32
	if(j.contains("outputNumber") && j["outputNumber"].is_number_unsigned()) {
		obj.outputNumber = j["outputNumber"].get<unsigned int>();
	}
	// outputValue: Double
	if(j.contains("outputValue") && j["outputValue"].is_number_float()) {
		obj.outputValue = j["outputValue"].get<double>();
	}
}

} // end namespace CommBasicObjectsIDL
