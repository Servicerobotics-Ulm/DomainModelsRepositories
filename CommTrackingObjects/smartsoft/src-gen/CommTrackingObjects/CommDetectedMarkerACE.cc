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
#include "CommTrackingObjects/CommDetectedMarkerACE.hh"
#include <ace/SString.h>
#include "CommBasicObjects/CommBaseStateACE.hh"
#include "CommBasicObjects/CommPose3dACE.hh"

// serialization operator for element CommDetectedMarker
ACE_CDR::Boolean operator<<(ACE_OutputCDR &cdr, const CommTrackingObjectsIDL::CommDetectedMarker &data)
{
	ACE_CDR::Boolean good_bit = true;
	// serialize list-element id
	good_bit = good_bit && cdr.write_ulong(data.id);
	// serialize list-element pose
	good_bit = good_bit && cdr << data.pose;
	// serialize list-element sensor_pose
	good_bit = good_bit && cdr << data.sensor_pose;
	// serialize list-element base_state
	good_bit = good_bit && cdr << data.base_state;
	
	return good_bit;
}

// de-serialization operator for element CommDetectedMarker
ACE_CDR::Boolean operator>>(ACE_InputCDR &cdr, CommTrackingObjectsIDL::CommDetectedMarker &data)
{
	ACE_CDR::Boolean good_bit = true;
	// deserialize type element id
	good_bit = good_bit && cdr.read_ulong(data.id);
	// deserialize type element pose
	good_bit = good_bit && cdr >> data.pose;
	// deserialize type element sensor_pose
	good_bit = good_bit && cdr >> data.sensor_pose;
	// deserialize type element base_state
	good_bit = good_bit && cdr >> data.base_state;
	
	return good_bit;
}

// serialization operator for CommunicationObject CommDetectedMarker
ACE_CDR::Boolean operator<<(ACE_OutputCDR &cdr, const CommTrackingObjects::CommDetectedMarker &obj)
{
	return cdr << obj.get();
}

// de-serialization operator for CommunicationObject CommDetectedMarker
ACE_CDR::Boolean operator>>(ACE_InputCDR &cdr, CommTrackingObjects::CommDetectedMarker &obj)
{
	return cdr >> obj.set();
}
