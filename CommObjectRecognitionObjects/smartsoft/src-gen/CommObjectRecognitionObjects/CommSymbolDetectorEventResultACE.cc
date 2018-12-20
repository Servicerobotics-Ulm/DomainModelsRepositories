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
#include "CommObjectRecognitionObjects/CommSymbolDetectorEventResultACE.hh"
#include <ace/SString.h>
#include "CommObjectRecognitionObjects/enumSymbolDetectorEventTypeData.hh"

// serialization operator for element CommSymbolDetectorEventResult
ACE_CDR::Boolean operator<<(ACE_OutputCDR &cdr, const CommObjectRecognitionObjectsIDL::CommSymbolDetectorEventResult &data)
{
	ACE_CDR::Boolean good_bit = true;
	// serialize list-element goal_x
	good_bit = good_bit && cdr.write_double(data.goal_x);
	// serialize list-element goal_y
	good_bit = good_bit && cdr.write_double(data.goal_y);
	// serialize list-element goal_z
	good_bit = good_bit && cdr.write_double(data.goal_z);
	// serialize list-element type
	good_bit = good_bit && cdr.write_long(data.type);
	
	return good_bit;
}

// de-serialization operator for element CommSymbolDetectorEventResult
ACE_CDR::Boolean operator>>(ACE_InputCDR &cdr, CommObjectRecognitionObjectsIDL::CommSymbolDetectorEventResult &data)
{
	ACE_CDR::Boolean good_bit = true;
	// deserialize type element goal_x
	good_bit = good_bit && cdr.read_double(data.goal_x);
	// deserialize type element goal_y
	good_bit = good_bit && cdr.read_double(data.goal_y);
	// deserialize type element goal_z
	good_bit = good_bit && cdr.read_double(data.goal_z);
	// deserialize type element type
	good_bit = good_bit && cdr.read_long(data.type);
	
	return good_bit;
}

// serialization operator for CommunicationObject CommSymbolDetectorEventResult
ACE_CDR::Boolean operator<<(ACE_OutputCDR &cdr, const CommObjectRecognitionObjects::CommSymbolDetectorEventResult &obj)
{
	return cdr << obj.get();
}

// de-serialization operator for CommunicationObject CommSymbolDetectorEventResult
ACE_CDR::Boolean operator>>(ACE_InputCDR &cdr, CommObjectRecognitionObjects::CommSymbolDetectorEventResult &obj)
{
	return cdr >> obj.set();
}
