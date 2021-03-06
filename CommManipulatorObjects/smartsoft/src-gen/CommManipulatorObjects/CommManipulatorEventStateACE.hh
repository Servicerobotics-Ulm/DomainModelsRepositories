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
#ifndef COMMMANIPULATOROBJECTS_COMMMANIPULATOREVENTSTATE_ACE_H_
#define COMMMANIPULATOROBJECTS_COMMMANIPULATOREVENTSTATE_ACE_H_

#include "CommManipulatorObjects/CommManipulatorEventState.hh"

#include <ace/CDR_Stream.h>

// serialization operator for DataStructure CommManipulatorEventState
ACE_CDR::Boolean operator<<(ACE_OutputCDR &cdr, const CommManipulatorObjectsIDL::CommManipulatorEventState &data);

// de-serialization operator for DataStructure CommManipulatorEventState
ACE_CDR::Boolean operator>>(ACE_InputCDR &cdr, CommManipulatorObjectsIDL::CommManipulatorEventState &data);

// serialization operator for CommunicationObject CommManipulatorEventState
ACE_CDR::Boolean operator<<(ACE_OutputCDR &cdr, const CommManipulatorObjects::CommManipulatorEventState &obj);

// de-serialization operator for CommunicationObject CommManipulatorEventState
ACE_CDR::Boolean operator>>(ACE_InputCDR &cdr, CommManipulatorObjects::CommManipulatorEventState &obj);

#endif /* COMMMANIPULATOROBJECTS_COMMMANIPULATOREVENTSTATE_ACE_H_ */
