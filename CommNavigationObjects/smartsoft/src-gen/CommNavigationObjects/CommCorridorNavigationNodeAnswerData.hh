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
#ifndef COMMNAVIGATIONOBJECTS_COMMCORRIDORNAVIGATIONNODEANSWER_DATA_H_
#define COMMNAVIGATIONOBJECTS_COMMCORRIDORNAVIGATIONNODEANSWER_DATA_H_

#include "CommNavigationObjects/CommCorridorNodeData.hh"

#include <vector>

namespace CommNavigationObjectsIDL 
{
	typedef std::vector<CommNavigationObjectsIDL::CommCorridorNode> CommCorridorNavigationNodeAnswer_nodesList_type;
	struct CommCorridorNavigationNodeAnswer
	{
		CommCorridorNavigationNodeAnswer_nodesList_type nodesList;
		bool success;
  	};
};

#endif /* COMMNAVIGATIONOBJECTS_COMMCORRIDORNAVIGATIONNODEANSWER_DATA_H_ */
