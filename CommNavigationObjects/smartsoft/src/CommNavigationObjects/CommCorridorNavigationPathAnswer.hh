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
#ifndef COMMNAVIGATIONOBJECTS_COMMCORRIDORNAVIGATIONPATHANSWER_H_
#define COMMNAVIGATIONOBJECTS_COMMCORRIDORNAVIGATIONPATHANSWER_H_

#include "CommNavigationObjects/CommCorridorNavigationPathAnswerCore.hh"

namespace CommNavigationObjects {
		
class CommCorridorNavigationPathAnswer : public CommCorridorNavigationPathAnswerCore {
	public:
		// default constructors
		CommCorridorNavigationPathAnswer();
		
		/**
		 * Constructor to set all values.
		 * NOTE that you have to keep this constructor consistent with the model!
		 * Use  at your own choice.
		 *
		 * The preferred way to set values for initialization is:
		 *      CommRepository::MyCommObject obj;
		 *      obj.setX(1).setY(2).setZ(3)...;
		 */
		// CommCorridorNavigationPathAnswer(const bool &valid, const CommNavigationObjects::CommNavigationPaths &paths);
		
		CommCorridorNavigationPathAnswer(const CommCorridorNavigationPathAnswerCore &commCorridorNavigationPathAnswer);
		CommCorridorNavigationPathAnswer(const DATATYPE &commCorridorNavigationPathAnswer);
		virtual ~CommCorridorNavigationPathAnswer();
		
		// use framework specific getter and setter methods from core (base) class
		using CommCorridorNavigationPathAnswerCore::get;
		using CommCorridorNavigationPathAnswerCore::set;
		
		//
		// feel free to add customized methods here
		//
};

inline std::ostream &operator<<(std::ostream &os, const CommCorridorNavigationPathAnswer &co)
{
	co.to_ostream(os);
	return os;
}
	
} /* namespace CommNavigationObjects */
#endif /* COMMNAVIGATIONOBJECTS_COMMCORRIDORNAVIGATIONPATHANSWER_H_ */
