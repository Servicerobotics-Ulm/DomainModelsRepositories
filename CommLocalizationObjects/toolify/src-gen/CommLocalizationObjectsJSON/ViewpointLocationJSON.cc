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

#include "ViewpointLocationJSON.hh"

#include "CommLocalizationObjectsJSON/CPose2DJSON.hh"
#include "CommLocalizationObjectsJSON/CMatrixDouble22JSON.hh"
#include "CommLocalizationObjectsJSON/CMatrixDouble22JSON.hh"

namespace CommLocalizationObjectsIDL {

void to_json(const CommLocalizationObjectsIDL::ViewpointLocation& obj, nlohmann::json& j)
{
	// id: Int32
	j["id"] = obj.id;
	// mean: CPose2D
	to_json(obj.mean, j["mean"]);
	// cov: CMatrixDouble22
	to_json(obj.cov, j["cov"]);
	// invCov: CMatrixDouble22
	to_json(obj.invCov, j["invCov"]);
	// observationCount: Int32
	j["observationCount"] = obj.observationCount;
	// possibleObservations: Int32
	j["possibleObservations"] = obj.possibleObservations;
}

/**
 * this transformation handles missing values and checks for correct types:
 * - missing primitive type values (including simple arrays) are set to zero values
 * - missing object type values are skipped entirely
 * - types are checked before performing the type-cast operation
 */
void from_json(const nlohmann::json& j, CommLocalizationObjectsIDL::ViewpointLocation& obj)
{
	// id: Int32
	if(j.contains("id") && j["id"].is_number_integer()) {
		obj.id = j["id"].get<int>();
	}
	// mean: CPose2D
	if(j.contains("mean") && j["mean"].is_object()) {
		//from_json(j["mean"], obj.mean);
		obj.mean = j["mean"].get<CommLocalizationObjectsIDL::CPose2D>();
	}
	// cov: CMatrixDouble22
	if(j.contains("cov") && j["cov"].is_object()) {
		//from_json(j["cov"], obj.cov);
		obj.cov = j["cov"].get<CommLocalizationObjectsIDL::CMatrixDouble22>();
	}
	// invCov: CMatrixDouble22
	if(j.contains("invCov") && j["invCov"].is_object()) {
		//from_json(j["invCov"], obj.invCov);
		obj.invCov = j["invCov"].get<CommLocalizationObjectsIDL::CMatrixDouble22>();
	}
	// observationCount: Int32
	if(j.contains("observationCount") && j["observationCount"].is_number_integer()) {
		obj.observationCount = j["observationCount"].get<int>();
	}
	// possibleObservations: Int32
	if(j.contains("possibleObservations") && j["possibleObservations"].is_number_integer()) {
		obj.possibleObservations = j["possibleObservations"].get<int>();
	}
}

} // end namespace CommLocalizationObjectsIDL
