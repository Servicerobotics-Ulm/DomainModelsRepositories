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
#ifndef COMMTRACKINGOBJECTS_COMMPERSONID_ACE_H_
#define COMMTRACKINGOBJECTS_COMMPERSONID_ACE_H_

#include "CommTrackingObjects/CommPersonId.hh"

#include <ace/CDR_Stream.h>

// serialization operator for DataStructure CommPersonId
ACE_CDR::Boolean operator<<(ACE_OutputCDR &cdr, const CommTrackingObjectsIDL::CommPersonId &data);

// de-serialization operator for DataStructure CommPersonId
ACE_CDR::Boolean operator>>(ACE_InputCDR &cdr, CommTrackingObjectsIDL::CommPersonId &data);

// serialization operator for CommunicationObject CommPersonId
ACE_CDR::Boolean operator<<(ACE_OutputCDR &cdr, const CommTrackingObjects::CommPersonId &obj);

// de-serialization operator for CommunicationObject CommPersonId
ACE_CDR::Boolean operator>>(ACE_InputCDR &cdr, CommTrackingObjects::CommPersonId &obj);

#endif /* COMMTRACKINGOBJECTS_COMMPERSONID_ACE_H_ */
