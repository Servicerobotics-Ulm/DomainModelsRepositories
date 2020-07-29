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
#ifndef COMMMANIPULATOROBJECTS_COMMGRASP_DATA_H_
#define COMMMANIPULATOROBJECTS_COMMGRASP_DATA_H_

#include "CommBasicObjects/CommPose3dData.hh"

#include <string>

namespace CommManipulatorObjectsIDL 
{
	struct CommGrasp
	{
		std::string id;
		CommBasicObjectsIDL::CommPose3d pose;
		double quality;
		double width;
  	};
};

#endif /* COMMMANIPULATOROBJECTS_COMMGRASP_DATA_H_ */
