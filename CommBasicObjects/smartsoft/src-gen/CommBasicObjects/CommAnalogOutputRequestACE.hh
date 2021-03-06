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
#ifndef COMMBASICOBJECTS_COMMANALOGOUTPUTREQUEST_ACE_H_
#define COMMBASICOBJECTS_COMMANALOGOUTPUTREQUEST_ACE_H_

#include "CommBasicObjects/CommAnalogOutputRequest.hh"

#include <ace/CDR_Stream.h>

// serialization operator for DataStructure CommAnalogOutputRequest
ACE_CDR::Boolean operator<<(ACE_OutputCDR &cdr, const CommBasicObjectsIDL::CommAnalogOutputRequest &data);

// de-serialization operator for DataStructure CommAnalogOutputRequest
ACE_CDR::Boolean operator>>(ACE_InputCDR &cdr, CommBasicObjectsIDL::CommAnalogOutputRequest &data);

// serialization operator for CommunicationObject CommAnalogOutputRequest
ACE_CDR::Boolean operator<<(ACE_OutputCDR &cdr, const CommBasicObjects::CommAnalogOutputRequest &obj);

// de-serialization operator for CommunicationObject CommAnalogOutputRequest
ACE_CDR::Boolean operator>>(ACE_InputCDR &cdr, CommBasicObjects::CommAnalogOutputRequest &obj);

#endif /* COMMBASICOBJECTS_COMMANALOGOUTPUTREQUEST_ACE_H_ */
