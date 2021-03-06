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
#ifndef COMMNAVIGATIONOBJECTS_COMMCORRIDORNAVIGATIONGOAL_DATA_H_
#define COMMNAVIGATIONOBJECTS_COMMCORRIDORNAVIGATIONGOAL_DATA_H_

#include "CommNavigationObjects/CommNavigationPathsData.hh"


namespace CommNavigationObjectsIDL 
{
	struct CommCorridorNavigationGoal
	{
		int goalID;
		CommNavigationObjectsIDL::CommNavigationPaths paths;
		double goalX;
		double goalY;
		int goal_id;
		double startX;
		double startY;
		int start_id;
  	};
};

#endif /* COMMNAVIGATIONOBJECTS_COMMCORRIDORNAVIGATIONGOAL_DATA_H_ */
