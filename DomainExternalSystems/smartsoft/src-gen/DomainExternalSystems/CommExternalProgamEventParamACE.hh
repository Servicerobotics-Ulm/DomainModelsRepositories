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
#ifndef DOMAINEXTERNALSYSTEMS_COMMEXTERNALPROGAMEVENTPARAM_ACE_H_
#define DOMAINEXTERNALSYSTEMS_COMMEXTERNALPROGAMEVENTPARAM_ACE_H_

#include "DomainExternalSystems/CommExternalProgamEventParam.hh"

#include <ace/CDR_Stream.h>

// serialization operator for DataStructure CommExternalProgamEventParam
ACE_CDR::Boolean operator<<(ACE_OutputCDR &cdr, const DomainExternalSystemsIDL::CommExternalProgamEventParam &data);

// de-serialization operator for DataStructure CommExternalProgamEventParam
ACE_CDR::Boolean operator>>(ACE_InputCDR &cdr, DomainExternalSystemsIDL::CommExternalProgamEventParam &data);

// serialization operator for CommunicationObject CommExternalProgamEventParam
ACE_CDR::Boolean operator<<(ACE_OutputCDR &cdr, const DomainExternalSystems::CommExternalProgamEventParam &obj);

// de-serialization operator for CommunicationObject CommExternalProgamEventParam
ACE_CDR::Boolean operator>>(ACE_InputCDR &cdr, DomainExternalSystems::CommExternalProgamEventParam &obj);

#endif /* DOMAINEXTERNALSYSTEMS_COMMEXTERNALPROGAMEVENTPARAM_ACE_H_ */
