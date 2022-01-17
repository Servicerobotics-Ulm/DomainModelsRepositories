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
#ifndef COMMNAVIGATIONOBJECTS_COMMBUNDLEDNAVIGATIONEVENTPARAMETER_DATA_H_
#define COMMNAVIGATIONOBJECTS_COMMBUNDLEDNAVIGATIONEVENTPARAMETER_DATA_H_

#include "CommNavigationObjects/enumBundledNavigationGoalStateData.hh"

#include <string>

namespace CommNavigationObjectsIDL 
{
	struct CommBundledNavigationEventParameter
	{
		std::string locationName;
		CommNavigationObjectsIDL::BundledNavigationGoalState previousState;
  	};
};

#endif /* COMMNAVIGATIONOBJECTS_COMMBUNDLEDNAVIGATIONEVENTPARAMETER_DATA_H_ */