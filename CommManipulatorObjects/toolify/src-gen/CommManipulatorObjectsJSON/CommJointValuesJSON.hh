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

#ifndef COMMJOINTVALUES_JSON_TRANSFORMATION_H_
#define COMMJOINTVALUES_JSON_TRANSFORMATION_H_

#include <nlohmann/json.hpp>

#include <CommManipulatorObjects/CommJointValuesData.hh>

namespace CommManipulatorObjectsIDL {

	void to_json(const CommManipulatorObjectsIDL::CommJointValues& obj, nlohmann::json& j);
	void from_json(const nlohmann::json& j, CommManipulatorObjectsIDL::CommJointValues& obj);
	
} // end namespace CommManipulatorObjectsIDL

#endif // COMMJOINTVALUES_JSON_TRANSFORMATION_H_
