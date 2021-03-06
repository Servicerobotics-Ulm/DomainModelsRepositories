//--------------------------------------------------------------------------
// Code generated by the SmartSoft MDSD Toolchain
// The SmartSoft Toolchain has been developed by:
//  
// Service Robotics Research Center
// University of Applied Sciences Ulm
// Prittwitzstr. 10
// 89075 Ulm (Germany)
//
// Information about the SmartSoft MDSD Toolchain is available at:
// www.servicerobotik-ulm.de
//
// Please do not modify this file. It will be re-generated
// running the code generator.
//--------------------------------------------------------------------------
#ifndef DOMAINEXTERNALSYSTEMS_COMMEXTERNALPROGRAM_DATA_H_
#define DOMAINEXTERNALSYSTEMS_COMMEXTERNALPROGRAM_DATA_H_

#include "DomainExternalSystems/CommExternalProgramArgumentData.hh"

#include <vector>
#include <string>

namespace DomainExternalSystemsIDL 
{
	typedef std::vector<DomainExternalSystemsIDL::CommExternalProgramArgument> CommExternalProgram_arguments_type;
	typedef std::vector<DomainExternalSystemsIDL::CommExternalProgramArgument> CommExternalProgram_resultArgs_type;
	struct CommExternalProgram
	{
		std::string name;
		std::string description;
		bool isExecutable;
		CommExternalProgram_arguments_type arguments;
		CommExternalProgram_resultArgs_type resultArgs;
  	};
};

#endif /* DOMAINEXTERNALSYSTEMS_COMMEXTERNALPROGRAM_DATA_H_ */
