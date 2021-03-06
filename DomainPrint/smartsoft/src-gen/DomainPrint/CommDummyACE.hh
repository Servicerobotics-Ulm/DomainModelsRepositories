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
#ifndef DOMAINPRINT_COMMDUMMY_ACE_H_
#define DOMAINPRINT_COMMDUMMY_ACE_H_

#include "DomainPrint/CommDummy.hh"

#include <ace/CDR_Stream.h>

// serialization operator for DataStructure CommDummy
ACE_CDR::Boolean operator<<(ACE_OutputCDR &cdr, const DomainPrintIDL::CommDummy &data);

// de-serialization operator for DataStructure CommDummy
ACE_CDR::Boolean operator>>(ACE_InputCDR &cdr, DomainPrintIDL::CommDummy &data);

// serialization operator for CommunicationObject CommDummy
ACE_CDR::Boolean operator<<(ACE_OutputCDR &cdr, const DomainPrint::CommDummy &obj);

// de-serialization operator for CommunicationObject CommDummy
ACE_CDR::Boolean operator>>(ACE_InputCDR &cdr, DomainPrint::CommDummy &obj);

#endif /* DOMAINPRINT_COMMDUMMY_ACE_H_ */
