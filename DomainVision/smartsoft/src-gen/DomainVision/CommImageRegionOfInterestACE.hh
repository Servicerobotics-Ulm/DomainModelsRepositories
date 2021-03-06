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
#ifndef DOMAINVISION_COMMIMAGEREGIONOFINTEREST_ACE_H_
#define DOMAINVISION_COMMIMAGEREGIONOFINTEREST_ACE_H_

#include "DomainVision/CommImageRegionOfInterest.hh"

#include <ace/CDR_Stream.h>

// serialization operator for DataStructure CommImageRegionOfInterest
ACE_CDR::Boolean operator<<(ACE_OutputCDR &cdr, const DomainVisionIDL::CommImageRegionOfInterest &data);

// de-serialization operator for DataStructure CommImageRegionOfInterest
ACE_CDR::Boolean operator>>(ACE_InputCDR &cdr, DomainVisionIDL::CommImageRegionOfInterest &data);

// serialization operator for CommunicationObject CommImageRegionOfInterest
ACE_CDR::Boolean operator<<(ACE_OutputCDR &cdr, const DomainVision::CommImageRegionOfInterest &obj);

// de-serialization operator for CommunicationObject CommImageRegionOfInterest
ACE_CDR::Boolean operator>>(ACE_InputCDR &cdr, DomainVision::CommImageRegionOfInterest &obj);

#endif /* DOMAINVISION_COMMIMAGEREGIONOFINTEREST_ACE_H_ */
