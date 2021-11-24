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
#ifndef COMMMANIPULATOROBJECTS_COMMINVERSEKINEMATICSRESPONSE_H_
#define COMMMANIPULATOROBJECTS_COMMINVERSEKINEMATICSRESPONSE_H_

#include "CommManipulatorObjects/CommInverseKinematicsResponseCore.hh"

namespace CommManipulatorObjects {
		
class CommInverseKinematicsResponse : public CommInverseKinematicsResponseCore {
	public:
		// default constructors
		CommInverseKinematicsResponse();
		
		/**
		 * Constructor to set all values.
		 * NOTE that you have to keep this constructor consistent with the model!
		 * Use  at your own choice.
		 *
		 * The preferred way to set values for initialization is:
		 *      CommRepository::MyCommObject obj;
		 *      obj.setX(1).setY(2).setZ(3)...;
		 */
		// CommInverseKinematicsResponse(const std::vector<float> &joint_angles, const bool &is_valid = false);
		
		CommInverseKinematicsResponse(const CommInverseKinematicsResponseCore &commInverseKinematicsResponse);
		CommInverseKinematicsResponse(const DATATYPE &commInverseKinematicsResponse);
		virtual ~CommInverseKinematicsResponse();
		
		// use framework specific getter and setter methods from core (base) class
		using CommInverseKinematicsResponseCore::get;
		using CommInverseKinematicsResponseCore::set;
		
		//
		// feel free to add customized methods here
		//
};

inline std::ostream &operator<<(std::ostream &os, const CommInverseKinematicsResponse &co)
{
	co.to_ostream(os);
	return os;
}
	
} /* namespace CommManipulatorObjects */
#endif /* COMMMANIPULATOROBJECTS_COMMINVERSEKINEMATICSRESPONSE_H_ */