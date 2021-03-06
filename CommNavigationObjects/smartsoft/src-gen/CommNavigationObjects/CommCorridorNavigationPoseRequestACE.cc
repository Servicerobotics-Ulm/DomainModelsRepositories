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
#include "CommNavigationObjects/CommCorridorNavigationPoseRequestACE.hh"
#include <ace/SString.h>
#include "CommNavigationObjects/enumNavigationNodeRequestTypeData.hh"

// serialization operator for element CommCorridorNavigationPoseRequest
ACE_CDR::Boolean operator<<(ACE_OutputCDR &cdr, const CommNavigationObjectsIDL::CommCorridorNavigationPoseRequest &data)
{
	ACE_CDR::Boolean good_bit = true;
	// serialize list-element requesttype
	good_bit = good_bit && cdr.write_long(data.requesttype);
	// serialize list-element pose
	good_bit = good_bit && cdr.write_ulong(data.pose);
	// serialize list-element robotID
	good_bit = good_bit && cdr << ACE_CString(data.robotID.c_str());
	
	return good_bit;
}

// de-serialization operator for element CommCorridorNavigationPoseRequest
ACE_CDR::Boolean operator>>(ACE_InputCDR &cdr, CommNavigationObjectsIDL::CommCorridorNavigationPoseRequest &data)
{
	ACE_CDR::Boolean good_bit = true;
	// deserialize type element requesttype
	good_bit = good_bit && cdr.read_long(data.requesttype);
	// deserialize type element pose
	good_bit = good_bit && cdr.read_ulong(data.pose);
	// deserialize string-type element robotID
	ACE_CString data_robotID_str;
	good_bit = good_bit && cdr >> data_robotID_str;
	data.robotID = data_robotID_str.c_str();
	
	return good_bit;
}

// serialization operator for CommunicationObject CommCorridorNavigationPoseRequest
ACE_CDR::Boolean operator<<(ACE_OutputCDR &cdr, const CommNavigationObjects::CommCorridorNavigationPoseRequest &obj)
{
	return cdr << obj.get();
}

// de-serialization operator for CommunicationObject CommCorridorNavigationPoseRequest
ACE_CDR::Boolean operator>>(ACE_InputCDR &cdr, CommNavigationObjects::CommCorridorNavigationPoseRequest &obj)
{
	return cdr >> obj.set();
}
