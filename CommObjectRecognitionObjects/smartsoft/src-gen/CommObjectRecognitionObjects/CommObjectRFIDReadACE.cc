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
#include "CommObjectRecognitionObjects/CommObjectRFIDReadACE.hh"
#include <ace/SString.h>

// serialization operator for element CommObjectRFIDRead
ACE_CDR::Boolean operator<<(ACE_OutputCDR &cdr, const CommObjectRecognitionObjectsIDL::CommObjectRFIDRead &data)
{
	ACE_CDR::Boolean good_bit = true;
	// serialize list-element tagId
	good_bit = good_bit && cdr << ACE_CString(data.tagId.c_str());
	// serialize list-element rssi
	good_bit = good_bit && cdr.write_long(data.rssi);
	
	return good_bit;
}

// de-serialization operator for element CommObjectRFIDRead
ACE_CDR::Boolean operator>>(ACE_InputCDR &cdr, CommObjectRecognitionObjectsIDL::CommObjectRFIDRead &data)
{
	ACE_CDR::Boolean good_bit = true;
	// deserialize string-type element tagId
	ACE_CString data_tagId_str;
	good_bit = good_bit && cdr >> data_tagId_str;
	data.tagId = data_tagId_str.c_str();
	// deserialize type element rssi
	good_bit = good_bit && cdr.read_long(data.rssi);
	
	return good_bit;
}

// serialization operator for CommunicationObject CommObjectRFIDRead
ACE_CDR::Boolean operator<<(ACE_OutputCDR &cdr, const CommObjectRecognitionObjects::CommObjectRFIDRead &obj)
{
	return cdr << obj.get();
}

// de-serialization operator for CommunicationObject CommObjectRFIDRead
ACE_CDR::Boolean operator>>(ACE_InputCDR &cdr, CommObjectRecognitionObjects::CommObjectRFIDRead &obj)
{
	return cdr >> obj.set();
}
