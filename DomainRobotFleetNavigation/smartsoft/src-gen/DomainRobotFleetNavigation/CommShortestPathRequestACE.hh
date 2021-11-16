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
#ifndef DOMAINROBOTFLEETNAVIGATION_COMMSHORTESTPATHREQUEST_ACE_H_
#define DOMAINROBOTFLEETNAVIGATION_COMMSHORTESTPATHREQUEST_ACE_H_

#include "DomainRobotFleetNavigation/CommShortestPathRequest.hh"

#include <ace/CDR_Stream.h>

// serialization operator for DataStructure CommShortestPathRequest
ACE_CDR::Boolean operator<<(ACE_OutputCDR &cdr, const DomainRobotFleetNavigationIDL::CommShortestPathRequest &data);

// de-serialization operator for DataStructure CommShortestPathRequest
ACE_CDR::Boolean operator>>(ACE_InputCDR &cdr, DomainRobotFleetNavigationIDL::CommShortestPathRequest &data);

// serialization operator for CommunicationObject CommShortestPathRequest
ACE_CDR::Boolean operator<<(ACE_OutputCDR &cdr, const DomainRobotFleetNavigation::CommShortestPathRequest &obj);

// de-serialization operator for CommunicationObject CommShortestPathRequest
ACE_CDR::Boolean operator>>(ACE_InputCDR &cdr, DomainRobotFleetNavigation::CommShortestPathRequest &obj);

#endif /* DOMAINROBOTFLEETNAVIGATION_COMMSHORTESTPATHREQUEST_ACE_H_ */
