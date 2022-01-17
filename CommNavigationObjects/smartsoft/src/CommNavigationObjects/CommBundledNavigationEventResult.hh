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
#ifndef COMMNAVIGATIONOBJECTS_COMMBUNDLEDNAVIGATIONEVENTRESULT_H_
#define COMMNAVIGATIONOBJECTS_COMMBUNDLEDNAVIGATIONEVENTRESULT_H_

#include "CommNavigationObjects/CommBundledNavigationEventResultCore.hh"

namespace CommNavigationObjects {
		
class CommBundledNavigationEventResult : public CommBundledNavigationEventResultCore {
	public:
		// default constructors
		CommBundledNavigationEventResult();
		
		/**
		 * Constructor to set all values.
		 * NOTE that you have to keep this constructor consistent with the model!
		 * Use  at your own choice.
		 *
		 * The preferred way to set values for initialization is:
		 *      CommRepository::MyCommObject obj;
		 *      obj.setX(1).setY(2).setZ(3)...;
		 */
		// CommBundledNavigationEventResult(const std::string &locationName, const CommNavigationObjects::BundledNavigationGoalState &goalState);
		
		CommBundledNavigationEventResult(const CommBundledNavigationEventResultCore &commBundledNavigationEventResult);
		CommBundledNavigationEventResult(const DATATYPE &commBundledNavigationEventResult);
		virtual ~CommBundledNavigationEventResult();
		
		// use framework specific getter and setter methods from core (base) class
		using CommBundledNavigationEventResultCore::get;
		using CommBundledNavigationEventResultCore::set;
		
		//
		// feel free to add customized methods here
		//
};

inline std::ostream &operator<<(std::ostream &os, const CommBundledNavigationEventResult &co)
{
	co.to_ostream(os);
	return os;
}
	
} /* namespace CommNavigationObjects */
#endif /* COMMNAVIGATIONOBJECTS_COMMBUNDLEDNAVIGATIONEVENTRESULT_H_ */
