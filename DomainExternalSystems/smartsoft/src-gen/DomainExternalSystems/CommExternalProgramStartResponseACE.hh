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
#ifndef DOMAINEXTERNALSYSTEMS_COMMEXTERNALPROGRAMSTARTRESPONSE_ACE_H_
#define DOMAINEXTERNALSYSTEMS_COMMEXTERNALPROGRAMSTARTRESPONSE_ACE_H_

#include "DomainExternalSystems/CommExternalProgramStartResponse.hh"

#include <ace/CDR_Stream.h>

// serialization operator for DataStructure CommExternalProgramStartResponse
ACE_CDR::Boolean operator<<(ACE_OutputCDR &cdr, const DomainExternalSystemsIDL::CommExternalProgramStartResponse &data);

// de-serialization operator for DataStructure CommExternalProgramStartResponse
ACE_CDR::Boolean operator>>(ACE_InputCDR &cdr, DomainExternalSystemsIDL::CommExternalProgramStartResponse &data);

// serialization operator for CommunicationObject CommExternalProgramStartResponse
ACE_CDR::Boolean operator<<(ACE_OutputCDR &cdr, const DomainExternalSystems::CommExternalProgramStartResponse &obj);

// de-serialization operator for CommunicationObject CommExternalProgramStartResponse
ACE_CDR::Boolean operator>>(ACE_InputCDR &cdr, DomainExternalSystems::CommExternalProgramStartResponse &obj);

#endif /* DOMAINEXTERNALSYSTEMS_COMMEXTERNALPROGRAMSTARTRESPONSE_ACE_H_ */
