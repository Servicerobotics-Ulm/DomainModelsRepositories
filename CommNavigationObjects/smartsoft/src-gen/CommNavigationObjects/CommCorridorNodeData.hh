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
#ifndef COMMNAVIGATIONOBJECTS_COMMCORRIDORNODE_DATA_H_
#define COMMNAVIGATIONOBJECTS_COMMCORRIDORNODE_DATA_H_

#include "CommNavigationObjects/enumNODE_TYPEData.hh"
#include "CommNavigationObjects/enumNODE_STATUSData.hh"

#include <string>

namespace CommNavigationObjectsIDL 
{
	struct CommCorridorNode
	{
		unsigned int id;
		double x;
		double y;
		unsigned int pose;
		unsigned int path;
		double width;
		CommNavigationObjectsIDL::NODE_TYPE type;
		CommNavigationObjectsIDL::NODE_STATUS sts;
		std::string robotID;
  	};
};

#endif /* COMMNAVIGATIONOBJECTS_COMMCORRIDORNODE_DATA_H_ */
