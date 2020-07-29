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
#ifndef COMMMANIPULATOROBJECTS_COMMVACUUMGRIPPEREVENTSTATE_H_
#define COMMMANIPULATOROBJECTS_COMMVACUUMGRIPPEREVENTSTATE_H_

#include "CommManipulatorObjects/CommVacuumGripperEventStateCore.hh"

namespace CommManipulatorObjects {
		
class CommVacuumGripperEventState : public CommVacuumGripperEventStateCore {
	public:
		// default constructors
		CommVacuumGripperEventState();
		
		/**
		 * Constructor to set all values.
		 * NOTE that you have to keep this constructor consistent with the model!
		 * Use  at your own choice.
		 *
		 * The preferred way to set values for initialization is:
		 *      CommRepository::MyCommObject obj;
		 *      obj.setX(1).setY(2).setZ(3)...;
		 */
		// CommVacuumGripperEventState(const CommManipulatorObjects::VacuumGraspState &state);
		
		CommVacuumGripperEventState(const CommVacuumGripperEventStateCore &commVacuumGripperEventState);
		CommVacuumGripperEventState(const DATATYPE &commVacuumGripperEventState);
		virtual ~CommVacuumGripperEventState();
		
		// use framework specific getter and setter methods from core (base) class
		using CommVacuumGripperEventStateCore::get;
		using CommVacuumGripperEventStateCore::set;
		
		//
		// feel free to add customized methods here
		//
};

inline std::ostream &operator<<(std::ostream &os, const CommVacuumGripperEventState &co)
{
	co.to_ostream(os);
	return os;
}
	
} /* namespace CommManipulatorObjects */
#endif /* COMMMANIPULATOROBJECTS_COMMVACUUMGRIPPEREVENTSTATE_H_ */