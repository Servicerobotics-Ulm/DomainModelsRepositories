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
#ifndef COMMLOCALIZATIONOBJECTS_COMMVISUALLOCALIZATIONFEATURE_ACE_H_
#define COMMLOCALIZATIONOBJECTS_COMMVISUALLOCALIZATIONFEATURE_ACE_H_

#include "CommLocalizationObjects/CommVisualLocalizationFeature.hh"

#include <ace/CDR_Stream.h>

// serialization operator for DataStructure CommVisualLocalizationFeature
ACE_CDR::Boolean operator<<(ACE_OutputCDR &cdr, const CommLocalizationObjectsIDL::CommVisualLocalizationFeature &data);

// de-serialization operator for DataStructure CommVisualLocalizationFeature
ACE_CDR::Boolean operator>>(ACE_InputCDR &cdr, CommLocalizationObjectsIDL::CommVisualLocalizationFeature &data);

// serialization operator for CommunicationObject CommVisualLocalizationFeature
ACE_CDR::Boolean operator<<(ACE_OutputCDR &cdr, const CommLocalizationObjects::CommVisualLocalizationFeature &obj);

// de-serialization operator for CommunicationObject CommVisualLocalizationFeature
ACE_CDR::Boolean operator>>(ACE_InputCDR &cdr, CommLocalizationObjects::CommVisualLocalizationFeature &obj);

#endif /* COMMLOCALIZATIONOBJECTS_COMMVISUALLOCALIZATIONFEATURE_ACE_H_ */