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
#include "DomainPrint/CommDummyACE.hh"
#include <ace/SString.h>
#include "CommBasicObjects/CommVoidACE.hh"

// serialization operator for element CommDummy
ACE_CDR::Boolean operator<<(ACE_OutputCDR &cdr, const DomainPrintIDL::CommDummy &data)
{
	ACE_CDR::Boolean good_bit = true;
	// serialize list-element dummy
	good_bit = good_bit && cdr << data.dummy;
	
	return good_bit;
}

// de-serialization operator for element CommDummy
ACE_CDR::Boolean operator>>(ACE_InputCDR &cdr, DomainPrintIDL::CommDummy &data)
{
	ACE_CDR::Boolean good_bit = true;
	// deserialize type element dummy
	good_bit = good_bit && cdr >> data.dummy;
	
	return good_bit;
}

// serialization operator for CommunicationObject CommDummy
ACE_CDR::Boolean operator<<(ACE_OutputCDR &cdr, const DomainPrint::CommDummy &obj)
{
	return cdr << obj.get();
}

// de-serialization operator for CommunicationObject CommDummy
ACE_CDR::Boolean operator>>(ACE_InputCDR &cdr, DomainPrint::CommDummy &obj)
{
	return cdr >> obj.set();
}