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
#include "CommNavigationObjects/CommCorridorNavigationGoalACE.hh"
#include <ace/SString.h>
#include "CommNavigationObjects/CommNavigationPathsACE.hh"

// serialization operator for element CommCorridorNavigationGoal
ACE_CDR::Boolean operator<<(ACE_OutputCDR &cdr, const CommNavigationObjectsIDL::CommCorridorNavigationGoal &data)
{
	ACE_CDR::Boolean good_bit = true;
	// serialize list-element goalID
	good_bit = good_bit && cdr.write_long(data.goalID);
	// serialize list-element paths
	good_bit = good_bit && cdr << data.paths;
	// serialize list-element goalX
	good_bit = good_bit && cdr.write_double(data.goalX);
	// serialize list-element goalY
	good_bit = good_bit && cdr.write_double(data.goalY);
	// serialize list-element goal_id
	good_bit = good_bit && cdr.write_long(data.goal_id);
	// serialize list-element startX
	good_bit = good_bit && cdr.write_double(data.startX);
	// serialize list-element startY
	good_bit = good_bit && cdr.write_double(data.startY);
	// serialize list-element start_id
	good_bit = good_bit && cdr.write_long(data.start_id);
	
	return good_bit;
}

// de-serialization operator for element CommCorridorNavigationGoal
ACE_CDR::Boolean operator>>(ACE_InputCDR &cdr, CommNavigationObjectsIDL::CommCorridorNavigationGoal &data)
{
	ACE_CDR::Boolean good_bit = true;
	// deserialize type element goalID
	good_bit = good_bit && cdr.read_long(data.goalID);
	// deserialize type element paths
	good_bit = good_bit && cdr >> data.paths;
	// deserialize type element goalX
	good_bit = good_bit && cdr.read_double(data.goalX);
	// deserialize type element goalY
	good_bit = good_bit && cdr.read_double(data.goalY);
	// deserialize type element goal_id
	good_bit = good_bit && cdr.read_long(data.goal_id);
	// deserialize type element startX
	good_bit = good_bit && cdr.read_double(data.startX);
	// deserialize type element startY
	good_bit = good_bit && cdr.read_double(data.startY);
	// deserialize type element start_id
	good_bit = good_bit && cdr.read_long(data.start_id);
	
	return good_bit;
}

// serialization operator for CommunicationObject CommCorridorNavigationGoal
ACE_CDR::Boolean operator<<(ACE_OutputCDR &cdr, const CommNavigationObjects::CommCorridorNavigationGoal &obj)
{
	return cdr << obj.get();
}

// de-serialization operator for CommunicationObject CommCorridorNavigationGoal
ACE_CDR::Boolean operator>>(ACE_InputCDR &cdr, CommNavigationObjects::CommCorridorNavigationGoal &obj)
{
	return cdr >> obj.set();
}