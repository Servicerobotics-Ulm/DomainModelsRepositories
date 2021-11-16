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
#ifndef COMMMANIPULATOROBJECTS_COMMINVERSEKINEMATICSRESPONSE_DATA_H_
#define COMMMANIPULATOROBJECTS_COMMINVERSEKINEMATICSRESPONSE_DATA_H_


#include <vector>

namespace CommManipulatorObjectsIDL 
{
	typedef std::vector<float> CommInverseKinematicsResponse_joint_angles_type;
	struct CommInverseKinematicsResponse
	{
		CommInverseKinematicsResponse_joint_angles_type joint_angles;
		bool is_valid;
  	};
};

#endif /* COMMMANIPULATOROBJECTS_COMMINVERSEKINEMATICSRESPONSE_DATA_H_ */
