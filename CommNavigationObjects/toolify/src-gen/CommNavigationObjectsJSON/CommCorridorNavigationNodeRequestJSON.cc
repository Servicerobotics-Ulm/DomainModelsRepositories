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

#include "CommCorridorNavigationNodeRequestJSON.hh"

#include <CommNavigationObjects/enumNavigationNodeRequestType.hh>
#include "CommNavigationObjectsJSON/CommCorridorNodeJSON.hh"

namespace CommNavigationObjectsIDL {

void to_json(const CommNavigationObjectsIDL::CommCorridorNavigationNodeRequest& obj, nlohmann::json& j)
{
	// requestType: NavigationNodeRequestType
	j["requestType"] = CommNavigationObjects::NavigationNodeRequestType(obj.requestType).to_string(false);
	// nodesList: CommCorridorNode[]
	for(size_t idx=0; idx < obj.nodesList.size(); idx++) {
		nlohmann::json array_element;
		to_json(obj.nodesList.at(idx), array_element);
		j["nodesList"].emplace_back(array_element);
	}
	// robotID: String
	j["robotID"] = obj.robotID;
}

/**
 * this transformation handles missing values and checks for correct types:
 * - missing primitive type values (including simple arrays) are set to zero values
 * - missing object type values are skipped entirely
 * - types are checked before performing the type-cast operation
 */
void from_json(const nlohmann::json& j, CommNavigationObjectsIDL::CommCorridorNavigationNodeRequest& obj)
{
	// requestType: NavigationNodeRequestType
	if(j.contains("requestType") && j["requestType"].is_string()) {
		obj.requestType = CommNavigationObjects::NavigationNodeRequestType::from_string(j["requestType"].get<std::string>());
	}
	// nodesList: CommCorridorNode[]
	if(j.contains("nodesList") && j["nodesList"].is_array()) {
		auto jnodesList = j["nodesList"];
		obj.nodesList.resize(jnodesList.size());
		for(size_t idx=0; idx < jnodesList.size(); idx++) {
			// convert the json array values individually
			if(jnodesList.at(idx).is_object()) {
				// from_json(jnodesList.at(idx), obj.nodesList.at(idx));
				obj.nodesList[idx] = jnodesList[idx].get<CommNavigationObjectsIDL::CommCorridorNode>();
			}
		}
	}
	// robotID: String
	if(j.contains("robotID") && j["robotID"].is_string()) {
		obj.robotID = j["robotID"].get<std::string>();
	}
}

} // end namespace CommNavigationObjectsIDL
