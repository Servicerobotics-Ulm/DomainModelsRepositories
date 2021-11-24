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
#ifndef DOMAINROBOTFLEETNAVIGATION_COMMPATH_DATA_H_
#define DOMAINROBOTFLEETNAVIGATION_COMMPATH_DATA_H_

#include "DomainRobotFleetNavigation/CommNodeData.hh"

#include <vector>

namespace DomainRobotFleetNavigationIDL 
{
	typedef std::vector<DomainRobotFleetNavigationIDL::CommNode> CommPath_node_type;
	struct CommPath
	{
		int id;
		int direction;
		double width;
		CommPath_node_type node;
  	};
};

#endif /* DOMAINROBOTFLEETNAVIGATION_COMMPATH_DATA_H_ */