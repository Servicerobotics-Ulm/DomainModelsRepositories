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

#ifndef COMMREMOTECONTROLEVENT_JSON_TRANSFORMATION_H_
#define COMMREMOTECONTROLEVENT_JSON_TRANSFORMATION_H_

#include <nlohmann/json.hpp>

#include <DomainHMI/CommRemoteControlEventData.hh>

namespace DomainHMIIDL {

	void to_json(const DomainHMIIDL::CommRemoteControlEvent& obj, nlohmann::json& j);
	void from_json(const nlohmann::json& j, DomainHMIIDL::CommRemoteControlEvent& obj);
	
} // end namespace DomainHMIIDL

#endif // COMMREMOTECONTROLEVENT_JSON_TRANSFORMATION_H_
