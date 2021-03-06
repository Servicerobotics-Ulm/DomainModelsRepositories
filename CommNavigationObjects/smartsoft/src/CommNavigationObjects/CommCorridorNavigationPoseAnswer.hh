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
#ifndef COMMNAVIGATIONOBJECTS_COMMCORRIDORNAVIGATIONPOSEANSWER_H_
#define COMMNAVIGATIONOBJECTS_COMMCORRIDORNAVIGATIONPOSEANSWER_H_

#include "CommNavigationObjects/CommCorridorNavigationPoseAnswerCore.hh"

namespace CommNavigationObjects {
		
class CommCorridorNavigationPoseAnswer : public CommCorridorNavigationPoseAnswerCore {
	public:
		// default constructors
		CommCorridorNavigationPoseAnswer();
		
		/**
		 * Constructor to set all values.
		 * NOTE that you have to keep this constructor consistent with the model!
		 * Use  at your own choice.
		 *
		 * The preferred way to set values for initialization is:
		 *      CommRepository::MyCommObject obj;
		 *      obj.setX(1).setY(2).setZ(3)...;
		 */
		// CommCorridorNavigationPoseAnswer(const CommNavigationObjects::NodeRequestAnserType &result);
		
		CommCorridorNavigationPoseAnswer(const CommCorridorNavigationPoseAnswerCore &commCorridorNavigationPoseAnswer);
		CommCorridorNavigationPoseAnswer(const DATATYPE &commCorridorNavigationPoseAnswer);
		virtual ~CommCorridorNavigationPoseAnswer();
		
		// use framework specific getter and setter methods from core (base) class
		using CommCorridorNavigationPoseAnswerCore::get;
		using CommCorridorNavigationPoseAnswerCore::set;
		
		//
		// feel free to add customized methods here
		//
};

inline std::ostream &operator<<(std::ostream &os, const CommCorridorNavigationPoseAnswer &co)
{
	co.to_ostream(os);
	return os;
}
	
} /* namespace CommNavigationObjects */
#endif /* COMMNAVIGATIONOBJECTS_COMMCORRIDORNAVIGATIONPOSEANSWER_H_ */
