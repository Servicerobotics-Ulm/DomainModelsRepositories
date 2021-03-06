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
#ifndef DOMAINPRINT_COMMPRINTREQUEST_ACE_H_
#define DOMAINPRINT_COMMPRINTREQUEST_ACE_H_

#include "DomainPrint/CommPrintRequest.hh"

#include <ace/CDR_Stream.h>

// serialization operator for DataStructure CommPrintRequest
ACE_CDR::Boolean operator<<(ACE_OutputCDR &cdr, const DomainPrintIDL::CommPrintRequest &data);

// de-serialization operator for DataStructure CommPrintRequest
ACE_CDR::Boolean operator>>(ACE_InputCDR &cdr, DomainPrintIDL::CommPrintRequest &data);

// serialization operator for CommunicationObject CommPrintRequest
ACE_CDR::Boolean operator<<(ACE_OutputCDR &cdr, const DomainPrint::CommPrintRequest &obj);

// de-serialization operator for CommunicationObject CommPrintRequest
ACE_CDR::Boolean operator>>(ACE_InputCDR &cdr, DomainPrint::CommPrintRequest &obj);

#endif /* DOMAINPRINT_COMMPRINTREQUEST_ACE_H_ */
