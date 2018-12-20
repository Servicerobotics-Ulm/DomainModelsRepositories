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
#include "CommManipulatorObjects/ManipulatorEventStateACE.hh"
#include <ace/SString.h>
#include "CommManipulatorObjects/enumManipulatorEventData.hh"

// serialization operator for element ManipulatorEventState
ACE_CDR::Boolean operator<<(ACE_OutputCDR &cdr, const CommManipulatorObjectsIDL::ManipulatorEventState &data)
{
	ACE_CDR::Boolean good_bit = true;
	// serialize list-element event
	good_bit = good_bit && cdr.write_long(data.event);
	
	return good_bit;
}

// de-serialization operator for element ManipulatorEventState
ACE_CDR::Boolean operator>>(ACE_InputCDR &cdr, CommManipulatorObjectsIDL::ManipulatorEventState &data)
{
	ACE_CDR::Boolean good_bit = true;
	// deserialize type element event
	good_bit = good_bit && cdr.read_long(data.event);
	
	return good_bit;
}

// serialization operator for CommunicationObject ManipulatorEventState
ACE_CDR::Boolean operator<<(ACE_OutputCDR &cdr, const CommManipulatorObjects::ManipulatorEventState &obj)
{
	return cdr << obj.get();
}

// de-serialization operator for CommunicationObject ManipulatorEventState
ACE_CDR::Boolean operator>>(ACE_InputCDR &cdr, CommManipulatorObjects::ManipulatorEventState &obj)
{
	return cdr >> obj.set();
}
