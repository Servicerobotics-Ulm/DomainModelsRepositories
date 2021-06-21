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
#ifndef DOMAINPRINT_COMMPRINTRESPONSE_DATA_H_
#define DOMAINPRINT_COMMPRINTRESPONSE_DATA_H_

#include "DomainPrint/enumPrintResponseResultEnumData.hh"

#include <string>

namespace DomainPrintIDL 
{
	struct CommPrintResponse
	{
		std::string resultValue;
		DomainPrintIDL::PrintResponseResultEnum result;
  	};
};

#endif /* DOMAINPRINT_COMMPRINTRESPONSE_DATA_H_ */
