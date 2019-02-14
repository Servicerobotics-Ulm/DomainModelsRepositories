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
#include "CommPTUObjects/CommMobilePTUStateACE.hh"
#include <ace/SString.h>
#include "CommBasicObjects/CommBaseStateACE.hh"
#include "CommPTUObjects/CommPTUStateACE.hh"

// serialization operator for element CommMobilePTUState
ACE_CDR::Boolean operator<<(ACE_OutputCDR &cdr, const CommPTUObjectsIDL::CommMobilePTUState &data)
{
	ACE_CDR::Boolean good_bit = true;
	// serialize list-element ptu_state
	good_bit = good_bit && cdr << data.ptu_state;
	// serialize list-element base_state
	good_bit = good_bit && cdr << data.base_state;
	
	return good_bit;
}

// de-serialization operator for element CommMobilePTUState
ACE_CDR::Boolean operator>>(ACE_InputCDR &cdr, CommPTUObjectsIDL::CommMobilePTUState &data)
{
	ACE_CDR::Boolean good_bit = true;
	// deserialize type element ptu_state
	good_bit = good_bit && cdr >> data.ptu_state;
	// deserialize type element base_state
	good_bit = good_bit && cdr >> data.base_state;
	
	return good_bit;
}

// serialization operator for CommunicationObject CommMobilePTUState
ACE_CDR::Boolean operator<<(ACE_OutputCDR &cdr, const CommPTUObjects::CommMobilePTUState &obj)
{
	return cdr << obj.get();
}

// de-serialization operator for CommunicationObject CommMobilePTUState
ACE_CDR::Boolean operator>>(ACE_InputCDR &cdr, CommPTUObjects::CommMobilePTUState &obj)
{
	return cdr >> obj.set();
}