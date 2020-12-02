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
#ifndef COMMNAVIGATIONOBJECTS_COMMCORRIDORNAVIGATIONPATHREQUEST_ACE_H_
#define COMMNAVIGATIONOBJECTS_COMMCORRIDORNAVIGATIONPATHREQUEST_ACE_H_

#include "CommNavigationObjects/CommCorridorNavigationPathRequest.hh"

#include <ace/CDR_Stream.h>

// serialization operator for DataStructure CommCorridorNavigationPathRequest
ACE_CDR::Boolean operator<<(ACE_OutputCDR &cdr, const CommNavigationObjectsIDL::CommCorridorNavigationPathRequest &data);

// de-serialization operator for DataStructure CommCorridorNavigationPathRequest
ACE_CDR::Boolean operator>>(ACE_InputCDR &cdr, CommNavigationObjectsIDL::CommCorridorNavigationPathRequest &data);

// serialization operator for CommunicationObject CommCorridorNavigationPathRequest
ACE_CDR::Boolean operator<<(ACE_OutputCDR &cdr, const CommNavigationObjects::CommCorridorNavigationPathRequest &obj);

// de-serialization operator for CommunicationObject CommCorridorNavigationPathRequest
ACE_CDR::Boolean operator>>(ACE_InputCDR &cdr, CommNavigationObjects::CommCorridorNavigationPathRequest &obj);

#endif /* COMMNAVIGATIONOBJECTS_COMMCORRIDORNAVIGATIONPATHREQUEST_ACE_H_ */
