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
#include "CommManipulatorObjects/CommGripperEventACE.hh"
#include <ace/SString.h>
#include "CommManipulatorObjects/enumGripperEventData.hh"

// serialization operator for element CommGripperEvent
ACE_CDR::Boolean operator<<(ACE_OutputCDR &cdr, const CommManipulatorObjectsIDL::CommGripperEvent &data)
{
	ACE_CDR::Boolean good_bit = true;
	// serialize list-element gripper_event
	good_bit = good_bit && cdr.write_long(data.gripper_event);
	// serialize list-element pos
	good_bit = good_bit && cdr.write_float(data.pos);
	
	return good_bit;
}

// de-serialization operator for element CommGripperEvent
ACE_CDR::Boolean operator>>(ACE_InputCDR &cdr, CommManipulatorObjectsIDL::CommGripperEvent &data)
{
	ACE_CDR::Boolean good_bit = true;
	// deserialize type element gripper_event
	good_bit = good_bit && cdr.read_long(data.gripper_event);
	// deserialize type element pos
	good_bit = good_bit && cdr.read_float(data.pos);
	
	return good_bit;
}

// serialization operator for CommunicationObject CommGripperEvent
ACE_CDR::Boolean operator<<(ACE_OutputCDR &cdr, const CommManipulatorObjects::CommGripperEvent &obj)
{
	return cdr << obj.get();
}

// de-serialization operator for CommunicationObject CommGripperEvent
ACE_CDR::Boolean operator>>(ACE_InputCDR &cdr, CommManipulatorObjects::CommGripperEvent &obj)
{
	return cdr >> obj.set();
}
