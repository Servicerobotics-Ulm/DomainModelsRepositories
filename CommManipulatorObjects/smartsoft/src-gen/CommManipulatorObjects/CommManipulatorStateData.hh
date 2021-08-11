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
#ifndef COMMMANIPULATOROBJECTS_COMMMANIPULATORSTATE_DATA_H_
#define COMMMANIPULATOROBJECTS_COMMMANIPULATORSTATE_DATA_H_

#include "CommBasicObjects/CommPose3dData.hh"

#include <vector>

namespace CommManipulatorObjectsIDL 
{
	typedef std::vector<double> CommManipulatorState_joint_angles_type;
	struct CommManipulatorState
	{
		unsigned int id;
		CommManipulatorState_joint_angles_type joint_angles;
		CommBasicObjectsIDL::CommPose3d pose_tcp;
		unsigned char motion_constraints;
		CommBasicObjectsIDL::CommPose3d pose_manipulator;
		bool is_valid;
  	};
};

#endif /* COMMMANIPULATOROBJECTS_COMMMANIPULATORSTATE_DATA_H_ */
