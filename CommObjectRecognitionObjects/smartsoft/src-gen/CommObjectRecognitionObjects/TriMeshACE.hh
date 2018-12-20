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
#ifndef COMMOBJECTRECOGNITIONOBJECTS_TRIMESH_ACE_H_
#define COMMOBJECTRECOGNITIONOBJECTS_TRIMESH_ACE_H_

#include "CommObjectRecognitionObjects/TriMesh.hh"

#include <ace/CDR_Stream.h>

// serialization operator for DataStructure TriMesh
ACE_CDR::Boolean operator<<(ACE_OutputCDR &cdr, const CommObjectRecognitionObjectsIDL::TriMesh &data);

// de-serialization operator for DataStructure TriMesh
ACE_CDR::Boolean operator>>(ACE_InputCDR &cdr, CommObjectRecognitionObjectsIDL::TriMesh &data);

// serialization operator for CommunicationObject TriMesh
ACE_CDR::Boolean operator<<(ACE_OutputCDR &cdr, const CommObjectRecognitionObjects::TriMesh &obj);

// de-serialization operator for CommunicationObject TriMesh
ACE_CDR::Boolean operator>>(ACE_InputCDR &cdr, CommObjectRecognitionObjects::TriMesh &obj);

#endif /* COMMOBJECTRECOGNITIONOBJECTS_TRIMESH_ACE_H_ */
