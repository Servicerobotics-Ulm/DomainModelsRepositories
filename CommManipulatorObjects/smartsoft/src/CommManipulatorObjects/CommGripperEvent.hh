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
#ifndef COMMMANIPULATOROBJECTS_COMMGRIPPEREVENT_H_
#define COMMMANIPULATOROBJECTS_COMMGRIPPEREVENT_H_

#include "CommManipulatorObjects/CommGripperEventCore.hh"

namespace CommManipulatorObjects {
		
class CommGripperEvent : public CommGripperEventCore {
	public:
		// default constructors
		CommGripperEvent();
		
		/**
		 * Constructor to set all values.
		 * NOTE that you have to keep this constructor consistent with the model!
		 * Use  at your own choice.
		 *
		 * The preferred way to set values for initialization is:
		 *      CommRepository::MyCommObject obj;
		 *      obj.setX(1).setY(2).setZ(3)...;
		 */
		// CommGripperEvent(const CommManipulatorObjects::GripperEvent &gripper_event, const float &pos = 0.0);
		
		CommGripperEvent(const CommGripperEventCore &commGripperEvent);
		CommGripperEvent(const DATATYPE &commGripperEvent);
		virtual ~CommGripperEvent();
		
		// use framework specific getter and setter methods from core (base) class
		using CommGripperEventCore::get;
		using CommGripperEventCore::set;
		
		//
		// feel free to add customized methods here
		//
};

inline std::ostream &operator<<(std::ostream &os, const CommGripperEvent &co)
{
	co.to_ostream(os);
	return os;
}
	
} /* namespace CommManipulatorObjects */
#endif /* COMMMANIPULATOROBJECTS_COMMGRIPPEREVENT_H_ */
