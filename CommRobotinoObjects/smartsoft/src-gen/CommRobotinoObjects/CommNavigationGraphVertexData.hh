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
#ifndef COMMROBOTINOOBJECTS_COMMNAVIGATIONGRAPHVERTEX_DATA_H_
#define COMMROBOTINOOBJECTS_COMMNAVIGATIONGRAPHVERTEX_DATA_H_

#include "CommRobotinoObjects/enumNODE_TYPEData.hh"

#include <vector>

namespace CommRobotinoObjectsIDL 
{
	typedef std::vector<int> CommNavigationGraphVertex_intersec_path_type;
	struct CommNavigationGraphVertex
	{
		double x;
		double y;
		int pose;
		int path;
		CommRobotinoObjectsIDL::NODE_TYPE type;
		CommNavigationGraphVertex_intersec_path_type intersec_path;
  	};
};

#endif /* COMMROBOTINOOBJECTS_COMMNAVIGATIONGRAPHVERTEX_DATA_H_ */