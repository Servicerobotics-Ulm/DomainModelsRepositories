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
#ifndef COMMNAVIGATIONOBJECTS_COMMBUNDLEDNAVIGATIONEVENTSTATE_H_
#define COMMNAVIGATIONOBJECTS_COMMBUNDLEDNAVIGATIONEVENTSTATE_H_

#include "CommNavigationObjects/CommBundledNavigationEventStateCore.hh"

namespace CommNavigationObjects {
		
class CommBundledNavigationEventState : public CommBundledNavigationEventStateCore {
	public:
		// default constructors
		CommBundledNavigationEventState();
		
		/**
		 * Constructor to set all values.
		 * NOTE that you have to keep this constructor consistent with the model!
		 * Use  at your own choice.
		 *
		 * The preferred way to set values for initialization is:
		 *      CommRepository::MyCommObject obj;
		 *      obj.setX(1).setY(2).setZ(3)...;
		 */
		// CommBundledNavigationEventState(const std::string &locationName, const CommNavigationObjects::BundledNavigationGoalState &goalState);
		
		CommBundledNavigationEventState(const CommBundledNavigationEventStateCore &commBundledNavigationEventState);
		CommBundledNavigationEventState(const DATATYPE &commBundledNavigationEventState);
		virtual ~CommBundledNavigationEventState();
		
		// use framework specific getter and setter methods from core (base) class
		using CommBundledNavigationEventStateCore::get;
		using CommBundledNavigationEventStateCore::set;
		
		//
		// feel free to add customized methods here
		//
};

inline std::ostream &operator<<(std::ostream &os, const CommBundledNavigationEventState &co)
{
	co.to_ostream(os);
	return os;
}
	
} /* namespace CommNavigationObjects */
#endif /* COMMNAVIGATIONOBJECTS_COMMBUNDLEDNAVIGATIONEVENTSTATE_H_ */
