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

#include "ImageParametersJSON.hh"


namespace DomainVisionIDL {

void to_json(const DomainVisionIDL::ImageParameters& obj, nlohmann::json& j)
{
	// width: UInt32
	j["width"] = obj.width;
	// height: UInt32
	j["height"] = obj.height;
	// format: FormatType
	j["format"] = obj.format;
	// depth: UInt32
	j["depth"] = obj.depth;
	// size: UInt32
	j["size"] = obj.size;
}

/**
 * this transformation handles missing values and checks for correct types:
 * - missing primitive type values (including simple arrays) are set to zero values
 * - missing object type values are skipped entirely
 * - types are checked before performing the type-cast operation
 */
void from_json(const nlohmann::json& j, DomainVisionIDL::ImageParameters& obj)
{
	// width: UInt32
	if(j.contains("width") && j["width"].is_number_unsigned()) {
		obj.width = j["width"].get<unsigned int>();
	}
	// height: UInt32
	if(j.contains("height") && j["height"].is_number_unsigned()) {
		obj.height = j["height"].get<unsigned int>();
	}
	// format: FormatType
	if(j.contains("format") && j["format"].is_number_integer()) {
		obj.format = j["format"].get<int>();
	}
	// depth: UInt32
	if(j.contains("depth") && j["depth"].is_number_unsigned()) {
		obj.depth = j["depth"].get<unsigned int>();
	}
	// size: UInt32
	if(j.contains("size") && j["size"].is_number_unsigned()) {
		obj.size = j["size"].get<unsigned int>();
	}
}

} // end namespace DomainVisionIDL
