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

#ifndef COMMMANIPULATIONPLANNEREVENTPARAMETER_JSON_TRANSFORMATION_H_
#define COMMMANIPULATIONPLANNEREVENTPARAMETER_JSON_TRANSFORMATION_H_

#include <nlohmann/json.hpp>

#include <CommManipulationPlannerObjects/CommManipulationPlannerEventParameterData.hh>

namespace CommManipulationPlannerObjectsIDL {

	void to_json(const CommManipulationPlannerObjectsIDL::CommManipulationPlannerEventParameter& obj, nlohmann::json& j);
	void from_json(const nlohmann::json& j, CommManipulationPlannerObjectsIDL::CommManipulationPlannerEventParameter& obj);
	
} // end namespace CommManipulationPlannerObjectsIDL

#endif // COMMMANIPULATIONPLANNEREVENTPARAMETER_JSON_TRANSFORMATION_H_
