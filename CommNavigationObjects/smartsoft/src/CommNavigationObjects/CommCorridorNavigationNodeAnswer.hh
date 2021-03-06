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
#ifndef COMMNAVIGATIONOBJECTS_COMMCORRIDORNAVIGATIONNODEANSWER_H_
#define COMMNAVIGATIONOBJECTS_COMMCORRIDORNAVIGATIONNODEANSWER_H_

#include "CommNavigationObjects/CommCorridorNavigationNodeAnswerCore.hh"

#include <deque>

namespace CommNavigationObjects {
		
class CommCorridorNavigationNodeAnswer : public CommCorridorNavigationNodeAnswerCore {
	public:
		// default constructors
		CommCorridorNavigationNodeAnswer();
		
		/**
		 * Constructor to set all values.
		 * NOTE that you have to keep this constructor consistent with the model!
		 * Use  at your own choice.
		 *
		 * The preferred way to set values for initialization is:
		 *      CommRepository::MyCommObject obj;
		 *      obj.setX(1).setY(2).setZ(3)...;
		 */
		// CommCorridorNavigationNodeAnswer(const std::vector<CommNavigationObjects::CommCorridorNode> &nodesList, const bool &success);
		
		CommCorridorNavigationNodeAnswer(const CommCorridorNavigationNodeAnswerCore &commCorridorNavigationNodeAnswer);
		CommCorridorNavigationNodeAnswer(const DATATYPE &commCorridorNavigationNodeAnswer);
		virtual ~CommCorridorNavigationNodeAnswer();
		
		// use framework specific getter and setter methods from core (base) class
		using CommCorridorNavigationNodeAnswerCore::get;
		using CommCorridorNavigationNodeAnswerCore::set;
		
		//
		// feel free to add customized methods here
		//
		void setNodes(std::deque<graphNode> &p);

		void setStsNodesListElemAtPos(const size_t pos, node_status sts);
};

inline std::ostream &operator<<(std::ostream &os, const CommCorridorNavigationNodeAnswer &co)
{
	co.to_ostream(os);
	return os;
}
	
} /* namespace CommNavigationObjects */
#endif /* COMMNAVIGATIONOBJECTS_COMMCORRIDORNAVIGATIONNODEANSWER_H_ */
