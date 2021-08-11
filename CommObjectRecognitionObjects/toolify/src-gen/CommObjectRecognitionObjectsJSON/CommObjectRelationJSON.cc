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

#include "CommObjectRelationJSON.hh"

#include <CommObjectRecognitionObjects/enumRelationType.hh>

namespace CommObjectRecognitionObjectsIDL {

void to_json(const CommObjectRecognitionObjectsIDL::CommObjectRelation& obj, nlohmann::json& j)
{
	// type: RelationType
	j["type"] = CommObjectRecognitionObjects::RelationType(obj.type).to_string(false);
	// relatedObjectId: UInt32
	j["relatedObjectId"] = obj.relatedObjectId;
}

/**
 * this transformation handles missing values and checks for correct types:
 * - missing primitive type values (including simple arrays) are set to zero values
 * - missing object type values are skipped entirely
 * - types are checked before performing the type-cast operation
 */
void from_json(const nlohmann::json& j, CommObjectRecognitionObjectsIDL::CommObjectRelation& obj)
{
	// type: RelationType
	if(j.contains("type") && j["type"].is_string()) {
		obj.type = CommObjectRecognitionObjects::RelationType::from_string(j["type"].get<std::string>());
	}
	// relatedObjectId: UInt32
	if(j.contains("relatedObjectId") && j["relatedObjectId"].is_number_unsigned()) {
		obj.relatedObjectId = j["relatedObjectId"].get<unsigned int>();
	}
}

} // end namespace CommObjectRecognitionObjectsIDL
