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
// This file is generated once. Modify this file to your needs. 
// If you want the toolchain to re-generate this file, please 
// delete it before running the code generator.
//--------------------------------------------------------------------------

#include "CommManipulatorObjects/CommInverseKinematicsRequest.hh"

using namespace CommManipulatorObjects;

CommInverseKinematicsRequest::CommInverseKinematicsRequest()
:	CommInverseKinematicsRequestCore()
{  }


/**
 * Constructor to set all values.
 * NOTE that you have to keep this constructor consistent with the model!
 * Use  at your own choice.
 *
 * The preferred way to set values for initialization is:
 *      CommRepository::MyCommObject obj;
 *      obj.setX(1).setY(2).setZ(3)...;
CommInverseKinematicsRequest::CommInverseKinematicsRequest(const CommBasicObjects::CommPose3d &tcp_pose, const unsigned char &motion_constraints, const bool &is_relative)
:	CommInverseKinematicsRequestCore() // base constructor sets default values as defined in the model
{
	setTcp_pose(tcp_pose);
	setIs_relative(is_relative);
	setMotion_constraints(motion_constraints);
}
 */

CommInverseKinematicsRequest::CommInverseKinematicsRequest(const CommInverseKinematicsRequestCore &commInverseKinematicsRequest)
:	CommInverseKinematicsRequestCore(commInverseKinematicsRequest)
{  }

CommInverseKinematicsRequest::CommInverseKinematicsRequest(const DATATYPE &commInverseKinematicsRequest)
:	CommInverseKinematicsRequestCore(commInverseKinematicsRequest)
{  }

CommInverseKinematicsRequest::~CommInverseKinematicsRequest()
{  }
