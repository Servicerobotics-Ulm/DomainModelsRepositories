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
#ifndef COMMBASICOBJECTS_COMMPOSITION3DWITHCOVARIANCE_ACE_H_
#define COMMBASICOBJECTS_COMMPOSITION3DWITHCOVARIANCE_ACE_H_

#include "CommBasicObjects/CommPosition3dWithCovariance.hh"

#include <ace/CDR_Stream.h>

// serialization operator for DataStructure CommPosition3dWithCovariance
ACE_CDR::Boolean operator<<(ACE_OutputCDR &cdr, const CommBasicObjectsIDL::CommPosition3dWithCovariance &data);

// de-serialization operator for DataStructure CommPosition3dWithCovariance
ACE_CDR::Boolean operator>>(ACE_InputCDR &cdr, CommBasicObjectsIDL::CommPosition3dWithCovariance &data);

// serialization operator for CommunicationObject CommPosition3dWithCovariance
ACE_CDR::Boolean operator<<(ACE_OutputCDR &cdr, const CommBasicObjects::CommPosition3dWithCovariance &obj);

// de-serialization operator for CommunicationObject CommPosition3dWithCovariance
ACE_CDR::Boolean operator>>(ACE_InputCDR &cdr, CommBasicObjects::CommPosition3dWithCovariance &obj);

#endif /* COMMBASICOBJECTS_COMMPOSITION3DWITHCOVARIANCE_ACE_H_ */
