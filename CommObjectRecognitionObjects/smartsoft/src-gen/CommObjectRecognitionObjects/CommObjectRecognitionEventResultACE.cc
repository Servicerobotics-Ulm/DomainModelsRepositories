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
#include "CommObjectRecognitionObjects/CommObjectRecognitionEventResultACE.hh"
#include <ace/SString.h>
#include "CommObjectRecognitionObjects/enumObjectRecognitionStateData.hh"

// serialization operator for element CommObjectRecognitionEventResult
ACE_CDR::Boolean operator<<(ACE_OutputCDR &cdr, const CommObjectRecognitionObjectsIDL::CommObjectRecognitionEventResult &data)
{
	ACE_CDR::Boolean good_bit = true;
	// serialize list-element state
	good_bit = good_bit && cdr.write_long(data.state);
	// serialize list-element environment_id
	good_bit = good_bit && cdr.write_ulong(data.environment_id);
	// serialize list-element object_id
	good_bit = good_bit && cdr << ACE_Utils::truncate_cast<ACE_CDR::ULong>(data.object_id.size());
	good_bit = good_bit && cdr.write_ulong_array(data.object_id.data(), data.object_id.size());
	
	return good_bit;
}

// de-serialization operator for element CommObjectRecognitionEventResult
ACE_CDR::Boolean operator>>(ACE_InputCDR &cdr, CommObjectRecognitionObjectsIDL::CommObjectRecognitionEventResult &data)
{
	ACE_CDR::Boolean good_bit = true;
	// deserialize type element state
	good_bit = good_bit && cdr.read_long(data.state);
	// deserialize type element environment_id
	good_bit = good_bit && cdr.read_ulong(data.environment_id);
	// deserialize list-type element object_id
	ACE_CDR::ULong data_object_idNbr;
	good_bit = good_bit && cdr >> data_object_idNbr;
	data.object_id.resize(data_object_idNbr);
	good_bit = good_bit && cdr.read_ulong_array(data.object_id.data(), data_object_idNbr);
	
	return good_bit;
}

// serialization operator for CommunicationObject CommObjectRecognitionEventResult
ACE_CDR::Boolean operator<<(ACE_OutputCDR &cdr, const CommObjectRecognitionObjects::CommObjectRecognitionEventResult &obj)
{
	return cdr << obj.get();
}

// de-serialization operator for CommunicationObject CommObjectRecognitionEventResult
ACE_CDR::Boolean operator>>(ACE_InputCDR &cdr, CommObjectRecognitionObjects::CommObjectRecognitionEventResult &obj)
{
	return cdr >> obj.set();
}
