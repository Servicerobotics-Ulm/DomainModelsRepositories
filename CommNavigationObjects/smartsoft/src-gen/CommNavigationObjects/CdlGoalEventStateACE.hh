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
#ifndef COMMNAVIGATIONOBJECTS_CDLGOALEVENTSTATE_ACE_H_
#define COMMNAVIGATIONOBJECTS_CDLGOALEVENTSTATE_ACE_H_

#include "CommNavigationObjects/CdlGoalEventState.hh"

#include <ace/CDR_Stream.h>

// serialization operator for DataStructure CdlGoalEventState
ACE_CDR::Boolean operator<<(ACE_OutputCDR &cdr, const CommNavigationObjectsIDL::CdlGoalEventState &data);

// de-serialization operator for DataStructure CdlGoalEventState
ACE_CDR::Boolean operator>>(ACE_InputCDR &cdr, CommNavigationObjectsIDL::CdlGoalEventState &data);

// serialization operator for CommunicationObject CdlGoalEventState
ACE_CDR::Boolean operator<<(ACE_OutputCDR &cdr, const CommNavigationObjects::CdlGoalEventState &obj);

// de-serialization operator for CommunicationObject CdlGoalEventState
ACE_CDR::Boolean operator>>(ACE_InputCDR &cdr, CommNavigationObjects::CdlGoalEventState &obj);

#endif /* COMMNAVIGATIONOBJECTS_CDLGOALEVENTSTATE_ACE_H_ */
