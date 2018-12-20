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
#ifndef COMMMANIPULATIONPLANNEROBJECTS_COMMMANIPULATIONPLANNEREVENTSTATE_ACE_H_
#define COMMMANIPULATIONPLANNEROBJECTS_COMMMANIPULATIONPLANNEREVENTSTATE_ACE_H_

#include "CommManipulationPlannerObjects/CommManipulationPlannerEventState.hh"

#include <ace/CDR_Stream.h>

// serialization operator for DataStructure CommManipulationPlannerEventState
ACE_CDR::Boolean operator<<(ACE_OutputCDR &cdr, const CommManipulationPlannerObjectsIDL::CommManipulationPlannerEventState &data);

// de-serialization operator for DataStructure CommManipulationPlannerEventState
ACE_CDR::Boolean operator>>(ACE_InputCDR &cdr, CommManipulationPlannerObjectsIDL::CommManipulationPlannerEventState &data);

// serialization operator for CommunicationObject CommManipulationPlannerEventState
ACE_CDR::Boolean operator<<(ACE_OutputCDR &cdr, const CommManipulationPlannerObjects::CommManipulationPlannerEventState &obj);

// de-serialization operator for CommunicationObject CommManipulationPlannerEventState
ACE_CDR::Boolean operator>>(ACE_InputCDR &cdr, CommManipulationPlannerObjects::CommManipulationPlannerEventState &obj);

#endif /* COMMMANIPULATIONPLANNEROBJECTS_COMMMANIPULATIONPLANNEREVENTSTATE_ACE_H_ */
