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
#ifndef COMMPTUOBJECTS_PTUGOALEVENTSTATE_H_
#define COMMPTUOBJECTS_PTUGOALEVENTSTATE_H_

#include "CommPTUObjects/PTUGoalEventStateCore.hh"

namespace CommPTUObjects {
		
class PTUGoalEventState : public PTUGoalEventStateCore {

	protected:
		PTUMoveStatus newState;

	public:
		// default constructors
		PTUGoalEventState();
		
		/**
		 * Constructor to set all values.
		 * NOTE that you have to keep this constructor consistent with the model!
		 * Use  at your own choice.
		 *
		 * The preferred way to set values for initialization is:
		 *      CommRepository::MyCommObject obj;
		 *      obj.setX(1).setY(2).setZ(3)...;
		 */
		// PTUGoalEventState(const CommPTUObjects::PTUMoveStatus &newState);
		
		PTUGoalEventState(const PTUGoalEventStateCore &pTUGoalEventState);
		PTUGoalEventState(const DATATYPE &pTUGoalEventState);
		virtual ~PTUGoalEventState();
		
		// use framework specific getter and setter methods from core (base) class
		using PTUGoalEventStateCore::get;
		using PTUGoalEventStateCore::set;
		
		//
		// feel free to add customized methods here
		//

		/**
		 * Set the status of the PTU action. (Success, Failure, etc.)
		 */
		inline void set_state(CommPTUObjects::PTUMoveStatus state) {
			newState = state;
		}

		/**
		 * Get the status of the PTU action. (Success, Failure, etc.)
		 */
		inline PTUMoveStatus get_state() const {
			return newState;
		}
};

inline std::ostream &operator<<(std::ostream &os, const PTUGoalEventState &co)
{
	co.to_ostream(os);
	return os;
}
	
} /* namespace CommPTUObjects */
#endif /* COMMPTUOBJECTS_PTUGOALEVENTSTATE_H_ */
