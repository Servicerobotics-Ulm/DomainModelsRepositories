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

#ifndef COMMEXTERNALPROGRAMSTARTRESPONSE_JSON_TRANSFORMATION_H_
#define COMMEXTERNALPROGRAMSTARTRESPONSE_JSON_TRANSFORMATION_H_

#include <nlohmann/json.hpp>

#include <DomainExternalSystems/CommExternalProgramStartResponseData.hh>

namespace DomainExternalSystemsIDL {

	void to_json(const DomainExternalSystemsIDL::CommExternalProgramStartResponse& obj, nlohmann::json& j);
	void from_json(const nlohmann::json& j, DomainExternalSystemsIDL::CommExternalProgramStartResponse& obj);
	
} // end namespace DomainExternalSystemsIDL

#endif // COMMEXTERNALPROGRAMSTARTRESPONSE_JSON_TRANSFORMATION_H_
