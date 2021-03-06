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

#include "CommBeaconLocalizationRawDataJSON.hh"

#include "CommLocalizationObjectsJSON/CommBeaconMeasurementJSON.hh"

namespace CommLocalizationObjectsIDL {

void to_json(const CommLocalizationObjectsIDL::CommBeaconLocalizationRawData& obj, nlohmann::json& j)
{
	// measurements: CommBeaconMeasurement[]
	for(size_t idx=0; idx < obj.measurements.size(); idx++) {
		nlohmann::json array_element;
		to_json(obj.measurements.at(idx), array_element);
		j["measurements"].emplace_back(array_element);
	}
}

/**
 * this transformation handles missing values and checks for correct types:
 * - missing primitive type values (including simple arrays) are set to zero values
 * - missing object type values are skipped entirely
 * - types are checked before performing the type-cast operation
 */
void from_json(const nlohmann::json& j, CommLocalizationObjectsIDL::CommBeaconLocalizationRawData& obj)
{
	// measurements: CommBeaconMeasurement[]
	if(j.contains("measurements") && j["measurements"].is_array()) {
		auto jmeasurements = j["measurements"];
		obj.measurements.resize(jmeasurements.size());
		for(size_t idx=0; idx < jmeasurements.size(); idx++) {
			// convert the json array values individually
			if(jmeasurements.at(idx).is_object()) {
				// from_json(jmeasurements.at(idx), obj.measurements.at(idx));
				obj.measurements[idx] = jmeasurements[idx].get<CommLocalizationObjectsIDL::CommBeaconMeasurement>();
			}
		}
	}
}

} // end namespace CommLocalizationObjectsIDL
