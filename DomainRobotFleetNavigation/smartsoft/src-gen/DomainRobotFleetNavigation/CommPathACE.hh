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
#ifndef DOMAINROBOTFLEETNAVIGATION_COMMPATH_ACE_H_
#define DOMAINROBOTFLEETNAVIGATION_COMMPATH_ACE_H_

#include "DomainRobotFleetNavigation/CommPath.hh"

#include <ace/CDR_Stream.h>

// serialization operator for DataStructure CommPath
ACE_CDR::Boolean operator<<(ACE_OutputCDR &cdr, const DomainRobotFleetNavigationIDL::CommPath &data);

// de-serialization operator for DataStructure CommPath
ACE_CDR::Boolean operator>>(ACE_InputCDR &cdr, DomainRobotFleetNavigationIDL::CommPath &data);

// serialization operator for CommunicationObject CommPath
ACE_CDR::Boolean operator<<(ACE_OutputCDR &cdr, const DomainRobotFleetNavigation::CommPath &obj);

// de-serialization operator for CommunicationObject CommPath
ACE_CDR::Boolean operator>>(ACE_InputCDR &cdr, DomainRobotFleetNavigation::CommPath &obj);

#endif /* DOMAINROBOTFLEETNAVIGATION_COMMPATH_ACE_H_ */
