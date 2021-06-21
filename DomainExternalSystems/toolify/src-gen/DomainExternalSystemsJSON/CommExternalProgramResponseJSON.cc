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

#include "CommExternalProgramResponseJSON.hh"

#include "DomainExternalSystemsJSON/CommExternalProgramArgumentJSON.hh"

namespace DomainExternalSystemsIDL {

void to_json(const DomainExternalSystemsIDL::CommExternalProgramResponse& obj, nlohmann::json& j)
{
	// status: ExternalProgramStatus
	j["status"] = obj.status;
	// result: ExternalProgramResult
	j["result"] = obj.result;
	// resultArgs: CommExternalProgramArgument[]
	for(size_t idx=0; idx < obj.resultArgs.size(); idx++) {
		nlohmann::json array_element;
		to_json(obj.resultArgs.at(idx), array_element);
		j["resultArgs"].emplace_back(array_element);
	}
}

/**
 * this transformation handles missing values and checks for correct types:
 * - missing primitive type values (including simple arrays) are set to zero values
 * - missing object type values are skipped entirely
 * - types are checked before performing the type-cast operation
 */
void from_json(const nlohmann::json& j, DomainExternalSystemsIDL::CommExternalProgramResponse& obj)
{
	// status: ExternalProgramStatus
	if(j.contains("status") && j["status"].is_number_integer()) {
		obj.status = j["status"].get<int>();
	}
	// result: ExternalProgramResult
	if(j.contains("result") && j["result"].is_number_integer()) {
		obj.result = j["result"].get<int>();
	}
	// resultArgs: CommExternalProgramArgument[]
	if(j.contains("resultArgs") && j["resultArgs"].is_array()) {
		auto jresultArgs = j["resultArgs"];
		obj.resultArgs.resize(jresultArgs.size());
		for(size_t idx=0; idx < jresultArgs.size(); idx++) {
			// convert the json array values individually
			if(jresultArgs.at(idx).is_object()) {
				// from_json(jresultArgs.at(idx), obj.resultArgs.at(idx));
				obj.resultArgs[idx] = jresultArgs[idx].get<DomainExternalSystemsIDL::CommExternalProgramArgument>();
			}
		}
	}
}

} // end namespace DomainExternalSystemsIDL
