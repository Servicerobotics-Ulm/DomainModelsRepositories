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
#ifndef COMMBASICOBJECTS_COMMTASKMESSAGE_ACE_H_
#define COMMBASICOBJECTS_COMMTASKMESSAGE_ACE_H_

#include "CommBasicObjects/CommTaskMessage.hh"

#include <ace/CDR_Stream.h>

// serialization operator for DataStructure CommTaskMessage
ACE_CDR::Boolean operator<<(ACE_OutputCDR &cdr, const CommBasicObjectsIDL::CommTaskMessage &data);

// de-serialization operator for DataStructure CommTaskMessage
ACE_CDR::Boolean operator>>(ACE_InputCDR &cdr, CommBasicObjectsIDL::CommTaskMessage &data);

// serialization operator for CommunicationObject CommTaskMessage
ACE_CDR::Boolean operator<<(ACE_OutputCDR &cdr, const CommBasicObjects::CommTaskMessage &obj);

// de-serialization operator for CommunicationObject CommTaskMessage
ACE_CDR::Boolean operator>>(ACE_InputCDR &cdr, CommBasicObjects::CommTaskMessage &obj);

#endif /* COMMBASICOBJECTS_COMMTASKMESSAGE_ACE_H_ */