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
#ifndef COMMMANIPULATOROBJECTS_COMMCARTESIANMANIPULATIONTARGET_H_
#define COMMMANIPULATOROBJECTS_COMMCARTESIANMANIPULATIONTARGET_H_

#include "CommManipulatorObjects/CommCartesianManipulationTargetCore.hh"

namespace CommManipulatorObjects {
		
class CommCartesianManipulationTarget : public CommCartesianManipulationTargetCore {
	public:
		// default constructors
		CommCartesianManipulationTarget();
		
		/**
		 * Constructor to set all values.
		 * NOTE that you have to keep this constructor consistent with the model!
		 * Use  at your own choice.
		 *
		 * The preferred way to set values for initialization is:
		 *      CommRepository::MyCommObject obj;
		 *      obj.setX(1).setY(2).setZ(3)...;
		 */
		// CommCartesianManipulationTarget(const CommBasicObjects::CommPose3d &tcp_pose, const CommManipulatorObjects::BasicRobotMotionType &motion_type, const CommManipulatorObjects::TargetVelocityTimeFlag &reach_type, const float &velocity, const float &acceleration, const unsigned char &motion_constraints, const bool &is_relative = false, const float &reach_time = 0.0, const float &blending_radius = 0.0);
		
		CommCartesianManipulationTarget(const CommCartesianManipulationTargetCore &commCartesianManipulationTarget);
		CommCartesianManipulationTarget(const DATATYPE &commCartesianManipulationTarget);
		virtual ~CommCartesianManipulationTarget();
		
		// use framework specific getter and setter methods from core (base) class
		using CommCartesianManipulationTargetCore::get;
		using CommCartesianManipulationTargetCore::set;
		
		//
		// feel free to add customized methods here
		//
};

inline std::ostream &operator<<(std::ostream &os, const CommCartesianManipulationTarget &co)
{
	co.to_ostream(os);
	return os;
}
	
} /* namespace CommManipulatorObjects */
#endif /* COMMMANIPULATOROBJECTS_COMMCARTESIANMANIPULATIONTARGET_H_ */
