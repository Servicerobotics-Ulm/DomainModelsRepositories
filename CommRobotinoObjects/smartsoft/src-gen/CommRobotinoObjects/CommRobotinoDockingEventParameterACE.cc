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
#include "CommRobotinoObjects/CommRobotinoDockingEventParameterACE.hh"
#include <ace/SString.h>
#include "CommRobotinoObjects/enumRobotinoDockingEventTypeData.hh"

// serialization operator for element CommRobotinoDockingEventParameter
ACE_CDR::Boolean operator<<(ACE_OutputCDR &cdr, const CommRobotinoObjectsIDL::CommRobotinoDockingEventParameter &data)
{
	ACE_CDR::Boolean good_bit = true;
	// serialize list-element oldState
	good_bit = good_bit && cdr.write_long(data.oldState);
	
	return good_bit;
}

// de-serialization operator for element CommRobotinoDockingEventParameter
ACE_CDR::Boolean operator>>(ACE_InputCDR &cdr, CommRobotinoObjectsIDL::CommRobotinoDockingEventParameter &data)
{
	ACE_CDR::Boolean good_bit = true;
	// deserialize type element oldState
	good_bit = good_bit && cdr.read_long(data.oldState);
	
	return good_bit;
}

// serialization operator for CommunicationObject CommRobotinoDockingEventParameter
ACE_CDR::Boolean operator<<(ACE_OutputCDR &cdr, const CommRobotinoObjects::CommRobotinoDockingEventParameter &obj)
{
	return cdr << obj.get();
}

// de-serialization operator for CommunicationObject CommRobotinoDockingEventParameter
ACE_CDR::Boolean operator>>(ACE_InputCDR &cdr, CommRobotinoObjects::CommRobotinoDockingEventParameter &obj)
{
	return cdr >> obj.set();
}
