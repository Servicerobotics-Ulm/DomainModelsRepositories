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
#include "CommLocalizationObjects/CommLocalizationZoneResultACE.hh"
#include <ace/SString.h>
#include "CommBasicObjects/CommTimeStampACE.hh"

// serialization operator for element CommLocalizationZoneResult
ACE_CDR::Boolean operator<<(ACE_OutputCDR &cdr, const CommLocalizationObjectsIDL::CommLocalizationZoneResult &data)
{
	ACE_CDR::Boolean good_bit = true;
	// serialize list-element currentZone
	good_bit = good_bit && cdr.write_long(data.currentZone);
	// serialize list-element timestamp
	good_bit = good_bit && cdr << data.timestamp;
	
	return good_bit;
}

// de-serialization operator for element CommLocalizationZoneResult
ACE_CDR::Boolean operator>>(ACE_InputCDR &cdr, CommLocalizationObjectsIDL::CommLocalizationZoneResult &data)
{
	ACE_CDR::Boolean good_bit = true;
	// deserialize type element currentZone
	good_bit = good_bit && cdr.read_long(data.currentZone);
	// deserialize type element timestamp
	good_bit = good_bit && cdr >> data.timestamp;
	
	return good_bit;
}

// serialization operator for CommunicationObject CommLocalizationZoneResult
ACE_CDR::Boolean operator<<(ACE_OutputCDR &cdr, const CommLocalizationObjects::CommLocalizationZoneResult &obj)
{
	return cdr << obj.get();
}

// de-serialization operator for CommunicationObject CommLocalizationZoneResult
ACE_CDR::Boolean operator>>(ACE_InputCDR &cdr, CommLocalizationObjects::CommLocalizationZoneResult &obj)
{
	return cdr >> obj.set();
}
