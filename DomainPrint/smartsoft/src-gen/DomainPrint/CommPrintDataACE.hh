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
#ifndef DOMAINPRINT_COMMPRINTDATA_ACE_H_
#define DOMAINPRINT_COMMPRINTDATA_ACE_H_

#include "DomainPrint/CommPrintData.hh"

#include <ace/CDR_Stream.h>

// serialization operator for DataStructure CommPrintData
ACE_CDR::Boolean operator<<(ACE_OutputCDR &cdr, const DomainPrintIDL::CommPrintData &data);

// de-serialization operator for DataStructure CommPrintData
ACE_CDR::Boolean operator>>(ACE_InputCDR &cdr, DomainPrintIDL::CommPrintData &data);

// serialization operator for CommunicationObject CommPrintData
ACE_CDR::Boolean operator<<(ACE_OutputCDR &cdr, const DomainPrint::CommPrintData &obj);

// de-serialization operator for CommunicationObject CommPrintData
ACE_CDR::Boolean operator>>(ACE_InputCDR &cdr, DomainPrint::CommPrintData &obj);

#endif /* DOMAINPRINT_COMMPRINTDATA_ACE_H_ */
