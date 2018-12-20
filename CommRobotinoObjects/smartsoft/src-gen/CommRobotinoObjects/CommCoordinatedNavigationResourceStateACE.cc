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
#include "CommRobotinoObjects/CommCoordinatedNavigationResourceStateACE.hh"
#include <ace/SString.h>
#include "CommRobotinoObjects/enumCoordinatedNavigationResourceStateTypeData.hh"

// serialization operator for element CommCoordinatedNavigationResourceState
ACE_CDR::Boolean operator<<(ACE_OutputCDR &cdr, const CommRobotinoObjectsIDL::CommCoordinatedNavigationResourceState &data)
{
	ACE_CDR::Boolean good_bit = true;
	// serialize list-element resourceID
	good_bit = good_bit && cdr.write_long(data.resourceID);
	// serialize list-element robotID
	good_bit = good_bit && cdr.write_long(data.robotID);
	// serialize list-element state
	good_bit = good_bit && cdr.write_long(data.state);
	// serialize list-element remainingCapacity
	good_bit = good_bit && cdr.write_long(data.remainingCapacity);
	
	return good_bit;
}

// de-serialization operator for element CommCoordinatedNavigationResourceState
ACE_CDR::Boolean operator>>(ACE_InputCDR &cdr, CommRobotinoObjectsIDL::CommCoordinatedNavigationResourceState &data)
{
	ACE_CDR::Boolean good_bit = true;
	// deserialize type element resourceID
	good_bit = good_bit && cdr.read_long(data.resourceID);
	// deserialize type element robotID
	good_bit = good_bit && cdr.read_long(data.robotID);
	// deserialize type element state
	good_bit = good_bit && cdr.read_long(data.state);
	// deserialize type element remainingCapacity
	good_bit = good_bit && cdr.read_long(data.remainingCapacity);
	
	return good_bit;
}

// serialization operator for CommunicationObject CommCoordinatedNavigationResourceState
ACE_CDR::Boolean operator<<(ACE_OutputCDR &cdr, const CommRobotinoObjects::CommCoordinatedNavigationResourceState &obj)
{
	return cdr << obj.get();
}

// de-serialization operator for CommunicationObject CommCoordinatedNavigationResourceState
ACE_CDR::Boolean operator>>(ACE_InputCDR &cdr, CommRobotinoObjects::CommCoordinatedNavigationResourceState &obj)
{
	return cdr >> obj.set();
}
