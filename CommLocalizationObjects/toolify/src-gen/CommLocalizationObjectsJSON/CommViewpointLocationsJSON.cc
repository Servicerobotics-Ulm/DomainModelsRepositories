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

#include "CommViewpointLocationsJSON.hh"

#include "CommLocalizationObjectsJSON/ViewpointLocationJSON.hh"

namespace CommLocalizationObjectsIDL {

void to_json(const CommLocalizationObjectsIDL::CommViewpointLocations& obj, nlohmann::json& j)
{
	// database: ViewpointLocation[]
	for(size_t idx=0; idx < obj.database.size(); idx++) {
		nlohmann::json array_element;
		to_json(obj.database.at(idx), array_element);
		j["database"].emplace_back(array_element);
	}
}

/**
 * this transformation handles missing values and checks for correct types:
 * - missing primitive type values (including simple arrays) are set to zero values
 * - missing object type values are skipped entirely
 * - types are checked before performing the type-cast operation
 */
void from_json(const nlohmann::json& j, CommLocalizationObjectsIDL::CommViewpointLocations& obj)
{
	// database: ViewpointLocation[]
	if(j.contains("database") && j["database"].is_array()) {
		auto jdatabase = j["database"];
		obj.database.resize(jdatabase.size());
		for(size_t idx=0; idx < jdatabase.size(); idx++) {
			// convert the json array values individually
			if(jdatabase.at(idx).is_object()) {
				// from_json(jdatabase.at(idx), obj.database.at(idx));
				obj.database[idx] = jdatabase[idx].get<CommLocalizationObjectsIDL::ViewpointLocation>();
			}
		}
	}
}

} // end namespace CommLocalizationObjectsIDL
