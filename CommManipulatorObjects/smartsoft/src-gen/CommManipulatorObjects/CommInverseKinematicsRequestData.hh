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
#ifndef COMMMANIPULATOROBJECTS_COMMINVERSEKINEMATICSREQUEST_DATA_H_
#define COMMMANIPULATOROBJECTS_COMMINVERSEKINEMATICSREQUEST_DATA_H_

#include "CommBasicObjects/CommPose3dData.hh"


namespace CommManipulatorObjectsIDL 
{
	struct CommInverseKinematicsRequest
	{
		CommBasicObjectsIDL::CommPose3d tcp_pose;
		bool is_relative;
		unsigned char motion_constraints;
  	};
};

#endif /* COMMMANIPULATOROBJECTS_COMMINVERSEKINEMATICSREQUEST_DATA_H_ */