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
#include "CommNavigationObjects/CommCorridorNavigationGoalEventStateACE.hh"
#include <ace/SString.h>
#include "CommBasicObjects/CommPosition3dACE.hh"
#include "CommNavigationObjects/enumPathNavigationEventTypeData.hh"

// serialization operator for element CommCorridorNavigationGoalEventState
ACE_CDR::Boolean operator<<(ACE_OutputCDR &cdr, const CommNavigationObjectsIDL::CommCorridorNavigationGoalEventState &data)
{
	ACE_CDR::Boolean good_bit = true;
	// serialize list-element newState
	good_bit = good_bit && cdr.write_long(data.newState);
	// serialize list-element nextGoal
	good_bit = good_bit && cdr << data.nextGoal;
	
	return good_bit;
}

// de-serialization operator for element CommCorridorNavigationGoalEventState
ACE_CDR::Boolean operator>>(ACE_InputCDR &cdr, CommNavigationObjectsIDL::CommCorridorNavigationGoalEventState &data)
{
	ACE_CDR::Boolean good_bit = true;
	// deserialize type element newState
	good_bit = good_bit && cdr.read_long(data.newState);
	// deserialize type element nextGoal
	good_bit = good_bit && cdr >> data.nextGoal;
	
	return good_bit;
}

// serialization operator for CommunicationObject CommCorridorNavigationGoalEventState
ACE_CDR::Boolean operator<<(ACE_OutputCDR &cdr, const CommNavigationObjects::CommCorridorNavigationGoalEventState &obj)
{
	return cdr << obj.get();
}

// de-serialization operator for CommunicationObject CommCorridorNavigationGoalEventState
ACE_CDR::Boolean operator>>(ACE_InputCDR &cdr, CommNavigationObjects::CommCorridorNavigationGoalEventState &obj)
{
	return cdr >> obj.set();
}
